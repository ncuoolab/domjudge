%{
        int count=0, i=0; int flag = 0;
%}
line \n[ \t]*\}
space ^[ \t]+
%%
"{" count++;printf("{");
"}" count--;printf("}");
{line} count--;printf("\n");for(i=0; i<count; i++)printf("\t");printf("}");
\n  {printf("\n");for(i=0; i<count; i++)printf("\t");}
{space} ;
. ECHO;
%%
int main(){
        yylex();
                return 0;
}
