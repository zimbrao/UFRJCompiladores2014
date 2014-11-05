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

{ID}       { return _ID; }
{INT}      { return _CTE_INT; }
{DOUBLE}   { return _CTE_DOUBLE; }

.          { return *yytext; }

%%

 


