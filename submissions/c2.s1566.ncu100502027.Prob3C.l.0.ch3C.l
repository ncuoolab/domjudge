%x COMMENT
hex1  ^[ ]*[0][xX][0-9A-Fa-f]{1,8}$
note ^[]*
hex2 [0][xX][0-9A-Fa-f]{1,8}$
%%
{hex1}    {ECHO;printf("\n");}
.|\n            ;
{note} {BEGIN COMMENT};
<COMMENT>{hex2} {ECHO;printf("\n");BEGIN INITIAL;}
%%
int main(int argc, char *argv[]){
   yylex();
   return(0);
}

