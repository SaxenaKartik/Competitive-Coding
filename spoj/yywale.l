%{
#include<stdio.h>
%}

%%
[0-9]+
{
	printf("it is a number");
	yymore();
	printf("it look like this");
}
[A-Z][a-z]*
{
	if(yyleng>8)
	yyless(8);

}
[a-z]*
{
	printf("%s",yytext);
	yyterminate();
	printf("didn't get the terminate word");
}
%%

main()
{
	yylex();
}