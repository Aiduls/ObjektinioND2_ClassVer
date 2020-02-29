#pragma once
#include <iostream>
#include <algorithm>    // std::any_of
#include <iomanip>      // std::setprecision
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

struct Studentas {

    string vardas = "", pavarde = "";
    int n = 0;
    vector<double> ND;
    double egz = 0, galVid = 0, galMed = 0;
};

void digitCheck(string& stringas, bool check);
void symbolCheck(double& skaicius, bool check, bool balas);
void symbolCheck(int& skaicius, bool check, bool balas);
void boolCheck(bool& arMediana);
double vectorSymbolCheck();
double mediana(vector<double>& nd);
double vidurkis(vector<double>& nd, double egz);
void isvedimas(string vardas, string pavarde, double vid, double med);
//void failoNuskaitymas(vector<Studentas>& eilinis, string &ndCheck, int& ndCount, int& stKiekis);
bool compareByLength(const Studentas& a, const Studentas& b);

