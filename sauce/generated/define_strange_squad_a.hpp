
namespace strange
{

template <typename ___TTT___, typename _1__chk = void>
inline bool check(squad_a<_1__chk> const& value) noexcept;

template <typename _1_>
class squad_a : public inventory_a<>
{
public:
	// arithmetic operator overloads
	inline squad_a& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

	inline squad_a operator++(int)
	{
		assert(handle_);
		squad_a result = *this;
		write().operator++();
		return result;
	}

	inline squad_a& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

	inline squad_a operator--(int)
	{
		assert(handle_);
		squad_a result = *this;
		write().operator--();
		return result;
	}

	inline squad_a& operator+=(any_a<> const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline squad_a& operator-=(any_a<> const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline squad_a& operator*=(any_a<> const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline squad_a& operator/=(any_a<> const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline squad_a& operator%=(any_a<> const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	inline std :: deque < any_a < > > const & extract_deque() const
	{ assert(handle_); return read().extract_deque(); }

	inline std :: deque < any_a < > > & mutate_deque()
	{ assert(handle_); return write().mutate_deque(); }

protected:
	struct ___squad_a_handle_base___ : ___inventory_a_handle_base___
	{
		virtual inline std :: deque < any_a < > > const & extract_deque() const = 0;
		virtual inline std :: deque < any_a < > > & mutate_deque() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___squad_a_handle_base___>
	struct ___squad_a_handle___ : ___inventory_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___squad_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___inventory_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___squad_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___inventory_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		virtual inline std :: deque < any_a < > > const & extract_deque() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.extract_deque(); }

		virtual inline std :: deque < any_a < > > & mutate_deque() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::value_.mutate_deque(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___squad_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___squad_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___squad_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___squad_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___squad_a_handle_final___ final : ___squad_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___squad_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___squad_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___squad_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___squad_a_handle___<___TTT___>{ std::move(value) }
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___squad_a_handle_final___>(___squad_a_handle___<___TTT___>::value_);
		}
	};

	template <typename ___TTT___>
	struct ___squad_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___squad_a_handle_final___<___TTT___&>
	{
		inline ___squad_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___squad_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

	inline ___squad_a_handle_base___ const& read() const noexcept
	{
		return *std::static_pointer_cast<___squad_a_handle_base___ const>(handle_);
	}

	inline ___squad_a_handle_base___& write() noexcept
	{
		if (!handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___squad_a_handle_base___>(handle_);
	}

	template <typename ___TTT___, typename _1__chk>
	friend inline bool check(squad_a<_1__chk> const& value) noexcept;

public:
	static inline bool ___check___(___SHARED___ const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___squad_a_handle_base___>(handle));
	}

	static inline squad_a val(squad_a const& other) noexcept
	{
		return squad_a{ other };
	}

	static inline squad_a ref(squad_a& other) noexcept
	{
		return squad_a(other, ___reference_tag___{});
	}

	static inline squad_a dup(squad_a& other) noexcept
	{
		return squad_a(other, ___duplicate_tag___{});
	}

	inline squad_a() = default;

	inline squad_a(squad_a& other, ___reference_tag___) noexcept
		: inventory_a(other, ___reference_tag___{})
	{}

	inline squad_a(squad_a& other, ___duplicate_tag___) noexcept
		: inventory_a(other, ___duplicate_tag___{})
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline squad_a(std::shared_ptr<___TTT___> const& handle)
		: inventory_a{ handle }
	{
		if (handle && !std::dynamic_pointer_cast<___squad_a_handle_base___>(handle))
		{
			throw dis("squad_a constructor failed to cast from base to squad_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline squad_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: inventory_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___squad_a_handle_base___>(handle));
	}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline squad_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___)
		: inventory_a(handle, ___reference_tag___{})
	{
		if (handle && !std::dynamic_pointer_cast<___squad_a_handle_base___>(handle))
		{
			throw dis("squad_a constructor failed to cast from base to squad_a");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline squad_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: inventory_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___squad_a_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<squad_a, std::decay_t<___TTT___>>::value>>
	explicit inline squad_a(___TTT___ value) noexcept
		: inventory_a{ std::make_shared<___squad_a_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)) }
	{
		handle_->___weak___(handle_);
	}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline squad_a& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (handle && !std::dynamic_pointer_cast<___squad_a_handle_base___>(handle))
		{
			throw dis("squad_a assignment failed to cast from base to squad_a");
		}
		handle_ = handle;
		return *this;
	}
#else
	template <typename ___TTT___>
	inline squad_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___squad_a_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<squad_a, std::decay_t<___TTT___>>::value>>
	inline squad_a& operator=(___TTT___ value) noexcept
	{
		squad_a temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}

private:
	static bool const ___share___;
	friend class ___squad_a_share___;
}; // class squad_a

template <typename ___TTT___, typename _1__chk>
inline bool check(squad_a<_1__chk> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

template <typename _1_>
bool const squad_a<_1_>::___share___ = []()
{
	auto& shoal = shared();
	reflection<squad_a<_1_>>::share(shoal);
	return shoal;
}();

} // namespace