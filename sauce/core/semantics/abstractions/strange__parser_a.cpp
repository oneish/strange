#include "../../../strange.h"

namespace strange
{
	var<symbol_a> parser_a::cat(con<> const& me)
	{
		static auto r = sym("<strange::parser>"); //TODO cat
		return r;
	}

	typename parser_a::creator_fp parser_a::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "parser")
			{
				if (function == "create_from_range")
				{
					// return thing_t::create_from_range;
				}
			}
		}
		return nullptr;
	}
}
