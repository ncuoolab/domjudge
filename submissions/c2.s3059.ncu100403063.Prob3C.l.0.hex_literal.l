%x COMMENT
%x COMMENT1
%{
%}
ok	[0-9a-fA-F]
yes	{ok}{ok}?{ok}?{ok}?{ok}?{ok}?{ok}?{ok}?
%%
^[^0]		{BEGIN COMMENT;}
^.[g-zG-Z]+	{BEGIN COMMENT1;}
^.{1}[^xX]	{BEGIN COMMENT;}
<COMMENT>.	{/*do nothing*/}
<COMMENT>\n	{BEGIN INITIAL;}
<COMMENT1>.	{/*do nothing*/}
<COMMENT1>\n	{BEGIN INITIAL;}
^0[x|X]{yes}$	{ECHO;}
%%
int main(void){
        yylex();
        return(0);
}

