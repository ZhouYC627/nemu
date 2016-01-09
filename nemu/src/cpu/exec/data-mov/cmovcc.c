#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "cmovcc-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "cmovcc-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "cmovcc-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */
//make_helper_v(push_i)
make_helper_v(cmova_rm2r)
make_helper_v(cmovae_rm2r)
make_helper_v(cmovb_rm2r)
make_helper_v(cmovbe_rm2r)
make_helper_v(cmovc_rm2r)
make_helper_v(cmove_rm2r)
make_helper_v(cmovg_rm2r)
make_helper_v(cmovge_rm2r)
make_helper_v(cmovl_rm2r)
make_helper_v(cmovle_rm2r)
make_helper_v(cmovs_rm2r)
make_helper_v(cmovns_rm2r)
make_helper_v(cmovne_rm2r)

/*
make_helper_v(jl_i)
make_helper_v(jle_i)
make_helper_v(jg_i)
make_helper_v(jge_i)
make_helper_v(ja_i)
make_helper_v(jae_i)
make_helper_v(jb_i)
make_helper_v(jbe_i)
make_helper_v(jne_i)
make_helper_v(jns_i)
*/
