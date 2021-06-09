#ifndef COM_ONEISH__STRANGE__RANGE_A_H
#define COM_ONEISH__STRANGE__RANGE_A_H

namespace strange
{
	template <typename element_d>
	struct range_o : any_o
	{
		fit<forward_extractor_a<element_d>> (*extract_begin)(con<range_a<element_d>> const& me);

		fit<forward_extractor_a<element_d>> (*extract_end)(con<range_a<element_d>> const& me);

		var<range_a<>> (*to_range_any)(con<range_a<element_d>> const& me);
	};

	template <typename element_d>
	struct range_a
	{
		using operations = range_o<element_d>;
		using creator_fp = var<range_a<element_d>>(*)();

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
		return range.o->extract_begin(range);
	}

	template <typename range_d>
	inline auto end(con<range_d> const& range)
	{
		return range.o->extract_end(range);
	}

	template <typename range_d>
	inline auto begin(var<range_d> const& range)
	{
		return range.o->extract_begin(range);
	}

	template <typename range_d>
	inline auto end(var<range_d> const& range)
	{
		return range.o->extract_end(range);
	}

	template <typename range_d>
	inline auto begin(ptr<range_d> const& range)
	{
		return range.o->extract_begin(reinterpret_cast<con<range_d> const&>(range));
	}

	template <typename range_d>
	inline auto end(ptr<range_d> const& range)
	{
		return range.o->extract_end(reinterpret_cast<con<range_d> const&>(range));
	}

	template <typename range_d>
	inline auto begin(var<range_d>& range)
	{
		return range.o->mutate_begin(range);
	}

	template <typename range_d>
	inline auto end(var<range_d>& range)
	{
		return range.o->mutate_end(range);
	}

	template <typename range_d>
	inline auto begin(ptr<range_d>& range)
	{
		return range.o->mutate_begin(reinterpret_cast<var<range_d>&>(range));
	}

	template <typename range_d>
	inline auto end(ptr<range_d>& range)
	{
		return range.o->mutate_end(reinterpret_cast<var<range_d>&>(range));
	}
}

#endif
