#ifndef COM_ONEISH_STRANGE_IT_T_H
#define COM_ONEISH_STRANGE_IT_T_H

namespace strange
{

template <typename _element = any_a<>, typename ___ego___ = forward_extractor_a<_element>>
class it_t : public thing_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const&)
	{
		return create_();
	}

	static inline forward_extractor_a<_element> create_()
	{
		static auto VAL = forward_extractor_a<_element>::template create<it_t<_element>>();
		return VAL;
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::it");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::it::create", native_function_create(&it_t<>::create__));
	}

	// comparison
	inline bool same_(any_a<> const& thing) const
	{
		return check<forward_extractor_a<_element>>(thing);
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std::size_t hash() const
	{
		return no().hash();
	}

	// forward extractor
	inline any_a<> get_() const
	{
		return no();
	}

	inline any_a<> const* operator->() const
	{
		return &operator*();
	}

	inline any_a<> const& operator*() const
	{
		static any_a<> NO = no();
		return NO;
	}

	inline void increment_()
	{}

protected:
	friend class any_a<>;

	inline it_t()
		: thing_t<___ego___>{}
	{}

private:
	static bool const ___share___;
	friend class ___it_t_share___;
};

template <typename _element, typename ___ego___>
bool const it_t<_element, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	it_t<_element, ___ego___>::share(shoal);
	return shoal;
}();

class ___it_t_share___
{
	static inline bool ___share___()
	{
		return it_t<>::___share___;
	}
};

} // namespace strange

#endif
