num1 [0-9]
num2 [0-4]

ip1 {num1}{num1}
ip2 "1"{num1}{num1}
ip3 "2"{num2}{num1}
ip4 "2""5"{num2}

ip {ip1}|{ip2}|{ip3}|{ip4}

%%
{ip}"."{ip}"."{ip}"."{ip}[ ] {ECHO; printf("\n");}
.|\n ;
%%

int main()
{
	yylex();
	return 0;
}



