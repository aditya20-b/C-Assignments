CC = gcc

SRC_DIR       = src
BUILD_DIR     = builds
LOOPS_SRC_DIR = $(SRC_DIR)/loops
LOOPS_DIR     = $(BUILD_DIR)/loops
STRINGS_SRC_DIR = $(SRC_DIR)/strings_and_arrays
STRINGS_DIR = $(BUILD_DIR)/strings
FUNCTIONS_SRC_DIR = $(SRC_DIR)/functions_and_recursion
FUNCTIONS_DIR = $(BUILD_DIR)/functions

# Each executable you expect to be generated
LOOP_EXECS = $(LOOPS_DIR)/denominations $(LOOPS_DIR)/fibinocci $(LOOPS_DIR)/largest_and_smallest $(LOOPS_DIR)/pattern_printing $(LOOPS_DIR)/sum_of_digits  $(LOOPS_DIR)/sum_of_n_natural_numbers $(LOOPS_DIR)/triangle_pattern

STRINGS_EXECS = $(STRINGS_DIR)/array_reverse $(STRINGS_DIR)/matrix_operations $(STRINGS_DIR)/mean_median_mode $(STRINGS_DIR)/palindrome $(STRINGS_DIR)/remove_vowels $(STRINGS_DIR)/sorting_and_searching $(STRINGS_DIR)/string_compare $(STRINGS_DIR)/string_reverse $(STRINGS_DIR)/string_to_ascii $(STRINGS_DIR)/substring

FUNCTION_EXECS = $(FUNCTIONS_DIR)/is_prime $(FUNCTIONS_DIR)/factorial $(FUNCTIONS_DIR)/print_till_zero $(FUNCTIONS_DIR)/string_reverse $(FUNCTIONS_DIR)/fibonacci_using_recursion $(FUNCTIONS_DIR)/sum_of_all_elements $(FUNCTIONS_DIR)/sum_of_even_numbers

CFLAGS = -Wall -Wextra -Wpedantic

.PHONY: all clean

all: $(STRINGS_EXECS) $(LOOP_EXECS) $(FUNCTION_EXECS)

loops: $(LOOP_EXECS)

strings: $(STRINGS_EXECS)

functions: $(FUNCTION_EXECS)

$(STRINGS_DIR)/%  : $(STRINGS_SRC_DIR)/%.c
	$(CC)	$(CFLAGS)	$<	-o	$@

$(LOOPS_DIR)/%	: $(LOOPS_SRC_DIR)/%.c
	$(CC)	$(CFLAGS)	$<	-o	$@

$(FUNCTIONS_DIR)/%:	$(FUNCTIONS_SRC_DIR)/%.c
	$(CC)	$(CFLAGS)	$<	-o	$@


clean:
	rm builds/loops/*.exe
	rm builds/strings/*.exe
	rm builds/functions/*.exe