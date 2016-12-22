#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

int main()
{
  //Dont forget to seed your random engine with time!
  default_random_engine re(time(NULL));
  uniform_real_distribution<float> attack(0.0f, 1.0f);

  int humans;
  int humanDeaths;
  int orcs;
  int orcDeaths;

  int defaultHumanHP = 25;
  int defaultHumanAttackDamage = 10;
  float defaultHumanDefence = 70.0f;

  int defaultOrcHP = 30;
  int defaultOrcAttackDamage = 20;
  float defaultOrcDefence = 30.0f;
  
  int currentHumanHP;
  int currentOrcHP;

  bool fighting = true;
  bool gameover = false;
  char gamerestart;

  float attackRoll;
  do {
	  cout << "--== Humans vs. Orcs ==--" << endl << endl;
		cout << "How many Humans? ";
  	cin >> humans;

  	cout << endl << "How many Orcs? ";
  	cin >> orcs;

  	humanDeaths = 0;
  	orcDeaths = 0;
  	currentHumanHP = defaultHumanHP;
  	currentOrcHP = defaultOrcHP;
  	fighting = true;

  	while (fighting) {
  		cout << "Starting a fight between " << humans << " humans and " << orcs << " orcs" << endl;

	  	while (!(currentHumanHP <= 0 || currentOrcHP <= 0)) {
	  		attackRoll = attack(re);
	  		cout << attackRoll << " <= " << (defaultOrcDefence/100) << " == " << (attackRoll <= (defaultOrcDefence/100.0f)) << endl;
	  		if (attackRoll <= (defaultOrcDefence/100.0f)) {
	  			currentOrcHP -= defaultHumanAttackDamage;
	  		}

	  		attackRoll = attack(re);
	  		cout << attackRoll << " <= " << (defaultHumanDefence/100) << " == " << (attackRoll <= (defaultHumanDefence/100.0f)) << endl;
	  		if (attackRoll <= (defaultHumanDefence/100.0f)) {
	  			currentHumanHP -= defaultOrcAttackDamage;
	  		}
	  		cout << currentHumanHP << " - " << currentOrcHP << endl;
	  	}
	  	if (currentHumanHP <= 0) {
	  		currentHumanHP = defaultHumanHP;
	  		humans--;
	  		humanDeaths++;
	  	}
	  	else {
	  		currentOrcHP = defaultOrcHP;
	  		orcs--;
	  		orcDeaths++;
	  	}

	  	if (humans <= 0 || orcs <= 0) {
	  		fighting = false;
	  	}
  	}

  	cout << "Humans left: " << humans << endl;;
  	cout << "Orcs left: " << orcs << endl;

  	if (humans == 0) {
  		cout << "Orcs won!";
  	}
  	else {
  		cout << "Humans won!";
  	}

  	cout << "Fight over!" << endl << endl;
  	gamerestart = 'n';
  	cout << "Do you want another round? [y/n] ";
  	cin >> gamerestart;

  	if (gamerestart != 'y') {
  		gameover = true;
  	}
  } while (!gameover);

	return 0;	
}