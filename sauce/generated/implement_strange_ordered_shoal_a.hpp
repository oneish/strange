
namespace strange
{

class ___ordered_shoal_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___ordered_shoal_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline ordered_shoal_d<_1> ___ordered_shoal_dynamic___(any_a<> const& thing)
{
	return ordered_shoal_d<_1>{ thing };
}

} // namespace
