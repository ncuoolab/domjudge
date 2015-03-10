%x COMMENT
digit [0-9]|[0-9][0-9]|[1][0-9][0-9]|[2][0-4][0-9]|(25)[0-5]
adress {digit}"\."{digit}"\."{digit}"\."{digit}
%%
{adress}    {ECHO;printf("\n");}
.|\n            ;
"\-"            {BEGIN COMMENT;}
<COMMENT>.              ;
<COMMENT>\n     {BEGIN INITIAL;}
%%
int main(int argc, char *argv[]){
   yylex();
   return(0);
}

