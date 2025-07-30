#include "magic.h"
#include "defs.h"
#include "logging.h"
#include "arch.h"
#include <stdio.h>
#include <string.h>
#include "fileutils.h"

int INTERNAL main(U16 argc, string_t argv[])
{
    printf("This is `disas` version %s for x86_%d.\n", VER, (int)ARCH);
    puts("USE OF THIS SOFTWARE FOR NON-AUTHORIZED PURPOSES IS ILLEGAL AND PUNISHABLE BY LAW.\n");

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
                puts("Further help can be found on the README.md file bundled with the program, or on the GitHub repo (mar1lusk1/disas).");
                return 0;
            case 'v':
                printf("Version: %s\n", VER);
                return 0;
            default:
                error(2, "Unknown option: %s\n", argv[1]);
        }
    }

    FILE* infile_ptr = fopen(argv[1], "rb");
    if (!infile_ptr) {
        error(1, "Cannot open file: %s.\n", argv[1]);
    }

    unsigned char buf[2048] = {0};
    size_t bytes_read = fread(buf, 1, sizeof(buf), infile_ptr);
    fclose(infile_ptr);

    remove_magic((string_t)buf);

    printf("file, no headers:\n");
    printf("%s\n", buf);
    return 0;
}

