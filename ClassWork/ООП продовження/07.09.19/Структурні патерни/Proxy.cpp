#include <iostream>
#include <string>
#include <list>
#include <stdexcept>
#include <ctime>

using namespace std;

class RobotBombDefuser
{
    int _robotConfiguredWavelength = 41;
    bool _isConnected = false;
public:

    void ConnectWireless(int communicationWaveLength)
    {
        if (communicationWaveLength == _robotConfiguredWavelength)
        {
            _isConnected = IsConnectedImmitatingConnectivitiyIssues();
        }
    }

    bool IsConnected()
    {
        _isConnected = IsConnectedImmitatingConnectivitiyIssues();
        return _isConnected;
    }

private:

    bool IsConnectedImmitatingConnectivitiyIssues()
    {
        return rand() % 10 < 9;
    }

public:

    virtual void WalkStraightForward(int steps)
    {
        cout << "Did " << steps << " steps forward..." << endl;
    }

    virtual void TurnRight()
    {
        cout << "Turned right..." << endl;
    }

    virtual void TurnLeft()
    {
        cout << "Turned left..." << endl;
    }

    virtual void DefuseBomb()
    { cout << "Cut red or green or blue wire..." << endl; }
};

class RobotBombDefuserProxy : RobotBombDefuser
{

    RobotBombDefuser *_robotBombDefuser;

    int _communicationWaveLength;

    int _connectionAttempts = 3;


public:
    RobotBombDefuserProxy(int communicationWaveLength)
    {
        _robotBombDefuser = new RobotBombDefuser();
        _communicationWaveLength = communicationWaveLength;
    }

    void WalkStraightForward(int steps) override
    {
        EnsureConnectedWithRobot();
        _robotBombDefuser->WalkStraightForward(steps);
    }

    void TurnRight() override
    {
        EnsureConnectedWithRobot();
        _robotBombDefuser->TurnRight();
    }

    void TurnLeft() override
    {
        EnsureConnectedWithRobot();
        _robotBombDefuser->TurnLeft();
    }

    void DefuseBomb() override
    {
        EnsureConnectedWithRobot();
        _robotBombDefuser->DefuseBomb();
    }

    ~RobotBombDefuserProxy()
    {
        if (_robotBombDefuser)
            delete _robotBombDefuser;
    }

private:

    void EnsureConnectedWithRobot()
    {
        if (_robotBombDefuser == nullptr)
        {
            _robotBombDefuser = new RobotBombDefuser();
            _robotBombDefuser->ConnectWireless(_communicationWaveLength);
        }
        for (int i = 0; i < _connectionAttempts; i++)
        {
            if (_robotBombDefuser->IsConnected() != true)
            { _robotBombDefuser->ConnectWireless(_communicationWaveLength); }
            else
            { break; }
        }
        if (_robotBombDefuser->IsConnected() != true)
        {
            throw exception();
        }
    }
};

 void PlanB(int nextOperationNum)
{
    RobotBombDefuser humanOperatingRobotDirectly;
    if (nextOperationNum == 0)
    {
        humanOperatingRobotDirectly.WalkStraightForward(100);
        nextOperationNum++;
    }
    if (nextOperationNum == 1)
    {
        humanOperatingRobotDirectly.TurnRight();
        nextOperationNum++;
    }
    if (nextOperationNum == 2)
    {
        humanOperatingRobotDirectly.WalkStraightForward(5);
        nextOperationNum++;
    }
    if (nextOperationNum == 3)
    { humanOperatingRobotDirectly.DefuseBomb(); }
}

int main()
{
    srand(time(0));
    int opNum = 0;
    try
    {
        RobotBombDefuserProxy proxy(41);
        proxy.WalkStraightForward(100);
        opNum++;
        proxy.TurnRight();
        opNum++;
        proxy.WalkStraightForward(5);
        opNum++;
        proxy.DefuseBomb();
        opNum++;
        cout << endl;
    } catch (exception e)
    {

        cout << "Exception has been caught. Decided to have human operate robot there." << endl;
        PlanB(opNum);
    }
	system("pause");
}