#ifndef COM_ONEISH_STRANGE_BROOK_A_H
#define COM_ONEISH_STRANGE_BROOK_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/fffinale_1.hpp -c ~/source/repos/strange/archetypes/brook.hpp > ~/source/repos/strange/sauce/strange_brook_a.h
*/

#include "any_forward.hpp"

namespace strange
{

template <typename _1_>
class brook_a
{
public:
	// brook
	inline std::deque<_1_> const& extract() const;
	inline void mutate(std::deque<_1_> const& data);
	inline std::deque<_1_>& reference();
};

} // namespace strange

#endif
