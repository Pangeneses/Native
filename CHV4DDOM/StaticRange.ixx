module;

#include <string>

export module CHV4DXML:StaticRange;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :AbstractRange;

export namespace CHV4DXML
{
	class StaticRange : public AbstractRange
	{
	public:
		StaticRange() = default; // (StaticRangeInit init);



	public:
		virtual ~StaticRange() = 0;

	};

}