#ifndef ARCH_H
#define ARCH_H

#include "defs.h"

/* Architecture detection and macros */
#if defined(__GNUC__)
# if defined(__x86_64__)
#  define ARCH ARCH_X86_64
#  include "x86_64.h"
# elif defined(__i386__)
#  define ARCH ARCH_I386
#  include "i386.h"
# elif defined(__arm__)
#  error ARM support is coming soon.
# else
#  error Unsupported architecture.
# endif
#elif defined(_MSC_VER)
# if defined(_M_X64)
#  define ARCH ARCH_X86_64
# elif defined(_M_IX86)
#  define ARCH ARCH_I386
# elif defined(_M_ARM)
#  error ARM support is coming soon.
# else
#  error Unsupported architecture.
# endif
#else
# error Unsupported compiler.
#endif

#endif /* ARCH_H */
