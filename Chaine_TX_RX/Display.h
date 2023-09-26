#include "systemc.h"


SC_MODULE(Display)
{
  // Ports
  sc_fifo_in<sc_logic> e1;


  // Processus principal
  void printm() 
  {
    cout <<"display: "<<"t=" << sc_time_stamp()<<": data = "<<e1<< endl;
  }

  SC_CTOR(Display) 
  {
    SC_THREAD(printm);
  }
};