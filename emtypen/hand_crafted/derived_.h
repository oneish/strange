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
		assert(handle_);
		write().mutate();
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
			___root_handle___<___TTT___, ___DHB___>::value_.mutate();
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

		virtual inline std::shared_ptr<___root_handle_base___> clone() const final
		{
			return std::make_shared<___derived_handle_final___>(___derived_handle___<___TTT___>::value_);
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

	inline const ___derived_handle_base___& read() const
	{
		return *std::static_pointer_cast<const ___derived_handle_base___>(handle_);
	}

	inline ___derived_handle_base___& write()
	{
		if (!handle_.unique())
		{
			handle_ = handle_->clone();
		}
		return *std::static_pointer_cast<___derived_handle_base___>(handle_);
	}

	template <typename ___TTT___>
	friend inline bool check_(const derived_& v);

public:
	static inline bool check(const std::shared_ptr<___root_handle_base___>& h)
	{
		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(h));
	}

	derived_() = default;

	template <typename ___TTT___>
	inline derived_(const std::shared_ptr<___TTT___>& other)
		: root_{ other }
	{
		assert(std::dynamic_pointer_cast<___derived_handle_base___>(other));
	}

	template <typename ___TTT___>
	inline derived_(___TTT___ value);

	template <typename ___TTT___>
	inline derived_& operator=(const std::shared_ptr<___TTT___>& other)
	{
		assert(std::dynamic_pointer_cast<___derived_handle_base___>(other));
		handle_ = other;
		return *this;
	}

	template <typename ___TTT___>
	inline derived_& operator=(___TTT___ value);
};

template <typename ___TTT___>
inline bool check_(const derived_& v)
{
	return ___TTT___::check(v.handle_);
}

template <typename ___TTT___>
inline derived_::derived_(___TTT___ value)
	: root_{ check_<derived_>(value)
		? static_<derived_>(std::move(value)).handle_
		: std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
{}

template <typename ___TTT___>
inline derived_& derived_::operator=(___TTT___ value)
{
	derived_ temp{ check_<derived_>(value)
		? static_<derived_>(std::move(value))
		: std::move(value) };
	std::swap(temp.handle_, handle_);
	return *this;
}

#endif