#ifndef COM_ONEISH_STRANGE_NOTHING_H
#define COM_ONEISH_STRANGE_NOTHING_H

#include "strange_thing.h"
#include "strange_everything.h"

namespace strange
{

class Nothing
{
public:
	static inline Thing& val(Thing _ = Thing())
	{
		static Thing VAL = Nothing{};
		return VAL;
	}

	// function
	inline Thing mutate(Thing _ = Thing())
	{
		return Nothing::val();
	}

	inline Thing extract(Thing _ = Thing()) const
	{
		return Nothing::val();
	}

	inline Thing operator()(Thing _ = Thing())
	{
		return Nothing::val();
	}

	inline Thing operator()(Thing _ = Thing()) const
	{
		return Nothing::val();
	}

	// comparison
	inline Thing same(Thing thing) const
	{
		return thing.is_nothing_() ? Everything::val() : Nothing::val();
	}

	inline Thing different(Thing thing) const
	{
		return thing.is_something_() ? Everything::val() : Nothing::val();
	}

	inline bool operator==(Thing thing) const
	{
		return thing.is_nothing_();
	}

	inline bool operator!=(Thing thing) const
	{
		return thing.is_something_();
	}

	inline Thing is_something(Thing _ = Thing()) const
	{
		return Nothing::val();
	}

	inline bool is_something_() const
	{
		return false;
	}

	inline Thing is_nothing(Thing _ = Thing()) const
	{
		return Everything::val();
	}

	inline bool is_nothing_() const
	{
		return true;
	}

	// range
	inline Thing begin(Thing _ = Thing())
	{
		return Nothing::val();
	}

	inline Thing cbegin(Thing _ = Thing()) const
	{
		return Nothing::val();
	}

	inline Thing end(Thing _ = Thing())
	{
		return Nothing::val();
	}

	inline Thing cend(Thing _ = Thing()) const
	{
		return Nothing::val();
	}

	// iterator
	inline Thing set(Thing thing)
	{
		return Nothing::val();
	}

	inline Thing get(Thing _ = Thing()) const
	{
		return Nothing::val();
	}

	inline Thing& operator*()
	{
		return Nothing::val();
	}

	inline const Thing& operator*() const
	{
		return Nothing::val();
	}

	inline Thing* operator->()
	{
		return &Nothing::val();
	}

	inline const Thing* operator->() const
	{
		return &Nothing::val();
	}

	inline Thing increment(Thing _ = Thing())
	{
		return Nothing::val();
	}

	inline Thing& operator++()
	{
		return Nothing::val();
	}
};

} // namespace strange

#endif