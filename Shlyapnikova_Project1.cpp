// Shlyapnikova_Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Pipe {
    int Length=0, Diameter =0;
    bool InRepair;
};

struct CompressorStation {
    string Name;
    int Workshops=0, WorkshopsInOperation=0, Efficiency=0;
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

template <typename T> //http://cppstudio.com/post/5188/
void DataInput(T& data) {
    while ((cin>>data).fail()||(data<0)) {
        cout << "Wrong request! Try again!\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void AddPipe(Pipe& pipe) {
    if (pipe.Length==0) { 
        do {
            cout << "Enter the non-zero length of the pipe\n";
            DataInput(pipe.Length);
            cout << "Enter the non-zero diameter of the pipe\n";
            DataInput(pipe.Diameter);
        } while ((pipe.Diameter == 0) || (pipe.Length == 0));
        cout << "Enter the pipe state: '0' if it is not in repair, '1' if it is under repair\n";
        DataInput(pipe.InRepair);
        cout << "Pipe added!\n\n";
    } else cout << "Pipe is already exist!\n";
}

void AddCompStation(CompressorStation& CS) {
    if (CS.Workshops==0) {
        cout << "Enter the name of the station\n";
        getline(cin>>ws,CS.Name);
        do {
            cout << "Enter the non-zero number of the workshops\n";
            DataInput(CS.Workshops);
        } while (CS.Workshops == 0);
        cout << "Enter the number of the workshops in operation\n";
        do {
            cout << "Enter a number from 0 to " << CS.Workshops << "\n";
            DataInput(CS.WorkshopsInOperation);
        } while (CS.Workshops < CS.WorkshopsInOperation);
        cout << "Enter the efficiency of the compressor station\n";
        DataInput(CS.Efficiency);

        cout << "Compressor station added!\n\n";
    } else cout << "Compressor station is already exist!\n";
}

void ViewObjects(const Pipe& pipe, const CompressorStation& CS) {
    if (pipe.Length!=0) {
        cout << "Pipe info:\n" << "- Length: " << pipe.Length << "\n- Diameter: " << pipe.Diameter << "\n- In Repair: ";
        if (pipe.InRepair) {
            cout << "Yes\n";
        } else cout << "No\n";
    } else cout << "Pipe is not added!\n\n";

    if (CS.Workshops!=0) {
        cout << "Compressor station info:\n" << "- Name: " << CS.Name << "\n- Number of workshops: " << CS.Workshops << "\n- Number of workshops in operation: " << CS.WorkshopsInOperation << "\n- Efficiency: " << CS.Efficiency << endl;
    }
    else cout << "Compressor station is not added!\n\n";
}

void EditPipe(Pipe& pipe) {
    if (pipe.Length!=0) {
        cout << "Change the pipe state: '0' if it is not in repair, '1' if it is under repair\n";
        DataInput(pipe.InRepair);
        cout << "Changes successfully saved!\n";
    } else cout << "Pipe is not added!\n\n";
}

void EditCS(CompressorStation& CS) {
    if (CS.Workshops!=0) {
        cout << "Change the number of workshops in operation\n";
        do {
            cout << "Enter a number from 0 to "<<CS.Workshops<<"\n";
            DataInput(CS.WorkshopsInOperation);
        } while (CS.Workshops < CS.WorkshopsInOperation);
        cout << "Changes successfully saved!\n";
    }  else cout << "Compressor station is not added!\n\n";
}

void SaveInfo(const Pipe& pipe, const CompressorStation& CS) {
    ofstream fout;
    fout.open("data.txt");
    if (fout.is_open()) {
        if (pipe.Length!=0) {
            fout << pipe.Length << "\n" << pipe.Diameter << "\n" << pipe.InRepair;
        }
        if (CS.Workshops!=0) {
            fout << CS.Name << "\n" << CS.Workshops << "\n" << CS.WorkshopsInOperation << "\n" << CS.Efficiency << endl;
        }
        cout << "Changes successfully saved!\n";
    }
    else cout << "Data has not been saved! Try again!\n";
    fout.close(); 
}

void DownloadInfo(Pipe& pipe, CompressorStation& CS) {
    ifstream fin;
    fin.open("data.txt");
    if (fin.is_open()){
        fin >> pipe.Length >> pipe.Diameter >> pipe.InRepair;
        getline(fin>>ws, CS.Name);
        fin >> CS.Workshops >> CS.WorkshopsInOperation >> CS.Efficiency;
        cout << "Data successfully uploaded!\n";
        fin.close();
    } else cout << "Data has not been downloaded! Try again!\n";
}

int main() {
    Pipe Pipe;
    CompressorStation CompStat;
    int request;
    do {
        PrintMenu();
        DataInput(request);
        switch (request) {
        case 1:
            AddPipe(Pipe);
            break;
        case 2:
            AddCompStation(CompStat);
            break;
        case 3:
            ViewObjects(Pipe, CompStat);
            break;
        case 4:
            EditPipe(Pipe);
            break;
        case 5:
            EditCS(CompStat);
            break;
        case 6:
            SaveInfo(Pipe, CompStat);
            break;
        case 7:
            DownloadInfo(Pipe, CompStat);
            break;
        case 0:
            cout << "Goodbye!";
            break;
        default:
            cout << "Wrong request! Try again!\n";
            break;
        }
    } while (request != 0);
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
