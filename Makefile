# For now, there's nothing to build using this Makefile
CC := clang

# files
SRCS := $(wildcard ./src/*.c)
OBJS := $(patsubst ./src/%.c,./obj/%.o,$(SRCS))
LIB := ./so/libdead-simple-test.so

all: 
	@echo "As of now, there's no need to build anything"

.PHONY: demo

demo: ./demo/demo.c
	$(CC) -o demo/$@ -Iheader/ $^

$(LIB): $(OBJS)
	$(CC) -o $@ -shared -fPIC $^

$(OBJS): ./obj/%.o: ./src/%.c
	$(CC) -o $@ -c $^

.PHONY: clean

clean:
	rm -f $(OBJS) $(LIB)
