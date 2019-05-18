#include <iostream>
#include <vector>
#include <fstream> //Ovviamente devo includerlo
int main()
{
	std::vector<int> ps;
	std::vector<int> spatk;
	std::vector<int> atk;
	std::vector<int> speed;
	std::vector<int> def;
	std::vector<int> spdef;
	std::vector<std::string> name;	
	
	std::ifstream in("pokps.txt"); // Apertura file dati.dat, ci va std
         while(1)
        // Loop infinito
       {
		int x;
		in >> x;
		// Lettura di un dato
		if (!in.good()) // Se finisce il file
			break;
			// uscita dal loop
		ps.push_back(x);
   // Aggiunta dato ad h
		}
		
		std::ifstream inps("pokname.txt"); // Apertura file dati.dat, ci va std, devo nominarlo diversamente da in
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
		
		std::ifstream inatk("pokatk.txt"); // Apertura file dati.dat, ci va std
         while(1)
        // Loop infinito
       {
		int x;
		inatk >> x;
		// Lettura di un dato
		if (!inatk.good()) // Se finisce il file
			break;
			// uscita dal loop
		atk.push_back(x);
   // Aggiunta dato ad h
		}
		
	std::ifstream inspatk("pokspatk.txt"); // Apertura file dati.dat, ci va std
         while(1)
        // Loop infinito
       {
		int x;
		inspatk >> x;
		// Lettura di un dato
		if (!inspatk.good()) // Se finisce il file
			break;
			// uscita dal loop
		spatk.push_back(x);
   // Aggiunta dato ad h
		}
		
		std::ifstream indef("pokdef.txt"); // Apertura file dati.dat, ci va std
         while(1)
        // Loop infinito
       {
		int x;
		indef >> x;
		// Lettura di un dato
		if (!indef.good()) // Se finisce il file
			break;
			// uscita dal loop
		def.push_back(x);
   // Aggiunta dato ad h
		}
		
		std::ifstream inspdef("pokspdef.txt"); // Apertura file dati.dat, ci va std
         while(1)
        // Loop infinito
       {
		int x;
		inspdef >> x;
		// Lettura di un dato
		if (!inspdef.good()) // Se finisce il file
			break;
			// uscita dal loop
		spdef.push_back(x);
   // Aggiunta dato ad h
		}
		
		std::ifstream inspeed("pokspeed.txt"); // Apertura file dati.dat, ci va std
         while(1)
        // Loop infinito
       {
		int x;
		inspeed >> x;
		// Lettura di un dato
		if (!inspeed.good()) // Se finisce il file
			break;
			// uscita dal loop
		speed.push_back(x);
   // Aggiunta dato ad h
		}
		
		
		
	for (int i=0; i<ps.size(); i++)
	{
		std::cout << "Pokemon('" << name[i] << " ' , " << ps[i] << ", " << atk[i] << ", " << 
		def[i] << ", " << spatk[i] << ", " << spdef[i] << ", " << speed[i] << ", " << 
		", " << ", " << ", " << "   )" << std::endl;
	}
	
	return 0;
}
