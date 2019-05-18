#include <iostream>
#include "pok.h"

int main()
{	
	Campo *Lega_Pokemon=	new Campo();
	
		
	Moves *Psychic = 		new Moves("Psychic " ,		"psico" ,"speciale" , 90, 100, 10   );
	Moves *Flamethrower= 	new Moves("Flamethrower " ,	"fuoco" ,"speciale" , 90, 100, 15  );
	Moves *Waterfall = 		new Moves("Waterfall " ,	"acqua" ,"contatto" , 80, 100, 15  );
	Moves *Dragon = 		new Moves("Dragon Claw " ,	"drago" ,"contatto" , 80, 100, 15  );
	Moves *Thunderbolt= 	new Moves("Thunderbolt " ,	"elettro" ,"speciale" , 80, 100, 10  );
	Moves *Fire = 			new Moves("Fire Blast " ,	"fuoco" ,"speciale" , 110, 85, 5   );
	Moves *Sludge = 		new Moves("Sludge Bomb " ,	"veleno" ,"speciale" , 90, 100, 10   );
	Moves *Stone= 			new Moves("Stone Edge " ,	"roccia" ,"contatto" , 100, 80, 5   );
	Moves *azione1 = 		new Moves("azione", 		"normale", "contatto", 40, 100, 40);
	Moves *azione2 =		new Moves("azione", 		"normale", "contatto", 40, 100, 40);
	Moves *azioneSpec = 	new Moves("azionespec", 	"normale", "speciale", 40, 100, 40);
	Moves *Earthquake = 	new Moves("Earthquake " ,	"terra" ,"contatto" , 100, 100, 10   );
	Moves *Explosion = 		new Moves("Explosion " ,	"normale" ,"contatto" , 250, 100, 5  );
	Moves *Seed = 			new Moves("Seed Bomb " ,	"erba" ,"speciale" , 80, 100, 15   );
	Moves *Slash = 			new Moves("Slash " ,		"normale" ,"contatto" , 70, 100, 20 );
	Moves *Calm = 			new Moves("Calm Mind " ,	"psico" ,"status no avversario" , 0, 100, 20   );
	Moves *Fly = 			new Moves("Fly" ,			"volante" , "contatto" , 90, 95, 15   );
	Moves *Rage = 			new Moves("Dragon Rage " ,	"drago" ,"status" , 0, 100, 10   ); //status così non toglie un ps all'avversario
	Moves *Focus_Blast = 	new Moves("Focus Blast " ,	"lotta" ,"speciale" , 120, 70, 5  );
	Moves *Flash_Cannon = 	new Moves("Flash Cannon " ,"acciaio" ,"speciale" , 80, 100, 10  );
	Moves *Toxic = 			new Moves("Toxic " ,		"veleno" ,"status" , 0, 90, 20   );
	Moves *Dragon_Dance = 	new Moves("Dragon Dance " ,	"drago" ,"status no avversario" , 0, 100, 15   );
	Moves *Crunch = 		new Moves("Crunch " ,		"buio" ,"contatto" , 80, 100, 15  );
	Moves *Recover = 		new Moves("Recover " ,		"normale" ,"status no avversario" , 0, 100, 10  );
	Moves *Thunder_Wave = 	new Moves("Thunder Wave " ,	"elettro" ,"status" , 0, 100, 20   );
	Moves *Hydro_Pump = 	new Moves("Hydro Pump " ,	"acqua" ,"speciale" , 110, 80, 5  );
	Moves *Extreme_Speed = 	new Moves("Extreme Speed " ,"normale" ,"contatto" , 80, 100, 5   );
	Moves *Leaf_Storm = 	new Moves("Leaf Storm " ,	"erba" , "speciale", 130, 90, 5   );
	Moves *Fire_Punch = 	new Moves("Fire Punch " ,	"fuoco" ,"contatto" , 75, 100, 15    );
	Moves *Ice_Beam = 		new Moves("Ice Beam " , "ghiaccio","speciale" , 90, 100, 10  );
	Moves *Hypnosis 	 = 	new Moves("Hypnosis " ,"spettro" ,"status" , 0, 60, 10    );
	Moves *Ice_Shard = 		new Moves("Ice Shard " ,"ghiaccio" ,"contatto" , 40, 100, 30    );
	Moves *Night_Shade = 	new Moves("Night Shade " ,"spettro" ,"status" , 0, 100, 15    );
	Moves *Sunny_Day = 		new Moves("Sunny Day " ,"fuoco" , "status no avversario", 0, 100, 20   );
	Moves *Hyper_Beam = 	new Moves("Hyper Beam" ,"normale" ,"speciale" , 150, 90, 5   );
	Moves *Reflect =		new Moves("Reflect " ,"psico" ,"status no avversario" , 0, 100, 15    );
	Moves *Confuse_Ray	 = 	new Moves("Confuse Ray " ,"spettro" ,"status" , 0, 100, 30    );

	
	//devo mettergli gli effetti

	
	//Moves * = new ;  prototipo per mettere altre mosse

	
	
	
	Psychic->putEffects("riduci spatk avversario"); //la stringa deve essere uguale, non deve contenere spazi alla fine!
	Calm->putEffects("aumento spatk mio");
	Calm->putEffects("aumento spdef mio");
	Rage->putEffects("togli 40 ps");
	Dragon_Dance->putEffects("aumento speed mio");
	Dragon_Dance->putEffects("aumento atk mio");
	Leaf_Storm->putEffects("riduci spatk mio");
	Recover->putEffects("recupera ps");
	Explosion->putEffects("autodistruzione");
	Crunch->putEffects("riduci def avversario");
	Toxic->putEffects("avvelena sicuro");
	Sludge->putEffects("avvelena");
	Fire->putEffects("brucia");
	Thunder_Wave->putEffects("paralizza sicuro");
	Thunderbolt->putEffects("paralizza");
	Hypnosis->putEffects("addormenta sicuro");
	Ice_Beam->putEffects("congela");
	Night_Shade->putEffects("togli ps come il livello");
	Sunny_Day->putEffects("giornodisole");
	Confuse_Ray->putEffects("confuso sicuro");
	Fly->putEffects("volo");
	Reflect->putEffects("reflect");

	
	/*
	->putEffects("");
	->putEffects("");
	*/
	
	Extreme_Speed->putPriority(8); 
	Ice_Shard->putPriority(6);
	
	
	
    Pokemon *Forretress = 	new Pokemon("Forretress " , 75, 90, 140, 60, 60, 40,"acciaio" ,"coleottero" , 50    );
	Pokemon *Donphan= 		new Pokemon("Donphan " , 90, 120, 120, 60, 60, 50,"terra" ,"" , 50 );
    Pokemon *bulba = 		new Pokemon("bulbasaur", 20, 10, 10, 10, 25, 15, "erba", "veleno", 5);
    Pokemon *charmender = 	new Pokemon("charmender", 20, 15, 15, 8, 20, 20, "fuoco", "" , 5);
    Pokemon *Charizard =	new Pokemon("Charizard " , 78, 104, 78, 159, 115, 100, "fuoco" ,"volante" , 50   );
    Pokemon *Alakazam = 	new Pokemon("Alakazam " , 55, 50, 45, 135, 95, 120, "psico" ,"" , 50   );
    Pokemon *Gyarados = 	new Pokemon("Gyarados " , 95, 125, 79, 60, 100, 81,"acqua" ,"volante" , 50   );
    Pokemon *Salamence =	new Pokemon("Salamence " , 95, 135, 80, 110, 80, 100,"drago" ,"volante" , 50 );
    Pokemon *Zapdos = 		new Pokemon("Zapdos " , 90, 90, 85, 125, 90, 100,"elettro" ,"volante" , 50   );
    Pokemon *Venusaur = 	new Pokemon("Venusaur " , 80, 82, 83, 100, 100, 80,"erba" ,"veleno" , 50   );
    Pokemon *Tyranitar = 	new Pokemon("Tyranitar " , 100, 134, 110, 95, 100, 61,"roccia" ,"buio"  , 50   );
    Pokemon *Typhlosion = 	new Pokemon("Typhlosion " , 78, 84, 78, 109, 85, 100,"fuoco" ,"", 50   );
    Pokemon *Gengar   = 	new Pokemon("Gengar " , 60, 65, 60, 130, 75, 110, "spettro","veleno" ,50 );
    Pokemon *Hippowdon   = 	new Pokemon("Hippowdon " , 108, 112, 118, 68, 72, 47,"terra" ,"" ,50  );
    Pokemon *Abomasnow   = 	new Pokemon("Abomasnow " , 90, 92, 75, 92, 85, 60, "erba","ghiaccio" ,50  );
    
    
    
    bulba->putMove(azione1);    
    charmender->putMove(azioneSpec);    
    charmender->putMove(azione2);
    
	Charizard->putMove(Flamethrower );
	Charizard->putMove(Slash );
	Charizard->putMove(Fly );
	Charizard->putMove(Rage );

	Alakazam->putMove(Psychic );
	Alakazam->putMove(Calm );
	Alakazam->putMove(Focus_Blast);
	Alakazam->putMove(Recover );
	
	Gyarados->putMove(Waterfall );
	Gyarados->putMove(Dragon_Dance );
	Gyarados->putMove(Hydro_Pump );
	//Gyarados->putMove(Waterfall );
	
	Salamence->putMove(Dragon );
	Salamence->putMove(Extreme_Speed );
	Salamence->putMove(Hyper_Beam ); 
//	Salamence->putMove(Dragon );  se glielo mettessi i pp scendono a tutti i Dragon, devo cambiargli nome al puntatore
	
	Zapdos->putMove( Thunderbolt);
	Zapdos->putMove( Thunder_Wave);
//	Zapdos->putMove( Thunderbolt);
//	Zapdos->putMove( Thunderbolt);
	
	Venusaur->putMove( Sludge);
	Venusaur->putMove( Seed);
	Venusaur->putMove( Toxic);
	Venusaur->putMove( Leaf_Storm);

	Tyranitar->putMove(Stone );
	Tyranitar->putMove(Crunch);
//	Tyranitar->putMove(Stone );
//	Tyranitar->putMove(Stone );
	
	Typhlosion->putMove(Fire );
	Typhlosion->putMove(Fire_Punch );
	Typhlosion->putMove(Sunny_Day );
//	Typhlosion->putMove(Fire );
	
	Donphan->putMove(Earthquake);
//	Donphan->putMove(Earthquake);
//	Donphan->putMove(Earthquake);
//	Donphan->putMove(Earthquake);
	
	Forretress->putMove(Explosion );
	Forretress->putMove(Flash_Cannon );
	Forretress->putMove(Reflect );
//	Forretress->putMove(Explosion );


	Gengar->putMove(Night_Shade );
	Gengar->putMove(Hypnosis );	
	Gengar->putMove(Confuse_Ray );
//	Gengar->putMove( );


//	Hippowdon->putMove( );
//	Hippowdon->putMove( );
//	Hippowdon->putMove( );
//	Hippowdon->putMove( );


	Abomasnow->putMove(Ice_Shard );
	Abomasnow->putMove(Ice_Beam );
//	Abomasnow->putMove( );
//	Abomasnow->putMove( );


	Allenatore Luca("Luca"); 
	Allenatore Stefano("Stefano");
	
	Luca.putPokemon(Donphan );
	Luca.putPokemon( Charizard);
	Luca.putPokemon(Alakazam );
	Luca.putPokemon( Gyarados);
	Luca.putPokemon(Salamence );
	Luca.putPokemon(Abomasnow );

	Stefano.putPokemon(Forretress );
	Stefano.putPokemon(Zapdos );
	Stefano.putPokemon(Venusaur );
	Stefano.putPokemon(Tyranitar );
	Stefano.putPokemon( Typhlosion);
	Stefano.putPokemon(Gengar );

	
	
    
    Lotta(Luca, Stefano, Lega_Pokemon);
	
	return 0;
}
