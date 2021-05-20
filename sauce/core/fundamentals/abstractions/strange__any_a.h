#ifndef COM_ONEISH__STRANGE__ANY_A_H
#define COM_ONEISH__STRANGE__ANY_A_H

namespace strange
{
	struct any_o
	{
		var<symbol_a> (*cat)(void const* const me_ /* :<any># */);

		void (*_free)(void* const me_ /* :<any># */);

		void (*_copy)(void const* const me_ /* :<any># */,
			void* const copy_ /* :<any>= */);

		bool (*is)(void const* const me_ /* :<any># */,
			void const* const abstraction_ /* :<any># */);

		bool (*as)(void const* const me_ /* :<any># */,
			void* const abstraction_ /* :<any>= */);

		void (*_as)(void const* const me_ /* :<any># */,
			void* const abstraction_ /* :<any>= */);

		var<symbol_a> (*type)(void const* const me_ /* :<any># */);

		void (*_set_pointer)(void* const me_ /* :<any>= */,
			bool is_pointer /* :_bool_# */ );

		bool (*_pointer)(void const* const me_ /* :<any># */);

		void (*set_something)(void* const me_ /* :<any>= */,
			bool is_something /* :_bool_# */);

		bool (*something)(void const* const me_ /* :<any># */);

		void (*set_error)(void* const me_ /* :<any>= */,
			void const* const error_ /* :<any># */);

		var<any_a> (*error)(void const* const me_ /* :<any># */);

		uint64_t (*hash)(void const* const me_ /* :<any># */);

		bool (*equal)(void const* const me_ /* :<any># */,
			void const* const other /* :<any># */);

		bool (*_equal)(void const* const me_ /* :<any># */,
			void const* const other /* :<any># */);

		bool (*not_equal)(void const* const me_ /* :<any># */,
			void const* const other /* :<any># */);

		bool (*_not_equal)(void const* const me_ /* :<any># */,
			void const* const other /* :<any># */);

		bool (*less)(void const* const me_ /* :<any># */,
			void const* const other /* :<any># */);

		bool (*_less)(void const* const me_ /* :<any># */,
			void const* const other /* :<any># */);

		bool (*greater)(void const* const me_ /* :<any># */,
			void const* const other /* :<any># */);

		bool (*_greater)(void const* const me_ /* :<any># */,
			void const* const other /* :<any># */);

		bool (*less_or_equal)(void const* const me_ /* :<any># */,
			void const* const other /* :<any># */);

		bool (*_less_or_equal)(void const* const me_ /* :<any># */,
			void const* const other /* :<any># */);

		bool (*greater_or_equal)(void const* const me_ /* :<any># */,
			void const* const other /* :<any># */);

		bool (*_greater_or_equal)(void const* const me_ /* :<any># */,
			void const* const other /* :<any># */);
	};

	struct any_a
	{
		thing_t* t;
		any_o const* o;

		static var<symbol_a> cat_e(void const* const me_ /* :<any># */);
	};
}

#endif
