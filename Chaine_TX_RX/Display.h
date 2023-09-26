#include "systemc.h"


SC_MODULE(Display)
{
  // Ports
  sc_in<bool>clk;
  sc_in<sc_logic> e1;


  // Processus principal
  void printm() 
  {
    cout <<"display: "<<"t=" << sc_time_stamp()<<": data = "<<e1<< endl;
  }

  SC_CTOR(Display) 
  {
    SC_METHOD(printm);
	sensitive<<clk;
  }
};