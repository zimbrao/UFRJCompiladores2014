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

void insereVariavelTS( TS*, string nomeVar, Tipo tipo );
bool buscaVariavelTS( TS*, string nomeVar, Tipo* tipo );

#define YYSTYPE Atributo

int yylex();
int yyparse();
void yyerror(const char *);
%}

%token _CTE_INT _CTE_CHAR _CTE_DOUBLE _CTE_STRING _ID 

%left '+' '-'
%left '*' '/'

%%

S : ATR { cout << $1.c << endl; }
  ;

ATR : _ID '=' E 
    { $$.c = $3.c +
             $1.v + " = " + $3.v; }
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

string geraTemp() {
  return "temp_" + toStr( ++n_var_temp );
}

void insereVariavelTS( TS*, string nomeVar, Tipo tipo ) {
  // TODO
}

bool buscaVariavelTS( TS*, string nomeVar, Tipo* tipo ) {
  // TODO
}

int main( int argc, char* argv[] )
{
  yyparse();
}