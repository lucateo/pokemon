#include <iostream>
#include "pok.h"
#include <cstdlib>
//forse ne devo mettere diversi...
/*descrizione status:
 * 0==morto
 * 1==sano
 * 2==veleno
 * 3==bruciato  I cambi di statistiche si prendono dagli effetti, ho cambiato la funzione cambio per non peggiorare la situazione
 * 4==paralizzato
 * 5==addormentato
 * 6==congelato
 * Descrizione status temporanei (forse dovrò mettere un vector)
 * 1==sano
 * 2==confuso
 * 3==ricarica
 * ecc
 */
 //devo mettere controlReflect
	
int ControlStatus(Allenatore *a, Allenatore *b) //si può mettere quando si vuole (dopo che si fanno danni di qualunque genere)
 {
	 if (a->getPokemon()[a->getCurrent()]->getStatus()==0 || a->getPokemon()[a->getCurrent()]->getPs()<=0 )
	 {
		 
		 a->getPokemon()[a->getCurrent()]->putPs(0);
		 a->getPokemon()[a->getCurrent()]->putStatus(0);
		 uccidi(a, b);
		 return 1;			 	 
	 }
	 if (b->getPokemon()[b->getCurrent()]->getStatus()==0 || b->getPokemon()[b->getCurrent()]->getPs()<=0)
	 {
		 b->getPokemon()[a->getCurrent()]->putPs(0);
		 b->getPokemon()[a->getCurrent()]->putStatus(0);
		 uccidi(b, a);
		 return 1;
	 }
    else
		return 0;
}

void ControlStatusDanni(Allenatore *a, Allenatore *b) //da mettere alla fine del turno EBBASTA
{
	
	srand(time(NULL));//setta il seme per rand
	 if (a->getPokemon()[a->getCurrent()]->getStatus()==2)//avvelenato
	 {
		 a->getPokemon()[a->getCurrent()]->putPs(a->getPokemon()[a->getCurrent()]->getPs() - (0.1*(a->getPokemon()[a->getCurrent()]->getMaxPs() ) ));
		 ControlStatus(a, b);
		 std::cout << "perdita ps per avvelenamento!" << std::endl;			 	 
	 }
	 if (b->getPokemon()[b->getCurrent()]->getStatus()==2)
	 {
		 b->getPokemon()[b->getCurrent()]->putPs(b->getPokemon()[b->getCurrent()]->getPs() - (0.1*(b->getPokemon()[b->getCurrent()]->getMaxPs() ) ));
		 ControlStatus(a, b);
	 }
	 
	 
	if (a->getPokemon()[a->getCurrent()]->getStatus()==3)//bruciato
	 {
		 a->getPokemon()[a->getCurrent()]->putPs(a->getPokemon()[a->getCurrent()]->getPs() - (0.05*(a->getPokemon()[a->getCurrent()]->getMaxPs() ) ));
		 ControlStatus(a, b);			 	 
	 }
	 if (b->getPokemon()[b->getCurrent()]->getStatus()==3)
	 {
		 b->getPokemon()[b->getCurrent()]->putPs(b->getPokemon()[b->getCurrent()]->getPs() - (0.05*(b->getPokemon()[b->getCurrent()]->getMaxPs() ) ));
		 ControlStatus(a, b);
	 }
	 
	 // i loro effetti anche su UsaMossa
	 if (a->getPokemon()[a->getCurrent()]->getStatus()==6)//congelato
	 {
		 int successo = rand()%100 +70;
		 if(successo > 100)
		 {
			a->getPokemon()[a->getCurrent()]->putStatus(1); //gli mette status sano
			std::cout << a->getPokemon()[a->getCurrent()]->getName() << " è stato scongelato!" << std::endl;
		}
	 }
	 if (b->getPokemon()[b->getCurrent()]->getStatus()==6)//congelato
	 {
		 int successo = rand()%100 +70;
		 if(successo > 100)
		 {
			b->getPokemon()[b->getCurrent()]->putStatus(1); //gli mette status sano
			std::cout << b->getPokemon()[b->getCurrent()]->getName() << " è stato scongelato!" << std::endl;
		}
	 }
	 
	 
	 if (a->getPokemon()[a->getCurrent()]->getStatus()==5)//addormentato
	 {
		 int successo = rand()%100 +70;
		 if(successo > 100)
		 {
			a->getPokemon()[a->getCurrent()]->putStatus(1); //gli mette status sano
			std::cout << a->getPokemon()[a->getCurrent()]->getName() << " si è svegliato!" << std::endl;
		}
	 }
	 if (b->getPokemon()[b->getCurrent()]->getStatus()==5)//addormentato
	 {
		 int successo = rand()%100 +70;
		 if(successo > 100)
		 {
			b->getPokemon()[b->getCurrent()]->putStatus(1); //gli mette status sano
			std::cout << b->getPokemon()[b->getCurrent()]->getName() << " si è svegliato!" << std::endl;
	 }
	 
	 
	 if (b->getPokemon()[b->getCurrent()]->getConfuso()==true)//confuso
	 {
		 int successo = rand()%100 +70;
		 if(successo > 100)
		 {
			b->getPokemon()[b->getCurrent()]->putConfuso(false); //gli mette status confuso
			std::cout << b->getPokemon()[b->getCurrent()]->getName() << " non è più confuso!" << std::endl;
		}
	 }
	 
 
}
}


float ControlWeather(Pokemon *a, Pokemon* b, Moves *c, Campo *d)
{
	if (d->getWeather() == "sole" && c->getType()=="fuoco")
		return 1.5;
	else if(d->getWeather() == "sole" && c->getType()=="acqua")
		return 0.5;
	
	else
		return 1;
}

void ControlWeatherEnd(Campo *d)
{
	if (d->getTurno()==d->getweatherEnd())
		d->putWeather("");
}

int controlRicarica(Pokemon* a, Campo *c) 
{
	if (a->getRicarica() != 0)
	{	
		bool prova = true;
		if (prova ==true)
		{
		for(int i=0; i<a->getMoves().size(); i++)
		{//                   i+1 perchè i parte da 0,      +1 perchè il putTurno si riferisce al turno prima      
			if (a->getRicarica() - ((i+1)*10000) - (c->getTurno() -1 ) ==0)//mosse tipo volo, 10000
			{	
				return i +11; //+11 perchè in LottaDisplay era così
				a->putRicarica(0); //lo azzera perchè usa l'attacco
				prova=false;
			} //INSERIRE PER OLTRAGGIO E SIMILI
			if (a->getRicarica() - ((i+1)*100000) - (c->getTurno() -1 ) ==0) //mosse tipo iper raggio, 100000
			{
				a->putRicarica(0);
				return 0; //ovvero fa tutto normale
				prova=false;
			}
		}
		if (prova==true)//se non trova allora significa che deve ricaricarsi
			return 1;
		}
	}
	return 0;
}










