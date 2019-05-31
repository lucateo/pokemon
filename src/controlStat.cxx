#include <iostream>
#include "pok.h"
#include <cstdlib>

void controlStat(Pokemon *a) 
{
	if(a->getModifyAtk() == 0 )
		a->putAtk(a->getMaxAtk() );
		
	if(a->getModifyAtk() < -6 )
		a->putModifyAtk(-6);
	if(a->getModifyAtk()>6)
		a->putModifyAtk(6);
		
	if(a->getModifyAtk() == -6)
		a->putAtk(a->getMaxAtk()*0.25 );
	if(a->getModifyAtk() == -5)
		a->putAtk(a->getMaxAtk()*0.29 );	
	if(a->getModifyAtk() == -4 )
		a->putAtk(a->getMaxAtk()*0.33 );	
	if(a->getModifyAtk() == -3)
		a->putAtk(a->getMaxAtk()*0.40 );	
	if(a->getModifyAtk() == -2)
		a->putAtk(a->getMaxAtk()*0.50 );	
	if(a->getModifyAtk() == -1 )
		a->putAtk(a->getMaxAtk()*0.67 );
		
	if(a->getModifyAtk() == 1)
		a->putAtk(a->getMaxAtk()*1.5 );		
	if(a->getModifyAtk() == 2)
		a->putAtk(a->getMaxAtk()*2 );		
	if(a->getModifyAtk() == 3)
		a->putAtk(a->getMaxAtk()*2.5 );	
	if(a->getModifyAtk() == 4 )
		a->putAtk(a->getMaxAtk()*3 );		
	if(a->getModifyAtk() == 5)
		a->putAtk(a->getMaxAtk()*3.5 );		
	if(a->getModifyAtk() == 6 )
		a->putAtk(a->getMaxAtk()*4 );	
		
		
		
	if(a->getModifyDef() == 0 )
		a->putDef(a->getMaxDef() );
		
	if(a->getModifyDef() < -6 )
		a->putModifyDef(-6);
	if(a->getModifyDef()>6)
		a->putModifyDef(6);
			
	if(a->getModifyDef() == -6)
		a->putDef(a->getMaxDef()*0.25 );
	if(a->getModifyDef() == -5)
		a->putDef(a->getMaxDef()*0.29 );	
	if(a->getModifyDef() == -4 )
		a->putDef(a->getMaxDef()*0.33 );	
	if(a->getModifyDef() == -3)
		a->putDef(a->getMaxDef()*0.40 );	
	if(a->getModifyDef() == -2)
		a->putDef(a->getMaxDef()*0.50 );	
	if(a->getModifyDef() == -1 )
		a->putDef(a->getMaxDef()*0.67 );
		
	if(a->getModifyDef() == 1)
		a->putDef(a->getMaxDef()*1.5 );		
	if(a->getModifyDef() == 2)
		a->putDef(a->getMaxDef()*2 );		
	if(a->getModifyDef() == 3)
		a->putDef(a->getMaxDef()*2.5 );	
	if(a->getModifyDef() == 4 )
		a->putDef(a->getMaxDef()*3 );		
	if(a->getModifyDef() == 5)
		a->putDef(a->getMaxDef()*3.5 );		
	if(a->getModifyDef() == 6 )
		a->putDef(a->getMaxDef()*4 );
		
		
		
		
	if(a->getModifySpatk() == 0 )
		a->putSpatk(a->getMaxSpatk() );	
		
	if(a->getModifySpatk() < -6 )
		a->putModifySpatk(-6);
	if(a->getModifySpatk()>6)
		a->putModifySpatk(6);
			
	if(a->getModifySpatk() == -6)
		a->putSpatk(a->getMaxSpatk()*0.25 );
	if(a->getModifySpatk() == -5)
		a->putSpatk(a->getMaxSpatk()*0.29 );	
	if(a->getModifySpatk() == -4 )
		a->putSpatk(a->getMaxSpatk()*0.33 );	
	if(a->getModifySpatk() == -3)
		a->putSpatk(a->getMaxSpatk()*0.40 );	
	if(a->getModifySpatk() == -2)
		a->putSpatk(a->getMaxSpatk()*0.50 );	
	if(a->getModifySpatk() == -1 )
		a->putSpatk(a->getMaxSpatk()*0.67 );
		
	if(a->getModifySpatk() == 1)
		a->putSpatk(a->getMaxSpatk()*1.5 );		
	if(a->getModifySpatk() == 2)
		a->putSpatk(a->getMaxSpatk()*2 );		
	if(a->getModifySpatk() == 3)
		a->putSpatk(a->getMaxSpatk()*2.5 );	
	if(a->getModifySpatk() == 4 )
		a->putSpatk(a->getMaxSpatk()*3 );		
	if(a->getModifySpatk() == 5)
		a->putSpatk(a->getMaxSpatk()*3.5 );		
	if(a->getModifySpatk() == 6 )
		a->putSpatk(a->getMaxSpatk()*4 );
		
		
		
		
		
	if(a->getModifySpdef() == 0 )
		a->putSpdef(a->getMaxSpdef() );
			
	if(a->getModifySpdef() < -6 )
		a->putModifySpdef(-6);
	if(a->getModifySpdef()>6)
		a->putModifySpdef(6);
			
	if(a->getModifySpdef() == -6)
		a->putSpdef(a->getMaxSpdef()*0.25 );
	if(a->getModifySpdef() == -5)
		a->putSpdef(a->getMaxSpdef()*0.29 );	
	if(a->getModifySpdef() == -4 )
		a->putSpdef(a->getMaxSpdef()*0.33 );	
	if(a->getModifySpdef() == -3)
		a->putSpdef(a->getMaxSpdef()*0.40 );	
	if(a->getModifySpdef() == -2)
		a->putSpdef(a->getMaxSpdef()*0.50 );	
	if(a->getModifySpdef() == -1 )
		a->putSpdef(a->getMaxSpdef()*0.67 );
		
	if(a->getModifySpdef() == 1)
		a->putSpdef(a->getMaxSpdef()*1.5 );		
	if(a->getModifySpdef() == 2)
		a->putSpdef(a->getMaxSpdef()*2 );		
	if(a->getModifySpdef() == 3)
		a->putSpdef(a->getMaxSpdef()*2.5 );	
	if(a->getModifySpdef() == 4 )
		a->putSpdef(a->getMaxSpdef()*3 );		
	if(a->getModifySpdef() == 5)
		a->putSpdef(a->getMaxSpdef()*3.5 );		
	if(a->getModifySpdef() == 6 )
		a->putSpdef(a->getMaxSpdef()*4 );
		
		
		
		
		
	if(a->getModifySpeed() == 0 )
		a->putSpeed(a->getMaxSpeed() );	
		
	if(a->getModifySpeed() < -6 )
		a->putModifySpeed(-6);
	if(a->getModifySpeed()>6)
		a->putModifySpeed(6);
			
	if(a->getModifySpeed() == -6)
		a->putSpeed(a->getMaxSpeed()*0.25 );
	if(a->getModifySpeed() == -5)
		a->putSpeed(a->getMaxSpeed()*0.29 );	
	if(a->getModifySpeed() == -4 )
		a->putSpeed(a->getMaxSpeed()*0.33 );	
	if(a->getModifySpeed() == -3)
		a->putSpeed(a->getMaxSpeed()*0.40 );	
	if(a->getModifySpeed() == -2)
		a->putSpeed(a->getMaxSpeed()*0.50 );	
	if(a->getModifySpeed() == -1 )
		a->putSpeed(a->getMaxSpeed()*0.67 );
		
	if(a->getModifySpeed() == 1)
		a->putSpeed(a->getMaxSpeed()*1.5 );		
	if(a->getModifySpeed() == 2)
		a->putSpeed(a->getMaxSpeed()*2 );		
	if(a->getModifySpeed() == 3)
		a->putSpeed(a->getMaxSpeed()*2.5 );	
	if(a->getModifySpeed() == 4 )
		a->putSpeed(a->getMaxSpeed()*3 );		
	if(a->getModifySpeed() == 5)
		a->putSpeed(a->getMaxSpeed()*3.5 );		
	if(a->getModifySpeed() == 6 )
		a->putSpeed(a->getMaxSpeed()*4 );
				
}

