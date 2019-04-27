#ifndef COM_ONEISH_STRANGE_MISUNDERSTANDING_T_H
#define COM_ONEISH_STRANGE_MISUNDERSTANDING_T_H

namespace strange
{

template <typename _ABSTRACTION_ = misunderstanding_a>
class misunderstanding_t : public something_t<_ABSTRACTION_>
{
public: ___THING___
	// construction
	static inline misunderstanding_a val(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline misunderstanding_a val_(any_a thing = nothing_t<>::val_())
	{
		return val__("");
	}

	template <typename F>
	static inline misunderstanding_a val__(F&& s)
	{
		return misunderstanding_a{ misunderstanding_t{ std::forward<F>(s) } };
	}

	static inline misunderstanding_a ref(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return ref_();
		}
		return ref_(*it);
	}

	static inline misunderstanding_a ref_(any_a thing = nothing_t<>::val_())
	{
		return ref__("");
	}

	template <typename F>
	static inline misunderstanding_a ref__(F&& s)
	{
		return misunderstanding_a(misunderstanding_t{ std::forward<F>(s) }, true);
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::misunderstanding");
		return TYPE;
	}

	// comparison
	inline bool operator==(any_a thing) const
	{
		return check_<misunderstanding_a>(thing) && cast_<misunderstanding_a>(thing).to_string__() == _string;
	}

	inline bool operator!=(any_a thing) const
	{
		return !check_<misunderstanding_a>(thing) || cast_<misunderstanding_a>(thing).to_string__() != _string;
	}

	inline std::size_t hash__() const
	{
		return std::hash<std::string>{}(_string);
	}

	// misunderstanding
	inline const std::string& to_string__() const
	{
		return _string;
	}

	inline misunderstanding_a add(any_a range) const
	{
		std::string s = _string;
		for (const any_a thing : range)
		{
			if (check_<misunderstanding_a>(thing))
			{
				s += cast_<misunderstanding_a>(thing).to_string__();
			}
		}
		return misunderstanding_a{ misunderstanding_t{ std::move(s) } };
	}

	inline misunderstanding_a add_(misunderstanding_a misunderstanding) const
	{
		return operator+(std::move(misunderstanding));
	}

	inline misunderstanding_a operator+(misunderstanding_a misunderstanding) const
	{
		return misunderstanding_a{ misunderstanding_t{ _string + misunderstanding.to_string__() } };
	}

protected:
	const std::string _string;

	template <typename F>
	inline misunderstanding_t(F&& s)
		: something_t{}
		, _string{ std::forward<F>(s) }
	{}
};

template <typename F>
inline misunderstanding_a mis__(F&& s)
{
	return misunderstanding_t<>::val__(std::forward<F>(s));
}

} // namespace strange

#endif