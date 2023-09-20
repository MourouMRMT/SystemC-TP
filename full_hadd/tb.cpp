#include"systemc.h"
#include"fhadd.h"

int sc_main(int argc,char *argv[])
{
	sc_signal<bool> A;
	sc_signal<bool> B;
	sc_signal<bool> Ci;
	sc_signal<bool> S;
	sc_signal<bool> Co;
	
	Fullhadd fhadd("f1");
	
	fhadd(A,B,Ci,S,Co);

	sc_trace_file *my_trace;
	my_trace = sc_create_vcd_trace_file("tb");
	sc_trace(my_trace,A,"A");
	sc_trace(my_trace,B,"B");
	sc_trace(my_trace,Ci,"Ci");
	sc_trace(my_trace,S,"S");
	sc_trace(my_trace,Co,"Co");

	A=0;
	B=0;
	Ci=0;
	sc_start(10,SC_NS);
	A=0;
	B=0;
	Ci=1;
	sc_start(10,SC_NS);	
	A=0;
	B=1;
	Ci=0;
	sc_start(10,SC_NS);	
	A=0;
	B=1;
	Ci=1;
	sc_start(10,SC_NS);
	A=1;
	B=0;
	Ci=0;
	sc_start(10,SC_NS);	
	A=1;
	B=0;
	Ci=1;
	sc_start(10,SC_NS);	
	A=1;
	B=1;
	Ci=0;
	sc_start(10,SC_NS);
	A=1;
	B=1;
	Ci=1;
	sc_start(10,SC_NS);
	
	sc_close_vcd_trace_file(my_trace);
	
	return EXIT_SUCCESS;
}