#include "cpu/exec/template-start.h"

#define instr jmp

static void do_execute() {
	print_asm_template1();
	if (ops_decoded.opcode ==0xeb||ops_decoded.opcode==0xe9){  //im
		cpu.eip+=(DATA_TYPE_S)op_src->val;
		if (DATA_BYTE==2){
			cpu.eip&=0x0000ffff;
		}
	}
	else{				//rm
		if (DATA_BYTE==2){
			cpu.eip=(op_src->val&0x0000ffff);
		}
		else{
			cpu.eip=(op_src->val);
		}
		if (op_src->type==OP_TYPE_REG){
			cpu.eip-=2;
		}
		else if (op_src->type==OP_TYPE_MEM){
			cpu.eip-=7;
		}
	}
	//print_asm_template1();
}

//make_instr_helper(i)
make_instr_helper(i)
#if DATA_BYTE==2 || DATA_BYTE==4
make_instr_helper(rm)
#endif
/*
make_helper(concat(jmp_i_,SUFFIX)){
	//cpu.eip+=op_src->val;
	//printf("%x\n",cpu.eip);
	cpu.eip+=instr_fetch(eip + 1, DATA_BYTE);
	//printf("%x\n",cpu.eip);
	if (ops_decoded.is_data_size_16)
                cpu.eip&=0x0000ffff;
	print_asm("jmp" str(SUFFIX) " 0x%x",cpu.eip);
	//print_asm_template1();
	return 1+DATA_BYTE;
}
make_helper(concat(jmp_rm_,SUFFIX)){
	
	concat(decode_rm_,SUFFIX)(cpu.eip+1);
	if (DATA_BYTE==2){
		cpu.eip=MEM_R(op_dest->val)&0x0000ffff;
	}
	else{
		cpu.eip=MEM_R(op_dest->val);
	}
	printf("%s(%d)\n",op_src->str,DATA_BYTE);
	print_asm_template1();
	//print_asm("jmp" str(SUFFIX) " %s",op_src->str);
	return 2;	
}*/
#include "cpu/exec/template-end.h"
