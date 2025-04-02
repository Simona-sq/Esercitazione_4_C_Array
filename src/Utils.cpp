#include "Utils.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


// Funzione che legge i dati dal file di input
bool ReadDatas(const string& InputFile, double& S, unsigned int& n, double*& w, double*& r)
{
    ifstream file(InputFile);
    if (!(file.is_open()))
        return false;

    string line;

    // Leggo S
    getline(file, line);
    stringstream ss1(line);
    char sep1;
    ss1 >> sep1 >> sep1 >> S;

    // Leggo n
    getline(file, line);
    stringstream ss2(line);
    char sep2;
    ss2 >> sep2 >> sep2 >> n;

    // Leggo w e r
    w = new double[n];
    r = new double[n];

    getline(file, line);
    char sep;
    for(unsigned int i = 0; i<n; i++){
        file >> w[i] >> sep >> r[i];
    }
    return true;
}

// Funzione che calcola il rate of return ror
double RateOfReturn(unsigned int& n, double*& w, double*& r){
    double ror = 0;
    for(unsigned int i = 0; i<n; i++){
        // ror: media pesata degli r[i] (i pesi rappresentano la partizione di S, quindi sono i w[i])
        ror += w[i]*r[i];
    }
    return ror;

}

// Funzione che calcola il final value V
double FinalValue(double& S,unsigned int& n, double*& w,double*& r){
    double V = 0;
    for(unsigned i=0; i<n; i++){
        // V: sommatoria dei V[i] = (1+r[i])*S, moltiplicati per la partizione di S
        V += (1+r[i])*w[i]*1000;
    }
    return V;
}

// Funzione che scrive i risultati sul file di output
bool WriteResults(const string& OutputFile, double& S, unsigned int& n, double& V, double& ror, double*& w, double*& r){
    ofstream file;
    file.open(OutputFile);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    // Scrivo S e n
    file << "S = "<< fixed << setprecision(2)<< S <<", n = "<< n << endl;

    // Scrivo w
    file << "w = [ ";
    for(unsigned int i = 0; i <n; i++){
        file << w[i]<< " ";
    }
    file<<"]"<<endl;

    // Scrivo r
    file << "r = [ ";
    for(unsigned int i = 0; i <n; i++){
        file << r[i]<< " ";
    }
    file<<"]"<<endl;

    // Scrivo ror
    file<< "Rate of return of the portfolio: "<< setprecision(4) <<ror << endl;

    // Scrivo V
    file << "V: " << fixed << setprecision(2) << V << endl;

    cout << "Results reported on the output file" <<endl;
    return true;
} 