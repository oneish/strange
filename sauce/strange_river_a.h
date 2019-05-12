#ifndef COM_ONEISH_STRANGE_RIVER_A_H
#define COM_ONEISH_STRANGE_RIVER_A_H

 //#include "any_forward.hpp"
 //#include "range_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename number_data_a_int8 , typename number_data_a_int64 , typename lake_a_int8 >
    class river_a : public ___derived___
    {
    public:
    	inline river_a& operator++()
    	{
    		assert(handle_);
    		write().operator++();
    		return *this;
    	}
    
    	inline river_a operator++(int)
    	{
    		assert(handle_);
    		river_a result = *this;
    		write().operator++();
    		return result;
    	}
    
    	inline river_a& operator--()
    	{
    		assert(handle_);
    		write().operator--();
    		return *this;
    	}
    
    	inline river_a operator--(int)
    	{
    		assert(handle_);
    		river_a result = *this;
    		write().operator--();
    		return result;
    	}
    
    	inline river_a& operator+=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator+=(other);
    		return *this;
    	}
    
    	inline river_a& operator-=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator-=(other);
    		return *this;
    	}
    
    	inline river_a& operator*=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator*=(other);
    		return *this;
    	}
    
    	inline river_a& operator/=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator/=(other);
    		return *this;
    	}
    
    	inline river_a& operator%=(___root___ const& other)
    	{
    		assert(handle_);
    		write().operator%=(other);
    		return *this;
    	}
    
     any_a < > get__ ( range_a < > const & _ )
     { assert(handle_); return write().get__(_ ); }
     number_data_a_int8 get_ ( )
     { assert(handle_); return write().get_( ); }
     int8_t get ( )
     { assert(handle_); return write().get( ); }
     any_a < > peek__ ( range_a < > const & _ )
     { assert(handle_); return write().peek__(_ ); }
     number_data_a_int8 peek_ ( )
     { assert(handle_); return write().peek_( ); }
     int8_t peek ( )
     { assert(handle_); return write().peek( ); }
     any_a < > unget__ ( range_a < > const & _ )
     { assert(handle_); return write().unget__(_ ); }
     any_a < > unget_ ( )
     { assert(handle_); return write().unget_( ); }
     void unget ( )
     { assert(handle_); write().unget( ); }
     any_a < > putback__ ( range_a < > const & range )
     { assert(handle_); return write().putback__(range ); }
     any_a < > putback_ ( number_data_a_int8 const & int_8 )
     { assert(handle_); return write().putback_(int_8 ); }
     void putback ( int8_t int_8 )
     { assert(handle_); write().putback(int_8 ); }
     any_a < > getline__ ( range_a < > const & range )
     { assert(handle_); return write().getline__(range ); }
     lake_a_int8 getline_ ( number_data_a_int64 const & count , number_data_a_int8 const & delim )
     { assert(handle_); return write().getline_(count, delim ); }
     std :: vector < int8_t > getline ( int64_t count = - 1 , int8_t delim = '\n' )
     { assert(handle_); return write().getline(count, delim ); }
     any_a < > ignore__ ( range_a < > const & range )
     { assert(handle_); return write().ignore__(range ); }
     any_a < > ignore_ ( number_data_a_int64 const & count )
     { assert(handle_); return write().ignore_(count ); }
     void ignore ( int64_t count = 1 )
     { assert(handle_); write().ignore(count ); }
     any_a < > read__ ( range_a < > const & range )
     { assert(handle_); return write().read__(range ); }
     lake_a_int8 read_ ( number_data_a_int64 const & count )
     { assert(handle_); return write().read_(count ); }
     std :: vector < int8_t > read ( int64_t count = - 1 )
     { assert(handle_); return write().read(count ); }
    
    protected:
    	struct ___dderived_handle_base___ : ___derived_handle_base___
    	{
      virtual any_a < > get__ ( range_a < > const & _ ) = 0;
      virtual number_data_a_int8 get_ ( ) = 0;
      virtual int8_t get ( ) = 0;
      virtual any_a < > peek__ ( range_a < > const & _ ) = 0;
      virtual number_data_a_int8 peek_ ( ) = 0;
      virtual int8_t peek ( ) = 0;
      virtual any_a < > unget__ ( range_a < > const & _ ) = 0;
      virtual any_a < > unget_ ( ) = 0;
      virtual void unget ( ) = 0;
      virtual any_a < > putback__ ( range_a < > const & range ) = 0;
      virtual any_a < > putback_ ( number_data_a_int8 const & int_8 ) = 0;
      virtual void putback ( int8_t int_8 ) = 0;
      virtual any_a < > getline__ ( range_a < > const & range ) = 0;
      virtual lake_a_int8 getline_ ( number_data_a_int64 const & count , number_data_a_int8 const & delim ) = 0;
      virtual std :: vector < int8_t > getline ( int64_t count = - 1 , int8_t delim = '\n' ) = 0;
      virtual any_a < > ignore__ ( range_a < > const & range ) = 0;
      virtual any_a < > ignore_ ( number_data_a_int64 const & count ) = 0;
      virtual void ignore ( int64_t count = 1 ) = 0;
      virtual any_a < > read__ ( range_a < > const & range ) = 0;
      virtual lake_a_int8 read_ ( number_data_a_int64 const & count ) = 0;
      virtual std :: vector < int8_t > read ( int64_t count = - 1 ) = 0;
    	};
    
    	template <typename ___TTT___, typename ___DDHB___ = ___dderived_handle_base___>
    	struct ___dderived_handle___ : ___derived_handle___<___TTT___, ___DDHB___>
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___dderived_handle___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
    			: ___derived_handle___<___TTT___, ___DDHB___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___dderived_handle___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
    			: ___derived_handle___<___TTT___, ___DDHB___>{ std::move(value) }
    		{}
    
      virtual any_a < > get__ ( range_a < > const & _ )
      { return value_.get__(_ ); }
      virtual number_data_a_int8 get_ ( )
      { return value_.get_( ); }
      virtual int8_t get ( )
      { return value_.get( ); }
      virtual any_a < > peek__ ( range_a < > const & _ )
      { return value_.peek__(_ ); }
      virtual number_data_a_int8 peek_ ( )
      { return value_.peek_( ); }
      virtual int8_t peek ( )
      { return value_.peek( ); }
      virtual any_a < > unget__ ( range_a < > const & _ )
      { return value_.unget__(_ ); }
      virtual any_a < > unget_ ( )
      { return value_.unget_( ); }
      virtual void unget ( )
      { value_.unget( ); }
      virtual any_a < > putback__ ( range_a < > const & range )
      { return value_.putback__(range ); }
      virtual any_a < > putback_ ( number_data_a_int8 const & int_8 )
      { return value_.putback_(int_8 ); }
      virtual void putback ( int8_t int_8 )
      { value_.putback(int_8 ); }
      virtual any_a < > getline__ ( range_a < > const & range )
      { return value_.getline__(range ); }
      virtual lake_a_int8 getline_ ( number_data_a_int64 const & count , number_data_a_int8 const & delim )
      { return value_.getline_(count, delim ); }
      virtual std :: vector < int8_t > getline ( int64_t count = - 1 , int8_t delim = '\n' )
      { return value_.getline(count, delim ); }
      virtual any_a < > ignore__ ( range_a < > const & range )
      { return value_.ignore__(range ); }
      virtual any_a < > ignore_ ( number_data_a_int64 const & count )
      { return value_.ignore_(count ); }
      virtual void ignore ( int64_t count = 1 )
      { value_.ignore(count ); }
      virtual any_a < > read__ ( range_a < > const & range )
      { return value_.read__(range ); }
      virtual lake_a_int8 read_ ( number_data_a_int64 const & count )
      { return value_.read_(count ); }
      virtual std :: vector < int8_t > read ( int64_t count = - 1 )
      { return value_.read(count ); }
    	};
    
    	template <typename ___TTT___, typename ___DDHB___>
    	struct ___dderived_handle___<std::reference_wrapper<___TTT___>, ___DDHB___>
    		: ___dderived_handle___<___TTT___&, ___DDHB___>
    	{
    		inline ___dderived_handle___(std::reference_wrapper<___TTT___> ref)
    			: ___dderived_handle___<___TTT___&, ___DDHB___>{ ref.get() }
    		{}
    	};
    
    private:
    	template <typename ___TTT___>
    	struct ___dderived_handle_final___ final : ___dderived_handle___<___TTT___>
    	{
    		template <typename ___UUU___ = ___TTT___>
    		inline ___dderived_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
    			: ___dderived_handle___<___TTT___>{ value }
    		{}
    
    		template <typename ___UUU___ = ___TTT___>
    		inline ___dderived_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
    			: ___dderived_handle___<___TTT___>{ std::move(value) }
    		{}
    
    		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final
    		{
    			return std::make_shared<___dderived_handle_final___>(___dderived_handle___<___TTT___>::value_);
    		}
    	};
    
    	template <typename ___TTT___>
    	struct ___dderived_handle_final___<std::reference_wrapper<___TTT___>> final
    		: ___dderived_handle_final___<___TTT___&>
    	{
    		inline ___dderived_handle_final___(std::reference_wrapper<___TTT___> ref)
    			: ___dderived_handle_final___<___TTT___&>{ ref.get() }
    		{}
    	};
    
    	inline ___dderived_handle_base___ const& read() const noexcept
    	{
    		return *std::static_pointer_cast<___dderived_handle_base___ const>(handle_);
    	}
    
    	inline ___dderived_handle_base___& write() noexcept
    	{
    		if (!___reference___ && !handle_.unique())
    		{
    			handle_ = handle_->___clone___();
    			handle_->___weak___(handle_);
    		}
    		return *std::static_pointer_cast<___dderived_handle_base___>(handle_);
    	}
    
    	template <typename ___TTT___>
    	friend inline bool check_(river_a<> const& value) noexcept;
    
    public:
    	static inline char const* ___abstraction_name___() noexcept
    	{
    		return "river_a";
    	}
    
    	static inline bool ___check___(std::shared_ptr<___root_handle_base___>const & handle) noexcept
    	{
    		return bool(std::dynamic_pointer_cast<___dderived_handle_base___>(handle));
    	}
    
    	inline river_a() = default;
    
    	explicit inline river_a(bool reference) noexcept
    		: ___derived___{ reference }
    	{}
    
    	inline river_a(river_a const& other, bool reference) noexcept
    		: ___derived___(other, reference)
    	{}
    
    	inline river_a(river_a&& other, bool reference) noexcept
    		: ___derived___(std::move(other), reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	explicit inline river_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)
    		: ___derived___(handle, reference)
    	{
    		if (!std::dynamic_pointer_cast<___dderived_handle_base___>(handle))
    		{
    			throw dis("river_a constructor failed to cast from base to dderived");
    		}
    	}
    #else
    	template <typename ___TTT___>
    	explicit inline river_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept
    		: ___derived___(handle, reference)
    	{
    		assert(std::dynamic_pointer_cast<___dderived_handle_base___>(handle));
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<river_a, std::decay_t<___TTT___>>::value>>
    	explicit inline river_a(___TTT___ value, bool reference = false) noexcept
    		: ___derived___(std::make_shared<___dderived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
    			reference)
    	{}
    
    #ifdef STRANGE_CHECK_STATIC_CASTS
    	template <typename ___TTT___>
    	inline river_a& operator=(std::shared_ptr<___TTT___> const& handle)
    	{
    		if (!std::dynamic_pointer_cast<___dderived_handle_base___>(handle))
    		{
    			throw dis("river_a assignment failed to cast from base to dderived");
    		}
    		handle_ = handle;
    		handle_->___weak___(handle_);
    		return *this;
    	}
    #else
    	template <typename ___TTT___>
    	inline river_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
    	{
    		assert(std::dynamic_pointer_cast<___dderived_handle_base___>(handle));
    		handle_ = handle;
    		handle_->___weak___(handle_);
    		return *this;
    	}
    #endif
    
    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<river_a, std::decay_t<___TTT___>>::value>>
    	inline river_a& operator=(___TTT___ value) noexcept
    	{
    		river_a temp{ std::move(value) };
    		std::swap(temp.handle_, handle_);
    		handle_->___weak___(handle_);
    		return *this;
    	}
    };
    
    template <typename ___TTT___>
    inline bool check_(river_a<> const& value) noexcept
    {
    	return ___TTT___::___check___(value.handle_);
    }
    
    #undef ___derived___

}
#endif
