prettyprint: c2html test1.c test2.c test3.c
	./c2html test1.c > test1.html
	./c2html test2.c > test2.html
	./c2html test3.c > test3.html

c2html: lex.yy.o c2html.o
	g++ lex.yy.o c2html.o -o c2html

lex.yy.c: c2html.l
	flex c2html.l

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

c2html.o: c2html.cc
	g++ -c c2html.cc
