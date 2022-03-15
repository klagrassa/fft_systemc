#include "sink.h"
#include <iostream>

void SINK::COMPORTEMENT()
{
    std::ofstream output("output_samples.txt");

    // Vérification du flux de sortie prêt
    if (!output)
        std::cout << "Fichier non ouvert" << std::endl;

    // Initialisation
    data_req = false;
    wait();

    data_req = true;

    // Tant qu'il y a une donnée à écrire, on l'inscrit dans le flux
    // Boucle while pour le thread
    while (true)
    {
        if (data_valid)
        {
            output << real.read() << " " << imag.read() << std::endl;
            wait();
        }
        else
        {
            // std::cout << "Fin d'écriture" << std::endl;
            wait();
        }
    }
}