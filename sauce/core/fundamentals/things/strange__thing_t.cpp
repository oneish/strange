#include "../../strange__core.h"

#include <functional>

namespace strange
{
	// any_o
	any_o const* thing_t::_operations()
	{
		static any_o operations =
		{
			// any_a
			any_a::cat,
			is,
			as,
			type,
			set_error,
			error,
			hash,
			equal,
			less,
			less_or_equal,
			pack,
			_free,
			_copy,
			_set_pointer,
			_pointer,
		};
		return &operations;
	}

	any_o const* thing_t::_pointer_operations()
	{
		static any_o operations = []()
		{
			any_o ops = *thing_t::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	bool thing_t::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		return abstraction.o->cat == any_a::cat;
	}

	bool thing_t::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!thing_t::is(me, abstraction))
		{
			return false;
		}
		bool const as_pointer = abstraction.o->_pointer(abstraction);
		abstraction = me;
		if (abstraction.o->_pointer(abstraction) != as_pointer)
		{
			if (as_pointer)
			{
				abstraction.mut();
			}
			abstraction.o->_set_pointer(abstraction, as_pointer);
			if (!as_pointer)
			{
				abstraction.mut();
			}
		}
		return true;
	}

	var<symbol_a> thing_t::type(con<> const& me)
	{
		static auto r = sym("strange::thing");
		return r;
	}

	void thing_t::set_error(var<> const& me,
		con<> const& err)
	{
		me.mut();
		auto& mate = reinterpret_cast<var<>&>(me.t->error_);
		if (mate.t != err.t)
		{
			if (err.o->something(err))
			{
				if (mate.t)
				{
					mate.dec();
				}
				mate.t = err.t;
				mate.o = err.o;
				mate.inc();
				mate.pointer_to_non_pointer();
			}
			else if (mate.t)
			{
				mate.dec();
				mate.t = nullptr;
				mate.o = nullptr;
			}
		}
		else
		{
			mate.o = err.o;
		}
	}

	var<> thing_t::error(con<> const& me)
	{
		if (!me.t->error_.t)
		{
			return thing_t::create_nothing();
		}
		return var<>{ me.t->error_ };
	}

	uint64_t thing_t::hash(con<> const& me)
	{
		return static_cast<uint64_t>(std::hash<void const*>{}(me.t));
	}

	bool thing_t::equal(con<> const& me,
		con<> const& other)
	{
		return thing_t::equal_thing(me, other);
	}

	bool thing_t::less(con<> const& me,
		con<> const& other)
	{
		return thing_t::less_thing(me, other);
	}

	bool thing_t::less_or_equal(con<> const& me,
		con<> const& other)
	{
		return thing_t::less_or_equal_thing(me, other);
	}

	bool thing_t::pack(con<> const& me,
		var<container_a> const& container)
	{
		assert(container.o->is_directory(container));
		auto const& mate = reinterpret_cast<con<> const&>(me.t->error_);
		if (mate.t)
		{
			container.o->directory_insert(container, sym("error"), container.o->make_thing(container, mate));
		}
		return true;
	}

	var<> thing_t::unpack(con<container_a> const& container)
	{
		assert(container.o->is_directory(container));
		auto const thing = create();
		auto const error = container.o->directory_at(container, sym("error"));
		if (error.o->something(error))
		{
			thing.o->set_error(thing, error.o->thing(error));
		}
		return thing;
	}

	void thing_t::_free(con<> const& me)
	{
		me.t->~thing_t();
	}

	void thing_t::_copy(con<> const& me,
		var<> const& copy)
	{
		new thing_t{ copy, me };
		thing_t::_clone(me, copy);
	}

	void thing_t::_no_copy(con<> const& me,
		var<> const& copy)
	{
		copy.t = me.t;
		copy.o = me.o;
	}

	void thing_t::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? thing_t::_pointer_operations() : thing_t::_operations();
	}

	bool thing_t::_pointer(con<> const& me)
	{
		return me.o->_copy == thing_t::_no_copy;
	}
}
