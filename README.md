#	`disas` -- minimal disassembly

`disas` is a small program able to convert ELF or MS-PE executables into
human-readable assembly code.

It supports both 32-bit and 64-bit x86, with future support for ARM planned.
Note the only compilers supported are MSVC, GCC and Clang, with best support
for MSVC.

`disas` got designed to be minimal, and extensible.
It was written on C and has an small, DRY codebase, and additionally includes
an API so you can make your own disassemblers effortlessly.

# Installation

Ensure you have an NT, BSD or Linux system (or anything that uses ELF or
MS-PE as the executable format), and a C compiler installed that supports C99,
GNU extensions or MSVC extensions, CMake or Visual Studio, and (finally),
[`git`](https://git-scm.com/) installed.

Now, the easiest way to install `disas` is to clone and build it from source.

Paste this into any terminal emulator:
```bash
# Note the dollar sign ($) is not part of the command, it's just a prompt indicator.
$ git clone https://github.com/mar1lusk1/disas.git
$ cd disas
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --config Release
$ cmake --install .
```

# Usage

## Command Line Interface (CLI)

`disas` includes a CLI you can use to get quick access to the disassembly
engine.

It has three options (note these have UNIX format):

---

| Option | Description                  | Example          | 
|--------|------------------------------|------------------|
| `-?`   | Displays help information    | `disas -?`       |
| `-v`   | Displays version information | `disas -v`       |
| `FILE` | Set the file to disassemble  | `disas file.exe` |

---

Or more briefly:

```
disas [-?|-v] FILE
```

## Application Programming Interface (API)

`disas` includes a C API you can use to create your own frontend for `disas`.

The most basic usage is as follows:

```c
#include <disas/disas.h>

int main(int argc, char *argv[])
{
	// Check if a file was provided
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return 1;
	}

	// Use Disas_Init to initialize the library._
	Disas_Init();

	// Set the input file for disassembly
	Disas_SetInputFile(argv[1]);

	// Set the output file for disassembly. This step is optional, as by default
	// it's set to stdout.
	Disas_SetOutputFile("output.asm");

	// And write to it
	Disas_WriteToOutput(Disas_Disassemble());

	// Cleanup and exit.
	Disas_Cleanup();_
	return 0;
}
```

As you can see, the API is pretty straight-forward and consistent.

The most important functions are:

	- `Disas_Init(void)`: Initializes the disassembly engine.
	- `Disas_SetInputFile(const string_t filename)`: Sets the input file to
		disassemble.
	- `Disas_SetOutputFile(const string_t outname)`: Sets the output file to write the
		disassembled code to. It is written to stdout by default.
	- `Disas_Disassemble(void)`: Disassembles the input file and returns a
		string with the disassembled code.
	- `Disas_WriteToOutput(const string_t output)`: Sets the output file's content
		to the provided string.
	- `Disas_Cleanup(void)`: Cleans up the disassembly engine and frees any
		resources used.

Every public function is prefixed with `Disas_` and follows `Pascal_Case`
naming.

Furthermore, you can find the complete API on the `api/disas.h` header file.

# Usage notice

**USE OF THIS PROGRAM FOR NON-AUTHORIZED PURPOSES IS ILLEGAL AND PUNISHED BY LAW.**

**THE AUTHORS AND CONTRIBUTORS OF THE WORK ARE NOT RESPONSIBLE IN ANY WAY FOR
DAMAGES CAUSED BY THE USE OF THIS PROGRAM.**

# License

The authors of this program have decided to give up all copyright and
related rights to the work worldwide, to the extent allowed by law
(public domain).

Furthermore, (as noted above), there is no warranty or liability of any kind,
to the extent permitted by applicable law.

See the [LICENSE](LICENSE) file bundled with the distribution for more
information, or visit the
[CC0 1.0 Universal](https://creativecommons.org/publicdomain/zero/1.0/)
license page for more information.

