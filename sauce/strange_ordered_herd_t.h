#ifndef COM_ONEISH_STRANGE_ORDERED_HERD_T_H
#define COM_ONEISH_STRANGE_ORDERED_HERD_T_H

namespace strange
{

template <bool CONCURRENT = false, typename _ABSTRACTION_ = ordered_herd_a<>>
class ordered_herd_t : public thing_t<_ABSTRACTION_>
{
	template <typename ITERATOR, typename _ABSTRACTION_ = bidirectional_const_iterator_data_a<ITERATOR>>
	class const_iterator_t : public thing_t<_ABSTRACTION_>
	{
	public: ___STRANGE_THING___
		// construction
		template <typename F>
		static inline bidirectional_const_iterator_data_a<ITERATOR> val(ordered_herd_a<> const& ordered_herd, F&& it)
		{
			return bidirectional_const_iterator_data_a<ITERATOR>{ const_iterator_t(ordered_herd, std::forward<F>(it)) };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::ordered_herd::const_iterator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check<bidirectional_const_iterator_data_a<ITERATOR>>(thing))
			{
				return false;
			}
			return _it == cast<bidirectional_const_iterator_data_a<ITERATOR>>(thing).extract();
		}

		inline std::size_t hash() const
		{
			return std::hash<void const*>{}(&*_it);
		}

		// forward iterator
		inline any_a<> get__(range_a<> const&) const
		{
			return get_();
		}

		inline any_a<> get_() const
		{
			return *_it;
		}

		inline any_a<> const* operator->() const
		{
			return &operator*();
		}

		inline any_a<> const& operator*() const
		{
			return *_it;
		}

		inline _ABSTRACTION_ increment__(range_a<> const&)
		{
			return increment_();
		}

		inline _ABSTRACTION_ increment_()
		{
			operator++();
			return me_();
		}

		inline const_iterator_t& operator++()
		{
			++_it;
			return *this;
		}

		inline const_iterator_t operator++(int)
		{
			const_iterator_t result = *this;
			operator++();
			return result;
		}

		// bidirectional iterator
		inline _ABSTRACTION_ decrement__(range_a<> const& _)
		{
			return decrement_();
		}

		inline _ABSTRACTION_ decrement_()
		{
			operator--();
			return me_();
		}

		inline const_iterator_t& operator--()
		{
			--_it;
			return *this;
		}

		inline const_iterator_t operator--(int)
		{
			const_iterator_t result = *this;
			operator--();
			return result;
		}

		// data
		inline ITERATOR const& extract() const
		{
			return _it;
		}

		inline void mutate(ITERATOR const& it)
		{
			_it = it;
		}

		inline ITERATOR& reference()
		{
			return _it;
		}

	protected:
		ITERATOR _it;
		ordered_herd_a<> _ordered_herd;

		template <typename F>
		inline const_iterator_t(ordered_herd_a<> const& ordered_herd, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _ordered_herd(ordered_herd, true)
		{}
	};

public: ___STRANGE_COLLECTION___
	using std_set_any = std::set<any_a<>>;

	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		return val_() += range;
	}

	static inline ordered_herd_a<> val_()
	{
		return val(std_set_any{});
	}

	template <typename... Args>
	static inline ordered_herd_a<> val_(Args&&... args)
	{
		return val(variadic_u<>::set(std::forward<Args>(args)...));
	}

	template <typename F>
	static inline ordered_herd_a<> val(F&& init)
	{
		return ordered_herd_a<>{ ordered_herd_t{ std::forward<F>(init) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<ordered_herd_t<CONCURRENT>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<ordered_herd_t<CONCURRENT>>::share(shoal);
	}

	// visitor pattern
	inline any_a<> visit__(range_a<> const& range) const
	{
		if (!check<flock_a<>>(range))
		{
			throw dis("strange::ordered_herd::visit passed non-flock");
		}
		return visit_(cast<flock_a<>>(range, true));
	}

	inline any_a<> visit_(flock_a<>& flock) const
	{
		auto result = thing_t<>::visit_(flock);
		if (result)
		{
			auto last = flock.size() - 1;
			typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
			for (auto const& visited : _set)
			{
				flock.update(last, visited);
				visited.visit_(flock);
			}
		}
		return result;
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<ordered_herd_a<>>(thing))
		{
			return false;
		}
		typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
		return _set == cast<ordered_herd_a<>>(thing).extract();
	}

	inline std::size_t hash() const
	{
		typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
		std::size_t seed = std::hash<std::size_t>{}(_set.size());
		for (auto const& item : _set)
		{
			seed ^= item.hash() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline bidirectional_const_iterator_a<> cbegin_() const
	{
		return const_iterator_t<std_set_any::const_iterator>::val(me_(), _set.cbegin());
	}

	inline bidirectional_const_iterator_a<> cend_() const
	{
		return const_iterator_t<std_set_any::const_iterator>::val(me_(), _set.cend());
	}

	// collection
	inline bool has(any_a<> const& key) const
	{
		typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
		std_set_any::const_iterator const it = _set.find(key);
		return it != _set.cend();
	}

	inline bool has_string(std::string const& s) const
	{
		return has(sym(s));
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
		std_set_any::const_iterator const it = _set.find(key);
		if (it == _set.cend())
		{
			return misunderstanding_t<>::val("strange::ordered_herd::at key not found");
		}
		return *it;
	}

	inline bool at_string(std::string const& s) const
	{
		typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
		std_set_any::const_iterator const it = _set.find(sym(s));
		return it != _set.cend();
	}

	inline void update(any_a<> const& key, any_a<> const&)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		_set.insert(key);
	}

	inline bool insert(any_a<> const& key, any_a<> const&)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		return _set.insert(key).second;
	}

	inline bool insert(any_a<> const& key)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		return _set.insert(key).second;
	}

	inline bool insert_string(std::string const& s)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		return _set.insert(sym(s)).second;
	}

	inline bool erase(any_a<> const& key)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		return _set.erase(key);
	}

	inline bool erase_string(std::string const& s)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		return _set.erase(sym(s));
	}

	inline void clear()
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		_set.clear();
	}

	inline int64_t size() const
	{
		typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
		return int64_t(_set.size());
	}

	inline bool empty() const
	{
		typename concurrent_u<CONCURRENT>::read_lock lock(_mutex);
		return _set.empty();
	}

	inline void push_front(any_a<> const& thing)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		_set.insert(thing);
	}

	inline any_a<> pop_front_()
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		std_set_any::const_iterator const it = _set.cbegin();
		if (it == _set.cend())
		{
			return no();
		}
		any_a<> result = *it;
		_set.erase(it);
		return result;
	}

	inline void push_back(any_a<> const& thing)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		_set.insert(thing);
	}

	inline any_a<> pop_back_()
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		std_set_any::const_iterator it = _set.cend();
		if (it == _set.cbegin())
		{
			return no();
		}
		any_a<> result = *--it;
		_set.erase(it);
		return result;
	}

	inline ordered_herd_t& operator+=(any_a<> const& range)
	{
		if (check<ordered_herd_a<>>(range))
		{
			auto other = cast<ordered_herd_a<>>(range).extract();
			typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
			_set.insert(other.cbegin(), other.cend());
		}
		else if (check<unordered_herd_a<>>(range))
		{
			auto other = cast<unordered_herd_a<>>(range).extract();
			typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
			_set.insert(other.cbegin(), other.cend());
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::ordered_herd += passed non-range");
			}
			typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
			for (auto const& thing : cast<range_a<>>(range))
			{
				_set.insert(thing);
			}
		}
		return *this;
	}

	inline ordered_herd_t& operator-=(any_a<> const& range)
	{
		if (!check<range_a<>>(range))
		{
			throw dis("strange::ordered_herd -= passed non-range");
		}
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		for (auto const& thing : cast<range_a<>>(range))
		{
			_set.erase(thing);
		}
		return *this;
	}

	// data
	inline std_set_any const& extract() const
	{
		return _set;
	}

	inline void mutate(std_set_any const& data)
	{
		typename concurrent_u<CONCURRENT>::write_lock lock(_mutex);
		_set = data;
	}

	inline std_set_any& reference()
	{
		return _set;
	}

protected:
	mutable typename concurrent_u<CONCURRENT>::mutex _mutex;
	std_set_any _set;

	template <typename F>
	inline ordered_herd_t(F&& init)
		: thing_t{}
		, _set{ std::forward<F>(init) }
	{}

public:
	inline ordered_herd_t(ordered_herd_t const& other)
		: _set{ other._set }
	{}

	inline ordered_herd_t(ordered_herd_t&& other)
		: _set{ std::move(other._set) }
	{}
};

} // namespace strange

#endif
