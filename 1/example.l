%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NUM 201692414
int num_chars = 0;
int num_ids=0;
int num_nums=0;
%}
delim [ ]
letter [A-Za-z]
digit [0-9]
number {digit}+
id {letter}+

%%
{number} {int r=atoi(yytext);if(r==NUM) printf("¿Ó¨ï¨ï");
else printf("%s ",yytext);
num_nums+=yyleng;}
{delim} {printf(" ");}
{id} {printf("%s ",yytext);++num_ids;int r=strlen(yytext);num_chars+=r;}


%%
main()
{
	yylex();

	printf("\n# of ids = %d ,# of letters = %d,# of numbers = %d",num_ids , num_chars , num_nums);
}

