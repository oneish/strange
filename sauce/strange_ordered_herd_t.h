#ifndef COM_ONEISH_STRANGE_ORDERED_HERD_T_H
#define COM_ONEISH_STRANGE_ORDERED_HERD_T_H

namespace strange
{

template <bool _concurrent_ = false, typename ___ego___ = ordered_herd_a<>>
class ordered_herd_t : public thing_t<___ego___>
{
	template <typename _iterator_, typename ___ego___ = bidirectional_const_iterator_data_a<_iterator_>>
	class const_iterator_t : public thing_t<___ego___>
	{
	public:
		// override
		using over = thing_o<const_iterator_t<_iterator_>>;

		// construction
		template <typename F>
		static inline bidirectional_const_iterator_data_a<_iterator_> val(ordered_herd_a<> const& ordered_herd, F&& it)
		{
			return bidirectional_const_iterator_data_a<_iterator_>{ over{ const_iterator_t<_iterator_>(ordered_herd, std::forward<F>(it)) } };
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
			if (!check<bidirectional_const_iterator_data_a<_iterator_>>(thing))
			{
				return false;
			}
			return _it == cast<bidirectional_const_iterator_data_a<_iterator_>>(thing).extract();
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

		inline ___ego___ increment__(range_a<> const&)
		{
			return increment_();
		}

		inline ___ego___ increment_()
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
		inline ___ego___ decrement__(range_a<> const& _)
		{
			return decrement_();
		}

		inline ___ego___ decrement_()
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
		inline _iterator_ const& extract() const
		{
			return _it;
		}

		inline void mutate(_iterator_ const& it)
		{
			_it = it;
		}

		inline _iterator_& reference()
		{
			return _it;
		}

	protected:
		_iterator_ _it;
		ordered_herd_a<> _ordered_herd;

		template <typename F>
		inline const_iterator_t(ordered_herd_a<> const& ordered_herd, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _ordered_herd(ordered_herd, true)
		{}
	};

public:
	using std_set_any = std::set<any_a<>>;

	// override
	using over = collection_o<ordered_herd_t<_concurrent_>>;

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
		return ordered_herd_a<>{ over{ ordered_herd_t<_concurrent_>{ std::forward<F>(init) } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<ordered_herd_t<_concurrent_>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<ordered_herd_t<_concurrent_>>::share(shoal);
	}

	// visitor pattern
	inline any_a<> visit__(range_a<> const& range) const
	{
		if (!check<inventory_a<>>(range))
		{
			throw dis("strange::ordered_herd::visit passed non-inventory");
		}
		return visit_(cast<inventory_a<>>(range, true));
	}

	inline any_a<> visit_(inventory_a<>& inventory) const
	{
		auto result = thing_t<>::visit_(inventory);
		if (result)
		{
			auto last = inventory.size() - 1;
			typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
			for (auto const& visited : _set)
			{
				inventory.update_index(last, visited);
				visited.visit_(inventory);
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
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _set == cast<ordered_herd_a<>>(thing).extract();
	}

	inline std::size_t hash() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
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
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std_set_any::const_iterator const it = _set.find(key);
		return it != _set.cend();
	}

	inline bool has_string(std::string const& s) const
	{
		return has(sym(s));
	}

	inline any_a<> at_(any_a<> const& key) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std_set_any::const_iterator const it = _set.find(key);
		if (it == _set.cend())
		{
			return misunderstanding_t<>::val("strange::ordered_herd::at key not found");
		}
		return *it;
	}

	inline bool at_string(std::string const& s) const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		std_set_any::const_iterator const it = _set.find(sym(s));
		return it != _set.cend();
	}

	inline void update(any_a<> const& key, any_a<> const&)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set.insert(key);
	}

	inline bool insert(any_a<> const& key, any_a<> const&)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _set.insert(key).second;
	}

	inline bool insert(any_a<> const& key)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _set.insert(key).second;
	}

	inline bool insert_string(std::string const& s)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _set.insert(sym(s)).second;
	}

	inline bool erase(any_a<> const& key)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _set.erase(key);
	}

	inline bool erase_string(std::string const& s)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		return _set.erase(sym(s));
	}

	inline void clear()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set.clear();
	}

	inline int64_t size() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return int64_t(_set.size());
	}

	inline bool empty() const
	{
		typename concurrent_u<_concurrent_>::read_lock lock(_mutex);
		return _set.empty();
	}

	inline void push_front(any_a<> const& thing)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set.insert(thing);
	}

	inline any_a<> pop_front_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
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
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set.insert(thing);
	}

	inline any_a<> pop_back_()
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
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
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			_set.insert(other.cbegin(), other.cend());
		}
		else if (check<unordered_herd_a<>>(range))
		{
			auto other = cast<unordered_herd_a<>>(range).extract();
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
			_set.insert(other.cbegin(), other.cend());
		}
		else
		{
			if (!check<range_a<>>(range))
			{
				throw dis("strange::ordered_herd += passed non-range");
			}
			typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
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
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		for (auto const& thing : cast<range_a<>>(range))
		{
			_set.erase(thing);
		}
		return *this;
	}

	inline any_a<> read_lock_() const
	{
		return data_t<read_lock_ptr<_concurrent_>>::val(make_read_lock_ptr<_concurrent_>(_mutex));
	}

	inline any_a<> write_lock_() const
	{
		return data_t<write_lock_ptr<_concurrent_>>::val(make_write_lock_ptr<_concurrent_>(_mutex));
	}

	// data
	inline std_set_any const& extract() const
	{
		return _set;
	}

	inline void mutate(std_set_any const& data)
	{
		typename concurrent_u<_concurrent_>::write_lock lock(_mutex);
		_set = data;
	}

	inline std_set_any& reference()
	{
		return _set;
	}

protected:
	mutable typename concurrent_u<_concurrent_>::mutex _mutex;
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

private:
	static bool const ___share___;
	friend class ___ordered_herd_t_share___;
};

template <bool _concurrent_, typename ___ego___>
bool const ordered_herd_t<_concurrent_, ___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	ordered_herd_t<_concurrent_, ___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
