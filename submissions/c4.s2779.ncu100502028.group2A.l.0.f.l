%{
        int count=0, i=0; int flag = 0;
%}
line \n[ \t]*\}

%%
"{" count++;printf("{");
"}" count--;printf("}");
{line} count--;print("\n");for(i=0; i<count; i++)printf("\t");printf("}");
\n  {printf("\n");for(i=0; i<count; i++)printf("\t");}
. ECHO;
%%
int main(){
        yylex();
                return 0;
}
