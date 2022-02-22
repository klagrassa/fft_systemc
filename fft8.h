#ifndef __FFT8_H
#define __FFT8_H

#include "systemc.h"
#include "fft.h"

#define POINTS_NUMBER 8

SC_MODULE(FFT8)
{
    public:
    sc_in_clk   clk;
    //sc_fifo_in<float>   in;
    sc_fifo_out<float>  out;

    // Lignes de données
    sc_in<double> real;
    sc_in<double> imag;
    
    // Handshake protocol
    sc_out<bool> data_req;
    sc_in<bool> data_valid;

    SC_CTOR(FFT8)
    {
        SC_THREAD(COMPORTEMENT);
        sensitive << clk.pos();
    }

    private:
    void    COMPORTEMENT();

    private:
    complex_t complex_in[POINTS_NUMBER], complex_out[POINTS_NUMBER];
    // Flag pour compter le nombre d'itérations à faire avant de faire le traitement
    int count = 0;

};

#endif /* __FFT8_H */