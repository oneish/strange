#ifndef COM_ONEISH_STRANGE_FLOCK_A_H
#define COM_ONEISH_STRANGE_FLOCK_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale.hpp -c ~/source/repos/strange/archetypes/flock.hpp > ~/source/repos/strange/sauce/strange_flock_a.h
*/

#include "any_forward.hpp"
#include "collection_forward.hpp"
#include "random_access_iterator_forward.hpp"

namespace strange
{

template <typename random_access_iterator_a>
class flock_a
{
public:
	// flock
	inline bool has__(int64_t index) const;
	inline any_a<> at__(int64_t index) const;
	inline void update__(int64_t index, any_a<> const& value);
	inline bool insert__(int64_t index, any_a<> const& value);
	inline bool erase__(int64_t index);

	// mutable range
	inline any_a<> beset(any_a<> const& _);
	inline random_access_iterator_a beset_();
	inline random_access_iterator_a begin();

	inline any_a<> enset(any_a<> const& _);
	inline random_access_iterator_a enset_();
	inline random_access_iterator_a end();

	// data
	inline std::vector<any_a<>> const& extract__() const;
	inline void mutate__(std::vector<any_a<>> const& data);
	inline std::vector<any_a<>>& reference__();
};

} // namespace strange

#endif
