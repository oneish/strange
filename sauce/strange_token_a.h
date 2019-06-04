#ifndef COM_ONEISH_STRANGE_TOKEN_A_H
#define COM_ONEISH_STRANGE_TOKEN_A_H

 //#include "any_forward.hpp"
 //#include "range_forward.hpp"
 //#include "symbol_forward.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>


namespace strange {
    template < typename number_data_a_int64 >
    class token_a : public ___root___

    {

    public:

    	inline token_a& operator++()

    	{

    		assert(handle_);

    		write().operator++();

    		return *this;

    	}

    

    	inline token_a operator++(int)

    	{

    		assert(handle_);

    		token_a result = *this;

    		write().operator++();

    		return result;

    	}

    

    	inline token_a& operator--()

    	{

    		assert(handle_);

    		write().operator--();

    		return *this;

    	}

    

    	inline token_a operator--(int)

    	{

    		assert(handle_);

    		token_a result = *this;

    		write().operator--();

    		return result;

    	}

    

    	inline token_a& operator+=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator+=(other);

    		return *this;

    	}

    

    	inline token_a& operator-=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator-=(other);

    		return *this;

    	}

    

    	inline token_a& operator*=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator*=(other);

    		return *this;

    	}

    

    	inline token_a& operator/=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator/=(other);

    		return *this;

    	}

    

    	inline token_a& operator%=(___root___ const& other)

    	{

    		assert(handle_);

    		write().operator%=(other);

    		return *this;

    	}

    

     inline any_a < > filename__ ( range_a < > const & _ ) const
     { assert(handle_); return read().filename__(_ ); }
     inline symbol_a < > filename_ ( ) const
     { assert(handle_); return read().filename_( ); }
     inline std :: string filename ( ) const
     { assert(handle_); return read().filename( ); }
     inline any_a < > line__ ( range_a < > const & _ ) const
     { assert(handle_); return read().line__(_ ); }
     inline number_data_a_int64 line_ ( ) const
     { assert(handle_); return read().line_( ); }
     inline int64_t line ( ) const
     { assert(handle_); return read().line( ); }
     inline any_a < > position__ ( range_a < > const & _ ) const
     { assert(handle_); return read().position__(_ ); }
     inline number_data_a_int64 position_ ( ) const
     { assert(handle_); return read().position_( ); }
     inline int64_t position ( ) const
     { assert(handle_); return read().position( ); }
     inline any_a < > tag__ ( range_a < > const & _ ) const
     { assert(handle_); return read().tag__(_ ); }
     inline symbol_a < > tag_ ( ) const
     { assert(handle_); return read().tag_( ); }
     inline std :: string tag ( ) const
     { assert(handle_); return read().tag( ); }
     inline any_a < > symbol__ ( range_a < > const & _ ) const
     { assert(handle_); return read().symbol__(_ ); }
     inline symbol_a < > symbol_ ( ) const
     { assert(handle_); return read().symbol_( ); }
     inline std :: string symbol ( ) const
     { assert(handle_); return read().symbol( ); }
     inline any_a < > literal__ ( range_a < > const & _ ) const
     { assert(handle_); return read().literal__(_ ); }
     inline any_a < > literal_ ( ) const
     { assert(handle_); return read().literal_( ); }
     inline any_a < > precedence__ ( range_a < > const & _ ) const
     { assert(handle_); return read().precedence__(_ ); }
     inline number_data_a_int64 precedence_ ( ) const
     { assert(handle_); return read().precedence_( ); }
     inline int64_t precedence ( ) const
     { assert(handle_); return read().precedence( ); }
    

    protected:

    	struct ___derived_handle_base___ : ___root_handle_base___

    	{

      virtual inline any_a < > filename__ ( range_a < > const & _ ) const = 0;
      virtual inline symbol_a < > filename_ ( ) const = 0;
      virtual inline std :: string filename ( ) const = 0;
      virtual inline any_a < > line__ ( range_a < > const & _ ) const = 0;
      virtual inline number_data_a_int64 line_ ( ) const = 0;
      virtual inline int64_t line ( ) const = 0;
      virtual inline any_a < > position__ ( range_a < > const & _ ) const = 0;
      virtual inline number_data_a_int64 position_ ( ) const = 0;
      virtual inline int64_t position ( ) const = 0;
      virtual inline any_a < > tag__ ( range_a < > const & _ ) const = 0;
      virtual inline symbol_a < > tag_ ( ) const = 0;
      virtual inline std :: string tag ( ) const = 0;
      virtual inline any_a < > symbol__ ( range_a < > const & _ ) const = 0;
      virtual inline symbol_a < > symbol_ ( ) const = 0;
      virtual inline std :: string symbol ( ) const = 0;
      virtual inline any_a < > literal__ ( range_a < > const & _ ) const = 0;
      virtual inline any_a < > literal_ ( ) const = 0;
      virtual inline any_a < > precedence__ ( range_a < > const & _ ) const = 0;
      virtual inline number_data_a_int64 precedence_ ( ) const = 0;
      virtual inline int64_t precedence ( ) const = 0;
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

    

      virtual inline any_a < > filename__ ( range_a < > const & _ ) const
      { return value_.filename__(_ ); }
      virtual inline symbol_a < > filename_ ( ) const
      { return value_.filename_( ); }
      virtual inline std :: string filename ( ) const
      { return value_.filename( ); }
      virtual inline any_a < > line__ ( range_a < > const & _ ) const
      { return value_.line__(_ ); }
      virtual inline number_data_a_int64 line_ ( ) const
      { return value_.line_( ); }
      virtual inline int64_t line ( ) const
      { return value_.line( ); }
      virtual inline any_a < > position__ ( range_a < > const & _ ) const
      { return value_.position__(_ ); }
      virtual inline number_data_a_int64 position_ ( ) const
      { return value_.position_( ); }
      virtual inline int64_t position ( ) const
      { return value_.position( ); }
      virtual inline any_a < > tag__ ( range_a < > const & _ ) const
      { return value_.tag__(_ ); }
      virtual inline symbol_a < > tag_ ( ) const
      { return value_.tag_( ); }
      virtual inline std :: string tag ( ) const
      { return value_.tag( ); }
      virtual inline any_a < > symbol__ ( range_a < > const & _ ) const
      { return value_.symbol__(_ ); }
      virtual inline symbol_a < > symbol_ ( ) const
      { return value_.symbol_( ); }
      virtual inline std :: string symbol ( ) const
      { return value_.symbol( ); }
      virtual inline any_a < > literal__ ( range_a < > const & _ ) const
      { return value_.literal__(_ ); }
      virtual inline any_a < > literal_ ( ) const
      { return value_.literal_( ); }
      virtual inline any_a < > precedence__ ( range_a < > const & _ ) const
      { return value_.precedence__(_ ); }
      virtual inline number_data_a_int64 precedence_ ( ) const
      { return value_.precedence_( ); }
      virtual inline int64_t precedence ( ) const
      { return value_.precedence( ); }
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

    	friend inline bool check(token_a<> const& value) noexcept;

    

    public:

    	static inline bool ___check___(std::shared_ptr<___root_handle_base___>const & handle) noexcept

    	{

    		return bool(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    

    	inline token_a() = default;

    

    	explicit inline token_a(bool reference) noexcept

    		: ___root___{ reference }

    	{}

    

    	inline token_a(token_a const& other, bool reference) noexcept

    		: ___root___(other, reference)

    	{}

    

    	inline token_a(token_a&& other, bool reference) noexcept

    		: ___root___(std::move(other), reference)

    	{}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	explicit inline token_a(std::shared_ptr<___TTT___> const& handle, bool reference = false)

    		: ___root___(handle, reference)

    	{

    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis("token_a constructor failed to cast from base to derived");

    		}

    	}

    #else

    	template <typename ___TTT___>

    	explicit inline token_a(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept

    		: ___root___(handle, reference)

    	{

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<token_a, std::decay_t<___TTT___>>::value>>

    	explicit inline token_a(___TTT___ value, bool reference = false) noexcept

    		: ___root___(std::make_shared<___derived_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),

    			reference)

    	{}

    

    #ifdef STRANGE_CHECK_STATIC_CASTS

    	template <typename ___TTT___>

    	inline token_a& operator=(std::shared_ptr<___TTT___> const& handle)

    	{

    		if (!std::dynamic_pointer_cast<___derived_handle_base___>(handle))

    		{

    			throw dis("token_a assignment failed to cast from base to derived");

    		}

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    #else

    	template <typename ___TTT___>

    	inline token_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept

    	{

    		assert(std::dynamic_pointer_cast<___derived_handle_base___>(handle));

    		handle_ = handle;

    		handle_->___weak___(handle_);

    		return *this;

    	}

    #endif

    

    	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<token_a, std::decay_t<___TTT___>>::value>>

    	inline token_a& operator=(___TTT___ value) noexcept

    	{

    		token_a temp{ std::move(value) };

    		std::swap(temp.handle_, handle_);

    		handle_->___weak___(handle_);

    		return *this;

    	}

    };

    

    template <typename ___TTT___>

    inline bool check(token_a<> const& value) noexcept

    {

    	return ___TTT___::___check___(value.handle_);

    }

    

}
#endif