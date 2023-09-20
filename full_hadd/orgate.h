#include "systemc.h"

SC_MODULE(Orgate)
{
  // Ports
  sc_in<bool> E1;
  sc_in<bool> E2;
  sc_out<bool> S;

	void gateor() 
	{
	  S=E1|E2;
	}

	SC_CTOR(Orgate) {
		SC_METHOD(gateor);
		sensitive<<E1<<E2;
	}
};