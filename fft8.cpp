#include "fft8.h"
#include <iostream>

void FFT8::COMPORTEMENT()
{
    int write_count = 0;
    // Initialisation hors de la boucle
    data_req = false;
    data_valid_sink = false;
    wait();

    // cerr << data_req << " " << data_valid << endl;
    data_req = true;
    wait();
    while (true)
    {
        if (write_count == 7)
            data_valid_sink = false;

        // ECRITURE
        // cerr << data_req << " " << data_valid << endl;
        if (data_valid && (count < POINTS_NUMBER))
        {
            cerr << "in ecriture" << endl;
            data_req = true;

            // cerr << " réel " << real << "img " << imag << endl;
            complex_in[count].real = real;
            complex_in[count].imag = imag;
            count++;
            cerr << count << endl;
        }

        // PROCESS ET ENVOI
        // Faire le traitement dès qu'il y en a 8

        if (count == POINTS_NUMBER)
        {
            cerr << "in process" << endl;
            // On bloque le flux, on fait le traitement
            data_req = false;
            fft(this->complex_in, this->complex_out);
            cerr << "been there" << endl;
            result = true;
            write_count = 0;
            wait();
            // Traitement fini, on redemande, pendant ce temps
            // on envoie les données dans le sink (output)
            data_req = true;

            count = 0;
        }

        if (result && write_count < POINTS_NUMBER && data_req_sink)
        {
            cerr << "in output" << endl;
            // Ecriture du résultat
            real_out.write(complex_out[write_count].real);
            imag_out.write(complex_out[write_count].imag);
            data_valid_sink = true;
            cerr << "wc" << write_count << endl;
            cerr << "valeur écrite : " << complex_out[write_count].real << endl;
            if (write_count == 7)
            {
                result = false;
            }
            else
                write_count++;
        }

        wait();
    }
}