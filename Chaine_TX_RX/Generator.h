#include "systemc.h"


 SC_MODULE(Generator)
{
	sc_fifo_out<sc_lv<8>>din;
	
	void generate()
	{
		while(1)
		{
			if(din.num_free()!=0)
			{
				din.write(01010101); //0x55 => 85
			}
			wait(200,SC,NS);
		}
		
	}
	
	SC_CTOR(Generator)
	{
		SC_THREAD(generate);
	}
};