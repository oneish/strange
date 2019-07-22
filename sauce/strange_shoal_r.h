#ifndef COM_ONEISH_STRANGE_SHOAL_R_H
#define COM_ONEISH_STRANGE_SHOAL_R_H

namespace strange
{

template<>
class reflection<shoal_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::shoal");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<collection_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<collection_a<>>::operations();
			operations.update_string("begin", native_mutation_t<shoal_a<>>::val(&shoal_a<>::begin__));
			operations.update_string("end", native_mutation_t<shoal_a<>>::val(&shoal_a<>::end__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___shoal_a_share___
{
	static inline bool ___share___()
	{
		return shoal_a<>::___share___;
	}
};

}

#endif
