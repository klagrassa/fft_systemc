#include "fft8.h"
#include <iostream>

void FFT8::COMPORTEMENT()
{
    while (true)
    {
        // Lire
        float real, imag;

        int n = in.num_available();
        if (n != 0)
        {
            complex_in[count].real = (double)in.read();
            complex_in[count].imag = (double)in.read();
            count++;            
            // Faire le traitement dès qu'il y en a 8
            
            if (count % POINTS_NUMBER == 0)
            {
                fft(this->complex_in, this->complex_out);
                // Ecriture du résultat
                for (int i = 0; i < POINTS_NUMBER; i++)
                {
                    out.write(complex_out[i].real);
                    out.write(complex_out[i].imag);
                }
                count = 0;
            }
        }

        wait();
    }
}