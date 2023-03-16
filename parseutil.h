# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

//util functions
void skipSpaces(char** start, char* end);
void consumeChar(char** start, char* end, char c);
void increment(char** start, char* end);
char* parseIdentifier(char** start, char* end);

bool is_alpha(char c);
bool is_alphanumeric(char c);
bool is_numeric(char c);

//errors
void e_expected_got(char expected, char got);
void e_expected_got_ss(char* expected, char* got);
void e_expected_got_sc(char* expected, char got);
void e_unexpected_token();
void e_unexpected_EOF();

//malloc/realloc
void* safe_malloc(size_t size);
void* safe_realloc(void* ptr, size_t size);
void* slice_malloc(char** start, char* end);
