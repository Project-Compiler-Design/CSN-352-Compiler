# Define compiler and tools
LEX = flex
BISON = bison
CC = g++
CFLAGS = -w

# Output executable name
EXEC = parser

# Source files
LEX_FILE = src/scanner.l
YACC_FILE = src/parser.y

# Default target
all: $(EXEC)

# Rule to compile the parser and scanner
$(EXEC): $(YACC_FILE) $(LEX_FILE)
	$(BISON) -d -Wno-all $(YACC_FILE)
	$(LEX) $(LEX_FILE)
	$(CC) $(CFLAGS) parser.tab.c lex.yy.c -o $(EXEC) -ll

# Clean build files
clean:
	rm -f $(EXEC) lex.yy.c parser.tab.c parser.tab.h
