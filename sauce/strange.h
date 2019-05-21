#ifndef COM_ONEISH_STRANGE_H
#define COM_ONEISH_STRANGE_H

// dependenicies
#include "strange_dependencies.h"

// options
#include "strange_options.h"

// abstractions
#include "strange_abstractions.h"

namespace strange
{

// conversion
inline any_a<> boole(bool b);

}

// utilities
#include "strange_utilities.h"

// things
#include "strange_things.h"

// operations
#include "strange_operations.h"

namespace strange
{

// conversion
inline any_a<> boole(bool b)
{
	return b ? something_t<>::val_() : nothing_t<>::val_();
}

}

#endif
