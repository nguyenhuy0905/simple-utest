CC := clang # or gcc

# a template Makefile to compile and run your test(s).
# this Makefile assumes you have the binary of the 
# test utility already

# directories. Change according to your project
# directory of the test source file
# directory of the simple-utest binary
SIMPLE_TEST_DIR := ./lib
# directory of test source code
SRC_DIR := ./test 
# directory for intermediate object files (.o)
OBJ_DIR := ./obj 
# test executable
TEST := ./test/test-something 

# find all test files
SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# export other environment variables if needed
# LD_LIBRARY_PATH should be exported in the following format:
# all: export LD_LIBRARY_PATH := $(LD_LIBRARY_PATH):/path/to/another/lib/dir/
all: export LD_LIBRARY_PATH := $(LD_LIBRARY_PATH):$(SIMPLE_TEST_DIR)
all: $(TEST)
	$^

# building (static) intermediate objects
# that will be combined into a singular test file.
# note: even though these are different files, do NOT name
# any function similar to one another.
$(TEST): $(OBJS)
	$(CC) -o $@ $^ -L$(SIMPLE_TEST_DIR) -lsimple-utest

# PHONY so that this step isn't automatically executed after the test binary
# is compiled
.PHONY: clean

# remove all the binary
clean:
	rm -f $(OBJS) $(TEST)
