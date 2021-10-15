#ifndef COM_ONEISH__STRANGE__DATA_T_H
#define COM_ONEISH__STRANGE__DATA_T_H

namespace strange
{
	template <typename type_d>
	struct data_t : thing_t
	{
		type_d data_;

	protected:
		template <typename v=void>
		inline data_t(any_a& me)
			: thing_t{ me }
			, data_{}
		{
			me.o = data_t<type_d>::_operations();
		}

		template <typename v = void>
		inline data_t(any_a& me,
			type_d const& data)
		: thing_t{ me }
		, data_{ data }
		{
			me.o = data_t<type_d>::_operations();
		}

		inline data_t(any_a& me,
			type_d& data)
			: thing_t{ me }
			, data_{ data }
		{
			me.o = data_t<type_d>::_operations();
		}

		inline data_t(any_a& me,
			any_a const& original)
		: thing_t{ me, original }
		, data_{ static_cast<data_t<type_d>*>(original.t)->data_ }
		{
			me.o = data_t<type_d>::_operations();
		}

		data_t(data_t const&) = delete;

		data_t& operator=(data_t const&) = delete;

	private:
		// data_o
		static data_o<std::remove_reference_t<type_d>> const* _operations();
		static data_o<std::remove_reference_t<type_d>> const* _pointer_operations();

	protected:
		// any_a
		static bool is(con<> const& me,
			con<> const& abstraction);

		static bool as(con<> const& me,
			var<> const& abstraction);

		static var<symbol_a> type(con<> const& me);

		static void _copy(any_a const& me,
			any_a& copy);

		static void _set_pointer(con<> const& me,
			bool is_pointer);

		// data_a
		static ptr<> read_lock(ptr<data_a<std::remove_reference_t<type_d>>> const& me);

		static ptr<> write_lock(ptr<data_a<std::remove_reference_t<type_d>>> const& me);

		static std::remove_reference_t<type_d> const& extract(con<data_a<std::remove_reference_t<type_d>>> const& me);

		static std::remove_reference_t<type_d>& mutate(var<data_a<std::remove_reference_t<type_d>>> const& me);

	public:
		// creators
		template <typename v = void>
		static inline var<data_a<std::remove_reference_t<type_d>>> create_default()
		{
			any_a r;
			new data_t<type_d>{ r };
			data_t<type_d>::_initialise(r);
			return var<data_a<std::remove_reference_t<type_d>>>{ reinterpret_cast<data_a<std::remove_reference_t<type_d>>&>(r) };
		}


		template <typename v = void>
		static inline var<data_a<std::remove_reference_t<type_d>>> create(type_d const& data)
		{
			any_a r;
			new data_t<type_d>{ r, data };
			data_t<type_d>::_initialise(r);
			return var<data_a<std::remove_reference_t<type_d>>>{ reinterpret_cast<data_a<std::remove_reference_t<type_d>>&>(r) };
		}

		template <typename v = void>
		static inline ptr<data_a<std::remove_reference_t<type_d>>> create_ptr(type_d const& data)
		{
			any_a r;
			new data_t<type_d>{ r, data };
			data_t<type_d>::_initialise(r);
			return ptr<data_a<std::remove_reference_t<type_d>>>{ reinterpret_cast<data_a<std::remove_reference_t<type_d>>&>(r) };
		}

		static inline var<data_a<std::remove_reference_t<type_d>>> create_ref(type_d& data)
		{
			any_a r;
			new data_t<type_d>{ r, data };
			data_t<type_d>::_initialise(r);
			return var<data_a<std::remove_reference_t<type_d>>>{ reinterpret_cast<data_a<std::remove_reference_t<type_d>>&>(r) };
		}

		template <typename v = void>
		static inline var<data_a<std::remove_reference_t<type_d>>> create_from_range(con<range_a<>> const& range)
		{
			return create_default();
		}

		template <typename v = void>
		static inline var<data_a<std::remove_reference_t<type_d>>> unpack(con<container_a> const& container)
		{
			return create_default();
		}
	};

	template <typename type_d>
	struct data_pointer_t : data_t<type_d>
	{
	protected:
		inline data_pointer_t(any_a& me,
			type_d data)
		: data_t<type_d>{ me, data }
		{
			me.o = data_pointer_t<type_d>::_operations();
		}

		inline data_pointer_t(any_a& me,
			any_a const& original)
		: data_t<type_d>{ me, nullptr }
		{
			me.o = data_pointer_t<type_d>::_operations();
		}

		virtual ~data_pointer_t()
		{
			delete data_t<type_d>::data_;
		}

	private:
		// data_o
		static data_o<type_d> const* _operations();
		static data_o<type_d> const* _pointer_operations();

	protected:
		// any_a
		static var<symbol_a> type(con<> const& me);

		static void _copy(any_a const& me,
			any_a& copy);

		static void _set_pointer(con<> const& me,
			bool is_pointer);

	public:
		// creators
		static inline ptr<data_a<type_d>> create_ptr(type_d data)
		{
			any_a r;
			new data_pointer_t<type_d>{ r, data };
			data_pointer_t<type_d>::_initialise(r);
			return ptr<data_a<type_d>>{ reinterpret_cast<data_a<type_d>&>(r) };
		}

		static inline var<data_a<type_d>> create_from_range(con<range_a<>> const& range)
		{
			return create_ptr(nullptr);
		}

		static inline var<data_a<type_d>> unpack(con<container_a> const& container)
		{
			return create_ptr(nullptr);
		}
	};

	template <typename type_d, typename lock_d>
	struct locked_data_t : data_t<type_d>
	{
		lock_d lock_;

	protected:
		inline locked_data_t(any_a& me,
			type_d data)
			: data_t<type_d>{ me, data }
			, lock_{ lock_d::create() }
		{
			me.o = locked_data_t<type_d, lock_d>::_operations();
		}

		inline locked_data_t(any_a& me,
			any_a const& original)
			: data_t<type_d>{ me, original }
			, lock_{ lock_d::create() }
		{
			me.o = locked_data_t<type_d, lock_d>::_operations();
		}

	private:
		// data_o
		static data_o<std::remove_reference_t<type_d>> const* _operations();
		static data_o<std::remove_reference_t<type_d>> const* _pointer_operations();

	protected:
		// any_a
		static var<symbol_a> type(con<> const& me);

		static void _copy(any_a const& me,
			any_a& copy);

		static void _set_pointer(con<> const& me,
			bool is_pointer);

		// data_a
		static ptr<> read_lock(ptr<data_a<std::remove_reference_t<type_d>>> const& me);

		static ptr<> write_lock(ptr<data_a<std::remove_reference_t<type_d>>> const& me);

	public:
		// creators
		static inline var<data_a<std::remove_reference_t<type_d>>> create(type_d data)
		{
			any_a r;
			new locked_data_t<type_d, lock_d>{ r, data };
			locked_data_t<type_d, lock_d>::_initialise(r);
			return var<data_a<std::remove_reference_t<type_d>>>{ reinterpret_cast<data_a<std::remove_reference_t<type_d>>&>(r) };
		}

		static inline ptr<data_a<std::remove_reference_t<type_d>>> create_ptr(type_d data)
		{
			any_a r;
			new locked_data_t<type_d, lock_d>{ r, data };
			locked_data_t<type_d, lock_d>::_initialise(r);
			return ptr<data_a<std::remove_reference_t<type_d>>>{ reinterpret_cast<data_a<std::remove_reference_t<type_d>>&>(r) };
		}

		static inline var<data_a<std::remove_reference_t<type_d>>> create_from_range(con<range_a<>> const& range)
		{
			return create(nullptr);
		}

		static inline var<data_a<std::remove_reference_t<type_d>>> unpack(con<container_a> const& container)
		{
			return create(nullptr);
		}
	};

	template <typename type_d, typename lock_d>
	struct locked_data_pointer_t : data_pointer_t<type_d>
	{
		lock_d lock_;

	protected:
		inline locked_data_pointer_t(any_a& me,
			type_d data)
			: data_pointer_t<type_d>{ me, data }
			, lock_{ lock_d::create() }
		{
			me.o = locked_data_pointer_t<type_d, lock_d>::_operations();
		}

		inline locked_data_pointer_t(any_a& me,
			any_a const& original)
			: data_pointer_t<type_d>{ me, nullptr }
			, lock_{ lock_d::create() }
		{
			me.o = locked_data_pointer_t<type_d, lock_d>::_operations();
		}

	private:
		// data_o
		static data_o<type_d> const* _operations();
		static data_o<type_d> const* _pointer_operations();

	protected:
		// any_a
		static var<symbol_a> type(con<> const& me);

		static void _copy(any_a const& me,
			any_a& copy);

		static void _set_pointer(con<> const& me,
			bool is_pointer);

		// data_a
		static ptr<> read_lock(ptr<data_a<type_d>> const& me);

		static ptr<> write_lock(ptr<data_a<type_d>> const& me);

	public:
		// creators
		static inline var<data_a<type_d>> create(type_d data)
		{
			any_a r;
			new locked_data_pointer_t<type_d, lock_d>{ r, data };
			locked_data_pointer_t<type_d, lock_d>::_initialise(r);
			return var<data_a<type_d>>{ reinterpret_cast<data_a<type_d>&>(r) };
		}

		static inline ptr<data_a<type_d>> create_ptr(type_d data)
		{
			any_a r;
			new locked_data_pointer_t<type_d, lock_d>{ r, data };
			locked_data_pointer_t<type_d, lock_d>::_initialise(r);
			return ptr<data_a<type_d>>{ reinterpret_cast<data_a<type_d>&>(r) };
		}

		static inline var<data_a<type_d>> create_from_range(con<range_a<>> const& range)
		{
			return create(nullptr);
		}

		static inline var<data_a<type_d>> unpack(con<container_a> const& container)
		{
			return create(nullptr);
		}
	};

	template <typename type_d>
	inline var<data_a<std::remove_reference_t<type_d>>> dat(type_d const& data)
	{
		return data_t<type_d>::create(data);
	}

	template <typename type_d>
	inline var<data_a<std::remove_reference_t<type_d>>> dat()
	{
		return data_t<type_d>::create_default();
	}

	template <typename type_d>
	inline var<data_a<std::remove_reference_t<type_d>>> dat_ref(type_d& data)
	{
		return data_t<type_d&>::create_ref(data);
	}

	template <typename type_d>
	inline ptr<data_a<type_d*>> dat_ptr(type_d* data)
	{
		return data_pointer_t<type_d*>::create_ptr(data);
	}

	template <typename type_d, typename lock_d = var<lock_a>>
	inline var<data_a<std::remove_reference_t<type_d>>> locked_dat(type_d const& data)
	{
		return locked_data_t<type_d, lock_d>::create(data);
	}

	template <typename type_d, typename lock_d = var<lock_a>>
	inline var<data_a<std::remove_reference_t<type_d>>> locked_dat()
	{
		return locked_data_t<type_d, lock_d>::create_default();
	}

	template <typename type_d, typename lock_d = var<lock_a>>
	inline var<data_a<std::remove_reference_t<type_d>>> locked_dat_ref(type_d& data)
	{
		return locked_data_t<type_d&, lock_d>::create_ref(data);
	}

	template <typename type_d, typename lock_d = var<lock_a>>
	inline ptr<data_a<type_d*>> locked_dat_ptr(type_d* data)
	{
		return locked_data_pointer_t<type_d*, lock_d>::create_ptr(data);
	}

	template <typename D>
	struct default_copy : D
	{
		default_copy() = default;

		inline default_copy(default_copy const&) : D{} {} // copy constructor

		default_copy& operator=(default_copy const&) = delete; // copy assignment operator
	};

	template <typename type_d>
	inline var<data_a<default_copy<type_d>>> dat_def()
	{
		return data_t<default_copy<type_d>>::create_default();
	}

	template <typename type_d, typename lock_d = var<lock_a>>
	inline var<data_a<default_copy<type_d>>> locked_dat_def()
	{
		return locked_data_t<default_copy<type_d>, lock_d>::create_default();
	}

	inline ptr<> lock_o::read_lock(var<lock_a> const& me)
	{
		me.mut();
		return dat_ptr(new std::shared_lock<std::shared_mutex>(static_cast<data_t<default_copy<std::shared_mutex>>*>(me.t)->data_));
	}

	inline ptr<> lock_o::write_lock(var<lock_a> const& me)
	{
		me.mut();
		return dat_ptr(new std::unique_lock<std::shared_mutex>(static_cast<data_t<default_copy<std::shared_mutex>>*>(me.t)->data_));
	}

	inline std::shared_lock<std::shared_mutex> lock_o::_read_lock(var<lock_a> const& me)
	{
		me.mut();
		return std::shared_lock<std::shared_mutex>(static_cast<data_t<default_copy<std::shared_mutex>>*>(me.t)->data_);
	}

	inline std::unique_lock<std::shared_mutex> lock_o::_write_lock(var<lock_a> const& me)
	{
		me.mut();
		return std::unique_lock<std::shared_mutex>(static_cast<data_t<default_copy<std::shared_mutex>>*>(me.t)->data_);
	}

	inline var<lock_a> lock_a::create()
	{
		return dat_def<std::shared_mutex>().val<var<lock_a>>();
	}

	inline ptr<> unlock_o::read_lock(var<lock_a> const& me)
	{
		return ptr<>{};
	}

	inline ptr<> unlock_o::write_lock(var<lock_a> const& me)
	{
		return ptr<>{};
	}
}

#endif
