#include "CCode.h"

#pragma once

using namespace std;

class CDecode {
public:
	CDecode() { }
	virtual ~CDecode() { }
};

enum { R0=0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15 };

enum { MOV0=0, MOV1, MOV2, MOV3, ADD, SUB, JZ, MUL, MOV4, MOV5 };

typedef struct {
	unsigned int OPCODE : 4; // 4bit
	unsigned int OP1    : 4; // 4bit
		     int OP2    : 8; // 8bit
} SInstruction;

class CT1DecodeDirectFetch : public CDecode {
public:
	CT1DecodeDirectFetch(CFlash1KWord& code) : m_code_memory(code) { }
	virtual ~CT1DecodeDirectFetch() { }

	bool do_fetch_from(int PC);
	bool do_decode();

    unsigned int get_opcode() { return m_instruction.OPCODE; }
    unsigned int get_op1()    { return m_instruction.OP1; }
    unsigned int get_op2()    { return m_instruction.OP2; }

	void show_instruction();
private:
	CFlash1KWord& m_code_memory;
	string m_inst_buffer;
	SInstruction m_instruction;

};
