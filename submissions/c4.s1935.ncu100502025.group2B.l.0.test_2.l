%{

%}
comment_word      "/""/""W""o""r""d"
comment_IP        "/""/""I""P"" ""A""d""d""r""e""s""s"
comment_email     "/""/""E""m""a""i""l"" ""A""d""d""r""e""s""s"
alphabet          ([a-z]|[A-Z])+
digit             [0-9]+
word              ^[A-Z]{alphabet}?
IPdigit           ([0-1][0-9][0-9])|([2][0-4][0-9])|([2][5][0-5][^0-9]?)|([0-9][0-9])|([0-9])
IP                ^{IPdigit}["."]{IPdigit}["."]{IPdigit}["."]{IPdigit}$
address_left      {alphabet}?{digit}?[^" ""\t""\n"]{alphabet}?{digit}?
address_right     {alphabet}["."]{alphabet}
address           ^{address_left}["@"]{address_right}

%%
{word}            {ECHO;printf(" is a word\n");}
{IP}              {ECHO;printf(" is an IP address\n");}
{address}         {ECHO;printf(" is an email address\n");}
{comment_word}    {printf("--Word--\n");}
{comment_IP}      {printf("--IP Address--\n");}  
{comment_email}   {printf("--Email Address--\n");}
.|\n              {}
%%
int main(){
	yylex();
	return(0);
}
