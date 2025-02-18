all: parser

parser: scanner.l parser.y
	flex scanner.l
	bison -d parser.y
	g++ parser.tab.h lex.yy.c -o parser

clean:
	rm -f parser lex.yy.c parser.tab.c parser.tab.h
