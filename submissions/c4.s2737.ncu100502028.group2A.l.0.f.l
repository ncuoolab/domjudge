%{
        int count=0, i=0; int flag = 0;
%}
line .\}.$

%%
"{" count++;printf("{");
"}" count--;printf("}");
{line} flag = 1;
\n  {printf("\n");if(flag == 0){for(i=0; i<count; i++)printf("\t");}else{count--;for(i=0; i<count; i++)printf("\t");flag = 1;}}
. ECHO;
%%
int main(){
        yylex();
                return 0;
}
