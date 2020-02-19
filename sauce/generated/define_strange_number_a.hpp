
namespace strange
{

template <typename ___TTT___, typename number_data_int64_a_chk = number_data_int64_a<> , typename number_data_uint64_a_chk = number_data_uint64_a<> , typename number_data_double_a_chk = number_data_double_a<> >
inline bool check(number_a<number_data_int64_a_chk, number_data_uint64_a_chk, number_data_double_a_chk> const& value) noexcept;

template <typename number_data_int64_a, typename number_data_uint64_a, typename number_data_double_a>
class number_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline number_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

	inline number_a operator++(int)
	{
		assert(handle_);
		number_a result = *this;
		write().operator++();
		return result;
	}

	inline number_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

	inline number_a operator--(int)
	{
		assert(handle_);
		number_a result = *this;
		write().operator--();
		return result;
	}

	inline number_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline number_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline number_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline number_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline number_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline any_a<> increment__(range_a<> const& range)
	{ assert(handle_); return write().increment__(range); }

	inline number_a<> increment_()
	{ assert(handle_); return write().increment_(); }

	inline any_a<> decrement__(range_a<> const& range)
	{ assert(handle_); return write().decrement__(range); }

	inline number_a<> decrement_()
	{ assert(handle_); return write().decrement_(); }

	inline any_a<> self_assign__(range_a<> const& range)
	{ assert(handle_); return write().self_assign__(range); }

	inline number_a<> self_assign_(number_a<> const& number)
	{ assert(handle_); return write().self_assign_(number); }

	inline any_a<> self_add__(range_a<> const& range)
	{ assert(handle_); return write().self_add__(range); }

	inline number_a<> self_add_(number_a<> const& number)
	{ assert(handle_); return write().self_add_(number); }

	inline any_a<> add__(range_a<> const& range) const
	{ assert(handle_); return read().add__(range); }

	inline number_a<> add_(number_a<> const& number) const
	{ assert(handle_); return read().add_(number); }

	inline number_a < > operator+(number_a < > const & number ) const
	{ assert(handle_); return read().operator+(number); }

	inline any_a<> self_subtract__(range_a<> const& range)
	{ assert(handle_); return write().self_subtract__(range); }

	inline number_a<> self_subtract_(number_a<> const& number)
	{ assert(handle_); return write().self_subtract_(number); }

	inline any_a<> subtract__(range_a<> const& range) const
	{ assert(handle_); return read().subtract__(range); }

	inline number_a<> subtract_(number_a<> const& number) const
	{ assert(handle_); return read().subtract_(number); }

	inline number_a < > operator-(number_a < > const & number ) const
	{ assert(handle_); return read().operator-(number); }

	inline any_a<> self_multiply__(range_a<> const& range)
	{ assert(handle_); return write().self_multiply__(range); }

	inline number_a<> self_multiply_(number_a<> const& number)
	{ assert(handle_); return write().self_multiply_(number); }

	inline any_a<> multiply__(range_a<> const& range) const
	{ assert(handle_); return read().multiply__(range); }

	inline number_a<> multiply_(number_a<> const& number) const
	{ assert(handle_); return read().multiply_(number); }

	inline number_a < > operator*(number_a < > const & number ) const
	{ assert(handle_); return read().operator*(number); }

	inline any_a<> self_divide__(range_a<> const& range)
	{ assert(handle_); return write().self_divide__(range); }

	inline number_a<> self_divide_(number_a<> const& number)
	{ assert(handle_); return write().self_divide_(number); }

	inline any_a<> divide__(range_a<> const& range) const
	{ assert(handle_); return read().divide__(range); }

	inline number_a<> divide_(number_a<> const& number) const
	{ assert(handle_); return read().divide_(number); }

	inline number_a < > operator/(number_a < > const & number ) const
	{ assert(handle_); return read().operator/(number); }

	inline any_a<> self_modulo__(range_a<> const& range)
	{ assert(handle_); return write().self_modulo__(range); }

	inline number_a<> self_modulo_(number_a<> const& number)
	{ assert(handle_); return write().self_modulo_(number); }

	inline any_a<> modulo__(range_a<> const& range) const
	{ assert(handle_); return read().modulo__(range); }

	inline number_a<> modulo_(number_a<> const& number) const
	{ assert(handle_); return read().modulo_(number); }

	inline number_a < > operator%(number_a < > const & number ) const
	{ assert(handle_); return read().operator%(number); }

	inline any_a<> to_int_64__(range_a<> const& range) const
	{ assert(handle_); return read().to_int_64__(range); }

	inline number_data_int64_a to_int_64_() const
	{ assert(handle_); return read().to_int_64_(); }

	inline int64_t to_int_64() const
	{ assert(handle_); return read().to_int_64(); }

	inline any_a<> from_int_64__(range_a<> const& range)
	{ assert(handle_); return write().from_int_64__(range); }

	inline any_a<> from_int_64_(number_data_int64_a const& int_64)
	{ assert(handle_); return write().from_int_64_(int_64); }

	inline void from_int_64(int64_t int_64 )
	{ assert(handle_); write().from_int_64(int_64); }

	inline any_a<> to_uint_64__(range_a<> const& range) const
	{ assert(handle_); return read().to_uint_64__(range); }

	inline number_data_uint64_a to_uint_64_() const
	{ assert(handle_); return read().to_uint_64_(); }

	inline uint64_t to_uint_64() const
	{ assert(handle_); return read().to_uint_64(); }

	inline any_a<> from_uint_64__(range_a<> const& range)
	{ assert(handle_); return write().from_uint_64__(range); }

	inline any_a<> from_uint_64_(number_data_uint64_a const& uint_64)
	{ assert(handle_); return write().from_uint_64_(uint_64); }

	inline void from_uint_64(uint64_t uint_64 )
	{ assert(handle_); write().from_uint_64(uint_64); }

	inline any_a<> to_float_64__(range_a<> const& range) const
	{ assert(handle_); return read().to_float_64__(range); }

	inline number_data_double_a to_float_64_() const
	{ assert(handle_); return read().to_float_64_(); }

	inline double to_float_64() const
	{ assert(handle_); return read().to_float_64(); }

	inline any_a<> from_float_64__(range_a<> const& range)
	{ assert(handle_); return write().from_float_64__(range); }

	inline any_a<> from_float_64_(number_data_double_a const& int_64)
	{ assert(handle_); return write().from_float_64_(int_64); }

	inline void from_float_64(double int_64 )
	{ assert(handle_); write().from_float_64(int_64); }

	inline any_a<> less_than__(range_a<> const& range) const
	{ assert(handle_); return read().less_than__(range); }

	inline any_a<> less_than_(number_a<> const& number) const
	{ assert(handle_); return read().less_than_(number); }

	inline bool operator<(number_a < > const & number ) const
	{ assert(handle_); return read().operator<(number); }

	inline any_a<> greater_than__(range_a<> const& range) const
	{ assert(handle_); return read().greater_than__(range); }

	inline any_a<> greater_than_(number_a<> const& number) const
	{ assert(handle_); return read().greater_than_(number); }

	inline bool operator>(number_a < > const & number ) const
	{ assert(handle_); return read().operator>(number); }

	inline any_a<> less_or_equal__(range_a<> const& range) const
	{ assert(handle_); return read().less_or_equal__(range); }

	inline any_a<> less_or_equal_(number_a<> const& number) const
	{ assert(handle_); return read().less_or_equal_(number); }

	inline bool operator<=(number_a < > const & number ) const
	{ assert(handle_); return read().operator<=(number); }

	inline any_a<> greater_or_equal__(range_a<> const& range) const
	{ assert(handle_); return read().greater_or_equal__(range); }

	inline any_a<> greater_or_equal_(number_a<> const& number) const
	{ assert(handle_); return read().greater_or_equal_(number); }

	inline bool operator>=(number_a < > const & number ) const
	{ assert(handle_); return read().operator>=(number); }

	inline any_a<> byte_size__(range_a<> const& range) const
	{ assert(handle_); return read().byte_size__(range); }

	inline number_data_int64_a byte_size_() const
	{ assert(handle_); return read().byte_size_(); }

	inline int64_t byte_size() const
	{ assert(handle_); return read().byte_size(); }

	inline any_a<> is_int__(range_a<> const& range) const
	{ assert(handle_); return read().is_int__(range); }

	inline any_a<> is_int_() const
	{ assert(handle_); return read().is_int_(); }

	inline bool is_int() const
	{ assert(handle_); return read().is_int(); }

	inline any_a<> is_signed__(range_a<> const& range) const
	{ assert(handle_); return read().is_signed__(range); }

	inline any_a<> is_signed_() const
	{ assert(handle_); return read().is_signed_(); }

	inline bool is_signed() const
	{ assert(handle_); return read().is_signed(); }

	inline any_a<> is_nan__(range_a<> const& range) const
	{ assert(handle_); return read().is_nan__(range); }

	inline any_a<> is_nan_() const
	{ assert(handle_); return read().is_nan_(); }

	inline bool is_nan() const
	{ assert(handle_); return read().is_nan(); }

	inline any_a<> is_inf__(range_a<> const& range) const
	{ assert(handle_); return read().is_inf__(range); }

	inline any_a<> is_inf_() const
	{ assert(handle_); return read().is_inf_(); }

	inline bool is_inf() const
	{ assert(handle_); return read().is_inf(); }

	inline any_a<> is_finite__(range_a<> const& range) const
	{ assert(handle_); return read().is_finite__(range); }

	inline any_a<> is_finite_() const
	{ assert(handle_); return read().is_finite_(); }

	inline bool is_finite() const
	{ assert(handle_); return read().is_finite(); }

	inline any_a<> is_normal__(range_a<> const& range) const
	{ assert(handle_); return read().is_normal__(range); }

	inline any_a<> is_normal_() const
	{ assert(handle_); return read().is_normal_(); }

	inline bool is_normal() const
	{ assert(handle_); return read().is_normal(); }

	inline any_a<> little_endian__(range_a<> const& range) const
	{ assert(handle_); return read().little_endian__(range); }

	inline any_a<> little_endian_() const
	{ assert(handle_); return read().little_endian_(); }

	inline bool little_endian() const
	{ assert(handle_); return read().little_endian(); }

protected:
	struct ___number_a_handle_base___ : ___any_a_handle_base___
	{
		virtual inline any_a<> increment__(range_a<> const& range) = 0;
		virtual inline number_a<> increment_() = 0;
		virtual inline any_a<> decrement__(range_a<> const& range) = 0;
		virtual inline number_a<> decrement_() = 0;
		virtual inline any_a<> self_assign__(range_a<> const& range) = 0;
		virtual inline number_a<> self_assign_(number_a<> const& number) = 0;
		virtual inline any_a<> self_add__(range_a<> const& range) = 0;
		virtual inline number_a<> self_add_(number_a<> const& number) = 0;
		virtual inline any_a<> add__(range_a<> const& range) const = 0;
		virtual inline number_a<> add_(number_a<> const& number) const = 0;
		virtual inline number_a < > operator+(number_a < > const & number ) const = 0;
		virtual inline any_a<> self_subtract__(range_a<> const& range) = 0;
		virtual inline number_a<> self_subtract_(number_a<> const& number) = 0;
		virtual inline any_a<> subtract__(range_a<> const& range) const = 0;
		virtual inline number_a<> subtract_(number_a<> const& number) const = 0;
		virtual inline number_a < > operator-(number_a < > const & number ) const = 0;
		virtual inline any_a<> self_multiply__(range_a<> const& range) = 0;
		virtual inline number_a<> self_multiply_(number_a<> const& number) = 0;
		virtual inline any_a<> multiply__(range_a<> const& range) const = 0;
		virtual inline number_a<> multiply_(number_a<> const& number) const = 0;
		virtual inline number_a < > operator*(number_a < > const & number ) const = 0;
		virtual inline any_a<> self_divide__(range_a<> const& range) = 0;
		virtual inline number_a<> self_divide_(number_a<> const& number) = 0;
		virtual inline any_a<> divide__(range_a<> const& range) const = 0;
		virtual inline number_a<> divide_(number_a<> const& number) const = 0;
		virtual inline number_a < > operator/(number_a < > const & number ) const = 0;
		virtual inline any_a<> self_modulo__(range_a<> const& range) = 0;
		virtual inline number_a<> self_modulo_(number_a<> const& number) = 0;
		virtual inline any_a<> modulo__(range_a<> const& range) const = 0;
		virtual inline number_a<> modulo_(number_a<> const& number) const = 0;
		virtual inline number_a < > operator%(number_a < > const & number ) const = 0;
		virtual inline any_a<> to_int_64__(range_a<> const& range) const = 0;
		virtual inline number_data_int64_a to_int_64_() const = 0;
		virtual inline int64_t to_int_64() const = 0;
		virtual inline any_a<> from_int_64__(range_a<> const& range) = 0;
		virtual inline any_a<> from_int_64_(number_data_int64_a const& int_64) = 0;
		virtual inline void from_int_64(int64_t int_64 ) = 0;
		virtual inline any_a<> to_uint_64__(range_a<> const& range) const = 0;
		virtual inline number_data_uint64_a to_uint_64_() const = 0;
		virtual inline uint64_t to_uint_64() const = 0;
		virtual inline any_a<> from_uint_64__(range_a<> const& range) = 0;
		virtual inline any_a<> from_uint_64_(number_data_uint64_a const& uint_64) = 0;
		virtual inline void from_uint_64(uint64_t uint_64 ) = 0;
		virtual inline any_a<> to_float_64__(range_a<> const& range) const = 0;
		virtual inline number_data_double_a to_float_64_() const = 0;
		virtual inline double to_float_64() const = 0;
		virtual inline any_a<> from_float_64__(range_a<> const& range) = 0;
		virtual inline any_a<> from_float_64_(number_data_double_a const& int_64) = 0;
		virtual inline void from_float_64(double int_64 ) = 0;
		virtual inline any_a<> less_than__(range_a<> const& range) const = 0;
		virtual inline any_a<> less_than_(number_a<> const& number) const = 0;
		virtual inline bool operator<(number_a < > const & number ) const = 0;
		virtual inline any_a<> greater_than__(range_a<> const& range) const = 0;
		virtual inline any_a<> greater_than_(number_a<> const& number) const = 0;
		virtual inline bool operator>(number_a < > const & number ) const = 0;
		virtual inline any_a<> less_or_equal__(range_a<> const& range) const = 0;
		virtual inline any_a<> less_or_equal_(number_a<> const& number) const = 0;
		virtual inline bool operator<=(number_a < > const & number ) const = 0;
		virtual inline any_a<> greater_or_equal__(range_a<> const& range) const = 0;
		virtual inline any_a<> greater_or_equal_(number_a<> const& number) const = 0;
		virtual inline bool operator>=(number_a < > const & number ) const = 0;
		virtual inline any_a<> byte_size__(range_a<> const& range) const = 0;
		virtual inline number_data_int64_a byte_size_() const = 0;
		virtual inline int64_t byte_size() const = 0;
		virtual inline any_a<> is_int__(range_a<> const& range) const = 0;
		virtual inline any_a<> is_int_() const = 0;
		virtual inline bool is_int() const = 0;
		virtual inline any_a<> is_signed__(range_a<> const& range) const = 0;
		virtual inline any_a<> is_signed_() const = 0;
		virtual inline bool is_signed() const = 0;
		virtual inline any_a<> is_nan__(range_a<> const& range) const = 0;
		virtual inline any_a<> is_nan_() const = 0;
		virtual inline bool is_nan() const = 0;
		virtual inline any_a<> is_inf__(range_a<> const& range) const = 0;
		virtual inline any_a<> is_inf_() const = 0;
		virtual inline bool is_inf() const = 0;
		virtual inline any_a<> is_finite__(range_a<> const& range) const = 0;
		virtual inline any_a<> is_finite_() const = 0;
		virtual inline bool is_finite() const = 0;
		virtual inline any_a<> is_normal__(range_a<> const& range) const = 0;
		virtual inline any_a<> is_normal_() const = 0;
		virtual inline bool is_normal() const = 0;
		virtual inline any_a<> little_endian__(range_a<> const& range) const = 0;
		virtual inline any_a<> little_endian_() const = 0;
		virtual inline bool little_endian() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___number_a_handle_base___>
	struct ___number_a_handle___ : ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___number_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___number_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline any_a<> increment__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.increment__(range); }

		virtual inline number_a<> increment_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.increment_(); }

		virtual inline any_a<> decrement__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.decrement__(range); }

		virtual inline number_a<> decrement_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.decrement_(); }

		virtual inline any_a<> self_assign__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_assign__(range); }

		virtual inline number_a<> self_assign_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_assign_(number); }

		virtual inline any_a<> self_add__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_add__(range); }

		virtual inline number_a<> self_add_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_add_(number); }

		virtual inline any_a<> add__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.add__(range); }

		virtual inline number_a<> add_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.add_(number); }

		virtual inline number_a < > operator+(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator+(number); }

		virtual inline any_a<> self_subtract__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_subtract__(range); }

		virtual inline number_a<> self_subtract_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_subtract_(number); }

		virtual inline any_a<> subtract__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.subtract__(range); }

		virtual inline number_a<> subtract_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.subtract_(number); }

		virtual inline number_a < > operator-(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator-(number); }

		virtual inline any_a<> self_multiply__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_multiply__(range); }

		virtual inline number_a<> self_multiply_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_multiply_(number); }

		virtual inline any_a<> multiply__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.multiply__(range); }

		virtual inline number_a<> multiply_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.multiply_(number); }

		virtual inline number_a < > operator*(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator*(number); }

		virtual inline any_a<> self_divide__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_divide__(range); }

		virtual inline number_a<> self_divide_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_divide_(number); }

		virtual inline any_a<> divide__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.divide__(range); }

		virtual inline number_a<> divide_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.divide_(number); }

		virtual inline number_a < > operator/(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator/(number); }

		virtual inline any_a<> self_modulo__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_modulo__(range); }

		virtual inline number_a<> self_modulo_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.self_modulo_(number); }

		virtual inline any_a<> modulo__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.modulo__(range); }

		virtual inline number_a<> modulo_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.modulo_(number); }

		virtual inline number_a < > operator%(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator%(number); }

		virtual inline any_a<> to_int_64__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.to_int_64__(range); }

		virtual inline number_data_int64_a to_int_64_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.to_int_64_(); }

		virtual inline int64_t to_int_64() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.to_int_64(); }

		virtual inline any_a<> from_int_64__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.from_int_64__(range); }

		virtual inline any_a<> from_int_64_(number_data_int64_a const& int_64) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.from_int_64_(int_64); }

		virtual inline void from_int_64(int64_t int_64 ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.from_int_64(int_64); }

		virtual inline any_a<> to_uint_64__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.to_uint_64__(range); }

		virtual inline number_data_uint64_a to_uint_64_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.to_uint_64_(); }

		virtual inline uint64_t to_uint_64() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.to_uint_64(); }

		virtual inline any_a<> from_uint_64__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.from_uint_64__(range); }

		virtual inline any_a<> from_uint_64_(number_data_uint64_a const& uint_64) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.from_uint_64_(uint_64); }

		virtual inline void from_uint_64(uint64_t uint_64 ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.from_uint_64(uint_64); }

		virtual inline any_a<> to_float_64__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.to_float_64__(range); }

		virtual inline number_data_double_a to_float_64_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.to_float_64_(); }

		virtual inline double to_float_64() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.to_float_64(); }

		virtual inline any_a<> from_float_64__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.from_float_64__(range); }

		virtual inline any_a<> from_float_64_(number_data_double_a const& int_64) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.from_float_64_(int_64); }

		virtual inline void from_float_64(double int_64 ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::value_.from_float_64(int_64); }

		virtual inline any_a<> less_than__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.less_than__(range); }

		virtual inline any_a<> less_than_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.less_than_(number); }

		virtual inline bool operator<(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator<(number); }

		virtual inline any_a<> greater_than__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.greater_than__(range); }

		virtual inline any_a<> greater_than_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.greater_than_(number); }

		virtual inline bool operator>(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator>(number); }

		virtual inline any_a<> less_or_equal__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.less_or_equal__(range); }

		virtual inline any_a<> less_or_equal_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.less_or_equal_(number); }

		virtual inline bool operator<=(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator<=(number); }

		virtual inline any_a<> greater_or_equal__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.greater_or_equal__(range); }

		virtual inline any_a<> greater_or_equal_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.greater_or_equal_(number); }

		virtual inline bool operator>=(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.operator>=(number); }

		virtual inline any_a<> byte_size__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.byte_size__(range); }

		virtual inline number_data_int64_a byte_size_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.byte_size_(); }

		virtual inline int64_t byte_size() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.byte_size(); }

		virtual inline any_a<> is_int__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_int__(range); }

		virtual inline any_a<> is_int_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_int_(); }

		virtual inline bool is_int() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_int(); }

		virtual inline any_a<> is_signed__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_signed__(range); }

		virtual inline any_a<> is_signed_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_signed_(); }

		virtual inline bool is_signed() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_signed(); }

		virtual inline any_a<> is_nan__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_nan__(range); }

		virtual inline any_a<> is_nan_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_nan_(); }

		virtual inline bool is_nan() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_nan(); }

		virtual inline any_a<> is_inf__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_inf__(range); }

		virtual inline any_a<> is_inf_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_inf_(); }

		virtual inline bool is_inf() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_inf(); }

		virtual inline any_a<> is_finite__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_finite__(range); }

		virtual inline any_a<> is_finite_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_finite_(); }

		virtual inline bool is_finite() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_finite(); }

		virtual inline any_a<> is_normal__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_normal__(range); }

		virtual inline any_a<> is_normal_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_normal_(); }

		virtual inline bool is_normal() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.is_normal(); }

		virtual inline any_a<> little_endian__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.little_endian__(range); }

		virtual inline any_a<> little_endian_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.little_endian_(); }

		virtual inline bool little_endian() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.little_endian(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___number_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___number_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___number_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___number_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___number_a_handle_final___ final : ___number_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___number_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___number_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___number_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___number_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___number_a_handle_final___>(___number_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___number_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___number_a_handle_final___<___TTT___&>
	{
		inline ___number_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___number_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline ___number_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___number_a_handle_base___ const>(handle_);
	}

	inline ___number_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___number_a_handle_base___>(handle_);
	}

	template <typename ___TTT___, typename number_data_int64_a_chk, typename number_data_uint64_a_chk, typename number_data_double_a_chk>
	friend inline bool check(number_a<number_data_int64_a_chk, number_data_uint64_a_chk, number_data_double_a_chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___number_a_handle_base___>(handle));
	}

	static inline number_a val(number_a const& other) noexcept
	{
		return number_a{ other };
	}

	static inline number_a ref(number_a& other) noexcept
	{
		return number_a(other, ___reference_tag___{});
	}

	static inline number_a dup(number_a& other) noexcept
	{
		return number_a(other, ___duplicate_tag___{});
	}

	inline number_a() = default;

	inline number_a(number_a& other, ___reference_tag___) noexcept
		: any_a(other, ___reference_tag___{})
	{}

	inline number_a(number_a& other, ___duplicate_tag___) noexcept
		: any_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline number_a(std::shared_ptr<___TTT___> const& handle)
		: any_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___number_a_handle_base___>(handle))
		{
			throw dis("number_a constructor failed to cast from base to number_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline number_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___number_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline number_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: any_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___number_a_handle_base___>(handle))
		{
			throw dis("number_a constructor failed to cast from base to number_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline number_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___number_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_a, std::decay_t<___TTT___>>::value>>
	explicit inline number_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___number_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline number_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___number_a_handle_base___>(handle))
		{
			throw dis("number_a assignment failed to cast from base to number_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline number_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___number_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_a, std::decay_t<___TTT___>>::value>>
	inline number_a& operator=(___TTT___ value) noexcept
	{
		number_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___number_a_share___;
}; // class number_a

template <typename ___TTT___, typename number_data_int64_a_chk, typename number_data_uint64_a_chk, typename number_data_double_a_chk>
inline bool check(number_a<number_data_int64_a_chk, number_data_uint64_a_chk, number_data_double_a_chk> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename number_data_int64_a, typename number_data_uint64_a, typename number_data_double_a>
bool const number_a<number_data_int64_a, number_data_uint64_a, number_data_double_a>::___share___ = []()
{
	auto& shoal = shared();
	reflection<number_a<number_data_int64_a, number_data_uint64_a, number_data_double_a>>::share(shoal);
	return shoal;
}();

} // namespace