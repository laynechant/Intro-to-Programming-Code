//
// Created by Kirit on 11/9/2023.
//
#pragma once
#include <string>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;
const int weaponDamageLongSword[2] = {50,175};
const int weaponDamageRapier[2] = {75,200};
const int weaponDamageBallOfTwine[2] = {1,50};
const int weaponDamageDynamite[2] = {150,200};
const int bossDamage[2] = {0,75};

void printIntro(string &entity);
void fightBoss(string &entity, string &entity2, string &entity3);
int chooseWeapon(int random);
int random1();
void fightSecondBoss(int playerHealth, string &entity2, string &entity3);
void fightthirdBoss(int playerHealth, string &entity3);
void printWithTime(const string& str, chrono::milliseconds timeToWaitMs);