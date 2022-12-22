CC = gcc

SRC_DIR       = src
BUILD_DIR     = builds
LOOPS_SRC_DIR = $(SRC_DIR)/Loops
LOOPS_DIR     = $(BUILD_DIR)/Loops

# Each executable you expect to be generated
LOOP_EXECS = $(LOOPS_DIR)/denominations $(LOOPS_DIR)/fibinocci $(LOOPS_DIR)/largest_and_smallest $(LOOPS_DIR)/pattern_printing $(LOOPS_DIR)/sum_of_digits  $(LOOPS_DIR)/sum_of_n_natural_numbers $(LOOPS_DIR)/triangle_pattern

CFLAGS = -Wall -Wextra -Wpedantic

all: $(LOOP_EXECS)

$(LOOPS_DIR)/%	: $(LOOPS_SRC_DIR)/%.c
	$(CC)	$(CFLAGS)	$<	-o	$@

