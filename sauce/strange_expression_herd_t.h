#ifndef COM_ONEISH_STRANGE_EXPRESSION_HERD_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_HERD_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_herd_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_herd_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_substitute_t<over>::create(over{ expression_herd_t<>(token, terms) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_herd");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_herd::create", native_function_create(&expression_herd_t<>::over::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		return unordered_herd_t<>::create__(range_operator_t<>::create_(_terms, thing, range));
	}

	// expression
	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert_string("$", unordered_shoal_create<true>());
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
		river.write_string(" {");
		bool first = true;
		for (auto const& term : _terms.extract_vector())
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
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_herd::generate with non-expression term");
			}
			fast<expression_a<>>(term).generate(version, indent, river);
		}
		river.write_string("} ");
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
			for (auto const& term : _terms.extract_vector())
			{
				if (!check<expression_a<>>(term))
				{
					throw dis(expression_t<___ego___>::_token.report() + "strange::expression_flock::generate_cpp with non-expression term");
				}
				fast<expression_a<>>(term).generate_cpp(version, indent, river, declare, define);
			}
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_herd::generate_cpp called for wrong type of expression");
		}
		river.write_string(" unordered_herd_t<>::create_(");
		bool first = true;
		for (auto const& term : _terms.extract_vector())
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
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_herd::generate_cpp with non-expression term");
			}
			fast<expression_a<>>(term).generate_cpp(version, indent, river, declare, define);
		}
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;

	inline expression_herd_t(token_a<> const& token, flock_a<> const& terms)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
		, _terms{ terms }
	{}

private:
	static bool const ___share___;
	friend class ___expression_herd_t_share___;
};

template <typename ___ego___>
bool const expression_herd_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_herd_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_herd_t_share___
{
	static inline bool ___share___()
	{
		return expression_herd_t<>::___share___;
	}
};

} // namespace strange

#endif
