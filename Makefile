CC := clang

# files
SRCS := $(wildcard ./src/*.c)
OBJS := $(patsubst ./src/%.c,./obj/%.o,$(SRCS))
LIB := ./lib/libsimple-utest.so

OPTS :=

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) -fPIC -shared -o $@ $^ $(OPTS)

$(OBJS): ./obj/%.o: ./src/%.c
	$(CC) -fPIC -c -o $@ $^ $(OPTS)

.PHONY: test

test: export LD_LIBRARY_PATH := ${LD_LIBRARY_PATH}:./lib/
test: ./test/test-something
	$^
	
./test/test-something: $(LIB) ./test/test-something.c
	$(CC) -o $@ $^ -L./lib/ -lsimple-utest $(OPTS)

.PHONY: clean

clean:
	rm -f $(OBJS) $(LIB) ./test/test-something
