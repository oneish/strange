
namespace strange
{

template <typename _element>
inline bool unordered_herd_a<_element>::operator==(unordered_herd_a < _element > const & herd ) const
{ assert(any_a<>::___handle___); return ___read___().operator==(herd); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool unordered_herd_a<_element>::___unordered_herd_a_handle___<___TTT___, ___DHB___>::operator==(unordered_herd_a < _element > const & herd ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator==(herd); }

template <typename _element>
inline bool unordered_herd_a<_element>::operator!=(unordered_herd_a < _element > const & herd ) const
{ assert(any_a<>::___handle___); return ___read___().operator!=(herd); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool unordered_herd_a<_element>::___unordered_herd_a_handle___<___TTT___, ___DHB___>::operator!=(unordered_herd_a < _element > const & herd ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.operator!=(herd); }

template <typename _element>
inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > unordered_herd_a<_element>::extract_begin() const
{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > unordered_herd_a<_element>::___unordered_herd_a_handle___<___TTT___, ___DHB___>::extract_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

template <typename _element>
inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > unordered_herd_a<_element>::extract_end() const
{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_data_a < _element , typename std_unordered_set < _element > :: const_iterator > unordered_herd_a<_element>::___unordered_herd_a_handle___<___TTT___, ___DHB___>::extract_end() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

template <typename _element>
inline std_unordered_set < _element > const & unordered_herd_a<_element>::extract_set() const
{ assert(any_a<>::___handle___); return ___read___().extract_set(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline std_unordered_set < _element > const & unordered_herd_a<_element>::___unordered_herd_a_handle___<___TTT___, ___DHB___>::extract_set() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_set(); }

template <typename _element>
inline std_unordered_set < _element > & unordered_herd_a<_element>::mutate_set()
{ assert(any_a<>::___handle___); return ___write___().mutate_set(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline std_unordered_set < _element > & unordered_herd_a<_element>::___unordered_herd_a_handle___<___TTT___, ___DHB___>::mutate_set()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_set(); }

template <typename _element>
inline cat_a<> unordered_herd_a<_element>::___cat___()
{
	static cat_a<> CAT = cat_create<cat_a<>>(1, "strange::unordered_herd");
	return CAT;
}

template <typename _element>
inline unordered_herd_a<> unordered_herd_a<_element>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = herd_a< _element >::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _element>
inline kind_a<> unordered_herd_a<_element>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___());
	return KIND;
}

template <typename _element>
inline unordered_herd_a<> unordered_herd_a<_element>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = herd_a< _element >::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _element>
inline unordered_shoal_a<> unordered_herd_a<_element>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = herd_a< _element >::___operations___();
		return operations;
	}();
	return OPERATIONS;
}

class ___unordered_herd_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___unordered_herd_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element>
inline unordered_herd_d<_element> ___unordered_herd_dynamic___(any_a<> const& thing)
{
	return unordered_herd_d<_element>{ thing };
}

} // namespace
