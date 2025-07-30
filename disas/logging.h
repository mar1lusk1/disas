#ifndef __LOGGING_H__
#		define __LOGGING_H__

#		include "magic.h"
#		include "defs.h"
#		include <stdio.h>
#		include <stdarg.h>
#		include <stdlib.h>

	static inline void INTERNAL
	error(U8 ecode, const string_t fmt, ...)
	{
		va_list ap;
		va_start(ap, fmt);
			fprintf(stderr, "\x1b[31m[ERROR]\x1b[0m ");
			vfprintf(stderr, fmt, ap);
		va_end(ap);

		if (ecode > 0) { exit(ecode); }
	}

#endif /* __LOGGING_H__ */