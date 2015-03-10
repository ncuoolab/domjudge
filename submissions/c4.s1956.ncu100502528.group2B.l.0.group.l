%{
%}
wordcomment ("//Word")
word ([A-Z]+)([a-z|A-Z]*)
ipComment ("//IP Address")
ipName [0-255]+
ipRule {ipName}("."){ipName}("."){ipName}("."){ipName}
email ("//Email Address")
string ([a-z|A-Z|0-9]+)
right {string}("."){string}
rightRule {right}+
emailRule {string}("@"){rightRule}
emailRuleBad ([ |\t|\n])("@"){emailRule}
%x COMMENT
%x ipComment
%x emailComment
%%

{wordcomment}  {printf("--Word--\n");BEGIN COMMENT;}
<COMMENT>{word} {ECHO;printf(" is a word\n");}
<COMMENT>.|\n {}
<COMMENT>{ipComment} {printf("--IP Address--\n");BEGIN ipComment;}
<ipComment>{ipRule} {ECHO;printf(" is an IP address\n");}
<ipComment>.|\n {}
<ipComment>{email} {printf("--Email Address--\n");BEGIN INITIAL;}
{emailRule} {ECHO;printf(" is an email address\n");}
{emailRuleBad} {}
.|\n {}
%%
int main(int argc, char* argv[])
{
 yylex();
 return 0;
}




