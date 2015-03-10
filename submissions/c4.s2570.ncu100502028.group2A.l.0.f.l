%{
        int count=0, i=0;
%}

line ^"}"

%%
"{" count++;printf("{");
"}" count--;printf("}");
\n  {printf("\n");if (line) count--; for(i=0; i<count; i++)printf("\t");}
. ECHO;
%%
int main(){
        yylex();
                return 0;
}
