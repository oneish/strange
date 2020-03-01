
namespace strange
{

template <typename number_data_int64_a = number_data_int64_a<> , typename number_data_uint64_a = number_data_uint64_a<> , typename number_data_double_a = number_data_double_a<> >
class number_d;

template <typename number_data_int64_a = number_data_int64_a<> , typename number_data_uint64_a = number_data_uint64_a<> , typename number_data_double_a = number_data_double_a<> >
inline number_d<number_data_int64_a, number_data_uint64_a, number_data_double_a> ___number_dynamic___(any_a<> const& thing); 

template <typename ___TTT___, typename number_data_int64_a_chk = number_data_int64_a<> , typename number_data_uint64_a_chk = number_data_uint64_a<> , typename number_data_double_a_chk = number_data_double_a<> >
inline bool check(number_a<number_data_int64_a_chk, number_data_uint64_a_chk, number_data_double_a_chk> const& value) noexcept;

template <typename number_data_int64_a, typename number_data_uint64_a, typename number_data_double_a>
class number_a : public any_a<>
{
public:
	// arithmetic operator overloads
	inline number_a& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline number_a operator++(int)
	{
		assert(___handle___);
		number_a result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline number_a& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline number_a operator--(int)
	{
		assert(___handle___);
		number_a result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline number_a& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline number_a& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline number_a& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline number_a& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline number_a& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> increment__(range_a<> const& range)
	{ assert(___handle___); return ___write___().increment__(range); }

	inline number_a<> increment_()
	{ assert(___handle___); return ___write___().increment_(); }

	inline any_a<> decrement__(range_a<> const& range)
	{ assert(___handle___); return ___write___().decrement__(range); }

	inline number_a<> decrement_()
	{ assert(___handle___); return ___write___().decrement_(); }

	inline any_a<> self_assign__(range_a<> const& range)
	{ assert(___handle___); return ___write___().self_assign__(range); }

	inline number_a<> self_assign_(number_a<> const& number)
	{ assert(___handle___); return ___write___().self_assign_(number); }

	inline any_a<> self_add__(range_a<> const& range)
	{ assert(___handle___); return ___write___().self_add__(range); }

	inline number_a<> self_add_(number_a<> const& number)
	{ assert(___handle___); return ___write___().self_add_(number); }

	inline any_a<> add__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().add__(range); }

	inline number_a<> add_(number_a<> const& number) const
	{ assert(___handle___); return ___read___().add_(number); }

	inline number_a < > operator+(number_a < > const & number ) const
	{ assert(___handle___); return ___read___().operator+(number); }

	inline any_a<> self_subtract__(range_a<> const& range)
	{ assert(___handle___); return ___write___().self_subtract__(range); }

	inline number_a<> self_subtract_(number_a<> const& number)
	{ assert(___handle___); return ___write___().self_subtract_(number); }

	inline any_a<> subtract__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().subtract__(range); }

	inline number_a<> subtract_(number_a<> const& number) const
	{ assert(___handle___); return ___read___().subtract_(number); }

	inline number_a < > operator-(number_a < > const & number ) const
	{ assert(___handle___); return ___read___().operator-(number); }

	inline any_a<> self_multiply__(range_a<> const& range)
	{ assert(___handle___); return ___write___().self_multiply__(range); }

	inline number_a<> self_multiply_(number_a<> const& number)
	{ assert(___handle___); return ___write___().self_multiply_(number); }

	inline any_a<> multiply__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().multiply__(range); }

	inline number_a<> multiply_(number_a<> const& number) const
	{ assert(___handle___); return ___read___().multiply_(number); }

	inline number_a < > operator*(number_a < > const & number ) const
	{ assert(___handle___); return ___read___().operator*(number); }

	inline any_a<> self_divide__(range_a<> const& range)
	{ assert(___handle___); return ___write___().self_divide__(range); }

	inline number_a<> self_divide_(number_a<> const& number)
	{ assert(___handle___); return ___write___().self_divide_(number); }

	inline any_a<> divide__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().divide__(range); }

	inline number_a<> divide_(number_a<> const& number) const
	{ assert(___handle___); return ___read___().divide_(number); }

	inline number_a < > operator/(number_a < > const & number ) const
	{ assert(___handle___); return ___read___().operator/(number); }

	inline any_a<> self_modulo__(range_a<> const& range)
	{ assert(___handle___); return ___write___().self_modulo__(range); }

	inline number_a<> self_modulo_(number_a<> const& number)
	{ assert(___handle___); return ___write___().self_modulo_(number); }

	inline any_a<> modulo__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().modulo__(range); }

	inline number_a<> modulo_(number_a<> const& number) const
	{ assert(___handle___); return ___read___().modulo_(number); }

	inline number_a < > operator%(number_a < > const & number ) const
	{ assert(___handle___); return ___read___().operator%(number); }

	inline any_a<> to_int_64__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().to_int_64__(range); }

	inline number_data_int64_a to_int_64_() const
	{ assert(___handle___); return ___read___().to_int_64_(); }

	inline int64_t to_int_64() const
	{ assert(___handle___); return ___read___().to_int_64(); }

	inline any_a<> from_int_64__(range_a<> const& range)
	{ assert(___handle___); return ___write___().from_int_64__(range); }

	inline any_a<> from_int_64_(number_data_int64_a const& int_64)
	{ assert(___handle___); return ___write___().from_int_64_(int_64); }

	inline void from_int_64(int64_t int_64 )
	{ assert(___handle___); ___write___().from_int_64(int_64); }

	inline any_a<> to_uint_64__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().to_uint_64__(range); }

	inline number_data_uint64_a to_uint_64_() const
	{ assert(___handle___); return ___read___().to_uint_64_(); }

	inline uint64_t to_uint_64() const
	{ assert(___handle___); return ___read___().to_uint_64(); }

	inline any_a<> from_uint_64__(range_a<> const& range)
	{ assert(___handle___); return ___write___().from_uint_64__(range); }

	inline any_a<> from_uint_64_(number_data_uint64_a const& uint_64)
	{ assert(___handle___); return ___write___().from_uint_64_(uint_64); }

	inline void from_uint_64(uint64_t uint_64 )
	{ assert(___handle___); ___write___().from_uint_64(uint_64); }

	inline any_a<> to_float_64__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().to_float_64__(range); }

	inline number_data_double_a to_float_64_() const
	{ assert(___handle___); return ___read___().to_float_64_(); }

	inline double to_float_64() const
	{ assert(___handle___); return ___read___().to_float_64(); }

	inline any_a<> from_float_64__(range_a<> const& range)
	{ assert(___handle___); return ___write___().from_float_64__(range); }

	inline any_a<> from_float_64_(number_data_double_a const& float_64)
	{ assert(___handle___); return ___write___().from_float_64_(float_64); }

	inline void from_float_64(double float_64 )
	{ assert(___handle___); ___write___().from_float_64(float_64); }

	inline any_a<> less_than__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().less_than__(range); }

	inline any_a<> less_than_(number_a<> const& number) const
	{ assert(___handle___); return ___read___().less_than_(number); }

	inline bool operator<(number_a < > const & number ) const
	{ assert(___handle___); return ___read___().operator<(number); }

	inline any_a<> greater_than__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().greater_than__(range); }

	inline any_a<> greater_than_(number_a<> const& number) const
	{ assert(___handle___); return ___read___().greater_than_(number); }

	inline bool operator>(number_a < > const & number ) const
	{ assert(___handle___); return ___read___().operator>(number); }

	inline any_a<> less_or_equal__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().less_or_equal__(range); }

	inline any_a<> less_or_equal_(number_a<> const& number) const
	{ assert(___handle___); return ___read___().less_or_equal_(number); }

	inline bool operator<=(number_a < > const & number ) const
	{ assert(___handle___); return ___read___().operator<=(number); }

	inline any_a<> greater_or_equal__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().greater_or_equal__(range); }

	inline any_a<> greater_or_equal_(number_a<> const& number) const
	{ assert(___handle___); return ___read___().greater_or_equal_(number); }

	inline bool operator>=(number_a < > const & number ) const
	{ assert(___handle___); return ___read___().operator>=(number); }

	inline any_a<> byte_size__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().byte_size__(range); }

	inline number_data_int64_a byte_size_() const
	{ assert(___handle___); return ___read___().byte_size_(); }

	inline int64_t byte_size() const
	{ assert(___handle___); return ___read___().byte_size(); }

	inline any_a<> is_int__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().is_int__(range); }

	inline any_a<> is_int_() const
	{ assert(___handle___); return ___read___().is_int_(); }

	inline bool is_int() const
	{ assert(___handle___); return ___read___().is_int(); }

	inline any_a<> is_signed__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().is_signed__(range); }

	inline any_a<> is_signed_() const
	{ assert(___handle___); return ___read___().is_signed_(); }

	inline bool is_signed() const
	{ assert(___handle___); return ___read___().is_signed(); }

	inline any_a<> is_nan__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().is_nan__(range); }

	inline any_a<> is_nan_() const
	{ assert(___handle___); return ___read___().is_nan_(); }

	inline bool is_nan() const
	{ assert(___handle___); return ___read___().is_nan(); }

	inline any_a<> is_inf__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().is_inf__(range); }

	inline any_a<> is_inf_() const
	{ assert(___handle___); return ___read___().is_inf_(); }

	inline bool is_inf() const
	{ assert(___handle___); return ___read___().is_inf(); }

	inline any_a<> is_finite__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().is_finite__(range); }

	inline any_a<> is_finite_() const
	{ assert(___handle___); return ___read___().is_finite_(); }

	inline bool is_finite() const
	{ assert(___handle___); return ___read___().is_finite(); }

	inline any_a<> is_normal__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().is_normal__(range); }

	inline any_a<> is_normal_() const
	{ assert(___handle___); return ___read___().is_normal_(); }

	inline bool is_normal() const
	{ assert(___handle___); return ___read___().is_normal(); }

	inline any_a<> little_endian__(range_a<> const& range) const
	{ assert(___handle___); return ___read___().little_endian__(range); }

	inline any_a<> little_endian_() const
	{ assert(___handle___); return ___read___().little_endian_(); }

	inline bool little_endian() const
	{ assert(___handle___); return ___read___().little_endian(); }

protected:
	struct ___number_a_handle_base___ : ___any_a_handle_base___
	{
		virtual any_a<> increment__(range_a<> const& range) = 0;
		virtual number_a<> increment_() = 0;
		virtual any_a<> decrement__(range_a<> const& range) = 0;
		virtual number_a<> decrement_() = 0;
		virtual any_a<> self_assign__(range_a<> const& range) = 0;
		virtual number_a<> self_assign_(number_a<> const& number) = 0;
		virtual any_a<> self_add__(range_a<> const& range) = 0;
		virtual number_a<> self_add_(number_a<> const& number) = 0;
		virtual any_a<> add__(range_a<> const& range) const = 0;
		virtual number_a<> add_(number_a<> const& number) const = 0;
		virtual number_a < > operator+(number_a < > const & number ) const = 0;
		virtual any_a<> self_subtract__(range_a<> const& range) = 0;
		virtual number_a<> self_subtract_(number_a<> const& number) = 0;
		virtual any_a<> subtract__(range_a<> const& range) const = 0;
		virtual number_a<> subtract_(number_a<> const& number) const = 0;
		virtual number_a < > operator-(number_a < > const & number ) const = 0;
		virtual any_a<> self_multiply__(range_a<> const& range) = 0;
		virtual number_a<> self_multiply_(number_a<> const& number) = 0;
		virtual any_a<> multiply__(range_a<> const& range) const = 0;
		virtual number_a<> multiply_(number_a<> const& number) const = 0;
		virtual number_a < > operator*(number_a < > const & number ) const = 0;
		virtual any_a<> self_divide__(range_a<> const& range) = 0;
		virtual number_a<> self_divide_(number_a<> const& number) = 0;
		virtual any_a<> divide__(range_a<> const& range) const = 0;
		virtual number_a<> divide_(number_a<> const& number) const = 0;
		virtual number_a < > operator/(number_a < > const & number ) const = 0;
		virtual any_a<> self_modulo__(range_a<> const& range) = 0;
		virtual number_a<> self_modulo_(number_a<> const& number) = 0;
		virtual any_a<> modulo__(range_a<> const& range) const = 0;
		virtual number_a<> modulo_(number_a<> const& number) const = 0;
		virtual number_a < > operator%(number_a < > const & number ) const = 0;
		virtual any_a<> to_int_64__(range_a<> const& range) const = 0;
		virtual number_data_int64_a to_int_64_() const = 0;
		virtual int64_t to_int_64() const = 0;
		virtual any_a<> from_int_64__(range_a<> const& range) = 0;
		virtual any_a<> from_int_64_(number_data_int64_a const& int_64) = 0;
		virtual void from_int_64(int64_t int_64 ) = 0;
		virtual any_a<> to_uint_64__(range_a<> const& range) const = 0;
		virtual number_data_uint64_a to_uint_64_() const = 0;
		virtual uint64_t to_uint_64() const = 0;
		virtual any_a<> from_uint_64__(range_a<> const& range) = 0;
		virtual any_a<> from_uint_64_(number_data_uint64_a const& uint_64) = 0;
		virtual void from_uint_64(uint64_t uint_64 ) = 0;
		virtual any_a<> to_float_64__(range_a<> const& range) const = 0;
		virtual number_data_double_a to_float_64_() const = 0;
		virtual double to_float_64() const = 0;
		virtual any_a<> from_float_64__(range_a<> const& range) = 0;
		virtual any_a<> from_float_64_(number_data_double_a const& float_64) = 0;
		virtual void from_float_64(double float_64 ) = 0;
		virtual any_a<> less_than__(range_a<> const& range) const = 0;
		virtual any_a<> less_than_(number_a<> const& number) const = 0;
		virtual bool operator<(number_a < > const & number ) const = 0;
		virtual any_a<> greater_than__(range_a<> const& range) const = 0;
		virtual any_a<> greater_than_(number_a<> const& number) const = 0;
		virtual bool operator>(number_a < > const & number ) const = 0;
		virtual any_a<> less_or_equal__(range_a<> const& range) const = 0;
		virtual any_a<> less_or_equal_(number_a<> const& number) const = 0;
		virtual bool operator<=(number_a < > const & number ) const = 0;
		virtual any_a<> greater_or_equal__(range_a<> const& range) const = 0;
		virtual any_a<> greater_or_equal_(number_a<> const& number) const = 0;
		virtual bool operator>=(number_a < > const & number ) const = 0;
		virtual any_a<> byte_size__(range_a<> const& range) const = 0;
		virtual number_data_int64_a byte_size_() const = 0;
		virtual int64_t byte_size() const = 0;
		virtual any_a<> is_int__(range_a<> const& range) const = 0;
		virtual any_a<> is_int_() const = 0;
		virtual bool is_int() const = 0;
		virtual any_a<> is_signed__(range_a<> const& range) const = 0;
		virtual any_a<> is_signed_() const = 0;
		virtual bool is_signed() const = 0;
		virtual any_a<> is_nan__(range_a<> const& range) const = 0;
		virtual any_a<> is_nan_() const = 0;
		virtual bool is_nan() const = 0;
		virtual any_a<> is_inf__(range_a<> const& range) const = 0;
		virtual any_a<> is_inf_() const = 0;
		virtual bool is_inf() const = 0;
		virtual any_a<> is_finite__(range_a<> const& range) const = 0;
		virtual any_a<> is_finite_() const = 0;
		virtual bool is_finite() const = 0;
		virtual any_a<> is_normal__(range_a<> const& range) const = 0;
		virtual any_a<> is_normal_() const = 0;
		virtual bool is_normal() const = 0;
		virtual any_a<> little_endian__(range_a<> const& range) const = 0;
		virtual any_a<> little_endian_() const = 0;
		virtual bool little_endian() const = 0;
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
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.increment__(range); }

		virtual inline number_a<> increment_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.increment_(); }

		virtual inline any_a<> decrement__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.decrement__(range); }

		virtual inline number_a<> decrement_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.decrement_(); }

		virtual inline any_a<> self_assign__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_assign__(range); }

		virtual inline number_a<> self_assign_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_assign_(number); }

		virtual inline any_a<> self_add__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_add__(range); }

		virtual inline number_a<> self_add_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_add_(number); }

		virtual inline any_a<> add__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.add__(range); }

		virtual inline number_a<> add_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.add_(number); }

		virtual inline number_a < > operator+(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator+(number); }

		virtual inline any_a<> self_subtract__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_subtract__(range); }

		virtual inline number_a<> self_subtract_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_subtract_(number); }

		virtual inline any_a<> subtract__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.subtract__(range); }

		virtual inline number_a<> subtract_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.subtract_(number); }

		virtual inline number_a < > operator-(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator-(number); }

		virtual inline any_a<> self_multiply__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_multiply__(range); }

		virtual inline number_a<> self_multiply_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_multiply_(number); }

		virtual inline any_a<> multiply__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.multiply__(range); }

		virtual inline number_a<> multiply_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.multiply_(number); }

		virtual inline number_a < > operator*(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator*(number); }

		virtual inline any_a<> self_divide__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_divide__(range); }

		virtual inline number_a<> self_divide_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_divide_(number); }

		virtual inline any_a<> divide__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.divide__(range); }

		virtual inline number_a<> divide_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.divide_(number); }

		virtual inline number_a < > operator/(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator/(number); }

		virtual inline any_a<> self_modulo__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_modulo__(range); }

		virtual inline number_a<> self_modulo_(number_a<> const& number) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_modulo_(number); }

		virtual inline any_a<> modulo__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.modulo__(range); }

		virtual inline number_a<> modulo_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.modulo_(number); }

		virtual inline number_a < > operator%(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator%(number); }

		virtual inline any_a<> to_int_64__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_int_64__(range); }

		virtual inline number_data_int64_a to_int_64_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_int_64_(); }

		virtual inline int64_t to_int_64() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_int_64(); }

		virtual inline any_a<> from_int_64__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.from_int_64__(range); }

		virtual inline any_a<> from_int_64_(number_data_int64_a const& int_64) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.from_int_64_(int_64); }

		virtual inline void from_int_64(int64_t int_64 ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.from_int_64(int_64); }

		virtual inline any_a<> to_uint_64__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_uint_64__(range); }

		virtual inline number_data_uint64_a to_uint_64_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_uint_64_(); }

		virtual inline uint64_t to_uint_64() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_uint_64(); }

		virtual inline any_a<> from_uint_64__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.from_uint_64__(range); }

		virtual inline any_a<> from_uint_64_(number_data_uint64_a const& uint_64) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.from_uint_64_(uint_64); }

		virtual inline void from_uint_64(uint64_t uint_64 ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.from_uint_64(uint_64); }

		virtual inline any_a<> to_float_64__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_float_64__(range); }

		virtual inline number_data_double_a to_float_64_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_float_64_(); }

		virtual inline double to_float_64() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.to_float_64(); }

		virtual inline any_a<> from_float_64__(range_a<> const& range) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.from_float_64__(range); }

		virtual inline any_a<> from_float_64_(number_data_double_a const& float_64) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.from_float_64_(float_64); }

		virtual inline void from_float_64(double float_64 ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.from_float_64(float_64); }

		virtual inline any_a<> less_than__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.less_than__(range); }

		virtual inline any_a<> less_than_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.less_than_(number); }

		virtual inline bool operator<(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(number); }

		virtual inline any_a<> greater_than__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.greater_than__(range); }

		virtual inline any_a<> greater_than_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.greater_than_(number); }

		virtual inline bool operator>(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(number); }

		virtual inline any_a<> less_or_equal__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.less_or_equal__(range); }

		virtual inline any_a<> less_or_equal_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.less_or_equal_(number); }

		virtual inline bool operator<=(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(number); }

		virtual inline any_a<> greater_or_equal__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.greater_or_equal__(range); }

		virtual inline any_a<> greater_or_equal_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.greater_or_equal_(number); }

		virtual inline bool operator>=(number_a < > const & number ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(number); }

		virtual inline any_a<> byte_size__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.byte_size__(range); }

		virtual inline number_data_int64_a byte_size_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.byte_size_(); }

		virtual inline int64_t byte_size() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.byte_size(); }

		virtual inline any_a<> is_int__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_int__(range); }

		virtual inline any_a<> is_int_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_int_(); }

		virtual inline bool is_int() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_int(); }

		virtual inline any_a<> is_signed__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_signed__(range); }

		virtual inline any_a<> is_signed_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_signed_(); }

		virtual inline bool is_signed() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_signed(); }

		virtual inline any_a<> is_nan__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_nan__(range); }

		virtual inline any_a<> is_nan_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_nan_(); }

		virtual inline bool is_nan() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_nan(); }

		virtual inline any_a<> is_inf__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_inf__(range); }

		virtual inline any_a<> is_inf_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_inf_(); }

		virtual inline bool is_inf() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_inf(); }

		virtual inline any_a<> is_finite__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_finite__(range); }

		virtual inline any_a<> is_finite_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_finite_(); }

		virtual inline bool is_finite() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_finite(); }

		virtual inline any_a<> is_normal__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_normal__(range); }

		virtual inline any_a<> is_normal_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_normal_(); }

		virtual inline bool is_normal() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.is_normal(); }

		virtual inline any_a<> little_endian__(range_a<> const& range) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.little_endian__(range); }

		virtual inline any_a<> little_endian_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.little_endian_(); }

		virtual inline bool little_endian() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.little_endian(); }

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
			return std::make_shared<___number_a_handle_final___>(___number_a_handle___<___TTT___>::___value___);
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

protected:
	inline ___number_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___number_a_handle_base___ const>(___handle___);
	}

	inline ___number_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___number_a_handle_base___>(___handle___);
	}

private:
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

	explicit inline number_a(std::shared_ptr<___number_a_handle_base___> const& handle) noexcept
		: any_a{ handle }
	{}

	explicit inline number_a(std::shared_ptr<___number_a_handle_base___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline number_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___number_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline number_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: any_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___number_a_handle_base___>(handle));
	}
/*
#endif

*/
	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_a, std::decay_t<___TTT___>>::value>>
	explicit inline number_a(___TTT___ value) noexcept
		: any_a{ std::make_shared<___number_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline number_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___number_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<number_a, std::decay_t<___TTT___>>::value>>
	inline number_a& operator=(___TTT___ value) noexcept
	{
		number_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline number_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___number_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return number_a{ ptr };
		}
		return number_a{ number_d<number_data_int64_a, number_data_uint64_a, number_data_double_a>{ thing } };
	}

	static inline number_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___number_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return number_a(ptr, ___reference_tag___{});
		}
		return number_a{ number_d<number_data_int64_a, number_data_uint64_a, number_data_double_a>{ thing, ___reference_tag___{} } };
	}

private:
	static bool const ___share___;
	friend class ___number_a_share___;
}; // class number_a

template <typename ___TTT___, typename number_data_int64_a_chk, typename number_data_uint64_a_chk, typename number_data_double_a_chk>
inline bool check(number_a<number_data_int64_a_chk, number_data_uint64_a_chk, number_data_double_a_chk> const& value) noexcept
{
	return ___TTT___::___check___(value.___handle___);
}

template <typename number_data_int64_a, typename number_data_uint64_a, typename number_data_double_a>
bool const number_a<number_data_int64_a, number_data_uint64_a, number_data_double_a>::___share___ = []()
{
	auto& shoal = shared();
	reflection<number_a<number_data_int64_a, number_data_uint64_a, number_data_double_a>>::share(shoal);
	return shoal;
}();

template <typename number_data_int64_a, typename number_data_uint64_a, typename number_data_double_a>
class number_d : public any_a<>
{
public:
	// arithmetic operator overloads
	inline number_d& operator++()
	{
		assert(___handle___);
		___write___().operator++();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline number_d operator++(int)
	{
		assert(___handle___);
		number_d result = *this;
		___write___().operator++();
		return result;
	}
#endif

	inline number_d& operator--()
	{
		assert(___handle___);
		___write___().operator--();
		return *this;
	}

#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS
	inline number_d operator--(int)
	{
		assert(___handle___);
		number_d result = *this;
		___write___().operator--();
		return result;
	}
#endif

	inline number_d& operator+=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator+=(other);
		return *this;
	}

	inline number_d& operator-=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator-=(other);
		return *this;
	}

	inline number_d& operator*=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator*=(other);
		return *this;
	}

	inline number_d& operator/=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator/=(other);
		return *this;
	}

	inline number_d& operator%=(any_a<> const& other)
	{
		assert(___handle___);
		___write___().operator%=(other);
		return *this;
	}

	inline any_a<> increment__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("increment_");
		if (!op)
		{
			throw dis("dynamic number_d::increment_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline number_a<> increment_()
	{
		assert(___handle___);
		auto const op = operation("increment_");
		if (!op)
		{
			throw dis("dynamic number_d::increment_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this));
	}

	inline any_a<> decrement__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("decrement_");
		if (!op)
		{
			throw dis("dynamic number_d::decrement_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline number_a<> decrement_()
	{
		assert(___handle___);
		auto const op = operation("decrement_");
		if (!op)
		{
			throw dis("dynamic number_d::decrement_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this));
	}

	inline any_a<> self_assign__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_assign_");
		if (!op)
		{
			throw dis("dynamic number_d::self_assign_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline number_a<> self_assign_(number_a<> const& number)
	{
		assert(___handle___);
		auto const op = operation("self_assign_");
		if (!op)
		{
			throw dis("dynamic number_d::self_assign_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> self_add__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_add_");
		if (!op)
		{
			throw dis("dynamic number_d::self_add_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline number_a<> self_add_(number_a<> const& number)
	{
		assert(___handle___);
		auto const op = operation("self_add_");
		if (!op)
		{
			throw dis("dynamic number_d::self_add_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> add__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic number_d::add_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline number_a<> add_(number_a<> const& number) const
	{
		assert(___handle___);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic number_d::add_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline number_a < > operator+(number_a < > const & number ) const
	{ return add_(number); }

	inline any_a<> self_subtract__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic number_d::self_subtract_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline number_a<> self_subtract_(number_a<> const& number)
	{
		assert(___handle___);
		auto const op = operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic number_d::self_subtract_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> subtract__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("subtract_");
		if (!op)
		{
			throw dis("dynamic number_d::subtract_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline number_a<> subtract_(number_a<> const& number) const
	{
		assert(___handle___);
		auto const op = operation("subtract_");
		if (!op)
		{
			throw dis("dynamic number_d::subtract_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline number_a < > operator-(number_a < > const & number ) const
	{ return subtract_(number); }

	inline any_a<> self_multiply__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_multiply_");
		if (!op)
		{
			throw dis("dynamic number_d::self_multiply_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline number_a<> self_multiply_(number_a<> const& number)
	{
		assert(___handle___);
		auto const op = operation("self_multiply_");
		if (!op)
		{
			throw dis("dynamic number_d::self_multiply_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> multiply__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("multiply_");
		if (!op)
		{
			throw dis("dynamic number_d::multiply_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline number_a<> multiply_(number_a<> const& number) const
	{
		assert(___handle___);
		auto const op = operation("multiply_");
		if (!op)
		{
			throw dis("dynamic number_d::multiply_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline number_a < > operator*(number_a < > const & number ) const
	{ return multiply_(number); }

	inline any_a<> self_divide__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_divide_");
		if (!op)
		{
			throw dis("dynamic number_d::self_divide_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline number_a<> self_divide_(number_a<> const& number)
	{
		assert(___handle___);
		auto const op = operation("self_divide_");
		if (!op)
		{
			throw dis("dynamic number_d::self_divide_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> divide__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("divide_");
		if (!op)
		{
			throw dis("dynamic number_d::divide_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline number_a<> divide_(number_a<> const& number) const
	{
		assert(___handle___);
		auto const op = operation("divide_");
		if (!op)
		{
			throw dis("dynamic number_d::divide_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline number_a < > operator/(number_a < > const & number ) const
	{ return divide_(number); }

	inline any_a<> self_modulo__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("self_modulo_");
		if (!op)
		{
			throw dis("dynamic number_d::self_modulo_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline number_a<> self_modulo_(number_a<> const& number)
	{
		assert(___handle___);
		auto const op = operation("self_modulo_");
		if (!op)
		{
			throw dis("dynamic number_d::self_modulo_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> modulo__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("modulo_");
		if (!op)
		{
			throw dis("dynamic number_d::modulo_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline number_a<> modulo_(number_a<> const& number) const
	{
		assert(___handle___);
		auto const op = operation("modulo_");
		if (!op)
		{
			throw dis("dynamic number_d::modulo_ passed non-existent member");
		}
		return cast<number_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline number_a < > operator%(number_a < > const & number ) const
	{ return modulo_(number); }

	inline any_a<> to_int_64__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("to_int_64_");
		if (!op)
		{
			throw dis("dynamic number_d::to_int_64_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline number_data_int64_a to_int_64_() const
	{
		assert(___handle___);
		auto const op = operation("to_int_64_");
		if (!op)
		{
			throw dis("dynamic number_d::to_int_64_ passed non-existent member");
		}
		return cast<number_data_int64_a>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline int64_t to_int_64() const
	{ return to_int_64_().extract_primitive(); }

	inline any_a<> from_int_64__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("from_int_64_");
		if (!op)
		{
			throw dis("dynamic number_d::from_int_64_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> from_int_64_(number_data_int64_a const& int_64)
	{
		assert(___handle___);
		auto const op = operation("from_int_64_");
		if (!op)
		{
			throw dis("dynamic number_d::from_int_64_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, int_64));
	}

	inline void from_int_64(int64_t int_64 )
	{ from_int_64_(num<int64_t, number_data_int64_a>(int_64)); }

	inline any_a<> to_uint_64__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("to_uint_64_");
		if (!op)
		{
			throw dis("dynamic number_d::to_uint_64_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline number_data_uint64_a to_uint_64_() const
	{
		assert(___handle___);
		auto const op = operation("to_uint_64_");
		if (!op)
		{
			throw dis("dynamic number_d::to_uint_64_ passed non-existent member");
		}
		return cast<number_data_uint64_a>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline uint64_t to_uint_64() const
	{ return to_uint_64_().extract_primitive(); }

	inline any_a<> from_uint_64__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("from_uint_64_");
		if (!op)
		{
			throw dis("dynamic number_d::from_uint_64_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> from_uint_64_(number_data_uint64_a const& uint_64)
	{
		assert(___handle___);
		auto const op = operation("from_uint_64_");
		if (!op)
		{
			throw dis("dynamic number_d::from_uint_64_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, uint_64));
	}

	inline void from_uint_64(uint64_t uint_64 )
	{ from_uint_64_(num<uint64_t, number_data_uint64_a>(uint_64)); }

	inline any_a<> to_float_64__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("to_float_64_");
		if (!op)
		{
			throw dis("dynamic number_d::to_float_64_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline number_data_double_a to_float_64_() const
	{
		assert(___handle___);
		auto const op = operation("to_float_64_");
		if (!op)
		{
			throw dis("dynamic number_d::to_float_64_ passed non-existent member");
		}
		return cast<number_data_double_a>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline double to_float_64() const
	{ return to_float_64_().extract_primitive(); }

	inline any_a<> from_float_64__(range_a<> const& range)
	{
		assert(___handle___);
		auto const op = operation("from_float_64_");
		if (!op)
		{
			throw dis("dynamic number_d::from_float_64_ passed non-existent member");
		}
		return op.operate(*this, range);
	}

	inline any_a<> from_float_64_(number_data_double_a const& float_64)
	{
		assert(___handle___);
		auto const op = operation("from_float_64_");
		if (!op)
		{
			throw dis("dynamic number_d::from_float_64_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *this, float_64));
	}

	inline void from_float_64(double float_64 )
	{ from_float_64_(num<double, number_data_double_a>(float_64)); }

	inline any_a<> less_than__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("less_than_");
		if (!op)
		{
			throw dis("dynamic number_d::less_than_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline any_a<> less_than_(number_a<> const& number) const
	{
		assert(___handle___);
		auto const op = operation("less_than_");
		if (!op)
		{
			throw dis("dynamic number_d::less_than_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline bool operator<(number_a < > const & number ) const
	{ return less_than_(number); }

	inline any_a<> greater_than__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("greater_than_");
		if (!op)
		{
			throw dis("dynamic number_d::greater_than_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline any_a<> greater_than_(number_a<> const& number) const
	{
		assert(___handle___);
		auto const op = operation("greater_than_");
		if (!op)
		{
			throw dis("dynamic number_d::greater_than_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline bool operator>(number_a < > const & number ) const
	{ return greater_than_(number); }

	inline any_a<> less_or_equal__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("less_or_equal_");
		if (!op)
		{
			throw dis("dynamic number_d::less_or_equal_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline any_a<> less_or_equal_(number_a<> const& number) const
	{
		assert(___handle___);
		auto const op = operation("less_or_equal_");
		if (!op)
		{
			throw dis("dynamic number_d::less_or_equal_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline bool operator<=(number_a < > const & number ) const
	{ return less_or_equal_(number); }

	inline any_a<> greater_or_equal__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("greater_or_equal_");
		if (!op)
		{
			throw dis("dynamic number_d::greater_or_equal_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline any_a<> greater_or_equal_(number_a<> const& number) const
	{
		assert(___handle___);
		auto const op = operation("greater_or_equal_");
		if (!op)
		{
			throw dis("dynamic number_d::greater_or_equal_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this), number));
	}

	inline bool operator>=(number_a < > const & number ) const
	{ return greater_or_equal_(number); }

	inline any_a<> byte_size__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("byte_size_");
		if (!op)
		{
			throw dis("dynamic number_d::byte_size_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline number_data_int64_a byte_size_() const
	{
		assert(___handle___);
		auto const op = operation("byte_size_");
		if (!op)
		{
			throw dis("dynamic number_d::byte_size_ passed non-existent member");
		}
		return cast<number_data_int64_a>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline int64_t byte_size() const
	{ return byte_size_().extract_primitive(); }

	inline any_a<> is_int__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("is_int_");
		if (!op)
		{
			throw dis("dynamic number_d::is_int_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline any_a<> is_int_() const
	{
		assert(___handle___);
		auto const op = operation("is_int_");
		if (!op)
		{
			throw dis("dynamic number_d::is_int_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool is_int() const
	{ return is_int_(); }

	inline any_a<> is_signed__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("is_signed_");
		if (!op)
		{
			throw dis("dynamic number_d::is_signed_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline any_a<> is_signed_() const
	{
		assert(___handle___);
		auto const op = operation("is_signed_");
		if (!op)
		{
			throw dis("dynamic number_d::is_signed_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool is_signed() const
	{ return is_signed_(); }

	inline any_a<> is_nan__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("is_nan_");
		if (!op)
		{
			throw dis("dynamic number_d::is_nan_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline any_a<> is_nan_() const
	{
		assert(___handle___);
		auto const op = operation("is_nan_");
		if (!op)
		{
			throw dis("dynamic number_d::is_nan_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool is_nan() const
	{ return is_nan_(); }

	inline any_a<> is_inf__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("is_inf_");
		if (!op)
		{
			throw dis("dynamic number_d::is_inf_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline any_a<> is_inf_() const
	{
		assert(___handle___);
		auto const op = operation("is_inf_");
		if (!op)
		{
			throw dis("dynamic number_d::is_inf_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool is_inf() const
	{ return is_inf_(); }

	inline any_a<> is_finite__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("is_finite_");
		if (!op)
		{
			throw dis("dynamic number_d::is_finite_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline any_a<> is_finite_() const
	{
		assert(___handle___);
		auto const op = operation("is_finite_");
		if (!op)
		{
			throw dis("dynamic number_d::is_finite_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool is_finite() const
	{ return is_finite_(); }

	inline any_a<> is_normal__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("is_normal_");
		if (!op)
		{
			throw dis("dynamic number_d::is_normal_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline any_a<> is_normal_() const
	{
		assert(___handle___);
		auto const op = operation("is_normal_");
		if (!op)
		{
			throw dis("dynamic number_d::is_normal_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool is_normal() const
	{ return is_normal_(); }

	inline any_a<> little_endian__(range_a<> const& range) const
	{
		assert(___handle___);
		auto const op = operation("little_endian_");
		if (!op)
		{
			throw dis("dynamic number_d::little_endian_ passed non-existent member");
		}
		return op.operate(*const_cast<number_d*>(this), range);
	}

	inline any_a<> little_endian_() const
	{
		assert(___handle___);
		auto const op = operation("little_endian_");
		if (!op)
		{
			throw dis("dynamic number_d::little_endian_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<number_d*>(this)));
	}

	inline bool little_endian() const
	{ return little_endian_(); }

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit number_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit number_d(any_a<>& thing, ___reference_tag___)
		: any_a<>{ thing, ___reference_tag___{} }
	{}

	explicit number_d(any_a<>& thing, ___duplicate_tag___)
		: any_a<>{ thing, ___duplicate_tag___{} }
	{}
};

template <typename number_data_int64_a, typename number_data_uint64_a, typename number_data_double_a>
inline number_d<number_data_int64_a, number_data_uint64_a, number_data_double_a> ___number_dynamic___(any_a<> const& thing)
{
	return number_d<number_data_int64_a, number_data_uint64_a, number_data_double_a>{ thing };
}

} // namespace
