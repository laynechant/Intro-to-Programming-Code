#include "game.h"
#include <string>
#include <random>
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;


void printWithTime(const string& str, chrono::milliseconds timeToWaitMs) {
    for (char c : str) {
        cout << c;
        cout.flush();
        this_thread::sleep_for(timeToWaitMs);
    }
}

void printIntro(string &entity) {

    printWithTime(
                  "###############                        #########                     #####################    \n"
                      "##             ###                   ##         ##                           #####                        \n"
                      "##               ###                ###         ###                          #####                   \n"
                      "##                 ###               ##         ##     ###                   #####              \n"
                      "##                  ###                #########     ##                      #####                 \n"
                      "##                 ###                ##        ## ##                        #####                 \n"
                      "##               ###                 ###        ###                          #####               \n"
                      "##             ###                    ##        ## ##                        #####                \n"
                      "###############                        #########    ###                      #####                  \n"
                      "\n", 1ms);

    printWithTime("On a night veiled by a churning tempest, an air of unease crept through the darkness.\n", 10ms);
    printWithTime("The wind whispered of a lurking presence, a mysterious entity whose legend was as old as the land itself...\n", 10ms);
    cout << "                ^    ^            " << endl;
    cout << "               / \\  //\\          " << endl;
    cout << " |\\___/|      /   \\//  .\\        " << endl;
    cout << " /O  O  \\__  /    //  | \\ \\     " << endl;
    cout << "/     /  \\/_/    //   |  \\  \\   " << endl;
    cout << "@___@'    \\/_   //    |   \\   \\ " << endl;
    cout << "   |       \\/_ //     |    \\    \\ " << endl;
    cout << "   |        \\///      |     \\     \\ " << endl;
    cout << "  _|_ /   )  //       |      \\     _\\" << endl;
    cout << " '/,_ _ _/  ( ; -.    |    _ _\\.-~        .-~~~^-." << endl;
    cout << " ,-{        _      `-.|.-~-.           .~         `." << endl;
    cout << "  '/\\      /                 ~-. _ .-~      .-~^-.  \\" << endl;
    cout << "     `.   {            }                   /      \\  \\" << endl;
    cout << "   .----~-.\        \\-'                 .~         \\  `. \\^-." << endl;
    cout << "  ///.----..>    c   \\             _ -~             `.  ^-`   ^-_" << endl;
    cout << "    ///-._ _ _ _ _ _ _}^ - - - - ~                     ~--,   .-~" << endl;
    cout << "                                                          /.-'" << endl;
    printWithTime("Enter the name of this enigmatic entity: ", 10ms);
    cin >> entity;

    printWithTime("As the tempest raged, " + entity + " emerged from the shadows, eyes aglow with eldritch fire.\n", 10ms);
    printWithTime("Your heart pounds as you brace for the encounter to come...\n", 10ms);




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
    cout << "2. Heal yourself (restore 10 HP)" << endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;

    double damage;

    if (choice == 1) {

        printWithTime("Choose your weapon:\n", 10ms);

        printWithTime("Choose your weapon: \n", 10ms);

        cout << "1. Long sword" << endl;
        cout << "2. Rapier" << endl;
        cout << "3. Ball of twine" << endl;
        cout << "4. Dynamite" << endl;
        cout << "Enter choice: ";
        int weaponChoice;
        cin >> weaponChoice;

        switch(weaponChoice)
        {
            case 1:
                damage = random1(weaponDamageLongSword[0], weaponDamageLongSword[1]);
                break;

            case 2:
                damage = random1(weaponDamageRapier[0], weaponDamageRapier[1]);
                break;

            case 3:
                damage = random1(weaponDamageBallOfTwine[0], weaponDamageBallOfTwine[1]);
                break;

            case 4:
                damage = random1(weaponDamageDynamite[0], weaponDamageDynamite[1]);
                break;

            default:
                cout << "This weapon does not exist" << endl;
        }

        cout <<"With the Weapon you have chosen, the damage you will deal is: " << damage << endl;
    } else if (choice == 2) {
        damage = 0;


        printWithTime("You have healed for 0 HP \n" , 10ms);
        printWithTime("Don't be a wimp and fight the boss like a man \n"  , 10ms);

    }
    return damage;
}

void fightSecondBoss(int playerHealth,string &entity2, string &entity3) {
    int secondBossHealth = 300;
    // string entity2;




    printWithTime("A new, more formidable challenger appears! \n", 10ms);
    cout << "         ,                                      ," << endl;
    cout << "        |\\                                      /|" << endl;
    cout << "     ,   \\'._ ,                           ,  _.'/   ," << endl;
    cout << "     |\\  {'. '-`\\,     ,-._**_.-,       ,/`-' .'}  /|" << endl;
    cout << "      \\`'-'-.  '.`\\    \\*____*/        /`.'  .-'-'`/" << endl;
    cout << "    ,'-'-._  '.  ) )     /`    `\\     ( (  .'  _.-'-'," << endl;
    cout << "    |\\'- _ '.   , /     /  /\"\"\\  \\     \\ ,  .'  _ -'/|" << endl;
    cout << "     \\'-   .  ; (      \\_|^  ^|_/      ) ;   .  .-'/" << endl;
    cout << "      `'--, . ;  {`-.      \\__/      .-'}  ; . ,--'`" << endl;
    cout << "      '--`_. ;  { ^  \\    _|  |_    /  ^ }  ; ._`--'" << endl;
    cout << "      `,_.--  ;  { ^  `-'`      `'-`  ^ }  ;  --._,`" << endl;
    cout << "        ,_.-    ; {^    /        \\    ^} ;    -._, " << endl;
    cout << "         ,_.-`), /\\{^,/\\_\\'__/\\_'_/\\,^}/\\ ,(`-._," << endl;
    cout << "           _.'.-` /.'   \\        /   `.` `-.'._" << endl;
    cout << "          `  _.' `       \\      /       ` '._   `" << endl;
    cout << "                        .-'.  .'-." << endl;
    cout << "                      .'    `` ^  '." << endl;
    cout << "                     /  ^ ^   ^  ^  \\" << endl;
    cout << "                     | ^    ^   ^   |" << endl;
    cout << "                    /^   ^/    \\  ^  \\" << endl;
    cout << "                    \\,_^_/    ^ \\_,^./" << endl;
    cout << "                     /=/  \\^   /  \\=\\" << endl;
    cout << "                 __ /=/_   | ^|   _\\=\\ __" << endl;
    cout << "               <(=,'=(==,) |  | (,==)=',=)>" << endl;
    cout << "                 /_/|_\\    /  \\    /_|_\\\\" << endl;
    cout << "                 `V (=|  .'    '.  |=) V`" << endl;
    cout << "                     V  / _/  \\_ \\  V" << endl;
    cout << "                       `\"` \\  / `\"`" << endl;
    printWithTime("Enter the name for this second boss:  \n", 10ms);

    cin >> entity2;
    printWithTime("From the shadows " + entity2 + " appears! From the darkness!!\n", 10ms);

    while (playerHealth > 0 && secondBossHealth > 0) {
        int playerDamage = chooseWeapon(1);

        if (playerDamage > 0) {
            cout << "You attack the new boss with your weapon and deal " << playerDamage << " damage!" << endl;
            secondBossHealth -= playerDamage;
        }
        if (secondBossHealth <= 0) {



            printWithTime( "Incredible! You defeated the second boss and emerged victorious. \n", 10ms);

            playerHealth += 100;// Add 100 hp after defeating the frist boss
            if (playerHealth > 200) playerHealth = 200; // Health does not exceed 200
            fightthirdBoss(playerHealth,entity3); // Start the second boss fight
            return;
        }


        //int secondBossDamage = 25;
        int bossDamage1 = random1(bossDamage[0], bossDamage[1]);
        cout << "The new boss attacks you and deals " << bossDamage1 << " damage!" << endl;
        playerHealth -= bossDamage1;

        if (playerHealth <= 0) {


            printWithTime("You have been overwhelmed by the second boss. Game over! \n" , 10ms);
            printWithTime("The end." , 10ms);

            return;
        }

        cout << "Player HP: " << playerHealth << " | Second Boss HP: " << secondBossHealth << endl;
    }
}

void fightBoss(string &entity, string &entity2, string &entity3) {
    int playerHealth = 100;
    int bossHealth = 200;

    printWithTime("The battle begins!\n", 10ms);

    while (playerHealth > 0 && bossHealth > 0) {
        int playerDamage = chooseWeapon(1);

        if (playerDamage > 0) {
            cout << "You attack the " << entity << " with your weapon and deal " << playerDamage << " damage!" << endl;
            bossHealth -= playerDamage;
        }

        if (bossHealth <= 0) {
            printWithTime("Congratulations! You defeated the " + entity + ".\n" , 10ms);
            playerHealth += 100;// Add 100 hp after defeating the first boss
            if (playerHealth > 200) playerHealth = 200; // Health does not exceed 200
            fightSecondBoss(playerHealth, entity2, entity3); // Start the second boss fight
            return;
        }

        //int bossDamage = 15;
        int bossDamage1 = random1(bossDamage[0], bossDamage[1]);
        printWithTime("The" + entity + "attacks you and deals\n" , 10ms);
        playerHealth -= bossDamage1;

        if (playerHealth <= 0) {



            printWithTime("You have been defeated by the enemy. Better luck next time! \n", 10ms);
            printWithTime("The end.", 10ms);

            return;
        }

        cout << "Player HP: " << playerHealth << " | Boss HP: " << bossHealth << endl;
    }
}

void fightthirdBoss(int playerHealth,string &entity3) {
    int thirdBossHealth = 400;



    printWithTime("A new, more formidable challenger appears! \n", 10ms);
    cout << "             *********" << endl;
    cout << "           *************" << endl;
    cout << "          *****     *****" << endl;
    cout << "         ***           ***" << endl;
    cout << "        ***             ***" << endl;
    cout << "        **    0     0    **" << endl;
    cout << "        **               **                  ____" << endl;
    cout << "        ***             ***             //////////" << endl;
    cout << "        ****           ****        ///////////////" << endl;
    cout << "        *****         *****    ///////////////////" << endl;
    cout << "        ******       ******/////////         |  |" << endl;
    cout << "      *********     ****//////               |  |" << endl;
    cout << "   *************   **/////*****              |  |" << endl;
    cout << "  *************** **///***********          *|  |*" << endl;
    cout << " ************************************    ****| <=>*" << endl;
    cout << "*********************************************|<===>*" << endl;
    cout << "*********************************************| <==>*" << endl;
    cout << "***************************** ***************| <=>*" << endl;
    cout << "******************************* *************|  |*" << endl;
    cout << "********************************** **********|  |*" << endl;
    cout << "*********************************** *********|  |*" << endl;
    printWithTime("His name is: ", 10ms);


    cin >> entity3;

    while (playerHealth > 0 && thirdBossHealth > 0) {
        int playerDamage = chooseWeapon(1);

        if (playerDamage > 0) {
            cout << "You attack " << entity3 << " with your weapon and deal " << playerDamage << " damage!" << endl;
            thirdBossHealth -= playerDamage;
        }

        if (thirdBossHealth <= 0) {



            printWithTime("Incredible! You defeated " + entity3 + " and emerged victorious. True legend! \n", 10ms);
            printWithTime("The end.", 10ms);

            return;
        }


        int bossDamage1 = random1(bossDamage[0], bossDamage[1]);
        cout << entity3 <<" attacks you and deals " << bossDamage1 << " damage!" << endl;
        playerHealth -= bossDamage1;

        if (playerHealth <= 0) {
            printWithTime("You have been overwhelmed by " + entity3 + ". Game over!\n", 10ms);
            printWithTime("The end.\n", 10ms);
            return;
        }

        cout << "Player HP: " << playerHealth << " | third Boss HP: " << thirdBossHealth << endl;
    }
}
