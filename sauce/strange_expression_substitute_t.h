#ifndef COM_ONEISH_STRANGE_EXPRESSION_SUBSTITUTE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SUBSTITUTE_T_H

namespace strange
{

template <typename _SUBSTITUTED_>
class expression_substitute_t : public _SUBSTITUTED_
{
public:
	// construction
	static inline expression_a<> create(_SUBSTITUTED_&& substituted)
	{
		if (substituted.literal())
		{
			try
			{
				any_a<> thing = substituted.evaluate_();
				if (expression_literal_t<>::validate(thing))
				{
					flock_a<> terms = flock_t<>::create_();
					terms.push_back(thing);
					return expression_literal_t<>::create(substituted.token_(), terms, thing);
				}
				return expression_a<>::create<expression_substitute_t>(std::move(substituted), thing);
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis("strange::expression_substitute::create thing evaluation error:") + substituted.token_().report_() + misunderstanding;
			}
		}
		return expression_a<>{ std::move(substituted) };
	}

	template <typename... Args>
	static inline expression_a<> create(any_a<> const& thing, Args&&... args)
	{
		return expression_a<>::create<expression_substitute_t<_SUBSTITUTED_>>(thing, std::forward<Args>(args)...);
	}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const&) const
	{
		return _thing;
	}

	// expression
	inline expression_a<> recreate_() const
	{
		auto const recreated = _SUBSTITUTED_::template recreate_expression<_SUBSTITUTED_>(_SUBSTITUTED_::me_());
		if (check<operation_a<>>(_thing))
		{
			auto const thing = recreated.evaluate_();
			if (check<operation_a<>>(thing))
			{
				fast_ref<operation_a<>>(_thing).assign(fast<operation_a<>>(thing));
			}
		}
		return recreated;
	}

	inline any_a<> evaluate_() const
	{
		any_a<> null;
		return operate(null, range_a<>{});
	}

	// public constructor
	inline expression_substitute_t(_SUBSTITUTED_&& substituted, any_a<> const& thing)
		: _SUBSTITUTED_{ std::move(substituted) }
		, _thing{ thing }
	{}

	template <typename... Args>
	inline expression_substitute_t(any_a<> const& thing, Args&&... args)
		: _SUBSTITUTED_(std::forward<Args>(args)...)
		, _thing{ thing }
	{}

protected:
	any_a<> mutable _thing;
};

} // namespace strange

#endif
