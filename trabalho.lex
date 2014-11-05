DELIM   [\t ]
LINHA   [\n]
NUMERO  [0-9]
LETRA   [A-Za-z_]
INT     {NUMERO}+
DOUBLE  {NUMERO}+("."{NUMERO}+)
ID      {LETRA}({LETRA}|{NUMERO})*


%%

{LINHA}    { nlinha++; }
{DELIM}    {}

{ID}       { yylval = Atributo( yytext ); return _ID; }
{INT}      { yylval = Atributo( yytext ); return _CTE_INT; }
{DOUBLE}   { yylval = Atributo( yytext ); return _CTE_DOUBLE; }

.          { yylval = Atributo( yytext ); return *yytext; }

%%

 


