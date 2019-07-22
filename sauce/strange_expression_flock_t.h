#ifndef COM_ONEISH_STRANGE_EXPRESSION_FLOCK_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_FLOCK_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_flock_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_flock_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_substitute_t<over>::val(over{ expression_flock_t<>(token, terms) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_flock_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_flock_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		return flock_t<>::val__(range_operator_t<>::val_(_terms, thing, range));
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t indent, river_a<>& river) const
	{
		river.write_string(" [");
		bool first = true;
		for (auto const& term : _terms)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(_token.report() + "strange::expression_flock::generate with non-expression term");
			}
			cast<expression_a<>>(term).generate(indent, river);
		}
		river.write_string("] ");
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		river.write_string(" flock_t<>::val_(");
		bool first = true;
		for (auto const& term : _terms)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(_token.report() + "strange::expression_flock::generate_cpp with non-expression term");
			}
			cast<expression_a<>>(term).generate_cpp(indent, river);
		}
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;

	inline expression_flock_t(token_a<> const& token, flock_a<> const& terms)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
	{}

private:
	static bool const ___share___;
	friend class ___expression_flock_t_share___;
};

template <typename _ABSTRACTION_>
bool const expression_flock_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_flock_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
