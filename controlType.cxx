#include <iostream>
#include "pok.h"
#include <cstdlib>
    
 float controlType(Moves a, Pokemon* b, Pokemon* c)
 {
	 float mod=1;
	 if ( a.getType() == "normale")
	 {
		    		 
			if(c->getType1()== "roccia")
				mod=mod*0.5;
			
			else if(c->getType1()== "spettro")
				mod=mod*0;
			
			else if(c->getType1()== "acciaio")
				mod=mod*0.5;
				
				
			if(c->getType2()== "roccia")
				mod=mod*0.5;
			
			else if(c->getType2()== "spettro")
				mod=mod*0;
			
			else if(c->getType2()== "acciaio")
				mod=mod*0.5;	
				 }
	 
	 
	 if ( a.getType() == "fuoco")
	 {
		 		 
			 if(c->getType1()== "roccia")
				mod=mod*0.5;
			else if(c->getType1()== "fuoco")
				mod=mod*0.5;
			else if(c->getType1()== "acqua")
				mod=mod*0.5;
			
			else if(c->getType1()== "drago")
				mod=mod*0.5;
			
				else if(c->getType1()== "ghiaccio")
				mod=mod*2;
			else if(c->getType1()== "erba")
				mod=mod*2;
			else if(c->getType1()== "coleottero")
				mod=mod*2;
							
			else if(c->getType1()== "acciaio")
				mod=mod*2;
				
				
			if(c->getType2()== "roccia")
				mod=mod*0.5;
			else if(c->getType2()== "fuoco")
				mod=mod*0.5;
			else if(c->getType2()== "acqua")
				mod=mod*0.5;
			
			else if(c->getType2()== "drago")
				mod=mod*0.5;
			
				else if(c->getType2()== "ghiaccio")
				mod=mod*2;
			else if(c->getType2()== "erba")
				mod=mod*2;
			else if(c->getType2()== "coleottero")
				mod=mod*2;
							
			else if(c->getType2()== "acciaio")
				mod=mod*2;
			
					     
	 }
	 
	 if ( a.getType() == "acqua")
	 {
		 
			 if(c->getType1()== "roccia")
				mod=mod*2;
			else if(c->getType1()== "fuoco")
				mod=mod*2;
			else if(c->getType1()== "acqua")
				mod=mod*0.5;
			
			else if(c->getType1()== "drago")
				mod=mod*0.5;
			
			else if(c->getType1()== "terra")
				mod=mod*2;
			
			else if(c->getType1()== "erba")
				mod=mod*0.5;
				
				
			if(c->getType2()== "roccia")
				mod=mod*2;
			else if(c->getType2()== "fuoco")
				mod=mod*2;
			else if(c->getType2()== "acqua")
				mod=mod*0.5;
			
			else if(c->getType2()== "drago")
				mod=mod*0.5;
			
			else if(c->getType2()== "terra")
				mod=mod*2;
			
			else if(c->getType2()== "erba")
				mod=mod*0.5;
	 
 }
	 
	 
	 if ( a.getType() == "erba" )
	 {
		  if(c->getType1()== "roccia")
				mod=mod*2;
			else if(c->getType1()== "fuoco")
				mod=mod*0.5;
			else if(c->getType1()== "acqua")
				mod=mod*2;
			
			else if(c->getType1()== "drago")
				mod=mod*0.5;
			
			else if(c->getType1()== "terra")
				mod=mod*2;
			
			else if(c->getType1()== "erba")
				mod=mod*0.5;
			else if(c->getType1()== "veleno")
				mod=mod*0.5;
			else if(c->getType1()== "coleottero")
				mod=mod*0.5;
							
			else if(c->getType1()== "volante")
				mod=mod*0.5;
				
			else if(c->getType1()== "acciaio")
				mod=mod*0.5;
				
				
			if(c->getType2()== "roccia")
				mod=mod*2;
			else if(c->getType2()== "fuoco")
				mod=mod*0.5;
			else if(c->getType2()== "acqua")
				mod=mod*2;
			
			else if(c->getType2()== "drago")
				mod=mod*0.5;
			
			else if(c->getType2()== "terra")
				mod=mod*2;
			
			else if(c->getType2()== "erba")
				mod=mod*0.5;
			else if(c->getType2()== "veleno")
				mod=mod*0.5;
			else if(c->getType2()== "coleottero")
				mod=mod*0.5;
							
			else if(c->getType2()== "volante")
				mod=mod*0.5;
				
			else if(c->getType2()== "acciaio")
				mod=mod*0.5;
	 }
 
 
	 if ( a.getType() == "veleno")
	 {
		  if(c->getType1()== "roccia")
				mod=mod*0.5;
			
			else if(c->getType1()== "terra")
				mod=mod*0.5;
			
			else if(c->getType1()== "erba")
				mod=mod*2;
			else if(c->getType1()== "veleno")
				mod=mod*0.5;
							
			else if(c->getType1()== "acciaio")
				mod=mod*0;
				
				else if(c->getType1()== "fata")
				mod=mod*2;
				
				
	  if(c->getType2()== "roccia")
				mod=mod*0.5;
			
			else if(c->getType2()== "terra")
				mod=mod*0.5;
			
			else if(c->getType2()== "erba")
				mod=mod*2;
			else if(c->getType2()== "veleno")
				mod=mod*0.5;
							
			else if(c->getType2()== "acciaio")
				mod=mod*0;
				
				else if(c->getType2()== "fata")
				mod=mod*2;
 }
	 
	 if ( a.getType() == "buio" )
	 {
		  
			if(c->getType1()== "lotta")
				mod=mod*0.5;
			
			else if(c->getType1()== "psico")
				mod=mod*2;
			else if(c->getType1()== "spettro")
				mod=mod*2;
							
			else if(c->getType1()== "buio")
				mod=mod*0.5;
			else if(c->getType1()== "fata")
				mod=mod*0.5;
				
				
	 if(c->getType2()== "lotta")
				mod=mod*0.5;
			
			else if(c->getType2()== "psico")
				mod=mod*2;
			else if(c->getType2()== "spettro")
				mod=mod*2;
							
			else if(c->getType2()== "buio")
				mod=mod*0.5;
			else if(c->getType2()== "fata")
				mod=mod*0.5;
 }
	 
	 
	 if ( a.getType() == "elettro")
	 {
		 
			  if(c->getType1()== "acqua")
				mod=mod*2;
			else if(c->getType1()== "elettro")
				mod=mod*0.5;
			else if(c->getType1()== "drago")
				mod=mod*0.5;
			
			else if(c->getType1()== "terra")
				mod=mod*0;
			
			else if(c->getType1()== "erba")
				mod=mod*0.5;
							
			else if(c->getType1()== "volante")
				mod=mod*2;
				
				
			if(c->getType2()== "acqua")
				mod=mod*2;
			else if(c->getType2()== "elettro")
				mod=mod*0.5;
			else if(c->getType2()== "drago")
				mod=mod*0.5;
			
			else if(c->getType2()== "terra")
				mod=mod*0;
			
			else if(c->getType2()== "erba")
				mod=mod*0.5;
							
			else if(c->getType2()== "volante")
				mod=mod*2;	 
 }
	 
	 
	 if ( a.getType() == "psico")
	 {
		  if(c->getType1()== "lotta")
				mod=mod*2;
			
			else if(c->getType1()== "veleno")
				mod=mod*2;
			
			else if(c->getType1()== "psico")
				mod=mod*0.5;
			
			else if(c->getType1()== "acciaio")
				mod=mod*0.5;
				
			else if(c->getType1()== "buio")
				mod=mod*0;
				
				
			if(c->getType2()== "lotta")
				mod=mod*2;
			
			else if(c->getType2()== "veleno")
				mod=mod*2;
			
			else if(c->getType2()== "psico")
				mod=mod*0.5;
			
			else if(c->getType2()== "acciaio")
				mod=mod*0.5;
				
			else if(c->getType2()== "buio")
				mod=mod*0;	 
 }
	 
	 
	 if ( a.getType() == "drago" )
	 {
		 if(c->getType1()== "drago")
				mod=mod*2;
			
			else if(c->getType1()== "acciaio")
				mod=mod*0.5;
			
			else if(c->getType1()== "fata")
				mod=mod*0;
				
				
			if(c->getType2()== "drago")
				mod=mod*2;
			
			else if(c->getType2()== "acciaio")
				mod=mod*0.5;
			
			else if(c->getType2()== "fata")
				mod=mod*0;	
	 }
 
	 
	 
	 if ( a.getType() == "roccia")
	 {
		  
			 if(c->getType1()== "fuoco")
				mod=mod*2;
			
			else if(c->getType1()== "lotta")
				mod=mod*0.5;
			else if(c->getType1()== "terra")
				mod=mod*0.5;
			else if(c->getType1()== "ghiaccio")
				mod=mod*2;
			else if(c->getType1()== "erba")
				mod=mod*0.5;
			
			else if(c->getType1()== "coleottero")
				mod=mod*2;
			
			else if(c->getType1()== "volante")
				mod=mod*2;
				
			else if(c->getType1()== "acciaio")
				mod=mod*0.5;
			
	  if(c->getType2()== "fuoco")
				mod=mod*2;
			
			else if(c->getType2()== "lotta")
				mod=mod*0.5;
			else if(c->getType2()== "terra")
				mod=mod*0.5;
			else if(c->getType2()== "ghiaccio")
				mod=mod*2;
			else if(c->getType2()== "erba")
				mod=mod*0.5;
			
			else if(c->getType2()== "coleottero")
				mod=mod*2;
			
			else if(c->getType2()== "volante")
				mod=mod*2;
				
			else if(c->getType2()== "acciaio")
				mod=mod*0.5;
 }
	 
	 
	 if ( a.getType() =="lotta" )
	 {
			 if(c->getType1()== "roccia")
				mod=mod*2;
			
			else if(c->getType1()== "ghiaccio")
				mod=mod*2;
			
			else if(c->getType1()== "veleno")
				mod=mod*0.5;
			else if(c->getType1()== "coleottero")
				mod=mod*0.5;
			else if(c->getType1()== "psico")
				mod=mod*0.5;
			else if(c->getType1()== "spettro")
				mod=mod*0;
			else if(c->getType1()== "normale")
				mod=mod*2;
				
			else if(c->getType1()== "volante")
				mod=mod*0.5;
				
			else if(c->getType1()== "acciaio")
				mod=mod*2;
				
			else if(c->getType1()== "buio")
				mod=mod*2;
			else if(c->getType1()== "fata")
				mod=mod*0.5;
			
		if(c->getType2()== "roccia")
				mod=mod*2;
			
			else if(c->getType2()== "ghiaccio")
				mod=mod*2;
			
			else if(c->getType2()== "veleno")
				mod=mod*0.5;
			else if(c->getType2()== "coleottero")
				mod=mod*0.5;
			else if(c->getType2()== "psico")
				mod=mod*0.5;
			else if(c->getType2()== "spettro")
				mod=mod*0;
			else if(c->getType2()== "normale")
				mod=mod*2;
				
			else if(c->getType2()== "volante")
				mod=mod*0.5;
				
			else if(c->getType2()== "acciaio")
				mod=mod*2;
				
			else if(c->getType2()== "buio")
				mod=mod*2;
			else if(c->getType2()== "fata")
				mod=mod*0.5;			
	 }
	 
	 
	 if ( a.getType() =="ghiaccio" )
	 {
	         if(c->getType1()== "fuoco")
				mod=mod*0.5;
			else if(c->getType1()== "acqua")
				mod=mod*0.5;
			else if(c->getType1()== "drago")
				mod=mod*2;
			else if(c->getType1()== "terra")
				mod=mod*2;
			else if(c->getType1()== "ghiaccio")
				mod=mod*0.5;
			else if(c->getType1()== "erba")
				mod=mod*2;
			
			else if(c->getType1()== "volante")
				mod=mod*2;
				
			else if(c->getType1()== "acciaio")
				mod=mod*0.5;
				
				
			 if(c->getType2()== "fuoco")
				mod=mod*0.5;
			else if(c->getType2()== "acqua")
				mod=mod*0.5;
			else if(c->getType2()== "drago")
				mod=mod*2;
			else if(c->getType2()== "terra")
				mod=mod*2;
			else if(c->getType2()== "ghiaccio")
				mod=mod*0.5;
			else if(c->getType2()== "erba")
				mod=mod*2;
			
			else if(c->getType2()== "volante")
				mod=mod*2;
				
			else if(c->getType2()== "acciaio")
				mod=mod*0.5;
			
	 }
	 
	 
	 if ( a.getType() == "spettro")
	 {
			if(c->getType1()== "psico")
				mod=mod*2;
			else if(c->getType1()== "spettro")
				mod=mod*0.5;
			else if(c->getType1()== "normale")
				mod=mod*0;
				
			else if(c->getType1()== "volante")
				mod=mod*0.5;
			
			else if(c->getType1()== "buio")
				mod=mod*0.5;
				
				
			if(c->getType2()== "psico")
				mod=mod*2;
			else if(c->getType2()== "spettro")
				mod=mod*0.5;
			else if(c->getType2()== "normale")
				mod=mod*0;
				
			else if(c->getType2()== "volante")
				mod=mod*0.5;
			
			else if(c->getType2()== "buio")
				mod=mod*0.5;
	 
	}
	 
	 if ( a.getType() == "acciaio")
	 {
	 
			 if(c->getType1()== "roccia")
				mod=mod*2;
			else if(c->getType1()== "fuoco")
				mod=mod*0.5;
			else if(c->getType1()== "acqua")
				mod=mod*0.5;
			else if(c->getType1()== "elettro")
				mod=mod*0.5;
			
			else if(c->getType1()== "ghiaccio")
				mod=mod*2;
			else if(c->getType1()== "erba")
				mod=mod*0.5;
			else if(c->getType1()== "veleno")
				mod=mod*0.5;
			
			else if(c->getType1()== "acciaio")
				mod=mod*0.5;
				
			else if(c->getType1()== "fata")
				mod=mod*2;
				
				
	 if(c->getType2()== "roccia")
				mod=mod*2;
			else if(c->getType2()== "fuoco")
				mod=mod*0.5;
			else if(c->getType2()== "acqua")
				mod=mod*0.5;
			else if(c->getType2()== "elettro")
				mod=mod*0.5;
			
			else if(c->getType2()== "ghiaccio")
				mod=mod*2;
			else if(c->getType2()== "erba")
				mod=mod*0.5;
			else if(c->getType2()== "veleno")
				mod=mod*0.5;
			
			else if(c->getType2()== "acciaio")
				mod=mod*0.5;
				
			else if(c->getType2()== "fata")
				mod=mod*2;
	}
	 
	 
	 
	 if ( a.getType() == "fata")
	 {
			
			 if(c->getType1()== "drago")
				mod=mod*2;
			else if(c->getType1()== "lotta")
				mod=mod*2;
			
			else if(c->getType1()== "veleno")
				mod=mod*0.5;
			else if(c->getType1()== "fuoco")
				mod=mod*0.5;
			else if(c->getType1()== "spettro")
				mod=mod*0.5;	
			else if(c->getType1()== "acciaio")
				mod=mod*0.5;
			else if(c->getType1()== "buio")
				mod=mod*2;	
				
				
			 if(c->getType2()== "drago")
				mod=mod*2;
			else if(c->getType2()== "lotta")
				mod=mod*2;
			
			else if(c->getType2()== "veleno")
				mod=mod*0.5;
			else if(c->getType2()== "fuoco")
				mod=mod*0.5;
			else if(c->getType2()== "spettro")
				mod=mod*0.5;	
			else if(c->getType2()== "acciaio")
				mod=mod*0.5;
			else if(c->getType2()== "buio")
				mod=mod*2;	
	 }
	
	 
	 
	 if ( a.getType() =="coleottero" )
	 {
			
		    if(c->getType1()== "lotta")
				mod=mod*0.5;
			else if(c->getType1()== "fuoco")
				mod=mod*0.5;
			else if(c->getType1()== "erba")
				mod=mod*2;
			else if(c->getType1()== "veleno")
				mod=mod*0.5;
			
			else if(c->getType1()== "psico")
				mod=mod*2;
			else if(c->getType1()== "spettro")
				mod=mod*0.5;
			
			else if(c->getType1()== "volante")
				mod=mod*0.5;
				
			else if(c->getType1()== "acciaio")
				mod=mod*0.5;
				
			else if(c->getType1()== "buio")
				mod=mod*2;
			else if(c->getType1()== "fata")
				mod=mod*0.5;
				
				
			 if(c->getType2()== "lotta")
				mod=mod*0.5;
			else if(c->getType2()== "fuoco")
				mod=mod*0.5;
			else if(c->getType2()== "erba")
				mod=mod*2;
			else if(c->getType2()== "veleno")
				mod=mod*0.5;
			
			else if(c->getType2()== "psico")
				mod=mod*2;
			else if(c->getType2()== "spettro")
				mod=mod*0.5;
			
			else if(c->getType2()== "volante")
				mod=mod*0.5;
				
			else if(c->getType2()== "acciaio")
				mod=mod*0.5;
				
			else if(c->getType2()== "buio")
				mod=mod*2;
			else if(c->getType2()== "fata")
				mod=mod*0.5;	
	 }
	
	 
	 
	 if ( a.getType() =="terra" )
	 {
			if(c->getType1()== "roccia")
				mod=mod*2;
			else if(c->getType1()== "fuoco")
				mod=mod*2;
			
			else if(c->getType1()== "elettro")
				mod=mod*2;
			
			else if(c->getType1()== "lotta")
				mod=mod*0.5;
			
			else if(c->getType1()== "erba")
				mod=mod*0.5;
			else if(c->getType1()== "veleno")
				mod=mod*2;
			
			else if(c->getType1()== "volante")
				mod=mod*0;
				
			else if(c->getType1()== "acciaio")
				mod=mod*2;
				
				
			if(c->getType2()== "roccia")
				mod=mod*2;
			else if(c->getType2()== "fuoco")
				mod=mod*2;
			
			else if(c->getType2()== "elettro")
				mod=mod*2;
			
			else if(c->getType2()== "lotta")
				mod=mod*0.5;
			
			else if(c->getType2()== "erba")
				mod=mod*0.5;
			else if(c->getType2()== "veleno")
				mod=mod*2;
			
			else if(c->getType2()== "volante")
				mod=mod*0;
				
			else if(c->getType2()== "acciaio")
				mod=mod*2;
	 
	}
	  return mod;
 }

