
namespace strange
{

template <typename _1_ = void>
class random_access_mutator_d;

template <typename _1_ = void>
inline random_access_mutator_d<_1_> ___random_access_mutator_dynamic___(any_a<> const& thing); 

template <typename _1_>
class random_access_mutator_a : public bidirectional_mutator_a<>
{
public:
	inline any_a<> self_add__(range_a<> const& ___arguments___);

	inline random_access_mutator_a self_add_(number_a<> const& number)
	{
		assert(___handle___);
		___write___().self_add_(number);
		return *this;
	}

	inline random_access_mutator_a& operator+=(number_a<> const& number)
	{
		assert(___handle___);
		___write___().self_add_(number);
		return *this;
	}

	inline any_a<> add__(range_a<> const& ___arguments___) const;

	inline random_access_mutator_a<> add_(number_a<> const& number) const
	{ assert(___handle___); return ___read___().add_(number); }

	inline random_access_mutator_a<> operator+(number_a<> const& number) const
	{ assert(___handle___); return ___read___().add_(number); }

	inline any_a<> self_subtract__(range_a<> const& ___arguments___);

	inline random_access_mutator_a self_subtract_(number_a<> const& number)
	{
		assert(___handle___);
		___write___().self_subtract_(number);
		return *this;
	}

	inline random_access_mutator_a& operator-=(number_a<> const& number)
	{
		assert(___handle___);
		___write___().self_subtract_(number);
		return *this;
	}

	inline any_a<> subtract__(range_a<> const& ___arguments___) const;

	inline random_access_mutator_a<> subtract_(number_a<> const& number) const
	{ assert(___handle___); return ___read___().subtract_(number); }

	inline random_access_mutator_a<> operator-(number_a<> const& number) const
	{ assert(___handle___); return ___read___().subtract_(number); }

	inline any_a<> less_than__(range_a<> const& ___arguments___) const;

	inline any_a<> less_than_(random_access_mutator_a<> const& it) const
	{ assert(___handle___); return ___read___().less_than_(it); }

	inline bool operator<(random_access_mutator_a < > const & it ) const
	{ assert(___handle___); return ___read___().operator<(it); }

	inline any_a<> greater_than__(range_a<> const& ___arguments___) const;

	inline any_a<> greater_than_(random_access_mutator_a<> const& it) const
	{ assert(___handle___); return ___read___().greater_than_(it); }

	inline bool operator>(random_access_mutator_a < > const & it ) const
	{ assert(___handle___); return ___read___().operator>(it); }

	inline any_a<> less_or_equal__(range_a<> const& ___arguments___) const;

	inline any_a<> less_or_equal_(random_access_mutator_a<> const& it) const
	{ assert(___handle___); return ___read___().less_or_equal_(it); }

	inline bool operator<=(random_access_mutator_a < > const & it ) const
	{ assert(___handle___); return ___read___().operator<=(it); }

	inline any_a<> greater_or_equal__(range_a<> const& ___arguments___) const;

	inline any_a<> greater_or_equal_(random_access_mutator_a<> const& it) const
	{ assert(___handle___); return ___read___().greater_or_equal_(it); }

	inline bool operator>=(random_access_mutator_a < > const & it ) const
	{ assert(___handle___); return ___read___().operator>=(it); }

protected:
	struct ___random_access_mutator_a_handle_base___ : ___bidirectional_mutator_a_handle_base___
	{
		virtual void self_add_(number_a<> const& number) = 0;
		virtual random_access_mutator_a<> add_(number_a<> const& number) const = 0;
		virtual void self_subtract_(number_a<> const& number) = 0;
		virtual random_access_mutator_a<> subtract_(number_a<> const& number) const = 0;
		virtual any_a<> less_than_(random_access_mutator_a<> const& it) const = 0;
		virtual bool operator<(random_access_mutator_a < > const & it ) const = 0;
		virtual any_a<> greater_than_(random_access_mutator_a<> const& it) const = 0;
		virtual bool operator>(random_access_mutator_a < > const & it ) const = 0;
		virtual any_a<> less_or_equal_(random_access_mutator_a<> const& it) const = 0;
		virtual bool operator<=(random_access_mutator_a < > const & it ) const = 0;
		virtual any_a<> greater_or_equal_(random_access_mutator_a<> const& it) const = 0;
		virtual bool operator>=(random_access_mutator_a < > const & it ) const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___random_access_mutator_a_handle_base___>
	struct ___random_access_mutator_a_handle___ : ___bidirectional_mutator_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_mutator_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___bidirectional_mutator_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_mutator_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___bidirectional_mutator_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___random_access_mutator_a_handle___(___variadic_tag___, Args&&... args)
			: ___bidirectional_mutator_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline void self_add_(number_a<> const& number) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_add_(number); }

		virtual inline random_access_mutator_a<> add_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.add_(number); }

		virtual inline void self_subtract_(number_a<> const& number) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.self_subtract_(number); }

		virtual inline random_access_mutator_a<> subtract_(number_a<> const& number) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.subtract_(number); }

		virtual inline any_a<> less_than_(random_access_mutator_a<> const& it) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.less_than_(it); }

		virtual inline bool operator<(random_access_mutator_a < > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<(it); }

		virtual inline any_a<> greater_than_(random_access_mutator_a<> const& it) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.greater_than_(it); }

		virtual inline bool operator>(random_access_mutator_a < > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>(it); }

		virtual inline any_a<> less_or_equal_(random_access_mutator_a<> const& it) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.less_or_equal_(it); }

		virtual inline bool operator<=(random_access_mutator_a < > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator<=(it); }

		virtual inline any_a<> greater_or_equal_(random_access_mutator_a<> const& it) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.greater_or_equal_(it); }

		virtual inline bool operator>=(random_access_mutator_a < > const & it ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.operator>=(it); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___random_access_mutator_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___random_access_mutator_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___random_access_mutator_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___random_access_mutator_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___random_access_mutator_a_handle_final___ final : ___random_access_mutator_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_mutator_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___random_access_mutator_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___random_access_mutator_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___random_access_mutator_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___random_access_mutator_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___random_access_mutator_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___random_access_mutator_a_handle_final___>(___random_access_mutator_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___random_access_mutator_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___random_access_mutator_a_handle_final___<___TTT___&>
	{
		inline ___random_access_mutator_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___random_access_mutator_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___random_access_mutator_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___random_access_mutator_a_handle_base___ const>(___handle___);
	}

	inline ___random_access_mutator_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___random_access_mutator_a_handle_base___>(___handle___);
	}

public:
	static inline random_access_mutator_a val(random_access_mutator_a const& other) noexcept
	{
		return random_access_mutator_a{ other };
	}

	static inline random_access_mutator_a ref(random_access_mutator_a& other) noexcept
	{
		return random_access_mutator_a(other, ___reference_tag___{});
	}

	static inline random_access_mutator_a dup(random_access_mutator_a& other) noexcept
	{
		return random_access_mutator_a(other, ___duplicate_tag___{});
	}

	inline random_access_mutator_a() = default;

	inline random_access_mutator_a(random_access_mutator_a& other, ___reference_tag___) noexcept
		: bidirectional_mutator_a(other, ___reference_tag___{})
	{}

	inline random_access_mutator_a(random_access_mutator_a& other, ___duplicate_tag___) noexcept
		: bidirectional_mutator_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline random_access_mutator_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: bidirectional_mutator_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_mutator_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline random_access_mutator_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: bidirectional_mutator_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_mutator_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_mutator_a, std::decay_t<___TTT___>>::value>>
	explicit inline random_access_mutator_a(___TTT___ value) noexcept
		: bidirectional_mutator_a{ std::make_shared<___random_access_mutator_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline random_access_mutator_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: bidirectional_mutator_a{ std::make_shared<___random_access_mutator_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline random_access_mutator_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___random_access_mutator_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<random_access_mutator_a, std::decay_t<___TTT___>>::value>>
	inline random_access_mutator_a& operator=(___TTT___ value) noexcept
	{
		random_access_mutator_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___random_access_mutator_a_handle_base___>(thing.___handle___) };
	}

	static inline random_access_mutator_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___random_access_mutator_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return random_access_mutator_a{ thing.___handle___ };
		}
		return random_access_mutator_a{ random_access_mutator_d<_1_>{ thing } };
	}

	static inline random_access_mutator_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___random_access_mutator_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return random_access_mutator_a(thing.___handle___, ___reference_tag___{});
		}
		return random_access_mutator_a{ random_access_mutator_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::random_access_mutator");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = bidirectional_mutator_a::___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = bidirectional_mutator_a::___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = bidirectional_mutator_a::___operations___<___unordered_shoal_a___>();
			operations.update_string("self_add_", native_mutation_t<random_access_mutator_a>::create(&random_access_mutator_a::self_add__));
			operations.update_string("add_", native_extraction_t<random_access_mutator_a>::create(&random_access_mutator_a::add__));
			operations.update_string("self_subtract_", native_mutation_t<random_access_mutator_a>::create(&random_access_mutator_a::self_subtract__));
			operations.update_string("subtract_", native_extraction_t<random_access_mutator_a>::create(&random_access_mutator_a::subtract__));
			operations.update_string("less_than_", native_extraction_t<random_access_mutator_a>::create(&random_access_mutator_a::less_than__));
			operations.update_string("greater_than_", native_extraction_t<random_access_mutator_a>::create(&random_access_mutator_a::greater_than__));
			operations.update_string("less_or_equal_", native_extraction_t<random_access_mutator_a>::create(&random_access_mutator_a::less_or_equal__));
			operations.update_string("greater_or_equal_", native_extraction_t<random_access_mutator_a>::create(&random_access_mutator_a::greater_or_equal__));
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline random_access_mutator_a create(Args&&... args)
	{
		return random_access_mutator_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___random_access_mutator_a_share___;
}; // class random_access_mutator_a

template <typename _1_>
class random_access_mutator_d : public bidirectional_mutator_d<>
{
public:
	inline any_a<> self_add__(range_a<> const& arguments)
	{
		assert(___handle___);
		auto const op = operation("self_add_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::self_add_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline random_access_mutator_a<> self_add_(number_a<> const& number)
	{
		assert(___handle___);
		auto const op = operation("self_add_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::self_add_ passed non-existent member");
		}
		return cast<random_access_mutator_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> add__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::add_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_mutator_d*>(this), arguments);
	}

	inline random_access_mutator_a<> add_(number_a<> const& number) const
	{
		assert(___handle___);
		auto const op = operation("add_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::add_ passed non-existent member");
		}
		return cast<random_access_mutator_a<>>(variadic_operate(op, *const_cast<random_access_mutator_d*>(this), number));
	}

	inline any_a<> self_subtract__(range_a<> const& arguments)
	{
		assert(___handle___);
		auto const op = operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::self_subtract_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline random_access_mutator_a<> self_subtract_(number_a<> const& number)
	{
		assert(___handle___);
		auto const op = operation("self_subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::self_subtract_ passed non-existent member");
		}
		return cast<random_access_mutator_a<>>(variadic_operate(op, *this, number));
	}

	inline any_a<> subtract__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::subtract_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_mutator_d*>(this), arguments);
	}

	inline random_access_mutator_a<> subtract_(number_a<> const& number) const
	{
		assert(___handle___);
		auto const op = operation("subtract_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::subtract_ passed non-existent member");
		}
		return cast<random_access_mutator_a<>>(variadic_operate(op, *const_cast<random_access_mutator_d*>(this), number));
	}

	inline any_a<> less_than__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("less_than_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::less_than_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_mutator_d*>(this), arguments);
	}

	inline any_a<> less_than_(random_access_mutator_a<> const& it) const
	{
		assert(___handle___);
		auto const op = operation("less_than_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::less_than_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<random_access_mutator_d*>(this), it));
	}

	inline bool operator<(random_access_mutator_a < > const & it ) const
	{ return less_than_(it); }

	inline any_a<> greater_than__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("greater_than_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::greater_than_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_mutator_d*>(this), arguments);
	}

	inline any_a<> greater_than_(random_access_mutator_a<> const& it) const
	{
		assert(___handle___);
		auto const op = operation("greater_than_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::greater_than_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<random_access_mutator_d*>(this), it));
	}

	inline bool operator>(random_access_mutator_a < > const & it ) const
	{ return greater_than_(it); }

	inline any_a<> less_or_equal__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("less_or_equal_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::less_or_equal_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_mutator_d*>(this), arguments);
	}

	inline any_a<> less_or_equal_(random_access_mutator_a<> const& it) const
	{
		assert(___handle___);
		auto const op = operation("less_or_equal_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::less_or_equal_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<random_access_mutator_d*>(this), it));
	}

	inline bool operator<=(random_access_mutator_a < > const & it ) const
	{ return less_or_equal_(it); }

	inline any_a<> greater_or_equal__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("greater_or_equal_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::greater_or_equal_ passed non-existent member");
		}
		return op.operate(*const_cast<random_access_mutator_d*>(this), arguments);
	}

	inline any_a<> greater_or_equal_(random_access_mutator_a<> const& it) const
	{
		assert(___handle___);
		auto const op = operation("greater_or_equal_");
		if (!op)
		{
			throw dis("dynamic random_access_mutator_d::greater_or_equal_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<random_access_mutator_d*>(this), it));
	}

	inline bool operator>=(random_access_mutator_a < > const & it ) const
	{ return greater_or_equal_(it); }

	void ___weak___(bidirectional_mutator_d<>::___WEAK___ const& weak) const {}

	explicit random_access_mutator_d(any_a<> const& thing)
		: bidirectional_mutator_d<>{ thing }
	{}

	explicit random_access_mutator_d(any_a<>& thing, ___reference_tag___)
		: bidirectional_mutator_d<>{ thing, ___reference_tag___{} }
	{}

	explicit random_access_mutator_d(any_a<>& thing, ___duplicate_tag___)
		: bidirectional_mutator_d<>{ thing, ___duplicate_tag___{} }
	{}
};

} // namespace