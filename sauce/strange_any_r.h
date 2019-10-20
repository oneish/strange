#ifndef COM_ONEISH_STRANGE_ANY_R_H
#define COM_ONEISH_STRANGE_ANY_R_H

namespace strange
{

template<>
class reflection<any_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::any");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = unordered_herd_t<>::create_();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = unordered_herd_t<>::create_();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = unordered_shoal_t<>::create_();
			operations.update_string("call", native_mutation_t<any_a<>>::create(&any_a<>::operator[]));
			operations.update_string("perform", native_mutation_t<any_a<>>::create(&any_a<>::operator()));
			operations.update_string("type", native_extraction_t<any_a<>>::create(&any_a<>::type__));
			operations.update_string("shared", native_extraction_t<any_a<>>::create(&any_a<>::shared__));
			operations.update_string("cat", native_extraction_t<any_a<>>::create(&any_a<>::cat__));
			operations.update_string("cats", native_extraction_t<any_a<>>::create(&any_a<>::cats__));
			operations.update_string("kind", native_extraction_t<any_a<>>::create(&any_a<>::kind__));
			operations.update_string("kinds", native_extraction_t<any_a<>>::create(&any_a<>::kinds__));
			operations.update_string("operations", native_extraction_t<any_a<>>::create(&any_a<>::operations__));
			operations.update_string("eater", native_extraction_t<any_a<>>::create(&any_a<>::eater__));
			operations.update_string("feeder", native_extraction_t<any_a<>>::create(&any_a<>::feeder__));
			operations.update_string("visit", native_extraction_t<any_a<>>::create(&any_a<>::visit__));
			operations.update_string("identity", native_extraction_t<any_a<>>::create(&any_a<>::identity__));
			operations.update_string("identical", native_extraction_t<any_a<>>::create(&any_a<>::identical__));
			operations.update_string("nothing", native_extraction_t<any_a<>>::create(&any_a<>::nothing__));
			operations.update_string("something", native_extraction_t<any_a<>>::create(&any_a<>::something__));
			operations.update_string("same", native_extraction_t<any_a<>>::create(&any_a<>::same__));
			operations.update_string("different", native_extraction_t<any_a<>>::create(&any_a<>::different__));
			operations.update_string("hash", native_extraction_t<any_a<>>::create(&any_a<>::hash__));
			operations.update_string("ranged", native_extraction_t<any_a<>>::create(&any_a<>::ranged__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___any_a_share___
{
	static inline bool ___share___()
	{
		return any_a<>::___share___;
	}
};

template<>
class reflection<any_c<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("<strange::any>");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("<strange::any>::animate", native_function_t<>::create(&any_c<>::animate__));
	}
};

class ___any_c_share___
{
	static inline bool ___share___()
	{
		return any_c<>::___share___;
	}
};

}

#endif
