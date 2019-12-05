#include <iostream>
#include "CCode.h"

#pragma once

using namespace std;

class CDecode {
public:
	CDecode() {}
	virtual ~CDecode() { }
};

typedef struct {
	unsigned int OPCODE : 4;
	unsigned int OP1    : 4;
		     int OP2    : 8;	 
} SInstruction;

class CT1DecodeDirectFetch : public CDecode {
public:
	CT1DecodeDirectFetch(CFlash1KWord& code) : m_code_memory(code_ { }
	virtual ~CT1DecodeDirectFetch() { }

	bool do_fetch_from(int PC);
	bool do_decode();

	void show_instrcution();

    unsigned int get_opcode() { return m_instruction.OPCODE; }
    unsigned int get_op1() { return m_instruction.OP1; }
             int get_op2() { return m_instruction.OP2; }
private:

	CFlash1KWord& m_code_memory;
	string m_inst_buffer;
	SInstrcution m_instrcution;
		
};
