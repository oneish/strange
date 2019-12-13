#ifndef COM_ONEISH_STRANGE_OPERATION_T_H
#define COM_ONEISH_STRANGE_OPERATION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class operation_t : public thing_t<___ego___>
{
public:
	// operation
	inline any_a<> pure__(range_a<> const&) const
	{
		return pure_();
	}

	inline any_a<> pure_() const
	{
		return boole(pure());
	}

	inline bool pure() const
	{
		return _pure;
	}

	static inline void aspects(unordered_shoal_a<> const&)
	{}

	static inline void assign(operation_a<> const&)
	{}

	inline any_a<> names__(range_a<> const&) const
	{
		return names_();
	}

	inline flock_a<> names_() const
	{
		return _names;
	}

protected:
	bool const _pure;
	flock_a<> const _names;

	inline operation_t(bool pure = false, flock_a<> const& names = flock_t<>::create_())
		: thing_t{}
		, _pure(pure)
		, _names(names)
	{}

	static inline std::pair<kind_a<>, flock_a<>> kind_names_params(flock_a<> const& params)
	{
		std::pair<kind_a<>, flock_a<>> kind_names(kind_t<>::create_(), flock_t<>::create_());
		auto it = params.cbegin_();
		if (it == params.cend_())
		{
			return kind_names;
		}
		auto kind = *it;
		if (!check<kind_a<>>(kind))
		{
			throw dis("strange::operation::kind_names_params passed non-kind result");
		}
		auto kind_result = cast<kind_a<>>(kind);
		auto kind_params = flock_t<>::create_();
		while (++it != params.cend_())
		{
			auto name = *it;
			if (!check<symbol_a<>>(name))
			{
				throw dis("strange::operation::kind_names_params passed non-symbol name");
			}
			bool const end = (++it == params.cend_());
			kind = end ? cast<any_a<>>(kind_t<>::create_()) : *it;
			if (!end && !check<kind_a<>>(kind))
			{
				throw dis("strange::operation::kind_names_params passed non-kind param");
			}
			kind_names.second.push_back(name);
			kind_params.push_back(kind);
			if (end)
			{
				break;
			}
		}
		kind_names.first = kind_t<>::create(1, "", flock_t<>::create_(), flock_t<>::create_(), kind_params, kind_result);
		return kind_names;
	}

	static inline unordered_herd_a<> cats(cat_a<> const& cat)
	{
		auto result = reflection<___ego___>::cats();
		result.insert(cat);
		return result;
	}

	static inline unordered_herd_a<> kinds(kind_a<> const& kind)
	{
		auto result = reflection<___ego___>::kinds();
		result.insert(kind);
		return result;
	}
};

} // namespace strange

#endif
