#include "systemc.h"

SC_MODULE(Monitor)
{
  // Ports
  sc_in<bool> e1;
  sc_in<bool> e2;
  sc_in<bool> e3;
  sc_in<bool> e4;

  // Processus principal
  void printm() {
    cout << "t=" << sc_time_stamp()<<": a = "<<e1<<"| b = "<<e2 << "| s = " << e3 <<"| c = "<<e4<< endl;
    }

  SC_CTOR(Monitor) {
    SC_METHOD(printm);
    sensitive << e3<< e4<<e2 ;
  }
};
