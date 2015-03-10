
%{
  unsigned int tab =0 , l_bracket =0;
%}

%x OTHER

%%

"\t"    {tab++;   }
"{"     {ECHO; l_bracket++;  }
"}"     {ECHO; l_bracket--;  }
"\n"    {ECHO; BEGIN OTHER;}

<OTHER>.  {if(l_bracket == 1){printf("\t");} if(l_bracket == 2){printf("\t\t"); if(l_bracket == 3){ printf("\t\t\t"); } }   ECHO; BEGIN INITIAL;}

.|\n|\t    {    ECHO; }

%%

int main(int argc, char *argv[]) {
        yylex();
        return(0);

}
