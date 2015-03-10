%{
        int count=0, i=0; bool flag=false;
%}

line1 .\}.$
line2	.$
%%
"{" count++;printf("{\n ");
"}" count--;printf("}");
{line1} count--;
{line2} { for(i=0; i<count; i++)printf("\t");ECHO;}

%%
int main(){
        yylex();
                return 0;
}
