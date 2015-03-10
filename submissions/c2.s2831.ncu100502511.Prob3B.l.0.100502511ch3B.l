
alpha [a-zA-Z]
spac " "
noodles ^{alpha}*{spac}*{alpha}*{spac}*noodles{spac}*{alpha}*\n
%%
{noodles} ECHO;
.|\n ;
%%
int main(){
        yylex();
        return(0);
}


