cpy cpy

head [a-zA-Z_$] 

sequence [A-Za-z0-9_$]* 
 

valid ({cpy}({sequence})*)|({head}{sequence}*{cpy}{sequence}*) 

legal1 (" "|"("|\t){valid} 

legal2 ^{valid} 


%%
 

{legal1} {printf("%s",1+yytext);printf("\n");} 

{legal2} {printf("%s",yytext);printf("\n");} 

.|\n ; 


%%
 

int main(int argc,char *argv[]) 

{
 
yylex();
 
return (0);

}
