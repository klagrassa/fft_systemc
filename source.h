/* fichier source.h */
#ifndef SOURCE_H
#define SOURCE_H

#include "systemc.h"

SC_MODULE(SOURCE)
{
public:
  sc_in_clk clk;
  // sc_fifo_out<float> out;

  // Handshake protocol
  sc_out<bool> data_valid;
  sc_in<bool> data_req;

  // Lignes de données
  sc_out<double> real;
  sc_out<double> imag;

  SC_CTOR(SOURCE)
  {
    SC_THREAD(COMPORTEMENT);
    sensitive << clk.pos();
  }

private:
  void COMPORTEMENT();
};
#endif
