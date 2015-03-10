letter        [a-zA-Z_]
digit         [0-9]
eol           \n
tab           \t
space         " "
special_char  [_$]

token_start   {letter}|{special_char}
token_follow  {letter}|{special_char}|{digit}
keyword       cpy

valid_1       {token_start}{token_follow}*{keyword}{token_follow}*
valid_2       {keyword}{token_follow}*

%%
{valid}      { ECHO; }
.            {}

%%

int main(int argc, char *argv[]) {
    yylex();
    return(0);
}
