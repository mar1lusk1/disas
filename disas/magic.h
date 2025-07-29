#ifndef __MAGIC_H__

// Declaration specifiers and attributes for cross-platform compatibility.

#   if defined(_MSC_VER)
#       define DECLSPEC(x) __declspec(x)
#       define DLLEXPORT DECLSPEC(dllexport)
#       define DLLIMPORT DECLSPEC(dllimport)
#       define INTERNAL
#   elif (defined(__GNUC__) || defined(__clang__))
#       define DECLSPEC(x) __attribute__((x))
#       if defined(_WIN32) || defined(__CYGWIN__)
#           define DLLEXPORT DECLSPEC(dllexport)
#           define DLLIMPORT DECLSPEC(dllimport)
#       else
#           define DLLEXPORT DECLSPEC(visibility("default"))
#           define DLLIMPORT
#       endif
#       define INTERNAL DECLSPEC(visibility("hidden"))
#   else
#       error Unsupported compiler.
#   endif
#   define DEPRECATED    DECLSPEC(deprecated)
#   define NORETURN      DECLSPEC(noreturn)
#endif /* __MAGIC_H__ */
