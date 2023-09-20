#include "systemc.h"
#include "hadd.h"
#include "orgate.h"

SC_MODULE(Fullhadd)
{
	//Channel
	sc_in<bool> A;
	sc_in<bool> B;
	sc_in<bool> Ci;
	sc_out<bool> S;
	sc_out<bool> Co;
	
	sc_signal<bool>S1;
	sc_signal<bool>C1;
	sc_signal<bool>C2;
	
	Hadd hadd1;
	Hadd hadd2;
	Orgate o1;
	
	SC_CTOR(Fullhadd) : hadd1("h1"),hadd2("h2"),o1("or1")
	{
		hadd1(A,B,S1,C1);
		hadd2(S1,Ci,S,C2);
		o1(C2,C1,Co);

	}
	
};