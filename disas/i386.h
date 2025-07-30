#ifndef __TABLE_I386_H__
#define __TABLE_I386_H__

#include "defs.h"

static const string_t i386_instructions[] = {
		"mov", "add", "sub", "mul", "div", "inc", "dec", "push", "pop", "jmp", "cmp", "call", "ret", "nop",
		"syscall", "sysret", "hlt", "int", "iret", "cld", "std", "sti", "cli"
};
static const string_t i386_registers[] = {
		"eax", "ebx", "ecx", "edx", "esi", "edi", "esp", "ebp",
		"ax",  "bx",  "cx",  "dx",  "si",  "di",  "sp",  "bp",
		"al",  "bl",  "cl",  "dl"
};
static const U8 i386_instruction_opcodes[] = {
		0x89, // mov
		0x01, // add
		0x29, // sub
		0xF7, // mul
		0xF7, // div
		0x40, // inc
		0x48, // dec
		0x50, // push
		0x58, // pop
		0xE9, // jmp
		0x39, // cmp
		0xE8, // call
		0xC3, // ret
		0x90,  // nop
		0x0F, // syscall
		0x0F, // sysret
		0xF4, // hlt
		0xCD, // int
		0xCF, // iret
		0xFC, // cl
		0xFD, // std
		0xFB, // sti
		0xFA  // cli
};
static const U8 i386_registers_binary[] = {
		0x00, /* eax */ 0x03, /* ebx */ 0x01, /* ecx */ 0x02, /* edx */
		0x06, /* esi */ 0x07, /* edi */ 0x04, /* esp */ 0x05, /* ebp */
		0x00, /* ax  */ 0x03, /* bx  */ 0x01, /* cx  */ 0x02, /* dx  */
		0x06, /* si  */ 0x07, /* di  */ 0x04, /* sp  */ 0x05, /* bp  */
		0x00, /* al  */ 0x03, /* bl  */ 0x01, /* cl  */ 0x02  /* dl  */
};

#endif /* __TABLE_I386_H__ */
