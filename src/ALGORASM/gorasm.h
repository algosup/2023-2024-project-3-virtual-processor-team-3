#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <getopt.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>

#define MAX_DATA_MEMORY 2048
#define MAX_CODE_MEMORY 2048
#define MAX_MNEMO_LENGTH 50
#define MAX_OPRD_COUNT 3
#define MAX_TOKENS 4
#define MAX_CHAR_PER_LINE_AMNT 4096
#define MAX_BYTE_ARRAY_DECLR 512
#define MAX_HALF_ARRAY_DECLR 256
#define MAX_WORD_ARRAY_DECLR 128
#define MAX_INSTR_COUNT 64
#define MAX_PROGRAM_MEMORY 4096

#define PRINT_WELCOME_DBG printf("🎉 🤖 < Welcome to ALGORASM, debugger mode!)\n\n"); // usleep(2000000); printf("🤖 < I will start by extracting all the data from the data segment!)\n\n"); // usleep(2000000);

// #include "ui.h"
#include "types.h"
#include "debug.h"
#include "symbols.h"
#include "lineParser.h"
// #include "encoder.h"