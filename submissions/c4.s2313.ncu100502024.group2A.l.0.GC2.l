%{
int counter = 0;int i;
%}
string			[#A-Za-z0-9<>();?=+|\*|\"|\\|" "]+
line_with_tab		^[#A-Za-z0-9<>();?=+|\*|\"|\\|" "|\t]+
line			^{string}$
left			[{]
right			^[}]$
line_with_left		^{string}{left}$
word_left  		 ^{left}$
%%
{word_left}		{for(i=0;i<counter;i++){printf("\t");};ECHO;counter++;}
{right}			{counter--;for(i=0;i<counter;i++){printf("\t");};ECHO;}
{line_with_left}	{for(i=0;i<counter;i++){printf("\t");};counter++;ECHO;}
{line_with_tab}		{for(i=0;i<counter-1;i++){printf("\t");};ECHO;}
{line}			{for(i=0;i<counter;i++){printf("\t");};ECHO;}


%%

int main()
{
	yylex();
	return(0);
}
