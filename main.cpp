#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"


using namespace std;
int main()
{
    // File di input
    string InputFile = "data.txt";

    // File di output
    string OutputFile = "result.txt";

    // Definisco le variabili nel main: verranno passate per riferimento
    double S;
    unsigned int n;
    double* ptrw = nullptr;
    double* ptrr = nullptr;

    // Chiamo le funzioni dichiarate in Utils.hpp e definite in Utils.cpp
    ReadDatas(InputFile, S, n, ptrw, ptrr);
    
    double V = FinalValue(S, n,ptrw, ptrr);

    double RoR = RateOfReturn(n, ptrw, ptrr);
    
    WriteResults(OutputFile, S, n, V, RoR, ptrw, ptrr);

    // Dealloco la memoria allocata in ReadDatas(...)
    delete[] ptrw;
    delete[] ptrr;

    return 0;
}

