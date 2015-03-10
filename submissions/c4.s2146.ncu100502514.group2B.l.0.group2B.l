
%{
#define bool char
#define true 1
#define false 0
	
	#include <string.h>
	
	bool isPrevSep = true;
	
	int commentPtr = 0;
	char commentBuf[1024];
	
	int ip_num_count = 0;
	bool ip_invalid_flag = false;
	bool enableNextIpNum = true;
	
	char ipBuf[1024];
	
	int stringToNum(char* str){
		int n=0, i=0;
		while(str[i]!='\0'){
			if(str[i]>'9' || str[i]<'0')return -1; //invalid char
			if(n==0 && i>0)return -1; //leading zero not allowed
			n *= 10;
			n += str[i]-'0';
			i++;
		}
		return n;
	}
	
	void doSeparator(){
		isPrevSep = true;
		if(ip_num_count==4 && !ip_invalid_flag){
			printf("%s is an IP address\n", ipBuf);
		}
		ip_num_count = 0;
		enableNextIpNum = true;
		ip_invalid_flag = false;
	}
	
%}

word [A-Z][A-Za-z]*
int [0-9]+
string [^ \t\n\.@]+
email ^{string}("."{string})*@{string}("."{string})+$
invalidEmail ^{string}@{string}("."{string})+"."$
dot "."
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
{int} {
	if(isPrevSep || ip_num_count>0){
		isPrevSep = false;
		if(enableNextIpNum){
			if(ip_num_count==0){
				ipBuf[0] = '\0';
			}
			int n = stringToNum(yytext);
			ip_num_count++;
			if(n<0 || n>255){
				ip_invalid_flag = true;
			}else{
				strcat(ipBuf, yytext);
			}
			enableNextIpNum = false;
		}
	}
}
{invalidEmail} {
	isPrevSep = false;
	//do nothing
}
{email} {
	if(isPrevSep){
		isPrevSep = false;
		printf("%s is an email address\n", yytext);
	}
}
{dot} {
	if(ip_num_count>0){
		strcat(ipBuf, yytext);
		if(!enableNextIpNum)enableNextIpNum = true;
		else ip_invalid_flag = true;
	}
}
{separator} {
	doSeparator();
}
{else} {
	//do nothing
}

"//" {
	commentPtr = 0;
	doSeparator();
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
	doSeparator();
	
	return 0;
}
