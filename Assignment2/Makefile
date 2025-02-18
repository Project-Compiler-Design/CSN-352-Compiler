# Directories
SRC_DIR = src
BUILD_DIR = .

# Tools and flags
CC      = gcc
LEX     = flex
YACC    = bison
CFLAGS  = -g -Wall
LIBS    = -lm

# Source files in src folder
YACC_FILE = $(SRC_DIR)/parser.y
LEX_FILE  = $(SRC_DIR)/scanner.l

# Output files
BISON_C = parser.c
BISON_H = y.tab.h
LEX_C = scanner.c
OUTPUT = parser

# Default target
all: $(OUTPUT)

# Build the parser executable
$(OUTPUT): $(BISON_C) $(LEX_C)
	$(CC) -o $(OUTPUT) $(BISON_C) $(LEX_C) $(LIBS)

# Generate parser.c and y.tab.h from parser.y
$(BISON_C) $(BISON_H): $(YACC_FILE)
	$(YACC) -d -o $(BISON_C) $(YACC_FILE) -y
	mv parser.h y.tab.h

# Generate scanner.c from scanner.l (depends on y.tab.h)
$(LEX_C): $(LEX_FILE) $(BISON_H)
	$(LEX) -o $(LEX_C) $(LEX_FILE)

# Clean up generated files
clean:
	rm -f $(OUTPUT) $(BISON_C) $(BISON_H) $(LEX_C)

.PHONY: all clean
