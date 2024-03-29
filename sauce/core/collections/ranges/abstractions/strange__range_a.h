#ifndef COM_ONEISH__STRANGE__RANGE_A_H
#define COM_ONEISH__STRANGE__RANGE_A_H

namespace strange
{
	template <typename element_d>
	struct range_o :
		any_o
	{
		fit<forward_extractor_a<element_d>> (*begin) (con<range_a<element_d>> const& me);

		fit<forward_extractor_a<element_d>> (*end) (con<range_a<element_d>> const& me);
	};

	template <typename element_d>
	struct range_a
	{
		using non_mutator_range = bool;
		using operations = range_o<element_d>;
		using variations = any_v<range_a<element_d>>;
		using creator_fp = var<range_a<element_d>>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};

	template <typename range_d>
	inline auto begin(con<range_d> const& range)
	{
		return range.o->begin(range);
	}

	template <typename range_d>
	inline auto end(con<range_d> const& range)
	{
		return range.o->end(range);
	}

	template <typename range_d, typename range_d::non_mutator_range = true>
	inline auto begin(var<range_d> const& range)
	{
		return range.o->begin(range);
	}

	template <typename range_d, typename range_d::non_mutator_range = true>
	inline auto end(var<range_d> const& range)
	{
		return range.o->end(range);
	}

	template <typename range_d, typename range_d::non_mutator_range = true>
	inline auto begin(ptr<range_d> const& range)
	{
		return range.o->begin(range);
	}

	template <typename range_d, typename range_d::non_mutator_range = true>
	inline auto end(ptr<range_d> const& range)
	{
		return range.o->end(range);
	}
}

#endif
