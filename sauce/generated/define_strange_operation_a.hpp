
namespace strange
{

template <typename _1 = void>
class operation_d;

template <typename _1 = void>
inline operation_d<_1> ___operation_dynamic___(any_a<> const& thing); 

template <typename _1>
class operation_a : public any_a<>
{
public:
	inline any_a<> pure__(range_a<> const& ___arguments___) const;

	inline any_a<> pure_() const
	{ assert(any_a<>::___handle___); return ___read___().pure_(); }

	inline bool pure() const
	{ assert(any_a<>::___handle___); return ___read___().pure(); }

	inline void aspects(unordered_shoal_a < > const & shoal )
	{ assert(any_a<>::___handle___); ___write___().aspects(shoal); }

	inline void assign(operation_a < > const & operation )
	{ assert(any_a<>::___handle___); ___write___().assign(operation); }

	inline any_a<> names__(range_a<> const& ___arguments___) const;

	inline flock_a<> names_() const
	{ assert(any_a<>::___handle___); return ___read___().names_(); }

protected:
	struct ___operation_a_handle_base___ : any_a<>::___any_a_handle_base___
	{
		virtual any_a<> pure_() const = 0;
		virtual bool pure() const = 0;
		virtual void aspects(unordered_shoal_a < > const & shoal ) = 0;
		virtual void assign(operation_a < > const & operation ) = 0;
		virtual flock_a<> names_() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___operation_a_handle_base___>
	struct ___operation_a_handle___ : any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___operation_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___operation_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___operation_a_handle___(any_a<>::___variadic_tag___, Args&&... args)
			: any_a<>::template ___any_a_handle___<___TTT___, ___DHB___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<> pure_() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.pure_(); }

		virtual inline bool pure() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.pure(); }

		virtual inline void aspects(unordered_shoal_a < > const & shoal ) final
		{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.aspects(shoal); }

		virtual inline void assign(operation_a < > const & operation ) final
		{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.assign(operation); }

		virtual inline flock_a<> names_() const final
		{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.names_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___operation_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___operation_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___operation_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___operation_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___operation_a_handle_final___ final : ___operation_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___operation_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___operation_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___operation_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___operation_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___operation_a_handle_final___(any_a<>::___variadic_tag___, Args&&... args)
			: ___operation_a_handle___<___TTT___>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline any_a<>::___SHARED___ ___clone___() const final
		{
			return std::make_shared<___operation_a_handle_final___>(___operation_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___operation_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___operation_a_handle_final___<___TTT___&>
	{
		inline ___operation_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___operation_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___operation_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___operation_a_handle_base___ const>(any_a<>::___handle___);
	}

	inline ___operation_a_handle_base___& ___write___() noexcept
	{
		if (!any_a<>::___handle___.unique())
		{
			any_a<>::___handle___ = any_a<>::___handle___->___clone___();
			any_a<>::___handle___->___weak___(any_a<>::___handle___);
		}
		return *std::static_pointer_cast<___operation_a_handle_base___>(any_a<>::___handle___);
	}

public:
	static inline operation_a val(operation_a const& other) noexcept
	{
		return operation_a{ other };
	}

	static inline operation_a ref(operation_a& other) noexcept
	{
		return operation_a(other, any_a<>::___reference_tag___{});
	}

	static inline operation_a dup(operation_a& other) noexcept
	{
		return operation_a(other, any_a<>::___duplicate_tag___{});
	}

	inline operation_a() = default;

	inline operation_a(operation_a& other, any_a<>::___reference_tag___) noexcept
		: any_a<>(other, any_a<>::___reference_tag___{})
	{}

	inline operation_a(operation_a& other, any_a<>::___duplicate_tag___) noexcept
		: any_a<>(other, any_a<>::___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline operation_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: any_a<>{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___operation_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline operation_a(std::shared_ptr<___TTT___>& handle, any_a<>::___reference_tag___) noexcept
		: any_a<>(handle, any_a<>::___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___operation_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<operation_a, std::decay_t<___TTT___>>::value>>
	explicit inline operation_a(___TTT___ value) noexcept
		: any_a<>{ std::make_shared<___operation_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline operation_a(any_a<>::___variadic_tag___, ___TTT___*, Args&&... args)
		: any_a<>{ std::make_shared<___operation_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(any_a<>::___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		any_a<>::___handle___->___weak___(any_a<>::___handle___);
	}

	template <typename ___TTT___>
	inline operation_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___operation_a_handle_base___>(handle));
		any_a<>::___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<operation_a, std::decay_t<___TTT___>>::value>>
	inline operation_a& operator=(___TTT___ value) noexcept
	{
		operation_a temp{ std::move(value) };
		std::swap(temp.___handle___, any_a<>::___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___operation_a_handle_base___>(thing.___handle___) };
	}

	static inline operation_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___operation_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return operation_a{ thing.___handle___ };
		}
		return operation_a{ operation_d<_1>{ thing } };
	}

	static inline operation_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___operation_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return operation_a(thing.___handle___, any_a<>::___reference_tag___{});
		}
		return operation_a{ operation_d<_1>(thing, any_a<>::___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::operation");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = any_a<>::template ___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			cats.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return cats;
		}();
		return CATS;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___kind_a___ ___kind___()
	{
		static ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>());
		return KIND;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___kinds___()
	{
		static ___unordered_herd_a___ KINDS = []()
		{
			auto kinds = any_a<>::template ___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
			kinds.update_thing(___cat___<___cat_a___, ___kind_a___>());
			return kinds;
		}();
		return KINDS;
	}

	template <typename ___unordered_shoal_a___ = unordered_shoal_a<>>
	static inline ___unordered_shoal_a___ ___operations___()
	{
		static ___unordered_shoal_a___ OPERATIONS = []()
		{
			___unordered_shoal_a___ operations = any_a<>::template ___operations___<___unordered_shoal_a___>();
			operations.update_string("pure_", native_extraction_t<operation_a>::create(&operation_a::pure__));
			operations.update_string("names_", native_extraction_t<operation_a>::create(&operation_a::names__));
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline operation_a create(Args&&... args)
	{
		return operation_a(any_a<>::___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class operation_a

template <typename _1>
class operation_d : public any_a<>
{
public:
	inline any_a<> pure__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("pure_");
		if (!op)
		{
			throw dis("dynamic operation_d::pure_ passed non-existent member");
		}
		return op.operate(*const_cast<operation_d*>(this), arguments);
	}

	inline any_a<> pure_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("pure_");
		if (!op)
		{
			throw dis("dynamic operation_d::pure_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<operation_d*>(this)));
	}

	inline bool pure() const
	{ return pure_(); }

	inline void aspects(unordered_shoal_a < > const & shoal )
	{ throw dis("dynamic operation_d::aspects(shoal) not available"); }

	inline void assign(operation_a < > const & operation )
	{ throw dis("dynamic operation_d::assign(operation) not available"); }

	inline any_a<> names__(range_a<> const& arguments) const
	{
		assert(any_a<>::___handle___); 
		auto const op = any_a<>::operation("names_");
		if (!op)
		{
			throw dis("dynamic operation_d::names_ passed non-existent member");
		}
		return op.operate(*const_cast<operation_d*>(this), arguments);
	}

	inline flock_a<> names_() const
	{
		assert(any_a<>::___handle___);
		auto const op = any_a<>::operation("names_");
		if (!op)
		{
			throw dis("dynamic operation_d::names_ passed non-existent member");
		}
		return cast<flock_a<>>(variadic_operate(op, *const_cast<operation_d*>(this)));
	}

	void ___weak___(any_a<>::___WEAK___ const& weak) const {}

	explicit operation_d(any_a<> const& thing)
		: any_a<>{ thing }
	{}

	explicit operation_d(any_a<>& thing, any_a<>::___reference_tag___)
		: any_a<>{ thing, any_a<>::___reference_tag___{} }
	{}

	explicit operation_d(any_a<>& thing, any_a<>::___duplicate_tag___)
		: any_a<>{ thing, any_a<>::___duplicate_tag___{} }
	{}
};

} // namespace
