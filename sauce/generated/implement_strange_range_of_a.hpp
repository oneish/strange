
namespace strange
{

template <typename element>
inline any_a<> range_of_a<element>::cbegin__(range_a<> const& ___arguments___) const
{
	return cbegin_();
}

template <typename element>
inline any_a<> range_of_a<element>::cend__(range_a<> const& ___arguments___) const
{
	return cend_();
}

template <typename element>
bool const range_of_a<element>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<range_of_a<element>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename element>
inline range_of_d<element> ___range_of_dynamic___(any_a<> const& thing)
{
	return range_of_d<element>{ thing };
}

} // namespace