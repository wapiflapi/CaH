CFLAGS = -Werror -Wall -pedantic -pie -fpie -FPIE -fstack-protector
LDFLAGS = -pie -fpie -FPIE
TARGET = hdsaas
OBJECTS = hdsaas.o

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(TARGET) $^

clean:
	$(RM) $(OBJECTS)
