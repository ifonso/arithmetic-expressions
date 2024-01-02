CC = gcc
CFLAGS = -I src
SOURCES = main.c src/stack.c src/expression.c src/AST.c
OUTPUT = output

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)