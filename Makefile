
CFILES = fdf.c countRow.c creat_tab.c free_matrix.c get_next_line_utils.c get_next_line.c initial_data.c \
	message_error.c mlx_event.c mlx_init.c remplir_tab.c zome_iso.c bresenham_algo.c initialBresenhame.c \
	description.c check_arg.c

OFILES = ${CFILES:.c=.o}

CBONUS = fdf_bonus.c check_data_mouve_bonus.c initialBresenhame_bonus.c mlx_event_1_bonus.c mlx_event_2_bonus.c \
	mlx_event_3_bonus.c bresenham_algo_bonus.c description_bonus.c countRow_bonus.c creat_tab_bonus.c \
	free_matrix_bonus.c get_next_line_utils.c get_next_line.c initial_data_bonus.c message_error_bonus.c\
	mlx_init_bonus.c remplir_tab_bonus.c zome_iso_bonus.c check_arg_bonus.c

OBONUS = ${CBONUS:.c=.o}

CC = gcc
W = -Wall -Werror -Wextra
FLAGS = -lmlx -framework openGL -framework Appkit
MATH_FLAGS = -lm
INC = fdf.h
INC_B = fdf_bonus.h
NAME = fdf

all : ${NAME}

${NAME} : ${OFILES} ${INC}
	@make -C ./FDF_libft
	@$(CC) $(OFILES) $(FLAGS) $(MATH_FLAGS) ./FDF_libft/libft.a -o $(NAME)

%.o:%.c
	@${CC} ${W} -Imlx -o $@ -c $<
	@echo "$@ created"

clean:
	@rm -f *.o
	@make fclean -C ./FDF_libft

fclean : clean
	@rm -f ${NAME}

re : fclean all

bonus: all ${OBONUS} $(INC_B)
	@$(CC) $(OBONUS) $(FLAGS) $(MATH_FLAGS) ./FDF_libft/libft.a  -o $(NAME)
	@echo "$(NAME) created"