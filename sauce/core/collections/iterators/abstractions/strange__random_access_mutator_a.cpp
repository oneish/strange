#include "../../../strange__core.h"

namespace strange
{
	template <typename element_d>
	var<symbol_a> random_access_mutator_a<element_d>::cat(con<> const& me)
	{
		static auto r = sym("<strange::random_access_mutator>"); //TODO cat
		return r;
	}

	template <typename element_d>
	typename random_access_mutator_a<element_d>::creator_fp random_access_mutator_a<element_d>::creator(con<symbol_a> const& scope,
		con<symbol_a> const& thing,
		con<symbol_a> const& function)
	{
		if (scope == "strange")
		{
			if (thing == "random_access_mutator")
			{
				if (function == "create_from_range")
				{
					// return thing_t::create_from_range;
				}
			}
		}
		return nullptr;
	}

	// instantiation
	template struct random_access_mutator_a<>;
	template struct random_access_mutator_a<int64_t>;
	template struct random_access_mutator_a<uint8_t>;
}
