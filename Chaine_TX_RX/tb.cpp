#include"systemc.h"
#include"Generator.h"
#include"TX.h"

int sc_main(int argc,char *argv[])
{
	sc_clock clk("clk",10,SC_NS,0.5,5,SC_NS);
	sc_fifo<sc_lv<8>>f;
	sc_signal TxD;
	
	
	sc_trace_file *my_trace;
	my_trace = sc_create_vcd_trace_file("tb");
	sc_trace(my_trace,clk,"Clk");
	sc_trace(my_trace,TxD,"txd");
	
	
	//Modules
	Generator gen("G1");
	TX_ transmitter("TX1");
	
	//I/O
	
	gen(f);
	transmitter(clk,f,TxD);
	
	
	//Run
	
	sc_start();
	
	sc_close_vcd_trace_file(my_trace);
	
	return EXIT_SUCCESS;
	

}