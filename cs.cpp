#include "CS.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "checking.h"

using namespace std;

int MaxCSId = 0;
istream& operator>> (istream& in, CompressorStation& CS)
{
    cout << "\nIndex of cs: " << CS.CSId;
    cout << "\nInput name ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, CS.Name);
    cout << "\nNumber of workshops ";
    //CS.Workshops = NumberChecking(0, INT_MAX);
    cout << "\nNumber of workshops in operation ";
    //CS.WorkshopsInOperation = NumberChecking(0, CS.Workshops);
    cout << "\nEnter the efficiency ";
    //CS.Efficiency = NumberChecking(0, 100);
    return in;
}
ostream& operator<< (ostream& out, CompressorStation& CS) {
    out << "\nIndex of CS: " << CS.CSId << "\nCS info:\nName: " << CS.Name << "\nNumber of workshops: " << CS.Workshops
        << "\nNumber of workshops in operation: " << CS.WorkshopsInOperation << "\nEfficiency: "
        << CS.Efficiency << "%" << endl;
    return out;
}

void CompressorStation::EditCS() {
    cout << "Workshops: " << Workshops << endl;
    cout << "Working workshop: " << WorkshopsInOperation << endl;
    cout << "Enter new number of working workshops" << endl;
    //WorkshopsInOperation = NumberChecking(0, Workshops);
}
void CompressorStation::SaveCSInfo(ofstream& file) {
    file << CSId << endl << Name << endl
        << Workshops << endl << WorkshopsInOperation << endl << Efficiency << endl;
}
void CompressorStation::LoadCSInfo(ifstream& file) {
    file >> CSId;
    getline(file, Name);
    getline(file, Name);
    file >> Workshops;
    file >> WorkshopsInOperation;
    file >> Efficiency;
}