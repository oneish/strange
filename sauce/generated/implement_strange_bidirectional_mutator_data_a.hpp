
namespace strange
{

class ___bidirectional_mutator_data_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___bidirectional_mutator_data_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1_>
inline bidirectional_mutator_data_d<_1_> ___bidirectional_mutator_data_dynamic___(any_a<> const& thing)
{
	return bidirectional_mutator_data_d<_1_>{ thing };
}

} // namespace
