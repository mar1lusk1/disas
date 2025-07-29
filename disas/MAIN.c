#include "magic.h"
#include "defs.h"
#include "logging.h"
#include <stdio.h>

#if (defined(__GNUC__))
// GNU defines the architecture macro different that MSVC.
#	if (defined(__x86_64__))
		// By default, ARCH is set to x86_64. Just include the header.
#		include "x86_64.h"
#	elif (defined(__i386__))
#		include "i386.h"
#		undef ARCH
#		define ARCH		ARCH_I386
#	elif (defined(__arm__))
#		error ARM support is comming soon.
#	else
#		error Unsupported architecture.
#	endif
#elif (defined(_MSC_VER))
#	if (defined(_M_X64))
		// By default, ARCH is set to x86_64.	
#	elif (defined(_M_IX86)
#		undef ARCH
#		define ARCH		ARCH_I386
#	elif (defined(_M_ARM)
#		error ARM support is comming soon.
#	else
#		error Unsupported architecture.
#	endif
#else
#	error Unsupported compiler.
#endif

void set_infile_with_path(string_t path)
{
	FILE* fp = fopen(path, "rb");

	if (!fp) {
		error(1, "Cannot open file: %s\n", path);
	}

	infile = fp;
}

int INTERNAL
main(U16 argc, string_t argv[])
{
	printf("This is `disas` version %s for x86_%d.\n", VER, (int)ARCH);
	puts("USE OF THIS SOFTWARE FOR NON-AUTHORIZED PURPOSES \
IS ILLEGAL AND PUNISHABLE BY LAW.\n");

	if (argc < 2)
		error(2, "No input file specified. Usage: %s [-h|-v] FILE\n", argv[0]);

	if (argv[1][0] == '-') { // If cmdarg starts with a dash, then it's a flag
		switch (argv[1][1]) {
			case 'h':
				printf("Usage: %s [-h|-v] FILE\n", argv[0]);
				puts("Options:");
				puts("  -h    Show this help message.");
				puts("  -v    Show version information.");
				puts("  FILE  The file to disassemble.");
				puts ("Further help can be found on the README.md file bundled\
with the program, or on the GitHub repo (mar1lusk1/disas).");
		
				return 0;
			case 'v':
				printf("Version: %s\n", VER);
				return 0;
			default:
				error(2, "Unknown option: %s\n", argv[1]);
		}
	}

	// If we reach here, then we have a file to disassemble.

}

