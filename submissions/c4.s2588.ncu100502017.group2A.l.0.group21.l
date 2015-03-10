%x comment
%{
unsigned int charCount=0, wordCount=0;
%}
space ^[ /t]+$
line [^{}\n\t ]+[ \t]*
left  "{"[ \t]*
right "}"[ \t]*
%%
\n     {printf("\n");BEGIN comment;}
[ ]      ;
\t       ;
{space}  ;
{line} {ECHO;}
{left} {wordCount++;ECHO;}
{right} {wordCount--;ECHO;}
<comment>[ ]    ;
<comment>\t   ;
<comment>{space}  ;
<comment>{line} {for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;BEGIN INITIAL;}
<comment>\n   {for(charCount=wordCount;charCount>0;charCount--)printf("\t");printf("\n");}
<comment>{left} {for(charCount=wordCount;charCount>0;charCount--)printf("\t");wordCount++;ECHO;BEGIN INITIAL;}
<comment>{right} {wordCount--;for(charCount=wordCount;charCount>0;charCount--)printf("\t");ECHO;BEGIN INITIAL;}
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
