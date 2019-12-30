#ifndef COM_ONEISH_STRANGE_EXPRESSION_LOCAL_UPDATE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_LOCAL_UPDATE_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_local_update_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_local_update_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_local_update::create not passed any terms");
		}
		any_a<> key = *it;
		if (!check<symbol_a<>>(key))
		{
			throw dis(token.report() + "strange::expression_local_update::create passed non-symbol key");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_local_update::create not passed sufficient terms");
		}
		any_a<> kind = *it;
		if (!check<kind_a<>>(kind) && !check<expression_a<>>(kind))
		{
			throw dis(token.report() + "strange::expression_local_update::create passed non-kind/expression");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_local_update::create not passed sufficient terms");
		}
		any_a<> expression = *it;
		if (!check<expression_a<>>(expression))
		{
			throw dis(token.report() + "strange::expression_local_update::create passed non-expression");
		}
		return expression_a<>{ over{ expression_local_update_t<>{ token, terms, cast<symbol_a<>>(key), kind, cast<expression_a<>>(expression) } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_local_update_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_local_update_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_local_update::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = static_cast<unordered_shoal_a<>&>(thing).mutate_unordered_map();
		auto it = local.find(_key);
		if (it == local.end())
		{
			throw dis(_token.report() + "strange::expression_local_update::operate key not found");
		}
		auto kind = _kind;
		if (check<expression_a<>>(kind))
		{
			try
			{
				kind = cast<expression_a<>>(kind).operate(thing, range);
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis(_token.report() + "strange::expression_local_update::operate kind expression evaluation error") + misunderstanding;
			}
		}
		auto value = _expression.operate(thing, range);
		if (!value.kinds_().has_(kind))
		{
			throw dis(_token.report() + "strange::expression_local_update::operate kind does not include value");
		}
		return it->second = value;
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" " + cast<symbol_a<>>(_key).to_string() + " :=");
		_expression.generate(version, indent, river);
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool type = false) const
	{
		if (type)
		{
			throw dis(_token.report() + "strange::expression_local_update::generate_cpp called for wrong type of expression");
		}
		river.write_string(" " + cast<symbol_a<>>(_key).to_string() + " =");
		_expression.generate_cpp(version, indent, river);
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _key;
	any_a<> const _kind;
	expression_a<> const _expression;

	inline expression_local_update_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& key, any_a<> const& kind, expression_a<> const& expression)
		: expression_t{ token }
		, _terms{ terms }
		, _key{ key }
		, _kind{ kind }
		, _expression{ expression }
	{}

private:
	static bool const ___share___;
	friend class ___expression_local_update_t_share___;
};

template <typename ___ego___>
bool const expression_local_update_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_local_update_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
