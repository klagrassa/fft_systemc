/* fichier source.h */
#ifndef SOURCE_H
#define SOURCE_H

#include "systemc.h"

SC_MODULE(SOURCE)
    {
      public:
        sc_in_clk    clk;
        sc_fifo_out<float> out;

          SC_CTOR(SOURCE)
                {
                  SC_THREAD(COMPORTEMENT);
                  sensitive << clk.pos();
                 }
      private:

      void COMPORTEMENT();

};
#endif
