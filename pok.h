#include <iostream>
#include <math.h>
#include <string>
#include <vector>
//in tutto get è per visualizzarlo, put è per metterlo

class Campo //per conta turni e altro
{
	public:
	Campo(); //guarda cosa succede se il pokemon viene sconfitto alla conta dei turni
	
	void putTurno(int a);
	void putWeather(std::string a);
	void putEffect(std::string a);
	//in realtà vanno in allenatore ma troppo sbatti
	
	
	void putweatherStart(int a); //potrebbe essere buon metodo per turni
	void putweatherEnd(int a);
	
	int getTurno();
	std::string getWeather();
	std::string getEffect();
	

	int getweatherStart();
	int getweatherEnd();
	
	int m_turno;
	std::string m_weather;
	std::string m_effect;
	int m_weatherStart;
	int m_weatherEnd;
	
};


class Moves
{
	public:
	Moves();
	
	Moves(std::string name, std::string type, std::string category, 
	      int power, int accuracy, int pp);
	      
		  
    void putName(std::string a);  	
    void putType(std::string a);  	
    void putCategory(std::string a); 
    void putPower(int a);   			
    void putAccuracy(int a);   		
    void putEffects(std::string a);  
    void putPp(int a);
    void putPriority(int a);			
    
    std::string getName();  		
    std::string getType();
    std::string getCategory();
    int getPower();
    int getAccuracy();
    int getPp();
    std::vector<std::string> getEffects();
    int getPriority();
    
	//private:
	          std::string m_name;
			  std::string m_type;
			  std::string m_category;
			  int m_power;
			  int m_accuracy;
			  int m_pp;
			  std::vector<std::string> m_effects;
			  int m_priority;
	
};


class Pokemon
{
   public:
    Pokemon();

		
    Pokemon(std::string name, int ps, int atk, int def, int spatk, int spdef, int speed, std::string type1,
            std::string type2, /*std::vector<Moves*> moves, */
            int level);
            
		
    void putPs(int a);
    void putAtk(int a);
    void putSpatk(int a);
    void putDef(int a);
    void putSpdef(int a);
    void putSpeed(int a);
    void putLevel(int a);
    void putType1(std::string a);
    void putType2(std::string a);
    void putName(std::string a);
    void putMove(Moves* a);
    void putStatus(int a);
    void putStatusTemp(int a);
    void putRicarica(int a);
    void putConfuso(bool a);
    void putNatura(std::string a);
    void putAbilita(std::string a);
    void putStrumento(std::string a);
    void putDisappeared(bool a);

    
   void putModifyAtk(int a);
   void putModifySpatk(int a);
   void putModifyDef(int a);
   void putModifySpdef(int a);
   void putModifySpeed(int a);
   
    int getMaxPs();
    int getPs();
         
    int getAtk();
    int getMaxAtk();
    int getModifyAtk();
    
    int getSpatk();
    int getMaxSpatk();
    int getModifySpatk();
    
    int getDef();		
    int getMaxDef();
    int getModifyDef();
    
    int getSpdef();		
    int getMaxSpdef();	
    int getModifySpdef();
    
    int getSpeed();
    int getMaxSpeed();
    int getModifySpeed();
    
    std::string getName();
    std::string getType1();
    std::string getType2();
    int getLevel();
    std::vector<Moves*> getMoves();
    int getStatus();
    int getStatusTemp();
    int getRicarica();
    bool getConfuso();
    std::string getNatura();
    std::string getStrumento();
    std::string getAbilita();
    bool getDisappeared();

    
   // private:
     int m_currentPs;
     int m_currentAtk;
     int m_currentDef;
     int m_currentSpatk;
     int m_currentSpdef;
     int m_currentSpeed;
     
     int m_ps;
     int m_atk;
     int m_spatk;
     int m_def;
     int m_spdef;
     int m_speed;
     int m_level;
	std::string m_type1;
	std::string m_type2;
	std::string	m_name;      
    std::vector<Moves*> m_moves; //vector di moves per mosse
    
    int m_status; //per dire se è ko o meno (potrebbe avere anche altri bei scopi... come avvelenato ecc.)
    int m_statusTemp; //status temporanei
    int m_ricarica; //per ricarica
    bool m_confuso;
    std::string m_natura;
    std::string m_strumento;
    std::string m_abilita;
    bool m_disappeared;
    
    int m_modifyAtk;
	int m_modifySpatk;
	int m_modifyDef;
	int m_modifySpdef;
	int m_modifySpeed;
	
};   

class Allenatore
{
	public:
	Allenatore(std::string name); //ho messo i puntatori perchè altrimenti non mi cambiava le variabili, probabilmente per la mancanza
	
	std::string getName();
	std::vector<Pokemon*> getPokemon();
	int getCurrent();
	bool getFinish();
	int getReflect();
	
	bool getStealthRock();
	bool getSpikes();
	bool getToxicSpikes();

	
	
	
	void putPokemon(Pokemon *a);	
    void putName(std::string a);
    void putCurrent(int a);		
	void putFinish(bool a);
	void putReflect(int a);
	
	void putStealthRock(bool a);
	void putSpikes(bool a);
	void putToxicSpikes(bool a);

	//private:
	
	std::string m_name;
	std::vector<Pokemon*> m_pokemon;
	int m_currentPokemon;
	bool m_finishBattle;
	int m_reflect;
	bool m_toxic_spikes;
	bool m_spikes;
	bool m_stealth_rock;
	
	};

    std::ostream &operator<<(std::ostream &out, Pokemon &a); //lo devo ASSOLUTAMENTE DEFINIRE 
                                                             //come free function!!!!!!!!!!
    void Lotta(Pokemon* a, Pokemon* b); //lotta tra due pokemon          
    void Lotta(Allenatore a, Allenatore b, Campo *c); //lotta tra due allenatori  //TUTTI ESEMPI DI FUNZIONI CHE USANO I POKEMON PRESI
    //void Lottare(Allenatore a, Allenatore b); //per lottare in mezzo    //DAL VECTOR<POKEMON*> DI ALLENATORE, QUINDI DEVO METTERE
    void UsaMossa(Moves *a, Pokemon* b, Pokemon* c, Campo *d, Allenatore *e, Allenatore *f);                     //I PUNTATORI
    int ControlStatus(Allenatore *a, Allenatore *b);
    void fuga(Allenatore *a, Allenatore b, Campo c);
    
    void cambio(Allenatore* a, int m);
    void cambioNoReturn(Allenatore *a, Allenatore *b);
    
    void uccidi(Allenatore* a, Allenatore* b);
	void useEffect(std::string effect, Pokemon *a, Pokemon *b, Campo *c, Allenatore *d, Allenatore *e);
	
	int Dispay(Allenatore *a, Allenatore *b);
    int cambioDisplay(Allenatore *a, Allenatore *b);
    int LottaDisplay(Pokemon *a, Allenatore *b, Allenatore *c);
          
    float controlType(Moves a, Pokemon* b, Pokemon *c);
    float controlStab(Moves a, Pokemon* b);
	void ControlStatusDanni(Allenatore *a, Allenatore *b); //da mettere alla fine del turno
	void ControlStatusAttacco(Allenatore *a); //per paralizzato ecc.
	void controlStat(Pokemon *a); //per modificatori
    float ControlWeather(Pokemon *a, Pokemon* b, Moves *c, Campo *d);
	void ControlWeatherEnd(Campo *d);
	int  controlRicarica(Pokemon* a, Campo *c);

    
    
    
    
    
    
    
    
    
    
