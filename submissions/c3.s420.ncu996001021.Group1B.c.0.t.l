

level      l[0-9]+[" "|"\n"]
FirstName  [A-Z][a-z]*[" "|"\n"]
LastName   [a|c-z]+[" "|"\n"]
cid        [0-9]+[" "|"\n"]
battle     b[" "|"\n"]
enter      "\n"
else       .      
%%
{else}      { printf("invalid input\n"); return;}
{level}     { printf("level "); ECHO; printf("\n");}
{FirstName} { printf("FirstName "); ECHO; printf("\n");}
{LastName}  { printf("LastName "); ECHO; }
{cid}       { printf("cid "); ECHO; printf("\n");}
{battle}    { printf("battle "); ECHO; printf("\n");}

%%
int main(){
    yylex();
    return(0);
}
