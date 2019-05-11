#ifndef COM_ONEISH_STRANGE_LAKE_DATA_A_H
#define COM_ONEISH_STRANGE_LAKE_DATA_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/fffinale_1.hpp -c ~/source/repos/strange/archetypes/lake_data.hpp > ~/source/repos/strange/sauce/strange_lake_data_a.h
*/

#include "any_forward.hpp"

namespace strange
{

template <typename _1_>
class lake_data_a
{
public:
	// data
	inline std::vector<_1_> const& extract() const;
	inline void mutate(std::vector<_1_> const& data);
	inline std::vector<_1_>& reference();
};

} // namespace strange

#endif