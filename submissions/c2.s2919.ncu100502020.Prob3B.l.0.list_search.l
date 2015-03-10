letter    [a-zA-z]
id        {letter}+[ ]+{letter}+[ ]+noodles[ ]+{letter}+
%%
{id}      {ECHO;printf("\n");}
.|\n      ;
%%
int main(int argc, char *argv[]){
    yylex();
    return(0);
}
