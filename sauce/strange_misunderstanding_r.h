#ifndef COM_ONEISH_STRANGE_MISUNDERSTANDING_R_H
#define COM_ONEISH_STRANGE_MISUNDERSTANDING_R_H

namespace strange
{

template<>
class reflection<misunderstanding_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val(1, "strange::misunderstanding");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<any_a<>>::cats();
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
			auto kinds = reflection<any_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update_string("add", native_extraction_t<misunderstanding_a<>>::val(&misunderstanding_a<>::add__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___misunderstanding_a_share___
{
	static inline bool ___share___()
	{
		return misunderstanding_a<>::___share___;
	}
};

template<>
class reflection<misunderstanding_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::misunderstanding");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::misunderstanding::val", native_function_t<>::val(&misunderstanding_t<>::val__));
	}
};

class ___misunderstanding_t_share___
{
	static inline bool ___share___()
	{
		return misunderstanding_t<>::___share___;
	}
};

}

#endif
