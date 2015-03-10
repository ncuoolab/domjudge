%{
unsigned int count=0, flag=0;
%}
Left		\{
Right1		\n[ \t]*\}
Right2		\}
garbage		^[ \t]+
%%
{Left}		{ECHO;count++;}
{Right1}	{flag=1;count--;return 1;}
{Right2}	{flag=2;count--;return 1;}
\n		{ECHO;return 1;}
{garbage} 	;
.		{ECHO;}
%%
int main(int argc, char* argv[]){
        while(yylex()){
                unsigned int temp=count;
		if(flag==1){
			printf("\n");
		}
		if(flag!=2){                
			while(temp!=0){
                        	printf("\t");
                       		temp--;
              		}
		}
		if(flag>0){
			printf("}");
			flag=0;
		}
        }
        return(0);
}
