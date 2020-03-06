#ifndef COM_ONEISH_STRANGE_EXPRESSION_ABSTRACTION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_ABSTRACTION_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_abstraction_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_abstraction_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_abstraction::create not passed any terms");
		}
		auto const scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_abstraction::create passed non-symbol scope");
		}
		auto dimension_names = flock_t<>::create_();
		auto dimension_kinds = flock_t<>::create_();
		auto dimension_expressions = flock_t<>::create_();
		auto dimension_defaults = flock_t<>::create_();
		auto parent_expressions = flock_t<>::create_();
		bool end = ++it == terms.cend_();
		while (!end)
		{
			auto const& term = *it;
			end = ++it == terms.cend_();
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_abstraction::create passed non-expression term");
			}
			if (end) // parents
			{
				if (!term.type_().is("strange::expression_block"))
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed non-block last term");
				}
				auto const subterms = cast<expression_a<>>(term).terms_();
				if (subterms.empty())
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed no subterms");
				}
				for (auto const& subterm : subterms)
				{
					if (!check<expression_a<>>(subterm))
					{
						throw dis(token.report() + "strange::expression_abstraction::create passed non-expression subterm");
					}
					parent_expressions.push_back(subterm);
				}
				break;
			}
			// dimensions
			if (!term.type_().is("strange::expression_local_at") &&
				!term.type_().is("strange::expression_local_insert"))
			{
				throw dis(token.report() + "strange::expression_abstraction::create passed invalid dimension term");
			}
			auto const subterms = cast<expression_a<>>(term).terms_();
			int64_t const count = subterms.size();
			auto const name = subterms.at_index(0);
			if (!check<symbol_a<>>(name))
			{
				throw dis(token.report() + "strange::expression_abstraction::create passed non-symbol dimension name");
			}
			if (cast<symbol_a<>>(name).first_character() != '#')
			{
				throw dis(token.report() + "strange::expression_abstraction::create passed dimension name without # preceding it");
			}
			dimension_names.push_back(name);
			if (count == 1)
			{
				dimension_kinds.push_back(kind_t<>::create_());
			}
			else
			{
				auto const kind = subterms.at_index(1);
				if (!check<kind_a<>>(kind) && !check<expression_a<>>(kind))
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed non-kind/expression dimension kind");
				}
				dimension_kinds.push_back(kind);
			}
			any_a<> expression;
			if (count == 3)
			{
				expression = subterms.at_index(2);
				if (!check<expression_a<>>(expression))
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed non-expression dimension default");
				}
			}
			else
			{
				expression = expression_t<>::create(token);
			}
			dimension_expressions.push_back(expression);
			try
			{
				dimension_defaults.push_back(cast<expression_a<>>(expression).evaluate_());
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis("strange::expression_abstraction::create parameter default evaluation error:") + token.report_() + misunderstanding;
			}
		}
		return expression_substitute_t<over>::create(over{ expression_abstraction_t<>(token, terms, cast<symbol_a<>>(scope), dimension_names, dimension_kinds, dimension_expressions, dimension_defaults, parent_expressions) },
			abstraction_t<>::create_(token, cast<symbol_a<>>(scope), dimension_names, dimension_kinds, dimension_defaults, parent_expressions));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_abstraction");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_abstraction::create", native_function_create(&expression_abstraction_t<>::over::create__));
		shoal.update_string("abstraction!", native_function_create(&expression_abstraction_t<>::over::create__));
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string(" abstraction(");
		auto nit = _dimension_names.extract_vector().cbegin();
		auto kit = _dimension_kinds.extract_vector().cbegin();
		auto eit = _dimension_expressions.extract_vector().cbegin();
		bool first = true;
		for (auto const& def : _dimension_defaults.extract_vector())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			auto const name = cast<symbol_a<>>(*nit++);
			auto const kind = *kit++;
			auto const expression = cast<expression_a<>>(*eit++);
			river.write_string(name.to_string() + ":");
			if (check<kind_a<>>(kind))
			{
				river.write_string(cast<kind_a<>>(kind).to_string() + "=");
			}
			else
			{
				cast<expression_a<>>(kind).generate(version, indent, river);
			}
			expression.generate(version, indent, river);
		}
		river.write_string(")\n");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const //TODO
	{
		if (declare || define)
		{
			_declare_or_define_(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp called for wrong type of expression");
		}
		river.write_string(" [](");
		auto nit = _dimension_names.extract_vector().cbegin();
		auto kit = _dimension_kinds.extract_vector().cbegin();
		auto eit = _dimension_expressions.extract_vector().cbegin();
		bool first = true;
		for (auto const& def : _dimension_defaults.extract_vector())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			auto const name = cast<symbol_a<>>(*nit++);
			auto const kind = *kit++;
			auto const expression = cast<expression_a<>>(*eit++);
			if (check<kind_a<>>(kind))
			{
				river.write_string("catch(" + cast<kind_a<>>(kind).code() + " const& ");
				river.write_string(cast<kind_a<>>(kind).to_string() + " =");
			}
			else
			{
				cast<expression_a<>>(kind).generate_cpp(version, indent, river, declare, define);
			}
			expression.generate_cpp(version, indent, river, declare, define);
		}
		river.write_string(")\n{\n");
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _scope;
	flock_a<> const _dimension_names;
	flock_a<> const _dimension_kinds;
	flock_a<> const _dimension_expressions;
	flock_a<> const _dimension_defaults;
	flock_a<> const _parent_expressions;

	inline expression_abstraction_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& scope, flock_a<> const& dimension_names, flock_a<> const& dimension_kinds, flock_a<> const& dimension_expressions, flock_a<> const& dimension_defaults, flock_a<> const& parent_expressions)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
		, _terms{ terms }
		, _scope{ scope }
		, _dimension_names{ dimension_names }
		, _dimension_kinds{ dimension_kinds }
		, _dimension_expressions{ dimension_expressions }
		, _dimension_defaults{ dimension_defaults }
		, _parent_expressions{ parent_expressions }
	{}

	inline void _declare_or_define_(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define) const
	{
		river.write_string("\n");
		flock_a<> split_scope = _split_scope_();
		auto const name = _namespace_open_(split_scope, river);
		std::string const name_string = name.to_string();
		std::string const class_name =
			((name.first_character() == '<' && name.last_character() == '>')
				? name_string.substr(1, name_string.length() - 2)
				: name_string)
			+ "_a";
		bool const root = _parent_expressions.size() <= 1;
		std::string base_name;
		std::string dynamic_name;
		if (!root)
		{
			base_name = _class_base_name_(version);
			if (define)
			{
				_declare_or_define_template_(version, indent, river, true, false);
				dynamic_name = class_name;
				dynamic_name[dynamic_name.length() - 1] = 'd';
				river.write_string(
					"class " + dynamic_name + ";\n\n");
				_declare_or_define_template_(version, indent, river, true, false);
				river.write_string(
					"inline " + dynamic_name);
				_declare_or_define_template_(version, indent, river, false, false);
				river.write_string(" ___" + dynamic_name + "ynamic___(any_a<> const& thing); \n\n");
			}
		}
		_declare_or_define_template_(version, indent, river, declare, define);
		_declare_or_define_class_(root, class_name, base_name, version, indent, river, declare, define);
		if (define)
		{
			_define_class_share_(class_name, version, river);
			if (!root)
			{
				_define_class_dynamic_(class_name, base_name, version, river);
				_declare_or_define_template_(version, indent, river, false, true);
				river.write_string(
					"inline " + dynamic_name);
				_declare_or_define_template_(version, indent, river, false, false);
				river.write_string(" ___" + dynamic_name + "ynamic___(any_a<> const& thing)\n"
					"{\n"
					"\treturn " + dynamic_name);
				_declare_or_define_template_(version, 0, river, false, false);
				river.write_string("{ thing };\n"
					"}\n\n");
			}
		}
		_namespace_close_(split_scope, river);
	}

	inline flock_a<> _split_scope_() const
	{
		auto split_scope = flock_t<>::create_();
		std::string const scope = _scope.to_string();
		std::size_t begin = 0;
		std::size_t pos = scope.find("::", begin);
		int64_t nest = 1;
		while (pos != std::string::npos)
		{
			split_scope.push_back(sym(scope.substr(begin, pos)));
			++nest;
			begin = pos + 2;
			pos = scope.find("::", begin);
		}
		split_scope.push_back(sym(scope.substr(begin)));
		return split_scope;
	}

	static inline symbol_a<> _namespace_open_(flock_a<> const& split_scope, river_a<>& river)
	{
		symbol_a<> name;
		for (auto const& scope_name : split_scope)
		{
			if (check<any_a<>>(name))
			{
				river.write_string(
					"namespace " + name.to_string() + "\n"
					"{\n\n");
			}
			name = cast<symbol_a<>>(scope_name);
		}
		return name;
	}

	static inline void _namespace_close_(flock_a<> const& split_scope, river_a<>& river)
	{
		int64_t nest = split_scope.size();
		while (--nest)
		{
			river.write_string("} // namespace\n");
		}
	}

	inline void _declare_or_define_template_(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define) const
	{
		if (declare)
		{
			river.write_string("template <");
			if (_dimension_names.empty())
			{
				river.write_string("typename _1_ = void");
			}
			else
			{
				bool first = true;
				auto kit = _dimension_kinds.extract_vector().cbegin();
				auto eit = _dimension_expressions.extract_vector().cbegin();
				for (auto const& name : _dimension_names.extract_vector())
				{
					if (first)
					{
						first = false;
					}
					else
					{
						river.write_string(", ");
					}
					river.write_string("typename " + cast<symbol_a<>>(name).to_string().substr(1));

					auto any_kind = *kit++;
					if (check<expression_a<>>(any_kind))
					{
						try
						{
							any_kind = cast<expression_a<>>(any_kind).evaluate_();
						}
						catch (misunderstanding_a<>& misunderstanding)
						{
							throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp kind expression evaluation error") + misunderstanding;
						}
					}
					if (!check<kind_a<>>(any_kind))
					{
						throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp non-kind dimension kind");
					}
					auto const kind = cast<kind_a<>>(any_kind);

					auto const expression = *eit++;
					if (kind.optional())
					{
						river.write_string(" =");
						cast<expression_a<>>(expression).generate_cpp(version, indent, river, false, false, true); // declare, define, type
					}
				}
			}
			river.write_string(">\n");
		}
		else if (define)
		{
			river.write_string("template <");
			if (_dimension_names.empty())
			{
				river.write_string("typename _1_");
			}
			else
			{
				bool first = true;
				for (auto const& name : _dimension_names.extract_vector())
				{
					if (first)
					{
						first = false;
					}
					else
					{
						river.write_string(", ");
					}
					river.write_string("typename " + cast<symbol_a<>>(name).to_string().substr(1));
				}
			}
			river.write_string(">\n");
		}
		else
		{
			river.write_string("<");
			if (_dimension_names.empty())
			{
				river.write_string("_1_");
			}
			else
			{
				bool first = true;
				for (auto const& name : _dimension_names.extract_vector())
				{
					if (first)
					{
						first = false;
					}
					else
					{
						river.write_string(", ");
					}
					river.write_string(cast<symbol_a<>>(name).to_string().substr(1));
				}
			}
			river.write_string(">");
		}
	}

	inline void _declare_or_define_class_(bool root, std::string const& class_name, std::string const& base_name, int64_t version, int64_t indent, river_a<>& river, bool declare, bool define) const
	{
		if (declare)
		{
			river.write_string("class " + class_name + ";\n\n");
		}
		else if (define)
		{
			_define_class_(root, class_name, base_name, version, indent, river, declare, define);
		}
	}

	inline void _define_class_dynamic_(std::string class_name, std::string base_name, int64_t version, river_a<>& river) const
	{
		_declare_or_define_template_(version, 0, river, false, true);
		class_name[class_name.length() - 1] = 'd';
		if (base_name != "any_a")
		{
			base_name[base_name.length() - 1] = 'd';
		}
		river.write_string(
			"class " + class_name + " : public " + base_name + "<>\n"
			"{\n");
		_define_class_boilerplate_(false, class_name, version, 0, river);
		auto const class_expression_terms = _class_expression_terms_();
		_define_class_dynamic_members_(false, class_name, class_expression_terms, version, 0, river);
		river.write_string(
			"\tvoid ___weak___(" + base_name + "<>::___WEAK___ const& weak) const {}\n\n"

			"\texplicit " + class_name + "(any_a<> const& thing)\n"
			"\t\t: " + base_name + "<>{ thing }\n"
			"\t{}\n\n"

			"\texplicit " + class_name + "(any_a<>& thing, ___reference_tag___)\n"
			"\t\t: " + base_name + "<>{ thing, ___reference_tag___{} }\n"
			"\t{}\n\n"

			"\texplicit " + class_name + "(any_a<>& thing, ___duplicate_tag___)\n"
			"\t\t: " + base_name + "<>{ thing, ___duplicate_tag___{} }\n"
			"\t{}\n"
			"};\n\n"		
		);
	}

	inline void _define_class_(bool root, std::string const& class_name, std::string const& base_name, int64_t version, int64_t indent, river_a<>& river, bool declare, bool define) const
	{
		river.write_string(
			"class " + class_name);
		if (!root)
		{
			river.write_string(" : public " + base_name + "<>");
		}
		river.write_string("\n"
			"{\n");
		_define_class_boilerplate_(root, class_name, version, indent, river);
		auto const class_expression_terms = _class_expression_terms_();
		_define_class_nonvirtual_members_(root, class_name, class_expression_terms, version, indent, river);
		_define_class_handle_(root, class_name, base_name, class_expression_terms, version, indent, river);
		_define_class_implementation_(root, class_name, base_name, class_expression_terms, version, indent, river);
		river.write_string("}; // class " + class_name +"\n\n");
	}

	inline std::string _class_base_name_(int64_t version) const
	{
		auto const expression = _parent_expressions.at_index(0);
		if (expression.type_() != expression_operate_t<>::type_())
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp non-expression-operate base class definition");
		}
		auto const terms = cast<expression_a<>>(expression).terms_();
		if (terms.size() < 1)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp expression-operate base class definition with too few terms");
		}
		auto abs = river_t<>::create();
		cast<expression_a<>>(terms.at_index(0)).generate_cpp(version, 0, abs, false, false);
		abs.seekg_beg(0);
		auto exp = parser_t<>::create_().parse_(tokenizer_t<>::create_(abs));
		auto river = river_t<>::create();
		exp.generate_cpp(version, 0, river, false, false, true);
		std::string str = river.to_string();
		return str.substr(1, str.length() - 4);
	}

	inline flock_a<> _class_expression_terms_() const
	{
		if (_parent_expressions.empty())
		{
			return flock_t<>::create_();
		}
		auto const expression = _parent_expressions.at_index(_parent_expressions.size() - 1);
		if (!check<expression_a<>>(expression))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp non-expression class definition");
		}
		return cast<expression_a<>>(expression).terms_();
	}

	static inline void _define_class_boilerplate_(bool root, std::string const& class_name, int64_t version, int64_t indent, river_a<>& river)
	{
		if (root)
		{
			river.write_string(
				"protected:\n"
				"\tstruct ___" + class_name + "_handle_base___;\n\n"

				"public:\n"
				"\t// constructor tags\n"
				"\tstruct ___reference_tag___ {};\n"
				"\tstruct ___duplicate_tag___ {};\n\n"
				"\tstruct ___variadic_tag___ {};\n\n"

				"\t// shared pointer typedefs\n"
				"\tusing ___WEAK___ = std::weak_ptr<___" + class_name + "_handle_base___>;\n"
				"\tusing ___SHARED___ = std::shared_ptr<___" + class_name + "_handle_base___>;\n\n"

				"\t// operator overloads\n"
				"\tinline " + class_name + "<> operator[](range const& arguments)\n"
				"\t{\n"
				"\t\treturn invoke(*this, arguments);\n"
				"\t}\n\n"

				"\tinline " + class_name + "<> operator()(range const& arguments)\n"
				"\t{\n"
				"\t\treturn operate(*this, arguments);\n"
				"\t}\n\n"

				"\tinline operator bool() const\n"
				"\t{\n"
				"\t\tassert(___handle___);\n"
				"\t\treturn ___read___().operator bool();\n"
				"\t}\n\n"

				"\t// trigger copy on write\n"
				"\tvoid mutate()\n"
				"\t{\n"
				"\t\tassert(___handle___);\n"
				"\t\t___write___();\n"
				"\t}\n\n");
		}
		else
		{
			river.write_string(
				"public:\n");
		}
		river.write_string(
			"\t// arithmetic operator overloads\n"
			"\tinline " + class_name + "& operator++()\n"
			"\t{\n"
			"\t\tassert(___handle___);\n"
			"\t\t___write___().operator++();\n"
			"\t\treturn *this;\n"
			"\t}\n\n"

			"#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS\n"
			"\tinline " + class_name + " operator++(int)\n"
			"\t{\n"
			"\t\tassert(___handle___);\n"
			"\t\t" + class_name + " result = *this;\n"
			"\t\t___write___().operator++();\n"
			"\t\treturn result;\n"
			"\t}\n"
			"#endif\n\n"

			"\tinline " + class_name + "& operator--()\n"
			"\t{\n"
			"\t\tassert(___handle___);\n"
			"\t\t___write___().operator--();\n"
			"\t\treturn *this;\n"
			"\t}\n\n"

			"#ifdef STRANGE_IMPLEMENT_POST_INCREMENT_AND_DECREMENT_OPERATORS\n"
			"\tinline " + class_name + " operator--(int)\n"
			"\t{\n"
			"\t\tassert(___handle___);\n"
			"\t\t" + class_name + " result = *this;\n"
			"\t\t___write___().operator--();\n"
			"\t\treturn result;\n"
			"\t}\n"
			"#endif\n\n"

			"\tinline " + class_name + "& operator+=(any_a<> const& other)\n"
			"\t{\n"
			"\t\tassert(___handle___);\n"
			"\t\t___write___().operator+=(other);\n"
			"\t\treturn *this;\n"
			"\t}\n\n"

			"\tinline " + class_name + "& operator-=(any_a<> const& other)\n"
			"\t{\n"
			"\t\tassert(___handle___);\n"
			"\t\t___write___().operator-=(other);\n"
			"\t\treturn *this;\n"
			"\t}\n\n"

			"\tinline " + class_name + "& operator*=(any_a<> const& other)\n"
			"\t{\n"
			"\t\tassert(___handle___);\n"
			"\t\t___write___().operator*=(other);\n"
			"\t\treturn *this;\n"
			"\t}\n\n"

			"\tinline " + class_name + "& operator/=(any_a<> const& other)\n"
			"\t{\n"
			"\t\tassert(___handle___);\n"
			"\t\t___write___().operator/=(other);\n"
			"\t\treturn *this;\n"
			"\t}\n\n"

			"\tinline " + class_name + "& operator%=(any_a<> const& other)\n"
			"\t{\n"
			"\t\tassert(___handle___);\n"
			"\t\t___write___().operator%=(other);\n"
			"\t\treturn *this;\n"
			"\t}\n\n");
	}

	using _define_member_p = void (expression_abstraction_t::*)(bool root, std::string const& class_name, std::string const& name, expression_a<> const& expression, bool extraction, int64_t version, river_a<> & river) const;
	using _define_native_member_p = void (expression_abstraction_t::*)(bool root, std::string const& class_name, std::string const& name, std::string const& value, int64_t version, river_a<>& river) const;

	inline void _define_class_members_(bool root, std::string const& class_name, flock_a<> const& class_expression_terms, int64_t version, int64_t indent, river_a<>& river,
		_define_member_p define_member_p,
		_define_native_member_p define_native_member_p) const
	{
		for (auto const& expression : class_expression_terms.extract_vector())
		{
			if (!check<expression_a<>>(expression) || expression.type_() != expression_flock_t<>::type_())
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp non-flock expression pair in class definition");
			}
			auto const pair = cast<expression_a<>>(expression).terms_();
			if (pair.size() != 2)
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp non-pair in class definition");
			}
			auto any_name = pair.at_index(0);
			if (!check<expression_a<>>(any_name) || any_name.type_() != expression_literal_t<>::type_())
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp non-literal expression name in class definition");
			}
			auto const name_flock = cast<expression_a<>>(any_name).terms_();
			if (name_flock.size() != 1)
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp non-single name in class definition");
			}
			any_name = name_flock.at_index(0);
			if (!check<symbol_a<>>(any_name))
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp non-symbol name in class definition");
			}
			auto const name = cast<symbol_a<>>(any_name);

			auto any_value = pair.at_index(1);
			if (!check<expression_a<>>(any_value))
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp non-expression value in class definition");
			}
			auto const value_expression = cast<expression_a<>>(any_value);
			if (name.last_character() == '_')
			{
				//TODO custom reference
				bool const extraction = value_expression.type_() == expression_extraction_t<>::type_();
				if (extraction || value_expression.type_() == expression_mutation_t<>::type_())
				{
					(this->*define_member_p)(root, class_name, name.to_string(), value_expression, extraction, version, river);
				}
				else
				{
					throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp invalid expression value in class definition");
				}
			}
			else if (value_expression.type_() == expression_literal_t<>::type_() && value_expression.terms_().size() == 1)
			{
				auto const value = value_expression.terms_().at_index(0);
				if (check<lake_a<int8_t>>(value))
				{
					(this->*define_native_member_p)(root, class_name, name.to_string(), lake_to_string(cast<lake_a<int8_t>>(value)), version, river);
				}
			}
			else
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp invalid expression pair in class definition");
			}
		}
	}

	inline void _define_class_dynamic_members_(bool root, std::string const& class_name, flock_a<> const& class_expression_terms, int64_t version, int64_t indent, river_a<>& river) const
	{
		_define_class_members_(root, class_name, class_expression_terms, version, indent, river,
			&expression_abstraction_t::_define_class_dynamic_member_,
			&expression_abstraction_t::_define_class_dynamic_native_member_);
	}

	inline void _define_class_dynamic_member_(bool root, std::string const& class_name, std::string const& name, expression_a<> const& expression, bool extraction, int64_t version, river_a<>& river) const
	{
		std::string result;
		std::string parameters;
		std::string arguments;
		std::string constness;
		_parse_member_definition_(version, expression, extraction, result, parameters, arguments, constness);

		river.write_string(
			"\tinline any_a<> " + name + "_(range" +
			(root ? "" : "_a<>") + " const& arguments)" + constness + "\n"
			"\t{\n"
			"\t\tassert(___handle___);\n"
			"\t\tauto const op = operation(\"" + name + "\");\n"
			"\t\tif (!op)\n"
			"\t\t{\n"
			"\t\t\tthrow dis(\"dynamic " + class_name + "::" + name + " passed non-existent member\");\n"
			"\t\t}\n"
			"\t\treturn op.operate(");
		if (constness.empty())
		{
			river.write_string("*this");
		}
		else
		{
			river.write_string("*const_cast<" + class_name + "*>(this)");
		}
		river.write_string(", arguments);\n"
			"\t}\n\n");

		river.write_string(
			"\tinline " + result);
		bool const template_result = result == class_name.substr(0, class_name.length() - 1) + "a";
		if (template_result)
		{
			_declare_or_define_template_(version, 0, river, false, false);
		}
		river.write_string(" " + name + parameters + constness + "\n"
			"\t{\n"
			"\t\tassert(___handle___);\n"
			"\t\tauto const op = operation(\"" + name + "\");\n"
			"\t\tif (!op)\n"
			"\t\t{\n"
			"\t\t\tthrow dis(\"dynamic " + class_name + "::" + name + " passed non-existent member\");\n"
			"\t\t}\n"
			"\t\treturn cast<" + result);
		if (template_result)
		{
			_declare_or_define_template_(version, 0, river, false, false);
		}
		river.write_string(">(variadic_operate(op, ");
		if (constness.empty())
		{
			river.write_string("*this");
		}
		else
		{
			river.write_string("*const_cast<" + class_name + "*>(this)");
		}
		if (arguments.length() > 2)
		{
			river.write_string(", " + arguments.substr(1) + ");\n");
		}
		else
		{
			river.write_string("));\n");
		}
		river.write_string(
			"\t}\n\n");
	}

	inline void _define_class_dynamic_native_member_(bool root, std::string const& class_name, std::string const& name, std::string const& value, int64_t version, river_a<>& river) const
	{
		std::string result;
		std::string parameters;
		std::string arguments;
		std::string constness;
		std::string dynamic;
		_parse_native_member_definition_(class_name, name, value, result, parameters, arguments, constness, dynamic);
		river.write_string(
			"\tinline " + result);
		if (result == class_name.substr(0, class_name.length() - 1) + "a")
		{
			_declare_or_define_template_(version, 0, river, false, false);
		}
		river.write_string(" " + name + parameters + constness + "\n"
			"\t" + dynamic + "\n\n");
	}

	inline void _define_class_nonvirtual_members_(bool root, std::string const& class_name, flock_a<> const& class_expression_terms, int64_t version, int64_t indent, river_a<>& river) const
	{
		_define_class_members_(root, class_name, class_expression_terms, version, indent, river,
			&expression_abstraction_t::_define_class_nonvirtual_member_,
			&expression_abstraction_t::_define_class_nonvirtual_native_member_);
	}

	inline void _define_class_nonvirtual_member_(bool root, std::string const& class_name, std::string const& name, expression_a<> const& expression, bool extraction, int64_t version, river_a<>& river) const
	{
		std::string result;
		std::string parameters;
		std::string arguments;
		std::string constness;
		_parse_member_definition_(version, expression, extraction, result, parameters, arguments, constness);

		river.write_string(
			"\tinline any_a<> " + name + "_(range" +
				(root ? "" : "_a<>") + " const& arguments)" + constness + "\n"
			"\t{ assert(___handle___); return ");
		if (constness.empty())
		{
			river.write_string("___write___().");
		}
		else
		{
			river.write_string("___read___().");
		}
		river.write_string(name + "_(arguments); }\n\n");

		river.write_string(
			"\tinline " + result + " " + name + parameters + constness + "\n"
			"\t{ assert(___handle___); return ");
		if (constness.empty())
		{
			river.write_string("___write___().");
		}
		else
		{
			river.write_string("___read___().");
		}
		river.write_string(name + arguments + "; }\n\n");
	}

	inline void _define_class_nonvirtual_native_member_(bool root, std::string const& class_name, std::string const& name, std::string const& value, int64_t version, river_a<>& river) const
	{
		std::string result;
		std::string parameters;
		std::string arguments;
		std::string constness;
		std::string dynamic;
		_parse_native_member_definition_(class_name, name, value, result, parameters, arguments, constness, dynamic);
		river.write_string(
			"\tinline " + result + " " + name + parameters + constness + "\n"
			"\t{ assert(___handle___); ");
		if (result != "void")
		{
			river.write_string("return ");
		}
		if (constness.empty())
		{
			river.write_string("___write___().");
		}
		else
		{
			river.write_string("___read___().");
		}
		river.write_string(name + arguments + "; }\n\n");
	}

	inline void _define_class_handle_(bool root, std::string const& class_name, std::string const& base_name, flock_a<> const& class_expression_terms, int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(
			"protected:\n"
			"\tstruct ___" + class_name + "_handle_base___");
		if (root)
		{
			river.write_string(
				"\n"
				"\t{\n"
				"\t\t___" + class_name + "_handle_base___() = default;\n"
				"\t\t___" + class_name + "_handle_base___(___" + class_name + "_handle_base___ const&) = default;\n"
				"\t\t___" + class_name + "_handle_base___(___" + class_name + "_handle_base___&&) = default;\n"
				"\t\t___" + class_name + "_handle_base___& operator=(___" + class_name + "_handle_base___ const&) = default;\n"
				"\t\t___" + class_name + "_handle_base___& operator=(___" + class_name + "_handle_base___&&) = default;\n"
				"\t\tvirtual ~___" + class_name + "_handle_base___() = default;\n"
				"\t\tvirtual ___SHARED___ ___clone___() const = 0;\n"
				"\t\tvirtual void ___weak___(___WEAK___ const& weak) const = 0;\n"
				"\t\tvirtual operator bool() const = 0;\n"
				"\t\tvirtual void operator++() = 0;\n"
				"\t\tvirtual void operator--() = 0;\n"
				"\t\tvirtual void operator+=(any_a<> const& other) = 0;\n"
				"\t\tvirtual void operator-=(any_a<> const& other) = 0;\n"
				"\t\tvirtual void operator*=(any_a<> const& other) = 0;\n"
				"\t\tvirtual void operator/=(any_a<> const& other) = 0;\n"
				"\t\tvirtual void operator%=(any_a<> const& other) = 0;\n");
		}
		else
		{
			river.write_string(
				" : ___" + base_name + "_handle_base___\n"
				"\t{\n");
		}
		_define_class_members_(root, class_name, class_expression_terms, version, indent, river,
			&expression_abstraction_t::_define_class_pure_virtual_member_,
			&expression_abstraction_t::_define_class_pure_virtual_native_member_);
		river.write_string(
			"\t};\n\n");

		if (root)
		{
			river.write_string(
				"\ttemplate <typename ___TTT___, typename ___BHB___ = ___" + class_name + "_handle_base___>\n"
				"\tstruct ___" + class_name + "_handle___ : ___BHB___\n"
				"\t{\n"
				"\t\ttemplate <typename ___UUU___ = ___TTT___>\n"
				"\t\tinline ___" + class_name + "_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)\n"
				"\t\t\t: ___value___{ value }\n"
				"\t\t{}\n\n"

				"\t\ttemplate <typename ___UUU___ = ___TTT___>\n"
				"\t\tinline ___" + class_name + "_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept\n"
				"\t\t\t: ___value___{ std::move(value) }\n"
				"\t\t{}\n\n"

				"\t\ttemplate <typename... Args>\n"
				"\t\tinline ___" + class_name + "_handle___(___variadic_tag___, Args&&... args)\n"
				"\t\t\t: ___value___(std::forward<Args>(args)...)\n"
				"\t\t{}\n\n"

				"\t\tvirtual inline void ___weak___(___WEAK___ const& weak) const final\n"
				"\t\t{\n"
				"\t\t\t___value___.___weak___(weak);\n"
				"\t\t}\n\n"

				"\t\tvirtual inline operator bool() const final\n"
				"\t\t{\n"
				"\t\t\treturn ___value___.operator bool();\n"
				"\t\t}\n\n"

				"\t\tvirtual inline void operator++() final\n"
				"\t\t{\n"
				"\t\t\t___value___.operator++();\n"
				"\t\t}\n\n"

				"\t\tvirtual inline void operator--() final\n"
				"\t\t{\n"
				"\t\t\t___value___.operator--();\n"
				"\t\t}\n\n"

				"\t\tvirtual inline void operator+=(any_a<> const& other) final\n"
				"\t\t{\n"
				"\t\t\t___value___.operator+=(other);\n"
				"\t\t}\n\n"

				"\t\tvirtual inline void operator-=(any_a<> const& other) final\n"
				"\t\t{\n"
				"\t\t\t___value___.operator-=(other);\n"
				"\t\t}\n\n"

				"\t\tvirtual inline void operator*=(any_a<> const& other) final\n"
				"\t\t{\n"
				"\t\t\t___value___.operator*=(other);\n"
				"\t\t}\n\n"

				"\t\tvirtual inline void operator/=(any_a<> const& other) final\n"
				"\t\t{\n"
				"\t\t\t___value___.operator/=(other);\n"
				"\t\t}\n\n"

				"\t\tvirtual inline void operator%=(any_a<> const& other) final\n"
				"\t\t{\n"
				"\t\t\t___value___.operator%=(other);\n"
				"\t\t}\n\n");
		}
		else
		{
			river.write_string(
				"\ttemplate <typename ___TTT___, typename ___DHB___ = ___" + class_name + "_handle_base___>\n"
				"\tstruct ___" + class_name + "_handle___ : ___" + base_name + "_handle___<___TTT___, ___DHB___>\n"
				"\t{\n"
				"\t\ttemplate <typename ___UUU___ = ___TTT___>\n"
				"\t\tinline ___" + class_name + "_handle___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)\n"
				"\t\t\t: ___" + base_name + "_handle___<___TTT___, ___DHB___>{ value }\n"
				"\t\t{}\n\n"

				"\t\ttemplate <typename ___UUU___ = ___TTT___>\n"
				"\t\tinline ___" + class_name + "_handle___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept\n"
				"\t\t\t: ___" + base_name + "_handle___<___TTT___, ___DHB___>{ std::move(value) }\n"
				"\t\t{}\n\n"

				"\t\ttemplate <typename... Args>\n"
				"\t\tinline ___" + class_name + "_handle___(___variadic_tag___, Args&&... args)\n"
				"\t\t\t: ___" + base_name + "_handle___<___TTT___, ___DHB___>(___variadic_tag___{}, std::forward<Args>(args)...)\n"
				"\t\t{}\n\n");
		}
		_define_class_members_(root, class_name, class_expression_terms, version, indent, river,
			&expression_abstraction_t::_define_class_virtual_member_,
			&expression_abstraction_t::_define_class_virtual_native_member_);
		if (root)
		{
			river.write_string(
				"\t\t___TTT___ ___value___;\n"
				"\t};\n\n"

				"\ttemplate <typename ___TTT___, typename ___BHB___>\n"
				"\tstruct ___" + class_name + "_handle___<std::reference_wrapper<___TTT___>, ___BHB___>\n"
				"\t\t: ___" + class_name + "_handle___<___TTT___&, ___BHB___>\n"
				"\t{\n"
				"\t\tinline ___" + class_name + "_handle___(std::reference_wrapper<___TTT___> ref)\n"
				"\t\t\t: ___" + class_name + "_handle___<___TTT___&, ___BHB___>{ ref.get() }\n"
				"\t\t{}\n"
				"\t};\n\n"

				"\t___SHARED___ ___shared___;\n\n"

				"public:\n"
				"\t___SHARED___& ___handle___;\n\n"

				"private:\n"
				"\ttemplate <typename ___TTT___>\n"
				"\tstruct ___" + class_name + "_handle_final___ final : ___" + class_name + "_handle___<___TTT___>\n"
				"\t{\n"
				"\t\ttemplate <typename ___UUU___ = ___TTT___>\n"
				"\t\tinline ___" + class_name + "_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)\n"
				"\t\t\t: ___" + class_name + "_handle___<___TTT___>{ value }\n"
				"\t\t{}\n\n"

				"\t\ttemplate <typename ___UUU___ = ___TTT___>\n"
				"\t\tinline ___" + class_name + "_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept\n"
				"\t\t\t: ___" + class_name + "_handle___<___TTT___>{ std::move(value) }\n"
				"\t\t{}\n\n"

				"\t\ttemplate <typename... Args>\n"
				"\t\tinline ___" + class_name + "_handle_final___(___variadic_tag___, Args&&... args)\n"
				"\t\t\t: ___" + class_name + "_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)\n"
				"\t\t{}\n\n"

				"\t\tvirtual inline ___SHARED___ ___clone___() const final\n"
				"\t\t{\n"
				"\t\t\treturn std::make_shared<___" + class_name + "_handle_final___>(___" + class_name + "_handle___<___TTT___>::___value___);\n"
				"\t\t}\n"

				"\t};\n\n"

				"\ttemplate <typename ___TTT___>\n"
				"\tstruct ___" + class_name + "_handle_final___<std::reference_wrapper<___TTT___>> final\n"
				"\t\t: ___" + class_name + "_handle_final___<___TTT___&>\n"
				"\t{\n"
				"\t\tinline ___" + class_name + "_handle_final___(std::reference_wrapper<___TTT___> ref)\n"
				"\t\t\t: ___" + class_name + "_handle_final___<___TTT___&>{ ref.get() }\n"
				"\t\t{}\n"
				"\t};\n\n");
		}
		else
		{
			river.write_string(
				"\t};\n\n"

				"\ttemplate <typename ___TTT___, typename ___DHB___>\n"
				"\tstruct ___" + class_name + "_handle___<std::reference_wrapper<___TTT___>, ___DHB___>\n"
				"\t\t: ___" + class_name + "_handle___<___TTT___&, ___DHB___>\n"
				"\t{\n"
				"\t\tinline ___" + class_name + "_handle___(std::reference_wrapper<___TTT___> ref)\n"
				"\t\t\t: ___" + class_name + "_handle___<___TTT___&, ___DHB___>{ ref.get() }\n"
				"\t\t{}\n"
				"\t};\n\n"

				"private:\n"
				"\ttemplate <typename ___TTT___>\n"
				"\tstruct ___" + class_name + "_handle_final___ final : ___" + class_name + "_handle___<___TTT___>\n"
				"\t{\n"
				"\t\ttemplate <typename ___UUU___ = ___TTT___>\n"
				"\t\tinline ___" + class_name + "_handle_final___(___TTT___ value, typename std::enable_if_t<std::is_reference<___UUU___>::value>* = 0)\n"
				"\t\t\t: ___" + class_name + "_handle___<___TTT___>{ value }\n"
				"\t\t{}\n\n"

				"\t\ttemplate <typename ___UUU___ = ___TTT___>\n"
				"\t\tinline ___" + class_name + "_handle_final___(___TTT___ value, typename std::enable_if_t<!std::is_reference<___UUU___>::value, int>* = 0) noexcept\n"
				"\t\t\t: ___" + class_name + "_handle___<___TTT___>{ std::move(value) }\n"
				"\t\t{}\n\n"

				"\t\ttemplate <typename... Args>\n"
				"\t\tinline ___" + class_name + "_handle_final___(___variadic_tag___, Args&&... args)\n"
				"\t\t\t: ___" + class_name + "_handle___<___TTT___>(___variadic_tag___{}, std::forward<Args>(args)...)\n"
				"\t\t{}\n\n"

				"\t\tvirtual inline ___SHARED___ ___clone___() const final\n"
				"\t\t{\n"
				"\t\t\treturn std::make_shared<___" + class_name + "_handle_final___>(___" + class_name + "_handle___<___TTT___>::___value___);\n"
				"\t\t}\n"
				"\t};\n\n"

				"\ttemplate <typename ___TTT___>\n"
				"\tstruct ___" + class_name + "_handle_final___<std::reference_wrapper<___TTT___>> final\n"
				"\t\t: ___" + class_name + "_handle_final___<___TTT___&>\n"
				"\t{\n"
				"\t\tinline ___" + class_name + "_handle_final___(std::reference_wrapper<___TTT___> ref)\n"
				"\t\t\t: ___" + class_name + "_handle_final___<___TTT___&>{ ref.get() }\n"
				"\t\t{}\n"
				"\t};\n\n");
		}
	}

	inline void _define_class_pure_virtual_member_(bool root, std::string const& class_name, std::string const& name, expression_a<> const& expression, bool extraction, int64_t version, river_a<>& river) const
	{
		std::string result;
		std::string parameters;
		std::string arguments;
		std::string constness;
		_parse_member_definition_(version, expression, extraction, result, parameters, arguments, constness);

		river.write_string(
			"\t\tvirtual any_a<> " + name + "_(range" +
			(root ? "" : "_a<>") + " const& arguments)" + constness + " = 0;\n");
		river.write_string(
			"\t\tvirtual " + result + " " + name + parameters + constness + " = 0;\n");
	}

	inline void _define_class_pure_virtual_native_member_(bool root, std::string const& class_name, std::string const& name, std::string const& value, int64_t version, river_a<>& river) const
	{
		std::string result;
		std::string parameters;
		std::string arguments;
		std::string constness;
		std::string dynamic;
		_parse_native_member_definition_(class_name, name, value, result, parameters, arguments, constness, dynamic);
		river.write_string(
			"\t\tvirtual " + result + " " + name + parameters + constness + " = 0;\n");
	}

	inline void _define_class_virtual_member_(bool root, std::string const& class_name, std::string const& name, expression_a<> const& expression, bool extraction, int64_t version, river_a<>& river) const
	{
		std::string result;
		std::string parameters;
		std::string arguments;
		std::string constness;
		_parse_member_definition_(version, expression, extraction, result, parameters, arguments, constness);
	
		std::string const scope = root ? "" : "___any_a_handle___<___TTT___, ___DHB___>::";

		river.write_string(
			"\t\tvirtual inline any_a<> " + name + "_(range" +
			(root ? "" : "_a<>") + " const& arguments)" + constness + " final\n"
			"\t\t{ return " + scope + "___value___." + name + "_(arguments); }\n\n");

		river.write_string(
			"\t\tvirtual inline " + result + " " + name + parameters + constness + " final\n"
			"\t\t{ return " + scope + "___value___." + name + arguments + "; }\n\n");
	}

	inline void _define_class_virtual_native_member_(bool root, std::string const& class_name, std::string const& name, std::string const& value, int64_t version, river_a<>& river) const
	{
		std::string result;
		std::string parameters;
		std::string arguments;
		std::string constness;
		std::string dynamic;
		_parse_native_member_definition_(class_name, name, value, result, parameters, arguments, constness, dynamic);

		std::string const scope = root ? "" : "___any_a_handle___<___TTT___, ___DHB___>::";

		river.write_string(
			"\t\tvirtual inline " + result + " " + name + parameters + constness + " final\n"
			"\t\t{ ");
		if (result != "void")
		{
			river.write_string("return ");
		}
		river.write_string(scope + "___value___." + name + arguments + "; }\n\n");
	}

	inline void _define_class_implementation_(bool root, std::string const& class_name, std::string const& base_name, flock_a<> const& class_expression_terms, int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(
			"protected:\n"
			"\tinline ___" + class_name + "_handle_base___ const& ___read___() const noexcept\n"
			"\t{\n" + (root
				? std::string{ "\t\treturn *___handle___;\n" }
				: ("\t\treturn *std::static_pointer_cast<___" + class_name + "_handle_base___ const>(___handle___);\n")) +
			"\t}\n\n"

			"\tinline ___" + class_name + "_handle_base___& ___write___() noexcept\n"
			"\t{\n"
			"\t\tif (!___handle___.unique())\n"
			"\t\t{\n"
			"\t\t\t___handle___ = ___handle___->___clone___();\n"
			"\t\t\t___handle___->___weak___(___handle___);\n"
			"\t\t}\n" + (root
				? std::string{ "\t\treturn *___handle___;\n" }
				: ("\t\treturn *std::static_pointer_cast<___" + class_name + "_handle_base___>(___handle___);\n")) +
			"\t}\n\n");

		if (root)
		{
			river.write_string(
				"\tinline any_a<> operation(std::string const& name) const\n"
				"\t{\n"
				"\t\treturn ___read___().operations_().at_string(name);\n"
				"\t}\n\n");
		}

		river.write_string(
			"public:\n");

		if (root)
		{
			river.write_string(
				"\tinline bool is_ref() const\n"
				"\t{\n"
				"\t\treturn &___handle___ != &___shared___;\n"
				"\t}\n\n");
		}

		river.write_string(
			"\tstatic inline " + class_name + " val(" + class_name + " const& other) noexcept\n"
			"\t{\n"
			"\t\treturn " + class_name + "{ other };\n"
			"\t}\n\n"

			"\tstatic inline " + class_name + " ref(" + class_name + "& other) noexcept\n"
			"\t{\n"
			"\t\treturn " + class_name + "(other, ___reference_tag___{});\n"
			"\t}\n\n"

			"\tstatic inline " + class_name + " dup(" + class_name + "& other) noexcept\n"
			"\t{\n"
			"\t\treturn " + class_name + "(other, ___duplicate_tag___{});\n"
			"\t}\n\n");

		if (root)
		{
			river.write_string(
				"\tinline " + class_name + "() noexcept\n"
				"\t\t: ___shared___{}\n"
				"\t\t, ___handle___{ ___shared___ }\n"
				"\t{}\n\n"

				"\tinline " + class_name + "(" + class_name + " const& other) noexcept\n"
				"\t\t: ___shared___{ other.___handle___ }\n"
				"\t\t, ___handle___{ ___shared___ }\n"
				"\t{}\n\n"

				"\tinline " + class_name + "(" + class_name + "& other, ___reference_tag___) noexcept\n"
				"\t\t: ___shared___{ ___SHARED___{} }\n"
				"\t\t, ___handle___{ other.___handle___ }\n"
				"\t{}\n\n"

				"\tinline " + class_name + "(" + class_name + "& other, ___duplicate_tag___) noexcept\n"
				"\t\t: ___shared___{ &other.___handle___ == &other.___shared___ ? other.___handle___ : ___SHARED___{} }\n"
				"\t\t, ___handle___{ *(&other.___handle___ == &other.___shared___ ? &___shared___ : &other.___handle___) }\n"
				"\t{}\n\n"

				"\tinline " + class_name + "(" + class_name + "&& other) noexcept\n"
				"\t: ___shared___{ other.___handle___ }\n"
				"\t, ___handle___{ ___shared___ }\n"
				"\t{}\n\n"

				"\tinline " + class_name + "& operator=(" + class_name + " const& other) noexcept\n"
				"\t{\n"
				"\t\t___handle___ = other.___handle___;\n"
				"\t\treturn *this;\n"
				"\t}\n\n"

				"\tinline " + class_name + "& operator=(" + class_name + "&& other) noexcept\n"
				"\t{\n"
				"\t\t___handle___ = other.___handle___;\n"
				"\t\treturn *this;\n"
				"\t}\n\n"

				"\tvirtual ~" + class_name + "() = default;\n\n"

				"\ttemplate <typename ___TTT___>\n"
				"\texplicit inline " + class_name + "(std::shared_ptr<___TTT___> const& handle) noexcept\n"
				"\t\t: ___shared___{ handle }\n"
				"\t\t, ___handle___{ ___shared___ }\n"
				"\t{}\n\n"

				"\ttemplate <typename ___TTT___>\n"
				"\texplicit inline " + class_name + "(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept\n"
				"\t\t: ___shared___{ ___SHARED___{} }\n"
				"\t\t, ___handle___{ reinterpret_cast<___SHARED___&>(handle) }\n"
				"\t{}\n\n"

				"\ttemplate <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<" + class_name + ", std::decay_t<___TTT___>>::value>>\n"
				"\texplicit inline " + class_name + "(___TTT___ value) noexcept\n"
				"\t\t: ___shared___{ std::make_shared<___" + class_name + "_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }\n"
				"\t\t, ___handle___{ ___shared___ }\n"
				"\t{\n"
				"\t\t___handle___->___weak___(___handle___);\n"
				"\t}\n\n"

				"\ttemplate <typename ___TTT___, typename... Args>\n"
				"\texplicit inline " + class_name + "(___variadic_tag___, ___TTT___*, Args&&... args)\n"
				"\t\t: ___shared___{ std::make_shared<___" + class_name + "_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }\n"
				"\t\t, ___handle___{ ___shared___ }\n"
				"\t{\n"
				"\t\t___handle___->___weak___(___handle___);\n"
				"\t}\n\n"
				
				"\ttemplate <typename ___TTT___>\n"
				"\tinline " + class_name + "& operator=(std::shared_ptr<___TTT___> const& handle) noexcept\n"
				"\t{\n"
				"\t\t___handle___ = handle;\n"
				"\t\treturn *this;\n"
				"\t}\n\n"

				"\ttemplate <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<" + class_name + ", std::decay_t<___TTT___>>::value>>\n"
				"\tinline " + class_name + "& operator=(___TTT___ value) noexcept\n"
				"\t{\n"
				"\t\t" + class_name + " temp{ std::move(value) };\n"
				"\t\tstd::swap(temp.___handle___, ___handle___);\n"
				"\t\treturn *this;\n"
				"\t}\n\n");

			river.write_string(
				"\tstatic inline bool ___check___(any_a<> const& thing)\n"
				"\t{\n"
				"\t\treturn bool{ thing.___handle___ };\n"
				"\t}\n\n");

			river.write_string(
				"\tstatic inline any_a<> ___cast___(any_a<> const& thing)\n"
				"\t{\n"
				"\t\treturn thing;\n"
				"\t}\n\n");

			river.write_string(
				"\tstatic inline any_a<> ___cast_ref___(any_a<>& thing)\n"
				"\t{\n"
				"\t\treturn any_a<>(thing, ___reference_tag___{});\n"
				"\t}\n\n");
		}
		else
		{
			river.write_string(
				"\tinline " + class_name + "() = default;\n\n"

				"\tinline " + class_name + "(" + class_name + "& other, ___reference_tag___) noexcept\n"
				"\t\t: " + base_name + "(other, ___reference_tag___{})\n"
				"\t{}\n\n"

				"\tinline " + class_name + "(" + class_name + "& other, ___duplicate_tag___) noexcept\n"
				"\t\t: " + base_name + "(other, ___duplicate_tag___{})\n"
				"\t{}\n\n"

				"\ttemplate <typename ___TTT___>\n"
				"\texplicit inline " + class_name + "(std::shared_ptr<___TTT___> const& handle) noexcept\n"
				"\t\t: " + base_name + "{ handle }\n"
				"\t{\n"
				"\t\tassert(!handle || std::dynamic_pointer_cast<___" + class_name + "_handle_base___>(handle));\n"
				"\t}\n\n"

				"\ttemplate <typename ___TTT___>\n"
				"\texplicit inline " + class_name + "(std::shared_ptr<___TTT___>& handle, ___reference_tag___) noexcept\n"
				"\t\t: " + base_name + "(handle, ___reference_tag___{})\n"
				"\t{\n"
				"\t\tassert(!handle || std::dynamic_pointer_cast<___" + class_name + "_handle_base___>(handle));\n"
				"\t}\n\n"

				"\ttemplate <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<" + class_name + ", std::decay_t<___TTT___>>::value>>\n"
				"\texplicit inline " + class_name + "(___TTT___ value) noexcept\n"
				"\t\t: " + base_name + "{ std::make_shared<___" + class_name + "_handle_final___<typename std::remove_reference_t<___TTT___>>>(std::move(value)) }\n"
				"\t{\n"
				"\t\t___handle___->___weak___(___handle___);\n"
				"\t}\n\n"

				"\ttemplate <typename ___TTT___, typename... Args>\n"
				"\texplicit inline " + class_name + "(___variadic_tag___, ___TTT___*, Args&&... args)\n"
				"\t\t: " + base_name + "{ std::make_shared<___" + class_name + "_handle_final___<typename std::remove_reference_t<___TTT___>>>(___variadic_tag___{}, std::forward<Args>(args)...) }\n"
				"\t{\n"
				"\t\t___handle___->___weak___(___handle___);\n"
				"\t}\n\n"

				"\ttemplate <typename ___TTT___>\n"
				"\tinline " + class_name + "& operator=(std::shared_ptr<___TTT___> const& handle) noexcept\n"
				"\t{\n"
				"\t\tassert(!handle || std::dynamic_pointer_cast<___" + class_name + "_handle_base___>(handle));\n"
				"\t\t___handle___ = handle;\n"
				"\t\treturn *this;\n"
				"\t}\n\n"

				"\ttemplate <typename ___TTT___, typename = typename std::enable_if_t<!std::is_base_of<" + class_name + ", std::decay_t<___TTT___>>::value>>\n"
				"\tinline " + class_name + "& operator=(___TTT___ value) noexcept\n"
				"\t{\n"
				"\t\t" + class_name + " temp{ std::move(value) };\n"
				"\t\tstd::swap(temp.___handle___, ___handle___);\n"
				"\t\treturn *this;\n"
				"\t}\n\n");

			river.write_string(
				"\tstatic inline bool ___check___(any_a<> const& thing)\n"
				"\t{\n"
				"\t\treturn bool{ std::dynamic_pointer_cast<___" + class_name + "_handle_base___>(thing.___handle___) };\n"
				"\t}\n\n");

			river.write_string(
				"\tstatic inline " + class_name + " ___cast___(any_a<> const& thing)\n"
				"\t{\n"
				"\t\tauto const ptr = std::dynamic_pointer_cast<___" + class_name + "_handle_base___>(thing.___handle___);\n"
				"\t\tif (ptr)\n"
				"\t\t{\n"
				"\t\t\treturn " + class_name + "{ thing.___handle___ };\n"
				"\t\t}\n"
				"\t\treturn " + class_name + "{ " + class_name.substr(0, class_name.length() - 1) + "d");
			_declare_or_define_template_(version, 0, river, false, false);
			river.write_string("{ thing } };\n"
				"\t}\n\n");

			river.write_string(
				"\tstatic inline " + class_name + " ___cast_ref___(any_a<>& thing)\n"
				"\t{\n"
				"\t\tauto const ptr = std::dynamic_pointer_cast<___" + class_name + "_handle_base___>(thing.___handle___);\n"
				"\t\tif (ptr)\n"
				"\t\t{\n"
				"\t\t\treturn " + class_name + "(thing.___handle___, ___reference_tag___{});\n"
				"\t\t}\n"
				"\t\treturn " + class_name + "{ " + class_name.substr(0, class_name.length() - 1) + "d");
			_declare_or_define_template_(version, 0, river, false, false);
			river.write_string("(thing, ___reference_tag___{}) };\n"
				"\t}\n\n");
		}

		_define_class_relfection_(root, class_name, base_name, class_expression_terms, version, indent, river);

		river.write_string(
			"\ttemplate <typename ___TTT___, typename... Args>\n"
			"\tstatic inline " + class_name + " create(Args&&... args)\n"
			"\t{\n"
			"\t\treturn " + class_name + "(___variadic_tag___{}, static_cast<___TTT___*>(nullptr), std::forward<Args>(args)...);\n"
			"\t}\n\n"

			"private:\n"
			"\tstatic bool const ___share___;\n"
			"\tfriend class ___" + class_name + "_share___;\n");
	}

	inline void _define_class_relfection_(bool root, std::string const& class_name, std::string const& base_name, flock_a<> const& class_expression_terms, int64_t version, int64_t indent, river_a<>& river) const
	{
		std::string scope = _scope.to_string();
		std::size_t const pos = scope.rfind("::");
		scope = pos == std::string::npos
			? std::string{}
			: scope.substr(0, pos + 2);

		// ___cat___()
		if (root)
		{
			river.write_string("\ttemplate <typename ___cat_a___ = cat, typename ___kind_a___ = kind>\n");
		}
		else
		{
			river.write_string("\ttemplate <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>\n");
		}
		river.write_string(
			"\tstatic inline ___cat_a___ ___cat___()\n"
			"\t{\n"
			"\t\tstatic ___cat_a___ CAT = cat_create<___cat_a___>(1, \"" + scope + class_name.substr(0, class_name.length() - 2) + "\"");
		// dimensions
		int64_t count = _dimension_kinds.size();
		while (count != 0)
		{
			--count;
			auto const name = _dimension_names.at_index(count);
			auto const kind = _dimension_kinds.at_index(count);
			auto const def = _dimension_defaults.at_index(count);
			if (!check<kind_a<>>(kind) || !check<kind_a<>>(def) ||
				sym("#") + fast<kind_a<>>(kind).name_() != name ||
				sym("#") + fast<kind_a<>>(def).name_() != name)
			{
				++count;
				break;
			}
		}
		_define_class_relfection_dimensions_(count, _dimension_kinds, version, river);
		river.write_string(");\n"
			"\t\treturn CAT;\n"
			"\t}\n\n");

		// ___cats___()
		if (root)
		{
			river.write_string("\ttemplate <typename ___cat_a___ = cat, typename ___kind_a___ = kind, typename ___unordered_herd_a___ = unordered_herd>\n");
		}
		else
		{
			river.write_string("\ttemplate <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>, typename ___unordered_herd_a___ = unordered_herd_a<>>\n");
		}
		river.write_string(
			"\tstatic inline ___unordered_herd_a___ ___cats___()\n"
			"\t{\n"
			"\t\tstatic ___unordered_herd_a___ CATS = ");
		if (root)
		{
			river.write_string("unordered_herd_vals(___cat___<___cat_a___, ___kind_a___>());\n");
		}
		else
		{
			river.write_string("[]()\n"
				"\t\t{\n"
				"\t\t\tauto cats = " + base_name + "::___cats___<___cat_a___, ___kind_a___, ___unordered_herd_a___>();\n"
				"\t\t\tcats.update_thing(___cat___<___cat_a___, ___kind_a___>());\n"
				"\t\t\treturn cats;\n"
				"\t\t}();\n");
		}
		river.write_string(
			"\t\treturn CATS;\n"
			"\t}\n\n");

		// ___kind___()
		if (root)
		{
			river.write_string("\ttemplate <typename ___cat_a___ = cat, typename ___kind_a___ = kind>\n");
		}
		else
		{
			river.write_string("\ttemplate <typename ___cat_a___ = cat_a<>, typename ___kind_a___ = kind_a<>>\n");
		}
		river.write_string(
			"\tstatic inline ___kind_a___ ___kind___()\n"
			"\t{\n"
			"\t\tstatic ___kind_a___ KIND = kind_from_cat(___cat___<___cat_a___, ___kind_a___>()");
		// aspects
		if (count)
		{
			river.write_string(", flock_vals(");
			bool first = true;
			while (count)
			{
				if (first)
				{
					first = false;
				}
				else
				{
					river.write_string(", ");
				}
				river.write_string("kind_of<" + fast<symbol_a<>>(_dimension_names.at_index(--count)).to_string().substr(1) + ">()");
			}
			river.write_string(")");
		}
		river.write_string(");\n"
			"\t\treturn KIND;\n"
			"\t}\n\n");
	}

	inline void _define_class_relfection_dimensions_(int64_t count, flock_a<> const& dimension_kinds, int64_t version, river_a<>& river) const
	{
		static kind_a<> ANY_KIND = kind_create();
		if (!count)
		{
			return;
		}
		river.write_string(", flock_vals(");
		bool first = true;
		for (auto const& dimension_kind : dimension_kinds.extract_vector())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(", ");
			}
			if (check<kind_a<>>(dimension_kind))
			{
				auto const kind = fast<kind_a<>>(dimension_kind);
				river.write_string("kind_create<___kind_a___>(" +
					std::to_string(kind.order()) + ", \"" +
					kind.name_().to_string() + "\"");
				if (kind != ANY_KIND)
				{
					// recurse for dimensions
					_define_class_relfection_dimensions_(kind.dimensions_().size(), kind.dimensions_(), version, river);
				}
				river.write_string(")");
			}
			else if (check<expression_a<>>(dimension_kind))
			{
				fast<expression_a<>>(dimension_kind).generate_cpp(version, 0, river, false, false);
			}
			if (!--count)
			{
				break;
			}
		}
		river.write_string(")");
	}
	
	inline void _define_class_share_(std::string const& class_name, int64_t version, river_a<>& river) const
	{
		_declare_or_define_template_(version, 0, river, false, true);
		river.write_string("bool const " + class_name);
		_declare_or_define_template_(version, 0, river, false, false);
		river.write_string("::___share___ = []()\n"
			"{\n"
			"\tauto& shared_shoal = shared();\n"
			"\treflection<" + class_name);
		_declare_or_define_template_(version, 0, river, false, false);
		river.write_string(">::share(shared_shoal);\n"
			"\treturn shared_shoal;\n"
			"}();\n\n");
	}

	inline void _parse_member_definition_(int64_t version, expression_a<> const& expression, bool extraction, std::string& result, std::string& parameters, std::string& arguments, std::string& constness) const
	{
		if (extraction)
		{
			auto const& exp = static_cast<expression_extraction_t<> const&>(expression.extract_thing());
			exp.abstraction(version, result, parameters, arguments, constness);
		}
		else
		{
			auto const& exp = static_cast<expression_mutation_t<> const&>(expression.extract_thing());
			exp.abstraction(version, result, parameters, arguments, constness);
		}
	}

	inline void _parse_native_member_definition_(std::string const& class_name, std::string const& name, std::string const& value, std::string& result, std::string& parameters, std::string& arguments, std::string& constness, std::string& dynamic) const
	{
		auto tokenizer = tokenizer_t<>::create_(river_t<>::create(value));
		int64_t toke = 1;
		std::string argument;
		bool optional = false;
		for (auto const& any_token : tokenizer)
		{
			if (!check<token_a<>>(any_token))
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_abstraction::generate_cpp invalid token in class definition");
			}
			auto const token = cast<token_a<>>(any_token);
			if (token.tag() == "punctuation" && token.symbol() == "{")
			{
				break;
			}
			switch (toke)
			{
			case 1:
				if (token.tag() == "punctuation" && token.symbol() == "(")
				{
					parameters = "(";
					arguments = "(";
					toke = 2;
				}
				else
				{
					if (!result.empty())
					{
						result += " ";
					}
					result += token.symbol();
				}
				break;
			case 2:
				if (token.tag() == "punctuation" && token.symbol() == ")")
				{
					parameters += ")";
					arguments += argument + ")";
					toke = 3;
				}
				else if (token.tag() == "punctuation" && token.symbol() == ",")
				{
					parameters += ", ";
					arguments += argument + ", ";
				}
				else if (token.tag() == "punctuation" && token.symbol() == "=")
				{
					parameters += "= ";
					optional = true;
				}
				else
				{
					parameters += token.symbol() + " ";
					if (!optional && token.tag() == "name")
					{
						argument = token.symbol();
					}
				}
				break;
			case 3:
				if (token.tag() == "name" && token.symbol() == "const")
				{
					constness = " const";
				}
				break;
			}
		}
		auto const pos = value.find('{');
		if (pos == std::string::npos)
		{
			dynamic = "{ throw dis(\"dynamic " + class_name + "::" + name + arguments + " not available\"); }";
		}
		else
		{
			dynamic = value.substr(pos);
		}
	}

private:
	static bool const ___share___;
	friend class ___expression_abstraction_t_share___;
};

template <typename ___ego___>
bool const expression_abstraction_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_abstraction_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_abstraction_t_share___
{
	static inline bool ___share___()
	{
		return expression_abstraction_t<>::___share___;
	}
};

} // namespace strange

#endif
