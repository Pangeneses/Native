module;

#include <string>
#include <vector>

export module CHV4DXML:NodeList;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class NodeList 
	{
	public:
		NodeList() = default;

	public:
		virtual INode Item(uint32_t index) = 0;
		
		virtual uint32_t length() = 0;

		virtual std::vector<INode>::iterator Nodes() = 0;

		virtual std::vector<INode>::iterator Begin() = 0;

		virtual std::vector<INode>::iterator End() = 0;

	public:
		virtual ~NodeList() = 0;

	};

}