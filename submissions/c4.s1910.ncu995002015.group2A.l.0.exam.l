%{
unsigned int count = 0, i;
%}
left    "{"
right   "}"
enter   \n

%%
{left}  {ECHO; count++;}
{right} {printf("\b\b\b\b\b\b\b\b"); ECHO; count--;}
{enter} {ECHO; for(i = 0; i<count; i++){printf("\t");}}
.       {ECHO;}
%%

int main(int argc, char *argv[]){
      yylex();
      return(0);
}
      
