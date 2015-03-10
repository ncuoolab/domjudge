%{
int counter = 0;int i;
%}
string			[^{}\n\t]+
line_with_tab		^[\t]+{string}$
line			^{string}$
left			[{]
right			^[}]{space}$
Right                   [}]
space			[" "]*
line_with_left		^{string}{left}{space}$
line_with_left_right	^{string}{left}{string}{Right}{space}$
word_left  		^{left}$
%%
{word_left}		{for(i=0;i<counter;i++){printf("\t");};ECHO;counter++;}
{right}			{counter--;for(i=0;i<counter;i++){printf("\t");};ECHO;}
{line_with_left}	{for(i=0;i<counter;i++){printf("\t");};counter++;ECHO;}
{line_with_tab}		{for(i=0;i<counter-1;i++){printf("\t");};ECHO;}
{line_with_left_right}    {for(i=0;i<counter;i++){printf("\t");};ECHO;}
{line}			{for(i=0;i<counter;i++){printf("\t");};ECHO;}


%%

int main()
{
	yylex();
	return(0);
}
