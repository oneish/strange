%struct_prefix% final : public ___derived___
{
public:
	inline %struct_name%& operator++()
	{
		assert(handle_);
		write().operator++();
		return *this;
	}

	inline %struct_name% operator++(int)
	{
		assert(handle_);
		% struct_name% result = *this;
		write().operator++();
		return result;
	}

	inline %struct_name%& operator--()
	{
		assert(handle_);
		write().operator--();
		return *this;
	}

	inline %struct_name% operator--(int)
	{
		assert(handle_);
		% struct_name% result = *this;
		write().operator--();
		return result;
	}

	inline %struct_name%& operator+=(___root___ const& other)
	{
		assert(handle_);
		write().operator+=(other);
		return *this;
	}

	inline %struct_name%& operator-=(___root___ const& other)
	{
		assert(handle_);
		write().operator-=(other);
		return *this;
	}

	inline %struct_name%& operator*=(___root___ const& other)
	{
		assert(handle_);
		write().operator*=(other);
		return *this;
	}

	inline %struct_name%& operator/=(___root___ const& other)
	{
		assert(handle_);
		write().operator/=(other);
		return *this;
	}

	inline %struct_name%& operator%=(___root___ const& other)
	{
		assert(handle_);
		write().operator%=(other);
		return *this;
	}

	%nonvirtual_members%

private:
	struct ___finale_handle_base___ : ___ddderived_handle_base___
	{
		%pure_virtual_members%
	};

	template <typename ___TTT___>
	struct ___finale_handle_final___ final : ___ddderived_handle___<___TTT___, ___finale_handle_base___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<std::is_reference<___UUU___>::value>::type * = 0)
			: ___ddderived_handle___<___TTT___, ___finale_handle_base___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___finale_handle_final___(___TTT___ value, typename std::enable_if<!std::is_reference<___UUU___>::value, int>::type * = 0) noexcept
			: ___ddderived_handle___<___TTT___, ___finale_handle_base___>{ std::move(value) }
		{}

		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final
		{
			return std::make_shared<___finale_handle_final___>(___ddderived_handle___<___TTT___, ___finale_handle_base___>::value_);
		}

		%virtual_members% //TODO final
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
		if (!___reference___ && !handle_.unique())
		{
			handle_ = handle_->___clone___();
			handle_->___weak___(handle_);
		}
		return *std::static_pointer_cast<___finale_handle_base___>(handle_);
	}

	template <typename ___TTT___, typename ___1___>
	friend inline bool check_(%struct_name%<___1___> const& value) noexcept;

public:
	static inline char const* ___abstraction_name___() noexcept
	{
		return "%struct_name%";
	}

	static inline bool ___check___(std::shared_ptr<___root_handle_base___> const& handle) noexcept
	{
		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
	}

	inline %struct_name%() = default;

	explicit inline %struct_name%(bool reference) noexcept
		: ___derived___{ reference }
	{}

	inline %struct_name%(%struct_name% const& other, bool reference) noexcept
		: ___derived___(other, reference)
	{}

	inline %struct_name%(%struct_name%&& other, bool reference) noexcept
		: ___derived___(std::move(other), reference)
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	explicit inline %struct_name%(std::shared_ptr<___TTT___> const& handle, bool reference = false)
		: ___derived___(handle, reference)
	{
		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))
		{
			throw dis("%struct_name% constructor failed to cast from base to final");
		}
	}
#else
	template <typename ___TTT___>
	explicit inline %struct_name%(std::shared_ptr<___TTT___> const& handle, bool reference = false) noexcept
		: ___derived___(handle, reference)
	{
		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<%struct_name%, std::decay_t<___TTT___>>::value>>
	explicit inline %struct_name%(___TTT___ value, bool reference = false) noexcept
		: ___derived___(std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
			reference)
	{}

#ifdef STRANGE_CHECK_STATIC_CASTS
	template <typename ___TTT___>
	inline %struct_name%& operator=(std::shared_ptr<___TTT___> const& handle)
	{
		if (!std::dynamic_pointer_cast<___finale_handle_base___>(handle))
		{
			throw dis("%struct_name% assignment failed to cast from base to final");
		}
		handle_ = handle;
		handle_->___weak___(handle_);
		return *this;
	}
#else
	template <typename ___TTT___>
	inline %struct_name%& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
		handle_ = handle;
		handle_->___weak___(handle_);
		return *this;
	}
#endif

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<%struct_name%, std::decay_t<___TTT___>>::value>>
	inline %struct_name%& operator=(___TTT___ value) noexcept
	{
		%struct_name% temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		handle_->___weak___(handle_);
		return *this;
	}
};

template <typename ___TTT___, typename ___1___>
inline bool check_(%struct_name%<___1___> const& value) noexcept
{
	return ___TTT___::___check___(value.handle_);
}

#undef ___derived___