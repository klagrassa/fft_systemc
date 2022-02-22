#include "fft8.h"
#include <iostream>

void FFT8::COMPORTEMENT()
{
    // Lire
    float real, imag;

    // Initialisation hors de la boucle
    data_req.write(false);

    wait();

    //cerr << data_req << " " << data_valid << endl;
    data_req.write(true);
    wait();
    while (true)
    {
        //cerr << data_req << " " << data_valid << endl;
        if (data_valid && count < POINTS_NUMBER)
        {
            data_req.write(true);
            
            cerr << " réel " << real << endl;
            complex_in[count].real = real;
            complex_in[count].imag = imag;
            count++;
            cerr << count << endl;
        }

        // Faire le traitement dès qu'il y en a 8
        if (count == POINTS_NUMBER)
        {
            

            for (int i = 0; i < POINTS_NUMBER; i++)
                cerr 
                << "avant fft" 
                << endl 
                << complex_in[i].real
                << complex_in[i].imag
                << endl;
            // On bloque le flux, on fait le traitement
            data_req.write(false);
            fft(this->complex_in, this->complex_out);
            wait();
            // Traitement fini, on redemande, pendant ce temps
            // on envoie les données dans le sink (output)
            data_req = true;

            
            // Ecriture du résultat
            for (int i = 0; i < POINTS_NUMBER; i++)
            {
                cerr << complex_out[i].real << " " << complex_out[i].imag << endl;
                out.write(complex_out[i].real);
                out.write(complex_out[i].imag);
            }

            count = 0;
        }

        wait();
    }
}