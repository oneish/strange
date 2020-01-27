#ifndef COM_ONEISH_STRANGE_EXPRESSION_XNOR_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_XNOR_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_xnor_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_xnor_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_xnor::create not passed any terms");
		}
		any_a<> left = *it;
		if (!check<expression_a<>>(left))
		{
			throw dis(token.report() + "strange::expression_xnor::create passed non-expression left-hand term");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_xnor::create not passed sufficient terms");
		}
		any_a<> right = *it;
		if (!check<expression_a<>>(right))
		{
			throw dis(token.report() + "strange::expression_xnor::create passed non-expression right-hand term");
		}
		return expression_a<>{ over{ expression_xnor_t<>( token, terms, cast<expression_a<>>(left), cast<expression_a<>>(right)) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_xnor_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_xnor_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto const left = _left.operate(thing, range);
		return boole(!left == !_right.operate(thing, range));
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" (");
		_left.generate(version, indent, river);
		river.write_string(" !% ");
		_right.generate(version, indent, river);
		river.write_string(") ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			_left.generate_cpp(version, indent, river, declare, define);
			_right.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(_token.report() + "strange::expression_xnor::generate_cpp called for wrong type of expression");
		}
		river.write_string(" (!");
		_left.generate_cpp(version, indent, river, declare, define);
		river.write_string(" == !");
		_right.generate_cpp(version, indent, river, declare, define);
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _left;
	expression_a<> const _right;

	inline expression_xnor_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& left, expression_a<> const& right)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _left{ left }
		, _right{ right }
	{}

private:
	static bool const ___share___;
	friend class ___expression_xnor_t_share___;
};

template <typename ___ego___>
bool const expression_xnor_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_xnor_t<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
