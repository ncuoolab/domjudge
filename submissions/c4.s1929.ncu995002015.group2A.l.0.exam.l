%{
unsigned int count = 0, i;
%}
left    "{"
right   "}"
blank   [ \t]
enter   \n

%%
{left}  {ECHO; count++;}
{right} {printf("\b\b\b\b\b\b\b\b"); ECHO; count--;}
{enter} {ECHO; for(i = 0; i<count; i++){printf("\t");}}
{blank} {}
.       {ECHO;}
%%

int main(int argc, char *argv[]){
      yylex();
      return(0);
}
      
