#ifndef COM_ONEISH_STRANGE_THING_T_H
#define COM_ONEISH_STRANGE_THING_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class thing_t : public one_t
{
public:
	// erasure
	inline _ABSTRACTION_ const me_() const
	{
		return _ABSTRACTION_(_meek.lock(), true);
	}

	inline _ABSTRACTION_ me_()
	{
		return _ABSTRACTION_(_meek.lock(), true);
	}

	// reflection
	static inline any_a<> cat__(range_a<> const&)
	{
		return cat_();
	}
	
	static inline cat_a<> cat_()
	{
		return reflection<_ABSTRACTION_>::cat();
	}

	static inline any_a<> cats__(range_a<> const&)
	{
		return cats_();
	}

	static inline unordered_herd_a<> cats_()
	{
		return reflection<_ABSTRACTION_>::cats();
	}

	static inline any_a<> operations__(range_a<> const&)
	{
		return operations_();
	}
	
	static inline unordered_shoal_a<> operations_()
	{
		return reflection<_ABSTRACTION_>::operations();
	}

	static inline any_a<> eater_()
	{
		return no();
	}

	static inline any_a<> feeder__(range_a<> const& range)
	{
		return no();
	}

	// visitor pattern
	static inline any_a<> visit__(range_a<> const& range)
	{
		return operate__(range);
	}

	static inline any_a<> visit_(inventory_a<>& inventory)
	{
		return operate__(inventory);
	}

	// function
	static inline any_a<> invoke__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::thing::invoke passed empty range");
		}
		any_a<> thing(*it, true);
		if (++it == range.cend_())
		{
			throw dis("strange::thing::invoke passed short range");
		}
		any_a<> member = *it;
		return invoke(thing, member, range_t<>::val_(++it, range.cend_()));
	}

	static inline any_a<> invoke_(any_a<>& thing, range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::thing::invoke passed short range");
		}
		any_a<> member = *it;
		return invoke(thing, member, range_t<>::val_(++it, range.cend_()));
	}

	static inline any_a<> invoke(any_a<>& thing, any_a<> const& member, range_a<> const& range)
	{
		if (!thing.operations_().has_(member))
		{
			throw dis("strange::thing::invoke passed non-existent member");
		}
		return thing.operations_().at_(member).operate_(thing, range);
	}

	static inline any_a<> operate__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::thing::operate passed empty range");
		}
		any_a<> thing(*it, true);
		if (++it == range.cend_())
		{
			throw dis("strange::thing::operate passed short range");
		}
		any_a<> operation = *it;
		return operation.operate_(thing, range_t<>::val_(++it, range.cend_()));
	}

	static inline any_a<> operate_(any_a<>& thing, range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::thing::operate passed short range");
		}
		any_a<> operation = *it;
		return operation.operate_(thing, range_t<>::val_(++it, range.cend_()));
	}

	// identification
	inline any_a<> identity__(range_a<> const&) const
	{
		return identity_();
	}

	inline number_data_a<uint64_t> identity_() const
	{
		return number_uint_64_t<>::val(uint64_t(identity()));
	}

	inline any_a<> identical__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::thing::identical passed empty range");
		}
		return identical_(*it);
	}

	inline any_a<> identical_(any_a<> const& thing) const
	{
		return boole(identical(thing));
	}

	// comparison
	static inline any_a<> nothing__(range_a<> const&)
	{
		return nothing_();
	}

	static inline any_a<> nothing_()
	{
		return no();
	}

	static inline any_a<> something__(range_a<> const&)
	{
		return something_();
	}

	static inline any_a<> something_()
	{
		return yes();
	}

	// conversion
	inline range_a<> ranged_() const
	{
		return range_t<>::val_(it_t<true>::val_(me_()), it_t<true>::val_());
	}

protected:
	// construction
	inline thing_t()
		: one_t{}
	{}
};

} // namespace strange

#endif
