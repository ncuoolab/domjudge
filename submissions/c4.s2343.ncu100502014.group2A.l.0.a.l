
%{
int count=0,i=0;
%}
string [^ \t\n\{\}]+[^\{\}\n]*
string2 [^ \t\n]+.*\{.*\}.*|\{.*\}.*
left [^ \t\n]*\{[^\}\n]*
right [^ \t\n\{]*\}.*
%%
{string} {for(i=0;i<count;i++){printf("\t");}ECHO;}
{left} {for(i=0;i<count;i++){printf("\t");}ECHO;count++;}
{right} {count--;for(i=0;i<count;i++){printf("\t");}ECHO;}
\n {printf("\n");}
. ;
%%
int main(void)
{
yylex();
return(0);
}
