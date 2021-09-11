NAME =			fdf

CC =			gcc 

FLAGS =			-Wall -Wextra -Werror

RM =			rm -rf

DIR_HEADERS =	./headers/

DIR_SRCS =		./src/

SANITIZE = -fsanitize=address


LIBMLX =		-lmlx -framework OpenGL -framework AppKit libmlx.dylib

			

SRC =			fdf.c error.c utils.c utils1.c  get_next_line.c read_file.c draw.c
SRC_BONUS =			fdf_bonus.c error.c utils_bonus.c utils1.c get_next_line.c read_file.c draw_bonus.c
			
SRCS =			$(addprefix $(DIR_SRCS), $(SRC))
SRCS_BONUS = 	$(addprefix $(DIR_SRCS), $(SRC_BONUS))


all:			$(NAME)

$(NAME) :		
				@make -C ./minilibx_mms
				@cp ./minilibx_mms/libmlx.dylib libmlx.dylib
				@make -C ./libft
				@cp ./libft/libft.a libft.a
				@$(CC) $(FLAGS) $(SRCS) -I $(DIR_HEADERS) $(LIBMLX)  libft.a  -o $(NAME)

bonus:			fclean
				@make -C ./minilibx_mms
				@cp ./minilibx_mms/libmlx.dylib libmlx.dylib
				@make -C ./libft
				@cp ./libft/libft.a libft.a
				@$(CC) $(FLAGS) $(SRCS_BONUS) -I $(DIR_HEADERS) $(LIBMLX)  libft.a  -o $(NAME)


clean:
				@make clean -C ./libft

fclean:			clean
				@make clean -C ./minilibx_mms
				@make fclean -C ./libft
				@$(RM) libmlx.dylib libft.a
				@$(RM) $(NAME)
				

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus