// Shlyapnikova_Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

struct Pipe {
    int Length, Diameter;
    bool InRepair, IsExist = false;
};

struct CompressorStation {
    string Name;
    int Workshops, WorkshopsInOperation, Efficiency;
    bool IsExist=false;
};

void PrintMenu() {
    cout << "Hello! Enter the number of the required item:" << endl;
    cout << "1. Add a pipe" << endl;
    cout << "2. Add a compressor station" << endl;
    cout << "3. Viewing all objects" << endl;
    cout << "4. Edit a pipe" << endl;
    cout << "5. Edit a compressor station" << endl;
    cout << "6. Save changes" << endl;
    cout << "7. Download" << endl;
    cout << "0. Exit" << endl;

}
template <typename T>
void ResponseChecking(T& input) {
    while ((cin>>input).fail()||input<0) {
        cout << "Wrong request! Try again!\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void AddPipe(Pipe& pipe) {
    
    if (not pipe.IsExist) { 
        cout << "Enter the length of the pipe\n";
        cin >> pipe.Length;
        ResponseChecking(pipe.Length);
        cout << "Enter the diameter of the pipe\n";
        cin >> pipe.Diameter;
        while ((!pipe.Diameter) || (pipe.Diameter < 0)) {
            cout << "Wrong request! Try again!\n";
            pipe.Diameter = 0;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> pipe.Diameter;
        }
        cout << "Enter the pipe state: '0' if it is not in repair, '1' if it is under repair\n";
        while ((cin >> pipe.InRepair).fail()) {
            cout << "Wrong request! Try again!\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        pipe.IsExist = true;
        cout << "Pipe added!\n\n";
    }
    else cout << "Pipe is already exist!\n";
}

void AddCompStation(CompressorStation& CS) {
    if (not CS.IsExist) {
        cout << "Enter the name of the station\n";
        cin.ignore();
        //getline(cin, CS.Name);
        cout << "Enter the number of the workshops\n";
        cin >> CS.Workshops;
        while ((!CS.Workshops) || (CS.Workshops < 0)) {
            cout << "Wrong request! Try again!\n";
            CS.Workshops = 0;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> CS.Workshops;
        }
        cout << "Enter the number of the workshops in operation\n";
        cin >> CS.WorkshopsInOperation;
        while ((!CS.WorkshopsInOperation) || (CS.WorkshopsInOperation < 0) || (CS.WorkshopsInOperation > CS.Workshops)) {
            cout << "Wrong request! Try again!\n";
            CS.WorkshopsInOperation = 0;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> CS.WorkshopsInOperation;
        }
        cout << "Enter the efficiency of the compressor station\n";
        cin >> CS.Efficiency;
        while ((!CS.Efficiency) || (CS.Efficiency < 0)){
            cout << "Wrong request! Try again!\n";
            CS.Efficiency = 0;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> CS.Efficiency;
        } 
        CS.IsExist = true;
        cout << "Compressor station added!\n\n";
    }
    else cout << "Compressor station is already exist!\n";
}

void ViewObjects(Pipe pipe, CompressorStation CS) {
    if (pipe.IsExist) {
        cout << "Pipe info:\n" << "-Length: " << pipe.Length << "\n-Diameter: " << pipe.Diameter << "\n-In Repair: ";
        if (pipe.InRepair) {
            cout << "Yes\n";
        }
        else cout << "No\n";
    }
    else cout << "Pipe is not added!\n\n";

    if (CS.IsExist) {
        cout << "Compressor station info:\n" << "-Name: " << CS.Name << "\n-Number of workshops: " << CS.Workshops << "\n-Number of workshops in operation: " << CS.WorkshopsInOperation << "\n-Efficiency: " << CS.Efficiency << endl;
    }
    else cout << "Compressor station is not added!\n\n";
}

void EditPipe(Pipe pipe) { // не доделано
    if (pipe.IsExist) {
        cout << "Pipe info:\n" << "-Length: " << pipe.Length << "\n-Diameter: " << pipe.Diameter << "\n-In Repair: ";
        if (pipe.InRepair) {
            cout << "Yes\n";
        }
        else cout << "No\n";
    }
    else cout << "Pipe is not added!\n\n";
}

int main()
{
    Pipe Pipe1{};
    CompressorStation CompStat1;
    int request1;
    do {
        PrintMenu();
        cin >> request1;
        switch (request1) {
        case 1:
            AddPipe(Pipe1);
            break;
        case 2:
            AddCompStation(CompStat1);
            break;
        case 3:
            ViewObjects(Pipe1, CompStat1);
            break;
        case 4:
            EditPipe(Pipe1);
            break;
        case 5:
            //EditCS(CompStat1);
            break;
        case 6:
          
            break;
        case 7:
            
            break;
        default:
            cout << "Wrong request! Try again!\n";
            break;
        }

    } while (request1 != 0);
    cout << "Goodbye!";
    //system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
