#ifndef __TABLE_X86_64__
#define __TABLE_X86_64__

#include "defs.h"

static const string_t x86_64_instructions[] = {
    "mov", "add", "sub", "mul", "div", "inc", "dec", "push", "pop", "jmp", "cmp", "call", "ret", "nop",
		"syscall", "sysret", "hlt", "int", "iret", "cld", "std", "sti", "cli"
};

static const string_t x86_64_registers[] = {
    "rax", "rbx", "rcx", "rdx", "rsi", "rdi", "rsp", "rbp",
    "r8",  "r9",  "r10", "r11", "r12", "r13", "r14", "r15",
    "eax", "ebx", "ecx", "edx", "esi", "edi", "esp", "ebp",
    "r8d", "r9d", "r10d", "r11d", "r12d", "r13d", "r14d", "r15d",
    "ax",  "bx",  "cx",  "dx",  "si",  "di",  "sp",  "bp",
    "r8w", "r9w", "r10w", "r11w", "r12w", "r13w", "r14w", "r15w",
    "al",  "bl",  "cl",  "dl",  "sil", "dil", "spl", "bpl",
    "r8b", "r9b", "r10b", "r11b", "r12b", "r13b", "r14b", "r15b"
};

static const U8 x86_64_instruction_opcodes[] = {
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
    0x90, // nop
		0x0F, // syscall
		0x0F, // sysret
		0xF4, // hlt
		0xCD, // int
		0xCF, // iret
		0xFC, // cld
		0xFD, // std
		0xFB, // sti
		0xFA  // cli
};

static const U8 x86_64_registers_binary[] = {
    0x00, /* rax */ 0x03, /* rbx */ 0x01, /* rcx */ 0x02, /* rdx */
    0x06, /* rsi */ 0x07, /* rdi */ 0x04, /* rsp */ 0x05, /* rbp */
    0x08, /* r8  */ 0x09, /* r9  */ 0x0A, /* r10 */ 0x0B, /* r11 */
    0x0C, /* r12 */ 0x0D, /* r13 */ 0x0E, /* r14 */ 0x0F, /* r15 */
    0x00, /* eax */ 0x03, /* ebx */ 0x01, /* ecx */ 0x02, /* edx */
    0x06, /* esi */ 0x07, /* edi */ 0x04, /* esp */ 0x05, /* ebp */
    0x08, /* r8d */ 0x09, /* r9d */ 0x0A, /* r10d */ 0x0B, /* r11d */
    0x0C, /* r12d */ 0x0D, /* r13d */ 0x0E, /* r14d */ 0x0F, /* r15d */
    0x00, /* ax  */ 0x03, /* bx  */ 0x01, /* cx  */ 0x02, /* dx  */
    0x06, /* si  */ 0x07, /* di  */ 0x04, /* sp  */ 0x05, /* bp  */
    0x08, /* r8w */ 0x09, /* r9w */ 0x0A, /* r10w */ 0x0B, /* r11w */
    0x0C, /* r12w */ 0x0D, /* r13w */ 0x0E, /* r14w */ 0x0F, /* r15w */
    0x00, /* al  */ 0x03, /* bl  */ 0x01, /* cl  */ 0x02, /* dl  */
    0x06, /* sil */ 0x07, /* dil */ 0x04, /* spl */ 0x05, /* bpl */
    0x08, /* r8b */ 0x09, /* r9b */ 0x0A, /* r10b */ 0x0B, /* r11b */
    0x0C, /* r12b */ 0x0D, /* r13b */ 0x0E, /* r14b */ 0x0F  /* r15b */
};

#endif /* __TABLE_X86_64__ */
