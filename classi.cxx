#include <iostream>
#include "pok.h"
#include <cstdlib>

Moves::Moves()
	{         m_name="???";
			  m_type="???";
			  m_category="???";
			  m_power=0;
			  m_accuracy=0;
			  m_pp=0;
			 
	}
	Moves::Moves(std::string name, std::string type, std::string category, 
	      int power, int accuracy, int pp)
	      {
			  m_name=name;
			  m_type=type;
			  m_category=category;
			  m_power=power;
			  m_accuracy=accuracy;
			  m_effects;
			  m_pp=pp;
			  m_priority=5; //per attacco rapido ecc. di default 5
		  }
		  
    void Moves::putName(std::string a)  	{  m_name=a;}
    void Moves::putType(std::string a)  	{  m_type=a;}
    void Moves::putCategory(std::string a) { m_category=a;}
    void Moves::putPower(int a)   			{ m_power=a;}
    void Moves::putAccuracy(int a)   		{ m_accuracy=a;}
    void Moves::putEffects(std::string a)  { m_effects.push_back(a);}
    void Moves::putPp(int a)			{ m_pp=a;}
    void Moves::putPriority(int a)		{ m_priority=a;}
    
    std::string Moves::getName()  		{  return m_name;}
    std::string Moves::getType()  		{  return m_type;}
    std::string Moves::getCategory() 	{ return m_category;}
    int Moves::getPower()   			{ return m_power;}
    int Moves::getAccuracy()   		{ return m_accuracy;}
    int Moves::getPp()					{ return m_pp;}
    std::vector<std::string> Moves::getEffects()  { return m_effects;}
    int Moves::getPriority()		{return m_priority;}
    
    
    
    
    
    
 Pokemon::Pokemon()
    { 
		m_ps=m_atk=m_spatk=m_def=m_spdef=m_speed=m_level=0;
		m_type1=m_type2=m_name= "???";
		
	}	
	//abilità e natura meglio metterli come parametri	
    Pokemon::Pokemon(std::string name, int ps, int atk, int def, int spatk, int spdef, int speed, std::string type1,
            std::string type2, /*std::vector<Moves*> moves, */
            int level)
            {//float(level) per forzare la divisione con frazione anche se ho interi
				m_currentPs=( (30 /*individual values*/ +(2*ps) /* + effort values / 4 */ )*(float(level)/100 )) + 10 + level;
				m_ps=(( (30 /*individual values*/ + 2 * ps /* + effort values / 4 */ ) * (float(level)/100 )) + 10 + level);
				m_atk= (( ( 30 /*individual values*/ + 2*atk /* + effort values / 4 */ ) * (float(level)/100) ) + 5 ) /* * natura */;
				m_currentAtk=(( ( 30 /*individual values*/ + 2*atk /* + effort values / 4 */ ) * (float(level)/100) ) + 5 ) /* * natura */;
				m_spatk=(( ( 30 /*individual values*/ + 2*spatk /* + effort values / 4 */ ) * (float(level)/100) ) + 5 ) /* * natura */;
				m_currentSpatk=(( ( 30 /*individual values*/ + 2*spatk /* + effort values / 4 */ ) * (float(level)/100) ) + 5 ) /* * natura */;
				m_def=(( ( 30 /*individual values*/ + 2*def /* + effort values / 4 */ ) * (float(level)/100) ) + 5 ) /* * natura */;
				m_currentDef=(( ( 30 /*individual values*/ + 2*def /* + effort values / 4 */ ) * (float(level)/100) ) + 5 ) /* * natura */;
				m_spdef=(( ( 30 /*individual values*/ + 2*spdef /* + effort values / 4 */ ) * (float(level)/100) ) + 5 ) /* * natura */;
				m_currentSpdef=(( ( 30 /*individual values*/ + 2*spdef /* + effort values / 4 */ ) * (float(level)/100) ) + 5 ) /* * natura */;
				m_speed=(( ( 30 /*individual values*/ + 2*speed /* + effort values / 4 */ ) * (float(level)/100) ) + 5 ) /* * natura */;
				m_currentSpeed=(( ( 30 /*individual values*/ + 2*speed /* + effort values / 4 */ ) * (float(level)/100) ) + 5 ) /* * natura */;
				m_level=level;
				m_type1= type1;
				m_type2= type2;
				m_name = name;
				m_moves;
				m_status= 1; // status che mi dice che è sano
				m_statusTemp=1; //status temporanei, questo è sano
				m_ricarica=0;
				m_confuso=false; //Non è confuso di default
				m_disappeared=false; //scomparso da mosse tipo volo ecc				
				m_natura; //natura pokemon
				m_modifyAtk=0;
				m_modifySpatk=0;
				m_modifyDef=0;
				m_modifySpdef=0;
				m_modifySpeed=0;
			}
		
    void Pokemon::putPs(int a)   {  m_currentPs=a;}
    void Pokemon::putAtk(int a)  {  m_currentAtk=a;}
    void Pokemon::putSpatk(int a) { m_currentSpatk=a;}
    void Pokemon::putDef(int a)   { m_currentDef=a;}
    void Pokemon::putSpdef(int a)   { m_currentSpdef=a;}
    void Pokemon::putSpeed(int a)   { m_currentSpeed=a;}
    void Pokemon::putLevel(int a)   { m_level=a;}
    void Pokemon::putType1(std::string a)   { m_type1=a;}
    void Pokemon::putType2(std::string a)   { m_type2=a;}
    void Pokemon::putName(std::string a)   { m_name=a;}
    void Pokemon::putMove(Moves* a) 		{ m_moves.push_back(a);} //acrobazia con puntatori
    void Pokemon::putStatus(int a)    { m_status=a;}
    void Pokemon::putStatusTemp(int a)			{ m_statusTemp=a;}
    void Pokemon::putRicarica(int a)			{ m_ricarica=a;}
    void Pokemon::putConfuso(bool a)			{ m_confuso=a;}
    void Pokemon::putNatura(std::string a)		{ m_natura=a;}
    void Pokemon::putAbilita(std::string a)		{ m_abilita=a;}
    void Pokemon::putStrumento(std::string a)	{ m_strumento=a;}
    void Pokemon::putDisappeared(bool a)		{ m_disappeared=a;}
    
    
    
//	void Pokemon::put( a)		{ m_=a;}
    
    
	void Pokemon::putModifyAtk(int a)			{m_modifyAtk=a;}
	void Pokemon::putModifySpatk(int a)			{m_modifySpatk=a;}
	void Pokemon::putModifyDef(int a)			{m_modifyDef=a;}
	void Pokemon::putModifySpdef(int a)			{m_modifySpdef=a;}
	void Pokemon::putModifySpeed(int a)			{m_modifySpeed=a;}
	
	
    int Pokemon::getMaxPs()			{return m_ps;} //distinguo i max ps da quelli attuali
    int Pokemon::getPs()			{return m_currentPs;}
        
    int Pokemon::getAtk()			{return m_currentAtk;}
    int Pokemon::getMaxAtk()		{return m_atk;}
    int Pokemon::getModifyAtk()		{return m_modifyAtk;}
    
    int Pokemon::getSpatk()			{return m_currentSpatk;}
    int Pokemon::getMaxSpatk()		{return m_spatk;}
    int Pokemon::getModifySpatk()	{return m_modifySpatk;}
    
    int Pokemon::getDef()			{return m_currentDef;}
    int Pokemon::getMaxDef()		{return m_spdef;}
    int Pokemon::getModifyDef()		{return m_modifySpatk;}
    
    int Pokemon::getSpdef()			{return m_currentSpdef;}
    int Pokemon::getMaxSpdef()		{return m_spdef;}
    int Pokemon::getModifySpdef()	{return m_modifySpatk;}
    
    int Pokemon::getSpeed()			{return m_currentSpeed;}
    int Pokemon::getMaxSpeed()		{return m_speed;}
    int Pokemon::getModifySpeed()	{return m_modifySpeed;}
    
    std::string Pokemon::getName()		{return m_name;}
    std::string Pokemon::getType1()		{return m_type1;}
    std::string Pokemon::getType2()		{return m_type2;}
    int Pokemon::getLevel()				{return m_level;}
    std::vector<Moves*> Pokemon::getMoves()     {return m_moves;}
    int Pokemon::getStatus() 				{ return m_status;}
    int Pokemon::getStatusTemp() 			{ return m_statusTemp;}   
    int Pokemon::getRicarica()				{ return m_ricarica;}
    bool Pokemon::getConfuso()				{ return m_confuso;}
    std::string Pokemon::getNatura()		{return m_natura;} 
    std::string Pokemon::getStrumento()		{return m_strumento;}
    std::string Pokemon::getAbilita()		{return m_abilita;}
    bool Pokemon::getDisappeared()			{return m_disappeared;}
    
    
    
//   Pokemon::get()		{return m_;}
   
    
    
    
    
    
    Allenatore::Allenatore(std::string name) //ho messo i puntatori perchè altrimenti non mi cambiava le variabili, probabilmente per la mancanza
	{                            //di memoria, quindi quando i pokemon sono presi dal vector dell'allenatore devo mettere ogni volta
		m_name=name;             // Pokemon*, anche a tutte le funzioni che usano come argomenti i Pokemon esplicitamente
		std::vector<Pokemon*> m_pokemon;	
		m_currentPokemon=0;
		m_finishBattle= true; //per far finire la battaglia senza exit
		m_stealth_rock=false; //esempio di entry hazard
		m_spikes=false;
		m_toxic_spikes=false;
		}
	std::string Allenatore::getName()  		{  return m_name;}
	std::vector<Pokemon*> Allenatore::getPokemon()	{ return m_pokemon;}
	int Allenatore::getCurrent()  	{ return m_currentPokemon;} //ritorna il pokemon che si ha
	bool Allenatore::getFinish() 	{return m_finishBattle;}
	int Allenatore::getReflect()		{return m_reflect;}
	bool Allenatore::getStealthRock()			{return m_stealth_rock;}
	bool Allenatore::getSpikes()					{return m_spikes;}
	bool Allenatore::getToxicSpikes()			{return m_toxic_spikes;}
	
	void Allenatore::putPokemon(Pokemon *a) { m_pokemon.push_back(a);}	
    void Allenatore::putName(std::string a)  	{  m_name=a;}
    void Allenatore::putCurrent(int a)		{m_currentPokemon = a;}
	void Allenatore::putFinish(bool a)		{m_finishBattle=a;}
	
    void Allenatore::putReflect(int a)		{ m_reflect=a;}
    void Allenatore::putStealthRock(bool a)		{m_stealth_rock=a;}
	void Allenatore::putSpikes(bool a)			{m_spikes=a;}
	void Allenatore::putToxicSpikes(bool a)		{m_toxic_spikes=a;}
    
    
    Campo::Campo() //guarda cosa succede se il pokemon viene sconfitto alla conta dei turni
	{
		m_turno=1;
		m_weather="";
		m_effect=""; //gli effetti possono essere tanti ma per ora tengo questi
		
		int m_weatherStart;
		int m_weatherEnd;
	
	}
    void Campo::putTurno(int a)				{m_turno=a;}
    
	void Campo::putWeather(std::string a)	{m_weather=a;}
	void Campo::putEffect(std::string a)	{m_effect=a;}
	void Campo::putweatherStart(int a)				{m_weatherStart=a;}
	void Campo::putweatherEnd(int a)				{m_weatherEnd=a;}
	
	int Campo::getTurno()					{return m_turno;}
	std::string Campo::getWeather()			{return m_weather;}
	std::string Campo::getEffect()			{return m_effect;}
	
    int Campo::getweatherStart()			{return m_weatherStart;}
	int Campo::getweatherEnd()				{return m_weatherEnd;}
    

    
    
    
    
    
    
    
