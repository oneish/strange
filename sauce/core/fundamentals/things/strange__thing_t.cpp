#include "../../../strange.h"
#include "../../utilities/strange__value_c.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#include <functional>

namespace strange
{
	// any_o
	any_o const* thing_o_f()
	{
		static any_o o =
		{
			// any_a
			any__cat_f,
			thing___free_f,
			thing___copy_f,
			thing__is_f,
			thing__as_f,
			thing___as_f,
			thing__type_f,
			thing___set_pointer_f,
			thing___pointer_f,
			thing__set_something_f,
			thing__something_f,
			thing__set_error_f,
			thing__error_f,
			thing__hash_f,
			thing__equal_f,
			thing___equal_f,
			thing__not_equal_f,
			thing___not_equal_f,
			thing__less_f,
			thing___less_f,
			thing__greater_f,
			thing___greater_f,
			thing__less_or_equal_f,
			thing___less_or_equal_f,
			thing__greater_or_equal_f,
			thing___greater_or_equal_f
		};
		return &o;
	}

	any_o const* thing_p_f()
	{
		static any_o p = []()
		{
			any_o p = *thing_o_f();
			p._copy = thing___no_copy_f;
			return p;
		}();
		return &p;
	}

	// init
	void thing__init_f(void* const me /* :<any>= */)
	{
		auto const ma = reinterpret_cast<any_a* const>(me);
		strange::one(ma);
		ma->d->error.d = 0;
		ma->d->error.o = 0;
		ma->o = thing_o_f();
	}

	// any_a
	void thing___free_f(void const* const me /* :<any># */)
	{
		if (!thing__something_f(me))
		{
			auto const ma = reinterpret_cast<any_a const* const>(me);
			strange::rel(&(ma->d->error));
		}
	}

	void thing___copy_f(void const* const me /* :<any># */,
		void* const cp /* :<any>= */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const ca = reinterpret_cast<any_a* const>(cp);
		ca->d = reinterpret_cast<thing_d*>(std::malloc(sizeof(thing_d)));
		if (!ca->d)
		{
			std::abort();
		}
		std::memcpy(ca->d, ma->d, sizeof(thing_d));
		thing___clone_f(me, cp);
	}

	void thing___clone_f(void const* const me /* :<any># */,
		void* const cp /* :<any>= */)
	{
		auto const ca = reinterpret_cast<any_a* const>(cp);
		strange::one(ca);
		if (!thing__something_f(ca))
		{
			strange::ref(&(ca->d->error));
		}
	}

	void thing___no_copy_f(void const* const me /* :<any># */,
		void* const cp /* :<any>= */)
	{
		auto const ca = reinterpret_cast<any_a* const>(cp);
		strange::ref(ca);
	}

	bool thing__is_f(void const* const me /* :<any># */,
		void const* const ab /* :<any># */)
	{
		auto const aa = reinterpret_cast<any_a const* const>(ab);
		// ab.cat in me.cats
		static thing_d* const mat = any__cat_f(me).d;
		return aa->o->cat(aa).d == mat;
	}

	bool thing__as_f(void const* const me /* :<any># */,
		void* const ab /* :<any>= */)
	{
		if (!thing__is_f(me, ab))
		{
			return false;
		}
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const aa = reinterpret_cast<any_a* const>(ab);
		bool const mp = ma->o->_pointer(ma);
		bool const ap = aa->o->_pointer(aa);
		thing___as_f(me, ab);
		strange::rep(aa, mp, ap);
		return true;
	}

	void thing___as_f(void const* const me /* :<any># */,
		void* const ab /* :<any>= */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const aa = reinterpret_cast<any_a* const>(ab);
		if (aa->d != ma->d)
		{
			strange::rel(aa);
			*aa = *ma;
			strange::ref(aa);
		}
		else
		{
			aa->o = ma->o;
		}
	}

	symbol_a thing__type_f(void const* const me /* :<any># */)
	{
		static auto r = strange::val("strange::thing");
		return r.ret();
	}

	void thing___set_pointer_f(void* const me /* :<any>= */,
		bool is_pointer /* :_bool_# */)
	{
		auto const ma = reinterpret_cast<any_a* const>(me);
		if (is_pointer)
		{
			ma->o = thing_p_f();
		}
		else
		{
			ma->o = thing_o_f();
		}
	}

	bool thing___pointer_f(void const* const me /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		return ma->o == thing_p_f();
	}

	void thing__set_something_f(void* const me /* :<any>= */,
		bool is_something /* :_bool_# */)
	{
		if (is_something == thing__something_f(me))
		{
			return;
		}
		strange::mut(me);
		auto const ma = reinterpret_cast<any_a* const>(me);
		if (is_something)
		{
			strange::rel(&(ma->d->error));
			ma->d->error.d = 0;
			ma->d->error.o = 0;
		}
		else
		{
			ma->d->error = thing__create_f();
		}
	}

	bool thing__something_f(void const* const me /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		return !ma->d->error.d;
	}

	void thing__set_error_f(void* const me /* :<any>= */,
		void const* const error /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a* const>(me);
		auto const ea = reinterpret_cast<any_a const* const>(error);
		if (ea->d == ma->d->error.d)
		{
			return;
		}
		auto const nothing = strange::val(thing__create_nothing_f());
		if (ea->d == nothing.a.d) // no error
		{
			thing__set_something_f(me, true);
		}
		else
		{
			strange::mut(me);
			ma->d->error = *ea;
			strange::ref(ea);
		}
	}

	any_a thing__error_f(void const* const me /* :<any># */)
	{
		if (thing__something_f(me))
		{
			return thing__create_nothing_f();
		}
		auto const ma = reinterpret_cast<any_a const* const>(me);
		strange::ref(&(ma->d->error));
		return ma->d->error;
	}

	uint64_t thing__hash_f(void const* const me /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		return std::hash<void const*>{}(ma->d);
	}

	bool thing__equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return thing___equal_f(me, other);
	}

	bool thing___equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const oa = reinterpret_cast<any_a const* const>(other);
		return ma->d == oa->d;
	}

	bool thing__not_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return thing___not_equal_f(me, other);
	}

	bool thing___not_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const oa = reinterpret_cast<any_a const* const>(other);
		return ma->d != oa->d;
	}

	bool thing__less_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return thing___less_f(me, other);
	}

	bool thing___less_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const oa = reinterpret_cast<any_a const* const>(other);
		return ma->d < oa->d;
	}

	bool thing__greater_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return thing___greater_f(me, other);
	}

	bool thing___greater_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const oa = reinterpret_cast<any_a const* const>(other);
		return ma->d > oa->d;
	}

	bool thing__less_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return thing___less_or_equal_f(me, other);
	}

	bool thing___less_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const oa = reinterpret_cast<any_a const* const>(other);
		return ma->d <= oa->d;
	}

	bool thing__greater_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		return thing___greater_or_equal_f(me, other);
	}

	bool thing___greater_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */)
	{
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const oa = reinterpret_cast<any_a const* const>(other);
		return ma->d >= oa->d;
	}

	// creators
	any_a thing__create_f()
	{
		static auto r = strange::var([]()
		{
			any_a r;
			r.d = reinterpret_cast<thing_d*>(std::malloc(sizeof(thing_d))); std::cout << "malloc\n";
			if (!r.d)
			{
				std::abort();
			}
			thing__init_f(&r);
			return r;
		}());
		return r.ret();
	}

	any_a thing__create_nothing_f()
	{
		static auto r = strange::var([]()
		{
			any_a r;
			r.d = reinterpret_cast<thing_d*>(std::malloc(sizeof(thing_d))); std::cout << "malloc\n";
			if (!r.d)
			{
				std::abort();
			}
			thing__init_f(&r);
			r.d->error = thing__create_f();
			return r;
		}());
		return r.ret();
	}
}
