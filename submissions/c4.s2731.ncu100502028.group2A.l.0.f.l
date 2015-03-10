%{
        int count=0, i=0; bool flag = TRUE;
%}
line .\}.$

%%
"{" count++;printf("{");
"}" count--;printf("}");
{line} flag = FALSE;
\n  {printf("\n");if(flag){for(i=0; i<count; i++)printf("\t");}else{count--;for(i=0; i<count; i++)printf("\t");flag = TRUE;}}
. ECHO;
%%
int main(){
        yylex();
                return 0;
}
