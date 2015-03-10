%{
unsigned int count=0, flag=0;
%}
Left	\{
Right	\n[ \t]*\}
space	[ \t]+
%%
{Left}	{ECHO;count++;}
{Right}	{flag++;count--;return 1;}
\n	{ECHO;return 1;}
{space}	;
.	{ECHO;}
%%
int main(int argc, char* argv[]){
        while(yylex()){
                unsigned int temp=count;
		if(flag>0){
			printf("\n");
		}
                while(temp!=0){
                        printf("\t");
                        temp--;
                }
		if(flag>0){
			printf("}");
			flag=0;
		}
        }
        return(0);
}
