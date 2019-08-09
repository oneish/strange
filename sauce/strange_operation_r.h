#ifndef COM_ONEISH_STRANGE_OPERATION_R_H
#define COM_ONEISH_STRANGE_OPERATION_R_H

namespace strange
{

template<>
class reflection<operation_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val(1, "strange::operation");
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
		static kind_a<> KIND = cat_to_kind(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = cats_to_kinds(cats());
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update_string("pure", native_extraction_t<operation_a<>>::val(&operation_a<>::pure__));
			operations.update_string("literal", native_extraction_t<operation_a<>>::val(&operation_a<>::literal__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___operation_a_share___
{
	static inline bool ___share___()
	{
		return operation_a<>::___share___;
	}
};

}

#endif
