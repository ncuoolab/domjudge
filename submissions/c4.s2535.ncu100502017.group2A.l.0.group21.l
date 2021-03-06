%x comment
%{
unsigned int charCount=0, wordCount=0;
%}
space ^[ ]+$
line [^{}\n\t]+[ \t]*
left  "{"
right "}"
%%
\n     {printf("\n");BEGIN comment;}
[ ]      ;
{space}  ;
{line} {ECHO;}
{left} {wordCount++;ECHO;}
{right} {wordCount--;ECHO;}
\t       ;
<comment>{space}  ;
<comment>[ ]      ;
<comment>{line} {for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;BEGIN INITIAL;}
<comment>\n   {for(charCount=wordCount;charCount>0;charCount--)printf("\t");printf("\n");}
<comment>{left} {for(charCount=wordCount;charCount>0;charCount--)printf("\t");wordCount++;ECHO;BEGIN INITIAL;}
<comment>{right} {wordCount--;for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;BEGIN INITIAL;}
<comment>\t   ;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
