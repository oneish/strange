#ifndef COM_ONEISH_STRANGE_EVERYTHING_H
#define COM_ONEISH_STRANGE_EVERYTHING_H

namespace strange
{

template <typename THING_ = thing_>
class Everything : public Something<THING_>
{
public:
	// construction
	static inline thing_& val(thing_ _ = thing_{})
	{
		static thing_ VAL = []()
		{
			thing_ thing;
			thing = Everything<>{ thing };
			return thing;
		}();
		return VAL;
	}

	static inline thing_& ref(thing_ _ = thing_{})
	{
		static thing_ REF = []()
		{
			thing_ thing{ true };
			thing = Everything<>{ thing };
			return thing;
		}();
		return REF;
	}

	// comparison
	inline thing_ same(thing_ range) const
	{
		const auto it = range.beget_();
		assert(it != range.enget_()); //TODO throw
		return same_(it.get_());
	}

	inline thing_ same_(thing_ thing) const
	{
		return _boole_(operator==(thing));
	}

	inline bool operator==(thing_ thing) const
	{
		return thing.hash__() == 1;
	}

	inline thing_ different(thing_ range) const
	{
		const auto it = range.beget_();
		assert(it != range.enget_()); //TODO throw
		return different_(it.get_());
	}

	inline thing_ different_(thing_ thing) const
	{
		return _boole_(operator!=(thing));
	}

	inline bool operator!=(thing_ thing) const
	{
		return thing.hash__() != 1;
	}

	inline thing_ hash(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_ hash_() const
	{
		return Everything<>::ref();
	}

	inline size_t hash__() const
	{
		return 1;
	}

	// range
	inline thing_ beget(thing_) const
	{
		return beget_();
	}

	inline thing_ beget_() const
	{
		return cbegin();
	}

	inline thing_ cbegin() const
	{
		return It<>::val_(Everything<>::ref());
	}

	inline thing_ beset(thing_)
	{
		return beset_();
	}

	inline thing_ beset_()
	{
		return begin();
	}

	inline thing_ begin()
	{
		return It<>::val_(Everything<>::ref());
	}

	inline thing_ enget(thing_) const
	{
		return enget_();
	}

	inline thing_ enget_() const
	{
		return cend();
	}

	inline thing_ cend() const
	{
		return Nothing<>::ref();
	}

	inline thing_ enset(thing_)
	{
		return enset_();
	}

	inline thing_ enset_()
	{
		return end();
	}

	inline thing_ end()
	{
		return Nothing<>::ref();
	}

	// iterator
	inline thing_ get(thing_) const
	{
		return get_();
	}

	inline thing_ get_() const
	{
		return Everything<>::ref();
	}

	inline thing_ set(thing_) const
	{
		return get_();
	}

	inline thing_ set_(thing_) const
	{
		return get_();
	}

	inline thing_& operator*() const
	{
		return Everything<>::ref();
	}

	inline thing_* operator->() const
	{
		return &Everything<>::ref();
	}

	inline thing_ increment(thing_)
	{
		return increment_();
	}

	inline thing_ increment_()
	{
		return operator++();
	}

	inline thing_ operator++()
	{
		return Everything<>::ref();
	}

protected:
	inline Everything(const thing_& me)
		: Something{ me }
	{}
};

} // namespace strange

#endif
