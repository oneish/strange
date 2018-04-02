#ifndef COM_ONEISH_STRANGE_H
#define COM_ONEISH_STRANGE_H

#include <memory>
#include <cstring>
#include <iostream>
#include <atomic>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cstdint>
#include <type_traits>

namespace strange
{

class Thing
{
public:
	typedef std::shared_ptr<Thing> Ptr;
	typedef std::weak_ptr<Thing> Weak;

	template<typename... Args>
	inline const Ptr call_(Args... args)
	{
		std::vector<Ptr>* const v = new std::vector<Ptr>;
		variadic_(*v, args...);
		return thing(Iterator<const std::vector<Ptr>>::mut_(v));
	}

	static inline void variadic_(std::vector<Ptr>& vec)
	{
	}

	template<typename... Args>
	static inline void variadic_(std::vector<Ptr>& vec, const char* const symbol, Args... args)
	{
		vec.push_back(sym_(symbol));
		variadic_(vec, args...);
	}

	template<typename... Args>
	static inline void variadic_(std::vector<Ptr>& vec, Thing& thing, Args... args)
	{
		for (Ptr p = thing.next_(); !p->is_("end"); p = thing.next_())
		{
			vec.push_back(p);
		}
		variadic_(vec, args...);
	}

	template<typename... Args>
	static inline void variadic_(std::vector<Ptr>& vec, const Ptr ptr, Args... args)
	{
		vec.push_back(ptr);
		variadic_(vec, args...);
	}

	inline const Ptr thing(const Ptr it)
	{
		return operator()(this, it);
	}

	virtual ~Thing() = default;

	virtual inline const Ptr next_()
	{
		return end_();
	}

	inline const Ptr next(const Ptr ignore)
	{
		return next_();
	}

	inline const bool is_(const char* const symbol) const;

	virtual inline size_t hash_() const
	{
		return (size_t)(this);
	}

	virtual inline const bool same_(const Thing& other) const
	{
		return (this == &other);
	}

	virtual inline const Ptr copy_() const = 0;

	inline const Ptr copy(const Ptr ignore) const
	{
		return copy_();
	}

	virtual inline void finalize_()
	{
	}

	inline const Ptr finalize(const Ptr ignore)
	{
		finalize_();
		return nothing_();
	}

	virtual inline const bool finalized_() const
	{
		return true;
	}

	inline const Ptr finalized(const Ptr ignore) const
	{
		return boolean_(finalized_());
	}

	virtual inline void freeze_()
	{
		finalize_();
	}

	inline const Ptr freeze(const Ptr ignore)
	{
		freeze_();
		return nothing_();
	}

	static inline const Ptr boolean_(const bool value)
	{
		return value ? one_() : nothing_();
	}

	static inline const Ptr boolean(const Ptr it)
	{
		return boolean_(!it->next_()->is_("0"));
	}

	static inline const Ptr factory(const Ptr it);

	virtual inline const Ptr pub_() const;

	inline const Ptr pub(const Ptr ignore) const
	{
		return pub_();
	}

	static inline const Ptr sym_(const char* const symbol);

	static inline const Ptr nothing_();

	static inline const Ptr nothing(const Ptr ignore)
	{
		return nothing_();
	}

	static inline const Ptr one_();

	static inline const Ptr one(const Ptr ignore)
	{
		return one_();
	}

	static inline const Ptr end_();

	static inline const Ptr end(const Ptr ignore)
	{
		return end_();
	}

	static inline const Ptr log_(const char* const message)
	{
		std::cout << message;
		return nothing_();
	}

	virtual inline const Ptr to_buffer_() const;

	virtual inline void from_buffer_(const Ptr buffer);
	
	virtual inline const Ptr type_() const
	{
		static const Ptr TYPE = sym_("strange::Thing");
		return TYPE;
	}

	inline const Ptr type(const Ptr ignore) const
	{
		return type_();
	}

	virtual inline const Ptr cats_() const;

	inline const Ptr cats(const Ptr ignore) const
	{
		return cats_();
	}

	virtual const Ptr visit(const Ptr it)
	{
		const Ptr visitor = it->next_();
		visitor->thing(it);
		return visitor;
	}

protected:
	Thing() = default;

	static inline const Ptr thing_(Thing* const thing, const Ptr member, const Ptr it)
	{
		return member->operator()(thing, it);
	}

	virtual inline const Ptr operator()(Thing* const thing, const Ptr it);

private:
	Thing(const Thing&) = delete;
	Thing& operator=(const Thing& thing) = delete;
};

class Me
{
protected:
	Me() = default;

	template<typename T>
	static inline const Thing::Ptr me_(T* const thing)
	{
		const Thing::Ptr result = Thing::Ptr(thing);
		thing->_me = result;
		return result;
	}

	inline const Thing::Ptr me_() const
	{
		const Thing::Ptr ptr = _me.lock();
		if (ptr)
		{
			return ptr;
		}
		return Thing::nothing_();
	}

private:
	Thing::Weak _me;
};

class Symbol : public Thing, public Me
{
public:
	virtual inline size_t hash_() const override
	{
		return _hash;
	}

	virtual inline const bool same_(const Thing& other) const override
	{
		return other.is_(_symbol);
	}

	inline const char* const symbol_() const
	{
		return _symbol;
	}

	virtual inline const Ptr copy_() const override
	{
		return me_();
	}

	static inline const Ptr fin_(const char* const symbol)
	{
		return me_<Symbol>(new Symbol(symbol));
	}

	static inline const Ptr buf(const Ptr it);

	virtual inline const Ptr to_buffer_() const override;

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Symbol");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override;

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		return me_();
	}

private:
	inline Symbol(const char* const symbol)
		: Me()
		, _symbol(symbol)
		, _hash(std::hash<std::string>()(symbol))
	{
	}

	const char* const _symbol;
	const size_t _hash;
};

inline const bool Thing::is_(const char* const symbol) const
{
	const Symbol* const sym = dynamic_cast<const Symbol*>(this);
	return (sym && (strcmp(symbol, sym->symbol_()) == 0));
}

inline const Thing::Ptr Thing::sym_(const char* const symbol)
{
	return Symbol::fin_(symbol);
}

inline const Thing::Ptr Thing::nothing_()
{
	static const Ptr NOTHING(sym_("0"));
	return NOTHING;
}

inline const Thing::Ptr Thing::one_()
{
	static const Ptr ONE(sym_("1"));
	return ONE;
}

inline const Thing::Ptr Thing::end_()
{
	static const Ptr END(sym_("end"));
	return END;
}

class Static : public Thing, public Me
{
	typedef const Ptr(*function)(const Ptr);

public:
	static inline const Ptr fin_(const function fun)
	{
		return me_<Static>(new Static(fun));
	}

	virtual inline const Ptr copy_() const override
	{
		return me_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Static");
		return TYPE;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		return _function(it);
	}

private:
	Static(const function fun)
		: Me()
		, _function(fun)
	{
	}

	const function _function;
};

template<typename T>
class Member : public Thing, public Me
{
	typedef const Ptr(T::* member)(const Ptr);

public:
	static inline const Ptr fin_(const member fun)
	{
		return me_<Member>(new Member(fun));
	}

	virtual inline const Ptr copy_() const override
	{
		return me_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Member");
		return TYPE;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		T* const t = dynamic_cast<T*>(thing);
		if (t)
		{
			if (t->finalized_())
			{
				return log_("ERROR: Member passed finalized thing\n");
			}
			return (t->*_function)(it);
		}
		return log_("ERROR: Member passed wrong type of thing\n");
	}

private:
	Member(const member fun)
		: Me()
		, _function(fun)
	{
	}

	const member _function;
};

template<typename T>
class Const : public Thing, public Me
{
	typedef const Ptr(T::* member)(const Ptr) const;

public:
	static inline const Ptr fin_(const member fun)
	{
		return me_<Const>(new Const(fun));
	}

	virtual inline const Ptr copy_() const override
	{
		return me_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Const");
		return TYPE;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		T* const t = dynamic_cast<T*>(thing);
		if (t)
		{
			return (t->*_function)(it);
		}
		return log_("ERROR: Const passed wrong type of thing\n");
	}

private:
	Const(const member fun)
		: Me()
		, _function(fun)
	{
	}

	const member _function;
};

class Mutable : public Thing
{
public:
	virtual inline void finalize_() override
	{
		_finalized = true;
	}

	virtual inline const bool finalized_() const override
	{
		return _finalized;
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Mutable");
		return TYPE;
	}

protected:
	inline Mutable()
		: Thing()
		, _finalized(false)
	{
	}

private:
	bool _finalized;
};

class Index : public Mutable, public Me
{
	class Hash
	{
	public:
		inline size_t operator()(const Ptr& ptr) const
		{
			return ptr->hash_();
		}
	};

	class Pred
	{
	public:
		inline const bool operator()(const Ptr& lhs, const Ptr& rhs) const
		{
			return lhs->same_(*rhs);
		}
	};

	typedef std::unordered_map<Ptr, Ptr, Hash, Pred> std_unordered_map_ptr_ptr;

public:
	virtual inline const Ptr copy_() const override
	{
		const Ptr result = mut_();
		static_cast<Index*>(result.get())->_map = _map;
		return result;
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_cast<Index*>(pub.get());
			index->update_("mut", Static::fin_(&Index::mut));
			index->update_("find", Const<Index>::fin_(&Index::find));
			index->update_("update", Member<Index>::fin_(&Index::update));
			index->update_("iterator", Const<Index>::fin_(&Index::iterator));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr mut_()
	{
		return me_<Index>(new Index);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	inline const Ptr find(const Ptr it) const
	{
		const std_unordered_map_ptr_ptr::const_iterator mit = _map.find(it->next_());
		if (mit == _map.end())
		{
			return nothing_();
		}
		return mit->second;
	}

	inline const Ptr update(const Ptr it)
	{
		const Ptr key = it->next_();
		const Ptr value = it->next_();
		return update_(key, value);
	}

	inline const Ptr update_(const Ptr key, const Ptr value)
	{
		return _map[key] = value;
	}

	inline const Ptr update_(const char* const key, const Ptr value)
	{
		return update_(sym_(key), value);
	}

	inline const Ptr iterator_() const
	{
		return It::mut_(me_());
	}

	inline const Ptr iterator(const Ptr ignore) const
	{
		return iterator_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Index");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override;

	virtual const Ptr visit(const Ptr it) override
	{
		const Ptr visitor = it->next_();
		const Ptr member = it->next_();
		if (visitor->call_(member, it->next_())->is_("0"))
		{
			return visitor;
		}
		for (auto visited : _map)
		{
			visited.first->call_("visit", visitor, member, visited.first);
			visited.second->call_("visit", visitor, member, visited.second);
		}
		return visitor;
	}

private:
	Index() = default;

	std_unordered_map_ptr_ptr _map;

	class It : public Mutable
	{
	public:
		virtual inline const Ptr next_() override;

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_index);
			static_cast<It*>(result.get())->_iterator = _iterator;
			return result;
		}

		static inline const Ptr mut_(const Ptr index)
		{
			return Ptr(new It(index));
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Index:It");
			return TYPE;
		}

		virtual inline const Ptr cats_() const override;

	private:
		inline It(const Ptr index)
			: Mutable()
			, _index(index)
			, _iterator(static_cast<Index*>(_index.get())->_map.begin())
		{
		}

		const Ptr _index;
		std_unordered_map_ptr_ptr::const_iterator _iterator;
	};
};

inline const Thing::Ptr Thing::pub_() const
{
	static const Ptr PUB = []()
	{
		const Ptr pub = Index::mut_();
		Index* const index = static_cast<Index*>(pub.get());
		index->update_("thing", Member<Thing>::fin_(&Thing::thing));
		index->update_("next", Member<Thing>::fin_(&Thing::next));
		index->update_("copy", Const<Thing>::fin_(&Thing::copy));
		index->update_("finalize", Member<Thing>::fin_(&Thing::finalize));
		index->update_("finalized", Const<Thing>::fin_(&Thing::finalized));
		index->update_("freeze", Member<Thing>::fin_(&Thing::freeze));
		index->update_("boolean", Static::fin_(&Thing::boolean));
		index->update_("factory", Static::fin_(&Thing::factory));
		index->update_("pub", Const<Thing>::fin_(&Thing::pub));
		index->update_(nothing_(), nothing_());
		index->update_(one_(), one_());
		index->update_(end_(), end_());
		index->update_("type", Const<Thing>::fin_(&Thing::type));
		index->update_("cats", Const<Thing>::fin_(&Thing::cats));
		index->update_("visit", Member<Thing>::fin_(&Thing::visit));
		index->finalize_();
		return pub;
	}();
	return PUB;
}

inline const Thing::Ptr Thing::operator()(Thing* const thing, const Thing::Ptr it)
{
	const Ptr member = static_cast<Index*>(pub_().get())->find(it);
	return thing_(thing, member, it);
}

class Decorator : public Thing
{
protected:
	inline Decorator(const Ptr decorated)
		: Thing()
		, _decorated(decorated)
	{
	}

	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		const Ptr cit = it->copy_();
		const Ptr member = static_cast<Index*>(pub_().get())->find(it);
		if (member->is_("0"))
		{
			return _decorated->thing(cit);
		}
		return thing_(thing, member, it);
	}

	const Ptr _decorated;
};

template<typename C>
class Iterator : public Mutable
{
	typedef const std::shared_ptr<C> const_std_shared_ptr_collection;

public:
	virtual inline const Ptr next_() override
	{
		if (_iterator == _collection->cend())
		{
			return end_();
		}
		return *_iterator++;
	}

	virtual inline const Ptr copy_() const override
	{
		const Ptr result = mut_(_collection);
		Iterator* const iterator = static_cast<Iterator*>(result.get());
		iterator->_iterator = _iterator;
		return result;
	}

	static inline const Ptr mut_(C* const collection)
	{
		return mut_(const_std_shared_ptr_collection(collection));
	}

	static inline const Ptr mut_(const_std_shared_ptr_collection collection)
	{
		return Ptr(new Iterator(collection));
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Iterator");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override;

private:
	inline Iterator(const_std_shared_ptr_collection collection)
		: Mutable()
		, _collection(collection)
		, _iterator(collection->cbegin())
	{
	}

	const_std_shared_ptr_collection _collection;
	typename C::const_iterator _iterator;
};

class Flock : public Mutable, public Me
{
	typedef std::vector<Ptr> std_vector_ptr;

public:
	virtual inline const Ptr copy_() const override
	{
		const Ptr result = mut_();
		static_cast<Flock*>(result.get())->_vector = _vector;
		return result;
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_cast<Index*>(pub.get());
			index->update_("mut", Static::fin_(&Flock::mut));
			index->update_("push_back", Member<Flock>::fin_(&Flock::push_back));
			index->update_("iterator", Const<Flock>::fin_(&Flock::iterator));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr mut_()
	{
		return me_<Flock>(new Flock);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	inline const Ptr push_back(const Ptr it)
	{
		const Ptr item = it->next_();
		_vector.push_back(item);
		return item;
	}

	inline const Ptr iterator_() const
	{
		return It::mut_(me_());
	}

	inline const Ptr iterator(const Ptr ignore) const
	{
		return iterator_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Flock");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override;

	virtual const Ptr visit(const Ptr it) override
	{
		const Ptr visitor = it->next_();
		const Ptr member = it->next_();
		if (visitor->call_(member, it->next_())->is_("0"))
		{
			return visitor;
		}
		for (auto visited : _vector)
		{
			visited->call_("visit", visitor, member, visited);
		}
		return visitor;
	}

private:
	Flock() = default;

	std_vector_ptr _vector;

	class It : public Mutable
	{
	public:
		virtual const Ptr next_() override
		{
			if (_iterator == static_cast<Flock*>(_flock.get())->_vector.cend())
			{
				return end_();
			}
			return *_iterator++;
		}

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_flock);
			static_cast<It*>(result.get())->_iterator = _iterator;
			return result;
		}

		static inline const Ptr mut_(const Ptr flock)
		{
			return Ptr(new It(flock));
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Flock::It");
			return TYPE;
		}

		virtual inline const Ptr cats_() const override;

	private:
		inline It(const Ptr flock)
			: Mutable()
			, _flock(flock)
			, _iterator(static_cast<Flock*>(_flock.get())->_vector.begin())
		{
		}

		const Ptr _flock;
		std_vector_ptr::const_iterator _iterator;
	};
};

inline const Thing::Ptr Index::It::next_()
{
	if (_iterator == static_cast<Index*>(_index.get())->_map.cend())
	{
		return end_();
	}
	const Ptr result = Flock::mut_();
	Flock* const flock = static_cast<Flock*>(result.get());
	flock->push_back(_iterator->first);
	flock->push_back(_iterator->second);
	flock->finalize_();
	++_iterator;
	return result;
}

class Herd : public Mutable, public Me
{
	class Hash
	{
	public:
		inline size_t operator()(const Ptr& ptr) const
		{
			return ptr->hash_();
		}
	};

	class Pred
	{
	public:
		inline const bool operator()(const Ptr& lhs, const Ptr& rhs) const
		{
			return lhs->same_(*rhs);
		}
	};

	typedef std::unordered_set<Ptr, Hash, Pred> std_unordered_set_ptr;

public:
	virtual inline const Ptr copy_() const override
	{
		const Ptr result = mut_();
		static_cast<Herd*>(result.get())->_set = _set;
		return result;
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_cast<Index*>(pub.get());
			index->update_("mut", Static::fin_(&Herd::mut));
			index->update_("find", Const<Herd>::fin_(&Herd::find));
			index->update_("insert", Member<Herd>::fin_(&Herd::insert));
			index->update_("iterator", Const<Herd>::fin_(&Herd::iterator));
			index->update_("gather", Member<Herd>::fin_(&Herd::gather));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline const Ptr mut_()
	{
		return me_<Herd>(new Herd);
	}

	static inline const Ptr mut(const Ptr ignore)
	{
		return mut_();
	}

	inline const Ptr find(const Ptr it) const
	{
		const std_unordered_set_ptr::const_iterator sit = _set.find(it->next_());
		if (sit == _set.end())
		{
			return nothing_();
		}
		return *sit;
	}

	inline const Ptr insert(const Ptr it)
	{
		return boolean_(_set.insert(it->next_()).second);
	}

	inline const Ptr insert_(const char* const key)
	{
		return insert(sym_(key));
	}

	inline const Ptr iterator_() const
	{
		return It::mut_(me_());
	}

	inline const Ptr iterator(const Ptr ignore) const
	{
		return iterator_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Herd");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_cast<Herd*>(cats.get());
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Iterable");
			herd->insert_("strange::Herd");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual const Ptr visit(const Ptr it) override
	{
		const Ptr visitor = it->next_();
		const Ptr member = it->next_();
		if (visitor->call_(member, it->next_())->is_("0"))
		{
			return visitor;
		}
		for (auto visited : _set)
		{
			visited->call_("visit", visitor, member, visited);
		}
		return visitor;
	}

	inline const Ptr gather(const Ptr it)
	{
		const Ptr visited = it->next_();
		return visited->call_("visit", me_(), "insert", visited);
	}

private:
	Herd() = default;

	std_unordered_set_ptr _set;

	class It : public Mutable
	{
	public:
		virtual inline const Ptr next_() override
		{
			if (_iterator == static_cast<Herd*>(_herd.get())->_set.cend())
			{
				return end_();
			}
			return *_iterator++;
		}

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_herd);
			static_cast<It*>(result.get())->_iterator = _iterator;
			return result;
		}

		static inline const Ptr mut_(const Ptr herd)
		{
			return Ptr(new It(herd));
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Herd::It");
			return TYPE;
		}

		virtual inline const Ptr cats_() const override
		{
			static const Ptr CATS = []()
			{
				const Ptr cats = Herd::mut_();
				Herd* const herd = static_cast<Herd*>(cats.get());
				herd->insert_("strange::Mutable");
				herd->insert_("strange::Iterator");
				herd->insert_("strange::Thing");
				herd->finalize_();
				return cats;
			}();
			return CATS;
		}

	private:
		inline It(const Ptr herd)
			: Mutable()
			, _herd(herd)
			, _iterator(static_cast<Herd*>(_herd.get())->_set.begin())
		{
		}

		const Ptr _herd;
		std_unordered_set_ptr::const_iterator _iterator;
	};
};

template<typename D>
class Data : public Mutable
{
public:
	static inline const Ptr mut_(const D& data = D())
	{
		return Ptr(new Data(data));
	}

	static inline const Ptr buf(const Ptr it)
	{
		const Ptr ptr = mut_();
		ptr->from_buffer_(it->next());
		return ptr;
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(_data);
	}

	inline void set_(const D& data)
	{
		_data = data;
	}

	inline const D& get_() const
	{
		return _data;
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Data");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_cast<Herd*>(cats.get());
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Data");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

private:
	Data(const D& data)
		: Mutable()
		, _data(data)
	{
	}

	D _data;
};

class Buffer : public Data<std::string>
{
public:
	virtual inline const Ptr to_buffer_() const override
	{
		const Ptr buffer = copy_();
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
		if (!buf)
		{
			log_("Buffer::from_buffer_ called with wrong type of thing");
			return;
		}
		set_(buf->get_());
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Buffer");
		return TYPE;
	}
};

inline const Thing::Ptr Thing::to_buffer_() const
{
	const Ptr buffer = Buffer::mut_(std::string());
	if (finalized_())
	{
		buffer->finalize_();
	}
	return buffer;
}

inline void Thing::from_buffer_(const Thing::Ptr buffer)
{
	Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
	if (!buf)
	{
		log_("Thing::from_buffer_ called with wrong type of thing");
		return;
	}
	if (buf->finalized_())
	{
		finalize_();
	}
}

inline const Thing::Ptr Symbol::buf(const Thing::Ptr it)
{
	const Ptr buffer = it->next_();
	Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
	if (!buf)
	{
		log_("Symbol::buf called with wrong type of thing");
		return nothing_();
	}
	return fin_(buf->get_().c_str());
}

inline const Thing::Ptr Symbol::to_buffer_() const
{
	const Ptr buffer = Buffer::mut_(std::string(_symbol));
	buffer->finalize_();
	return buffer;
}

class Bit : public Data<bool>
{
public:
	static inline const Ptr mut(const Ptr it)
	{
		return mut_(!it->next_()->is_("0"));
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_cast<Index*>(pub.get());
			index->update_("mut", Static::fin_(&Bit::mut));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	virtual inline const Ptr to_buffer_() const override
	{
		const Ptr buffer = Buffer::mut_(std::string(1, get_() ? char(1) : char(0)));
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
		if (!buf)
		{
			log_("Bit::from_buffer_ called with wrong type of thing");
			return;
		}
		set_(buf->get_() != "0");
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Bit");
		return TYPE;
	}
};

class Byte : public Data<unsigned char>
{
public:
	virtual inline const Ptr to_buffer_() const override
	{
		const Ptr buffer = Buffer::mut_(std::string(1, *reinterpret_cast<const char*>(&get_())));
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
		if (!buf)
		{
			log_("Byte::from_buffer_ called with wrong type of thing");
			return;
		}
		set_(*reinterpret_cast<const unsigned char*>(&(buf->get_()[0])));
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Byte");
		return TYPE;
	}
};

class Int16 : public Data<int16_t>
{
public:
	virtual inline const Ptr to_buffer_() const override
	{
		std::string str(2, 0);
		str[0] = get_() & 0xFF;
		str[1] = (get_() >> 8) & 0xFF;
		const Ptr buffer = Buffer::mut_(str);
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
		if (!buf)
		{
			log_("Int16::from_buffer_ called with wrong type of thing");
			return;
		}
		set_(
			uint16_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[0]))) |
			uint16_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[1]))) << 8
			);
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Int16");
		return TYPE;
	}
};

class Int32 : public Data<int32_t>
{
public:
	virtual inline const Ptr to_buffer_() const override
	{
		std::string str(4, 0);
		str[0] = get_() & 0xFF;
		str[1] = (get_() >> 8) & 0xFF;
		str[2] = (get_() >> 16) & 0xFF;
		str[3] = (get_() >> 24) & 0xFF;
		const Ptr buffer = Buffer::mut_(str);
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
		if (!buf)
		{
			log_("Int32::from_buffer_ called with wrong type of thing");
			return;
		}
		set_(
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[0]))) |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[1]))) << 8 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[2]))) << 16 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[3]))) << 24
			);
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Int32");
		return TYPE;
	}
};

class Int64 : public Data<int64_t>
{
public:
	virtual inline const Ptr to_buffer_() const override
	{
		std::string str(8, 0);
		str[0] = get_() & 0xFF;
		str[1] = (get_() >> 8) & 0xFF;
		str[2] = (get_() >> 16) & 0xFF;
		str[3] = (get_() >> 24) & 0xFF;
		str[4] = (get_() >> 32) & 0xFF;
		str[5] = (get_() >> 40) & 0xFF;
		str[6] = (get_() >> 48) & 0xFF;
		str[7] = (get_() >> 56) & 0xFF;
		const Ptr buffer = Buffer::mut_(str);
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
		if (!buf)
		{
			log_("Int64::from_buffer_ called with wrong type of thing");
			return;
		}
		set_(
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[0]))) |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[1]))) << 8 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[2]))) << 16 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[3]))) << 24 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[4]))) << 32 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[5]))) << 40 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[6]))) << 48 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[7]))) << 56
			);
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Int64");
		return TYPE;
	}
};

class Float32 : public Data<float>
{
public:
	virtual inline const Ptr to_buffer_() const override
	{
		std::string str(4, 0);
		uint32_t i = *reinterpret_cast<const uint32_t*>(&get_());
		str[0] = i & 0xFF;
		str[1] = (i >> 8) & 0xFF;
		str[2] = (i >> 16) & 0xFF;
		str[3] = (i >> 24) & 0xFF;
		const Ptr buffer = Buffer::mut_(str);
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
		if (!buf)
		{
			log_("Float32::from_buffer_ called with wrong type of thing");
			return;
		}
		const uint32_t i =
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[0]))) |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[1]))) << 8 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[2]))) << 16 |
			uint32_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[3]))) << 24;
		set_(*reinterpret_cast<const float*>(&i));
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Float32");
		return TYPE;
	}
};

class Float64 : public Data<double>
{
public:
	virtual inline const Ptr to_buffer_() const override
	{
		std::string str(8, 0);
		uint64_t i = *reinterpret_cast<const uint64_t*>(&get_());
		str[0] = i & 0xFF;
		str[1] = (i >> 8) & 0xFF;
		str[2] = (i >> 16) & 0xFF;
		str[3] = (i >> 24) & 0xFF;
		str[4] = (i >> 32) & 0xFF;
		str[5] = (i >> 40) & 0xFF;
		str[6] = (i >> 48) & 0xFF;
		str[7] = (i >> 56) & 0xFF;
		const Ptr buffer = Buffer::mut_(str);
		if (finalized_())
		{
			buffer->finalize_();
		}
		return buffer;
	}

	virtual inline void from_buffer_(const Ptr buffer) override
	{
		Buffer* const buf = dynamic_cast<Buffer*>(buffer.get());
		if (!buf)
		{
			log_("Float64::from_buffer_ called with wrong type of thing");
			return;
		}
		const uint64_t i =
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[0]))) |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[1]))) << 8 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[2]))) << 16 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[3]))) << 24 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[4]))) << 32 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[5]))) << 40 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[6]))) << 48 |
			uint64_t(*reinterpret_cast<const unsigned char*>(&(buf->get_()[7]))) << 56;
		set_(*reinterpret_cast<const double*>(&i));
		if (buf->finalized_())
		{
			finalize_();
		}
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Float64");
		return TYPE;
	}
};

class Fence : public Mutable
{
public:
	static inline const Ptr mut(const Ptr it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr ptr)
	{
		return Ptr(new Fence(ptr));
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(_ptr);
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Index* const index = static_cast<Index*>(pub.get());
			index->update_("mut", Static::fin_(&Fence::mut));
			index->update_("give", Member<Fence>::fin_(&Fence::give));
			index->update_("take", Member<Fence>::fin_(&Fence::take));
			index->finalize_();
			return pub;
		}();
		return PUB;
	}

	inline const bool give_(const Ptr ptr)
	{
		if (_fence.load(std::memory_order_acquire))
		{
			return false;
		}
		_ptr = ptr;
		_fence.store(true, std::memory_order_release);
		return true;
	}

	inline const Ptr give(const Ptr it)
	{
		return boolean_(give_(it->next_()));
	}

	inline const Ptr take_()
	{
		if (_fence.load(std::memory_order_acquire))
		{
			_fence.store(false, std::memory_order_release);
			return _ptr;
		}
		return nothing_();
	}

	inline const Ptr take(const Ptr ignore)
	{
		return take_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Bit");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_cast<Herd*>(cats.get());
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Concurrent");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

private:
	inline Fence(const Ptr ptr)
		: Mutable()
		, _fence()
		, _ptr(ptr)
	{
		_fence.store(false, std::memory_order_release);
	}

	std::atomic<bool> _fence;
	Ptr _ptr;
};

class Stream : public Mutable, public Me
{
	typedef const std::unique_ptr<std::iostream> const_std_unique_iostream;

public:

private:
	Stream(std::iostream* const stream)
		: Mutable()
		, _stream(stream)
	{
	}

	const_std_unique_iostream _stream;
};

inline const Thing::Ptr Thing::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		cats->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Symbol::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_cast<Herd*>(cats.get());
		herd->insert_("strange::Final");
		herd->insert_("strange::Symbol");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Index::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_cast<Herd*>(cats.get());
		herd->insert_("strange::Mutable");
		herd->insert_("strange::Iterable");
		herd->insert_("strange::Index");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Index::It::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_cast<Herd*>(cats.get());
		herd->insert_("strange::Mutable");
		herd->insert_("strange::Iterator");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

template<typename C>
inline const Thing::Ptr Iterator<C>::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_cast<Herd*>(cats.get());
		herd->insert_("strange::Mutable");
		herd->insert_("strange::Iterator");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Flock::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_cast<Herd*>(cats.get());
		herd->insert_("strange::Mutable");
		herd->insert_("strange::Iterable");
		herd->insert_("strange::Flock");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Flock::It::cats_() const
{
	static const Ptr CATS = []()
	{
		const Ptr cats = Herd::mut_();
		Herd* const herd = static_cast<Herd*>(cats.get());
		herd->insert_("strange::Mutable");
		herd->insert_("strange::Iterator");
		herd->insert_("strange::Thing");
		herd->finalize_();
		return cats;
	}();
	return CATS;
}

inline const Thing::Ptr Thing::factory(const Ptr it)
{
	static const Ptr FACTORY = []()
	{
		const Ptr factory = Index::mut_();
		Index* const index = static_cast<Index*>(factory.get());
		index->update_("strange::Index::mut", Static::fin_(&Index::mut));
		index->update_("strange::Flock::mut", Static::fin_(&Flock::mut));
		index->update_("strange::Herd::mut", Static::fin_(&Herd::mut));
		index->finalize_();
		return factory;
	}();
	return FACTORY;
}

} // namespace strange

#endif
