#include"systemc.h"
#include"altbit.h"

int sc_main(int argc,char *argv[])
{
	sc_clock clk("clk",10,SC_NS,0.5,5,SC_NS);
	sc_signal<bool> E;
	sc_signal<bool> Err;
	
	sc_trace_file *my_trace;
	my_trace = sc_create_vcd_trace_file("tb");
	sc_trace(my_trace,clk,"H");
	sc_trace(my_trace,E,"E");
	sc_trace(my_trace,Err,"Err");

	AltBit myaltbit("alt1");
	myaltbit(E,clk,Err);
	
	E=0;
	sc_start(10,SC_NS);
	E=1;
	sc_start(10,SC_NS);
	E=0;
	sc_start(10,SC_NS);
	E=1;
	sc_start(20,SC_NS);	
	E=0;
	sc_start(10,SC_NS);
	E=1;
	sc_start(10,SC_NS);
	E=0;
	sc_start(30,SC_NS);
	E=1;
	sc_start(30,SC_NS);
	
	
	sc_close_vcd_trace_file(my_trace);
	
	return EXIT_SUCCESS;
}