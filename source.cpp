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

  if(!input)
    cout<< "Un des fichiers d'entree n'est pas ouvert" <<endl;

  wait();

  while(true)
    {
      // Tant que l'on est pas à la fin du fichier, on copie l'input
      // dans un buffer et ce buffer est ensuite transmis à l'output
      if(!input.eof()){
        input>>tmp_val;
        out.write(tmp_val);
        //cerr << tmp_val << " ";
        wait();
        input>>tmp_val;
        out.write(tmp_val);
        //cerr << tmp_val << endl;
        wait();
      }
      else
      { 
        //cout << "Fin des fichiers d'entree atteinte." << endl;
        wait();
      }
      
    }
}	
