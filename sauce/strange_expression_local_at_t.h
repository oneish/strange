#ifndef COM_ONEISH_STRANGE_EXPRESSION_LOCAL_AT_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_LOCAL_AT_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_local_at_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_local_at_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_local_at::val not passed any terms");
		}
		return expression_a<>{ over{ expression_local_at_t<>{ token, terms, *it } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_local_at_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_local_at_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_local_at::operate passed non-unordered-shoal local");
		}
#endif
		auto const& local = static_cast<unordered_shoal_a<>&>(thing).extract();
		auto it = local.find(_key);
		if (it == local.cend())
		{
			throw dis(_token.report() + "strange::expression_local_at::operate key not found");
		}
		return it->second;
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t indent, river_a<>& river) const
	{
		if (!check<symbol_a<>>(_key))
		{
			throw dis(_token.report() + "strange::expression_local_at::generate with non-symbol key");
		}
		river.write_string(" " + cast<symbol_a<>>(_key).to_string() + " ");
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		if (!check<symbol_a<>>(_key))
		{
			throw dis(_token.report() + "strange::expression_local_at::generate_cpp with non-symbol key");
		}
		river.write_string(" " + cast<symbol_a<>>(_key).to_string() + " ");
	}

protected:
	flock_a<> const _terms;
	any_a<> const _key;

	inline expression_local_at_t(token_a<> const& token, flock_a<> const& terms, any_a<> const& key)
		: expression_t{ token }
		, _terms{ terms }
		, _key{ key }
	{}
};

} // namespace strange

#endif
