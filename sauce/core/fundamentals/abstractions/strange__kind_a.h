#ifndef COM_ONEISH__STRANGE__KIND_A_H
#define COM_ONEISH__STRANGE__KIND_A_H

namespace strange
{
	struct kind_o :
		symbol_o
	{
		bool (*address) (con<kind_a> const& me);

		behaviour_e (*behaviour) (con<kind_a> const& me);

		var<cat_a> (*the_cat) (con<kind_a> const& me);

		var<type_a> (*the_type) (con<kind_a> const& me);

		// constant					#<any>						address of constant					&#
		// variable					=<any>						address of variable					&=
		// pointer					@<any>						address of pointer					&@
		// forward_iterator			+<forward_extractor>		address of forward_iterator			&+
		// bidirectional_iterator	-<bidirectional_mutator>	address of bidirectional_iterator	&-
		// random_access_iterator	*<random_access_extractor>	address of random_access_iterator	&*
	};

	struct kind_a
	{
		using operations = kind_o;
		using variations = any_v<kind_a>;
		using creator_fp = var<kind_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
