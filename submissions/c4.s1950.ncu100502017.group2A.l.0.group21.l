
%{
unsigned int charCount=0, wordCount=0;
%}
left  "{"
right "}"
%%
{left} {wordCount++;}
{right} {wordCount--;}
\n      {for(charCount=wordCount;charCount>0;charCount--)printf("123");ECHO;}

%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
