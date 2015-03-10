%{

%}
name            [A-Z][a-z]*
career          ([a-z]|[A-Z])*
favorite        ([a-z]|[A-Z])*
hometown        [A-Z]([A-Z]|[a-z])*
information     ^{name}[" "|'\t']+{career}[" "|'\t']+"n""o""o""d""l""e""s"[" "|'\t']+{hometown}[" "|'\t']*

%%
{information}   {ECHO;}
.               {}


%%
int main(){
	yylex();
	return(0);

}
