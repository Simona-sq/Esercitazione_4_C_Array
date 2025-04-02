#pragma once

#include "ClassObj.hpp"
#include <iostream>
#include <fstream>

using namespace std;

bool ReadDatas(const string& InputFile, double& S, unsigned int& n, double*& w, double*& r);

double FinalValue(double& S,unsigned int& n, double*& w,double*& r);

double RateOfReturn(unsigned int& n, double*& w, double*& r);

bool WriteResults(const string& OutputFile, double& S, unsigned int& n, double& V, double& ror, double*& w, double*& r);