INCLUDE_DIR := include
SRC_DIR := src

CC := gcc
CCFLAGS := -I$(INCLUDE_DIR) -Wall -Wextra -pedantic

main:
	$(CC) $(SRC_DIR)/* $(CCFLAGS) -o classificacao-externa