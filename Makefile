CC = gcc

SRC_DIR       = src
BUILD_DIR     = builds
LOOPS_SRC_DIR = $(SRC_DIR)/loops
LOOPS_DIR     = $(BUILD_DIR)/loops
STRINGS_SRC_DIR = $(SRC_DIR)/strings_and_arrays
STRINGS_DIR = $(BUILD_DIR)/strings


# Each executable you expect to be generated
LOOP_EXECS = $(LOOPS_DIR)/denominations $(LOOPS_DIR)/fibinocci $(LOOPS_DIR)/largest_and_smallest $(LOOPS_DIR)/pattern_printing $(LOOPS_DIR)/sum_of_digits  $(LOOPS_DIR)/sum_of_n_natural_numbers $(LOOPS_DIR)/triangle_pattern

STRINGS_EXECS = $(STRINGS_DIR)/matrix_operations $(STRINGS_DIR)/palindrome $(STRINGS_DIR)/sorting_and_searching $(STRINGS_DIR)/string_compare $(STRINGS_DIR)/string_reverse $(STRINGS_DIR)/string_to_ascii

CFLAGS = -Wall -Wextra -Wpedantic

.PHONY: all clean

all: $(STRINGS_EXECS) $(LOOP_EXECS) 

#loops: $(LOOP_EXECS)

#strings: $(STRINGS_EXECS)

$(STRINGS_DIR)/%  : $(STRINGS_SRC_DIR)/%.c
	$(CC)	$(CFLAGS)	$<	-o	$@

$(LOOPS_DIR)/%	: $(LOOPS_SRC_DIR)/%.c
	$(CC)	$(CFLAGS)	$<	-o	$@

# $(STRINGS_DIR)/%:	$(STRINGS_SRC_DIR)/%.c
# 	$(CC)	$(CFLAGS)	$<	-o	$@


clean:
	rm builds/loops/*.exe
	rm builds/strings/*.exe