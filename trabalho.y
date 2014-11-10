%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>

using namespace std;

struct Tipo {
  string nome;
};

struct Atributo {
  string v;  // Valor
  Tipo   t;  // tipo
  string c;  // codigo
  
  Atributo() {}  // inicializacao automatica para vazio ""
  Atributo( string v, string t = "", string c = "" ) {
    this->v = v;
    this->t.nome = t;
    this->c = c;
  }
};

typedef map< string, Tipo > TS;

string geraTemp();

void insereVariavelTS( TS&, string nomeVar, Tipo tipo );
bool buscaVariavelTS( TS&, string nomeVar, Tipo* tipo );

#define YYSTYPE Atributo

int yylex();
int yyparse();
void yyerror(const char *);
%}

%token _CTE_INT _CTE_CHAR _CTE_DOUBLE _CTE_STRING _ID 
%token _INT _CHAR _BOOL _DOUBLE _FLOAT _STRING

%left '+' '-'
%left '*' '/'

%%

S : VAR ';' S
  | ATR ';' S { cout << $1.c << endl; }
  |
  ;

VAR : VAR ',' _ID
    | TIPO _ID
    ;
    
TIPO : _INT
     | _CHAR
     | _BOOL
     | _DOUBLE
     | _FLOAT
     | _STRING
     ;
  
ATR : _ID '=' E 
    { $$.c = $3.c +
             $1.v + " = " + $3.v + ";\n"; }
    ;

E : E '+' E   
  { $$.v = geraTemp();
    $$.c = $1.c + $3.c + 
           $$.v + " = " + $1.v + " + " + $3.v + ";\n"; }
  | E '-' E
  | E '*' E
  { $$.v = geraTemp();
    $$.c = $1.c + $3.c + 
           $$.v + " = " + $1.v + " * " + $3.v + ";\n"; }
  | E '/' E
  | F
  ;

F : _ID		
  | _CTE_INT    
  | _CTE_DOUBLE 
  | '(' E ')'  { $$ = $2; }
  ;

%%
int nlinha = 1;
int n_var_temp = 0;
TS ts; // Tabela de simbolos

#include "lex.yy.c"

int yyparse();

string toStr( int n ) {
  char buf[1024] = "";
  
  sprintf( buf, "%d", n );
  
  return buf;
}

void yyerror( const char* st )
{
  puts( st );
  printf( "Linha: %d\nPerto de: '%s'\n", nlinha, yytext );
}

void erro( string msg ) {
  yyerror( msg.c_str() );
}

string geraTemp() {
  return "temp_" + toStr( ++n_var_temp );
}

void insereVariavelTS( TS& ts, string nomeVar, Tipo tipo ) {
  if( !buscaVariavelTS( ts, nomeVar, &tipo ) )
    ts[nomeVar] = tipo;
  else  
    erro( "Variavel já definida: " + nomeVar );
}

bool buscaVariavelTS( TS& ts, string nomeVar, Tipo* tipo ) {
  if( ts.find( nomeVar ) != ts.end() ) {
    *tipo = ts[ nomeVar ];
    return true;
  }
  else
    return false;
}

int main( int argc, char* argv[] )
{
  yyparse();
}
