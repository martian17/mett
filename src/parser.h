# include <types.h>
# include <parseutil.h>

Scope _parseScope(char** start, char* end);

//main functions
Global* parseGlobal(char** start, char* end);
Function* parseFunction(char** start, char* end);
Statement* parseStatement(char** start, char* end);
//no alloc functions, contents of statement
  While _parseWhile(char** start, char* end);
  If _parseIf(char** start, char* end);
  Return _parseReturn(char** start, char* end);
  Declaration _parseIfDeclaration(char** start, char* end, bool* success);
  Expression _parseExpression(char** start, char* end);

Expression* parseExpression(char** start, char* end);
//no alloc functions, contents of expression
  //this might change
  Toekn _getIfNextToken(char** start, char* end, bool* success);
