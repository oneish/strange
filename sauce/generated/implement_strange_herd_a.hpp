
namespace strange
{

template <typename _element>
inline any_a<> herd_a<_element>::update_thing__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "herd_a::update_thing_ passed short range");
	}
	auto thing = cast< _element >(*___it___);
	return update_thing_(thing);
}

template <typename _element>
inline _element herd_a<_element>::update_thing_(_element const& thing)
{ assert(any_a<>::___handle___); return ___write___().update_thing_(thing); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element herd_a<_element>::___herd_a_handle___<___TTT___, ___DHB___>::update_thing_(_element const& thing)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update_thing_(thing); }

template <typename _element>
inline void herd_a<_element>::update_thing(_element const & thing )
{ assert(any_a<>::___handle___); ___write___().update_thing(thing); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void herd_a<_element>::___herd_a_handle___<___TTT___, ___DHB___>::update_thing(_element const & thing )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update_thing(thing); }

template <typename _element>
inline any_a<> herd_a<_element>::insert_thing__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "herd_a::insert_thing_ passed short range");
	}
	auto thing = cast< _element >(*___it___);
	return insert_thing_(thing);
}

template <typename _element>
inline any_a<> herd_a<_element>::insert_thing_(_element const& thing)
{ assert(any_a<>::___handle___); return ___write___().insert_thing_(thing); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> herd_a<_element>::___herd_a_handle___<___TTT___, ___DHB___>::insert_thing_(_element const& thing)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_thing_(thing); }

template <typename _element>
inline bool herd_a<_element>::insert_thing(_element const & thing )
{ assert(any_a<>::___handle___); return ___write___().insert_thing(thing); }

template <typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool herd_a<_element>::___herd_a_handle___<___TTT___, ___DHB___>::insert_thing(_element const & thing )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_thing(thing); }

template <typename _element>
inline cat_a<> herd_a<_element>::___cat___()
{
	static cat_a<> CAT = cat_create(1, "strange::herd");
	return CAT;
}

template <typename _element>
inline unordered_herd_a<> herd_a<_element>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = collection_a< _element , _element , _element >::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _element>
inline kind_a<> herd_a<_element>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___());
	return KIND;
}

template <typename _element>
inline unordered_herd_a<> herd_a<_element>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = collection_a< _element , _element , _element >::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _element>
inline unordered_shoal_a<> herd_a<_element>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = collection_a< _element , _element , _element >::___operations___();
		operations.update(sym("update_thing_"), native_mutation::create(&herd_a::update_thing__));
		operations.update(sym("insert_thing_"), native_mutation::create(&herd_a::insert_thing__));
		return operations;
	}();
	return OPERATIONS;
}

class ___herd_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___herd_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element>
inline herd_d<_element> ___herd_dynamic___(any_a<> const& thing)
{
	return herd_d<_element>{ thing };
}

} // namespace
