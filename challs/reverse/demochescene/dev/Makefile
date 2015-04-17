
NAME = demochescene

CIPH = second_stage/second.ciph \
	third_stage/third.ciph \
	fourth_stage/fourth.ciph \
	flag_stage/demochescene.ciph

RM = rm -f

all: $(NAME)

$(NAME): make_stage build_binary

make_stage:
	make -C setup/
	make -C second_stage/
	make -C third_stage/
	make -C fourth_stage/
	make -C flag_stage/
	./cipher_them_all.py

build_binary:
	cp setup/demochescene demochescene
	objcopy --add-section hidden1=second_stage/second.ciph demochescene demochescene
	objcopy --add-section hidden2=third_stage/third.ciph demochescene demochescene
	objcopy --add-section hidden3=fourth_stage/fourth.ciph demochescene demochescene
	objcopy --add-section demochescene=flag_stage/demochescene.ciph demochescene demochescene

clean:
	make -C setup/ clean
	make -C second_stage/ clean
	make -C third_stage/ clean
	make -C fourth_stage/ clean
	make -C flag_stage/ clean
	$(RM) $(CIPH)

fclean: 
	make -C setup/ fclean
	make -C second_stage/ fclean
	make -C third_stage/ fclean
	make -C fourth_stage/ fclean
	make -C flag_stage/ fclean
	$(RM) $(CIPH)
	$(RM) $(NAME)

re: fclean all


.PHONY: all make_stage build_binary clean fclean re
