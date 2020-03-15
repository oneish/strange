
namespace strange
{

template <typename _1_ = void>
class inventory_d;

template <typename _1_ = void>
inline inventory_d<_1_> ___inventory_dynamic___(any_a<> const& thing); 

template <typename _1_>
class inventory_a : public collection_a<>
{
public:
	inline bool has_index(int64_t index ) const
	{ assert(___handle___); return ___read___().has_index(index); }

	inline any_a < > at_index(int64_t index ) const
	{ assert(___handle___); return ___read___().at_index(index); }

	inline void update_index(int64_t index , any_a < > const & value )
	{ assert(___handle___); ___write___().update_index(index, value); }

	inline bool insert_index(int64_t index , any_a < > const & value )
	{ assert(___handle___); return ___write___().insert_index(index, value); }

	inline bool erase_index(int64_t index )
	{ assert(___handle___); return ___write___().erase_index(index); }

	inline any_a<> mutate_begin__(range_a<> const& ___arguments___);

	inline random_access_mutator_a<> mutate_begin_()
	{ assert(___handle___); return ___write___().mutate_begin_(); }

	inline any_a<> mutate_end__(range_a<> const& ___arguments___);

	inline random_access_mutator_a<> mutate_end_()
	{ assert(___handle___); return ___write___().mutate_end_(); }

protected:
	struct ___inventory_a_handle_base___ : ___collection_a_handle_base___
	{
		virtual bool has_index(int64_t index ) const = 0;
		virtual any_a < > at_index(int64_t index ) const = 0;
		virtual void update_index(int64_t index , any_a < > const & value ) = 0;
		virtual bool insert_index(int64_t index , any_a < > const & value ) = 0;
		virtual bool erase_index(int64_t index ) = 0;
		virtual random_access_mutator_a<> mutate_begin_() = 0;
		virtual random_access_mutator_a<> mutate_end_() = 0;
	};

	template <typename ___TTT___, typename ___DHB___ = ___inventory_a_handle_base___>
	struct ___inventory_a_handle___ : ___collection_a_handle___<___TTT___, ___DHB___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___inventory_a_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___collection_a_handle___<___TTT___, ___DHB___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___inventory_a_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___collection_a_handle___<___TTT___, ___DHB___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___inventory_a_handle___(___variadic_tag___, Args&&... args)
			: ___collection_a_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline bool has_index(int64_t index ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.has_index(index); }

		virtual inline any_a < > at_index(int64_t index ) const final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.at_index(index); }

		virtual inline void update_index(int64_t index , any_a < > const & value ) final
		{ ___any_a_handle___<___TTT___, ___DHB___>::___value___.update_index(index, value); }

		virtual inline bool insert_index(int64_t index , any_a < > const & value ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_index(index, value); }

		virtual inline bool erase_index(int64_t index ) final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.erase_index(index); }

		virtual inline random_access_mutator_a<> mutate_begin_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_begin_(); }

		virtual inline random_access_mutator_a<> mutate_end_() final
		{ return ___any_a_handle___<___TTT___, ___DHB___>::___value___.mutate_end_(); }

	};

	template <typename ___TTT___, typename ___DHB___>
	struct ___inventory_a_handle___<std::reference_wrapper<___TTT___>, ___DHB___>
		: ___inventory_a_handle___<___TTT___&, ___DHB___>
	{
		inline ___inventory_a_handle___(std::reference_wrapper<___TTT___> ref)
			: ___inventory_a_handle___<___TTT___&, ___DHB___>{ ref.get() }
		{}
	};

private:
	template <typename ___TTT___>
	struct ___inventory_a_handle_final___ final : ___inventory_a_handle___<___TTT___>
	{
		template <typename ___UUU___ = ___TTT___>
		inline ___inventory_a_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)
			: ___inventory_a_handle___<___TTT___>{ value }
		{}

		template <typename ___UUU___ = ___TTT___>
		inline ___inventory_a_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept
			: ___inventory_a_handle___<___TTT___>{ std::move(value) }
		{}

		template <typename... Args>
		inline ___inventory_a_handle_final___(___variadic_tag___, Args&&... args)
			: ___inventory_a_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)
		{}

		virtual inline ___SHARED___ ___clone___() const final
		{
			return std::make_shared<___inventory_a_handle_final___>(___inventory_a_handle___<___TTT___>::___value___);
		}
	};

	template <typename ___TTT___>
	struct ___inventory_a_handle_final___<std::reference_wrapper<___TTT___>> final
		: ___inventory_a_handle_final___<___TTT___&>
	{
		inline ___inventory_a_handle_final___(std::reference_wrapper<___TTT___> ref)
			: ___inventory_a_handle_final___<___TTT___&>{ ref.get() }
		{}
	};

protected:
	inline ___inventory_a_handle_base___ const& ___read___() const noexcept
	{
		return *std::static_pointer_cast<___inventory_a_handle_base___ const>(___handle___);
	}

	inline ___inventory_a_handle_base___& ___write___() noexcept
	{
		if (!___handle___.unique())
		{
			___handle___ = ___handle___->___clone___();
			___handle___->___weak___(___handle___);
		}
		return *std::static_pointer_cast<___inventory_a_handle_base___>(___handle___);
	}

public:
	static inline inventory_a val(inventory_a const& other) noexcept
	{
		return inventory_a{ other };
	}

	static inline inventory_a ref(inventory_a& other) noexcept
	{
		return inventory_a(other, ___reference_tag___{});
	}

	static inline inventory_a dup(inventory_a& other) noexcept
	{
		return inventory_a(other, ___duplicate_tag___{});
	}

	inline inventory_a() = default;

	inline inventory_a(inventory_a& other, ___reference_tag___) noexcept
		: collection_a(other, ___reference_tag___{})
	{}

	inline inventory_a(inventory_a& other, ___duplicate_tag___) noexcept
		: collection_a(other, ___duplicate_tag___{})
	{}

	template <typename ___TTT___>
	explicit inline inventory_a(std::shared_ptr<___TTT___> const& handle) noexcept
		: collection_a{ handle }
	{
		assert(!handle || std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle));
	}

	template <typename ___TTT___>
	explicit inline inventory_a(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept
		: collection_a(handle, ___reference_tag___{})
	{
		assert(!handle || std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle));
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<inventory_a, std::decay_t<___TTT___>>::value>>
	explicit inline inventory_a(___TTT___ value) noexcept
		: collection_a{ std::make_shared<___inventory_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___, typename... Args>
	explicit inline inventory_a(___variadic_tag___, ___TTT___*, Args&&... args)
		: collection_a{ std::make_shared<___inventory_a_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }
	{
		___handle___->___weak___(___handle___);
	}

	template <typename ___TTT___>
	inline inventory_a& operator=(std::shared_ptr<___TTT___> const& handle) noexcept
	{
		assert(!handle || std::dynamic_pointer_cast<___inventory_a_handle_base___>(handle));
		___handle___ = handle;
		return *this;
	}

	template <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<inventory_a, std::decay_t<___TTT___>>::value>>
	inline inventory_a& operator=(___TTT___ value) noexcept
	{
		inventory_a temp{ std::move(value) };
		std::swap(temp.___handle___, ___handle___);
		return *this;
	}

	static inline bool ___check___(any_a<> const& thing)
	{
		return bool{ std::dynamic_pointer_cast<___inventory_a_handle_base___>(thing.___handle___) };
	}

	static inline inventory_a ___cast___(any_a<> const& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___inventory_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return inventory_a{ thing.___handle___ };
		}
		return inventory_a{ inventory_d<_1_>{ thing } };
	}

	static inline inventory_a ___cast_ref___(any_a<>& thing)
	{
		auto const ptr = std::dynamic_pointer_cast<___inventory_a_handle_base___>(thing.___handle___);
		if (ptr)
		{
			return inventory_a(thing.___handle___, ___reference_tag___{});
		}
		return inventory_a{ inventory_d<_1_>(thing, ___reference_tag___{}) };
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>
	static inline ___cat_a___ ___cat___()
	{
		static ___cat_a___ CAT = cat_create<___cat_a___>(1, "strange::inventory");
		return CAT;
	}

	template <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>
	static inline ___unordered_herd_a___ ___cats___()
	{
		static ___unordered_herd_a___ CATS = []()
		{
			auto cats = collection_a::___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			auto kinds = collection_a::___kinds___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();
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
			___unordered_shoal_a___ operations = collection_a::___operations___<___unordered_shoal_a___>();
			operations.update_string("mutate_begin_", native_mutation_t<inventory_a>::create(&inventory_a::mutate_begin__));
			operations.update_string("mutate_end_", native_mutation_t<inventory_a>::create(&inventory_a::mutate_end__));
			return operations;
		}();
		return OPERATIONS;
	}

	template <typename ___TTT___, typename... Args>
	static inline inventory_a create(Args&&... args)
	{
		return inventory_a(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);
	}

private:
	static bool const ___share___;
	friend class ___inventory_a_share___;
}; // class inventory_a

template <typename _1_>
class inventory_d : public collection_d<>
{
public:
	inline bool has_index(int64_t index ) const
	{ return has_(num(index)); }

	inline any_a < > at_index(int64_t index ) const
	{ return at_(num(index)); }

	inline void update_index(int64_t index , any_a < > const & value )
	{ update_(num(index), value); }

	inline bool insert_index(int64_t index , any_a < > const & value )
	{ return insert_(num(index), value); }

	inline bool erase_index(int64_t index )
	{ return erase_(num(index)); }

	inline any_a<> mutate_begin__(range_a<> const& arguments)
	{
		assert(___handle___);
		auto const op = operation("mutate_begin_");
		if (!op)
		{
			throw dis("dynamic inventory_d::mutate_begin_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline random_access_mutator_a<> mutate_begin_()
	{
		assert(___handle___);
		auto const op = operation("mutate_begin_");
		if (!op)
		{
			throw dis("dynamic inventory_d::mutate_begin_ passed non-existent member");
		}
		return cast<random_access_mutator_a<>>(variadic_operate(op, *this));
	}

	inline any_a<> mutate_end__(range_a<> const& arguments)
	{
		assert(___handle___);
		auto const op = operation("mutate_end_");
		if (!op)
		{
			throw dis("dynamic inventory_d::mutate_end_ passed non-existent member");
		}
		return op.operate(*this, arguments);
	}

	inline random_access_mutator_a<> mutate_end_()
	{
		assert(___handle___);
		auto const op = operation("mutate_end_");
		if (!op)
		{
			throw dis("dynamic inventory_d::mutate_end_ passed non-existent member");
		}
		return cast<random_access_mutator_a<>>(variadic_operate(op, *this));
	}

	void ___weak___(collection_d<>::___WEAK___ const& weak) const {}

	explicit inventory_d(any_a<> const& thing)
		: collection_d<>{ thing }
	{}

	explicit inventory_d(any_a<>& thing, ___reference_tag___)
		: collection_d<>{ thing, ___reference_tag___{} }
	{}

	explicit inventory_d(any_a<>& thing, ___duplicate_tag___)
		: collection_d<>{ thing, ___duplicate_tag___{} }
	{}
};

} // namespace
