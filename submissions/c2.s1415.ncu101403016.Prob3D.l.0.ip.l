%x COMMENT
%x COMMENT1
%%
^((?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)[" "])	 {printf("%s\n",yytext);BEGIN COMMENT;}
.	{BEGIN COMMENT;}
<COMMENT>.|\n      {}
<COMMENT>^((?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?))[" "]	{printf("%s\n",yytext);}
<COMMENT1>.	{}
<COMMENT1>[" "]\x22$	{BEGIN INITIAL;}
%%
int main(void){
	yylex();
	return(0);
}
