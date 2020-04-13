#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_UPDATE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_UPDATE_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_shared_update_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return expression_t<___ego___>::template create_expression<expression_shared_update_t<___ego___>>(range);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_shared_update::create not passed any terms");
		}
		any_a<> key = *it;
		if (!check<symbol_a<>>(key))
		{
			throw dis(token.report() + "strange::expression_shared_update::create passed non-symbol key");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_shared_update::create not passed sufficient terms");
		}
		any_a<> kind = *it;
		if (!check<kind_a<>>(kind) && !check<expression_a<>>(kind))
		{
			throw dis(token.report() + "strange::expression_shared_update::create passed non-kind/expression");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_shared_update::create not passed sufficient terms");
		}
		any_a<> expression = *it;
		if (!check<expression_a<>>(expression))
		{
			throw dis(token.report() + "strange::expression_shared_update::create passed non-expression");
		}
		return expression_a<>::create<expression_shared_update_t<>>(token, terms, fast<symbol_a<>>(key), kind, fast<expression_a<>>(expression));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_shared_update");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_shared_update::create"), native_function_create(&expression_shared_update_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_update::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = static_cast<unordered_shoal_a<>&>(thing).mutate_map();
		auto lit = local.find(sym("$"));
		if (lit == local.end())
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_update::operate $ not found");
		}
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(lit->second))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_update::operate passed non-unordered-shoal shared");
		}
#endif
		auto kind = _kind;
		if (check<expression_a<>>(kind))
		{
			try
			{
				kind = fast<expression_a<>>(kind).operate(thing, range);
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_update::operate kind expression evaluation error") + misunderstanding;
			}
		}
		auto value = any_a<>::val(_expression.operate(thing, range));
		if (!value.kinds_().has_(kind))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_update::operate kind does not include value");
		}
		auto& shared = static_cast<unordered_shoal_a<>&>(lit->second);
		auto& map = shared.mutate_map();
		auto lock = shared.write_lock_();
		auto it = map.find(_key);
		if (it == map.end())
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_update::operate key not found");
		}
		it->second = value;
		return value;
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_shared_update_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert_string("$", unordered_shoal_create<any_a<>, any_a<>, true>());
		return operate(local, range_create());
	}

	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		generate(version.extract_primitive(), indent.extract_primitive(), river);
		return river;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" " + fast<symbol_a<>>(_key).to_string() + " :=");
		_expression.generate(version, indent, river);
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = no()) const
	{
		generate_cpp(version.extract_primitive(), indent.extract_primitive(), river, declare, define, type);
		return river;
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			_expression.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_update::generate_cpp called for wrong type of expression");
		}
		river.write_string(" " + fast<symbol_a<>>(_key).to_string() + " ="); //TODO remove $ prefix
		_expression.generate_cpp(version, indent, river, declare, define);
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _key;
	any_a<> const _kind;
	expression_a<> const _expression;

	friend class any_a<>;

	inline expression_shared_update_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& key, any_a<> const& kind, expression_a<> const& expression)
		: expression_t<___ego___>{ token }
		, _terms{ terms }
		, _key{ key }
		, _kind{ kind }
		, _expression{ expression }
	{}

private:
	static bool const ___share___;
	friend class ___expression_shared_update_t_share___;
};

template <typename ___ego___>
bool const expression_shared_update_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_shared_update_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_shared_update_t_share___
{
	static inline bool ___share___()
	{
		return expression_shared_update_t<>::___share___;
	}
};

} // namespace strange

#endif
