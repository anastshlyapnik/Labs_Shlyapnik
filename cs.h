#pragma once
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <float.h>

class CompressorStation
{
public: static int MaxCSId;
      CompressorStation() {
          CSId = MaxCSId++;
      }
      friend istream& operator>> (istream& in, CompressorStation& CS);
      friend ostream& operator<< (ostream& out, CompressorStation& CS);
      void SaveCSInfo(ofstream& file);
      void EditCS();
      void LoadCSInfo(ifstream& file);
      int GetCSId() { return CSId; }
      double GetUsing() { return (((double)Workshops - (double)WorkshopsInOperation) / (double)Workshops) * 100; }
      string Name = "";


private:
    int  Workshops, WorkshopsInOperation, CSId;
    double Efficiency;
};

