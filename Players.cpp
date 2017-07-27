#include "Players.h"
#include <iostream>
#include <string>

using namespace std;

Players::Players(){
        _playerPoint=0;
}
Players::~Players(){
}
void Players::setPlayerName(string playerName){
    _playerName=playerName;

}
string Players::getPlayerName(){
 return _playerName;
}
void Players::setPlayerPoint(int playerPoint){
    _playerPoint +=playerPoint;
}
int Players::getPlayerPoint(){
 return _playerPoint;
}
void Players::printResult(){
    cout << "\n" << _playerName;
    cout <<  " (" << _playerPoint << ")\n" << endl;
}

