//global scope
typedef struct {
    size_t size;
    Function** funcs;
} Global;

//function
typedef struct {
    char*  name;
    char** ret_types;
    size_t ret_types_size;
    char** args;
    size_t args_size;
    char** arg_types;
    Statement** statements;
    size_t statements_size;
} Function;

//util scope
typedef struct {
    Statement** body;
    size_t size;
} Scope;


//statements
typedef enum {
    _Declaration,
    _While,
    _If,
    _Return,
    _Expression// function call, increment, decrement
} Statement_type;

typedef struct{
    Statement_type type;
    union {
        Declaration declaration_st;
        While while_st;
        If if_st;
        Return return_st;
        Expression expression_st;
    } content;
} Statement;

typedef struct {
    char** types;
    char** types_size;
    char** names;
    char** names_size;
    Expression* right;
} Declaration;

typedef struct {
    Expression* cond;
    Statement** body;
    size_t body_size;
} While;

typedef struct {
    Expression* cond;
    Statement** body;
    size_t body_size;
    Statement** body_else;
    size_t body_else_size;
} If;

typedef struct {
    Expression* content;
} Return;

//expressions
typedef enum {
    Assign,
    Assign_add,
    Assign_sub,
    Add,
    Sub,
    Increment,
    Decrement
} Operator_type;

typedef struct {
    Operator_type type;
    Expression* left;
    Expression* right;
} Binary_expr;

typedef struct {
    Operator_type type;
    Expression* content;
} Unary_expr;

typedef struct {
    char* name;
    Expression** args;
    size_t args_size;
} Funccall_expr;

typedef struct {
    int value;
} Int_literal;

typedef struct {
    char value;
} Char_literal;

typedef struct {
    char* name;
} Identifier;

typedef struct {
    Expression** values;
    size_t values_size;
} Tuple;

typedef enum {
    _Binary,
    _Unary,
    _Funccall,

    _Int,
    _Char,
    _Identifier,
    _Tuple
} Expression_type;

typedef struct {
    Expression_type type;
    union {
        Binary_expr binary;
        Unary_expr unary;
        Funccall_expr func;
        Int_literal int_l;
        Char_literal char_l;
        Identifier id;
        Tuple tuple;
    } content;
} Expression;

