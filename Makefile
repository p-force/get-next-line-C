HEADER = get_next_line.h
SRC = main.c get_next_line.c get_next_line_utils.c
BUF_S = BUFFER_SIZE=10
FLAG = -D

all: $(HEADER)
	@echo "\033[1m\033[38;5;11m gcc $(SRC) $(FLAG) $(BUF_S)\n \033[0m"
	@gcc $(SRC) $(FLAG) $(BUF_S)
	@./a.out

fclean:
	@echo "\033[1m\033[38;5;11m rm a.out\n \033[0m"
	@rm a.out

re: fclean all

.PHONY: all fclean re