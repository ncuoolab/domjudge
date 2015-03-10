letter       [a-zA-Z]
digit        [0-9]
lord         ({letter}|{digit})
space        [ \t]
keyword      "noodles"
dataline     {lord}+{space}+{lord}+{space}+{keyword}{space}+{lord}+
%%
{dataline}   { ECHO; printf("\n"); }
.|\n         ;
%%
int main( int argc, char *argv[] )
{
  yylex();
  return(0);
}
