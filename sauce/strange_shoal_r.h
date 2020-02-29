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
		static cat_a<> CAT = cat_t<>::create(1, "strange::shoal");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<collection_a<>>::cats();
			cats.insert_thing(cat());
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
			auto kinds = reflection<collection_a<>>::kinds();
			kinds.insert_thing(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<collection_a<>>::operations();
			operations.update_string("begin_", native_mutation_t<shoal_a<>>::create(&shoal_a<>::begin__));
			operations.update_string("end_", native_mutation_t<shoal_a<>>::create(&shoal_a<>::end__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
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
