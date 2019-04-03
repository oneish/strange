#ifndef COM_ONEISH_STRANGE_NOTHING_H
#define COM_ONEISH_STRANGE_NOTHING_H

#include "strange_thing_.h"
#include "strange_everything.h"

namespace strange
{

class Nothing : public Thing
{
public:
	static inline thing_& val(thing_ _ = thing_{})
	{
		static thing_ VAL = Nothing{};
		return VAL;
	}

	static inline thing_& ref(thing_ _ = thing_{})
	{
		static thing_ REF(Nothing{}, true);
		return REF;
	}

	// conversion
	inline operator bool() const
	{
		return false;
	}

	// function
	inline thing_ mutate(thing_)
	{
		return Nothing::val();
	}

	inline thing_ operator()(thing_)
	{
		return Nothing::val();
	}

	inline thing_ extract(thing_) const
	{
		return Nothing::val();
	}

	inline thing_ operator()(thing_) const
	{
		return Nothing::val();
	}

	// comparison
	inline thing_ same(thing_ range) const;

	inline thing_ same_(thing_ thing) const;

	inline bool operator==(thing_ thing) const
	{
		return !thing;
	}

	inline thing_ different(thing_ range) const;

	inline thing_ different_(thing_ thing) const;

	inline bool operator!=(thing_ thing) const
	{
		return thing;
	}

	inline thing_ is_something(thing_) const
	{
		return Nothing::val();
	}

	inline thing_ is_something_() const
	{
		return Nothing::val();
	}

	inline thing_ is_nothing(thing_) const
	{
		return Everything::val();
	}

	inline thing_ is_nothing_() const
	{
		return Everything::val();
	}

	// range
	inline thing_ begin_set(thing_)
	{
		return Nothing::val();
	}

	inline thing_ begin_set_()
	{
		return Nothing::val();
	}

	inline thing_ begin()
	{
		return Nothing::val();
	}

	inline thing_ begin_get(thing_) const
	{
		return Nothing::val();
	}

	inline thing_ begin_get_() const
	{
		return Nothing::val();
	}

	inline thing_ cbegin() const
	{
		return Nothing::val();
	}

	inline thing_ end_set(thing_)
	{
		return Nothing::val();
	}

	inline thing_ end_set_()
	{
		return Nothing::val();
	}

	inline thing_ end()
	{
		return Nothing::val();
	}

	inline thing_ end_get(thing_) const
	{
		return Nothing::val();
	}

	inline thing_ end_get_() const
	{
		return Nothing::val();
	}

	inline thing_ cend() const
	{
		return Nothing::val();
	}

	// iterator
	inline thing_ set(thing_)
	{
		return Nothing::val();
	}

	inline thing_ set_(thing_)
	{
		return Nothing::val();
	}

	inline thing_& operator*()
	{
		return Nothing::val();
	}

	inline thing_* operator->()
	{
		return &Nothing::val();
	}

	inline thing_ get(thing_) const
	{
		return Nothing::val();
	}

	inline thing_ get_() const
	{
		return Nothing::val();
	}

	inline const thing_& operator*() const
	{
		return Nothing::val();
	}

	inline const thing_* operator->() const
	{
		return &Nothing::val();
	}

	inline thing_ increment(thing_)
	{
		return Nothing::val();
	}

	inline thing_ increment_()
	{
		return Nothing::val();
	}

	inline thing_& operator++()
	{
		return Nothing::val();
	}

private:
	inline Nothing() {};
};

} // namespace strange

#endif
