CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
TARGET = shell
SRC = simple_shell.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

re: clean all

.PHONY: all clean re
