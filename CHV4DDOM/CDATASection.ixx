module;



export module CHV4DXML:CDATASection;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Text;

export namespace CHV4DXML
{
	class CDATASection : public Text
	{
	public:
		CDATASection() = default;


	public:
		virtual ~CDATASection() = 0;

	};

}