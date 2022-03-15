#ifndef __SINK_H
#define __SINK_H

#include "systemc.h"

SC_MODULE(SINK)
{
    public:
    sc_in_clk   clk;
    //sc_fifo_in<float>   in;

    // Ligne de données
    sc_in<double> real;
    sc_in<double> imag;

    // Handshake protocol
    sc_out<bool> data_req;
    sc_in<bool> data_valid;

    SC_CTOR(SINK)
    {
        SC_THREAD(COMPORTEMENT);
        sensitive << clk.pos();
    }

    private:
    void    COMPORTEMENT();
};

#endif /* __SINK_H */