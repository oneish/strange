#ifndef COM_ONEISH_STRANGE_DATA_A_H
#define COM_ONEISH_STRANGE_DATA_A_H

// # include "any.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename DATA >
    class data_a : public ___root___

    {

    public:

     inline const DATA & extract__ ( ) const
     { assert(handle_); return read().extract__( ); }
     inline void mutate__ ( const DATA & data )
     { assert(handle_); write().mutate__(data ); }
     inline DATA & reference__ ( )
     { assert(handle_); return write().reference__( ); }
    

    protected:

    	struct ___derived_handle_base___ : ___root_handle_base___

    	{

      virtual inline const DATA & extract__ ( ) const = 0;
      virtual inline void mutate__ ( const DATA & data ) = 0;
      virtual inline DATA & reference__ ( ) = 0;
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

    

      virtual inline const DATA & extract__ ( ) const
      { return value_.extract__( ); }
      virtual inline void mutate__ ( const DATA & data )
      { value_.mutate__(data ); }
      virtual inline DATA & reference__ ( )
      { return value_.reference__( ); }
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

    

    	inline const ___derived_handle_base___& read() const

    	{

    		return *std::static_pointer_cast<const ___derived_handle_base___>(handle_);

    	}

    

    	inline ___derived_handle_base___& write()

    	{

    		if (!___reference___ && !handle_.unique())

    		{

    			handle_ = handle_->___clone___();

    			handle_->___weak___(handle_);

    		}

    		return *std::static_pointer_cast<___derived_handle_base___>(handle_);

    	}

    

    	template <typename ___TTT___, typename D>

    	friend inline bool check_(const data_a<D>& value);

    

    public:

    	static inline const char* ___abstraction_name___()

    	{

    		return "data";

    	}

    

    	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>& handle)

    	{

    		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    

    	inline data_a() = default;

    

    	explicit inline data_a(bool reference)

    		: ___root___{ reference }

    	{}

    

    	inline data_a(const data_a& other, bool reference)

    		: ___root___(other, reference)

    	{}

    

    	inline data_a(data_a&& other, bool reference)

    		: ___root___(std::move(other), reference)

    	{}

    

    	template <typename ___TTT___>

    	explicit inline data_a(const std::shared_ptr<___TTT___>& handle, bool reference = false)

    		: ___root___(handle, reference)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis__("data constructor failed to cast from base to derived");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    #endif

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<data_a, std::decay_t<___TTT___>>::value>>

    	explicit inline data_a(___TTT___ value, bool reference = false);

    

    	template <typename ___TTT___>

    	inline data_a& operator=(const std::shared_ptr<___TTT___>& handle)

    	{

    #ifdef STRANGE_CHECK_STATIC_CASTS

    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis__("data assignment failed to cast from base to derived");

    		}

    #else

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    #endif

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<data_a, std::decay_t<___TTT___>>::value>>

    	inline data_a& operator=(___TTT___ value);

    };

    

    template <typename ___TTT___, typename D>

    inline bool check_(const data_a<D>& value)

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

    template <typename DATA>

    template <typename ___TTT___, typename>

    inline data_a<DATA>::data_a(___TTT___ value, bool reference)

    	: ___root___(std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    		reference)

    {}

    

    template <typename DATA>

    template <typename ___TTT___, typename>

    inline data_a<DATA>& data_a<DATA>::operator=(___TTT___ value)

    {

    	data_a temp{ std::move(value) };

    	std::swap(temp.handle_, handle_);

    	handle_->___weak___(handle_);

    	return *this;

    }

    

    #undef ___root___

}
#endif