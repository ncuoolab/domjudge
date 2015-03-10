digit    [0-9]
space    [ ]
head     0[Xx]
letter   (a|b|c|d|e|f|A|B|C|D|E|F) 
hex      ^{head}({digit}|{letter}){1,8}$
%%
{hex}    {ECHO;printf("\n");}
{space}  ;
.|\n     ;
%%
int main(int argc, char*argv[]){
   yylex();
   return(0);
}
