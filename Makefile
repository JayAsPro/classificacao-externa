INCLUDE_DIR := include
SRC_DIR := src

CC := gcc
CCFLAGS := -I$(INCLUDE_DIR) -Wall -Wextra -pedantic

main:
	$(CC) $(SRC_DIR)/*.c $(CCFLAGS) -o classificacao-externa

clean:
	rm -f classificacao-externa
	rm -f part*.txt