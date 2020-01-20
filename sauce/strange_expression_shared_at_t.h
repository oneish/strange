#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_AT_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_AT_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_shared_at_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_shared_at_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_shared_at::create not passed any terms");
		}
		any_a<> key = *it;
		if (!check<symbol_a<>>(key))
		{
			throw dis(token.report() + "strange::expression_shared_at::create passed non-symbol key");
		}
		return expression_a<>{ over{ expression_shared_at_t<>{ token, terms, cast<symbol_a<>>(key) } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_shared_at_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_shared_at_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_shared_at::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = const_cast<unordered_shoal_t<>::std_unordered_map_any_any&>(static_cast<unordered_shoal_a<>&>(thing).extract_map());
		auto lit = local.find(sym("$"));
		if (lit == local.end())
		{
			throw dis(_token.report() + "strange::expression_shared_at::operate $ not found");
		}
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(lit->second))
		{
			throw dis(_token.report() + "strange::expression_shared_at::operate passed non-unordered-shoal shared");
		}
#endif
		auto& shared = static_cast<unordered_shoal_a<>&>(lit->second);
		auto& map = const_cast<unordered_shoal_t<>::std_unordered_map_any_any&>(shared.extract_map());
		auto lock = shared.read_lock_();
		auto it = map.find(_key);
		if (it == map.end())
		{
			throw dis(_token.report() + "strange::expression_shared_at::operate key not found");
		}
		return any_a<>::ref(it->second);
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" " + cast<symbol_a<>>(_key).to_string() + " ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool def, bool type = false) const
	{
		if (def)
		{
			return;
		}
		if (type)
		{
			throw dis(_token.report() + "strange::expression_shared_at::generate_cpp called for wrong type of expression");
		}
		river.write_string(" " + cast<symbol_a<>>(_key).to_string() + " "); //TODO remove $ prefix
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _key;

	inline expression_shared_at_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& key)
		: expression_t{ token }
		, _terms{ terms }
		, _key{ key }
	{}

private:
	static bool const ___share___;
	friend class ___expression_shared_at_t_share___;
};

template <typename ___ego___>
bool const expression_shared_at_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_shared_at_t<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
