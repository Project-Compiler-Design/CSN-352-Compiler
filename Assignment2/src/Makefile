all: parser

parser: scanner.l parser.y
	bison -d parser.y
	flex scanner.l
	gcc -w -o parser parser.tab.c lex.yy.c -lfl
	./parser < input1.c

clean:
	rm -f parser lex.yy.c parser.tab.c parser.tab.h