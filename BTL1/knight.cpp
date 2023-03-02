#include "knight.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#define BowserSurrendered 0
#define MeetMadBear 1
#define MeetBandit 2
#define MeetLordLupin 3
#define MeetElf 4
#define MeetTroll 5
#define MeetShaman 6
#define MeetSirenVajsh 7
#define PickUpMushMario 11
#define PickUpMushFib 12
#define PickUpMushGhost 13
#define ObtainRemedy 15
#define ObtainMaidenKiss 16
#define ObtainPhoenixDown 17
#define MeetMerlin 18
#define MeetAsclepius 19
#define MeetBowser 99

float baseDmg[]={0.0,1.0,1.5,4.5,7.5,9.5};

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

void getInput(string input_string,int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue, int events[100]){
    stringstream ss(input_string);
    if(ss.peek() == '\n') ss.ignore();
    string line;
    getline(ss,line);
    stringstream line_ss(line);
    line_ss >> HP >> level >> remedy >> maidenkiss >> phoenixdown >> rescue;
    string event_line;
    stringstream event_ss(event_line);
    int event_count=1;
    while(event_ss >> events[event_count]){
        event_count++;
    }
}
void battleEngage(int & HP, int & level, int event) {
        int levelO=0;
        int b=event%10;
        levelO=event>6?(b>5?b:5):b;
        if(level>levelO){
            level=min(10,level++);
        }
        else if(level==levelO){
            level=level;
        }
        else if(level<levelO){
            float dmg=baseDmg[event]*levelO*10.0;
            HP=int(HP-dmg);
        }
    }
}
int witchShaman(int & HP, int & level, int event){
        int levelO=0;
        int b=event%10;
        levelO=event>6?(b>5?b:5):b;
        if(level>levelO){
            level=min(10,level+=2);
            return 1;
        }
        else if(level==levelO){
            level=level;
            return 0;
        }
        else if(level<levelO){
            if(HP<5) HP=1;
            else {
                HP = int(HP / 5);
                return -1;
            }
        }
    }
}
int battleVajsh(int & HP, int & level, int event){
    int levelO=0;
    int b=event%10;
    levelO=event>6?(b>5?b:5):b;
    if(level>levelO){
        level=min(10,level+=2);
        return 1;
    }
    else if(level==levelO){
        level=level;
        return 0;
    }
    else if(level<levelO){
        return -1;
    }
}
}
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    ifstream input_file(file_input);
    if (!input_file.is_open())
    {
        cerr << "Cannot open file!";
        return;
    }
    string input_string;
    int events[100]={0};
    int MaxHP=min(HP,172);
    getline(input_file,input_string);
    getInput(input_string,HP, level,remedy,maidenkiss,phoenixdown,rescue,events);
    for (int i=1;i<(sizeof(events)/sizeof(*events))&&HP>0&&level<=10&&rescue==0;i++) {
        int event=events[i];

//        if (event>=MeetMadBear&&event<=MeetTroll){
//            battleEngage(HP, level, event);
//            if(HP<=0&&phoenixdown==0){
//                rescue=-1;
//                break;
//            }
//            else if(HP>0&&phoenixdown>0){
//                phoenixdown-=1;
//                HP=MaxHP;
//                continue;
//            }
//        }
//        else if(event==MeetShaman){
//            witchShaman(HP,level,event);
//            if (witchShaman(HP,level,event)==-1){
//                if(remedy>0){
//                    HP=MaxHP;
//                    remedy--;
//                }
//                else if(phoenixdown>0&&HP<=0){
//                    HP=MaxHP;
//                    phoenixdown--;
//                }
//                int countTiny=3;
//            }
//        }
//        else if(event==MeetSirenVajsh){
//            battleVajsh(HP,level, event);
//            if(battleVajsh(HP,level,event)==-1{
//                int countFrog=3;
//                if(maidenkiss>0){
//                    countFrog=0;
//                    level=level;
//                    maidenkiss--;
//                }
//                level=1;
//            }
//        }
    }
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);

    cout << "Function isn't implemented" << endl;
}