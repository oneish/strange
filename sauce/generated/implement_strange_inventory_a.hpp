
namespace strange
{

template <typename _1_>
inline any_a<> inventory_a<_1_>::mutate_begin__(range_a<> const& ___arguments___)
{
	return mutate_begin_();
}

template <typename _1_>
inline any_a<> inventory_a<_1_>::mutate_end__(range_a<> const& ___arguments___)
{
	return mutate_end_();
}

template <typename _1_>
bool const inventory_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

class ___inventory_a_share___
{
	static inline bool ___share___()
	{
		return false; // inventory_a<>::___share___;
	}
};

template <typename _1_>
inline inventory_d<_1_> ___inventory_dynamic___(any_a<> const& thing)
{
	return inventory_d<_1_>{ thing };
}

} // namespace
