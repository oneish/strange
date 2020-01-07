#ifndef COM_ONEISH_STRANGE_NUMBER_DATA_A_H
#define COM_ONEISH_STRANGE_NUMBER_DATA_A_H

 //# include "any_forward.hpp"
 //# include "number_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class number_data_a final : public ___derived___

    {

    public:

    	inline number_data_a& operator++()

    	{

    		assert(handle_);

    		write().operator++();

    		return *this;

    	}

    

    	inline number_data_a operator++(int)

    	{

    		assert(handle_);

    		number_data_a result = *this;

    		write().operator++();

    		return result;

    	}

    

    	inline number_data_a& operator--()

    	{

    		assert(handle_);

    		write().operator--();

    		return *this;

    	}

    

    	inline number_data_a operator--(int)

    	{

    		assert(handle_);

    		number_data_a result = *this;

    		write().operator--();

    		return result;

    	}

    

    	inline number_data_a& operator+=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator+=(other);

    		return *this;

    	}

    

    	inline number_data_a& operator-=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator-=(other);

    		return *this;

    	}

    

    	inline number_data_a& operator*=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator*=(other);

    		return *this;

    	}

    

    	inline number_data_a& operator/=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator/=(other);

    		return *this;

    	}

    

    	inline number_data_a& operator%=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator%=(other);

    		return *this;

    	}

    

     inline _1_ const & extract_primitive ( ) const
     { assert(handle_); return read().extract_primitive( ); }
     inline _1_ & mutate_primitive ( )
     { assert(handle_); return write().mutate_primitive( ); }
    

    private:

    	struct ___finale_handle_base___ : ___derived_handle_base___

    	{

      virtual inline _1_ const & extract_primitive ( ) const = 0;
      virtual inline _1_ & mutate_primitive ( ) = 0;
    	};

    

    	template <typename ___TTT___>

    	struct ___finale_handle_final___ final : ___derived_handle___<___TTT___, ___finale_handle_base___>

    	{

    		template <typename ___UUU___ = ___TTT___>

    		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)

    			: ___derived_handle___<___TTT___, ___finale_handle_base___>{ value }

    		{}

    

    		template <typename ___UUU___ = ___TTT___>

    		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept

    			: ___derived_handle___<___TTT___, ___finale_handle_base___>{ std::move(value) }

    		{}

    

    		virtual inline ___SHARED___ ___clone___() const final

    		{

    			return std::make_shared<___finale_handle_final___>(___derived_handle___<___TTT___, ___finale_handle_base___>::value_);

    		}

    

      virtual inline _1_ const & extract_primitive ( ) const
      { return value_.extract_primitive( ); }
      virtual inline _1_ & mutate_primitive ( )
      { return value_.mutate_primitive( ); }
    	};

    

    	template <typename ___TTT___>

    	struct ___finale_handle_final___<std::reference_wrapper<___TTT___>> final

    		: ___finale_handle_final___<___TTT___&>

    	{

    		inline ___finale_handle_final___(std::reference_wrapper<___TTT___> ref)

    			: ___finale_handle_final___<___TTT___&>{ ref.get() }

    		{}

    	};

    

    	inline ___finale_handle_base___ const& read() const noexcept

    	{

    		return *std::static_pointer_cast<___finale_handle_base___ const>(handle_);

    	}

    

    	inline ___finale_handle_base___& write() noexcept

    	{

    		if (!handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    			handle_->___weak___(handle_);

    		}

    		return *std::static_pointer_cast<___finale_handle_base___>(handle_);

    	}

    

    	template <typename ___TTT___, typename ___1___>

    	friend inline bool check(number_data_a<___1___> const& value) noexcept;

    

    public:

    	static inline bool ___check___(___SHARED___ const& handle) noexcept

    	{

    		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    

    	inline number_data_a() = default;

    

    	inline number_data_a(number_data_a const& other, bool reference) noexcept

    		: ___derived___(other, reference)

    	{}

    

    	inline number_data_a(number_data_a& other, reference_tag) noexcept

    		: ___shared___{ ___SHARED___{} }

    		, handle_{ other.handle_ }

    	{}

    

    	static inline number_data_a ref(number_data_a& other) noexcept

    	{

    		return number_data_a(other, reference_tag{});

    	}

    

    	inline number_data_a(number_data_a& other, duplicate_tag) noexcept

    		: ___shared___{ &other.handle_ == &other.___shared___ ? other.handle_ : ___SHARED___{} }

    		, handle_{ *(&other.handle_ == &other.___shared___ ? &___shared___ : &other.handle_) }

    	{}

    

    	static inline number_data_a dup(number_data_a& other) noexcept

    	{

    		return number_data_a(other, duplicate_tag{});

    	}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline number_data_a(std::shared_ptr<___TTT___> const& handle)

    		: ___derived___{ handle }

    	{

    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis("number_data_a constructor failed to cast from base to final");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline number_data_a(std::shared_ptr<___TTT___> const& handle) noexcept

    		: ___derived___{ handle }

    	{

    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    #endif

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline number_data_a(std::shared_ptr<___TTT___> const& handle, bool reference)

    		: ___derived___(handle, reference)

    	{

    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis("number_data_a constructor failed to cast from base to final");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline number_data_a(std::shared_ptr<___TTT___> const& handle, bool reference) noexcept

    		: ___derived___(handle, reference)

    	{

    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    #endif

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline number_data_a(std::shared_ptr<___TTT___>& handle, reference_tag)

    		: ___derived___(handle, reference_tag{})

    	{

    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis("number_data_a constructor failed to cast from base to final");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline number_data_a(std::shared_ptr<___TTT___>& handle, reference_tag) noexcept

    		: ___derived___(handle, reference_tag{})

    	{

    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_data_a, std::decay_t<___TTT___>>::value>>

    	explicit inline number_data_a(___TTT___ value) noexcept

    		: ___derived___{ std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }

    	{

    		handle_->___weak___(handle_);

    	}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	inline number_data_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    		if (handle && !std::dynamic_pointer_cast<___finale_handle_base___>(handle))

    		{

    			throw dis("number_data_a assignment failed to cast from base to final");

    		}

    		handle_ = handle;

    		return *this;

    	}

    #else

    	template <typename ___TTT___>

    	inline number_data_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept

    	{

    		assert(!handle || std::dynamic_pointer_cast<___finale_handle_base___>(handle));

    		handle_ = handle;

    		return *this;

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_data_a, std::decay_t<___TTT___>>::value>>

    	inline number_data_a& operator=(___TTT___ value) noexcept

    	{

    		number_data_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		return *this;

    	}

    

    private:

    	static bool const ___share___;

    	friend class ___number_data_a_share___;

    };

    

    template <typename ___TTT___, typename ___1___>

    inline bool check(number_data_a<___1___> const& value) noexcept

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    template <typename ___1___>

    bool const number_data_a<___1___>::___share___ = []()

    {

    	auto& shoal = shared();

    	reflection<number_data_a<___1___>>::share(shoal);

    	return shoal.something();

    }();

    

    #undef ___derived___

}
#endif
