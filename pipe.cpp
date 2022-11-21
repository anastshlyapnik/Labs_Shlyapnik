#include "pipe.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "checking.h"

string StatusChecking(bool x)
{
    if (x == true)
        return ("Pipe is working");
    else if (x == false)
        return ("Pipe is repairing");
}
int Pipe::MaxPipeId = 0;
istream& operator>> (istream& in, Pipe& p)
{
    cout << "\n Index of pipe: " << p.PipeId;
    cout << "\n Input Name ";

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    getline(cin, p.Name);
    cout << "\nInput length ";
    p.length = NumberChecking(0.0, DBL_MAX);
    cout << "\nInput diameter ";
    p.diameter = NumberChecking(0.0, DBL_MAX);
    cout << "\nChoose status of pipe (0 if repairing, 1 if works) ";
    p.status = NumberChecking(0, 1);
    cout << StatusChecking(p.status) << endl;
    return in;
}
ostream& operator<< (ostream& out, Pipe& p) {
    out << "\nIndex of pipe: " << p.PipeId << "\nPipe info: " << "\nName: " << p.Name << "\nLenght: "
        << p.length << "\nDiameter : " << p.diameter
        << "\nStatus: " << StatusChecking(p.status) << endl;
    return out;
}
void Pipe::EditPipe() {
    cout << "Status: " << StatusChecking(status) << endl;
    cout << "Enter new status of pipe (0 if in repairing, 1 if works)" << endl;
    status = NumberChecking(0, 1);
    cout << StatusChecking(status) << endl;;
}
void Pipe::SavePipeInfo(ofstream& file) {
    file << PipeId << endl << Name << endl << length << endl << diameter << endl << status << endl;
}
void Pipe::LoadPipeInfo(ifstream& file) {
    file >> PipeId;
    getline(file, Name);
    getline(file, Name);
    file >> length;
    file >> diameter;
    file >> status;
}