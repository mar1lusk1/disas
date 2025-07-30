#include "fileutils.h"
#include "logging.h"
#include "arch.h"
#include <stdio.h>

FILE* infile = NULL;

void set_infile_with_path(string_t path)
{
    FILE* fp = fopen(path, "rb");
    if (!fp) {
        error(1, "Cannot open file: %s\n", path);
    }
    infile = fp;
}

void remove_magic(const string_t str)
{
    // Check for ELF magic: 0x7F 'E' 'L' 'F'.
    if (str && (unsigned char)str[0] == 0x7F && str[1] == 'E' && str[2] == 'L' && str[3] == 'F') {
        if (ARCH == ARCH_X86_64) {
            for (int i = 0; i < 0x40; ++i)
                str[i] = 0;
        }
        else if (ARCH == ARCH_I386) {
            for (int i = 0; i < 0x34; ++i)
                str[i] = 0;
        }
        return;
    }
    // Now the MS PE one. It starts with 0x4D 0x5A ('MZ').
    if (str && (unsigned char)str[0] == 0x4D && str[1] == 0x5A) {
        for (int i = 0; i < 0x40; ++i)
            str[i] = 0;
        unsigned int pe_offset = *(const unsigned int *)(str + 0x3C);
        unsigned int pe_struct_size = (ARCH == ARCH_X86_64) ? 264 : 248;
        unsigned int end = pe_offset + pe_struct_size;
        for (unsigned int i = 0; i < end; ++i)
            str[i] = 0;
    }
}
