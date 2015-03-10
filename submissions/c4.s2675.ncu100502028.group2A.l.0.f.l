%{
        int count=0, i=0; bool flag=false;
%}
line3  .\{$
line1 .\}.$
line2	.^\{^\}$
%%
{line3} count++;printf("{\n ");

{line1} count--;printf("}\n");
{line2} { for(i=0; i<count; i++)printf("\t");ECHO;}

%%
int main(){
        yylex();
                return 0;
}
