
namespace strange
{

template <typename _element>
inline any_a<> bidirectional_extractor_a<_element>::decrement__(range_a<> const& ___arguments___)
{
	return decrement_();
}

class ___bidirectional_extractor_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___bidirectional_extractor_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _element>
inline bidirectional_extractor_d<_element> ___bidirectional_extractor_dynamic___(any_a<> const& thing)
{
	return bidirectional_extractor_d<_element>{ thing };
}

} // namespace
