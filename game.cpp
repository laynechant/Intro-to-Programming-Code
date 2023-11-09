#include "game.h"
#include <string>
#include <iostream>
using namespace std;

string entity;
void printIntro() {

    cout << "On a night veiled by a churning tempest, an air of unease crept through the darkness. " << endl;
    cout << "The wind whispered of a lurking presence, a mysterious entity whose legend was as old as the land itself..." << endl;
    cout << "Enter the name of this enigmatic entity: ";
    cin >> entity;
    cout << "As the tempest raged," << entity << " emerged from the shadows,eyes aglow with eldritch fire."<< endl;
    cout << "Your heart pounds as you brace for the encounter to come..." << endl;
}

int chooseWeapon() {
    cout << "Choose your action:" << endl;
    cout << "1. Attack with your weapon" << endl;
    cout << "2. Heal yourself (restore 50 HP)" << endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;

    int damage;

    if (choice == 1) {
        cout << "Choose your weapon:" << endl;
        cout << "1. Long sword" << endl;
        cout << "2. Rapier" << endl;
        cout << "3. Ball of twine" << endl;
        cout << "4. Dynamite" << endl;
        cout << "Enter choice: ";
        int weaponChoice;
        cin >> weaponChoice;


        switch (weaponChoice) {
            case 1:
                damage = 20;
                break;
            case 2:
                damage = 15;
                break;
            case 3:
                damage = 5;
                break;
            case 4:
                damage = 200;
                break;
            default:
                damage = 0;
                break;
        }
    } else if (choice == 2) {
        damage = 0;
        cout << "You have healed for 0 HP" << endl;
        cout << "Don't be a wimp and fight the boss like a man" << endl;
    }
    return damage;
}

void fightboss() {
    int playerHealth = 100;
    int bossHealth = 200;

    cout << "The battle begins!" << endl;

    while (playerHealth > 0 && bossHealth > 0) {
        // Player chooses an action
        int playerDamage = chooseWeapon();


        if (playerDamage > 0) {
            cout << "You attack the " << entity << " with your weapon and deal " << playerDamage << " damage!" << endl;
            bossHealth -= playerDamage;
        }

        if (bossHealth <= 0) {
            cout << "Congratulations! You defeated the " << entity << " and saved the day. What a hero!" << endl;
            cout << "The end." << endl;
            return;
        }


        int bossDamage = 15;
        cout << "The " << entity <<  "attacks you and deals " << bossDamage << " damage!" << endl;
        playerHealth -= bossDamage;

        if (playerHealth <= 0) {
            cout << "You have been defeated by the enemy. Better luck next time!" << endl;
            cout << "The end." << endl;
            return;
        }

        cout << "Player HP: " << playerHealth << " | Boss HP: " << bossHealth << endl;
    }
}

