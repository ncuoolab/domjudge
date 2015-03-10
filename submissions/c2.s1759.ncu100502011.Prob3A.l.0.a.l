identifier    [ |(|\t|$]([a-zA-Z0-9_"$"]+)"cpy"[a-zA-Z0-9_"$"]*
id            [" "|(|\t]"cpy"[a-zA-Z0-9_$]*
%%
{identifier}     {if(!(yytext[1]>='0'&&yytext[1]<='9')){
                        if(yytext[0]=='$'){
                                printf("%s",yytext);
                        }
                        else{
                                printf("%s",yytext+1);
                        }
                        printf("\n");}
                 }
{id}             {printf("%s",yytext+1);printf("\n");}
.|\n             ;
%%
int main(int argc, char *argv){
        yylex();
        return(0);
}

