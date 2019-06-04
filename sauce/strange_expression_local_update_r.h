#ifndef COM_ONEISH_STRANGE_EXPRESSION_LOCAL_UPDATE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_LOCAL_UPDATE_R_H

namespace strange
{

template<>
class reflection<expression_local_update_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_local_update");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update("strange::expression_local_update::val", native_function_t<>::val(&expression_local_update_t<>::val__));
	}
};

}

#endif
