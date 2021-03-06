#ifndef __REG_H__
#define __REG_H__

#include "common.h"
#include "../../lib-common/x86-inc/cpu.h"
enum { R_EAX, R_ECX, R_EDX, R_EBX, R_ESP, R_EBP, R_ESI, R_EDI };
enum { R_AX, R_CX, R_DX, R_BX, R_SP, R_BP, R_SI, R_DI };
enum { R_AL, R_CL, R_DL, R_BL, R_AH, R_CH, R_DH, R_BH };
enum { R_ES, R_CS, R_SS, R_DS, R_GS, R_FS };

typedef struct {
	lnaddr_t base;
	uint16_t limit;
}DTR;

typedef struct {
	union {
		struct {
			uint32_t RPL    : 2;
		    	uint32_t TI	: 1;
			uint32_t index  : 13;
		};
		uint16_t val;
	}Selector;
	struct {
	     lnaddr_t base;
	     uint32_t limit;
	     bool valid;
	};
} Sreg;

/* TODO: Re-organize the `CPU_state' structure to match the register
 * encoding scheme in i386 instruction format. For example, if we
 * access cpu.gpr[3]._16, we will get the `bx' register; if we access
 * cpu.gpr[1]._8[1], we will get the 'ch' register. Hint: Use `union'.
 * For more details about the register encoding scheme, see i386 manual.
 */

typedef struct {
	union{
	union {
		uint32_t _32;
		uint16_t _16;
		uint8_t _8[2];
	} gpr[8];

	/* Do NOT change the order of the GPRs' definitions. */

	struct{
	uint32_t eax, ecx, edx, ebx, esp, ebp, esi, edi;
	//uint16_t ax, cx, dx, bx, sp, bp, si, di;
	//uint8_t al, cl, dl, bl, ah, ch, dh, bh;
	};
	};
	swaddr_t eip;
	
	union{
    		struct{
			unsigned int CF:1;
			unsigned int   :1;
			unsigned int PF:1;
			unsigned int   :1;
			unsigned int AF:1;
			unsigned int   :1;
			unsigned int ZF:1;
			unsigned int SF:1;
			unsigned int TF:1;
			unsigned int IF:1;
			unsigned int DF:1;
			unsigned int OF:1;
			unsigned int OL:1;
			unsigned int IP:1;
			unsigned int NT:1;
			unsigned int   :1;
			unsigned int RF:1;
			unsigned int VM:1;
			unsigned int   :14;	
    		};
		unsigned int eflags;
	}EFLAGS;

	CR0 cr0; 
	CR3 cr3;
	DTR gdtr, idtr;
	volatile bool INTR;
	union	{
		Sreg sreg[6];
		struct{ Sreg ES, CS, SS, DS, GS, FS;};
	};
} CPU_state;

extern CPU_state cpu;

static inline int check_reg_index(int index) {
	assert(index >= 0 && index < 8);
	return index;
}

#define reg_l(index) (cpu.gpr[check_reg_index(index)]._32)
#define reg_w(index) (cpu.gpr[check_reg_index(index)]._16)
#define reg_b(index) (cpu.gpr[check_reg_index(index) & 0x3]._8[index >> 2])

extern const char* regsl[];
extern const char* regsw[];
extern const char* regsb[];


#endif
