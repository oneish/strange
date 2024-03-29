#ifndef COM_ONEISH__STRANGE__THING_T_H
#define COM_ONEISH__STRANGE__THING_T_H

namespace strange
{
	struct thing_t
	{
		std::atomic_int64_t refs_;
		std::atomic_int64_t weak_;
		any_a error_;

	protected:
		inline thing_t(any_a const& me)
			: refs_{ 0 }
			, weak_{ 1 }
			, error_{ { { nullptr, nullptr } } }
		{
			me.t = this;
			me.o = thing_t::_operations();
		}

		inline thing_t(any_a const& me,
			any_a const& original)
			: refs_{ 0 }
			, weak_{ 1 }
			, error_{ original.t->error_ }
		{
			me.t = this;
			me.o = thing_t::_operations();

			if (error_.t)
			{
				reinterpret_cast<var<>&>(error_).inc();
			}
		}

		thing_t(thing_t const&) = delete;

		thing_t& operator=(thing_t const&) = delete;

		virtual ~thing_t()
		{
			if (error_.t)
			{
				reinterpret_cast<var<>&>(error_).dec();
			}
		}

	private:
		// any_o
		static any_o const* _operations();
		static any_o const* _pointer_operations();

	protected:
		// inline
		static inline void _initialise(var<> const& me)
		{
		}

		static inline void _clone(con<> const& me,
			var<> const& copy)
		{
		}

	public:
		static inline bool equal_thing(con<> const& me,
			con<> const& other)
		{
			return me.t == other.t;
		}

		static inline bool less_thing(con<> const& me,
			con<> const& other)
		{
			return me.t < other.t;
		}

		static inline bool less_or_equal_thing(con<> const& me,
			con<> const& other)
		{
			return me.t <= other.t;
		}

	protected:
		// any_a
		static bool is(con<> const& me,
			con<> const& abstraction);

		static bool as(con<> const& me,
			var<> const& abstraction);

		static var<symbol_a> type(con<> const& me);

		static void set_error(var<> const& me,
			con<> const& err);

		static var<> error(con<> const& me);

		static uint64_t hash(con<> const& me);

		static bool equal(con<> const& me,
			con<> const& other);

		static bool less(con<> const& me,
			con<> const& other);

		static bool less_or_equal(con<> const& me,
			con<> const& other);

		static bool pack(con<> const& me,
			var<container_a> const& container);

		static void _free(con<> const& me);

		static void _copy(con<> const& me,
			var<> const& copy);

		static void _no_copy(con<> const& me,
			var<> const& copy);

		static void _set_pointer(con<> const& me,
			bool is_pointer);

		static bool _pointer(con<> const& me);

	public:
		// creators
		static inline var<> create()
		{
			static auto thing = var([]()
				{
					any_a r;
					new thing_t{ r };
					thing_t::_initialise(reinterpret_cast<var<> const&>(r));
					return r;
				}());
			return thing;
		}

		static inline var<> create_nothing()
		{
			static auto nothing = var([]()
				{
					any_a r;
					new thing_t{ r };
					thing_t::_initialise(reinterpret_cast<var<> const&>(r));
					auto const e = thing_t::create();
					e.inc();
					r.t->error_ = e;
					return r;
				}());
			return nothing;
		}

		static inline var<> create_from_range(con<range_a<>> const& range)
		{
			return create();
		}

		static var<> unpack(con<container_a> const& container);
	};

	inline void any_o::set_something(var<> const& me,
		bool is_something)
	{
		me.o->set_error(me, is_something ? thing_t::create_nothing() : thing_t::create());
	}

	inline bool any_o::something(con<> const& me)
	{
		return !me.t->error_.t;
	}
}

#endif
