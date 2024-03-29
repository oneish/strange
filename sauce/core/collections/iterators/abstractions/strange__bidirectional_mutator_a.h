#ifndef COM_ONEISH__STRANGE__BIDIRECTIONAL_MUTATOR_A_H
#define COM_ONEISH__STRANGE__BIDIRECTIONAL_MUTATOR_A_H

namespace strange
{
	template <typename element_d>
	struct bidirectional_mutator_o :
		forward_mutator_o<element_d>
	{
		void (*decrement) (var<bidirectional_mutator_a<element_d>> const& me);
	};

	template <typename element_d>
	struct bidirectional_mutator_a
	{
		using operations = bidirectional_mutator_o<element_d>;
		using variations = any_v<bidirectional_mutator_a<element_d>>;
		using creator_fp = bit<bidirectional_mutator_a<element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
