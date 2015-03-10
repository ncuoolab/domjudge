hex [0-9a-fA-F]

legal ^0(x|X){hex}{1,6}

%%
{legal} {ECHO; printf("\n");}

.|\n ;

%%

int main(int argc,char *argv[])

{
  
yylex();
 
 return (0);

}

