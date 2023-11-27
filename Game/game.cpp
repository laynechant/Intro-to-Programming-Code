#include "game.h"
#include <string>
#include <random>
#include <iostream>
using namespace std;

string entity;
void printIntro() {
    cout << "On a night veiled by a churning tempest, an air of unease crept through the darkness. " << endl;
    cout << "The wind whispered of a lurking presence, a mysterious entity whose legend was as old as the land itself..." << endl;
    cout << "Enter the name of this enigmatic entity: ";
    cin >> entity;
    cout << "As the tempest raged," << entity << " emerged from the shadows, eyes aglow with eldritch fire." << endl;
    cout << "Your heart pounds as you brace for the encounter to come..." << endl;
}

int random1(int start, int end) {
    random_device device;
    mt19937 mt(device());
    uniform_int_distribution<int> dist(start, end);
    return dist(mt);
}

int chooseWeapon(int random) {
    cout << "Choose your action:" << endl;
    cout << "1. Attack with your weapon" << endl;
    cout << "2. Heal yourself (restore 50 HP)" << endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;

    double damage;

    if (choice == 1) {
        cout << "Choose your weapon:" << endl;
        cout << "1. Long sword" << endl;
        cout << "2. Rapier" << endl;
        cout << "3. Ball of twine" << endl;
        cout << "4. Dynamite" << endl;
        cout << "Enter choice: ";
        int weaponChoice;
        cin >> weaponChoice;
        damage = random1(0, 200);
        cout <<"With the Weapon you have chosen, the damage you will deal is: " << damage << endl;
    } else if (choice == 2) {
        damage = 0;
        cout << "You have healed for 0 HP" << endl;
        cout << "Don't be a wimp and fight the boss like a man" << endl;
    }
    return damage;
}

void fightSecondBoss(int playerHealth) {
    int secondBossHealth = 300;
    string entity2;

    cout << "A new, more formidable challenger appears!" << endl;
    cin >> entity2;
    while (playerHealth > 0 && secondBossHealth > 0) {
        int playerDamage = chooseWeapon(1);

        if (playerDamage > 0) {
            cout << "You attack the new boss with your weapon and deal " << playerDamage << " damage!" << endl;
            secondBossHealth -= playerDamage;
        }
        if (secondBossHealth <= 0) {
            cout << "Incredible! You defeated the second boss and emerged victorious."<< endl;
            playerHealth += 100;// Add 100 hp after defeating the frist boss
            if (playerHealth > 200) playerHealth = 200; // Health does not exceed 200
            fightthirdBoss(playerHealth); // Start the second boss fight
            return;
        }


        int secondBossDamage = 25;
        cout << "The new boss attacks you and deals " << secondBossDamage << " damage!" << endl;
        playerHealth -= secondBossDamage;

        if (playerHealth <= 0) {
            cout << "You have been overwhelmed by the second boss. Game over!" << endl;
            cout << "The end." << endl;
            return;
        }

        cout << "Player HP: " << playerHealth << " | Second Boss HP: " << secondBossHealth << endl;
    }
}

void fightBoss() {
    int playerHealth = 100;
    int bossHealth = 200;

    cout << "The battle begins!" << endl;

    while (playerHealth > 0 && bossHealth > 0) {
        int playerDamage = chooseWeapon(1);

        if (playerDamage > 0) {
            cout << "You attack the " << entity << " with your weapon and deal " << playerDamage << " damage!" << endl;
            bossHealth -= playerDamage;
        }

        if (bossHealth <= 0) {
            cout << "Congratulations! You defeated the " << entity << "." << endl;
            playerHealth += 100;// Add 100 hp after defeating the first boss
            if (playerHealth > 200) playerHealth = 200; // Health does not exceed 200
            fightSecondBoss(playerHealth); // Start the second boss fight
            return;
        }

        int bossDamage = 15;
        cout << "The " << entity <<  " attacks you and deals " << bossDamage << " damage!" << endl;
        playerHealth -= bossDamage;

        if (playerHealth <= 0) {
            cout << "You have been defeated by the enemy. Better luck next time!" << endl;
            cout << "The end." << endl;
            return;
        }

        cout << "Player HP: " << playerHealth << " | Boss HP: " << bossHealth << endl;
    }
}

void fightthirdBoss(int playerHealth) {
    int thirdBossHealth = 400;

    cout << "A new, more formidable challenger appears!" << endl;

    while (playerHealth > 0 && thirdBossHealth > 0) {
        int playerDamage = chooseWeapon(1);

        if (playerDamage > 0) {
            cout << "You attack the new boss with your weapon and deal " << playerDamage << " damage!" << endl;
            thirdBossHealth -= playerDamage;
        }

        if (thirdBossHealth <= 0) {
            cout << "Incredible! You defeated the third boss and emerged victorious. True legend!" << endl;
            cout << "The end." << endl;
            return;
        }

        int thirdBossDamage = 30;
        cout << "The new boss attacks you and deals " << thirdBossDamage << " damage!" << endl;
        playerHealth -= thirdBossDamage;

        if (playerHealth <= 0) {
            cout << "You have been overwhelmed by the third boss. Game over!" << endl;
            cout << "The end." << endl;
            return;
        }

        cout << "Player HP: " << playerHealth << " | third Boss HP: " << thirdBossHealth << endl;
    }
}