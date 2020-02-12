
namespace strange
{

template <typename ___TTT___, typename _1_ = void>
inline bool check(ordered_herd_a<_1_> const& value) noexcept;

template <typename _1_>
class ordered_herd_a : public herd_a<>
{
public:
	// arithmetic operator overloads
	inline ordered_herd_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

	inline ordered_herd_a operator++(int)
	{
		assert(handle_);
		ordered_herd_a result = *this;
		write().operator++();
		return result;
	}

	inline ordered_herd_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

	inline ordered_herd_a operator--(int)
	{
		assert(handle_);
		ordered_herd_a result = *this;
		write().operator--();
		return result;
	}

	inline ordered_herd_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline ordered_herd_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline ordered_herd_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline ordered_herd_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline ordered_herd_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline std :: set < any_a < > > const & extract_set() const
	{ assert(handle_); return read().extract_set(); }

	inline std :: set < any_a < > > & mutate_set()
	{ assert(handle_); return write().mutate_set(); }

protected:
	struct ___ordered_herd_a_handle_base___ : ___herd_a_handle_base___
	{
		virtual inline std :: set < any_a < > > const & extract_set() const = 0;
		virtual inline std :: set < any_a < > > & mutate_set() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___ordered_herd_a_handle_base___>
	struct ___ordered_herd_a_handle___ : ___herd_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___ordered_herd_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___herd_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___ordered_herd_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___herd_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline std :: set < any_a < > > const & extract_set() const final
		{ return value_.extract_set(); }

		virtual inline std :: set < any_a < > > & mutate_set() final
		{ return value_.mutate_set(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___ordered_herd_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___ordered_herd_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___ordered_herd_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___ordered_herd_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___ordered_herd_a_handle_final___ final : ___ordered_herd_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___ordered_herd_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___ordered_herd_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___ordered_herd_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___ordered_herd_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___ordered_herd_a_handle_final___>(___ordered_herd_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___ordered_herd_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___ordered_herd_a_handle_final___<___TTT___&>
	{
		inline ___ordered_herd_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___ordered_herd_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline ___ordered_herd_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___ordered_herd_a_handle_base___ const>(handle_);
	}

	inline ___ordered_herd_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___ordered_herd_a_handle_base___>(handle_);
	}

	template <typename ___TTT___, typename _1_>
	friend inline bool check(ordered_herd_a<_1_> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___ordered_herd_a_handle_base___>(handle));
	}

	static inline ordered_herd_a val(ordered_herd_a const& other) noexcept
	{
		return ordered_herd_a{ other };
	}

	static inline ordered_herd_a ref(ordered_herd_a& other) noexcept
	{
		return ordered_herd_a(other, ___reference_tag___{});
	}

	static inline ordered_herd_a dup(ordered_herd_a& other) noexcept
	{
		return ordered_herd_a(other, ___duplicate_tag___{});
	}

	inline ordered_herd_a() = default;

	inline ordered_herd_a(ordered_herd_a& other, ___reference_tag___) noexcept
		: herd_a(other, ___reference_tag___{})
	{}

	inline ordered_herd_a(ordered_herd_a& other, ___duplicate_tag___) noexcept
		: herd_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline ordered_herd_a(std::shared_ptr<___TTT___> const& handle)
		: herd_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___ordered_herd_a_handle_base___>(handle))
		{
			throw dis("ordered_herd_a constructor failed to cast from base to ordered_herd_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline ordered_herd_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: herd_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___ordered_herd_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline ordered_herd_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: herd_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___ordered_herd_a_handle_base___>(handle))
		{
			throw dis("ordered_herd_a constructor failed to cast from base to ordered_herd_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline ordered_herd_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: herd_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___ordered_herd_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<ordered_herd_a, std::decay_t<___TTT___>>::value>>
	explicit inline ordered_herd_a(___TTT___ value) noexcept
		: herd_a{ std::make_shared<___ordered_herd_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline ordered_herd_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___ordered_herd_a_handle_base___>(handle))
		{
			throw dis("ordered_herd_a assignment failed to cast from base to ordered_herd_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline ordered_herd_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___ordered_herd_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<ordered_herd_a, std::decay_t<___TTT___>>::value>>
	inline ordered_herd_a& operator=(___TTT___ value) noexcept
	{
		ordered_herd_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___ordered_herd_a_share___;
}; // class ordered_herd_a

template <typename ___TTT___, typename _1_>
inline bool check(ordered_herd_a<_1_> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename _1_>
bool const ordered_herd_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<ordered_herd_a<_1_>>::share(shoal);
	return shoal.something();
}();

} // namespace
