letter          [a-zA-Z_$]
digit           [0-9]
lord            ({letter}|{digit})
keyword         "cpy"
identifierA     {letter}{lord}*{keyword}{lord}*
identifierB     {keyword}{lord}*
notid           {digit}{lord}*{keyword}{lord}*
%x COMMENT
%%
"//"            { BEGIN COMMENT; }
<COMMENT>.      ;
<COMMENT>\n     { BEGIN INITIAL; }
{notid}         ;
{identifierA}   { ECHO;  printf("\n"); }
{identifierB}   { ECHO;  printf("\n"); }
.|\n            ;
%%
int main(int argc, char *argv[])
{
  yylex();
  return(0);
}
