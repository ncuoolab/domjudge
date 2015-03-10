%{
        int count=0, i=0;
%}


%%
"{" count++;printf("{");
"}" count--;printf("}");
\n  {printf("\n");for(i=0; i<count; i++)printf("\t");}
. ECHO;
%%
int main(){
        yylex();
                return 0;
}
