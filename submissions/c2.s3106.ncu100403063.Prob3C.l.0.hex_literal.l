%x COMMENT
%x COMMENT1
%{
%}
ok	[0-9a-fA-F]
yes	0[x|X]{ok}{ok}?{ok}?{ok}?{ok}?{ok}?{ok}?{ok}?
space	[ ]*
%%
^[^0]		{BEGIN COMMENT;}
^.[g-zG-Z]+	{BEGIN COMMENT1;}
^.{1}[^xX]	{BEGIN COMMENT;}
<COMMENT>.	{/*do nothing*/}
<COMMENT>\n	{BEGIN INITIAL;}
<COMMENT1>.	{/*do nothing*/}
<COMMENT1>\n	{BEGIN INITIAL;}
[ ]*{yes}$	{int i=0;while(yytext[i]!='\0'){if(yytext[i]!=' '){printf("%c",yytext[i]);}i++;}}
%%
int main(void){
        yylex();
        return(0);
}
