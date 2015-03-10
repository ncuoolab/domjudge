%{

%}
name            [A-Z][a-z]*
career          ([a-z]|[A-Z])*
favorite        ([a-z]|[A-Z])*
hometown        [A-Z]([A-Z]|[a-z])*
information     ^{name}[" "]+{career}[" "]+"n""o""o""d""l""e""s"[" "]+{hometown}

%%
{information}   {ECHO;}
.               {}


%%
int main(){
	yylex();
	return(0);

}
