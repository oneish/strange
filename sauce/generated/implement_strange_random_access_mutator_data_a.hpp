
namespace strange
{

class ___random_access_mutator_data_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___random_access_mutator_data_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1_>
inline random_access_mutator_data_d<_1_> ___random_access_mutator_data_dynamic___(any_a<> const& thing)
{
	return random_access_mutator_data_d<_1_>{ thing };
}

} // namespace
