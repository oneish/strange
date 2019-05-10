#ifndef COM_ONEISH_STRANGE_COLLECTION_T_H
#define COM_ONEISH_STRANGE_COLLECTION_T_H

namespace strange
{

// adaptation
#define ___STRANGE_COLLECTION___ ___STRANGE_RANGE___ \
inline any_a<> has(range_a<> const& range) const \
{ \
	forward_const_iterator_a<> it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		throw dis("[collection] has passed empty range"); \
	} \
	return has_(*it); \
} \
inline any_a<> has_(any_a<> const& key) const \
{ \
	return _boole_(has__(key)); \
} \
inline any_a<> at(range_a<> const& range) const \
{ \
	forward_const_iterator_a<> it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		throw dis("[collection] at passed empty range"); \
	} \
	return at_(*it); \
} \
inline any_a<> update(range_a<> const& range) \
{ \
	forward_const_iterator_a<> it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		throw dis("[collection] update passed empty range"); \
	} \
	any_a<> key = *it; \
	if (++it == range.cend()) \
	{ \
		return update_(key, key); \
	} \
	return update_(key, *it); \
} \
inline any_a<> insert(range_a<> const& range) \
{ \
	forward_const_iterator_a<> it = range.cbegin(); \
	if (it == range.cend()) \
	{ \
		throw dis("[collection] insert passed empty range"); \
	} \
	any_a<> key = *it; \
	if (++it == range.cend()) \
	{ \
		return insert_(key, key); \
	} \
	return insert_(key, *it); \
} \
inline any_a<> insert_(any_a<> const& key, any_a<> const& value) \
{ \
	return _boole_(insert__(key, value)); \
} \
inline any_a<> erase(range_a<> const& range) \
{ \
	bool erased = false; \
	for (auto const& key : range) \
	{ \
		if (erase__(key)) \
		{ \
			erased = true; \
		} \
	} \
	return _boole_(erased); \
} \
inline any_a<> erase_(any_a<> const& key) \
{ \
	return _boole_(erase__(key)); \
} \
inline _ABSTRACTION_ clear(range_a<> const&) \
{ \
	return clear_(); \
} \
inline _ABSTRACTION_ clear_() \
{ \
	clear__(); \
	return me_(); \
} \
inline any_a<> size(range_a<> const&) const \
{ \
	return size_(); \
} \
inline number_data_a<int64_t> size_() const \
{ \
	return number_int_64_t<>::val(size__()); \
} \
inline any_a<> empty(range_a<> const&) const \
{ \
	return empty_(); \
} \
inline any_a<> empty_() const \
{ \
	return _boole_(empty__()); \
} \
inline _ABSTRACTION_ push_front(range_a<> const& range) \
{ \
	for (auto const& value : range) \
	{ \
		push_front__(value); \
	} \
	return me_(); \
} \
inline _ABSTRACTION_ push_front_(any_a<> const& value) \
{ \
	push_front__(value); \
	return me_(); \
} \
inline any_a<> pop_front(range_a<> const&) \
{ \
	return pop_front_(); \
} \
inline _ABSTRACTION_ push_back(range_a<> const& range) \
{ \
	for (auto const& value : range) \
	{ \
		push_back__(value); \
	} \
	return me_(); \
} \
inline _ABSTRACTION_ push_back_(any_a<> const& value) \
{ \
	push_back__(value); \
	return me_(); \
} \
inline any_a<> pop_back(range_a<> const&) \
{ \
	return pop_back_(); \
} \
inline _ABSTRACTION_ self_add(range_a<> const& range) \
{ \
	for (auto const& collection : range) \
	{ \
		operator+=(collection); \
	} \
	return me_(); \
} \
inline _ABSTRACTION_ self_add_(collection_a<> const& collection) \
{ \
	operator+=(collection); \
	return me_(); \
} \
inline _ABSTRACTION_ add(range_a<> const& range) const \
{ \
	_ABSTRACTION_ result = me_(); \
	for (auto const& collection : range) \
	{ \
		result += collection; \
	} \
	return result; \
} \
inline _ABSTRACTION_ add_(collection_a<> const& collection) const \
{ \
	return operator+(collection); \
} \
inline _ABSTRACTION_ operator+(collection_a<> const& collection) const \
{ \
	_ABSTRACTION_ result = me_(); \
	result += collection; \
	return result; \
} \
inline _ABSTRACTION_ self_subtract(range_a<> const& range) \
{ \
	for (auto const& collection : range) \
	{ \
		operator-=(collection); \
	} \
	return me_(); \
} \
inline _ABSTRACTION_ self_subtract_(collection_a<> const& collection) \
{ \
	operator-=(collection); \
	return me_(); \
} \
inline _ABSTRACTION_ subtract(range_a<> const& range) const \
{ \
	_ABSTRACTION_ result = me_(); \
	for (auto const& collection : range) \
	{ \
		result -= collection; \
	} \
	return result; \
} \
inline _ABSTRACTION_ subtract_(collection_a<> const& collection) const \
{ \
	return operator-(collection); \
} \
inline _ABSTRACTION_ operator-(collection_a<> const& collection) const \
{ \
	_ABSTRACTION_ result = me_(); \
	result -= collection; \
	return result; \
} \

} // namespace strange

#endif
