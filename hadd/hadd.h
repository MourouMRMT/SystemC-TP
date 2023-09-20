#include "systemc.h"

SC_MODULE(Hadd)
{
  sc_in<bool> a;
  sc_in<bool> b;
  sc_out<bool> s;
  sc_out<bool> c;
  
  void hadd();

  SC_CTOR(Hadd) {
    SC_METHOD(hadd);
	sensitive<< b;
  }
};
