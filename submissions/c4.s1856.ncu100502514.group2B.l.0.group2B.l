
%{
#define bool char
#define true 1
#define false 0
	
	bool isPrevSep = true;
	
	int commentPtr = 0;
	char commentBuf[1024];
%}

word [A-Z][A-Za-z]*
int 25[0-4]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]?|0
invalid_too_long_ip 0*{ip}("."{int})+
invalid_leading_zero_ip 0+{ip}
ip {int}"."{int}"."{int}"."{int}
string [^ \t\n]+
email {string}@{string}("."{string})+
separator [ \t\n]
else .

%x COMMENT

%%

{word} {
	if(isPrevSep){
		isPrevSep = false;
		printf("%s is a word\n", yytext);
	}
}
{invalid_too_long_ip} {
	isPrevSep = false;
	//print nothing but skip
}
{invalid_leading_zero_ip} {
	isPrevSep = false;
	//print nothing but skip
}
{ip} {
	if(isPrevSep){
		isPrevSep = false;
		printf("%s is an IP address\n", yytext);
	}
}
{email} {
	if(isPrevSep){
		isPrevSep = false;
		printf("%s is an email address\n", yytext);
	}
}
{separator} {
	isPrevSep = true;
}
{else} {
	//do nothing
}

"//" {
	commentPtr = 0;
	BEGIN(COMMENT);
}
<COMMENT>"\n" {
	int i;
	printf("--");
	for(i=0; i<commentPtr; i++){
		printf("%c", commentBuf[i]);
	}
	printf("--\n");
	BEGIN(INITIAL);
}
<COMMENT>. {
	commentBuf[commentPtr++] = *yytext;
}


%%
main(){
	
	//call the yylex process
	yylex();
	
	return 0;
}
