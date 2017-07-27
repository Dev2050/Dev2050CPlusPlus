#include <string>

using namespace std;

class Players
{
private:
    string _playerName;
    int _playerPoint;

public:
    Players();
    ~Players();
    void setPlayerName(string playerName);
    string getPlayerName();
    void setPlayerPoint(int playerPoint);
    int getPlayerPoint();
    void printResult();
};
