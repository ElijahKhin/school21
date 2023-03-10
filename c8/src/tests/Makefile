CC := gcc
CFLAGS := -c -std=c11
FLAGS := -Wall -Wextra -Werror -g -std=c11 -lcheck --coverage -fsanitize=address

# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)
TARGET_EXEC := final_program

BUILD_DIR := ./build
SRC_DIRS := ..

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. Make will incorrectly expand these otherwise.
SRCS := main.c scale.c rotate.c move.c parser.c ../struct/object3/create.c ../struct/object3/update.c ../struct/object3/free.c ../parser/core.c ../struct/object3/transformations/move.c ../struct/object3/transformations/rotate.c ../struct/object3/transformations/scale.c ../struct/vector3/add.c ../struct/vector3/rotate.c

# String substitution for every C/C++ file.
# As an example, hello.cpp turns into ./build/hello.cpp.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
# As an example, ./build/hello.cpp.o turns into ./build/hello.cpp.d
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP

.PHONY : tests
tests: CFLAGS+=$(FLAGS)
tests: clean $(BUILD_DIR)/$(TARGET_EXEC)
	./$(BUILD_DIR)/$(TARGET_EXEC)

.PHONY : gcov_report
gcov_report: tests
	geninfo $(shell find . -name '*.gcda' -or -name '*.gcno') -b . -o $(BUILD_DIR)/bebra
	genhtml $(BUILD_DIR)/bebra -o $(BUILD_DIR)/coverage

.PHONY : open
open: gcov_report
	open $(BUILD_DIR)/coverage/index.html

# The final build step.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(FLAGS)

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


.PHONY: clean
clean:
	@rm -rf .DS_Store *.o a.out

-include $(DEPS)
