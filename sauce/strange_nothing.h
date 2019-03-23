#ifndef COM_ONEISH_STRANGE_NOTHING_H
#define COM_ONEISH_STRANGE_NOTHING_H

#include "strange_thing.h"
#include "strange_oneish.h"

namespace strange
{

class Nothing
{
public:
	static inline Thing& nothing_()
	{
		static Thing NOTHING = Nothing{};
		return NOTHING;
	}

	// function
	inline Thing mutate(Thing thing = Thing())
	{
		return nothing_();
	}

	inline Thing extract(Thing thing = Thing()) const
	{
		return nothing_();
	}

	inline Thing operator()(Thing thing = Thing())
	{
		return nothing_();
	}

	inline Thing operator()(Thing thing = Thing()) const
	{
		return nothing_();
	}

	// comparison
	inline Thing same(Thing thing) const
	{
		return thing.is_nothing_() ? Oneish::oneish_() : nothing_();
	}

	inline Thing different(Thing thing) const
	{
		return thing.is_something_() ? Oneish::oneish_() : nothing_();
	}

	inline bool operator==(Thing thing) const
	{
		return thing.is_nothing_();
	}

	inline bool operator!=(Thing thing) const
	{
		return thing.is_something_();
	}

	inline Thing is_something(Thing thing = Thing()) const
	{
		return nothing_();
	}

	inline bool is_something_() const
	{
		return false;
	}

	inline Thing is_nothing(Thing thing = Thing()) const
	{
		return Oneish::oneish_();
	}

	inline bool is_nothing_() const
	{
		return true;
	}

	// range
	inline Thing begin(Thing thing = Thing())
	{
		return nothing_();
	}

	inline Thing cbegin(Thing thing = Thing()) const
	{
		return nothing_();
	}

	inline Thing end(Thing thing = Thing())
	{
		return nothing_();
	}

	inline Thing cend(Thing thing = Thing()) const
	{
		return nothing_();
	}

	// iterator
	inline Thing set(Thing thing)
	{
		return nothing_();
	}

	inline Thing get(Thing thing = Thing()) const
	{
		return nothing_();
	}

	inline Thing& operator*()
	{
		return nothing_();
	}

	inline const Thing& operator*() const
	{
		return nothing_();
	}

	inline Thing* operator->()
	{
		return &nothing_();
	}

	inline const Thing* operator->() const
	{
		return &nothing_();
	}

	inline Thing increment(Thing thing = Thing())
	{
		return nothing_();
	}

	inline Thing& operator++()
	{
		return nothing_();
	}
};

} // namespace strange

#endif
