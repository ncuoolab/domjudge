
%{
int count=0,i=0;
%}
string [a-zA-Z][^\{\}\n]*
left [a-zA-Z].*\{.*
l \{.*
right [a-zA-Z].*\}.* 
r \}.*
%%
{left} {for(i=0;i<count;i++){printf("\t");}ECHO;count++;}
{right} {count--;for(i=0;i<count;i++){printf("\t");}ECHO;}
{l} {for(i=0;i<count;i++){printf("\t");}ECHO;count++;}
{r} {count--;for(i=0;i<count;i++){printf("\t");}ECHO;}
{string} {for(i=0;i<count;i++){printf("\t");}ECHO;}
\n {printf("\n");}
. ;
%%
int main(void)
{
yylex();
return(0);
}
