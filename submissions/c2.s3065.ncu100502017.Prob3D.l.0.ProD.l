%x comment
%{
unsigned int charCount=0, wordCount=0;
%}
space (25[0-5])|(2[0-5][0-5])|(1[0-9][0-9])|([1-9][0-9])|([0-9])
spacea {space}[.]{space}[.]{space}[.]{space}
%%
{spacea} {ECHO;printf("\n");BEGIN comment;}
.|\n ;
<comment>.  ;
<comment>\n   {BEGIN INITIAL;}
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
