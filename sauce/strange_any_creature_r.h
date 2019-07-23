#ifndef COM_ONEISH_STRANGE_ANY_CREATURE_R_H
#define COM_ONEISH_STRANGE_ANY_CREATURE_R_H

namespace strange
{

template<>
class reflection<any_c<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::any_creature");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::any_creature::val", native_function_t<>::val(&any_c<>::val__));
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