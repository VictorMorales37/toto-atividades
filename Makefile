.PHONY: all clean

# Get all lc-* directories
LC_DIRS := $(wildcard Leetcode/lc-*)

# Create build targets for each directory
TARGETS := $(patsubst Leetcode/lc-%,build-lc-%,$(LC_DIRS))

# Default target
all: $(TARGETS)

# Build each lc-* directory
build-lc-%: Leetcode/lc-%/main.c
	@echo "Compiling Leetcode/lc-$*/main.c..."
	gcc -o Leetcode/lc-$*/main Leetcode/lc-$*/main.c

# Clean all compiled binaries
clean:
	@echo "Cleaning compiled binaries..."
	@for dir in $(LC_DIRS); do \
		if [ -f $$dir/main ]; then \
			rm -f $$dir/main; \
			echo "Removed $$dir/main"; \
		fi \
	done

# Run a specific problem (usage: make run-1 for lc-1)
run-%: Leetcode/lc-%/main
	@Leetcode/lc-$*/main