#ifndef COM_ONEISH_STRANGE_SYMBOL_T_H
#define COM_ONEISH_STRANGE_SYMBOL_T_H

namespace strange
{

template <typename ___ego___ = symbol_a<>>
class symbol_t : public thing_t<___ego___>
{
public:
	// override
	using over = thing_o<symbol_t<>>;

	// construction
	static inline any_a<> val__(range_a<> const&)
	{
		return val_();
	}

	static inline symbol_a<> val_()
	{
		static symbol_a<> VAL = symbol_t<>::val("");
		return VAL;
	}

	template <typename F>
	static inline symbol_a<> val(F&& s)
	{
		return symbol_a<>{ over{ symbol_t<>{ std::forward<F>(s) } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<symbol_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<symbol_t<>>::share(shoal);
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		return check<symbol_a<>>(thing) && !check<cat_a<>>(thing) && cast<symbol_a<>>(thing).to_string() == _string;
	}

	inline std::size_t hash() const
	{
		return _hash;
	}

	inline bool is(std::string const& s) const
	{
		return s == _string;
	}

	// symbol
	inline std::string const& to_string() const
	{
		return _string;
	}

	inline symbol_a<> add__(range_a<> const& range) const
	{
		std::string s = _string;
		for (any_a<> const& thing : range)
		{
			if (check<symbol_a<>>(thing))
			{
				s += cast<symbol_a<>>(thing).to_string();
			}
		}
		return symbol_t<>::val(std::move(s));
	}

	inline symbol_a<> add_(symbol_a<> const& symbol) const
	{
		return operator+(symbol);
	}

	inline symbol_a<> operator+(symbol_a<> const& symbol) const
	{
		return symbol_t<>::val(_string + symbol.to_string());
	}

protected:
	std::string const _string;
	std::size_t const _hash;

	template <typename F>
	inline symbol_t(F&& s)
		: thing_t{}
		, _string{ std::forward<F>(s) }
		, _hash{ std::hash<std::string>{}(_string) }
	{}

private:
	static bool const ___share___;
	friend class ___symbol_t_share___;
};

template <typename ___ego___>
bool const symbol_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	symbol_t<___ego___>::share(shoal);
	return shoal;
}();

template <typename F>
inline symbol_a<> sym(F&& s)
{
	return symbol_t<>::val(std::forward<F>(s));
}

} // namespace strange

#endif
