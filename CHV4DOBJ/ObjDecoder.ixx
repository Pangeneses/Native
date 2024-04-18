module;

#include <string>
#include <fstream>
#include <vector>
#include <map>

export module ObjDecoder;

import CHV4DTBASIC;
import CHV4DTENSOR;

export namespace WaveObject
{
	std::map<std::string, size_t> NodeType{
		{ "",		   99 },			
		{ "#",			0 },
		{ "o",			1 },
		{ "g",			2 },
		{ "l",			3 },
		{ "v",			4 },
		{ "vt",			5 },
		{ "vn",			6 },
		{ "vp",			7 },
		{ "f",			8 },
		{ "m",			9 },
		{ "u",		   10 },
		{ "n",         11 },
		{ "s",         12 },
		{ "mtllib",    13 },
		{ "usemtl",    14 } };
            
	class ObjDecoder 
	{
	public:
		ObjDecoder() = default;

	public:
		Deck::CHV4DOBJ const& LoadMeshFromFile(const char* file);

	private:
		size_t switchType;

	private:
		void AppendObject(std::string obj);

		void AppendGroup(std::string group);

		void ExtractVertexFromLine(std::string l);

		void ExtractTextCoordFromLine(std::string l);

		void ExtractVertexNormalFromLine(std::string l);

		void MakeFace(std::string l);

		void AppendMaterialLibrary(std::string lib);

		void ApplyMaterial(std::string mat);

	private:
		std::vector<GeV::CHV4DFLOAT4> point;

		std::vector<GeV::CHV4DFLOAT4> text;

		std::vector<GeV::CHV4DFLOAT4> norm;

		Deck::CHV4DOBJ Obj;

	private:
		std::string line;

		std::wofstream log;

	};

}