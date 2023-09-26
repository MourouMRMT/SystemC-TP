#include "systemc.h"

typedef enum{att,envoie} t_state;

 SC_MODULE(TX)
{
	sc_in<bool>clk;
	sc_fifo_in<sc_lv<8>>din;
	sc_out<sc_logic> TxD;
	
	
	t_state state;
	
	
	sc_lv<8> temp;
	sc_logic parite;
	sc_int<8> i;
	
	void transmit();
	
	SC_CTOR(TX)
	{
		state=att;
		SC_THREAD(transmit);
	}
	
};