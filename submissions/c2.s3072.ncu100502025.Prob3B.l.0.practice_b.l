%{

%}
name            [A-Z][a-z]+
notcareer	"s""a""l""a""d"
career          ([a-z]|[A-Z])+
favorite        [a-z]+
hometown        [A-Z]([A-Z]|[a-z])+
notinformation  ^{name}[" "]+{notcareer}[" "]+"noodles"[" "]+{hometown}
information     ^{name}[" "]+{career}[" "]+"noodles"[" "]+{hometown}

%%
{notinformation}  {}
{information}   {ECHO;}
.               {}


%%
int main(){
	yylex();
	return(0);

}
