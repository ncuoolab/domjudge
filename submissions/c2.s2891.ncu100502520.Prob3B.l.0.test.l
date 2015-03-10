letter      [a-zA-Z]
digit       [0-9] 
word        ({letter}|{digit})+
space1       [ ]+
space2       ^[]*
nood        noodles
com         {word}{space1}
ans         {com}{com}{nood}{space1}{word}
%%       
{ans}         {ECHO;printf("\n");}
.|\n        ;
%%
int main(int argc, char *argv[]){
      yylex();
      return(0);
}
