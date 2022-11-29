// Shlyapnikova_Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <string>
#include "cs.h"
#include "pipe.h"
#include "checking.h"
using namespace std;

unordered_map<int, Pipe> PipeGroup;
unordered_map<int, CompressorStation> CSGroup;
unordered_set<int> PipeIds;
unordered_set<int> CSIds;

void Info(unordered_map<int, Pipe>& PipeGroup, unordered_map<int, CompressorStation>& CSGroup) {
    for (auto& pipe : PipeGroup) {
        cout << pipe.second << endl;
    }
    for (auto& cs : CSGroup) {
        cout << cs.second << endl;
    }
}

bool CheckingPipeName(Pipe& p, string name) {
    return (p.Name.find(name) != string::npos);
}
bool CheckingPipeStatus(Pipe& p, bool status) {
    return (p.status == status);
}
bool CheckingCSName(CompressorStation& cs, string Name) {
    return (cs.Name.find(Name) != string::npos);
}
bool CheckingWork(CompressorStation& cs, double p) {
    return (cs.GetUsing() >= p);
}

vector<int> SearchPipe(unordered_map <int, Pipe>& PipeGroup) {
    vector<int> ids;
    int x;
    cout << "Search pipe by \n 1. Name \n 2. Status" << endl;
    x = NumberChecking(1, 2);
    if (x == 1) {
        string name;
        cout << "Enter the name of pipe: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        ids = SearchPipebyParameter(PipeGroup, CheckingPipeName, name);
    }
    else {
        bool k;
        cout << "Enter status of pipe: 0 - in repair, 1 - is working): " << endl;
        k = NumberChecking(0, 1);
        ids = SearchPipebyParameter(PipeGroup, CheckingPipeStatus, k);
    }
    return ids;
}
vector<int> SearchCS(unordered_map <int, CompressorStation>& CSGroup) {
    int x;
    vector <int> id;
    cout << "Search CS by\n1. Name \n2. Percentage of unused workshops" << endl;
    x = NumberChecking(1, 2);
    if (x == 1) {
        string name;
        cout << "Enter the name of CS: " << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        getline(cin, name);
        id = SearchCSbyParameter(CSGroup, CheckingCSName, name);

    }
    else {
        double k;
        cout << "Enter the percentage of unused workshops" << endl;
        k = NumberChecking(0, 100);
        id = SearchCSbyParameter(CSGroup, CheckingWork, k);
    }
    return id;
}

void Edit(unordered_map<int, Pipe>& PipeGroup)
{
    if (PipeGroup.size() != 0) {
        cout << "1. Choose one pipe \n2. Choose pipes \n3. Delete the pipe" << endl;;
        int edit = NumberChecking(1, 3);
        if (edit == 1) {
            cout << "1. Choose pipe to edit" << endl;
            cout << PipeGroup;
            int id = NumberChecking(0, (int)PipeGroup.size());
            if (PipeGroup.find(id) != PipeGroup.end()) {
                PipeGroup[id].EditPipe();
                cout << "Pipe was edited" << endl;
            }
            else
                cout << "There is no such pipe";
        }
        if (edit == 2) {
            cout << "Choose pipes by \n1. Filter \n2. Id" << endl;
            int x = NumberChecking(1, 2);
            if (x == 1) {
                auto idp = SearchPipe(PipeGroup);
                if (idp.size() != 0) {
                    cout << "Enter the new status: 0 - in repair, 1 - is working)" << endl;
                    bool s;
                    s = NumberChecking(0, 1);
                    for (auto& i : idp)
                        PipeGroup[i].status = s;
                }
                else {
                    cout << "There is no such pipe";

                }
            }


            if (x == 2) {
                unordered_set <int> ids;
                cout << PipeGroup;
                cout << "Enter the number of pipe IDs you want to edit" << endl;
                int n;
                int id;
                n = NumberChecking(1, (int)PipeGroup.size());
                cout << "Enter the IDs of pipes" << endl;
                for (int i = 0; ids.size() < n; i++) {
                    id = NumberChecking(0, Pipe::MaxPipeId - 1);
                    if (PipeGroup.find(id) != PipeGroup.end()) {
                        if (PipeGroup.find(id) != PipeGroup.end())
                            ids.insert(id);
                    }
                    else
                    {
                        cout << "There is no such pipe" << endl;;
                    }
                }
                cout << "Enter the new status: 0 - in repair, 1 - is working" << endl;
                bool s;
                s = NumberChecking(0, 1);
                for (auto& i : ids) {
                    for (auto& i : ids)
                        PipeGroup[i].status = s;
                }
            }
        }
        if (edit == 3) {
            cout << "1. ID of one pipe you want to delete \n2. Delete some pipes" << endl;
            int d;
            d = NumberChecking(1, 2);
            if (d == 1) {
                cout << PipeGroup;
                cout << "Enter id of pipe you want to delete" << endl;
                int n;
                n = NumberChecking(0, Pipe::MaxPipeId - 1);
                while (PipeGroup.find(n) == PipeGroup.end()) {
                    cout << "There is no such pipe" << endl;
                    n = NumberChecking(0, Pipe::MaxPipeId - 1);
                }
                PipeGroup.erase(PipeGroup.find(n));
            }

            else {
                unordered_set <int> ids;
                cout << "1. Delete by filter \n2. Delete by id" << endl;
                int action = NumberChecking(1, 2);
                if (action == 2) {
                    cout << PipeGroup;
                    cout << "Enter the number of pipes you want to edit" << endl;;
                    int n = NumberChecking(1, (int)PipeGroup.size());
                    cout << "Enter IDs of pipes" << endl;

                    while (ids.size() < n)
                    {
                        int x = NumberChecking(0, Pipe::MaxPipeId - 1);
                        if (PipeGroup.find(x) != PipeGroup.end())
                            ids.insert(x);
                        else
                            cout << "There is no such pipe" << endl;
                    }

                    for (auto& id : ids) {
                        PipeGroup.erase(PipeGroup.find(id));
                    }

                }

                else {
                    auto idp = SearchPipe(PipeGroup);
                    if (idp.size() != 0) {
                        for (auto& i : idp) {
                            PipeGroup.erase(PipeGroup.find(i));
                        }
                        cout << "Pipe was deleted";
                    }
                    else {
                        cout << "There is no such pipe";

                    }

                }
            }

        }
    }



    else
        cout << "There is no pipe to edit" << endl;
}

void EditCS(unordered_map<int, CompressorStation>& CSGroup) {
    vector <int> idcs;
    if (CSGroup.size() != 0) {
        cout << "1. Edit 1 CS \n2. Edit CSs \n3. Delete CS" << endl;
        int edit;
        int x;
        edit = NumberChecking(1, 3);
        if (edit == 1) {
            int id;
            cout << CSGroup;
            cout << "Choose CS to edit" << endl;
            id = NumberChecking(0, (int)CSGroup.size());
            if (CSGroup.find(id) != CSGroup.end()) {
                CSGroup[id].EditCS();
                cout << "CS was edited!";
            }
        }
        if (edit == 2) {
            unordered_set <int> idw;
            cout << "Choose by \n1. Filter 2. ID" << endl;
            int n;
            n = NumberChecking(1, 2);
            if (n == 2) {
                cout << CSGroup;
                cout << "Enter the number of CS you want to edit" << endl;
                int y;
                y = NumberChecking(1, (int)CSGroup.size());
                cout << "Enter IDs of CSs" << endl;
                for (int i = 0; idw.size() < y; i++) {
                    cin >> x;
                    if (CSGroup.find(x) != CSGroup.end())
                        idw.insert(x);
                    else {

                        cout << "There is no such cs" << endl;
                    }
                }
                for (auto& id : idw)

                    CSGroup[id].EditCS();
            }

            else {
                auto idp = SearchCS(CSGroup);
                if (idp.size() != 0) {
                    for (auto& i : idp)
                        CSGroup[i].EditCS();
                }

                else {
                    cout << "There is no such CS";

                }

            }
        }
        if (edit == 3) {
            cout << "1. ID of one CS you want to delete \n2. Delete some CS" << endl;
            int d;
            d = NumberChecking(1, 2);
            if (d == 1) {
                cout << CSGroup;
                cout << "Enter ID of CS you want to delete" << endl;
                int n;
                n = NumberChecking(0, CompressorStation::MaxCSId - 1);
                while (CSGroup.find(n) == CSGroup.end()) {
                    cout << "There is no such CS" << endl;
                    n = NumberChecking(0, CompressorStation::MaxCSId - 1);
                }
                CSGroup.erase(CSGroup.find(n));

            }
            else {
                unordered_set <int> idd;
                cout << "1. Delete by filter 2. Delete by ID" << endl;
                int n;
                n = NumberChecking(1, 2);
                if (n == 2) {
                    cout << CSGroup;
                    cout << "Enter the number of CS you want to edit" << endl;
                    int y;
                    int x;
                    y = NumberChecking(1, (int)CSGroup.size());
                    cout << "Enter IDs of CSs" << endl;
                    for (int i = 0; i < y; i++) {
                        x = NumberChecking(0, CompressorStation::MaxCSId);
                        if (CSGroup.find(x) != CSGroup.end())
                            idd.insert(x);
                        else
                        {
                            i = i - 1;
                            cout << "There is no such CS" << endl;
                        }
                    }
                    for (auto& i : idd) {
                        CSGroup.erase(CSGroup.find(i));
                    }
                }
                else {
                    auto idp = SearchCS(CSGroup);
                    if (idp.size() != 0) {
                        for (auto& i : idp) {
                            CSGroup.erase(CSGroup.find(i));
                        }
                    }
                    else {
                        cout << "There is no such CS" << endl;


                    }
                }

            }
        }
    }
    else
        cout << "There is no CS to edit" << endl;
}


int main() {
    unordered_map<int, Pipe> pipe_group;
    unordered_map<int, CompressorStation> cs_group;
    int request;

    do {
        cout << "Hello! Enter the number of the required item:" << endl
            << "1. Add a pipe" << endl
            << "2. Add a compressor station" << endl
            << "3. Viewing all objects" << endl
            << "4. Edit a pipe" << endl
            << "5. Edit a compressor station" << endl
            << "6. Save changes" << endl
            << "7. Download" << endl
            << "8. Search the pipe" << endl
            << "9. Search CS" << endl
            << "0. Exit" << endl;
        request = NumberChecking(0, 9);
        switch (request) {
        case 1: {
            Pipe p;
            cin >> p;
            pipe_group.insert({ p.GetPipeId(), p });
            break;
        }
        case 2: {
            CompressorStation cs;
            cin >> cs;
            cs_group.insert({ cs.GetCSId(), cs });
            break;
        }
        case 3: {
            Info(pipe_group, cs_group);
            break;
        }
        case 4: {
            Edit(pipe_group);
            break;
        }
        case 5: {
            EditCS(cs_group);
            break;
        }
        case 6: {
            string x;
            cout << "Enter the name of file " << endl;
            cin >> x;
            ofstream file;
            file.open(x + ".txt");
            if (!file)
                cout << "File error!" << endl;
            else {
                file << pipe_group.size() << " " << cs_group.size() << endl;
                for (auto pipe : pipe_group)
                    pipe.second.SavePipeInfo(file);
                for (auto cs : cs_group)
                    cs.second.SaveCSInfo(file);
            }
            break;
        }
        case 7: {
            string x;
            int len1, len2;
            Pipe newP;
            CompressorStation newCS;
            cout << "Enter the name of file  " << endl;
            cin >> x;
            ifstream file;
            file.open(x + ".txt");
            if (!file)
                cout << "There is no file";
            else {
                Pipe::MaxPipeId = 0;
                CompressorStation::MaxCSId = 0;
                pipe_group.clear();
                cs_group.clear();
                file >> len1 >> len2;
                for (int i = 0; i < len1; i++) {
                    newP.LoadPipeInfo(file);
                    pipe_group.insert({ newP.GetPipeId(),newP });
                    if (Pipe::MaxPipeId <= newP.GetPipeId())
                        Pipe::MaxPipeId = newP.GetPipeId() + 1;

                }
                for (int i = 0; i < len2; i++) {
                    newCS.LoadCSInfo(file);
                    cs_group.insert({ newCS.GetCSId(),newCS });
                    if (CompressorStation::MaxCSId <= newCS.GetCSId())
                        CompressorStation::MaxCSId = newCS.GetCSId() + 1;
                }
            }
            break;
        }
        case 8: {
            if (pipe_group.size() != 0) {
                auto x = SearchPipe(pipe_group);
                if (x.size() != 0) {
                    for (auto& i : x)
                        cout << pipe_group[i] << endl;
                }
                else
                    cout << "There is no such pipe!" << endl;
            }
            else
                cout << "There is no pipe to be found there!" << endl;
            break;
        }
        case 9: {

            if (cs_group.size() != 0) {
                auto x = SearchCS(cs_group);
                if (x.size() != 0) {
                    for (auto& i : x)
                        cout << cs_group[i] << endl;
                }
                else
                    cout << "There is no such CS";
            }
            else
                cout << "There is no CS to be found there!" << endl;
            break;
        }
        case 0: {
            cout << "Goodbye!";
            break;
        }
        default:
            cout << "Wrong request! Try to enter the number from 0 to 9 again!";
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
