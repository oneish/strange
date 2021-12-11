#ifndef COM_ONEISH__STRANGE__LOCK_A_H
#define COM_ONEISH__STRANGE__LOCK_A_H

namespace strange
{
	struct lock_o :
		any_o
	{
		static inline ptr<> read_lock (var<lock_a> const& me);

		static inline ptr<> write_lock (var<lock_a> const& me);

		static inline std::shared_lock<std::shared_mutex> _read_lock (var<lock_a> const& me);

		static inline std::unique_lock<std::shared_mutex> _write_lock (var<lock_a> const& me);
	};

	struct lock_a
	{
		using operations = lock_o;
		using variations = any_v<lock_a>;
		using creator_fp = var<lock_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
