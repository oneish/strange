
namespace strange
{

class ___herd_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___herd_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline herd_d<_1> ___herd_dynamic___(any_a<> const& thing)
{
	return herd_d<_1>{ thing };
}

} // namespace
