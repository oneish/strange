#define ___derived___ symbol_

%struct_prefix% final : public ___derived___
{
public:
	%nonvirtual_members%

private:
	struct ___finale_handle_base___ : ___derived_handle_base___
	{
		%pure_virtual_members%
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

		virtual inline std::shared_ptr<___root_handle_base___> ___clone___() const final
		{
			return std::make_shared<___finale_handle_final___>(___derived_handle___<___TTT___, ___finale_handle_base___>::value_);
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

	inline const ___finale_handle_base___& read() const
	{
		return *std::static_pointer_cast<const ___finale_handle_base___>(handle_);
	}

	inline ___finale_handle_base___& write()
	{
		if (!___reference___ && !handle_.unique())
		{
			handle_ = handle_->___clone___();
		}
		return *std::static_pointer_cast<___finale_handle_base___>(handle_);
	}

	template <typename ___TTT___>
	friend inline bool check_(const %struct_name%& value);

public:
	static inline bool ___check___(const std::shared_ptr<___root_handle_base___>& handle)
	{
		return bool(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
	}

	inline %struct_name%(bool reference = false)
		: ___derived___{ reference }
	{}


	template <typename ___TTT___>
	inline %struct_name%(const std::shared_ptr<___TTT___>& handle, bool reference = false)
		: ___derived___(handle, reference)
	{
		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
	}

	template <typename ___TTT___>
	inline %struct_name%(___TTT___ value, bool reference = false)
		: ___derived___(std::make_shared<___finale_handle_final___<typename std::remove_reference<___TTT___>::type>>(std::move(value)),
			reference)
	{}

	template <typename ___TTT___>
	inline %struct_name%& operator=(const std::shared_ptr<___TTT___>& handle)
	{
		assert(std::dynamic_pointer_cast<___finale_handle_base___>(handle));
		handle_ = handle;
		return *this;
	}

	template <typename ___TTT___>
	inline %struct_name%& operator=(___TTT___ value)
	{
		%struct_name% temp{ std::move(value) };
		std::swap(temp.handle_, handle_);
		return *this;
	}
};

template <typename ___TTT___>
inline bool check_(const %struct_name%& value)
{
	return ___TTT___::___check___(value.handle_);
}

#undef ___derived___