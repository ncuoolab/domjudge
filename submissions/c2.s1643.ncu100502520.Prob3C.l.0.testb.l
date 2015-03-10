digit    [0-9]
letter   (a|b|c|d|e|f|A|B|C|D|E|F)
head     0(X|x)
hex      ^{head}({digit}|{letter})+
%%
{hex}    {ECHO;printf("\n");}
.|\n     ;
%%
int main(int argc, char*argv[]){
   yylex();
   return(0);
}
