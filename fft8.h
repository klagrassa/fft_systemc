#ifndef __FFT8_H
#define __FFT8_H

#include "systemc.h"

SC_MODULE(FFT8)
{
    public:
    sc_in_clk   clk;
    sc_fifo_in<float>   in;
    sc_fifo_out<float>  out;

    SC_CTOR(FFT8)
    {
        SC_THREAD(COMPORTEMENT);
        sensitive << clk.pos();
    }

    private:
    void    COMPORTEMENT();

};

#endif /* __FFT8_H */