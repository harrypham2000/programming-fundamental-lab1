#include "knight.h"
#include "fstream"
#include <iostream>
#define bowserSurrender 0
#define meetMadBear 1
#define meetBandit 2
#define meetLordLupin 3
#define meetElf 4
#define meetTroll 5
#define meetShaman 6
#define meetSirenVajsh 7
#define pickMushMario 11
#define pickMushFib 12
#define pickMushGhost 13
#define obtainRemedy 15
#define obtainMaidenKiss 16
#define obtainPhoenixDown 17
#define meetMerlin 18
#define meetAsclepius 19
#define meetBowser 99
int events[50]={0,};
float baseDmg[]={0.0,1.0,1.5,4.5,7.5,9.5};
void getInput(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue, int * events);
bool checkOpenFile(string& file_input);
int battleEngage(int &HP, int &level, int &events, int&count);
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
         << ", level=" << level
         << ", remedy=" << remedy
         << ", maidenkiss=" << maidenkiss
         << ", phoenixdown=" << phoenixdown
         << ", rescue=" << rescue << endl;
}
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    ifstream inputFile(file_input);
    if(checkOpenFile(file_input)==false){
        cerr << "File cannot be openned!";
        return;
    }
    string inputString;
    getline(inputFile,inputString);
    getInput(inputString,HP,level, remedy, maidenkiss, phoenixdown, rescue, events);
    while(HP>0&&level<=10&&rescue==0){
        for(int i=1; i<=sizeof(events)/sizeof(events[0]);i++){
            int event=events[i], count=1;
            switch (event) {
                case bowserSurrender:
                    rescue=1;
                    break;
                case meetMadBear:
                case meetBandit:
                case meetLordLupin:
                case meetElf:
                case meetTroll:
                    battleEngage(HP, level, event, count);
                    break;

            }
        }
    }
    cout << "Function isn't implemented" << endl;
}
void getInput(string input_string, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue, int * events){
    stringstream ss(input_string);
    string line, eventLine;
    int eventCount=1;
    while(getline(ss,line)){
        stringstream lineSS(line);
        lineSS >> HP >> level >> remedy >> maidenkiss >> phoenixdown >> rescue;
        stringstream eventSS(eventLine);
        while(eventSS.peek()!=EOF){
            eventSS >> events[eventCount];
            eventCount++;
        }
    }
}
bool checkOpenFile(string& file_input){
    ifstream inputFile(file_input);
    if(!inputFile){
        return false;
    }
    return true;
}
int battleEngage(int & HP, int & level, int & event, int & count){
    int levelO=0;
    float b=count%10;
    levelO=count>6?(b>5?b:5):b;
    if(level>levelO){
        level++;
        level=max(level,10);
        return HP, level;
    }
    else if (level == levelO){
        return HP,level;
    }
    else if (level < levelO){
        int dmg=int(baseDmg[event])*levelO*10;
        HP=HP-dmg;
        return HP,level;
    }

}