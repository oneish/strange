#ifndef COM_ONEISH_STRANGE_FLOCK_T_H
#define COM_ONEISH_STRANGE_FLOCK_T_H

#include <vector>

namespace strange
{

template <typename _ABSTRACTION_ = flock_a>
class flock_t : public something_t<_ABSTRACTION_>
{
	using std_vector_any = std::vector<any_a>;

	template <typename ITERATOR, typename _ABSTRACTION_ = data_a<ITERATOR>>
	class iterator_t : public something_t<_ABSTRACTION_>
	{
	public: ___THING___
		// construction
		static inline any_a val(any_a range)
		{
			assert(false);
			return nothing_t<>::val_();
		}

		template <typename F>
		static inline data_a<ITERATOR> val__(flock_a flock, F&& it)
		{
			return data_a<ITERATOR>{ iterator_t(std::move(flock), std::forward<F>(it)) };
		}

		static inline any_a ref(any_a range)
		{
			assert(false);
			return nothing_t<>::val_();
		}

		template <typename F>
		static inline data_a<ITERATOR> ref__(flock_a flock, F&& it)
		{
			return data_a<ITERATOR>(iterator_t(std::move(flock), std::forward<F>(it)), true);
		}

		// reflection
		static inline symbol_a type_()
		{
			static symbol_a TYPE = sym__("strange::flock::iterator");
			return TYPE;
		}

		// comparison
		inline bool operator==(any_a thing) const
		{
			if (!check_<data_a<ITERATOR>>(thing))
			{
				return false;
			}
			return _it == cast_<data_a<ITERATOR>>(thing).extract__();
			/*
			if (!type_().identical__(thing.type_()))
			{
				return false;
			}
			return _it == reinterpret_cast<const iterator_t<ITERATOR, _ABSTRACTION_>*>(thing.identity__())->_it;
			*/
		}

		inline bool operator!=(any_a thing) const
		{
			if (!check_<data_a<ITERATOR>>(thing))
			{
				return true;
			}
			return _it != cast_<data_a<ITERATOR>>(thing).extract__();
			/*
			if (!type_().identical__(thing.type_()))
			{
				return true;
			}
			return _it != reinterpret_cast<const iterator_t<ITERATOR, _ABSTRACTION_>*>(thing.identity__())->_it;
			*/
		}

		inline std::size_t hash__() const
		{
			return std::hash<const void*>{}(&*_it);
		}

		// iterator
		inline any_a& operator*() const
		{
			return const_cast<any_a&>(*_it);
		}

		inline iterator_t& operator++()
		{
			++_it;
			return *this;
		}

		inline iterator_t operator++(int)
		{
			iterator_t result = *this;
			operator++();
			return result;
		}

		//TODO random access iterator abstractions:
		inline _ABSTRACTION_ decrement(any_a _)
		{
			return decrement_();
		}

		inline _ABSTRACTION_ decrement_()
		{
			operator--();
			return me_();
		}

		inline iterator_t& operator--()
		{
			--_it;
			return *this;
		}

		inline iterator_t operator--(int)
		{
			iterator_t result = *this;
			operator--();
			return result;
		}

		inline _ABSTRACTION_ self_add(any_a range)
		{
			return self_add_();
		}

		inline _ABSTRACTION_ self_add_(any_a thing)
		{
			operator+=(std::move(thing));
			return me_();
		}

		inline iterator_t& operator+=(any_a thing)
		{
			return operator+=(0); //TODO index
		}

		inline iterator_t& operator+=(int64_t index)
		{
			_it += index;
			return *this;
		}

		inline _ABSTRACTION_ self_subtract(any_a range)
		{
			return self_subtract_();
		}

		inline _ABSTRACTION_ self_subtract_(any_a thing)
		{
			operator-=(std::move(thing));
			return me_();
		}

		inline iterator_t& operator-=(any_a thing)
		{
			return operator-=(0); //TODO index
		}

		inline iterator_t& operator-=(int64_t index)
		{
			_it -= index;
			return *this;
		}

		// data
		inline const ITERATOR& extract__() const
		{
			return _it;
		}

		inline void mutate__(const ITERATOR& it)
		{
			_it = it;
		}

		inline ITERATOR& reference__()
		{
			return _it;
		}

	private:
		ITERATOR _it;
		flock_a _flock;

		template <typename F>
		inline iterator_t(flock_a flock, F&& it)
			: something_t{}
			, _it{ std::forward<F>(it) }
			, _flock(std::move(flock), true)
		{}
	};

public: ___COLLECTION___
	// construction
	static inline flock_a val(any_a range)
	{
		return cast_<flock_a>(val_() += std::move(range));
	}

	static inline flock_a val_()
	{
		return val__(std_vector_any{});
	}

	template <typename F>
	static inline flock_a val__(F&& init)
	{
		return flock_a{ flock_t{ std::forward<F>(init) } };
	}

	static inline flock_a ref(any_a range)
	{
		return cast_<flock_a>(ref_() += std::move(range), true);
	}

	static inline flock_a ref_()
	{
		return ref__(std_vector_any{});
	}

	template <typename F>
	static inline flock_a ref__(F&& init)
	{
		return flock_a(flock_t{ std::forward<F>(init) }, true);
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::flock");
		return TYPE;
	}

	inline any_a feeder(any_a range) const // return range of parameter values
	{
		return nothing_t<>::val_(); //TODO
	}

	// visitor pattern
	static inline any_a visit(any_a range)
	{
		return nothing_t<>::val_(); //TODO
	}

	// comparison
	inline bool operator==(any_a thing) const
	{
		if (!type_().identical__(thing.type_()))
		{
			return false;
		}
		return _vector == reinterpret_cast<const flock_t<_ABSTRACTION_>*>(thing.identity__())->_vector;
	}

	inline bool operator!=(any_a thing) const
	{
		if (!type_().identical__(thing.type_()))
		{
			return true;
		}
		return _vector != reinterpret_cast<const flock_t<_ABSTRACTION_>*>(thing.identity__())->_vector;
	}

	inline std::size_t hash__() const
	{
		std::size_t seed = std::hash<std::size_t>{}(_vector.size());
		for (const auto item : _vector)
		{
			seed ^= item.hash__() + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}

	// range
	inline any_a cbegin() const
	{
		return iterator_t<std_vector_any::const_iterator>::val__(me_(), _vector.cbegin());
	}

	inline any_a begin()
	{
		return iterator_t<std_vector_any::iterator>::val__(me_(), _vector.begin());
	}

	inline any_a cend() const
	{
		return iterator_t<std_vector_any::const_iterator>::val__(me_(), _vector.cend());
	}

	inline any_a end()
	{
		return iterator_t<std_vector_any::iterator>::val__(me_(), _vector.end());
	}

	// collection
	inline bool has__(any_a key) const
	{
		return has__(0); //TODO index
	}

	inline bool has__(int64_t index) const
	{
		return index >= 0 && index < size__();
	}

	inline any_a at_(any_a key) const
	{
		return at__(0); //TODO index
	}

	inline any_a at__(int64_t index) const
	{
		if (index >= 0 && index < size__())
		{
			return _vector[std::size_t(index)];
		}
		return nothing_t<>::val_();
	}

	inline any_a update_(any_a key, any_a value)
	{
		update__(0, value); //TODO index
		return value;
	}

	inline void update__(int64_t index, any_a value)
	{
		if (index >= 0)
		{
			const int64_t size = size__();
			if (index == size)
			{
				push_back__(std::move(value));
			}
			else
			{
				if (index > size)
				{
					_vector.resize(std::size_t(index) + 1, nothing_t<>::val_());
				}
				_vector[std::size_t(index)] = std::move(value);
			}
		}
	}

	inline bool insert__(any_a key, any_a value)
	{
		return insert__(0, std::move(value)); //TODO index
	}

	inline bool insert__(int64_t index, any_a value)
	{
		if (index >= 0)
		{
			const int64_t size = size__();
			if (index == size)
			{
				push_back__(std::move(value));
			}
			else
			{
				if (index > size)
				{
					_vector.resize(std::size_t(index) + 1, nothing_t<>::val_());
					_vector[std::size_t(index)] = std::move(value);
				}
				else
				{
					_vector.insert(_vector.cbegin() + index, std::move(value));
				}
			}
			return true;
		}
		return false;
	}

	inline bool erase__(any_a key)
	{
		return erase__(0); //TODO index
	}

	inline bool erase__(int64_t index)
	{
		if (index >= 0 && index < size__())
		{
			_vector.erase(_vector.cbegin() + index);
			return true;
		}
		return false;
	}

	inline void clear__()
	{
		_vector.clear();
	}

	inline int64_t size__() const
	{
		return int64_t(_vector.size());
	}

	inline bool empty__() const
	{
		return _vector.empty();
	}

	inline void push_front__(any_a thing)
	{
		push_back__(std::move(thing));
	}

	inline any_a pop_front_()
	{
		return pop_back_();
	}

	inline void push_back__(any_a thing)
	{
		_vector.push_back(std::move(thing));
	}

	inline any_a pop_back_()
	{
		if (_vector.empty())
		{
			return nothing_t<>::val_();
		}
		any_a result = _vector.back();
		_vector.pop_back();
		return result;
	}

	inline flock_t& operator+=(any_a range)
	{
		for (const auto thing : range)
		{
			insert(thing);
		}
		return *this;
	}

	inline flock_t& operator-=(any_a range)
	{
		for (const auto thing : range)
		{
			erase(thing);
		}
		return *this;
	}

protected:
	std_vector_any _vector;

	template <typename F>
	inline flock_t(F&& init)
		: something_t{}
		, _vector{ std::forward<F>(init) }
	{}
};

} // namespace strange

#endif
