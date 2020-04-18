#ifndef COM_ONEISH_STRANGE_DEPENDENCIES_H
#define COM_ONEISH_STRANGE_DEPENDENCIES_H

// dependencies
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>
#include <ios>
#include <fstream>
#include <sstream>
#include <iterator>
#include <mutex>
#include <shared_mutex>
#include <iostream>
#include <cmath>

#include "../../libdart/include/dart.h"

namespace strange
{
	using std_size_t = std::size_t;
	using std_string = std::string;
	using std_stringstream = std::stringstream;

	using dart_packet = dart::packet;
}

#endif
