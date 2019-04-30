#ifndef COM_ONEISH_STRANGE_SYMBOL_A_H
#define COM_ONEISH_STRANGE_SYMBOL_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/symbol.hpp > ~/source/repos/strange/sauce/strange_symbol_a.h
*/

#include "any.hpp"

namespace strange
{

class symbol_a
{
public:
	// symbol
	inline std::string const& to_string__() const;

	inline symbol_a add(any_a<> const& range) const;
	inline symbol_a add_(symbol_a const& symbol) const;
	inline symbol_a operator+(symbol_a const& symbol) const;
};

} // namespace strange

#endif
