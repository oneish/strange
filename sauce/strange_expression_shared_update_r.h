#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_UPDATE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_UPDATE_R_H

namespace strange
{

template<>
class reflection<expression_shared_update_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_shared_update");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_shared_update::val", native_function_t<>::val(&expression_shared_update_t<>::over::val__));
	}
};

}

#endif
