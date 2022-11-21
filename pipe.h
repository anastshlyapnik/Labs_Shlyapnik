#pragma once
using namespace std;

#include <iostream>
#include <string>
#include <vector>

class Pipe
{
public:
    static int MaxPipeId;
    string Name = "";
    bool status = 0;
    Pipe()
    {
        PipeId = MaxPipeId++;
    }
    friend istream& operator >> (istream& in, Pipe& p);
    friend ostream& operator << (ostream& out, Pipe& p);
    void EditPipe();
    void SavePipeInfo(ofstream& file);
    void LoadPipeInfo(ifstream& file);
    int GetPipeId() { return PipeId; };

private:
    double length = 0, diameter = 0;
    int PipeId = 0;

};
};

