#ifndef COM_ONEISH_STRANGE_DATA_T_H
#define COM_ONEISH_STRANGE_DATA_T_H

namespace strange
{

// template <typename _data_, typename ___ego___ = data_a<_data_>>
template <typename _data_, typename ___ego___>
class data_t : public thing_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& _)
	{
		return create_();
	}

	static inline data_a<_data_> create_()
	{
		return create(_data_{});
	}

	static inline data_a<_data_> create(_data_ primitive)
	{
		return data_a<_data_>::template create<data_t<_data_>>(primitive);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::data");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		// nope: shoal.update(sym(type_().to_string() + "::create"), native_function_create(&data_t<std::shared_ptr<strange::concurrent_u<false>::read_lock>>::create__));
	}

	// comparison
	inline bool same_(any_a<> const& thing) const
	{
		return check<data_a<_data_>>(thing) &&
			_data == fast<data_a<_data_>>(thing).extract_data();
	}

	inline bool operator==(data_a<_data_> const& data) const
	{
		return _data == data.extract_data();
	}

	inline bool operator!=(data_a<_data_> const& data) const
	{
		return _data != data.extract_data();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std::size_t hash() const
	{
		return std::hash<_data_>{}(_data);
	}

	// data
	inline _data_ const& extract_data() const
	{
		return _data;
	}

	inline _data_& mutate_data()
	{
		return _data;
	}

protected:
	_data_ _data;

	friend class any_a<>;

	inline data_t(_data_ data)
		: thing_t<___ego___>{}
		, _data(data)
	{}

private:
	static bool const ___share___;
	friend class ___data_t_share___;
};

template <typename _data_, typename ___ego___>
bool const data_t<_data_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	data_t<_data_, ___ego___>::share(shoal);
	return shoal;
}();

class ___data_t_share___
{
	static inline bool ___share___()
	{
		return data_t<std::shared_ptr<strange::concurrent_u<false>::read_lock>>::___share___
			&& data_t<std::shared_ptr<strange::concurrent_u<true>::read_lock>>::___share___
			&& data_t<std::shared_ptr<strange::concurrent_u<false>::write_lock>>::___share___
			&& data_t<std::shared_ptr<strange::concurrent_u<true>::write_lock>>::___share___;
	}
};

} // namespace strange

#endif
