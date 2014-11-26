%{
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>

/*
 * Programa exemplo de um compilador para o curso de Compiladores-2014-2 - Zimbrão
 * TODO:
 * - variavel do tipo boolean
 * - Funções e parametros
 * - Variaveis locais
 * - Array
 * - pipes
 *
 */

using namespace std;

const int MAX_STR = 256;

struct Tipo {
  string nome;
  
  Tipo() {}
  Tipo( string nome ) {
    this->nome = nome;
  }
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
TS ts; // Tabela de simbolos

string pipeAtivo; // Tipo do pipe ativo
string passoPipeAtivo; // Label 'fim' do pipe ativo

Tipo tipoResultado( Tipo a, string operador, Tipo b );
string geraTemp( Tipo tipo );
string geraLabel( string cmd );
string geraDeclaracaoTemporarias();
string geraDeclaracaoVarPipe();

void insereVariavelTS( TS&, string nomeVar, Tipo tipo );
bool buscaVariavelTS( TS&, string nomeVar, Tipo* tipo );
void erro( string msg );
string toStr( int n );

void geraCodigoAtribuicao( Atributo* SS, Atributo& lvalue, const Atributo& rvalue );
void geraCodigoOperadorBinario( Atributo* SS, const Atributo& S1, const Atributo& S2, const Atributo& S3 );
void geraCodigoFuncaoPrincipal( Atributo* SS, const Atributo& cmds );
void geraCodigoIfComElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen,
                                        const Atributo& cmdsElse );
void geraCodigoIfSemElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen );
void geraCodigoFor( Atributo* SS, const Atributo& inicial, 
                                  const Atributo& condicao, 
                                  const Atributo& passo, 
                                  const Atributo& cmds );
void geraCodigoFilter( Atributo* SS, const Atributo& condicao );

void geraDeclaracaoVariavel( Atributo* SS, const Atributo& tipo,
                                           const Atributo& id );
                                           
// Usando const Atributo& não cria cópia desnecessária

#define YYSTYPE Atributo

int yylex();
int yyparse();
void yyerror(const char *);
%}

%token _CTE_INT _CTE_CHAR _CTE_DOUBLE _CTE_STRING _ID 
%token _INT _CHAR _BOOL _DOUBLE _FLOAT _STRING  _COUT _SHIFTL
%token _PROGRAM _VAR _BEGIN _END _FUNCTION _IF _THEN _ELSE
%token _PIPE _INTERVALO _FILTER _FOREACH _2PTS _X

%nonassoc '<' '>' _IG
%left '+' '-' 
%left '*' '/' '%'

%%

S1 : _PROGRAM _ID ';' DECLS MAIN '.' 
     { cout << "#include <stdio.h>\n"
               "#include <stdlib.h>\n"
               "#include <string.h>\n\n"
            << $4.c << $5.c << endl; }
   ;
     
DECLS : VARGLOBAL DECLS 
        { $$ = Atributo();
          $$.c = $1.c + $2.c; }        
      | FUNC DECLS
        { $$ = Atributo();
          $$.c = $1.c + $2.c; }    
      |
        { $$ = Atributo(); }
      ;
      
VARGLOBAL : _VAR DECLVAR ';'
            { $$ = $2; }
          ;

FUNC : _FUNCTION
     ; 

MAIN : _BEGIN CMDS _END
       { geraCodigoFuncaoPrincipal( &$$, $2 ); }
     ; 

CMD : CMD_ATR   
    | CMD_OUT  
    | CMD_IF    
    ;

CMDS : CMD ';' CMDS  		{ $$.c = $1.c + $3.c; }
     | CMD_PIPE ';' CMDS  	{ $$.c = $1.c + $3.c; }
     | { $$ = Atributo(); }
     ;
     
CMD_PIPE : _INTERVALO '[' E _2PTS INI_PIPE ']' PROCS CONSOME 
          { 
            Atributo inicio, condicao, passo, cmd;
            
            inicio.c = $3.c + $5.c +
                       "  x_" + pipeAtivo + " = " + $3.v + ";\n";
            condicao.t.nome = "bool";
            condicao.v = geraTemp( Tipo( "bool" ) ); 
            condicao.c = "  " + condicao.v + " = " + "x_" + pipeAtivo + 
                         " <= " + $5.v + ";\n";
            passo.c = passoPipeAtivo + ":\n" + 
                      "  x_" + pipeAtivo + " = x_" + pipeAtivo + " + 1;\n";
            cmd.c = $7.c + $8.c;
            
            geraCodigoFor( &$$, inicio, condicao, passo, cmd );
            
            pipeAtivo = ""; }
        ;

INI_PIPE : E
           { $$ = $1;
             pipeAtivo =  $1.t.nome;
	     passoPipeAtivo = geraLabel( "passo_pipe" ); }
	 ;    
        
PROCS : _PIPE PROC PROCS 
        { $$.c = $2.c + $3.c; }
      | _PIPE
        { $$ = Atributo(); }
      ;
      
PROC : _FILTER '[' E ']'
       { geraCodigoFilter( &$$, $3 ); }
     ;
      
CONSOME : _FOREACH '[' CMD ']'
          { $$.c = $3.c; }
        ;
  
CMD_IF : _IF E _THEN CMDS _END _IF
         { geraCodigoIfSemElse( &$$, $2, $4 ); }
       | _IF E _THEN CMDS _ELSE CMDS _END _IF
         { geraCodigoIfComElse( &$$, $2, $4, $6 ); }
       ;
  
CMD_OUT : _COUT COUT_EXPR
          { $$ = $2; }
        ;
        
COUT_EXPR : COUT_EXPR _SHIFTL E 
            { if( $3.t.nome == "int" )
                $$.c = $1.c + $3.c + 
                       "  printf( \"%d\" , " + $3.v + " );\n";
              else if( $3.t.nome == "string" )
                $$.c = $1.c + $3.c + 
                       "  printf( \"%s\" , " + $3.v + " );\n";}
          | { $$ = Atributo(); }
          ;
                     

DECLVAR : DECLVAR ',' _ID
          { insereVariavelTS( ts, $3.v, $1.t ); 
            geraDeclaracaoVariavel( &$$, $1, $3 ); }
        | TIPO _ID
          { insereVariavelTS( ts, $2.v, $1.t ); 
            geraDeclaracaoVariavel( &$$, $1, $2 ); }
        ;
    
TIPO : _INT
     | _CHAR
     | _BOOL
     | _DOUBLE
     | _FLOAT
     | _STRING
     ;
  
CMD_ATR : _ID '=' E 
          { geraCodigoAtribuicao( &$$, $1, $3 ); }
        ;

E : E '+' E   
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '-' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '*' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '%' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '/' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '<' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E _IG E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | E '>' E
    { geraCodigoOperadorBinario( &$$, $1, $2, $3 ); }
  | F
  ;

F : _ID		
  { if( buscaVariavelTS( ts, $1.v, &$$.t ) ) 
      $$.v = $1.v; 
    else
      erro( "Variavel nao declarada: " + $1.v );
  }	
  | _CTE_INT 
    {  $$.v = $1.v; 
       $$.t = Tipo( "int" ); }
  | _CTE_DOUBLE 
    {  $$.v = $1.v; 
       $$.t = Tipo( "double" ); }
  | _CTE_STRING 
    {  $$.v = $1.v; 
       $$.t = Tipo( "string" ); }
  | '(' E ')'  { $$ = $2; }
  | _X
    { if( pipeAtivo != "" )
        $$ = Atributo( "x_" + pipeAtivo, pipeAtivo ); 
      else
        erro( "Variavel 'x' so pode ser usada dentro de pipe" );
    }
  ;

%%
int nlinha = 1;
map<string,int> n_var_temp;
map<string,Tipo> resultadoOperador;
map<string,int> label;

string geraLabel( string cmd ) {
  return "L_" + cmd +"_" + toStr( ++label[cmd] );
}

void geraCodigoFor( Atributo* SS, const Atributo& inicial, 
                                  const Atributo& condicao, 
                                  const Atributo& passo, 
                                  const Atributo& cmds ) {
  string forCond = geraLabel( "for_cond" ),
         forFim = geraLabel( "for_fim" );
  string valorNotCond = geraTemp( Tipo( "bool" ) );
         
  *SS = Atributo();
  if( condicao.t.nome != "bool" )
    erro( "A expressão de teste deve ser booleana: " + condicao.t.nome ); 
  
  // Funciona apenas para filtro, sem pipe que precisa de buffer 
  // (sort, por exemplo, não funciona)
  SS->c = inicial.c + forCond + ":\n" + condicao.c +
          "  " + valorNotCond + " = !" + condicao.v + ";\n" +
          "  if( " + valorNotCond + " ) goto " + forFim + ";\n" +
          cmds.c +
          passo.c +
          "  goto " + forCond + ";\n" + 
          forFim + ":\n";
}

void geraCodigoFilter( Atributo* SS, const Atributo& condicao ) {
  *SS = Atributo();
  SS->v = geraTemp( Tipo( "bool" ) );
  SS->c = condicao.c + 
          "  " + SS->v + " = !" + condicao.v + ";\n" +
          "  if( " + SS->v + " ) goto " + passoPipeAtivo + ";\n";
}

void geraCodigoAtribuicao( Atributo* SS, Atributo& lvalue, 
                                         const Atributo& rvalue ) {
  if( buscaVariavelTS( ts, lvalue.v, &lvalue.t ) ) {
    if( lvalue.t.nome == rvalue.t.nome ) {
      if( lvalue.t.nome == "string" ) {
        SS->c = lvalue.c + rvalue.c + 
                "  strncpy( " + lvalue.v + ", " + rvalue.v + ", " + 
                            toStr( MAX_STR - 1 ) + " );\n" +
                "  " + lvalue.v + "[" + toStr( MAX_STR - 1 ) + "] = 0;\n";
      }
      else
        SS->c = lvalue.c + rvalue.c + 
                "  " + lvalue.v + " = " + rvalue.v + ";\n"; 
    }
    else
      erro( "Expressao " + rvalue.t.nome + 
            " nao pode ser atribuida a variavel " +
            lvalue.t.nome );
    } 
    else
      erro( "Variavel nao declarada: " + lvalue.v );
}      
       
void geraCodigoIfComElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen,
                                        const Atributo& cmdsElse ) {
  string ifTrue = geraLabel( "if_true" ),
         ifFalse = geraLabel( "if_false" ),
         ifFim = geraLabel( "if_fim" );
      
  *SS = Atributo();
  SS->c = expr.c + 
          "  if( " + expr.v + " ) goto " + ifTrue + ";\n" +
          "  goto " + ifFalse + ";\n" +
          "  " + ifTrue + ":\n" + cmdsThen.c +
          "  goto " + ifFim + ";\n" +
          "  " + ifFalse + ":\n" + cmdsElse.c +
          "  " + ifFim + ":\n";
}

void geraCodigoIfSemElse( Atributo* SS, const Atributo& expr, 
                                        const Atributo& cmdsThen ) {
}


void geraDeclaracaoVariavel( Atributo* SS, const Atributo& tipo,
                                           const Atributo& id ) {
  SS->v = "";
  SS->t = tipo.t;
  if( tipo.t.nome == "string" ) {
    SS->c = tipo.c + 
           "char " + id.v + "["+ toStr( MAX_STR ) +"];\n";   
  }
  else {
    SS->c = tipo.c + 
            tipo.t.nome + " " + id.v + ";\n";
  }
}

void geraCodigoFuncaoPrincipal( Atributo* SS, const Atributo& cmds ) {
  *SS = Atributo();
  SS->c = "\nint main() {\n" +
           geraDeclaracaoVarPipe() + 
           "\n" + 
           geraDeclaracaoTemporarias() + 
           "\n" +
           cmds.c + 
           "  return 0;\n" 
           "}\n";
}  

string geraDeclaracaoTemporarias() {
  string c;
  
  for( int i = 0; i < n_var_temp["bool"]; i++ )
    c += "  int temp_bool_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["int"]; i++ )
    c += "  int temp_int_" + toStr( i + 1 ) + ";\n";

    for( int i = 0; i < n_var_temp["char"]; i++ )
    c += "  char temp_char_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["double"]; i++ )
    c += "  double temp_double_" + toStr( i + 1 ) + ";\n";

    for( int i = 0; i < n_var_temp["float"]; i++ )
    c += "  float temp_float_" + toStr( i + 1 ) + ";\n";
    
  for( int i = 0; i < n_var_temp["string"]; i++ )
    c += "  char temp_string_" + toStr( i + 1 ) + "[" + toStr( MAX_STR )+ "];\n";
    
  return c;  
}

void geraCodigoOperadorBinario( Atributo* SS, const Atributo& S1, const Atributo& S2, const Atributo& S3 ) {
  SS->t = tipoResultado( S1.t, S2.v, S3.t );
  SS->v = geraTemp( SS->t );

  if( SS->t.nome == "string" ) {
    // Falta o operador de comparação para string
    SS->c = S1.c + S3.c + 
            "\n  strncpy( " + SS->v + ", " + S1.v + ", " + 
                        toStr( MAX_STR - 1 ) + " );\n" +
            "  strncat( " + SS->v + ", " + S3.v + ", " + 
                        toStr( MAX_STR - 1 ) + " );\n" +
            "  " + SS->v + "[" + toStr( MAX_STR - 1 ) + "] = 0;\n\n";    
  }
  else
    SS->c = S1.c + S3.c + 
            "  " + SS->v + " = " + S1.v + " " + S2.v + " " + S3.v + ";\n";
}

void inicializaResultadoOperador() {
  resultadoOperador["string+string"] = Tipo( "string" );
  resultadoOperador["int+int"] = Tipo( "int" );
  resultadoOperador["int-int"] = Tipo( "int" );
  resultadoOperador["int*int"] = Tipo( "int" );
  resultadoOperador["int==int"] = Tipo( "bool" );
  resultadoOperador["int%int"] = Tipo( "int" );
  resultadoOperador["int/int"] = Tipo( "int" );
  resultadoOperador["int<int"] = Tipo( "bool" );
  resultadoOperador["int>int"] = Tipo( "bool" );
  resultadoOperador["double+int"] = Tipo( "double" );
  resultadoOperador["int*double"] = Tipo( "double" );
  // TODO: completar essa lista... :(
}

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
  exit(0);
}

string geraDeclaracaoVarPipe() {
  return "  int x_int;\n"
         "  double x_double;\n"
         "  float x_float;\n";
}

string geraTemp( Tipo tipo ) {
  return "temp_" + tipo.nome + "_" + toStr( ++n_var_temp[tipo.nome] );
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

Tipo tipoResultado( Tipo a, string operador, Tipo b ) {
  if( resultadoOperador.find( a.nome + operador + b.nome ) == resultadoOperador.end() )
    erro( "Operacao nao permitida: " + a.nome + operador + b.nome );

  return resultadoOperador[a.nome + operador + b.nome];
}

int main( int argc, char* argv[] )
{
  inicializaResultadoOperador();
  yyparse();
}
