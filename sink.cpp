#include "sink.h"
#include <iostream>


void SINK::COMPORTEMENT()
{
    std::ofstream output("output_samples.txt");
    float val;

    // Vérification du flux de sortie prêt
    if(!output)
        std::cout << "Fichier non ouvert" << std::endl;

    // Tant qu'il y a une donnée à écrire, on l'inscrit dans le flux
    // Boucle while pour le thread
    while (true)
    {
        if (in.num_available() > 1)
        {
            output << in.read() << " " << in.read() << std::endl;
            wait();
        }
        else {
            //std::cout << "Fin d'écriture" << std::endl;
            wait();
        }
    }

}