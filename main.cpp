#include <iostream>
#include <ctime>

#include <cassert>
#include <vector>
#include <string>

using namespace std;

//#include "player.h"//game player
//#include "enemy.h"//game enemy

//later classes only with test, to fit the ctiteria
//#include "weapon.h"
//#include "inventory.h"

//#include "character.h"
//#include "monster.h"//inherited from character class
//#include "boss.h"//inherited from character class
//#include "npc.h"//inherited from character class

//#include "animal.h"// +4 classes inherited in line from animal: animal-pet-dog-pupppy and tests for them

//


//player

class Player
{
public:

    Player()
    {
        cout << "(player obj is created, his introduction text)" << endl;
        cout << "hi! i am a knight. we need to save this kingdom from the enemy!" << endl;
        cout << "________________________" << endl;
        cout << "player's Attack range is between " << minDamage << " - " << maxDamage << endl;
        cout << "________________________" << endl;
        cout << "player's Healing Range is between " << minHealing << " - " << maxHealing << endl;
        cout << "________________________" << endl;
    }//constructing object with introdction in terminal

    int GetHealth()
    {
        return health;
    }//getter

    void TakeDamage(int damage)
    {
        cout << "Ohh no, a critical hit to player:() " << endl;
        cout << "Enemy is dealing damage of " << damage << "to the player" << endl;
        health = health - damage;

        if (health < 0)
        {
            cout << "player died... game over" << endl;
        }


        else
        {
            cout << "player's current health after recieving the damage is: " << health << endl;
        }

    }

    int GiveDamage() //atacking mechanics
    {
        srand(time(0));
        int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);

        cout << "player is performing hit of " << randomDamage << " to the enemy" << endl;

        return randomDamage;
    }

    void Heal()// healing machanic
    {
        srand(time(0));
        int randomHeal = (rand() % (maxHealing - minHealing + 1) + minHealing);

        health = health + randomHeal;

        cout << "player Healed with HP of " << randomHeal << endl;

        cout << "Player's health afyer healing is " << health << endl;
    }

private:
    int health = 100;

    int maxDamage = 30;
    int minDamage = 20;

    int maxHealing = 15;
    int minHealing = 8;

};
//
//enemy


class Enemy
{
public:

    Enemy()
    {
        cout << "i'm an enemy" << endl;
    }


    int GetHealth()
    {
        return health;
    }
    void TakeDamage(int damage)
    {

        cout << " a critical hit to enemy) " << endl;
        cout << "player is dealing damage of " << damage << "to the enemy" << endl;
        health = health - damage;



        if (health < 0)
        {
            cout << "enemy died. You win!!! :) ) " << endl;
        }
        else
        {
            cout << "enemy's current health after recieving the damage is: " << health << endl;
        }


    }

    int GiveDamage()
    {
        srand(time(0));
        int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);

        return randomDamage;
    }


private:
    int health = 100;

    int maxDamage = 20;
    int minDamage = 10;



};

//
// animal


class Animal {
public:
    Animal()//constructor po umolchaniyu
    {

    }
    ~Animal()//destructor po umolchaniyu
    {
    }

    void makeSound() {
        cout << "animal makesound function" << endl;
    }
private:
    int age;
    string name;
};

class Pet : public Animal {
public:


    void play() {
        cout << "pet play function" << endl;
    }
private:
    bool hasOwner;
};

class Dog : public Pet {
public:

    void bark() {
        cout << "dog bark function" << endl;
    }
private:
    string breed;
};

class Puppy : public Dog {
public:


    void wagTail() {
        cout << "puppy wigtail function" << endl;
    }
};
//
// character


class Character {
public:
    Character(string name, int health, int damage) : name(name), health(health), damage(damage) {}

    string GetName() const {
        return name;
    }

    int GetHealth() const {
        return health;
    }

    int GetDamage() const {
        return damage;
    }

    void TakeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }

    bool IsAlive() const {
        return health > 0;
    }

private:
    string name;
    int health;
    int damage;
};

//monster



class Monster : public Character {
public:
    Monster(string name, int health, int damage) : Character(name, health, damage) {}
};
void TestMonster() {
    Monster goblin("Goblin", 30, 5);
    assert(goblin.GetName() == "Goblin");
    assert(goblin.GetHealth() == 30);
    assert(goblin.GetDamage() == 5);

    cout << "Monster test passed" << endl;
}
// boss


class Boss : public Monster {
public:
    Boss(string name, int health, int damage, int bossLevel) : Monster(name, health, damage), bossLevel(bossLevel) {}

    int GetBossLevel() const {
        return bossLevel;
    }

private:
    int bossLevel;
};
void TestBoss() {
    Boss dragon("Dragon Boss", 150, 30, 5);
    assert(dragon.GetName() == "Dragon Boss");
    assert(dragon.GetHealth() == 150);
    assert(dragon.GetDamage() == 30);
    assert(dragon.GetBossLevel() == 5);

    cout << "Boss test passed." << endl;
}
//
//npc
class NPC : public Character {
public:
    NPC(string name, int health, int damage, string role) : Character(name, health, damage), role(role) {}

    string GetRole() const {
        return role;
    }

private:
    string role;
};
void TestNPC() {
    NPC merchant("Merchant", 100, 10, "Trader");
    assert(merchant.GetName() == "Merchant");
    assert(merchant.GetRole() == "Trader");

    cout << " NPC test passed." << endl;
};
//weapon

class Weapon {
public:
    Weapon(string name, int damage) : name(name), damage(damage) {}

    int GetDamage() const {
        return damage;
    }

private:
    string name;
    int damage;
};
void TestWeapon() {
    Weapon sword("Sword", 20);

    assert(sword.GetDamage() == 20);

    cout << "Weapon test passed." << endl;
}

//inventory

class Inventory {
public:
    void AddWeapon(const Weapon& weapon) {
        weapons.push_back(weapon);
    }

    const vector<Weapon>& GetWeapons() const {
        return weapons;
    }

private:
    vector<Weapon> weapons;
};
void TestInventory() {
    Inventory inventory;
    Weapon sword("Sword", 20);
    Weapon axe("Axe", 30);

    inventory.AddWeapon(sword);
    inventory.AddWeapon(axe);

    assert(inventory.GetWeapons().size() == 2);

    // 
    assert(inventory.GetWeapons()[0].GetDamage() == 20);
    assert(inventory.GetWeapons()[1].GetDamage() == 30);

    cout << "inventory test passed" << endl;
}




void gameStory() {

    cout << endl << endl;
    cout << "_________________________________________________________________________________________________________________________" << endl;
    cout << "|                                           WELCOME TO THE LAB#2 GAME!                                                  |" << endl;
    cout << "|                                           (Grishina Kseniya 23-b18)                                                   |" << endl;
    cout << "|                                                                                                                       |" << endl;
    cout << "|  You are standing in a dark forest. In front of you is a someone that doesnt look friendly. and i think it is hungry. |" << endl;
    cout << "|                                                                                                                       |" << endl;
    cout << "|  You know you must defeat it to survive. But the enemy seems to be strong, and you do not have much health.           |" << endl;
    cout << "|                                                                                                                       |" << endl;
    cout << "|  You must damage it to weaken it, but you must also remember to heal yourself so you do not die yourself.             |" << endl;
    cout << "|                                                                                                                       |" << endl;
    cout << "|                                                                                                                       |" << endl;
    cout << "|_______________________________________________________________________________________________________________________|" << endl << endl << endl;

    cout << "______________________________________________________________________________" << endl;
    cout << "|                                 CONTROL INFO                               |" << endl;
    cout << "|                                                                            |" << endl;
    cout << "|  On each turn, you can do one of two actions:                              |" << endl;
    cout << "|                                                                            |" << endl;
    cout << "|  - Damage the enemy.                                                       |" << endl;
    cout << "|  - Heal yourself.                                                          |" << endl;
    cout << "|                                                                            |" << endl;
    cout << "| If you damage the ogre enough, it will die. If you die, the game will end. |" << endl;
    cout << "|____________________________________________________________________________|" << endl << endl;
}

void battleLoop(Player player, Enemy enemy)
{

    char playerChoice;

    do {
        cout << "press A to attack or H to heal" << endl;
        cin >> playerChoice;
        if (playerChoice == 'A' || playerChoice == 'a')
        {

            //attack
            enemy.TakeDamage(player.GiveDamage());

            if (enemy.GetHealth() > 0)//if enemy alive he attacks
            {
                cout << "ha ha ha, its my turn now!!!" << endl;
                player.TakeDamage(enemy.GiveDamage());
            }


        }
        else if (playerChoice == 'H' || playerChoice == 'h')
        {

            //healing
            player.Heal();

            if (enemy.GetHealth() > 0)//if enemy alive he attacks
            {
                cout << "ha ha ha, its my turn now!!!" << endl;
                player.TakeDamage(enemy.GiveDamage());
            }

        }
        else
        {
            cout << "invalid input" << endl;
        }
    } while (player.GetHealth() > 0 && enemy.GetHealth() > 0);
}

int main() {
    /*  tests */
    TestWeapon();
    TestInventory();

    //puppy is the animal last inherited class test(means that all animals classes work (incapsulation priciple))
    Puppy puppy;

    puppy.makeSound(); // animal's method
    puppy.play(); // pet's method
    puppy.bark(); // dpg's method
    puppy.wagTail(); // puppy's method



    // obj inherited from character class tests:
    TestMonster();
    TestBoss();
    TestNPC();

    /* working cli game code    */

    gameStory();

    char userInput;

    do
    {
        cout << "press S to Start the game and any other key to exit!" << endl;
        cin >> userInput;

        if (userInput == 'S' || userInput == 's')
        {
            Player playerObj;//creating a player's obj
            Enemy enemyObj;//creating a enemy's obj
            battleLoop(playerObj, enemyObj);// battle mechanics including:  attack and heal mechanics // (enemy and player interaction)

        }
        else
        {
            cout << "Thanks for playing!" << endl;
        }


    } while (userInput == 'S' || userInput == 's');

    return 0;
}
