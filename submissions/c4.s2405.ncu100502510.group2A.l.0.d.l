%{
%}
digit    [0-9]
ip       {digit}{1,3}"."{digit}{1,3}"."{digit}{1,3}"."{digit}{1,3}
%%
{ip}     {ECHO;printf("\n");}
\n       {}
.        {}
%%
int main(void){
     yylex();
     return(0);
}

