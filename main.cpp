#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>
#include "Players.h"

using namespace std;

std::string to_string(int i)
{
    std::stringstream _strs;
    _strs << i;
    return _strs.str();
}

//class for checking winning status
class WinnerPointReached{
public:
    void setWinnerPointReached(bool winnerPointReached){
    _winnerPointReached=winnerPointReached;
}
bool getWinnerPointReached(){
    return _winnerPointReached;
}
private:
    bool _winnerPointReached;
};

int main()
{
    //Creating vector of Players object
    vector<Players> playersList;
    vector<Players>::iterator itr;
    itr=playersList.begin();
    string playerName;
    string unknown="UNANIMOUS_";
    int playerPoint;
    Players *player;
    WinnerPointReached winnerPointReached;
    winnerPointReached.setWinnerPointReached(false);

    //Local variables
    int biggestDieThrowNum=0;
    int dieThrowOccuranceNumber=0;
    int countPoints=0;

    //TheDieThrowRandomOccurance struct
    struct TheDieThrowRandomOccurance{
        static int throwDieThenMove(int dieThrowOccuranceNumber){
                    dieThrowOccuranceNumber=(rand()%6)+1;
                    cout <<"Dice throw resulted in: " <<dieThrowOccuranceNumber<< endl;
                    cout <<"You have moved "<<dieThrowOccuranceNumber<<" steps forwards around the circle.\n"<< endl;
                return dieThrowOccuranceNumber;
        }
        static void notifyTheDieThrowResult(int dieThrowOccuranceNumber){
                    cout <<"Dice throw resulted in " <<dieThrowOccuranceNumber<< endl;
                    cout <<"You have moved "<<dieThrowOccuranceNumber<<" steps forwards around the circle.\n"<< endl;
        }
    };

    cout << "HELLO! WELCOME TO THIS CONSOLE KIMBLE GAME APPLICATION!\n";
    cout << "PLEASE ENTER PLAYERS!\n";
    cout << "If you like to play the game, press the ENTER key.";

    if (cin.get() == '\n'){
        for(int i=0; i<4; i++){
            itr=playersList.begin();
            srand(time(0));
            cout << "\nEnter KimbleGame's player name: ";
            getline(cin, playerName);
            cout << "To identify who starts first, press the ENTER key to throw die.";
            if (cin.get() == '\n'){
                dieThrowOccuranceNumber=(rand()%6)+1;
                playerPoint=dieThrowOccuranceNumber;
                cout <<"Your die throw resulted in " <<dieThrowOccuranceNumber<< "\n" << endl;
                player = new Players();
                if(playerName.empty() && dieThrowOccuranceNumber>biggestDieThrowNum ){
                    biggestDieThrowNum=dieThrowOccuranceNumber;
                    player->setPlayerName(unknown.append(to_string(i+7)));
                    player->setPlayerPoint(playerPoint);
                    playersList.insert(itr, *player);
                    }
                else if(playerName.empty() && dieThrowOccuranceNumber <= biggestDieThrowNum ){
                    player->setPlayerName(unknown.append(to_string(i+47)));
                    player->setPlayerPoint(playerPoint);
                    playersList.push_back(*player);
                    }
                else if(!playerName.empty() && dieThrowOccuranceNumber <= biggestDieThrowNum ){
                    player->setPlayerName(playerName);
                    player->setPlayerPoint(playerPoint);
                    playersList.push_back(*player);
                    }
                else if(!playerName.empty() && dieThrowOccuranceNumber > biggestDieThrowNum ){
                    biggestDieThrowNum=dieThrowOccuranceNumber;
                    player->setPlayerName(playerName);
                    player->setPlayerPoint(playerPoint);
                    playersList.insert(itr, *player);
                    }
                else{
                    player->setPlayerName(playerName);
                    player->setPlayerPoint(playerPoint);
                    playersList.push_back(*player);
                }

            }
            else{
            cout << "\nYou were supposed to press the ENTER key.\n";
            }
        }
    }
    cout << "\nThese are the Kimble players participating and their die throw results side by side:\n";

    //setting up an iterator loop through the vector
    for(itr=playersList.begin(); itr!=playersList.end(); ++itr){
            //for each player print out their name and point
            itr->printResult();
            itr->setPlayerPoint(0);
    }


    cout<<"\nAs you can see player " << playersList.front().getPlayerName() << " have the biggest die throw number of " <<biggestDieThrowNum<< " and is the first to obtain the biggest number and hence,this player starts the game.\n";

    while(winnerPointReached.getWinnerPointReached()!=true){
        srand(time(0));
        cout <<"\n"<<playersList.front().getPlayerName()<<" it is your turn, press the ENTER key to throw dice.";
        if (cin.get() == '\n'){
            for (int j=0;j<1;j++){
                dieThrowOccuranceNumber=(rand()%6)+1;
                TheDieThrowRandomOccurance::notifyTheDieThrowResult(dieThrowOccuranceNumber);
                countPoints += dieThrowOccuranceNumber;
                playersList.front().setPlayerPoint(countPoints);
                countPoints=0;

                if(dieThrowOccuranceNumber==6){
                    cout <<playersList.front().getPlayerName()<<" it is your turn again, press the ENTER key to throw dice.";

                    if(cin.get()=='\n'){
                        dieThrowOccuranceNumber=(rand()%6)+1;
                        dieThrowOccuranceNumber=TheDieThrowRandomOccurance::throwDieThenMove(dieThrowOccuranceNumber);
                        countPoints += dieThrowOccuranceNumber;
                        playersList.front().setPlayerPoint(countPoints);
                        countPoints=0;
                    }
                }else{
                cout <<playersList.at(1).getPlayerName()<<" it is your turn, press the ENTER key to throw dice.";
                    if (cin.get()=='\n'){
                        for (int j=0;j<1;j++){
                            dieThrowOccuranceNumber=(rand()%6)+1;
                            TheDieThrowRandomOccurance::notifyTheDieThrowResult(dieThrowOccuranceNumber);
                            countPoints += dieThrowOccuranceNumber;
                            playersList.at(1).setPlayerPoint(countPoints);
                            countPoints=0;
                            if(dieThrowOccuranceNumber==6){
                            cout <<playersList.at(1).getPlayerName()<<" it is your turn again, press the ENTER key to throw dice.";

                                if(cin.get()=='\n'){
                                    dieThrowOccuranceNumber=(rand()%6)+1;
                                    dieThrowOccuranceNumber=TheDieThrowRandomOccurance::throwDieThenMove(dieThrowOccuranceNumber);
                                    countPoints += dieThrowOccuranceNumber;
                                    playersList.at(1).setPlayerPoint(countPoints);
                                    countPoints=0;
                                }
                            }else{
                            cout <<playersList.at(2).getPlayerName()<<" it is your turn, press the ENTER key to throw dice.";
                                    if (cin.get()=='\n'){
                                        for (int k=0;k<1;k++){
                                            dieThrowOccuranceNumber=(rand()%6)+1;
                                            TheDieThrowRandomOccurance::notifyTheDieThrowResult(dieThrowOccuranceNumber);
                                            countPoints += dieThrowOccuranceNumber;
                                            playersList.at(2).setPlayerPoint(countPoints);
                                            countPoints=0;
                                            if(dieThrowOccuranceNumber==6){
                                            cout <<playersList.at(2).getPlayerName()<<" it is your turn again, press the ENTER key to throw dice.";

                                                if(cin.get()=='\n'){
                                                    dieThrowOccuranceNumber=(rand()%6)+1;
                                                    dieThrowOccuranceNumber=TheDieThrowRandomOccurance::throwDieThenMove(dieThrowOccuranceNumber);
                                                    countPoints += dieThrowOccuranceNumber;
                                                    playersList.at(2).setPlayerPoint(countPoints);
                                                    countPoints=0;
                                                }
                                            }else{
                                            cout <<playersList.at(3).getPlayerName()<<" it is your turn, press the ENTER key to throw dice.";
                                                if (cin.get()=='\n'){
                                                    for (int z=0;z<1;z++){
                                                        dieThrowOccuranceNumber=(rand()%6)+1;
                                                        TheDieThrowRandomOccurance::notifyTheDieThrowResult(dieThrowOccuranceNumber);
                                                        countPoints += dieThrowOccuranceNumber;
                                                        playersList.at(3).setPlayerPoint(countPoints);
                                                        countPoints=0;
                                                        if(dieThrowOccuranceNumber==6){
                                                        cout <<playersList.at(3).getPlayerName()<<" it is your turn again, press the ENTER key to throw dice.";

                                                            if(cin.get()=='\n'){
                                                                dieThrowOccuranceNumber=(rand()%6)+1;
                                                                dieThrowOccuranceNumber=TheDieThrowRandomOccurance::throwDieThenMove(dieThrowOccuranceNumber);
                                                                countPoints += dieThrowOccuranceNumber;
                                                                playersList.at(3).setPlayerPoint(countPoints);
                                                                countPoints=0;
                                                            }
                                                        }
                                                    }
                                                }

                                            }
                                        }
                                    }

                            }
                        }
                    }

                }
            }
        }
        else{
            cout << "\nYou were supposed to press the ENTER key.\n";
        }

        //Notify the game winner
        for(itr=playersList.begin(); itr!=playersList.end(); ++itr){
            if(itr->getPlayerPoint()>=40){
                bool winnerFound=winnerPointReached.getWinnerPointReached();
                if(winnerFound==false){
                winnerPointReached.setWinnerPointReached(true);
                cout <<itr->getPlayerName()<< " you win the race!\n";
                cout << "Total points " <<itr->getPlayerPoint()<< " and this signifies that all of your four pieces have made one complete round! \nCongrats!\n";
                    for(int i=0; i<1; i++){
                        cout  << "\n" <<    " ("<<"7"<<")"<<"("<<"7"<<")"<<"("<<"7"<<")";
                        cout << "\n" <<     " (" << "7" << ")\n";
                        cout  <<     " (" << "7" << ")\n";
                        cout <<      " (" << "7" << ")\n";
                        cout  <<     " ("<<"7"<<")"<<"("<<"7"<<")"<<"("<<"7"<<")\n";

                    }
                }
            }
            cout << "\nGame Status! Remember the first to score 40 or above 40 and to complete the race is winner and that is regardless of total points!\n";
            itr->printResult();
        }

    }
    return 0;
}
