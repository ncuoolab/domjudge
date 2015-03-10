%{

%}
name            [A-Z][a-z]+
career          ([a-z]|[A-Z])+
favorite        [a-z]+
hometown        [A-Z]([A-Z]|[a-z])+
notinformation  ^{name}[" "]+{notcareer}[" "]+"noodles"[" "]+{hometown}
information     ^{name}[" "]+{career}[" "]+"noodles"[" "]+{hometown}

%%
{information}   {ECHO;}
.               {}


%%
int main(){
	yylex();
	return(0);

}
