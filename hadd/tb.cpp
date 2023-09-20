#include"systemc.h"
#include"hadd.h"
#include"monitor.h"

int sc_main(int argc,char *argv[])
{
	sc_signal<bool> a;
	sc_signal<bool> b;
	sc_signal<bool> s;
	sc_signal<bool> c;
	
	Hadd myhadd("h1");
	myhadd.a(a);
	myhadd.b(b);
	myhadd.s(s);
	myhadd.c(c);
	
	/*Monitor view("v1");
	view.e1(a);
	view.e2(b);
	view.e3(s);
	view.e4(c);*/
	sc_trace_file *my_trace;
	my_trace = sc_create_vcd_trace_file("tb");
	sc_trace(my_trace,a,"A");
	sc_trace(my_trace,b,"B");
	sc_trace(my_trace,s,"S");
	sc_trace(my_trace,c,"C");
	
	a=0;
	b=0;
	sc_start(10,SC_NS);
	a=0;
	b=1;
	sc_start(10,SC_NS);
	a=1;
	b=0;
	sc_start(10,SC_NS);
	a=1;
	b=1;
	sc_start(10,SC_NS);
	
	sc_close_vcd_trace_file(my_trace);
	
	return EXIT_SUCCESS;
}