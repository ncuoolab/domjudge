digit 	[0-9]
letter	[a-zA-Z$_]
letter_or_digit [0-9a-zA-Z$_]
match	cpy
start	[ (\t]
legal_word1 {start}{letter}*{match}{letter_or_digit}*
legal_word2 {start}{letter}{letter_or_digit}*{match}{letter_or_digit}*
legal_word {legal_word1}|{legal_word2}
%x COMMENT
%%
"//"    {BEGIN COMMENT;}
<COMMENT>.      {/*do nothing.*/}
<COMMENT>"\n"   {BEGIN INITIAL;}
.|\n               ;
{legal_word}    {printf("%s\n",1+yytext);}
%%
int main(int argc, char* argv){
	yylex();
	return(0);
}
