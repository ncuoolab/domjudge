digit 	[0-9]
letter	[a-zA-Z$_]
letter_or_digit [0-9a-zA-Z$_]
match	cpy
legal_word1 {letter}*{match}{letter_or_digit}*
legal_word2 {letter}{letter_or_digit}*{match}{letter_or_digit}*
legal_word {legal_word1}|{legal_word2}
%x COMMENT
%%
{legal_word}    {printf("%s\n",yytext);}
.|\n	;
%%
int main(int argc, char* argv){
	yylex();
	return(0);
}
