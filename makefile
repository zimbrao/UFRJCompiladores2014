all: 	saida.c
	../../gabarito/trabalho < saida.c
	g++ -o saida saida.c
	./saida

saida.c: trabalho entrada.cc
	./trabalho < entrada.cc > saida.c

lex.yy.c: trabalho.lex
	lex trabalho.lex

y.tab.c: trabalho.y
	yacc trabalho.y

trabalho: lex.yy.c y.tab.c
	g++ -o trabalho y.tab.c -lfl
