#include "magic.h"
#include "defs.h"
#include "logging.h"
#include "arch.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "fileutils.h"
#include "i386.h"
#include "x86_64.h"

static void cli(int argc, const char *argv[]);
static size_t read_input_file(const char *filename, string_t buf, size_t bufsize);
static void disassemble_buffer(const string_t buf, size_t bytes_read);

// === main ===
int INTERNAL main(int argc, const char *argv[]) {
		printf("This is `disas` version %s for x86_%d.\n", VER, (int)ARCH);
		puts("USE OF THIS SOFTWARE FOR NON-AUTHORIZED PURPOSES IS ILLEGAL AND PUNISHABLE BY LAW.\n");

		cli(argc, argv);

		unsigned char buf[2048] = {0};
		size_t bytes_read = read_input_file(argv[1], buf, sizeof(buf));

		remove_magic(buf);  // buf is string_t

		printf("\nAssembly conversion:\n");
		disassemble_buffer(buf, bytes_read);
		return 0;
}

// === CLI Handling ===
static void INTERNAL cli(int argc, const char *argv[]) {
		if (argc < 2)
				error(2, "No input file specified. Usage: %s [-h|-v] FILE\n", argv[0]);

		if (argv[1][0] == '-') {
				switch (argv[1][1]) {
						case '?':
								printf("Usage: %s [-h|-v] FILE\n", argv[0]);
								puts("Options:");
								puts("  -?    Show this help message.");
								puts("  -v    Show version information.");
								puts("  FILE  The file to disassemble.");
								puts("Further help can be found in the README.md file or the GitHub repo.");
								exit(0);
						case 'v':
								printf("Version: %s\n", VER);
								exit(0);
						default:
								error(2, "Unknown option: %s\n", argv[1]);
				}
		}
}

// === File Reader ===
static size_t INTERNAL read_input_file(const char *filename, string_t buf, size_t bufsize) {
		FILE *infile_ptr = fopen(filename, "rb");
		if (!infile_ptr)
				error(1, "Cannot open file: %s.\n", filename);

		size_t bytes_read = fread(buf, 1, bufsize, infile_ptr);
		fclose(infile_ptr);
		return bytes_read;
}

// === Padding Detector (for PE files) ===
size_t get_padding_start(const U8 *buf, size_t bytes_read) {
    const U8 padding_byte = 0xCC;
    const U8 min_for_detection = 8;
    size_t count = 0;

    // First, count how many padding bytes at the end
    for (ptrdiff_t i = (ptrdiff_t)bytes_read - 1; i >= 0; --i) {
        if (buf[i] == padding_byte) {
            count++;
        } else {
            // Padding run ended
            break;
        }
    }

    // If run is less than min_for_detection, no padding detected
    if (count < min_for_detection)
        return bytes_read;

    // Return the start offset of padding
    return bytes_read - count;
}

// === Disassembler Core ===
static void INTERNAL disassemble_buffer(const string_t buf, size_t bytes_read) {
		const string_t *instructions;
		const U8 *opcodes;
		int num_instructions;

		if (ARCH == ARCH_X86_64) {
				instructions = x86_64_instructions;
				opcodes = x86_64_instruction_opcodes;
				num_instructions = sizeof(x86_64_instruction_opcodes) / sizeof(U8);
		} else {
				instructions = i386_instructions;
				opcodes = i386_instruction_opcodes;
				num_instructions = sizeof(i386_instruction_opcodes) / sizeof(U8);
		}

		size_t padding_start = get_padding_start(buf, bytes_read);
		printf("Debug: padding starts at offset 0x%zx of 0x%zx bytes\n", padding_start, bytes_read);

		for (size_t i = 0; i < bytes_read; ++i) {
				if (i >= padding_start) {
						continue;
				}

				int found = 0;
				for (int j = 0; j < num_instructions; ++j) {
						if (buf[i] == opcodes[j]) {
								printf("%04zx: %s\n", i, instructions[j]);
								found = 1;
								break;
						}
				}

				if (!found && buf[i] != 0) {
						printf("%04zx: ??? [binary: 0x%02x]\n", i, buf[i]);
				}
		}
}

