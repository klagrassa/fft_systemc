#include "fft8.h"

void FFT8::COMPORTEMENT()
{
    while (true)
    {
        out.write(in.read());
        wait();
    }

}