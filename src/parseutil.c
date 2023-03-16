# include "./parseutil.h"


//util functions
void skipSpaces(char** start, char* end){
    //skip spaces and comments
    for(;;(*start)++){
        if(*start >= end)return;
        char c = **start;
        if(c == ' ' || c == '\t' || c == '\n'){
            continue;
        }else if(c != '/'){
            return;
        }
        (*start)++;
        if(*start >= end)return;
        char c2 = **start;
        if(c2 == '/'){
            for(;;(*start)++){
                if(*start >= end)return;
                char c3 = **start;
                if(c3 == '\n')break;
            }
            continue;
        }else if(c2 == '*'){
            for(;;(*start)++){
                if(*start >= end){
                    fprintf(stderr,"Unclosed comment at the end of file");
                    exit(1);
                }
                char c3 = **start;
                if(c3 != '*')continue;
                (*start)++;
                if(*start >= end){
                    fprintf(stderr,"Unclosed comment at the end of file");
                    exit(1);
                }
                char c4 = **start;
                if(c4 == '/')break;
            }
            continue;
        }
        *start--
        return *start-1;
    }
}

void consumeChar(char** start, char* end, char c) {
    if(**start != c)
        e_expected_got(c,**start);
    skipSpaces(start,end);
}
void increment(char** start, char* end) {
    if(*start >= end)e_unexpected_EOF();
    (*start)++;
    skipSpaces(start,end);
}
char* parseIdentifier(char** start, char* end) {
    char* start0 = *start;
    if(start >= end)
        e_unexpected_EOF();
    if(!is_alpha(**start))
        e_expected_got_sc("identifier",**start);
    (*start)++;
    for(;;(*start)++){
        if(*start >= end)return slice_malloc(start0,end);
        if(is_alphanumeric(**start)){
            continue;
        }else{
            return slice_malloc(start0,start);
        }
    }
}

bool is_alpha(char c){
    return (65 <= c && c <= 90)
    || (97 <= c && c <= 122)
    || c == 95;
}
bool is_alphanumeric(char c){
    return (48 <= c && c <= 57)
    || (65 <= c && c <= 90)
    || (97 <= c && c <= 122)
    || c == 95;
}
bool is_numeric(char c){
    return (48 <= c && c <= 57);
}

//errors
void e_expected_got(char expected, char got){
    fprintf(stderr,"Syntax Error: Expected %c, got %c",expected,got);
    exit(1);
}
void e_expected_got_ss(char* expected, char* got){
    fprintf(stderr,"Syntax Error: Expected %s, got %s",expected,got);
    exit(1);
}
coid e_expected_got_sc(char* expected, char got){
    fprintf(stderr,"Syntax Error: Expected %s, got %c",expected,got);
    exit(1);
}
void e_unexpected_token(){
    fprintf(stderr,"Syntax Error: Unexpected token");
    exit(1);
}
void e_unexpected_EOF(){
    fprintf(stderr,"Syntax Error: Unexpected EOF");
    exit(1);
}

//malloc/realloc
void* safe_malloc(size_t size){
    void* ptr = malloc(size);
    if(ptr == null){
        fprintf(stderr,"Error: out of memory");
        exit(1);
    }
    return ptr;
};

void* safe_realloc(void* ptr, size_t size){
    ptr = realloc(ptr);
    if(ptr == null){
        fprintf(stderr,"Error: out of memory");
        exit(1);
    }
    return ptr;
};
char* slice_malloc(start,end){
    char* str = malloc((end-start)+1);
    strncpy(str,start,end-start);
    str[end-start] = '\0';
    return str;
};



