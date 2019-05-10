#ifndef COM_ONEISH_STRANGE_CAT_A_H
#define COM_ONEISH_STRANGE_CAT_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale.hpp -c ~/source/repos/strange/archetypes/cat.hpp > ~/source/repos/strange/sauce/strange_cat_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"
#include "symbol_forward.hpp"

namespace strange
{

template <typename _1_>
class cat_a
{
public:
	// cat
	inline any_a<> name(range_a<> const& _) const;
	inline symbol_a<> name_() const;

	inline any_a<> arguments(range_a<> const& _) const;
	inline any_a<> arguments_() const;

	inline any_a<> parameters(range_a<> const& _) const;
	inline any_a<> parameters_() const;

	inline any_a<> result(range_a<> const& _) const;
	inline cat_a result_() const;

	inline any_a<> includes(range_a<> const& range) const;
	inline any_a<> includes_(any_a<> const& thing) const;
	inline bool includes__(any_a<> const& thing) const;

	inline any_a<> conforms(range_a<> const& range) const;
	inline any_a<> conforms_(any_a<> const& thing, any_a<> const& cat_or_herd) const;
	inline bool conforms__(any_a<> const& thing, any_a<> const& cat_or_herd) const;
};

} // namespace strange

#endif
