### If you wish to use extra libraries (math.h for instance),
### add their flags here (-lm in our case) in the "LIBS" variable.

# LIBS = -lm

# ###
# CFLAGS  = -std=c99
# CFLAGS += -g
# CFLAGS += -Wall
# CFLAGS += -Wextra
# CFLAGS += -pedantic
# CFLAGS += -Werror
# CFLAGS += -Wmissing-declarations
# CFLAGS += -DUNITY_SUPPORT_64 -DUNITY_OUTPUT_COLOR

# ASANFLAGS  = -fsanitize=address
# ASANFLAGS += -fno-common
# ASANFLAGS += -fno-omit-frame-pointer




# .PHONY: test
# test: tests.out
# 	@./tests.out

# .PHONY: memcheck
# memcheck: ./*.c ./*.h
# 	@echo Compiling $@
# 	@$(CC) $(ASANFLAGS) $(CFLAGS) test-framework/unity.c ./*.c -o memcheck.out $(LIBS)
# 	@./memcheck.out
# 	@echo "Memory check passed"

# .PHONY: clean
# clean:
# 	rm -rf *.o *.out *.out.dSYM


# tests.out: ./*.c ./*.h
# 	@echo Compiling $@
# 	@$(CC) $(CFLAGS) test-framework/unity.c ./*.c -o tests.out $(LIBS)


# Version 2 makefile (base)

# CC = gcc
# CFLAGS = -Wall -Wextra -std=c99
# TARGET = gorasm
# SRC = gorasm.c

# .PHONY: all clean

# all: $(TARGET)

# $(TARGET): $(SRC)
# 	$(CC) $(CFLAGS) -o $@ $<

# run: $(TARGET)
# 	./$(TARGET)

# clean:
# 	rm -f $(TARGET)

# Version 3 makefile (base+sanitize)

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SANITIZEFLAGS = -fsanitize=address -fno-omit-frame-pointer -g
TARGET = gorasm
SRC = gorasm.c

.PHONY: all clean sanitize

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

sanitize: $(SRC)
	$(CC) $(CFLAGS) $(SANITIZEFLAGS) -o $(TARGET) $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
