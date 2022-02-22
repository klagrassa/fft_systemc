#include "systemc.h"
#include "source.h"
#include "sink.h"
#include "fft8.h"

int sc_main(int ac, char** argv)
{
    sc_trace_file *tf;

    // Chaîne de communication
    SOURCE source1("Source");
    FFT8 fft1("FFT8");
    SINK sink1("Sink");

    sc_clock clk ("ID", 10, SC_NS, 0.5, 10, SC_NS, true);
    // sc_fifo<float> fft_in;
    sc_fifo<float> fft_out;

    // Signaux de contrôle
    sc_signal<bool> data_valid;
    sc_signal<bool> data_req;

    // Signaux de données
    sc_signal<double> real;
    sc_signal<double> imag;

    // Port mapping
    source1.clk(clk);
    source1.real(real);
    source1.imag(imag);
    source1.data_req(data_req);
    source1.data_valid(data_valid);

    fft1.real(real);
    fft1.imag(imag);
    fft1.out(fft_out);
    fft1.clk(clk);
    fft1.data_valid(data_valid);
    fft1.data_req(data_req);
    
    sink1.in(fft_out);
    sink1.clk(clk);

    // Waves:
    tf = sc_create_vcd_trace_file("waves");
    tf->set_time_unit(1, SC_NS);
    sc_trace(tf, clk, "clk");
    sc_trace(tf, data_valid, "data_valid");
    sc_trace(tf, data_req, "data_req");
    sc_trace(tf, real, "source1_FFT");
    sc_trace(tf, imag, "source1_img_FFT");
    // Useful waves
    //fft_in.trace(tf);
    fft_out.trace(tf);

    sc_start(1000, SC_NS);
    sc_close_vcd_trace_file(tf);
    return 0;
}