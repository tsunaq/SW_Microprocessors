#include <iostream>
#include "CRegister.h"

using namespace std;

void C16RegisterFile::show_regs() {
	cout << "----- register file -----" << endl;
	for(int i=0;i<10; i++)
		cout << " R" << i << ": " << m_regs[i] << endl;
	
	for(int i=10;i<16; i++)
		cout << " R" << i << ": " << m_regs[i] << endl;
}
