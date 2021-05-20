#include "../../../strange.h"
#include "../../utilities/strange__value_u.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string_view>

namespace strange
{
	symbol_t::symbol_t(void* const me /* :<symbol>= */,
		char const* const s /* :_char_star_# */)
		:	thing_t{ me }
		,	symbol{ 0 }
		,	length{ 0 }
		,	hash{ 0 }
	{
		auto const ma = reinterpret_cast<symbol_a* const>(me);
		ma->o = symbol_t::operations_f();

		if (s)
		{
			length = std::strlen(s);
			symbol = new char[length + 1];
			std::memcpy(symbol, s, length + 1);
			hash = std::hash<std::string_view>{}(std::string_view{ symbol, static_cast<uint64_t>(length) });
		}
	}

	symbol_t::symbol_t(void* const me /* :<symbol>= */,
		void const* const original /* :<symbol># */)
		:	thing_t{ me, original }
		,	symbol{ 0 }
		,	length{ 0 }
		,	hash{ 0 }
	{
		auto const ma = reinterpret_cast<symbol_a* const>(me);
		ma->o = symbol_t::operations_f();

		auto const oa = reinterpret_cast<symbol_a const* const>(original);
		auto const ot = static_cast<symbol_t const* const>(oa->t);
		length = ot->length;
		symbol = new char[length + 1];
		std::memcpy(symbol, ot->symbol, length + 1);
		hash = ot->hash;
	}

	symbol_t::~symbol_t()
	{
		delete[] symbol;
	}

	// symbol_o
	symbol_o const* symbol_t::operations_f()
	{
		static symbol_o operations =
		{
			// any_a
			symbol_a::cat_f,
			_free_f,
			_copy_f,
			is_f,
			as_f,
			_as_f,
			type_f,
			_set_pointer_f,
			_pointer_f,
			set_something_f,
			something_f,
			set_error_f,
			error_f,
			hash_f,
			equal_f,
			_equal_f,
			not_equal_f,
			_not_equal_f,
			less_f,
			_less_f,
			greater_f,
			_greater_f,
			less_or_equal_f,
			_less_or_equal_f,
			greater_or_equal_f,
			_greater_or_equal_f,
			// symbol_a
			add_f,
			to_char_star_f,
			length_f,
			first_char_f,
			last_char_f
		};
		return &operations;
	}

	symbol_o const* symbol_t::pointer_operations_f()
	{
		static symbol_o operations = []()
		{
			symbol_o operations = *symbol_t::operations_f();
			operations._copy = thing_t::_no_copy_f;
			return operations;
		}();
		return &operations;
	}

	// any_a
	void symbol_t::_copy_f(void const* const me /* :<symbol># */,
		void* const cp /* :<symbol>= */)
	{
		new symbol_t{ cp, me };
		symbol_t::_clone_f(me, cp);
	}

	bool symbol_t::is_f(void const* const me /* :<symbol># */,
		void const* const ab /* :<any># */)
	{
		auto const aa = reinterpret_cast<symbol_a const* const>(ab);
		auto const abc = aa->o->cat(aa).t;
		// ab.cat in me.cats
		static thing_t* mats[] =
		{
			any_a::cat_f(me).t,
			symbol_a::cat_f(me).t
		};
		return abc == mats[0] || abc == mats[1];
	}

	bool symbol_t::as_f(void const* const me /* :<symbol># */,
		void* const ab /* :<any>= */)
	{
		if (!symbol_t::is_f(me, ab))
		{
			return false;
		}
		auto const ma = reinterpret_cast<any_a const* const>(me);
		auto const aa = reinterpret_cast<any_a* const>(ab);
		bool const mp = ma->o->_pointer(ma);
		bool const ap = aa->o->_pointer(aa);
		thing_t::_as_f(me, ab);
		strange::rep(aa, mp, ap);
		return true;
	}

	var<symbol_a> symbol_t::type_f(void const* const me /* :<symbol># */)
	{
		static auto r = strange::sym("strange::symbol");
		return r;
	}

	void symbol_t::_set_pointer_f(void* const me /* :<symbol>= */,
		bool is_pointer /* :_bool_# */)
	{
		auto const ma = reinterpret_cast<symbol_a* const>(me);
		if (is_pointer)
		{
			ma->o = symbol_t::pointer_operations_f();
		}
		else
		{
			ma->o = symbol_t::operations_f();
		}
	}

	bool symbol_t::_pointer_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		return ma->o == symbol_t::pointer_operations_f();
	}

	uint64_t symbol_t::hash_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		return md->hash;
	}

	bool symbol_t::equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other);
		auto os = symbol_t::create_empty_f();
		if (oa->o->as(oa, os))
		{
			return symbol_t::_equal_f(me, os);
		}
		return thing_t::equal_f(me, other);
	}

	bool symbol_t::_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		auto const os = reinterpret_cast<symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) == 0;
	}

	bool symbol_t::not_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other);
		auto os = symbol_t::create_empty_f();
		if (oa->o->as(oa, os))
		{
			return symbol_t::_not_equal_f(me, os);
		}
		return thing_t::not_equal_f(me, other);
	}

	bool symbol_t::_not_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		auto const os = reinterpret_cast<symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) != 0;
	}

	bool symbol_t::less_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other);
		auto os = symbol_t::create_empty_f();
		if (oa->o->as(oa, os))
		{
			return symbol_t::_less_f(me, os);
		}
		return thing_t::less_f(me, other);
	}

	bool symbol_t::_less_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		auto const os = reinterpret_cast<symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) < 0;
	}

	bool symbol_t::greater_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other);
		auto os = symbol_t::create_empty_f();
		if (oa->o->as(oa, os))
		{
			return symbol_t::_greater_f(me, os);
		}
		return thing_t::greater_f(me, other);
	}

	bool symbol_t::_greater_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		auto const os = reinterpret_cast<symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) > 0;
	}

	bool symbol_t::less_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other);
		auto os = symbol_t::create_empty_f();
		if (oa->o->as(oa, os))
		{
			return symbol_t::_less_or_equal_f(me, os);
		}
		return thing_t::less_or_equal_f(me, other);
	}

	bool symbol_t::_less_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		auto const os = reinterpret_cast<symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) <= 0;
	}

	bool symbol_t::greater_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<any># */)
	{
		auto const oa = reinterpret_cast<any_a const* const>(other);
		auto os = symbol_t::create_empty_f();
		if (oa->o->as(oa, os))
		{
			return symbol_t::_greater_or_equal_f(me, os);
		}
		return thing_t::greater_or_equal_f(me, other);
	}

	bool symbol_t::_greater_or_equal_f(void const* const me /* :<symbol># */,
		void const* const other /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = static_cast<symbol_t const* const>(ma->t);
		auto const os = reinterpret_cast<symbol_a const* const>(other);
		return std::strncmp(md->symbol, os->o->to_char_star(os),
			std::max(md->length, os->o->length(os))) >= 0;
	}

	// symbol_a
	var<symbol_a> symbol_t::add_f(void const* const me /* :<symbol># */,
		void const* const suffix /* :<symbol># */)
	{
		// cannot assume symbol has a symbol_t, only that it implements symbol_a
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = static_cast<symbol_t* const>(ma->t);
		auto const sa = reinterpret_cast<symbol_a const* const>(suffix);
		symbol_a r;
		auto const rd = new symbol_t{ &r, static_cast<const char* const>(0) };
		symbol_t::_init_f(&r);
		int64_t const symbol_length = sa->o->length(sa);
		rd->length = md->length + symbol_length;
		rd->symbol = new char[rd->length + 1];
		std::memcpy(rd->symbol, md->symbol, md->length);
		std::memcpy(rd->symbol + md->length, sa->o->to_char_star(sa), symbol_length + 1);
		rd->hash = std::hash<std::string_view>{}(std::string_view{ rd->symbol, static_cast<uint64_t>(rd->length) });
		return var<symbol_a>{ r };
	}

	char const* symbol_t::to_char_star_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = static_cast<symbol_t* const>(ma->t);
		return md->symbol;
	}

	int64_t symbol_t::length_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = static_cast<symbol_t* const>(ma->t);
		return md->length;
	}

	char symbol_t::first_char_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = static_cast<symbol_t* const>(ma->t);
		return (md->symbol)[0];
	}

	char symbol_t::last_char_f(void const* const me /* :<symbol># */)
	{
		auto const ma = reinterpret_cast<symbol_a const* const>(me);
		auto const md = static_cast<symbol_t* const>(ma->t);
		return (md->symbol)[std::max(int64_t{ 0 }, md->length - 1)];
	}

	// creators
	var<symbol_a> symbol_t::create_f(char const* const s /* :_char_star_# */)
	{
		symbol_a r;
		auto const rd = new symbol_t{ &r, s };
		symbol_t::_init_f(&r);
		return var<symbol_a>{ r };
	}

	var<symbol_a> symbol_t::create_empty_f()
	{
		static auto r = symbol_t::create_f("");
		return r;
	}
}
