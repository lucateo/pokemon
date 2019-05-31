#include <iostream>
#include "pok.h"
#include <cstdlib>
#include <stdlib.h> //per system


std::ostream &operator<<(std::ostream &out, Pokemon &a)
{//change std ostream to allow to directly write the pokemon status on the terminal
	std::string status;
	switch (a.getStatus() )
	{
		case 2:
		status="avvelenato";
		break;
		case 3:
		status="bruciato";
		break;
		case 4:
		status="paralizzato";
		break;
		case 5:
		status="addormentato";
		break;
		case 6:
		status="congelato";
		break;
		
		
	}
  out << a.getName() <<", PS " << a.getPs() << "/" << a.getMaxPs() << ", Lv " << a.getLevel() 
   << " " << status << " atk " << a.getAtk() << " spAtk " << a.getSpatk() <<" def " << a.getDef() <<
   " spDef " << a.getSpdef() << " speed "  << a.getSpeed();
   
   
  return out;
}

void UsaMossa(Moves *a, Pokemon* b, Pokemon* c, Campo *d, Allenatore *e, Allenatore *f) 
{
	int indMossa;
	 for (int j=0; j<b->getMoves().size(); j++) //mi mette indice mossa
	 {
		if(b->getMoves()[j]->getName() ==a->getName())
			indMossa=j;
	}
		controlStat(b);//sempre prima di ogni usamossa
		controlStat(c);	
	srand (time(NULL)); //setta il seme per rand		
	int fallimento=rand()%100 + 25; //per il paralizzato e/o il confuso, forse meglio metterlo dentro un altro if
	
	int randomAttack= 85 + rand()%16; //valore random per l'attacco, può assumere da 85 a 100 compresi

	if (b->getStatus()==5) //se addormentato
		std::cout << b->getName() << " è addormentato!" << std::endl;
	else if(b->getStatus()==6) //congelato
		std::cout << b->getName() << " è congelato!" << std::endl;
		
	else if(b->getStatus()==4 && fallimento > 100) //se paralizzato
		std::cout << b->getName() << " è paralizzato!" << std::endl;
		
	else if(b->getConfuso()==true && fallimento > 100) //se confuso
		{
			std::cout << b->getName() << " è talmente confuso da colpirsi da solo!" << std::endl;
			int psConfuso = randomAttack*((((40*b->getAtk() )/float(50*b->getDef() ))*((float(b->getLevel())/5) +1))+1)/50;//ps tolti da confuso, di default usa l'attacco e ha potenza 40
			b->putPs(b->getPs() - psConfuso);			
		}
		 
	else
	{
		
		a->putPp(a->getPp() - 1);
		int colpito= a->getAccuracy() + rand()%100;
	
		std::cout << b->getName() << " usa " << a->getName() << std::endl;
		
		
		for (int j=0; j<a->getEffects().size(); j++)//controllo mosse tipo volo ecc, per iper raggio e simila ci va un altro if
		{
			if(a->getEffects()[j] == "volo" && b->getDisappeared()==false) //metterci gli ||, non succederà mai che una mossa abbia più effetti di questo tipo	
			{
				useEffect(a->getEffects()[j], b, c, d, e, f);
				b->putDisappeared(true);
				b->putRicarica(d->getTurno() + (indMossa+1)*10000); //ATTENZIONE! METTE INDICE MOSSA NELL'ORDINE DEL 10000, IL RESTO È IL PASSARE DEL TURNO, C'È IL +1 PER COME È DEFINITO IL LOTTADISPLAY				
			}
		}
		if(a->getName() == "Hyper Beam" && b->getRicarica()==0) //eventualmente metterci gli altri
			b->putRicarica(d->getTurno() + (indMossa+1)*100000 +1); //mosse tipo iper raggio hanno centomila e non diecimila come volo
		
		if(	b->getRicarica() -(indMossa +1)*10000 - d->getTurno() +1 ==0 && b->getDisappeared()==true)
			{
				b->putDisappeared(false); //mette che non è più scomparso se è il turno dopo che è scomparso
				b->putRicarica(0);
			}
			
		if ((c->getDisappeared() == true && b->getDisappeared()==false) && a->getCategory() != "status no avversario") //alcune mosse si usano anche se l'avversario non c'è
			std::cout << c->getName() << " non c'è!" << std::endl;
			
		
		
	else if (b->getDisappeared()==false) //se nessuno è scomparso, questo else si dovrebbe riferire all'if immediatamente precedente spero
	{	
		float stab = controlStab(*a, b); //ATTENTO! Non so se devo specificare se sono puntatori...
		float mod = controlType(*a, b, c);
		float weather = ControlWeather(b, c, a, d);
		if (mod==0 )  //così dovrebbe proprio bloccarlo 
			std::cout << "non ha effetto..." << std::endl;
	
		else if (colpito < 100)
			std::cout << "attacco fallito!" << std::endl;
       
		else
		{
			int psTolti=0;
			if(a->getCategory() == "contatto")	
				 psTolti =( weather*mod*stab*randomAttack*/*modificatori tipo nature ecc */((((a->getPower()*b->getAtk() )/float(50*c->getDef() ))*((float(b->getLevel())/5) +1))+1) )/50; // UNA VOLTA DEFINITO PSTOLTI COME INT NON DEVO RIMETTERE
			else if (a->getCategory() == "speciale")                                                         						 //INT DI NUOVO!!!!!!!!!!!!!
				 psTolti = ( weather*mod*stab*randomAttack*( ( ((a->getPower()*b->getSpatk() )/float(50*c->getSpdef()) )*((float(b->getLevel())/5) +1))+1) )/50; //getPower() DEVE moltiplicare, altrimenti anche attacchi
							/* 100 sarebbe il valore random */															//che tolgono 0 fanno danni...
			if (psTolti < 0) { psTolti=1; } // psTolti può essere negativo se la difesa dell'avversario è troppo alta
											//ma sarà 0 se non ha effetto o per attacchi status, OK
		
			if(( (mod==2 || mod==4) && a->getCategory() != "status") && a->getCategory() != "status no avversario" )
				std::cout << " è superefficace! " << std::endl;
			
			else if ( ((mod==0.5 || mod==0.25) && a->getCategory() != "status") && a->getCategory() != "status no avversario")
				std::cout << " non è molto efficace... " << std::endl;
		
		if(a->getName() != "Fly") //mettere gli || per le altre mosse, non usa ovviamente gli altri effetti
		{    
			for (int j=0; j<a->getEffects().size(); j++)
				useEffect(a->getEffects()[j], b, c, d, e, f); //per usare gli effetti
		}
		
		int i = c->getPs()- psTolti; //messo qua che deve andare dopo la conta degli effetti 
		if( i < 1)
		  {
			  std::cout << c->getName() << " è stato sconfitto!" << std::endl;
			  c->putPs(0);
			  c->putStatus(0); // gli mette status morto
		   	  }
		 else if (a->getCategory() != "status" && a->getCategory() != "status no avversario") // se è status non voglio calcolo danni
		{ 
			c->putPs(i);  
			std::cout << c->getName() << " subisce " << psTolti << " danni!" << std::endl;
		}
		if (b->getPs() < 1) //se usa esplosione mi ammazza anche lui
		{
			  std::cout << b->getName() << " è stato sconfitto!" << std::endl;
			  b->putStatus(0); // gli mette status morto
		}
	}
}	
}
}

void fuga(Allenatore *a, Allenatore b)
{
        srand (time(NULL)); //setta il seme per rand

		 if(a->getPokemon()[a->getCurrent()]->getSpeed() < b.getPokemon()[b.getCurrent()]->getSpeed()) //i pkmn sono puntatori ci va ->
		 {
			 int i= rand()%100 +1;
			 
			 int j= b.getPokemon()[b.getCurrent()]->getSpeed() - a->getPokemon()[a->getCurrent()]->getSpeed();
			 if(j<i)
			   { std::cout << "fuga riuscita!" << std::endl;
				  a->putFinish(false); }
			 else { std::cout << "non si scappa!" << std::endl;
					}
		 }
		 else { 
			      std::cout << "fuga riuscita!" << std::endl;
			      a->putFinish(false);
			    }

}



void cambio(Allenatore *a, int m) //quando le funzioni non ti cambiano la variabile prova con i puntatori!
{
        
	     //per resettare vari cambi di statistiche come nel gioco vero quando si cambia
	     if(a->getPokemon()[a->getCurrent()]->getStatus() !=3) //resetta l'attacco solo se non bruciato
			a->getPokemon()[a->getCurrent()]->putModifyAtk(0);
		 else //se bruciato lo lascia con l'attacco dimezzato
			a->getPokemon()[a->getCurrent()]->putModifyAtk(-1);
				
	     a->getPokemon()[a->getCurrent()]->putModifySpatk(0);
	     a->getPokemon()[a->getCurrent()]->putModifyDef(0);
	     a->getPokemon()[a->getCurrent()]->putModifySpdef(0);
	     
	     if(a->getPokemon()[a->getCurrent()]->getStatus() !=4) //se non è paralizzato
			a->getPokemon()[a->getCurrent()]->putModifySpeed(0);
		 else //lo lascia con velocità ridicola
			a->getPokemon()[a->getCurrent()]->putModifySpeed(-2);
	     
		 a->putCurrent(m-31); // non posso mettere il meno uno nel cin, ricordati che i cambi vanno da trentuno
 		 std::cout << a->getName() << " cambia con " << a->getPokemon()[a->getCurrent()]->getName() << "!" << std::endl;

	 
}
	
  
 //continuare qua rimuovendo il pokemon ecc.
void uccidi(Allenatore *a, Allenatore *b)
{	
	     bool prova=false; //lo cambia se anche uno solo è vivo
		 for(int i=0; i<a->getPokemon().size(); i++)
		 {
			if(a->getPokemon()[i]->getStatus()!=0)
               { prova = true;}  //metterlo così mi assicura che se proprio l'ultimo pokemon è l'unico vivo
                                 //allora comunque sia, prova sia true
			 
		 }
		 if (prova==false) // se a non ha più pokemon
		 {
			 std::cout << a->getName() << " non è più in grado di lottare! vince " <<
			 b->getName() << "!" << std::endl;
			 a->putFinish(false);
		 }	
		 else
		 {		 		 
			std::cout << a->getName() << " deve cambiare Pokemon!" << std::endl;
			cambioNoReturn(a, b); 
		}
 }
 
float controlStab(Moves a, Pokemon* b)
{
	float stab =1; //same attack type bonus
	if (a.getType() == b->getType1())
	{	stab= stab*1.5;	}
	if (a.getType() == b->getType2() )
	{	stab = stab*1.5;	}
	
	return stab;
}
 
 
void Lotta(Allenatore a, Allenatore b, Campo *c) 
{
	//system( "play Jingle-Bells-Singing-Bell.wav &"); //per far partire canzoni
	
	while(a.getFinish() == true && b.getFinish() == true) //loop per farlo ritornare qui finito il turno
	 
	 {
		 
		 std::cout << "TURNO " << c->getTurno() << " " << c->getWeather() << std::endl;
		 int primo, secondo;
		 
		 int primo_r=controlRicarica(a.getPokemon()[a.getCurrent()], c); 
		 
		 if(primo_r ==0)//se controlricarica non dà nessun risultato
				primo = Dispay(&a, &b); //DA CONTROLLARE SE EFFETTIVAMENTE FA TUTTO E ASSEGNA GIUSTO
										//SEMBRA ASSEGNI SE METTO DISPAY DOPO IL RETURN (IN UN ALTRO CICLO), OVVIAMENTE NON DEVO ASSEGNARE NESSUN RETURN A DISPAY MA SOLO ALLE SUE SOTTOCATEGORIE
		 else
				primo=primo_r; //se ricarica dà risultato
				
		 int secondo_r = controlRicarica(b.getPokemon()[b.getCurrent()], c);
		 
		 if(secondo_r ==0)//se controlricarica non dà nessun risultato
				secondo = Dispay(&b, &a);//POTREBBE SUCCEDERE CHE SICCOME LA POTREI RICHIAMARE PIÙ VOLTE NON MI ASSEGNA UNA SEGA
		 else
				secondo = secondo_r; //se ricarica dà risultato	
		if(primo==1)//controlricarica dice che deve ancora ricaricarsi
				std::cout << a.getPokemon()[a.getCurrent()]->getName() << " deve ancora ricaricarsi!" << std::endl;
		if(secondo==1)//controlricarica dice che deve ancora ricaricarsi
				std::cout << b.getPokemon()[b.getCurrent()]->getName() << " deve ancora ricaricarsi!" << std::endl;
				
			
		 
		if(primo==20) //fuga primo
		{
			fuga(&a, b);
			if(a.getFinish() ==true) //se la fuga NON ha avuto successo
			{
				if(secondo==20) //fuga secondo
					fuga(&b, a); //poi finisce il turno
				
				if(secondo > 25) //se ha deciso di cambiare
						cambio(&b, secondo); //finisce turno
				if(secondo < 15 && secondo > 5) //lotta senza speed no scontro
					{
						controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
						controlStat(b.getPokemon()[b.getCurrent()]);
						UsaMossa(b.getPokemon()[b.getCurrent()]->getMoves()[secondo-11], b.getPokemon()[b.getCurrent()], a.getPokemon()[a.getCurrent()], c, &b, &a );
						ControlStatus(&a, &b);//dopo ogni UsaMossa ci va un controlstatus
					}
				if(secondo==15)//usa scontro
				{
					Moves *Scontro = new Moves("Scontro", "normale", "contatto", 40, 100, 40);
					controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
					controlStat(b.getPokemon()[b.getCurrent()]);
					UsaMossa(Scontro, b.getPokemon()[b.getCurrent()], a.getPokemon()[a.getCurrent()], c, &b, &a );
					ControlStatus(&a, &b);

				}
			}
		}
			
			if(primo> 25) //cambio primo
			{
				cambio(&a, primo);
				if(secondo==20) //fuga secondo
					fuga(&b, a); //poi finisce il turno
				
				if(secondo > 25) //se ha deciso di cambiare
						cambio(&b, secondo); //finisce turno
				if(secondo < 15 && secondo > 5) //lotta senza speed no scontro
					{
						controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
						controlStat(b.getPokemon()[b.getCurrent()]);
						UsaMossa(b.getPokemon()[b.getCurrent()]->getMoves()[secondo-11], b.getPokemon()[b.getCurrent()], a.getPokemon()[a.getCurrent()], c, &b, &a );
						ControlStatus(&a, &b);
					}
				if(secondo==15)//usa scontro
				{
					Moves *Scontro = new Moves("Scontro", "normale", "contatto", 40, 100, 40);
					controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
					controlStat(b.getPokemon()[b.getCurrent()]);
					UsaMossa(Scontro, b.getPokemon()[b.getCurrent()], a.getPokemon()[a.getCurrent()], c, &b, &a );
					ControlStatus(&a, &b);
				}
			}
			if(primo < 15 && primo > 5) //ATTENZIONE ALLE ECCEZIONI, SE IL POKEMON DI SECONDO MUORE?
			{
				if(secondo==20) //fuga secondo
				{
					fuga(&b, a);
					if (b.getFinish()==true) //fuga non riuscita, se riesce il programma chiude
						{
							controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
							controlStat(b.getPokemon()[b.getCurrent()]);
							UsaMossa(a.getPokemon()[a.getCurrent()]->getMoves()[primo-11], a.getPokemon()[a.getCurrent()], b.getPokemon()[b.getCurrent()], c, &a, &b );
							ControlStatus(&a, &b);
						}
				}
				if(secondo>25)
				{	
					cambio(&b, secondo);
					controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
					controlStat(b.getPokemon()[b.getCurrent()]);
					UsaMossa(a.getPokemon()[a.getCurrent()]->getMoves()[primo-11], a.getPokemon()[a.getCurrent()], b.getPokemon()[b.getCurrent()], c, &a, &b );
					ControlStatus(&a, &b);
				}	
				if(secondo < 15 && secondo > 5)//lotta tutti e due
				{
					if(b.getPokemon()[b.getCurrent()]->getMoves()[secondo-11]->getPriority() >  a.getPokemon()[a.getCurrent()]->getMoves()[primo-11]->getPriority() )
					{
						controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
						controlStat(b.getPokemon()[b.getCurrent()]);
						UsaMossa(b.getPokemon()[b.getCurrent()]->getMoves()[secondo-11], b.getPokemon()[b.getCurrent()], a.getPokemon()[a.getCurrent()], c, &b, &a );
						int uccisione = ControlStatus(&a, &b);
						std::cout << uccisione << std::endl;
						if(uccisione ==0) //se il pokemon non è morto continua
						{
							controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
							controlStat(b.getPokemon()[b.getCurrent()]);
							UsaMossa(a.getPokemon()[a.getCurrent()]->getMoves()[primo-11], a.getPokemon()[a.getCurrent()], b.getPokemon()[b.getCurrent()], c, &a, &b );
							ControlStatus(&a, &b);
						}
					}
					else if(b.getPokemon()[b.getCurrent()]->getMoves()[secondo-11]->getPriority() <  a.getPokemon()[a.getCurrent()]->getMoves()[primo-11]->getPriority() )
					{
						UsaMossa(a.getPokemon()[a.getCurrent()]->getMoves()[primo-11], a.getPokemon()[a.getCurrent()], b.getPokemon()[b.getCurrent()], c, &a, &b );
						int uccisione = ControlStatus(&a, &b);
						if(uccisione ==0) //se il pokemon non è morto continua
						{
							controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
							controlStat(b.getPokemon()[b.getCurrent()]);
							UsaMossa(b.getPokemon()[b.getCurrent()]->getMoves()[secondo-11], b.getPokemon()[b.getCurrent()], a.getPokemon()[a.getCurrent()], c, &b, &a );
							ControlStatus(&a, &b);
						}
					}
					else //se priority sono uguali va avanti normalmente
					{
						controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
						controlStat(b.getPokemon()[b.getCurrent()]);//ma anche prima di valutazione speed
						if(a.getPokemon()[a.getCurrent()]->getSpeed() < b.getPokemon()[b.getCurrent()]->getSpeed() ) //velocità primo minore
						{
							
							UsaMossa(b.getPokemon()[b.getCurrent()]->getMoves()[secondo-11], b.getPokemon()[b.getCurrent()], a.getPokemon()[a.getCurrent()], c, &b, &a );
							int uccisione = ControlStatus(&a, &b);
							if(uccisione ==0) //se il pokemon non è morto continua
							{
								controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
								controlStat(b.getPokemon()[b.getCurrent()]);
								UsaMossa(a.getPokemon()[a.getCurrent()]->getMoves()[primo-11], a.getPokemon()[a.getCurrent()], b.getPokemon()[b.getCurrent()], c, &a, &b);
								ControlStatus(&a, &b);
							}
						}
						else
						{
							UsaMossa(a.getPokemon()[a.getCurrent()]->getMoves()[primo-11], a.getPokemon()[a.getCurrent()], b.getPokemon()[b.getCurrent()], c, &a, &b );
							int uccisione = ControlStatus(&a, &b);
							if(uccisione ==0) //se il pokemon non è morto continua
							{
								controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
								controlStat(b.getPokemon()[b.getCurrent()]);
								UsaMossa(b.getPokemon()[b.getCurrent()]->getMoves()[secondo-11], b.getPokemon()[b.getCurrent()], a.getPokemon()[a.getCurrent()], c, &b, &a);
								ControlStatus(&a, &b);
							}
						}
					}
				}//DOVREI ANCHE AGGIUNGERE PER LA MOSSA SCONTRO, PIÙ TARDI
				if(secondo==1) //se deve ricaricarsi il pokemon di b
				{
					controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
					controlStat(b.getPokemon()[b.getCurrent()]);
					UsaMossa(a.getPokemon()[a.getCurrent()]->getMoves()[primo-11], a.getPokemon()[a.getCurrent()], b.getPokemon()[b.getCurrent()], c, &a, &b );
					ControlStatus(&a, &b);
				}
		}
		if(primo==1) //se il pokemon di a deve ricaricarsi
		{
			if(secondo==20) //fuga secondo
					fuga(&b, a); //poi finisce il turno
				
			if(secondo > 25) //se ha deciso di cambiare
				cambio(&b, secondo); //finisce turno
			if(secondo < 15 && secondo > 5) //lotta senza speed no scontro
			{
				controlStat(a.getPokemon()[a.getCurrent()]);//sempre prima di ogni usamossa
				controlStat(b.getPokemon()[b.getCurrent()]);
				UsaMossa(b.getPokemon()[b.getCurrent()]->getMoves()[secondo-11], b.getPokemon()[b.getCurrent()], a.getPokemon()[a.getCurrent()], c, &b, &a );
				ControlStatus(&a, &b);
			}
		}
		
		//robe di fine turno
		ControlStatusDanni(&a, &b);
		ControlStatus(&a, &b);
		c->putTurno(c->getTurno()+1); //aumenta il numero del turno alla fine del while
		ControlWeatherEnd(c);
      }
}

		
int Dispay(Allenatore *a, Allenatore *b) //serve per fare il display delle scelte, ritorna l'int che è la scelta
//FORSE DOVRO METTERE PUNTATORI
{
	controlStat(a->getPokemon()[a->getCurrent()]); controlStat(b->getPokemon()[b->getCurrent()]);
	std::cout << a->getName() << ", in campo " << *a->getPokemon()[a->getCurrent()] << std::endl;
	std::cout << *b->getPokemon()[b->getCurrent()] << " di " << b->getName() << std::endl; //ci vuole * perchè altrimenti mi da l'indirizzo 
	 std::cout << "1) Lotta" << std::endl;                                    //della loro memoria!!!
	 std::cout << "2) Fuggi" << std::endl;
     std::cout << "3) Cambia pokemon" << std::endl;
     std::cout << "4) borsa" << std::endl;
     int n;
     std::cin>>n;
     bool scontro; //per far eventualmente usare la mossa scontro
     
          	
	 if(n==3) //cambio, della fuga non c'è bisogno di fare il display
	 {
		 return cambioDisplay(a, b); //senza attuarlo veramente, DOVREBBE FUNZIONARE ANCHE CON RETURN
		 
	  }
	if(n==1)
	{
		return LottaDisplay(a->getPokemon()[a->getCurrent()], a, b); //senza attuarla veramente, dà il via alla funzione e assegna
		
	}	
	if(n==2)																//il suo output a scontro, DA CONTROLLARE
		return 20; //alla fuga è associato il venti
}	

int cambioDisplay(Allenatore *a, Allenatore *b)//ESISTE ANCHE IL CAMBIONORETURN!!!!!!!
{
	bool impedisci = false; //per impedire il cambio se tutti morti
        for(int i=0; i<a->getPokemon().size(); i++)
        {
			if(a->getPokemon()[i]->getStatus()!=0 && i != a->getCurrent() ) //diverso anche dal pokemon in campo
				impedisci = true; //se qualcuno viene toccato mette true, nessuno toccato significa tutti morti
		}
        
     if (impedisci==true) //cioè non impedisce il cambio
     {   
        for(int i=0; i<a->getPokemon().size(); i++)
		 {
			if(a->getPokemon()[i]->getStatus()==0)
			 {std::cout << i+1 << ") " << *a->getPokemon()[i] << " KO" << std::endl;} //puntatore, altrimenti mi dà l'indirizzo di memoria
			 
		else
		{   std::cout << i+1 << ") " << *a->getPokemon()[i] << std::endl;} //puntatore, altrimenti mi dà l'indirizzo di memoria

	}
		 std::cout << "premi 7 per tornare indietro" << std::endl;
		 int m;
		 bool x=false;
		 while (x==false) //Ottimo metodo, potrebbe essere utile per fuggi e simili...
		 {
		    std::cin >> m;

		    if (m==7) //tornare indietro
			{
				x=true;
				return Dispay(a, b);
			}
		    else if (a->getPokemon()[m-1]->getStatus()==0) //E SE GIÀ IN CAMPO E KO COINCIDESSERO?
		    {
				std::cout << "è KO! Non puoi!" << std::endl;
			
			}
		    else if (a->getCurrent()== m-1 && a->getPokemon()[m-1]->getStatus()!=0) //
		    {
				std::cout << "è il pokemon già in campo!" << std::endl;
			}
			
			else 
			{
				x=true;
				return 30 + m;//poi dipenderà dal pokemon scelto
			}  
	     }
	     
	 
	 
	 }
	 else if(impedisci==false)
	 {
		 std::cout << "sono tutti morti! Hai solo questo!" << std::endl;
		return Dispay(a, b);
	 }
	
}

int LottaDisplay(Pokemon *a, Allenatore *b, Allenatore *c) //non serve il secondo pokemon per il display
{
		
		 bool y=false; //per far usare la mossa scontro
		 	 		 
		 for (int i =0; i< a->getMoves().size(); i++)
			{
				if(a->getMoves()[i]->getPp() > 0)
					y=true;
			}
		if (y==false) //caso non si abbiano più pp
		{
			std::cout << a->getName() << " non ha più pp! Vuoi continuare? 1 per continuare, 2 per lasciar perdere" << std::endl;//dopo dovrò fare in modo di impedire di mettere numeri a caso
			int n;
			std::cin >>n;
			
			if (n==1)//continua
				return 15; //15 è mossa scontro
			else if (n==2)//lascia perdere
				return Dispay(b, c);//va dopo i return
			else //nel caso premesse un altro numero
			{
				std::cerr << "Cazzo fai idiota!" << std::endl;
				return Dispay(b, c);
			}
		}	
			
		else if (y==true)
	{				
	     std::cout << "questi sono i tuoi attacchi, quale usi?" << std::endl;
		 for (int i=0; i< a->getMoves().size(); i++)
		 {
			 std::cout << i+1 << ") " << a->getMoves()[i]->getName()<< " PP " << a->getMoves()[i]->getPp() << std::endl;			 
 
          }
          std::cout << "premi 5 per tornare indietro"<< std::endl;
          int n_atk; //numero attacco di cui sopra
          std::cin>> n_atk;
          if (n_atk==5)
			return Dispay(b, c);
          if (a->getMoves()[n_atk-1]->getPp() < 1)
          { 
			  std::cout << "non puoi, pp finiti!" << std::endl;
			  return Dispay(b,c);
		  }
		  else		  
		  	return 10+n_atk; //DEVO METTERE I RETURN NEGLI IF, POI QUESTO DIPENDERÀ DALL'ATTACCO
		
	}
}

void cambioNoReturn(Allenatore *a, Allenatore *b) //per la funzione uccidi et simila
{
	   for(int i=0; i<a->getPokemon().size(); i++)
		 {
			if(a->getPokemon()[i]->getStatus()==0)
			 {std::cout << i+1 << ") " << *a->getPokemon()[i] << " KO" << std::endl;} //puntatore, altrimenti mi dà l'indirizzo di memoria
			 
		else
		    std::cout << i+1 << ") " << *a->getPokemon()[i] << std::endl; //puntatore, altrimenti mi dà l'indirizzo di memoria

	    }
		 int m;
		  // ricordati che i vector partono da 0
		 bool x=false;
		 		 		 	
		 while (x==false) //Ottimo metodo, potrebbe essere utile per fuggi e simili...
		 {
		    std::cin >> m;
		    if (a->getPokemon()[m-1]->getStatus()==0)
		    {
			 std::cout << " è KO! Non puoi!" << std::endl;			 	 
		    }
		    		
			else { x=true;} //questo per non richiamare la funzione stessa che non è mai una buona idea 
	     }
	     a->putCurrent(m-1); // non posso mettere il meno uno nel cin
		 std::cout << a->getName() << " cambia con " << a->getPokemon()[a->getCurrent()]->getName() << "!" << std::endl;
	 }
	 
	 

		 
	 
	












	
