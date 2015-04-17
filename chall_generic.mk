PLAYERDIR	= player/
SERVERDIR	= server/
DEVDIR		?= dev/

PLAYERFILES	?=
SERVERFILES	?=

PLAYERFILES	:= $(addprefix $(PLAYERDIR),$(PLAYERFILES))
SERVERFILES	:= $(addprefix $(SERVERDIR),$(SERVERFILES))


all: dev server player

# check for the impossible error

check:
	@if [ $(shell realpath -s $(PLAYERDIR)) == "/" ]; \
	then \
	echo "PLAYERDIR is set to /. YOU DONT WANT THAT!"; \
	fi; \
	if [ $(shell realpath -s $(DEVDIR)) == "/" ]; \
	then \
	echo "DEVDIR is set to /. YOU DONT WANT THAT!"; \
	fi; \
	if [ $(shell realpath -s $(SERVERDIR)) == "/" ]; \
	then \
	echo "SERVERDIR is set to /. YOU DONT WANT THAT!"; \
	fi;

# Setup server directory

server: $(SERVERFILES)
	-@rmdir --ignore-fail-on-non-empty $(SERVERDIR) &> /dev/null || true

$(SERVERDIR)%:	$(DEVDIR)%
	@if [ ! -d $(SERVERDIR) ]; \
	then \
		mkdir -p $(SERVERDIR); \
	fi;

	cp -r $^ $(SERVERDIR)

# Setup player directory

player: $(PLAYERFILES)
	-@rmdir --ignore-fail-on-non-empty $(PLAYERDIR) &> /dev/null || true

$(PLAYERDIR)%:	$(DEVDIR)%
	@if [ ! -d $(PLAYERDIR) ]; \
	then \
		mkdir -p $(PLAYERDIR); \
	fi;

	cp -r $^ $(PLAYERDIR)


# Exec sub-makefile

dev:
	@if [ -f $(DEVDIR)Makefile ]; \
	then \
		make -C $(DEVDIR); \
	fi;

# If some dependancy in DEVDIR are not present
# then there is probably a sub-makefile that can
# create them

$(DEVDIR)%:
	@if [ -f $(DEVDIR)Makefile ]; \
	then \
		make -C $(DEVDIR) $(@:$(DEVDIR)%=%); \
	fi;

clean:
	@if [ -f $(DEVDIR)Makefile ]; \
	then \
		make -C dev/ clean; \
	fi;

fclean: clean
	$(RM) -r $(PLAYERFILES)
	$(RM) -r $(SERVERFILES)
	-@rmdir --ignore-fail-on-non-empty $(PLAYERDIR) &> /dev/null || true
	-@rmdir --ignore-fail-on-non-empty $(SERVERDIR) &> /dev/null || true
	@if [ -f $(DEVDIR)Makefile ]; \
	then \
		make -C dev/ fclean; \
	fi;

real-fclean: fclean
	$(RM) -r $(PLAYERDIR)
	$(RM) -r $(SERVERDIR)

re: fclean all

# It would be nice to test the program

test:
	@if [ -f test/test.py ]; \
	then \
		nosetests3 -v test/test.py; \
	else \
		echo "There is no test available"; \
	fi;

.PHONY: all clean fclean dev re test real-fclean
