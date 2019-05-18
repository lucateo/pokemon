#include <iostream>
#include <vector>
#include <fstream> //Ovviamente devo includerlo
int main()
{
	std::vector<int> power;
	std::vector<int> acc;
	std::vector<int> pp;
	std::vector<std::string> name;	
	
	std::ifstream inpower("dataMovePower.txt"); // Apertura file dati.dat, ci va std
         while(1)
        // Loop infinito
       {
		int x;
		inpower >> x;
		// Lettura di un dato
		if (!inpower.good()) // Se finisce il file
			break;
			// uscita dal loop
		power.push_back(x);
   // Aggiunta dato ad h
		}
		
		std::ifstream inps("dataMoveName.txt"); // Apertura file dati.dat, ci va std, devo nominarlo diversamente da in
         while(1)
        // Loop infinito
       {
		std::string x; //ovviamente devo lavorare con una stringa
		inps >> x;
		// Lettura di un dato
		if (!inps.good()) // Se finisce il file
			break;
			// uscita dal loop
		name.push_back(x);
   // Aggiunta dato ad h
		}
		
		std::ifstream inatk("dataMoveAcc.txt"); // Apertura file dati.dat, ci va std
         while(1)
        // Loop infinito
       {
		int x;
		inatk >> x;
		// Lettura di un dato
		if (!inatk.good()) // Se finisce il file
			break;
			// uscita dal loop
		acc.push_back(x);
   // Aggiunta dato ad h
		}
		
	std::ifstream inspatk("dataMovePP.txt"); // Apertura file dati.dat, ci va std
         while(1)
        // Loop infinito
       {
		int x;
		inspatk >> x;
		// Lettura di un dato
		if (!inspatk.good()) // Se finisce il file
			break;
			// uscita dal loop
		pp.push_back(x);
   // Aggiunta dato ad h
		}
		
		
		
	for (int i=0; i<name.size(); i++)
	{
		std::cout << "Moves('" << name[i] << " ' , " << ", " << ", " << power[i] << ", " << 
		acc[i] << ", " << pp[i] << ", "  << "   )" << std::endl;
	}
	
	return 0;
}
