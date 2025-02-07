# Define compiler and flags
LEX = flex
CXX = g++
CXXFLAGS = -Wall

# Output executable name
EXEC = lexer

# Lex file
LEX_FILE = src/lexanalyser.l

# Default target
all: $(EXEC)

# Rule to compile the lex file using g++
$(EXEC): $(LEX_FILE)
	$(LEX) $(LEX_FILE)
	$(CXX) $(CXXFLAGS) lex.yy.c -o $(EXEC) -lfl

# Clean build files
clean:
	rm -f lex.yy.c $(EXEC)