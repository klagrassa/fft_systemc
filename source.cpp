/* fichier source.cpp */
#include "source.h"
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;

/**
 * @brief Prend un fichier contenant les données à traiter sous la forme :
 *  réel imaginaire
 *
 */
void SOURCE::COMPORTEMENT()
{
  std::ifstream input("input_samples.txt");

  float tmp_val;

  if (!input)
    cout << "Un des fichiers d'entree n'est pas ouvert" << endl;

  // Initialisation
  data_valid.write(false);
  wait();

  while (true)
  {
    // Tant que l'on est pas à la fin du fichier, on copie l'input
    // dans un buffer et ce buffer est ensuite transmis à l'output
    if (!input.eof())
    {
      // La data est prête à être envoyé
      if (data_req)
      {
        data_valid.write(true);
        input >> tmp_val;
        real.write(tmp_val);
        input >> tmp_val;
        imag.write(tmp_val);
        cerr << "val " << real << " " << imag << endl;
      }
      
    }
    else
    {
      // cout << "Fin des fichiers d'entree atteinte." << endl;
      data_valid.write(false);
    }
    wait();
  }
}
