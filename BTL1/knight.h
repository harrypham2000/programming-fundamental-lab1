#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void getInput(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue, int * events);
bool checkOpenFile(string& file_input);
int battleEngage(int&HP,int&maxHP, int &level,int&phoenixdown,int & rescue ,int &event, int&count);
int battleShaman(int&HP,int&maxHP, int &level,int&phoenixdown,int&remedy,int & rescue ,int &event, int&count,int&countTiny);
int battleSirenVajsh(int&HP,int&maxHP, int &level,int&maidenkiss,int&remedy,int & rescue ,int &event, int&count,int&countFrog);
int mushMario(int&HP, int&maxHP, int&level,int&phoenixdown);
int calcFibo(int n);
int mushFibo(int&HP);
int mushGhost();
int comeToKoopa();

void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);

#endif // __KNIGHT_H__