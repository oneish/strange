
namespace strange
{

template <typename _element>
inline bool inventory_a<_element>::has_index(int64_t index ) const
{ assert(any_a<>::___handle___); return ___read___().has_index(index); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::has_index(int64_t index ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.has_index(index); }

template <typename _element>
inline _element inventory_a<_element>::at_index(int64_t index ) const
{ assert(any_a<>::___handle___); return ___read___().at_index(index); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::at_index(int64_t index ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.at_index(index); }

template <typename _element>
inline void inventory_a<_element>::update_index(int64_t index , _element const & value )
{ assert(any_a<>::___handle___); ___write___().update_index(index, value); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::update_index(int64_t index , _element const & value )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update_index(index, value); }

template <typename _element>
inline bool inventory_a<_element>::insert_index(int64_t index , _element const & value )
{ assert(any_a<>::___handle___); return ___write___().insert_index(index, value); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::insert_index(int64_t index , _element const & value )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_index(index, value); }

template <typename _element>
inline bool inventory_a<_element>::erase_index(int64_t index )
{ assert(any_a<>::___handle___); return ___write___().erase_index(index); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::erase_index(int64_t index )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.erase_index(index); }

template <typename _element>
inline any_a<> inventory_a<_element>::mutate_begin__(list_a<> const& ___arguments___)
{
	return mutate_begin_();
}

template <typename _element>
inline random_access_mutator_a< _element > inventory_a<_element>::mutate_begin_()
{ assert(any_a<>::___handle___); return ___write___().mutate_begin_(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline random_access_mutator_a< _element > inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::mutate_begin_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_begin_(); }

template <typename _element>
inline any_a<> inventory_a<_element>::mutate_end__(list_a<> const& ___arguments___)
{
	return mutate_end_();
}

template <typename _element>
inline random_access_mutator_a< _element > inventory_a<_element>::mutate_end_()
{ assert(any_a<>::___handle___); return ___write___().mutate_end_(); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline random_access_mutator_a< _element > inventory_a<_element>::___inventory_a_handle___<___TTT___, ___DHB___>::mutate_end_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_end_(); }

template <typename _element>
inline cat_a<> inventory_a<_element>::___cat___()
{
	static cat_a<> CAT = cat_create(1, "strange::inventory");
	return CAT;
}

template <typename _element>
inline unordered_herd_a<> inventory_a<_element>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = collection_a< number_data_int64_a<> , _element , _element >::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _element>
inline kind_a<> inventory_a<_element>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___());
	return KIND;
}

template <typename _element>
inline unordered_herd_a<> inventory_a<_element>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = collection_a< number_data_int64_a<> , _element , _element >::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _element>
inline unordered_shoal_a<> inventory_a<_element>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = collection_a< number_data_int64_a<> , _element , _element >::___operations___();
		operations.update(sym("mutate_begin_"), native_mutation::create(&inventory_a::mutate_begin__));
		operations.update(sym("mutate_end_"), native_mutation::create(&inventory_a::mutate_end__));
		return operations;
	}();
	return OPERATIONS;
}

class ___inventory_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___inventory_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element>
inline inventory_d<_element> ___inventory_dynamic___(any_a<> const& thing)
{
	return inventory_d<_element>{ thing };
}

} // namespace
