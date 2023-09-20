#include "systemc.h"

typedef enum{E0,E1,E2} t_etat;
SC_MODULE(AltBit)
{
  sc_in<bool> E;
  sc_in<bool> H;
  sc_out<bool> Err;
  
  t_etat etat;
  
  void altbit();

  SC_CTOR(AltBit) {
    SC_THREAD(altbit);
  }
};
