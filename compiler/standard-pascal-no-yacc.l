%{
/*
 * scan.l
 *
 * lex input file for pascal scanner
 *
 * extensions: two ways to spell "external" and "->" ok for "^".
 */

 #include <stdio.h>
#include "y.tab.h"
int line_no = 1;
char buf_comment[256];

%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^']
digit [0-9]

%%
{A}{R}{R}{A}{Y}              {printf("shift array\n");yylval.string = "array";return(ARRAY);    }  
{D}{O}                       {printf("shift do\n");yylval.string = "do";return(DO);       }     
{E}{L}{S}{E}                 {printf("shift else\n");yylval.string = "else";return(ELSE);     }  
{E}{N}{D}                    {printf("shift end\n");yylval.string = "end";return(END);      }     
{F}{U}{N}{C}{T}{I}{O}{N}     {printf("shift function\n");yylval.string = "function";return(FUNCTION); }       
{I}{N}{T}{E}{G}{E}{R}        {printf("shift integer\n");yylval.string = "integer";return(INTEGER);  }       
{I}{F}                       {printf("shift if\n");yylval.string = "if";return(IF);       }    
{N}{O}{T}                    {printf("shift not\n");yylval.string = "not";return(NOT);      }  
{O}{F}                       {printf("shift of\n");yylval.string = "of";return(OF);       }    
{B}{E}{G}{I}{N}              {printf("shift begin\n");yylval.string = "begin";return(PBEGIN);   } 
{P}{R}{O}{C}{E}{D}{U}{R}{E}  {printf("shift procedure\n");yylval.string = "procedure";return(PROCEDURE);} 
{P}{R}{O}{G}{R}{A}{M}        {printf("shift program\n");yylval.string = "program";return(PROGRAM);  } 
{R}{E}{A}{L}                 {printf("shift real\n");yylval.string = "real";return(REAL);     }  
{T}{H}{E}{N}                 {printf("shift then\n");yylval.string = "then";return(THEN);     }    
{V}{A}{R}                    {printf("shift var\n");yylval.string = "var";return(VAR);      }              
{W}{H}{I}{L}{E}              {printf("shift while\n");yylval.string = "while";return(WHILE);    }    
[a-zA-Z]([a-zA-Z0-9_])*      {printf("shift ID:%s\n",yytext);yylval.string = strdup(yytext);/*printf("this is ID\n");*/return(id);}
"-"                          {printf("shift '+'\n");yylval.string = strdup(yytext);return(MINUS);}
"+"                          {printf("shift '-'\n");yylval.string = strdup(yytext);return(PLUS);}
\/\/[" "0-9a-zA-z_\+\-\*\/\%=\<\>\(\)\[\],;\{\}~@\%\.'!#\$\^&\?\\\|]* {
	fprintf(stderr,"comments in line %d:%s\n",line_no,yytext);
}
\"[" "0-9a-zA-z_\+\-\*\/\%=\<\>\(\)\[\],;\{\}~@\%\.'!#\$\^&\?\\\|]*\" {
	printf("shift %s\n",yytext);
	yylval.string = strdup(yytext);
	return (CONST_STRING);
}
(0|[1-9][0-9]*) {
	printf("shift %s\n",yytext);
	yylval.int_val = atoi(yytext);
	return (CONST_INT);//integer
}
({digit}+)\.{digit}*{E}[\+\-]?{digit}+ {
	printf("shift %s\n",yytext);
	yylval.real_val = atof(yytext);
	return (CONST_REAL);//scientific expression
}
'[" "0-9a-zA-z_\+\-\*\/\%=\<\>\(\})\[\],;\{\}~@\%\.'!#\$\^&\?\\\|]*' {
	//printf("this is another string\n");
	printf("shift %s\n",yytext);
	yylval.string = strdup(yytext);
	return (CONST_STRING);
}
":="                         {printf("shift ':='\n");yylval.string = strdup(yytext);return(ASSIGNMENT);}
":"                          {printf("shift ':'\n");yylval.string = strdup(yytext);return(COLON);}
","                          {printf("shift ','\n");yylval.string = strdup(yytext);return(COMMA);}
"."                          {printf("shift '.'\n");yylval.string = strdup(yytext);return(DOT);       }            
".."                         {printf("shift '..'\n");yylval.string = strdup(yytext);return(DOTDOT);    }             
"="                          {printf("shift '='\n");yylval.string = strdup(yytext);return(EQUAL);     }              
"!="                         {printf("shift '!='\n");yylval.string = strdup(yytext);return(notEQUAL);  } 
">="                         {printf("shift '>='\n");yylval.string = strdup(yytext);return(GE);        }    
">"                          {printf("shift '>'\n");yylval.string = strdup(yytext);return(GT);        } 
"["                          {printf("shift '['\n");yylval.string = strdup(yytext);return(LBRAC);     }         
"<="                         {printf("shift '<='\n");yylval.string = strdup(yytext);return(LE);        }        
"("                          {printf("shift '('\n");yylval.string = strdup(yytext);return(LPAREN);    }         
"<"                          {printf("shift '<'\n");yylval.string = strdup(yytext);return(LT);        }      
"]"                          {printf("shift ']'\n");yylval.string = strdup(yytext);return(RBRAC);     }        
[0-9]+"."[0-9]+       {printf("shift %s\n",yytext);yylval.real_val = atof(yytext);return(CONST_REAL);       }       
")"                          {printf("shift ')'\n");yylval.string = strdup(yytext);return(RPAREN);    }        
";"                          {printf("shift ';'\n");yylval.string = strdup(yytext);return(SEMICOLON); }       
"/"                          {printf("shift '\'\n");yylval.string = strdup(yytext);return(SLASH);     }      
"*"                          {printf("shift '*'\n");yylval.string = strdup(yytext);return(STAR);      }      
"(*"   |
"{"    { register int c;
     while ((c = input()))
     {
      if (c == '}')
       break;
      else if (c == '*')
      {
       if ((c = input()) == ')')
        break;
       else
        unput (c);
      }
      else if (c == '\n')
       line_no++;
      else if (c == 0)
        fprintf (stderr, "Unexpected EOF inside comment at line %d\n",line_no);
     }
    }

[ \t\f]    ;

\r         ;
\n    line_no++;

.    {fprintf(stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);}

%%

/*int main(int argc, char** argv) {
  int i, tok;
  yyin = fopen("test.txt", "r");
  for (i = 0; 1==1; i ++) {
    tok = yylex();
    fprintf(stderr, "%3d-th token(type:%d) on line %d : %s\n", i, tok,line_no, yytext);
  }
  return(0);
} /* end of main */

int yywrap() {
  fclose(yyin);
  exit(1);
}

