#-------------compilateur------------------#
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -O3 -g
#--------------Name-------------------------#
NAME = ft_minishell1

#--------------Sources----------------------#
FILES_CORE =	main.c\
	    		ft_dub_environ.c\
	    		ft_exec_bin.c\
	    		ft_parse_input.c\
	    		ft_get_args.c\
	    		ft_cd.c\
	    		ft_cd2.c\
	    		ft_editenv.c\
	    		ft_envtools.c\
	    		ft_envtools2.c\
	    		ft_tools.c

FILES_INPUTS =	ft_arrows.c\
			  	ft_arrows2.c\
			  	ft_special.c\
			  	ft_charmanage.c\
			  	ft_cursor.c\
			  	ft_delete.c\
			  	ft_env.c\
			  	ft_imputs.c\
			  	ft_clean.c\
			  	ft_lstrmanage.c\
			  	ft_managechar.c\
			  	ft_put.c\
			  	ft_move.c

FILES_SIGNALS =	ft_init_suite.c ft_init.c

OBJECT =		$(patsubst %.c,%.o,$(FILES_CORE))\
				$(patsubst %.c,%.o,$(FILES_INPUTS))\
				$(patsubst %.c,%.o,$(FILES_SIGNALS))
BASEDIR_CORE = 	srcs/core
BASEDIR_INPUTS = srcs/inputs
BASEDIR_SIGNALS = srcs/signals

OBJECT_DIR = objs

#CURRENT_DIR = $(shell pwd)/$(NAME)
#--------------Actions----------------------#

.PHONY: all, fclean, clean, re

all: $(NAME)

$(NAME): $(OBJECT_DIR)
	@echo "\033[4;1;33m***   Creation de la LIBFT   ***\033[0m"
	@echo "\033[4;1;35m ... Patientez svp ...\033[0m"
	@make -C includes/libft
	@echo "\033[1;32m>>> libft... ok  <<<\033[0m"
	@echo "\033[4;1;33m***   Compilation de ft_sh1  ***\033[0m"
	@$(CC) -c $(CFLAGS) $(addprefix $(BASEDIR_CORE)/, $(FILES_CORE)) \
	$(addprefix $(BASEDIR_INPUTS)/, $(FILES_INPUTS)) \
	$(addprefix $(BASEDIR_SIGNALS)/, $(FILES_SIGNALS))
	@$(CC) -o $(NAME) $(OBJECT) -L ./includes/libft -l ft -L /usr/lib -ltermcap
	@echo "\033[1;32m>>> ft_sh1... ok <<<\033[0m"
	@bash -c "sh setIcon.sh icon/gladosh_icon.png ft_minishell1"
	@bash -c "touch auteur && echo \"shabbach\" > auteur"
	@bash -c "sh setIcon.sh icon/auteur_icon.png auteur"
	@mv *.o objs
#@echo $(CURRENT_DIR)

clean :
	@echo "\033[4;1;31mClean OBJS      >>\033[0m     \033[1;32mok.\033[0m"
	@rm -Rf $(OBJECT_DIR)

fclean: clean
	@echo "\033[4;1;31mClean ft_sh1    >>\033[0m     \033[1;32mok.\033[0m"
	@rm -Rf $(NAME)

re:	fclean all

$(OBJECT_DIR):
		@mkdir objs

