#ifndef COM_ONEISH_STRANGE_EXPRESSION_WHILE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_WHILE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_while_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_while_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_while::val not passed any terms");
		}
		any_a<> condition = *it;
		if (!check<expression_a<>>(condition))
		{
			throw dis(token.report() + "strange::expression_while::val passed non-expression condition");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_while::val not passed sufficient terms");
		}
		any_a<> loop = *it;
		if (!check<expression_a<>>(loop))
		{
			throw dis(token.report() + "strange::expression_while::val passed non-expression loop");
		}
		return expression_a<>{ over{ expression_while_t<>( token, terms, cast<expression_a<>>(condition), cast<expression_a<>>(loop)) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_while_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_while_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		any_a<> result = no();
		try
		{
			while (_condition.operate_(thing, range))
			{
				try
				{
					result = _loop.operate_(thing, range);
				}
				catch (continue_i&)
				{}
			}
		}
		catch (break_i&)
		{}
		return result;
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" while_(");
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
				throw dis(_token.report() + "strange::expression_while::generate with non-expression term");
			}
			cast<expression_a<>>(term).generate(version, indent, river);
		}
		river.write_string(") ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" while(");
		_condition.generate_cpp(version, indent, river);
		river.write_string(")\n{");
		_loop.generate_cpp(version, indent, river);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _condition;
	expression_a<> const _loop;

	inline expression_while_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& condition, expression_a<> const& loop)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _condition{ condition }
		, _loop{ loop }
	{}

private:
	static bool const ___share___;
	friend class ___expression_while_t_share___;
};

template <typename _ABSTRACTION_>
bool const expression_while_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_while_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
