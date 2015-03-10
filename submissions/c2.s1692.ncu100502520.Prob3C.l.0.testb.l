digit    [0-9]
letter   (a|b|c|d|e|f|A|B|C|D|E|F)
head     0(X|x)
eol      $ 
hex      ^{head}({digit}|{letter})+{eol}
%%
{hex}    {ECHO;printf("\n");}
.|\n     ;
%%
int main(int argc, char*argv[]){
   yylex();
   return(0);
}
