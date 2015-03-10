letter      [a-zA-Z]
digit       [0-9] 
word        ({letter}|{digit})+
space1       [ ]+
space2       []*
nood        "noodles"
ans         ^{word}{space1}{word}{space1}{nood}{space1}{word}{space2}$
%%
ans         {ECHO;}
.           ;
%%
int main(int argc, char *argv[]){
      yylex();
      return(0);
}
