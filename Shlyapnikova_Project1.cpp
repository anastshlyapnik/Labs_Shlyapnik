// Shlyapnikova_Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>


using namespace std;

struct Pipe {
    int Length, Diameter;
    bool InRepair, IsExist;
};

struct CompressorStation {
    string Name;
    int Workshops, WorkshopsInOperation, Efficiency;
    bool IsExist;
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


int main()
{
    Pipe pipe1{};
    int request1;
    do {
        PrintMenu();
        cin >> request1;
        switch (request1) {
        case 1:
     
           
            break;
        case 2:
           
            break;
        case 3:
           
            break;
        case 4:
           
            break;
        case 5:
           
            break;
        case 6:
          
            break;
        case 7:
            
            break;
        default:
            
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