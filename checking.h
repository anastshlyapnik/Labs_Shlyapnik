#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "pipe.h"
#include "cs.h"
using namespace std;


template <typename T>
T NumberChecking(T min, T max) {
     T x;
    while (((cin >> x).fail()) || (cin.peek() != '\n') || (x < min) || (x > max)) {
        cout << "Wrong request! Please input numeric value more than " << min << " and less than " << max <<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    return x;
}
template <typename T>
ostream& operator<< (ostream& out, unordered_map <int, T>& par) 
{
    out << "Exiting id: ";
     for (auto& [i, obj] : par) {
     out << i << " ";
     }
     out << endl;
     return out;
}

template <typename T>
using PipeFilter = bool (*) (Pipe& p, T par);
template <typename T>
using CSFilter = bool(*) (CompressorStation& cs, T par);

template <typename T>
vector <int> SearchPipebyParameter(unordered_map <int, Pipe>& PipeGroup, PipeFilter<T> f, T par) {
     vector <int> id;
     for (auto& pipe : PipeGroup) {
         if (f(pipe.second, par))
             id.push_back(pipe.second.GetPipeId());
     }
     return id;
}


template <typename T>
vector <int> SearchCSbyParameter(unordered_map <int, CompressorStation>& CSGroup, CSFilter<T> f, T par) {
    vector <int> id;
    for (auto& cs : CSGroup) {
        if (f(cs.second, par))
           id.push_back(cs.second.GetCSId());
     }
    return id;
}

