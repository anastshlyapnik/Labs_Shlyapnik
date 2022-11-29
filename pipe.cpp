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
    cout << "\nIndex of the pipe: " << p.PipeId;
    cout << "\nEnter the name: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, p.Name);
    cout << "\nEnter the length: ";
    p.length = NumberChecking(0.0, DBL_MAX);
    cout << "\nEnter the diameter: ";
    p.diameter = NumberChecking(0.0, DBL_MAX);
    cout << "\nSelect the pipe state: 0 - in repair, 1 - is working ";
    p.status = NumberChecking(0, 1);
    cout << "\nPipe added successfully\n";
    //cout << StatusChecking(p.status) << endl;
    return in;
}
ostream& operator<< (ostream& out, Pipe& p) {
    out << "\nIndex of pipe: " << p.PipeId << "\nPipe info: " << "\n- Name: " << p.Name << "\n- Length: "
        << p.length << "\n- Diameter : " << p.diameter
        << "\n- Status: " << StatusChecking(p.status) << endl;
    return out;
}
void Pipe::EditPipe() {
    cout << "Status: " << StatusChecking(status) << endl;
    cout << "Select the new pipe state: 0 - in repair, 1 - is working" << endl;
    status = NumberChecking(0, 1);
    //cout << StatusChecking(status) << endl;
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