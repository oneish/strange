#ifndef COM_ONEISH_STRANGE_EXPRESSION_CHECK_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_CHECK_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_check_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_check_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_check::create not passed any terms");
		}
		any_a<> left = *it;
		if (!check<expression_a<>>(left))
		{
			throw dis(token.report() + "strange::expression_check::create passed non-expression left-hand term");
		}
		if (++it == terms.cend_())
		{
			return expression_a<>{ over{ expression_check_t<>(token, terms, cast<expression_a<>>(left), expression_kind_t<>::create_(token, flock_t<>::create_())) } };
		}
		any_a<> right = *it;
		if (!check<expression_a<>>(right))
		{
			throw dis(token.report() + "strange::expression_check::create passed non-expression right-hand term");
		}
		return expression_a<>{ over{ expression_check_t<>(token, terms, cast<expression_a<>>(left), cast<expression_a<>>(right)) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_check_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_check_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto const left = _left.operate(thing, range);
		return left.kinds_().has_(_right.operate(thing, range));
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" check(");
		_left.generate(version, indent, river);
		river.write_string(", ");
		_right.generate(version, indent, river);
		river.write_string(") ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool type = false) const
	{
		if (type)
		{
			throw dis(_token.report() + "strange::expression_check::generate_cpp called for wrong type of expression");
		}
		river.write_string(" strange::check<");
		_right.generate_cpp(version, indent, river, true); // type
		river.write_string(">(");
		_left.generate_cpp(version, indent, river);
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _left;
	expression_a<> const _right;

	inline expression_check_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& left, expression_a<> const& right)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _left{ left }
		, _right{ right }
	{}

private:
	static bool const ___share___;
	friend class ___expression_check_t_share___;
};

template <typename ___ego___>
bool const expression_check_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_check_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif