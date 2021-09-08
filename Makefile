NAME =			fdf

CC =			gcc 

FLAGS =			-Wall -Wextra -Werror

RM =			rm -rf

DIR_HEADERS =	./headers/

DIR_SRCS =		./src/

SANITIZE = -fsanitize=address


LIBMLX =		-lmlx -framework OpenGL -framework AppKit libmlx.dylib

			

SRC =			fdf.c error.c utils.c get_next_line.c read_file.c draw.c
			
SRCS =			$(addprefix $(DIR_SRCS), $(SRC))



all:			$(NAME)

$(NAME) :		
				@make -C ./minilibx_mms
				@cp ./minilibx_mms/libmlx.dylib libmlx.dylib
				@make -C ./libft
				@cp ./libft/libft.a libft.a
				@$(CC) $(FLAGS) $(SRCS) -I $(DIR_HEADERS) $(LIBMLX) $(SANITIZE) libft.a  -o $(NAME)

norme:
				norminette $(DIR_SRCS) 
				norminette $(DIR_HEADERS)
# run:			
# 				@./miniRT Scene/new_scene.rt

clean:
				@make clean -C ./libft

fclean:			clean
				@make clean -C ./minilibx_mms
				@make fclean -C ./libft
				@$(RM) libmlx.dylib
				@$(RM) $(NAME)
				

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus