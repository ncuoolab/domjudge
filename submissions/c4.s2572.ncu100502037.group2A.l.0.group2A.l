
%{
  int tab =0 , l_bracket =0, i=0;
%}

%x OTHER

%%

"\t"    {tab++;   }
"{"     {ECHO; l_bracket++;  }
"}"     {ECHO; l_bracket--; }
"\n"    {ECHO; BEGIN OTHER;}
<OTHER>"}" {l_bracket--; for(i=0; i< l_bracket; i++)printf("\t");  ECHO; BEGIN INITIAL;  }
<OTHER>\t {  }
<OTHER>.  { for( i=0; i< l_bracket; i++)printf("\t");    ECHO; BEGIN INITIAL;}

.|\n|\t    {    ECHO; }

%%

int main(int argc, char *argv[]) {
        yylex();
        return(0);

}
