
namespace strange
{

template <typename _1 = void>
class kind_d;

template <typename _1 = void>
inline kind_d<_1> ___kind_dynamic___(any_a<> const& thing); 

template <typename _1>
class kind_a : public cat_a<>
{
public:
	inline any_a<> aspects__(range_a<> const& ___arguments___) const;

	inline flock_a<> aspects_() const
	{ assert(___handle___); return ___read___().aspects_(); }

	inline any_a<> fixed__(range_a<> const& ___arguments___) const;

	inline any_a<> fixed_() const
	{ assert(___handle___); return ___read___().fixed_(); }

	inline bool fixed() const
	{ assert(___handle___); return ___read___().fixed(); }

	inline any_a<> reference__(range_a<> const& ___arguments___) const;

	inline any_a<> reference_() const
	{ assert(___handle___); return ___read___().reference_(); }

	inline bool reference() const
	{ assert(___handle___); return ___read___().reference(); }

	inline any_a<> optional__(range_a<> const& ___arguments___) const;

	inline any_a<> optional_() const
	{ assert(___handle___); return ___read___().optional_(); }

	inline bool optional() const
	{ assert(___handle___); return ___read___().optional(); }

protected:
	struct ___kind_a_handle_base___ : ___cat_a_handle_base___
	{
		virtual flock_a<> aspects_() const = 0;
		virtual any_a<> fixed_() const = 0;
		virtual bool fixed() const = 0;
		virtual any_a<> reference_() const = 0;
		virtual bool reference() const = 0;
		virtual any_a<> optional_() const = 0;
		virtual bool optional() const = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___kind_a_handle_base___>
	struct ___kind_a_handle___ : ___cat_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___kind_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___cat_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___kind_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___cat_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___kind_a_handle___(___variadic_tag___, Args&&... args)
			: ___cat_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline flock_a<> aspects_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.aspects_(); }

		virtual inline any_a<> fixed_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.fixed_(); }

		virtual inline bool fixed() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.fixed(); }

		virtual inline any_a<> reference_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.reference_(); }

		virtual inline bool reference() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.reference(); }

		virtual inline any_a<> optional_() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.optional_(); }

		virtual inline bool optional() const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.optional(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___kind_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___kind_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___kind_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___kind_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___kind_a_handle_final___ final : ___kind_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___kind_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___kind_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___kind_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___kind_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___kind_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___kind_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___kind_a_handle_final___>(___kind_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___kind_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___kind_a_handle_final___<___TTT___&>
	{
		inline ___kind_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___kind_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___kind_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___kind_a_handle_base___ const>(___handle___);
	}

	inline ___kind_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___kind_a_handle_base___>(___handle___);
	}

public:
	static inline kind_a val(kind_a const& other) noexcept
	{
		return kind_a{ other };
	}

	static inline kind_a ref(kind_a& other) noexcept
	{
		return kind_a(other, ___reference_tag___{});
	}

	static inline kind_a dup(kind_a& other) noexcept
	{
		return kind_a(other, ___duplicate_tag___{});
	}

	inline kind_a() = default;

	inline kind_a(kind_a& other, ___reference_tag___) noexcept
		: cat_a(other, ___reference_tag___{})
	{}

	inline kind_a(kind_a& other, ___duplicate_tag___) noexcept
		: cat_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline kind_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: cat_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___kind_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline kind_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: cat_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___kind_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<kind_a, std::decay_t<___TTT___>>::value>>
	explicit inline kind_a(___TTT___ value) noexcept
		: cat_a{ std::make_shared<___kind_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline kind_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: cat_a{ std::make_shared<___kind_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline kind_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___kind_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<kind_a, std::decay_t<___TTT___>>::value>>
	inline kind_a& operator=(___TTT___ value) noexcept
	{
		kind_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___kind_a_handle_base___>(thing.___handle___) };
	}

	static inline kind_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___kind_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return kind_a{ thing.___handle___ };
		}
		return kind_a{ kind_d<_1>{ thing } };
	}

	static inline kind_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___kind_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return kind_a(thing.___handle___, ___reference_tag___{});
		}
		return kind_a{ kind_d<_1>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::kind");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = cat_a::___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = cat_a::___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = cat_a::___operations___<___unordered_shoal_a___>();
			operations.update_string("aspects_", native_extraction_t<kind_a>::create(&kind_a::aspects__));
			operations.update_string("fixed_", native_extraction_t<kind_a>::create(&kind_a::fixed__));
			operations.update_string("reference_", native_extraction_t<kind_a>::create(&kind_a::reference__));
			operations.update_string("optional_", native_extraction_t<kind_a>::create(&kind_a::optional__));
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline kind_a create(Args&&... args)
	{
		return kind_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}
}; // class kind_a

template <typename _1>
class kind_d : public cat_d<>
{
public:
	inline any_a<> aspects__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("aspects_");
		if (!op)
		{
			throw dis("dynamic kind_d::aspects_ passed non-existent member");
		}
		return op.operate(*const_cast<kind_d*>(this), arguments);
	}

	inline flock_a<> aspects_() const
	{
		assert(___handle___);
		auto const op = operation("aspects_");
		if (!op)
		{
			throw dis("dynamic kind_d::aspects_ passed non-existent member");
		}
		return cast<flock_a<>>(variadic_operate(op, *const_cast<kind_d*>(this)));
	}

	inline any_a<> fixed__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("fixed_");
		if (!op)
		{
			throw dis("dynamic kind_d::fixed_ passed non-existent member");
		}
		return op.operate(*const_cast<kind_d*>(this), arguments);
	}

	inline any_a<> fixed_() const
	{
		assert(___handle___);
		auto const op = operation("fixed_");
		if (!op)
		{
			throw dis("dynamic kind_d::fixed_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<kind_d*>(this)));
	}

	inline bool fixed() const
	{ return fixed_(); }

	inline any_a<> reference__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("reference_");
		if (!op)
		{
			throw dis("dynamic kind_d::reference_ passed non-existent member");
		}
		return op.operate(*const_cast<kind_d*>(this), arguments);
	}

	inline any_a<> reference_() const
	{
		assert(___handle___);
		auto const op = operation("reference_");
		if (!op)
		{
			throw dis("dynamic kind_d::reference_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<kind_d*>(this)));
	}

	inline bool reference() const
	{ return reference_(); }

	inline any_a<> optional__(range_a<> const& arguments) const
	{
		assert(___handle___);
		auto const op = operation("optional_");
		if (!op)
		{
			throw dis("dynamic kind_d::optional_ passed non-existent member");
		}
		return op.operate(*const_cast<kind_d*>(this), arguments);
	}

	inline any_a<> optional_() const
	{
		assert(___handle___);
		auto const op = operation("optional_");
		if (!op)
		{
			throw dis("dynamic kind_d::optional_ passed non-existent member");
		}
		return cast<any_a<>>(variadic_operate(op, *const_cast<kind_d*>(this)));
	}

	inline bool optional() const
	{ return optional_(); }

	void ___weak___(cat_d<>::___WEAK___ const& weak) const {}

	explicit kind_d(any_a<> const& thing)
		: cat_d<>{ thing }
	{}

	explicit kind_d(any_a<>& thing, ___reference_tag___)
		: cat_d<>{ thing, ___reference_tag___{} }
	{}

	explicit kind_d(any_a<>& thing, ___duplicate_tag___)
		: cat_d<>{ thing, ___duplicate_tag___{} }
	{}
};

} // namespace
