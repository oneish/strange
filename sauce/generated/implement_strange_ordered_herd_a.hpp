
namespace strange
{

class ___ordered_herd_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___ordered_herd_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1_>
inline ordered_herd_d<_1_> ___ordered_herd_dynamic___(any_a<> const& thing)
{
	return ordered_herd_d<_1_>{ thing };
}

} // namespace
