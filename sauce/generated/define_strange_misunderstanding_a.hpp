
namespace strange
{

template <typename _lake_int8 = lake_int8_a<> >
class misunderstanding_d;

template <typename _lake_int8 = lake_int8_a<> >
inline misunderstanding_d<_lake_int8> ___misunderstanding_dynamic___(any_a<> const& thing);

template <typename _lake_int8>
class misunderstanding_a : public any_a<>
{
public:
	inline any_a<> to_lake__(list_a<> const& ___arguments___) const;

	inline _lake_int8 to_lake_() const;

	inline std_string to_string() const;

	inline any_a<> add__(list_a<> const& ___arguments___) const;

	inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const;

	inline misunderstanding_a<> operator+(misunderstanding_a<> const& misunderstanding) const;

protected:
	struct ___misunderstanding_a_handle_base___ : any_a<>::___any_a_handle_base___
	{
		virtual _lake_int8 to_lake_() const = 0;
		virtual std_string to_string() const = 0;
		virtual misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___misunderstanding_a_handle_base___>
	struct ___misunderstanding_a_handle___ : any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___misunderstanding_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___misunderstanding_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___misunderstanding_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline _lake_int8 to_lake_() const final;

		virtual inline std_string to_string() const final;

		virtual inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const final;

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___misunderstanding_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___misunderstanding_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___misunderstanding_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___misunderstanding_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___misunderstanding_a_handle_final___ final : ___misunderstanding_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___misunderstanding_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___misunderstanding_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___misunderstanding_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___misunderstanding_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___misunderstanding_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___misunderstanding_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std_make_shared<___misunderstanding_a_handle_final___>(___misunderstanding_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___misunderstanding_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___misunderstanding_a_handle_final___<___TTT___&>
	{
		inline ___misunderstanding_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___misunderstanding_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___misunderstanding_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___misunderstanding_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___misunderstanding_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___misunderstanding_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline misunderstanding_a val(misunderstanding_a const& other) noexcept
	{
		return misunderstanding_a{ other };
	}

	static inline misunderstanding_a ref(misunderstanding_a& other) noexcept
	{
		return misunderstanding_a(other, any_a<>::___reference_tag___{});
	}

	static inline misunderstanding_a dup(misunderstanding_a& other) noexcept
	{
		return misunderstanding_a(other, any_a<>::___duplicate_tag___{});
	}

	inline misunderstanding_a() = default;

	inline misunderstanding_a(misunderstanding_a& other, any_a<>::___reference_tag___) noexcept
		: any_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline misunderstanding_a(misunderstanding_a& other, any_a<>::___duplicate_tag___) noexcept
		: any_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline misunderstanding_a(std_shared_ptr<___TTT___> const& handle) noexcept
		: any_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline misunderstanding_a(std_shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: any_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<misunderstanding_a, std::decay_t<___TTT___>>::value>>
	explicit inline misunderstanding_a(___TTT___ value) noexcept
		: any_a<>{ std_make_shared<___misunderstanding_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline misunderstanding_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a<>{ std_make_shared<___misunderstanding_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline misunderstanding_a& operator=(std_shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<misunderstanding_a, std::decay_t<___TTT___>>::value>>
	inline misunderstanding_a& operator=(___TTT___ value) noexcept
	{
		misunderstanding_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(thing.___handle___) };
	}

	static inline misunderstanding_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return misunderstanding_a{ thing.___handle___ };
		}
		return misunderstanding_a{ misunderstanding_d<_lake_int8>{ thing } };
	}

	static inline misunderstanding_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___misunderstanding_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return misunderstanding_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return misunderstanding_a{ misunderstanding_d<_lake_int8>(thing, any_a<>::___reference_tag___{}) };
	}

	static inline cat_a<> ___cat___();

	static inline unordered_herd_a<> ___cats___();

	static inline kind_a<> ___kind___();

	static inline unordered_herd_a<> ___kinds___();

	static inline unordered_shoal_a<> ___operations___();

	template <typename ___TTT___, typename... Args>
	static inline misunderstanding_a create(Args&&... args)
	{
		return misunderstanding_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class misunderstanding_a

template <typename _lake_int8>
class misunderstanding_d : public any_a<>
{
public:
	inline any_a<> to_lake__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_lake_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic misunderstanding_d::to_lake_ passed non-existent member");
		}
		return op.operate(*const_cast<misunderstanding_d*>(this), arguments);
	}

	inline _lake_int8 to_lake_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("to_lake_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic misunderstanding_d::to_lake_ passed non-existent member");
		}
		return cast<_lake_int8>(variadic_operate(op, *const_cast<misunderstanding_d*>(this)));
	}

	inline std_string to_string() const
	{ return lake::to_string(to_lake_()); }

	inline any_a<> add__(list_a<> const& arguments) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("add_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic misunderstanding_d::add_ passed non-existent member");
		}
		return op.operate(*const_cast<misunderstanding_d*>(this), arguments);
	}

	inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("add_");
		if (!op)
		{
			throw dis(__FILE__, __LINE__, "dynamic misunderstanding_d::add_ passed non-existent member");
		}
		return cast<misunderstanding_a<>>(variadic_operate(op, *const_cast<misunderstanding_d*>(this), misunderstanding));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit misunderstanding_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit misunderstanding_d(any_a<>& thing, any_a<>::___reference_tag___)
		: any_a<>{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit misunderstanding_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: any_a<>{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
