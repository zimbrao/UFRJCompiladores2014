DELIM   [\t ]
LINHA   [\n]
NUMERO  [0-9]
LETRA   [A-Za-z_]
INT     {NUMERO}+
DOUBLE  {NUMERO}+("."{NUMERO}+)
ID      {LETRA}({LETRA}|{NUMERO})*
STRING  \"[^"\n]*\"
COMMENT "//".*

%%

{LINHA}    	{ nlinha++; }
{DELIM}    	{}
{COMMENT}	{}

"int"		{  yylval = Atributo( "", yytext ); return _INT; }
"char"		{  yylval = Atributo( "", yytext ); return _CHAR; }
"bool"		{  yylval = Atributo( "", yytext ); return _BOOL; }
"double"	{  yylval = Atributo( "", yytext ); return _DOUBLE; }
"float"		{  yylval = Atributo( "", yytext ); return _FLOAT; }
"string"	{  yylval = Atributo( "", yytext ); return _STRING; }

"<<" 		{  yylval = Atributo( yytext ); return _SHIFTL; }
"=>"		{  yylval = Atributo( yytext ); return _PIPE; }
".."		{  yylval = Atributo( yytext ); return _2PTS; }
"=="		{  yylval = Atributo( yytext ); return _IG; }

{INT}      	{ yylval = Atributo( yytext ); return _CTE_INT; }
{DOUBLE}   	{ yylval = Atributo( yytext ); return _CTE_DOUBLE; }
{STRING}   	{ yylval = Atributo( yytext ); return _CTE_STRING; }

"COUT"		{  yylval = Atributo( yytext ); return _COUT; }
"PROGRAM"	{ yylval = Atributo( yytext ); return _PROGRAM; }
"VAR"		{ yylval = Atributo( yytext ); return _VAR; }
"BEGIN"		{ yylval = Atributo( yytext ); return _BEGIN; }
"END"		{ yylval = Atributo( yytext ); return _END; }
"FUNCTION"	{ yylval = Atributo( yytext ); return _FUNCTION; }
"IF"		{ yylval = Atributo( yytext ); return _IF; }
"THEN"		{ yylval = Atributo( yytext ); return _THEN; }
"ELSE"		{ yylval = Atributo( yytext ); return _ELSE; }
"INTERVALO"	{ yylval = Atributo( yytext ); return _INTERVALO; }
"FILTER"	{ yylval = Atributo( yytext ); return _FILTER; }
"FOREACH"	{ yylval = Atributo( yytext ); return _FOREACH; }
"x"		{ yylval = Atributo( yytext ); return _X; }

{ID}       { yylval = Atributo( yytext ); return _ID; }
.          { yylval = Atributo( yytext ); return *yytext; }

%%

 


