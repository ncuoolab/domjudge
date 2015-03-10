%{
        int count=0, i=0;
%}


%%
"{" count++;printf("{\n");for(i=0; i<count; i++)printf("\t");
"}" count--;printf("}");
\n  printf("\n");
. ECHO;
%%
int main(){
        yylex();
                return 0;
}

