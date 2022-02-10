#ifndef __SINK_H
#define __SINK_H

#include "systemc.h"

SC_MODULE(SINK)
{
    public:
    sc_in_clk   clk;
    sc_fifo_in<float>   in;

    SC_CTOR(SINK)
    {
        SC_THREAD(COMPORTEMENT);
        sensitive << clk.pos();
    }

    private:
    void    COMPORTEMENT();
};

#endif /* __SINK_H */