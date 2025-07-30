#ifndef __DEFS_H__
#	define __DEFS_H__
#	include <stdio.h>

#	define VER "0.0.1 dev"

	enum arch_t {
		ARCH_X86_64 = 64,
		ARCH_I386 = 32,
	};

	typedef unsigned char		U8;
	typedef unsigned short		U16;
	typedef unsigned int		U32;
	typedef unsigned long long  U64;

	typedef char*				string_t;
	typedef U8					bool_t;

	extern FILE* infile;

#		define ARCH		ARCH_X86_64
	
#		define true			1
#		define false		0

#endif // __DEFS_H__
