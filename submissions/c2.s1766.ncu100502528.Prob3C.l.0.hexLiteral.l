%{
%}

hex ^(0x|0X)([a-fA-F0-9]){1,8}$
hex2  0(x|X)([a-fA-F0-9]){1,8}$
space [ ]  
%x COMMENT
%%

{hex} {ECHO;printf("\n");}
{space}  {BEGIN COMMENT;}
<COMMENT>{space} {}
<COMMENT>{hex2} { ECHO; printf("\n"); BEGIN INITIAL;}
<COMMENT>. {printf("\n");}
.|\n {}
%%
int main(int argc, char* argv[])
{
 yylex();
 return 0;
}



