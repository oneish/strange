#ifndef DERIVED__H
#define DERIVED__H

#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>

#include "root_.h"

class derived_ : public root_
{
public:
	inline void mutate()
	{
		assert(___handle___);
		___write___().mutate();
	}

protected:
	struct ___derived_handle_base___ : ___root_handle_base___
	{
		virtual void mutate() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___derived_handle_base___>
	struct ___derived_handle___ : ___root_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___derived_handle___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: ___root_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___derived_handle___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: ___root_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline void mutate() final
		{
			___root_handle___<___TTT___, ___DHB___>::___value___.mutate();
		}
	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___derived_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___derived_handle___<___TTT___&, ___DHB___>
	{
		inline ___derived_handle___(std::reference_wrapper<___TTT___> ref)
			: ___derived_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___derived_handle_final___ final : ___derived_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___derived_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: ___derived_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___derived_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: ___derived_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final
		{
			return std::make_shared<___derived_handle_final___>(___derived_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___derived_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___derived_handle_final___<___TTT___&>
	{
		inline ___derived_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___derived_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline const ___derived_handle_base___& ___read___() const
	{
		return *std::static_pointer_cast<const ___derived_handle_base___>(___handle___);
	}

	inline ___derived_handle_base___& ___write___()
	{
		if (!___reference___ && !___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___derived_handle_base___>(___handle___);
	}

	template <typename ___TTT___>
	friend inline bool check(const derived_& v);

public:
	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>& h)
	{
		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(h));
	}

	derived_() = default;

	explicit inline derived_(bool reference)
		: root_{ reference }
	{}

	inline derived_(const derived_& other, bool reference)
		: root_(other, reference)
	{}

	inline derived_(derived_&& other, bool reference)
		: root_(std::move(other), reference)
	{}

	template <typename ___TTT___>
	explicit inline derived_(const std::shared_ptr<___TTT___>& other, bool reference = false)
		: root_(other, reference)
	{
		assert(std::dynamic_pointer_cast<___derived_handle_base___>(other));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<root_, ___TTT___>::value>>
	explicit inline derived_(___TTT___ value, bool reference = false);

	template <typename ___TTT___>
	inline derived_& operator=(const std::shared_ptr<___TTT___>& other)
	{
		assert(std::dynamic_pointer_cast<___derived_handle_base___>(other));
		___handle___ = other;
		___handle___->___weak___(___handle___);
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<root_, ___TTT___>::value>>
	inline derived_& operator=(___TTT___ value);
};

template <typename ___TTT___>
inline bool check(const derived_& v)
{
	return ___TTT___::___check___(v.___handle___);
}

template <typename ___TTT___, typename>
inline derived_::derived_(___TTT___ value, bool reference)
	: root_(std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
		reference)
{}

template <typename ___TTT___, typename>
inline derived_& derived_::operator=(___TTT___ value)
{
	derived_ temp{ std::move(value) };
	std::swap(temp.___handle___, ___handle___);
	___handle___->___weak___(___handle___);
	return *this;
}

#endif