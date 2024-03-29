#include "../../../strange__core.h"

namespace strange
{
	// bidirectional_pair_mutator_t
	// bidirectional_mutator_o
	template <typename iterator_d, typename key_d, typename value_d>
	bidirectional_mutator_o<typename bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::element_d> const* bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_operations()
	{
		static bidirectional_mutator_o<element_d> operations =
		{
			{
				{
					// any_a
					bidirectional_mutator_a<element_d>::cat,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::is,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::as,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::type,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::set_error,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::error,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::hash,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::equal,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::less,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::less_or_equal,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::pack,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_free,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_copy,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_set_pointer,
					bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_pointer,
				},
				// forward_mutator_a
				bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::equal_iterator,
				bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::get,
				bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::set,
				bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::increment,
				bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_operator_star,
				bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_operator_arrow,
			},
			// bidirectional_mutator_a
			bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::decrement,
		};
		return &operations;
	}

	template <typename iterator_d, typename key_d, typename value_d>
	bidirectional_mutator_o<typename bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::element_d> const* bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_pointer_operations()
	{
		static bidirectional_mutator_o<element_d> operations = []()
		{
			bidirectional_mutator_o<element_d> ops = *bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_operations();
			ops._copy = thing_t::_no_copy;
			return ops;
		}();
		return &operations;
	}

	// any_a
	template <typename iterator_d, typename key_d, typename value_d>
	bool bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::is(con<> const& me,
		con<> const& abstraction)
	{
		// abstraction.cat in me.cats
		auto const abc = abstraction.o->cat;
		return abc == any_a::cat ||
			abc == forward_mutator_a<element_d>::cat ||
			abc == bidirectional_mutator_a<element_d>::cat;
	}

	template <typename iterator_d, typename key_d, typename value_d>
	bool bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::as(con<> const& me,
		var<> const& abstraction)
	{
		if (!bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::is(me, abstraction))
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

	template <typename iterator_d, typename key_d, typename value_d>
	var<symbol_a> bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::type(con<> const& me)
	{
		static auto r = sym("strange::bidirectional_pair_mutator");
		return r;
	}

	template <typename iterator_d, typename key_d, typename value_d>
	void bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_copy(con<> const& me,
		var<> const& copy)
	{
		new bidirectional_pair_mutator_t<iterator_d, key_d, value_d>{ copy, me };
		bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_clone(me, copy);
	}

	template <typename iterator_d, typename key_d, typename value_d>
	void bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_set_pointer(con<> const& me,
		bool is_pointer)
	{
		me.o = is_pointer ? bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_pointer_operations() : bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::_operations();
	}

	// bidirectional_tuple_mutator_a
	template <typename iterator_d, typename key_d, typename value_d>
	void bidirectional_pair_mutator_t<iterator_d, key_d, value_d>::decrement(var<bidirectional_mutator_a<element_d>> const& me)
	{
		me.mut();
		--(static_cast<bidirectional_pair_mutator_t<iterator_d, key_d, value_d>*>(me.t)->iterator_);
	}

	// instantiation
	template struct bidirectional_pair_mutator_t<std::map<int64_t, table_value_tuple_u<int64_t, int64_t, std::pair<int64_t const, int64_t>>>::iterator, int64_t, int64_t>;
}
