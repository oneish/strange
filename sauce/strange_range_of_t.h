#ifndef COM_ONEISH_STRANGE_RANGE_OF_T_H
#define COM_ONEISH_STRANGE_RANGE_OF_T_H

namespace strange
{

template <typename _element_ = any_a<>, typename ___ego___ = range_of_a<_element_>>
class range_of_t : public thing_t<___ego___>
{
public:
	// override
	using over = range_o<range_of_t<_element_>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			return create_();
		}
		any_a<> begin = *it;
		if (!check<forward_const_iterator_a<>>(begin))
		{
			throw dis("strange::range_of::create passed non-iterator begin");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::range_of::create passed short range");
		}
		any_a<> end = *it;
		if (!check<forward_const_iterator_a<>>(end))
		{
			throw dis("strange::range_of::create passed non-iterator end");
		}
		return create_(cast<forward_const_iterator_a<>>(begin), cast<forward_const_iterator_a<>>(end));
	}

	static inline range_of_a<_element_> create_()
	{
		static range_of_a<_element_> VAL = range_of_t<_element_>::create_(it_t<>::create_(), it_t<>::create_());
		return VAL;
	}

	static inline range_of_a<_element_> create_(forward_const_iterator_a<> const& begin, forward_const_iterator_a<> const& end)
	{
		return range_of_a<_element_>{ over{ range_of_t<_element_>(begin, end) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<range_of_t<_element_>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<range_of_t<_element_>>::share(shoal);
	}

	// range
	inline forward_const_iterator_a<> cbegin_() const
	{
		return _begin;
	}

	inline forward_const_iterator_a<> cend_() const
	{
		return _end;
	}

protected:
	forward_const_iterator_a<> _begin;
	forward_const_iterator_a<> _end;

	inline range_of_t(forward_const_iterator_a<> const& begin, forward_const_iterator_a<> const& end)
		: thing_t{}
		, _begin(begin)
		, _end(end)
	{}

private:
	static bool const ___share___;
	friend class ___range_of_t_share___;
};

template <typename _element_, typename ___ego___>
bool const range_of_t<_element_, ___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	range_of_t<_element_, ___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
