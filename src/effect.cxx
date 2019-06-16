#include <iostream>
#include "pok.h"
#include <cstdlib>


void useEffect(std::string effect, Pokemon *a, Pokemon *b, Campo *c, Allenatore *d, Allenatore *e)
{
	 srand (time(NULL)); //setta il seme per rand
	 
	if(effect=="riduci spatk avversario"   )
	{
		int successo=rand()%100 + 30;
		if(successo>100)
		{
			b->putModifySpatk(b->getModifySpatk() - 1);
			std::cout << "cala attacco speciale di " << b->getName() << std::endl;
		}
	}
	
	if(effect=="riduci spdef avversario"   )
	{
		int successo=rand()%100 + 30;
		if(successo>100)
		{
			b->putModifySpdef(b->getModifySpdef() -1);
			std::cout << "cala difesa speciale di " << b->getName() << std::endl;
		}
	}
	
	if(effect=="riduci def avversario"   )
	{
		int successo=rand()%100 + 30;
		if(successo>100)
		{
			b->putModifyDef(b->getModifyDef() -1);
			std::cout << b->getModifyDef() << std::endl;
			std::cout << "cala difesa di " << b->getName() << std::endl;
		}
	}
	
	if(effect=="riduci spatk mio"     )
	{
			a->putModifySpatk(a->getModifySpatk() -1);
			std::cout << "cala attacco speciale di " << a->getName() << std::endl;
		
	}
	
	if(effect=="aumento spatk mio"     )
	{
			a->putModifySpatk(a->getModifySpatk() +1);
			std::cout << "aumenta attacco speciale di " << a->getName() << std::endl;
	}
	
	if(effect=="aumento spdef mio"     )
	{
			a->putModifySpdef(a->getModifySpdef() +1);
			std::cout << "aumenta difesa speciale di " << a->getName() << std::endl;
	}
	
	if(effect=="aumento speed mio"     )
	{
		
			a->putModifySpeed(a->getModifySpeed() +1);
			std::cout << "aumenta velocità di " << a->getName() << std::endl;
	}
	
	if(effect=="aumento atk mio"     )
	{
			a->putModifyAtk(a->getModifyAtk() +1);
			std::cout << "aumenta attacco di " << a->getName() << std::endl;
	}
	
	if(effect=="togli 40 ps"     )
	{
		b->putPs(b->getPs() - 40);
	}
	
	if(effect=="recupera ps"     )
	{
		int recupero = a->getPs() + (a->getMaxPs())/2;
		if (recupero > a->getMaxPs() )
			a->putPs(a->getMaxPs() );
		else
			a->putPs(recupero);
	}
	
	if(effect=="autodistruzione"     )
	{
		a->putPs(0);
	}
	
	if(effect=="avvelena sicuro"     )
	{
		if(b->getStatus()==1)
		{
			b->putStatus(2);
			std::cout << b->getName() << " è stato avvelenato!" << std::endl;
		}
	}
	
	if(effect=="avvelena"     )
	{
		int successo=rand()%100 + 30;
		if(successo>100 && b->getStatus()==1)
		{
			b->putStatus(2);
			std::cout << b->getName() << " è stato avvelenato!" << std::endl;
		}
	}
	
	if(effect=="brucia sicuro"     )
	{
		if(b->getStatus()==1)
		{
			b->putStatus(3);
			b->putModifyAtk(b->getAtk() -1 );
			std::cout << b->getName() << " è stato bruciato!" << std::endl;
		}
	}
	
	if(effect=="brucia"     )
	{
		int successo=rand()%100 + 30;
		if(successo>100 && b->getStatus()==1)
		{
			b->putStatus(3);
			b->putModifyAtk(b->getModifyAtk() -1 );
			std::cout << b->getName() << " è stato bruciato!" << std::endl;
		}
	}
	
	if(effect=="paralizza"     )
	{
		int successo=rand()%100 + 30;
		if(successo>100 && b->getStatus()==1)
		{
			b->putStatus(4);
			b->putModifySpeed(b->getModifySpeed() -2 );
			std::cout << b->getName() << " è stato paralizzato!" << std::endl;
		}
	}
	
	if(effect=="paralizza sicuro"     )
	{
		if(b->getStatus()==1)
		{
			b->putStatus(4);
			b->putModifySpeed(b->getModifySpeed() -2 );
			std::cout << b->getName() << " è stato paralizzato!" << std::endl;
		}
	}
	
	if(effect=="addormenta sicuro"     )
	{
		if(b->getStatus()==1)
		{
			b->putStatus(5);
			
			std::cout << b->getName() << " è stato addormentato!" << std::endl;
		}
	}
	
	if(effect=="congela"     )
	{
		int successo=rand()%100 + 30;
		if(successo>100 && b->getStatus()==1)
		{
			b->putStatus(6);
			
			std::cout << b->getName() << " è stato congelato!" << std::endl;
		}
	}
	
	if(effect=="togli ps come il livello"     )
	{
		b->putPs(b->getPs() - a->getLevel());	
	}
	
	if(effect=="giornodisole"     )
	{
		if(c->getWeather() != "sole")
		{
			c->putWeather("sole");
			c->putweatherStart(c->getTurno());
			c->putweatherEnd(c->getTurno() + 5);
		}
		else
			std::cout << "c'è già il sole!" << std::endl;
	}
	
	if(effect=="confuso sicuro"     )
	{
		if (b->getConfuso() == false)
			b->putConfuso(true);
		else
			std::cout << b->getName() << " è già confuso!" << std::endl;
	}
	
	if(effect=="volo"     )
	{
		std::cout << a->getName() << " è volato in alto!" << std::endl;
	}
	
	if(effect=="reflect"     )
	{
		if (d->getReflect() != 0)//d è l'allenatore
			d->putReflect(c->getTurno()+5); //riflesso dura cinque turni
		else
			std::cout << "è già settato!" << std::endl;
	}
	
	
	/*if(effect=="     )
	{
		
	}*/
	
	
	
	
}










