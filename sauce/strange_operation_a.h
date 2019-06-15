#ifndef COM_ONEISH_STRANGE_OPERATION_A_H
#define COM_ONEISH_STRANGE_OPERATION_A_H

 //#include "any_forward.hpp"
 //#include "range_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename _1_ >
    class operation_a : public ___root___

    {

    public:

    	inline operation_a& operator++()

    	{

    		assert(handle_);

    		write().operator++();

    		return *this;

    	}

    

    	inline operation_a operator++(int)

    	{

    		assert(handle_);

    		operation_a result = *this;

    		write().operator++();

    		return result;

    	}

    

    	inline operation_a& operator--()

    	{

    		assert(handle_);

    		write().operator--();

    		return *this;

    	}

    

    	inline operation_a operator--(int)

    	{

    		assert(handle_);

    		operation_a result = *this;

    		write().operator--();

    		return result;

    	}

    

    	inline operation_a& operator+=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator+=(other);

    		return *this;

    	}

    

    	inline operation_a& operator-=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator-=(other);

    		return *this;

    	}

    

    	inline operation_a& operator*=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator*=(other);

    		return *this;

    	}

    

    	inline operation_a& operator/=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator/=(other);

    		return *this;

    	}

    

    	inline operation_a& operator%=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator%=(other);

    		return *this;

    	}

    

     inline any_a < > pure__ ( range_a < > const & _ ) const
     { assert(handle_); return read().pure__(_ ); }
     inline any_a < > pure_ ( ) const
     { assert(handle_); return read().pure_( ); }
     inline bool pure ( ) const
     { assert(handle_); return read().pure( ); }
     inline any_a < > literal__ ( range_a < > const & _ ) const
     { assert(handle_); return read().literal__(_ ); }
     inline any_a < > literal_ ( ) const
     { assert(handle_); return read().literal_( ); }
     inline bool literal ( ) const
     { assert(handle_); return read().literal( ); }
    

    protected:

    	struct ___derived_handle_base___ : ___root_handle_base___

    	{

      virtual inline any_a < > pure__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > pure_ ( ) const = 0;
      virtual inline bool pure ( ) const = 0;
      virtual inline any_a < > literal__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > literal_ ( ) const = 0;
      virtual inline bool literal ( ) const = 0;
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

    

      virtual inline any_a < > pure__ ( range_a < > const & _ ) const
      { return value_.pure__(_ ); }
      virtual inline any_a < > pure_ ( ) const
      { return value_.pure_( ); }
      virtual inline bool pure ( ) const
      { return value_.pure( ); }
      virtual inline any_a < > literal__ ( range_a < > const & _ ) const
      { return value_.literal__(_ ); }
      virtual inline any_a < > literal_ ( ) const
      { return value_.literal_( ); }
      virtual inline bool literal ( ) const
      { return value_.literal( ); }
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

    

    	inline ___derived_handle_base___ const& read() const noexcept

    	{

    		return *std::static_pointer_cast<___derived_handle_base___ const>(handle_);

    	}

    

    	inline ___derived_handle_base___& write() noexcept

    	{

    		if (!___reference___ && !handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    			handle_->___weak___(handle_);

    		}

    		return *std::static_pointer_cast<___derived_handle_base___>(handle_);

    	}

    

    	template <typename ___TTT___>

    	friend inline bool check(operation_a<> const& value) noexcept;

    

    public:

    	static inline bool ___check___(std::shared_ptr<___root_handle_base___>const & handle) noexcept

    	{

    		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    

    	inline operation_a() = default;

    

    	explicit inline operation_a(bool reference) noexcept

    		: ___root___{ reference }

    	{}

    

    	inline operation_a(operation_a const& other, bool reference) noexcept

    		: ___root___(other, reference)

    	{}

    

    	inline operation_a(operation_a&& other, bool reference) noexcept

    		: ___root___(std::move(other), reference)

    	{}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline operation_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)

    		: ___root___(handle, reference)

    	{

    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis("operation_a constructor failed to cast from base to derived");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline operation_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept

    		: ___root___(handle, reference)

    	{

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<operation_a, std::decay_t<___TTT___>>::value>>

    	explicit inline operation_a(___TTT___ value, bool reference = false) noexcept

    		: ___root___(std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    			reference)

    	{}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	inline operation_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis("operation_a assignment failed to cast from base to derived");

    		}

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    #else

    	template <typename ___TTT___>

    	inline operation_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept

    	{

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<operation_a, std::decay_t<___TTT___>>::value>>

    	inline operation_a& operator=(___TTT___ value) noexcept

    	{

    		operation_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		handle_->___weak___(handle_);

    		return *this;

    	}

    };

    

    template <typename ___TTT___>

    inline bool check(operation_a<> const& value) noexcept

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

}
#endif