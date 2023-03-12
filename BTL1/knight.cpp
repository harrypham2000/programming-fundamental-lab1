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
    if(!checkOpenFile(file_input)){
        cerr << "File cannot be openned!";
        return;
    }
    string inputString;
    getline(inputFile,inputString);
    getInput(inputString,HP,level, remedy, maidenkiss, phoenixdown, rescue, events);
    int maxHP=min(HP,172), countTiny,countFrog;
    while(HP>0&&level<=10&&rescue==0){
        for(int i=1; i<=sizeof(events)/sizeof(events[0]);i++){
            int event=events[i], count=1;
            countTiny--;
            countFrog--;
            int getLevel=min(level,10);
            switch (event) {
                case bowserSurrender:
                    rescue=1;
                    break;
                case meetMadBear:
                case meetBandit:
                case meetLordLupin:
                case meetElf:
                case meetTroll:
                    battleEngage(HP,maxHP, level,phoenixdown,rescue, event, count);
                    break;
                case meetShaman:
                    if(countTiny>0||countFrog>0){
                        break;
                    }
                    else if(countTiny==0){
                        HP=min(HP*5,maxHP);
                        battleShaman(HP,maxHP, level,phoenixdown,remedy,rescue ,event, count, countTiny);
                        break;
                    }
                    else{
                    battleShaman(HP,maxHP, level,phoenixdown,remedy,rescue ,event, count, countTiny);
                    break;
                    }
                case meetSirenVajsh:
                    if (countTiny>0||countFrog>0){
                        break;
                    }
                    else if(countFrog==0){
                        level=getLevel;
                        battleSirenVajsh(HP, maxHP, level, maidenkiss,remedy, rescue, event, count, countFrog);
                        break;
                    }
                    else {
                        battleSirenVajsh(HP, maxHP, level, maidenkiss,remedy, rescue, event, count, countFrog);
                        break;
                    }
                case pickMushMario:
                    mushMario(HP, maxHP, level, phoenixdown);
                    break;
                case pickMushFib:
                    break;
                case pickMushGhost:
                    break;
                default:
                    comeToKoopa();
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
int battleEngage(int & HP,int&maxHP, int & level,int&phoenixdown,int & rescue, int & event, int & count){
    int levelO=0;
    float b=count%10;
    levelO=count>6?(b>5?b:5):b;
    if(level>levelO){
        level++;
        level=min(level,10);
        return level;
    }
    else if (level == levelO){
        return level;
    }
    else if (level < levelO){
        int dmg=int(baseDmg[event])*levelO*10;
        HP=HP-dmg;
        if(HP<=0&&phoenixdown<1){
            rescue=-1;
            return HP,rescue;
        }
        else if(HP<=0&&phoenixdown>=1){
            phoenixdown--;
            HP=maxHP;
            return HP, phoenixdown;
        }
    }
}
int battleShaman(int &HP,int&maxHP, int &level,int&phoenixdown,int & remedy,int & rescue ,int &events, int&count, int&countTiny){
    int levelO=0;
    float b=count%10;
    levelO=count>6?(b>5?b:5):b;
    if(level>levelO){
        level+=2;
        level=min(level,10);
        countTiny=0;
        return level,countTiny;
    }
    else if (level == levelO){
        countTiny=0;
        return countTiny,level;
    }
    else if (level < levelO){
        countTiny=3;
        if(HP<5){
            if(remedy>=1){
                remedy--;
                countTiny=0;
                return HP,remedy,countTiny;
            }
            else if(phoenixdown>=1&&HP<=0){
                phoenixdown--;
                countTiny=0;
                HP=maxHP;
                return HP,phoenixdown,countTiny;
            }
            else{
                HP=1;
                return HP;
            }
        }
        else{
            if(remedy>=1){
                remedy--;
                countTiny=0;
                return HP,remedy,countTiny;
            }
            HP=int(HP/5);
            if(phoenixdown>=1&&HP<=0){
                phoenixdown--;
                countTiny=0;
                HP=maxHP;
                return HP, phoenixdown,countTiny;
            }
            return HP;
        }
    }
}
int battleSirenVajsh(int&HP,int&maxHP, int &level,int&maidenkiss,int&remedy,int & rescue ,int &event, int&count,int&countFrog){
    int levelO=0;
    float b=count%10;
    levelO=count>6?(b>5?b:5):b;
    if(level>levelO){
        level++;
        level=min(level,10);
        countFrog=0;
        return level,countFrog;
    }
    else if (level == levelO){
        countFrog=0;
        return level,countFrog;
    }
    else if (level < levelO){
        countFrog=3;
        if(maidenkiss>0){
            maidenkiss--;
            countFrog=0;
            return level, countFrog;
        }
        else if(remedy>0){
            remedy--;
            countFrog=0;
            return remedy,countFrog;
        }
        else{
            level=1;
            return level;
        }
    }
}
int mushMario(int&HP, int&maxHP, int&level, int & phoenixdown){
    int n1=((level+phoenixdown)%5+1)*3,odd,s1=0;
    for(; n1=0; n1--){

    }
}
int comeToKoopa(){

}
