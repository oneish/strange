
namespace strange
{

template <typename _1_>
inline any_a<> kind_a<_1_>::aspects__(range_a<> const& ___arguments___) const
{
	return aspects_();
}

template <typename _1_>
inline any_a<> kind_a<_1_>::fixed__(range_a<> const& ___arguments___) const
{
	return fixed_();
}

template <typename _1_>
inline any_a<> kind_a<_1_>::reference__(range_a<> const& ___arguments___) const
{
	return reference_();
}

template <typename _1_>
inline any_a<> kind_a<_1_>::optional__(range_a<> const& ___arguments___) const
{
	return optional_();
}

template <typename _1_>
bool const kind_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<kind_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline kind_d<_1_> ___kind_dynamic___(any_a<> const& thing)
{
	return kind_d<_1_>{ thing };
}

} // namespace