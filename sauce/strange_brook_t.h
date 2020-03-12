#ifndef COM_ONEISH_STRANGE_BROOK_T_H
#define COM_ONEISH_STRANGE_BROOK_T_H

namespace strange
{

template <typename _primitive_, bool _concurrent_ = false, typename ___ego___ = brook_a<_primitive_>>
class brook_t : public thing_t<___ego___>
{
	template <typename _iterator_, typename ___ego_it___ = random_access_mutator_data_a<_iterator_>>
	class mutator_t : public thing_t<___ego_it___>
	{
	public:
		// override
		using over = thing_o<mutator_t<_iterator_>>;

		// construction
		template <typename F>
		static inline random_access_mutator_data_a<_iterator_> create(brook_t const& brook_thing, F&& it)
		{
			return random_access_mutator_data_a<_iterator_>::template create<over>(mutator_t<_iterator_>(brook_thing, std::forward<F>(it)));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::brook::mutator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_iterator_>>(thing) &&
				_it == fast<random_access_mutator_data_a<_iterator_>>(thing).extract_it();
		}

		inline std::size_t hash() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			return std::hash<void const*>{}(&*_it);
		}

		// forward mutator
		inline any_a<> get_() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			return num(*_it);
		}

		inline any_a<> set_(any_a<> const& thing) const
		{
			if (!check<number_a<>>(thing))
			{
				throw dis("strange::brook::mutator set passed non-number");
			}
			typename concurrent_u<_concurrent_>::write_lock lock(_brook_thing._mutex);
			*_it = number_u<_primitive_>::from_number(cast<number_a<>>(thing));
			return thing;
		}

		inline any_a<>* operator->() const
		{
			return &operator*();
		}

		inline any_a<>& operator*() const
		{
			_brook_thing._shadow.resize(_brook_thing._deque.size());
			auto& number = _brook_thing._shadow[_it - _brook_thing._deque.begin()];
			auto& primitive = *_it;
			if (!check<any_a<>>(number) || &number.extract_primitive() != &primitive)
			{
				number = number_reference_t<_primitive_>::create(primitive);
			}
			// assigning to this reference won't change the collection
			// assigning from this reference will create a shared non-const reference
			return number;
		}

		inline void increment_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			++_it;
		}

		// bidirectional mutator
		inline void decrement_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			--_it;
		}

		// random access mutator
		inline void self_add_(number_a<> const& number)
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			_it += number.to_int_64();
		}

		inline random_access_mutator_a<> add_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			result.mutate_it() += number.to_int_64();
			return result;
		}

		inline void self_subtract_(number_a<> const& number)
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			_it -= number.to_int_64();
		}

		inline random_access_mutator_a<> subtract_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			result.mutate_it() -= number.to_int_64();
			return result;
		}

		inline bool less_than_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_iterator_>>(thing)
				? _it < fast<random_access_mutator_data_a<_iterator_>>(thing).extract_it()
				: one_t::less_than_(thing);
		}

		inline bool greater_than_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_iterator_>>(thing)
				? _it > fast<random_access_mutator_data_a<_iterator_>>(thing).extract_it()
				: one_t::greater_than_(thing);
		}

		inline bool less_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_iterator_>>(thing)
				? _it <= fast<random_access_mutator_data_a<_iterator_>>(thing).extract_it()
				: one_t::less_or_equal_(thing);
		}

		inline bool greater_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_mutator_data_a<_iterator_>>(thing)
				? _it >= fast<random_access_mutator_data_a<_iterator_>>(thing).extract_it()
				: one_t::greater_or_equal_(thing);
		}

		// data
		inline _iterator_ const& extract_it() const
		{
			return _it;
		}

		inline _iterator_& mutate_it()
		{
			return _it;
		}

	protected:
		_iterator_ _it;
		brook_t const& _brook_thing;

		template <typename F>
		inline mutator_t(brook_t const& brook_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _brook_thing{ brook_thing }
		{}
	};

	template <typename _iterator_, typename ___ego_it___ = random_access_extractor_data_a<_iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// override
		using over = thing_o<extractor_t<_iterator_>>;

		// construction
		template <typename F>
		static inline random_access_extractor_data_a<_iterator_> create(brook_a<_primitive_> const& brook, brook_t const& brook_thing, F&& it)
		{
			return random_access_extractor_data_a<_iterator_>::template create<over>(extractor_t<_iterator_>(brook, brook_thing, std::forward<F>(it)));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::brook::extractor");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_iterator_>>(thing) &&
				_it == fast<random_access_extractor_data_a<_iterator_>>(thing).extract_it();
		}

		inline std::size_t hash() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			return std::hash<void const*>{}(&*_it);
		}

		// forward mutator
		inline any_a<> get_() const
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			return num(*_it);
		}

		inline any_a<> const* operator->() const
		{
			return &operator*();
		}

		inline any_a<> const& operator*() const
		{
			_brook_thing._shadow.resize(_brook_thing._deque.size());
			auto& number = _brook_thing._shadow[_it - _brook_thing._deque.cbegin()];
			auto& primitive = const_cast<_primitive_&>(*_it);
			if (!check<any_a<>>(number) || &number.extract_primitive() != &primitive)
			{
				number = number_reference_t<_primitive_>::create(primitive);
			}
			// assigning from this reference will create a shared non-const reference
			return number;
		}

		inline void increment_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			++_it;
		}

		// bidirectional mutator
		inline void decrement_()
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			--_it;
		}

		// random access mutator
		inline void self_add_(number_a<> const& number)
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			_it += number.to_int_64();
		}

		inline random_access_extractor_a<> add_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			result.mutate_it() += number.to_int_64();
			return result;
		}

		inline void self_subtract_(number_a<> const& number)
		{
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			_it -= number.to_int_64();
		}

		inline random_access_extractor_a<> subtract_(number_a<> const& number) const
		{
			___ego_it___ result = thing_t<___ego_it___>::me_();
			typename concurrent_u<_concurrent_>::read_lock lock(_brook_thing._mutex);
			result.mutate_it() -= number.to_int_64();
			return result;
		}

		inline bool less_than_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_iterator_>>(thing)
				? _it < fast<random_access_extractor_data_a<_iterator_>>(thing).extract_it()
				: one_t::less_than_(thing);
		}

		inline bool greater_than_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_iterator_>>(thing)
				? _it > fast<random_access_extractor_data_a<_iterator_>>(thing).extract_it()
				: one_t::greater_than_(thing);
		}

		inline bool less_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_iterator_>>(thing)
				? _it <= fast<random_access_extractor_data_a<_iterator_>>(thing).extract_it()
				: one_t::less_or_equal_(thing);
		}

		inline bool greater_or_equal_(any_a<> const& thing) const
		{
			return check<random_access_extractor_data_a<_iterator_>>(thing)
				? _it >= fast<random_access_extractor_data_a<_iterator_>>(thing).extract_it()
				: one_t::greater_or_equal_(thing);
		}

		// data
		inline _iterator_ const& extract_it() const
		{
			return _it;
		}

		inline _iterator_& mutate_it()
		{
			return _it;
		}

	protected:
		_iterator_ _it;
		brook_a<_primitive_> const _brook;
		brook_t const& _brook_thing;

		template <typename F>
		inline extractor_t(brook_a<_primitive_> const& brook, brook_t const& brook_thing, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _brook{ brook }
			, _brook_thing{ brook_thing }
		{}
	};

public:
	using std_deque_number = std::deque<_primitive_>;

	// override
	using over = collection_o<brook_t<_primitive_, _concurrent_>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return create_() += range;
	}

	static inline brook_a<_primitive_> create_()
	{
		return create(std_deque_number{});
	}

	template <typename... Args>
	static inline brook_a<_primitive_> create_(Args&&... args)
	{
		return create(variadic_u<_primitive_>::deque(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline brook_a<_primitive_> create_refs_(Args&&... args)
	{
		return create(variadic_u<_primitive_>::deque_ref(std::forward<Args>(args)...));
	}

	template <typename... Args>
	static inline brook_a<_primitive_> create_dups_(Args&&... args)
	{
		return create(variadic_u<_primitive_>::deque_dup(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline brook_a<_primitive_> create(F&& init)
	{
		return brook_a<_primitive_>::template create<over>(brook_t<_primitive_, _concurrent_>{ std::forward<F>(init) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::brook_" + number_u<_primitive_>::category() +
			(_concurrent_ ? "_concurrent" : ""));
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type_().to_string() + "::create", native_function_create(&brook_t<_primitive_, _concurrent_>::create__));
	}

	// comparison
	inline bool same_(any_a<> const& thing) const
	{
		if (!check<brook_a<_primitive_>>(thing))
		{
			return false;
		}
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque == cast<brook_a<_primitive_>>(thing).extract_deque();
	}

	inline std::size_t hash() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std::size_t seed = std::hash<std::size_t>{}(_deque.size());
		for (auto item : _deque)
		{
			seed ^= std::hash<_primitive_>{}(item) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline random_access_extractor_a<> extract_begin_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<typename std_deque_number::const_iterator>::create(thing_t<___ego___>::me_(), *this, _deque.cbegin());
	}

	inline random_access_extractor_a<> extract_end_() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return extractor_t<typename std_deque_number::const_iterator>::create(thing_t<___ego___>::me_(), *this, _deque.cend());
	}

	inline random_access_mutator_a<> mutate_begin_()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<typename std_deque_number::iterator>::create(*this, _deque.begin());
	}

	inline random_access_mutator_a<> mutate_end_()
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return mutator_t<typename std_deque_number::iterator>::create(*this, _deque.end());
	}

	// collection
	inline bool has(any_a<> const& key) const
	{
		return check<number_a<>>(key) && has_index(cast<number_a<>>(key).to_int_64());
	}

	inline bool has_index(int64_t index) const
	{
		return index >= 0 && index < size();
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		if (check<number_a<>>(key))
		{
			return at_index(cast<number_a<>>(key).to_int_64());
		}
		return at_index(-1);
	}

	inline any_a<> at_index(int64_t index) const
	{
		return num(pat(index));
	}

	inline _primitive_ pat(int64_t index) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		if (index >= 0 && index < int64_t(_deque.size()))
		{
			return _deque[std::size_t(index)];
		}
		return _primitive_{};
	}

	inline void update(any_a<> const& key, any_a<> const& value)
	{
		if (check<number_a<>>(key))
		{
			update_index(cast<number_a<>>(key).to_int_64(), value);
		}
	}

	inline void update_index(int64_t index, any_a<> const& value)
	{
		if (!check<number_a<>>(value))
		{
			throw dis("strange::brook::update passed non-number value");
		}
		return pupdate(index, number_u<_primitive_>::from_number(cast<number_a<>>(value)));
	}

	inline void pupdate(int64_t index, _primitive_ number)
	{
		if (index >= 0)
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			int64_t const siz = int64_t(_deque.size());
			if (index == siz)
			{
				_deque.push_back(number);
			}
			else
			{
				if (index > siz)
				{
					_deque.resize(std::size_t(index) + 1, no());
				}
				_deque[std::size_t(index)] = number;
			}
		}
	}

	inline bool insert(any_a<> const& key, any_a<> const& value)
	{
		return check<number_a<>>(key) && insert_index(cast<number_a<>>(key).to_int_64(), value);
	}

	inline bool insert_index(int64_t index, any_a<> const& value)
	{
		if (!check<number_a<>>(value))
		{
			throw dis("strange::brook::insert passed non-number value");
		}
		return pinsert(index, number_u<_primitive_>::from_number(cast<number_a<>>(value)));
	}

	inline bool pinsert(int64_t index, _primitive_ number)
	{
		if (index >= 0)
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			int64_t const siz = int64_t(_deque.size());
			if (index == siz)
			{
				_deque.push_back(number);
			}
			else
			{
				if (index > siz)
				{
					_deque.resize(std::size_t(index) + 1, no());
					_deque[std::size_t(index)] = number;
				}
				else
				{
					_deque.insert(_deque.cbegin() + index, number);
				}
			}
			return true;
		}
		return false;
	}

	inline bool erase(any_a<> const& key)
	{
		return check<number_a<>>(key) && erase_index(cast<number_a<>>(key).to_int_64());
	}

	inline bool erase_index(int64_t index)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (index >= 0 && index < int64_t(_deque.size()))
		{
			_deque.erase(_deque.cbegin() + index);
			return true;
		}
		return false;
	}

	inline void clear()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque.clear();
	}

	inline int64_t size() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return int64_t(_deque.size());
	}

	inline bool empty() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _deque.empty();
	}

	inline void push_front(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::brook::push_front passed non-number");
		}
		push_front(number_u<_primitive_>::from_number(cast<number_a<>>(thing)));
	}

	inline void push_front(_primitive_ number)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque.push_front(number);
	}

	inline any_a<> pop_front_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (_deque.empty())
		{
			return no();
		}
		_primitive_ number = _deque.front();
		_deque.pop_front();
		return num(number);
	}

	inline _primitive_ pop_front()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_primitive_ number = _deque.front();
		_deque.pop_front();
		return number;
	}

	inline void push_back(any_a<> const& thing)
	{
		if (!check<number_a<>>(thing))
		{
			throw dis("strange::brook::push_back passed non-number");
		}
		push_back(number_u<_primitive_>::from_number(cast<number_a<>>(thing)));
	}

	inline void push_back(_primitive_ number)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_deque.push_back(number);
	}

	inline any_a<> pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		if (_deque.empty())
		{
			return no();
		}
		_primitive_ number = _deque.back();
		_deque.pop_back();
		return num(number);
	}

	inline _primitive_ pop_back()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_primitive_ number = _deque.back();
		_deque.pop_back();
		return number;
	}

	inline void self_assign_(range_a<> const& range)
	{
		if (check<brook_a<_primitive_>>(range))
		{
			auto const other = fast<brook_a<_primitive_>>(range);
			auto read_lock = other.read_lock_();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque = other.extract_deque();
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque.clear();
			for (auto const& thing : range)
			{
				_deque.push_back(thing);
			}
		}
	}

	inline void self_add_(range_a<> const& range)
	{
		if (check<brook_a<_primitive_>>(range))
		{
			auto const other = fast<brook_a<_primitive_>>(range);
			auto read_lock = other.read_lock_();
			auto const& other_deque = other.extract_deque();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			_deque.insert(_deque.cend(), other_deque.cbegin(), other_deque.cend());
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				_deque.push_back(thing);
			}
		}
	}

	inline void self_subtract_(range_a<> const& range)
	{
		if (check<collection_a<>>(range))
		{
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			_deque.resize(std::size_t(std::max<int64_t>(0, int64_t(_deque.size()) - fast<collection_a<>>(range).size())));
		}
		else
		{
			auto read_lock = check<collection_a<>>(range) ? fast<collection_a<>>(range).read_lock_() : no();
			typename concurrent_u<_concurrent_>::write_lock write_lock(_mutex);
			for (auto const& thing : range)
			{
				if (_deque.empty())
				{
					break;
				}
				_deque.pop_back();
			}
		}
	}

	inline any_a<> read_lock_() const
	{
		return data_t<read_lock_ptr<_concurrent_>>::create(make_read_lock_ptr<_concurrent_>(_mutex));
	}

	inline any_a<> write_lock_() const
	{
		return data_t<write_lock_ptr<_concurrent_>>::create(make_write_lock_ptr<_concurrent_>(_mutex));
	}

	// data
	inline std_deque_number const& extract_deque() const
	{
		return _deque;
	}

	inline std_deque_number& mutate_deque()
	{
		return _deque;
	}

protected:
	typename concurrent_u<_concurrent_>::mutex mutable _mutex;
	std_deque_number _deque;
	std::vector<number_data_a<_primitive_>> mutable _shadow;

	template <typename F>
	inline brook_t(F&& init)
		: thing_t<___ego___>{}
		, _mutex{}
		, _deque{ std::forward<F>(init) }
		, _shadow{}
	{}

public:
	inline brook_t(brook_t const& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _deque{ other._deque }
		, _shadow{}
	{}

	inline brook_t(brook_t&& other)
		: thing_t<___ego___>{}
		, _mutex{}
		, _deque{ std::move(other._deque) }
		, _shadow{}
	{}

private:
	static bool const ___share___;
	friend class ___brook_t_share___;
};

template <typename _primitive_, bool _concurrent_, typename ___ego___>
bool const brook_t<_primitive_, _concurrent_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	brook_t<_primitive_, _concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

template <bool _concurrent_ = false, typename ___ego___ = brook_a<int8_t>>
using brook_int_8_t = brook_t<int8_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<uint8_t>>
using brook_uint_8_t = brook_t<uint8_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<int16_t>>
using brook_int_16_t = brook_t<int16_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<uint16_t>>
using brook_uint_16_t = brook_t<uint16_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<int32_t>>
using brook_int_32_t = brook_t<int32_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<uint32_t>>
using brook_uint_32_t = brook_t<uint32_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<int64_t>>
using brook_int_64_t = brook_t<int64_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<uint64_t>>
using brook_uint_64_t = brook_t<uint64_t, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<float>>
using brook_float_32_t = brook_t<float, _concurrent_, ___ego___>;

template <bool _concurrent_ = false, typename ___ego___ = brook_a<double>>
using brook_float_64_t = brook_t<double, _concurrent_, ___ego___>;

class ___brook_t_share___
{
	static inline bool ___share___()
	{
		return brook_int_8_t<>::___share___
			&& brook_uint_8_t<>::___share___
			&& brook_int_16_t<>::___share___
			&& brook_uint_16_t<>::___share___
			&& brook_int_32_t<>::___share___
			&& brook_uint_32_t<>::___share___
			&& brook_int_64_t<>::___share___
			&& brook_uint_64_t<>::___share___
			&& brook_float_32_t<>::___share___
			&& brook_float_64_t<>::___share___
			&& brook_int_8_t<true>::___share___
			&& brook_uint_8_t<true>::___share___
			&& brook_int_16_t<true>::___share___
			&& brook_uint_16_t<true>::___share___
			&& brook_int_32_t<true>::___share___
			&& brook_uint_32_t<true>::___share___
			&& brook_int_64_t<true>::___share___
			&& brook_uint_64_t<true>::___share___
			&& brook_float_32_t<true>::___share___
			&& brook_float_64_t<true>::___share___;
	}
};

} // namespace strange

#endif
