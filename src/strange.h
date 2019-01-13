#ifndef COM_ONEISH_STRANGE_H
#define COM_ONEISH_STRANGE_H

#include "strange_core.h"
#include "strange_method.h"
#include "strange_reference.h"
#include "strange_weak.h"
#include "strange_fence.h"
#include "strange_creature.h"
#include "strange_expression.h"
#include "strange_function.h"
#include "strange_token.h"
#include "strange_tokenizer.h"
#include "strange_parser.h"

namespace strange
{
	// Categories:
	// private typedefs
	// protected typedefs
	// public typedefs
	// public static utility functions
	// public static factory functions
	// public static symbols
	// public construction/destruction/assignment
	// public pure virtual member functions and adapters
	// public impure virtual member functions and adapters
	// public non-virtual member functions and adapters
	// protected static utility functions
	// protected static factory functions
	// protected static symbols
	// protected construction/destruction/assignment
	// protected pure virtual member functions and adapters
	// protected impure virtual member functions and adapters
	// protected non-virtual member functions and adapters
	// private static utility functions
	// private static factory functions
	// private static symbols
	// private construction/destruction/assignment
	// private pure virtual member functions and adapters
	// private impure virtual member functions and adapters
	// private non-virtual member functions and adapters

inline void Thing::share_(const Ptr& shoal)
{
	Shoal* const s = static_<Shoal>(shoal);
	s->update_("strange::Thing::boolean", Static::fin_(&Thing::boolean, "value"));
	s->update_("strange::Thing::log", Static::fin_(&Thing::log, "message"));
	s->update_("strange::Thing::call", Static::fin_(&Thing::call, "function"));
	s->update_("strange::Thing::nothing", Static::fin_(&Thing::nothing));
	s->update_("strange::Thing::one", Static::fin_(&Thing::one));
	s->update_("strange::Thing::stop", Static::fin_(&Thing::stop));

	// strange_core
	Symbol::share_(shoal);
	Shoal::share_(shoal);
	Shoal::Concurrent::share_(shoal);
	Flock::share_(shoal);
	Flock::Concurrent::share_(shoal);
	Herd::share_(shoal);
	Herd::Concurrent::share_(shoal);
	Lake::share_(shoal);
	Bit::share_(shoal);
	Int8::share_(shoal);
	UInt8::share_(shoal);
	Int16::share_(shoal);
	UInt16::share_(shoal);
	Int32::share_(shoal);
	UInt32::share_(shoal);
	Int64::share_(shoal);
	UInt64::share_(shoal);
	Float32::share_(shoal);
	Float64::share_(shoal);
	Complex32::share_(shoal);
	Complex64::share_(shoal);
	River::share_(shoal);

	// strange_reference
	Reference::share_(shoal);

	// strange_weak
	Weak::share_(shoal);

	// strange_fence
	Fence::share_(shoal);
}

} // namespace strange

#endif
