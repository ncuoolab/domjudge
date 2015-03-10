letter        [a-zA-Z_]
digit         [0-9]
eol           \n
tab           \t
space         " "

description    Name\tCareer\tFavorite\tHometown
name           ({letter}|{digit})+
career         ({letter}|{digit})+
favorite       ({letter}|{digit})+
hometown       ({letter}|{digit})+

list           ^{name}({tab}|{space})+{career}({tab}|{space})+noodles({tab}|{space})+{hometown}

%%
{list}      { ECHO; }
.           {}

%%

int main(int argc, char *argv[]) {
    yylex();
    return(0);
}
