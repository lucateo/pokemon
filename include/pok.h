#include <iostream>
#include <math.h>
#include <string>
#include <vector>
//in tutto get è per visualizzarlo, put è per metterlo

/**
 * \class Campo
 * \brief Class for counting turns and effects that last in time
 *
 * \author Luca Teodori
 */
class Campo //per conta turni e altro
{
	public:
	/**
	 * Look at what happens when the pokemon gets defeated at the end of the turn
	 */
	Campo(); //guarda cosa succede se il pokemon viene sconfitto alla conta dei turni

	/**
	 * Puts the number of the turn you are in to print it at the beginning of it
	 * and to track the number for particular moves that last in time like reflect
   * \param a the number of the turn
	 */
	void putTurno(int a);
	/**
	 * Enters the type of weather you are in (sun, rain,...)
   * \param a the string for the weather, e.g. "sole"
	 */
	void putWeather(std::string a);
	/**
	 * put effects
	 */
	void putEffect(std::string a);
	//in realtà vanno in allenatore ma troppo sbatti

	/**
	 * Puts the start turn of the weather
	 */
	void putweatherStart(int a); //potrebbe essere buon metodo per turni
	/**
	 * It puts the end turn of the weather
	 */
	void putweatherEnd(int a);

	/**
	 * Returns the number of the turn you are in
	 */
	int getTurno();
	/**
	 * Returns the weather you are in
	 */
	std::string getWeather();
	/**
	 * Returns the effect
	 */
	std::string getEffect();

	/**
	 * Returns the number of the turn the weather condition began
	 */
	int getweatherStart();
	/**
	 * Returns the number of the turn the weather condition ended
	 */
	int getweatherEnd();

	// put < for Doxygen documentation if you want to put the description after the declaration of the stuff
	int m_turno; 			/**< The turn (contained in the class Campo) */
	std::string m_weather;	/**< The weather string, I cannot have more than one weather at once */
	std::string m_effect;	/**< The effect string (contained in the class Campo) */
	int m_weatherStart;		/**< The weather start turn (contained in the class Campo) */
	int m_weatherEnd;		/**< The weather end turn  (contained in the class Campo) */

};

/**
 * \class Moves
 * Class for moves
*/
class Moves
{
	public:
	Moves(); /**< Default constructor */

	/**
	* Full constructor for the moves, Moves(name of the move, type of the move,
	* category of the move (status/special/physical), power, accuracy, pp)
	*/
	Moves(std::string name, std::string type, std::string category,
	      int power, int accuracy, int pp);

  void putName(std::string a);  	/**< Puts the name on the move*/
  void putType(std::string a);  	/**< Puts the type on the move*/
  void putCategory(std::string a);/**< Puts the category on the move*/
  void putPower(int a);   		/**< Puts the power on the move */
  void putAccuracy(int a);   		/**< Puts the accuracy on the move */
  void putEffects(std::string a); /**< Puts the effect on the move */
  void putPp(int a);				/**< Puts the pp on the move */
  void putPriority(int a);		/**< Puts the priority on the move */

  std::string getName();  		/**< Return the name of the move */
  std::string getType();			/**< Return the type of the move */
  std::string getCategory();		/**< Return the category of the move */
  int getPower();					/**< Return the power of the move */
  int getAccuracy();				/**< Return the accuracy of the move */
  int getPp();					/**< Return the PP of the move */
  std::vector<std::string> getEffects();/**< Return the effect of the move */
  int getPriority();					/**< Return the priority  of the move */

	//private:
	std::string m_name;			/**< The name of the move */
	std::string m_type;			/**< The type of the move */
	std::string m_category;		/**< The category (status,physical, special) of the move */
	int m_power;				/**< The power of the move */
	int m_accuracy;				/**< The accuracy of the move */
	int m_pp;					/**< The pp of the move */
	std::vector<std::string> m_effects;	/**< The array of all the effects of the move */
	int m_priority;				/**< The integer specifying the priority of the move (the higher it is, the higher the priority */

};

/** The class for the pokemon */
class Pokemon
{
  public:
  Pokemon(); /**< default constructor */

  //this to put more elaborate description of the constructor later
  /** Full constructor  */
  /**
  * Pokemon(name of the move, ps, attack, defense, special attack, special defense, speed, type 1, type 2, level)
  */
  Pokemon(std::string name, int ps, int atk, int def, int spatk, int spdef, int speed, std::string type1,
          std::string type2, /*std::vector<Moves*> moves, */
          int level);
  ~Pokemon() {
    for (int i =0; i< m_moves.size();i++)
      delete m_moves[i];
  };
  void putPs(int a);		/**< Put the  on the Pokemon */
  void putAtk(int a);/**<  Put the  on the Pokemon */
  void putSpatk(int a);/**<  Put the  on the Pokemon */
  void putDef(int a);/**<  Put the  on the Pokemon */
  void putSpdef(int a);/**<  Put the  on the Pokemon */
  void putSpeed(int a);/**<  Put the  on the Pokemon */
  void putLevel(int a);/**<  Put the  on the Pokemon */
  void putType1(std::string a);/**<  Put the  on the Pokemon */
  void putType2(std::string a);/**<  Put the  on the Pokemon */
  void putName(std::string a);/**<  Put the  on the Pokemon */
  void putMove(Moves* a);/**<  Put the  on the Pokemon */
  void putStatus(int a);/**<  Put the  on the Pokemon */
  void putStatusTemp(int a);/**<  Put the  on the Pokemon */
  void putRicarica(int a);/**<  Put the  on the Pokemon */
  void putConfuso(bool a);/**<  Put the  on the Pokemon */
  void putNatura(std::string a);/**<  Put the  on the Pokemon */
  void putAbilita(std::string a);/**<  Put the  on the Pokemon */
  void putStrumento(std::string a);/**<  Put the  on the Pokemon */
  void putDisappeared(bool a);/**<  Put the  on the Pokemon */

  void putModifyAtk(int a);/**<  Put the  on the Pokemon */
  void putModifySpatk(int a);/**<  Put the  on the Pokemon */
  void putModifyDef(int a);/**<  Put the  on the Pokemon */
  void putModifySpdef(int a);/**<  Put the  on the Pokemon */
  void putModifySpeed(int a);/**< Put the  on the Pokemon */

  int getMaxPs(); /**< Returns the of the Pokemon */
  int getPs();/**< Returns the of the Pokemon */

  int getAtk();/**< Returns the of the Pokemon */
  int getMaxAtk();/**< Returns the of the Pokemon */
  int getModifyAtk();/**< Returns the of the Pokemon */

  int getSpatk();/**< Returns the of the Pokemon */
  int getMaxSpatk();/**< Returns the of the Pokemon */
  int getModifySpatk();/**< Returns the of the Pokemon */

  int getDef();		/**< Returns the of the Pokemon */
  int getMaxDef();/**< Returns the of the Pokemon */
  int getModifyDef();/**< Returns the of the Pokemon */

  int getSpdef();		/**< Returns the of the Pokemon */
  int getMaxSpdef();	/**< Returns the of the Pokemon */
  int getModifySpdef();/**< Returns the of the Pokemon */

  int getSpeed();/**< Returns the of the Pokemon */
  int getMaxSpeed();/**< Returns the of the Pokemon */
  int getModifySpeed();/**< Returns the of the Pokemon */

  std::string getName(); /**< Returns the of the Pokemon */
  std::string getType1();/**< Returns the of the Pokemon */
  std::string getType2();/**< Returns the of the Pokemon */
  int getLevel();/**< Returns the of the Pokemon */
  std::vector<Moves*> getMoves();/**< Returns the of the Pokemon */
  int getStatus();/**< Returns the of the Pokemon */
  int getStatusTemp();/**< Returns the of the Pokemon */
  int getRicarica();/**< Returns the of the Pokemon */
  bool getConfuso();/**< Returns the of the Pokemon */
  std::string getNatura();/**< Returns the of the Pokemon */
  std::string getStrumento();/**< Returns the of the Pokemon */
  std::string getAbilita();/**< Returns the of the Pokemon */
  bool getDisappeared();/**< Returns the of the Pokemon */

  // private:
  int m_currentPs;/**< of the pokemon currently */
  int m_currentAtk;/**< of the pokemon currently */
  int m_currentDef;/**< of the pokemon currently */
  int m_currentSpatk;/**< of the pokemon currently */
  int m_currentSpdef;/**<of the pokemon  currently */
  int m_currentSpeed;/**< of the pokemon currently */

  int m_ps;/**< of the pokemon*/
  int m_atk;/**< of the pokemon*/
  int m_spatk;/**< of the pokemon*/
  int m_def;/**< of the pokemon*/
  int m_spdef;/**< of the pokemon*/
  int m_speed;/**< of the pokemon*/
  int m_level;/**<of the pokemon */
  std::string m_type1;/**< of the pokemon*/
  std::string m_type2;/**< of the pokemon*/
  std::string	m_name;      /**< of the pokemon*/
  std::vector<Moves*> m_moves; /**< vector of moves for the moves of the Pokemon */

  int m_status; //per dire se è ko o meno (potrebbe avere anche altri bei scopi... come avvelenato ecc.)
  int m_statusTemp; 			/**< For temporary status */
  int m_ricarica; 			/**< Number to decide wether the pokemon needs to recharge (for moves like hyperbeam) */
  bool m_confuso;				/**< If it is true, it means the pokemon is confused */
  std::string m_natura;		/**< Contains the nature of the pokemon */
  std::string m_strumento;	/**< Contains the instrument a Pokemon keeps */
  std::string m_abilita;		/**< The ability of the pokemon*/
  bool m_disappeared;			/**< Tells wether the pokemon is on the field or not (for moves like fly, dig...) */

  int m_modifyAtk;			/**< The integer for the modification of the attack due to status moves */
  int m_modifySpatk;			/**<The integer for the modification of the special attack due to status moves */
  int m_modifyDef;			/**<The integer for the modification of the defense due to status moves */
  int m_modifySpdef;			/**<The integer for the modification of the special defense due to status moves */
  int m_modifySpeed;			/**<The integer for the modification of the speed due to status moves */
};

/// Class for the trainer
class Allenatore
{
  public:
  Allenatore(std::string name); ///< trainer constructor with the name
  ~Allenatore() {
    for (int i =0; i< m_pokemon.size();i++)
      delete m_pokemon[i];
  };
  std::string getName(); ///< it gets the name of the trainer
  std::vector<Pokemon*> getPokemon(); ///< vector of pokemon the trainer has
  int getCurrent(); ///< it gets of the trainer
  bool getFinish();///< it gets of the trainer
  int getReflect();///< it gets of the trainer

  bool getStealthRock();///< it gets of the trainer
  bool getSpikes();///< it gets of the trainer
  bool getToxicSpikes();///< it gets of the trainer

  void putPokemon(Pokemon *a); ///< it puts on the trainer
  void putName(std::string a);///< it puts on the trainer
  void putCurrent(int a);		///< it puts on the trainer
  void putFinish(bool a);///< it puts on the trainer
  void putReflect(int a);///< it puts on the trainer

  void putStealthRock(bool a);///< it puts on the trainer
  void putSpikes(bool a);///< it puts on the trainer
  void putToxicSpikes(bool a);///< it puts on the trainer

  //private:

  std::string m_name; ///< name of the trainer
  std::vector<Pokemon*> m_pokemon; ///< vector of Pokemon of the trainer
  int m_currentPokemon; ///< the number corresponding to the current pokemon in the field
  bool m_finishBattle; ///< Tells wether the trainer has at least one pokemon still alive or not
  int m_reflect; ///< tells the turn of reflect
  bool m_toxic_spikes;///< tells wether it is in the field of the trainer or not
  bool m_spikes;///< tells wether it is in the field of the trainer or not
  bool m_stealth_rock;///< tells wether it is in the field of the trainer or not
};
/// overload operator to print on terminal all the feature of the pokemon on the field
std::ostream &operator<<(std::ostream &out, Pokemon &a); //lo devo ASSOLUTAMENTE DEFINIRE
                                                 //come free function!!!!!!!!!!
/// Function for the battle between pokemon
void Lotta(Pokemon* a, Pokemon* b); //lotta tra due pokemon
/// Function to initialize the battle between two trainers
void Lotta(Allenatore a, Allenatore b, Campo *c); //lotta tra due allenatori  //TUTTI ESEMPI DI FUNZIONI CHE USANO I POKEMON PRESI
//void Lottare(Allenatore a, Allenatore b); //per lottare in mezzo    //DAL VECTOR<POKEMON*> DI ALLENATORE, QUINDI DEVO METTERE
/// Function to use the move of the pokemon
/** UsaMossa(move used, pokemon that uses the move, pokemon the move acts upon, the field,
* the trainer of the pokemon, the opponent trainer
*/
void UsaMossa(Moves *a, Pokemon* b, Pokemon* c, Campo *d, Allenatore *e, Allenatore *f);                     //I PUNTATORI
/// It controls the status of pokemon, to end the battle if needed
int ControlStatus(Allenatore *a, Allenatore *b);
/// It is called when one wants to escape
void fuga(Allenatore *a, Allenatore b, Campo c);

/// To change the pokemon with the one corresponding to the position m
void cambio(Allenatore* a, int m);

/// It changes the pokemon without calling the return option, this apply when a pokemon is defeated and a change must be fullfilled
void cambioNoReturn(Allenatore *a, Allenatore *b);

/// It kills a pokemon and calls the appropriate functions
void uccidi(Allenatore* a, Allenatore* b);
/// Uses the effect of the move
void useEffect(std::string effect, Pokemon *a, Pokemon *b, Campo *c, Allenatore *d, Allenatore *e);

/// Display to choose what to do
int Dispay(Allenatore *a, Allenatore *b);
/// Display for the change option
int cambioDisplay(Allenatore *a, Allenatore *b);
/// Display for the battle
int LottaDisplay(Pokemon *a, Allenatore *b, Allenatore *c);

/// It controls how the move is effective against the second pokemon
float controlType(Moves a, Pokemon* b, Pokemon *c);
/// It controls if the move receives Stab bonus
float controlStab(Moves a, Pokemon* b);
/// It controls
void ControlStatusDanni(Allenatore *a, Allenatore *b); //da mettere alla fine del turno
/// It controls
void ControlStatusAttacco(Allenatore *a); //per paralizzato ecc.
/// It controls
void controlStat(Pokemon *a); //per modificatori
/// It controls	the weather
float ControlWeather(Pokemon *a, Pokemon* b, Moves *c, Campo *d);
/// It controls if the weather ended
void ControlWeatherEnd(Campo *d);
/// It controls	if the pokemon has to charge due to a move
int  controlRicarica(Pokemon* a, Campo *c);











