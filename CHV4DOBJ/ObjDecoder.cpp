module;

#include <string>
#include <fstream>
#include <vector>

module ObjDecoder;

import CHV4DTBASIC;
import CHV4DTENSOR;

namespace SysT = CHV4DTBASIC;

namespace WaveObject
{
	Deck::CHV4DOBJ const& ObjDecoder::LoadMeshFromFile(const char* file)
	{
		std::fstream streamView{ file, std::ios::in };

		streamView.seekg(0, std::ios::end);

		std::fstream::pos_type length = streamView.tellg();

		streamView.seekg(0, std::ios::beg);

		std::vector<char> charArray;

		charArray.resize(length);

		streamView.read(&charArray[0], length);

		std::vector<char>::iterator itt{ charArray.begin() };

		while (itt != charArray.end())
		{
			line.clear();

			while (*itt != '\n')
			{
				line.push_back(*itt);

				itt++;

			}

			itt++;

			std::string nodeType = line.substr(0, line.find(' '));

			try
			{
				switchType = NodeType[nodeType];

			}
			catch (std::out_of_range)
			{
				return {};

			}

			switch (switchType) {

			case 0:case 99: break; // # // ""

			case 1: AppendObject(line.substr(2, std::string::npos)); break; // o
			case 2: AppendGroup(line.substr(2, std::string::npos)); break; // g

			case 3: break; // l polyline

			case 4: ExtractVertexFromLine(line.substr(2, std::string::npos)); break; // v
			case 5: ExtractTextCoordFromLine(line.substr(3, std::string::npos)); break; // vt
			case 6: ExtractVertexNormalFromLine(line.substr(3, std::string::npos)); break; // vn

			case 7: break; // vp parameter space

			case 8: MakeFace(line.substr(2, std::string::npos)); break; //f

			case 9: break; // m 
			case 10: break; // u
			case 11: break; // n
			case 12: break; // s smooth shading

			case 13: AppendMaterialLibrary(line.substr(6, std::string::npos)); break; // mtllib
			case 14: ApplyMaterial(line.substr(6, std::string::npos)); break; // usemtl

			default: break;

			}

		}

		return Obj;

	}

	void ObjDecoder::AppendMaterialLibrary(std::string lib)
	{
		Obj.MatLib.push_back(lib);

	}

	void ObjDecoder::AppendObject(std::string obj)
	{
		Obj.Objects.push_back({ obj, {} });

	}

	void ObjDecoder::AppendGroup(std::string group)
	{
		Obj.Groups.push_back({ group, {} });

		Obj.Objects.back().second.push_back(Obj.Groups.size() - 1);

	}

	void ObjDecoder::ExtractVertexFromLine(std::string l)
	{
		size_t n{ 0 };

		std::string str;

		float val[3];

		for (size_t i = 0; i < l.length(); ++i)
		{
			if (l[i] == ' ')
			{
				val[n] = std::stof(str.c_str());

				++n;

				str = {};

			}
			else if (i == l.length() - 1)
			{
				str.push_back(l[i]);

				val[n] = std::stof(str.c_str());

				++n;

			}
			else
			{
				str.push_back(l[i]);

			}

		}

		point.push_back({ val[0], val[1], val[2], 1.0f });

		return;

	}

	void ObjDecoder::ExtractTextCoordFromLine(std::string l)
	{
		size_t n{ 0 };

		std::string str;

		float val[2];

		for (size_t i = 0; i < l.length(); ++i)
		{
			if (l[i] == ' ')
			{
				val[n] = std::stof(str.c_str());

				++n;

				str = {};

			}
			else if (i == l.length() - 1)
			{
				str.push_back(l[i]);

				val[n] = std::stof(str.c_str());

				++n;

			}
			else
			{
				str.push_back(l[i]);

			}

		}

		text.push_back({ val[0], val[1], 0.0f, 0.0f });

		return;

	}

	void ObjDecoder::ExtractVertexNormalFromLine(std::string l)
	{
		size_t n{ 0 };

		std::string str;

		float val[3];

		for (size_t i = 0; i < l.length(); ++i)
		{
			if (l[i] == ' ')
			{
				val[n] = std::stof(str.c_str());

				++n;

				str = {};

			}
			else if (i == l.length() - 1)
			{
				str.push_back(l[i]);

				val[n] = std::stof(str.c_str());

				++n;

			}
			else
			{
				str.push_back(l[i]);

			}

		}

		norm.push_back({ val[0], val[1], val[2], 1.0f });

		return;

	}

	void ObjDecoder::ApplyMaterial(std::string lib)
	{
		if (Obj.Groups.size() == 0) Obj.Groups.push_back({ "", {} });

		Obj.Groups.back().first = lib;

	}

	void ObjDecoder::MakeFace(std::string l)
	{
		size_t n{ 0 };

		std::string str;

		size_t val[12];

		for (size_t i = 0; i < l.length(); ++i)
		{
			if (l[i] == ' ' || l[i] == '/')
			{
				val[n] = std::stoi(str.c_str()) - 1;

				++n;

				str = {};

			}
			else if (i == l.length() - 1)
			{
				str.push_back(l[i]);

				val[n] = std::stoi(str.c_str()) - 1;

				++n;

			}
			else
			{
				str.push_back(l[i]);

			}

		}

		if (Obj.Groups.size() == 0)
		{
			Obj.Groups.push_back({ "", {} });

			Obj.Objects.back().second.push_back(0);

		}

		if (n == 9)
		{
			Obj.Groups.back().second.push_back(
				Deck::CHV4DFACE{
					Deck::CHV4DVERTEX{ point.at(val[0]), text.at(val[1]), norm.at(val[2]) },
					Deck::CHV4DVERTEX{ point.at(val[3]), text.at(val[4]), norm.at(val[5]) },
					Deck::CHV4DVERTEX{ point.at(val[6]), text.at(val[7]), norm.at(val[8]) }
				});

		}
		else
		{
			Obj.Groups.back().second.push_back(
				Deck::CHV4DFACE{
					Deck::CHV4DVERTEX{ point.at(val[3]), text.at(val[4]), norm.at(val[5]) },
					Deck::CHV4DVERTEX{ point.at(val[0]), text.at(val[1]), norm.at(val[2]) },					
					Deck::CHV4DVERTEX{ point.at(val[9]), text.at(val[10]), norm.at(val[11]) }
				});

			Obj.Groups.back().second.push_back(
				Deck::CHV4DFACE{
					Deck::CHV4DVERTEX{ point.at(val[6]), text.at(val[7]), norm.at(val[8]) },
					Deck::CHV4DVERTEX{ point.at(val[3]), text.at(val[4]), norm.at(val[5]) },					
					Deck::CHV4DVERTEX{ point.at(val[9]), text.at(val[10]), norm.at(val[11]) }
				});

		};

		return;

	}

}