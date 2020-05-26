#pragma once
#include <iostream>
#include <algorithm>    // std::any_of
#include <iomanip>      // std::setprecision
#include <vector>
#include <random>
#include <fstream>
#include <string>
#include <iterator>
#include <chrono>
#include <list>
#include <deque>


using namespace std;

struct Studentas {

    string vardas = "", pavarde = "";
      int n = 0;
    vector<double> ND;
    double egz = 0, galVid = 0, galMed = 0;
};

class StudentasClass {
private:
    string vardas;
    string pavarde;
    int ndKiekis = 0;
    vector<double> ND;
    int egz;
    double vidurkis, galutinis = 0;

public:
    // konstruktoriai
    StudentasClass() { 
        setValues("", "", 0, 0); 
    }

    StudentasClass(string vardas, string pavarde, double vidurkis, double egz) {
        setValues(vardas, pavarde, vidurkis, egz);
    }
    // priskyrimo opratorius
    StudentasClass& operatorASSIGN(const StudentasClass& that);
    
    // destruktoriai
    ~StudentasClass() {}

    // kopijavimo operatorius
    StudentasClass(const StudentasClass& that) : vardas(that.vardas), pavarde(that.pavarde), vidurkis(that.vidurkis), egz(that.egz), galutinis(that.galutinis) {}

    // setteriai
    void setValues(std::string vardas, std::string pavarde, double vidurkis, double egz) {
        this->vardas = vardas;
        this->pavarde = pavarde;
        this->vidurkis = vidurkis;
        this->egz = egz;
    }
    void setGalutinis() { // set'eris
        this->galutinis = 0.4 * this->vidurkis + 0.6 * this-> egz;
    }

    // getteriai
    string getVardas() const { return vardas; }  
    string getPavarde() const { return pavarde; }  
    double getGalutinis() const { return galutinis; }  
};

void isvedimas(vector<Studentas>& eilinis);
bool compareByLength(const Studentas& a, const Studentas& b);
string generuoti(vector<Studentas>& eilinis, int kiekis);
void nuskaityti(vector<Studentas>& eilinis, int kiekis, string failas);
void rusiuoti(vector<Studentas>& eilinis);
bool maziau(const Studentas& a, const Studentas& b);
void skirstyti(vector<Studentas>& eilinis, vector<Studentas> &pabiruciai, vector<Studentas> &protinguciai);
void isvedimas(vector<Studentas> vektorius, string failoPav);
void containerTesting(vector<Studentas>& pabiruciai, vector<Studentas>& protinguciai, vector<Studentas>& eilinis, int kiekis);
void containerTesting(list<Studentas>& pabiruciai, list<Studentas>& protinguciai, list<Studentas>& eilinis, int kiekis);
string generuoti(list<Studentas> eilinis, int kiekis);
void nuskaityti(list<Studentas>& eilinis, int kiekis, string failas);
void isvedimas(list<Studentas>& listas, string failoPav);
void rusiuoti(list<Studentas>& eilinis);
void containerTesting(deque<Studentas>& pabiruciai, deque<Studentas>& protinguciai, deque<Studentas>& eilinis, int kiekis);
string generuoti(deque<Studentas> eilinis, int kiekis);
void nuskaityti(deque<Studentas>& eilinis, int kiekis, string failas);
void rusiuoti(deque<Studentas>& eilinis);
void skirstyti(deque<Studentas>& eilinis, deque<Studentas>& pabiruciai, deque<Studentas>& protinguciai);
void isvedimas(deque<Studentas> dekas, string failoPav);
void skirstyti(list<Studentas>& eilinis, list<Studentas>& pabiruciai, list<Studentas>& protinguciai);
bool compare_5(const Studentas& v);
void skirstytiv2(vector<Studentas>& eilinis, vector<Studentas>& pabiruciai);
void skirstytiv2(list<Studentas>& eilinis, list<Studentas>& pabiruciai);
void skirstytiv2(deque<Studentas>& eilinis, deque<Studentas>& pabiruciai);
void skirstytiv3(vector<Studentas>& eilinis, vector<Studentas>& pabiruciai);

// nuo v1.1
void containerTestingVector_Class(vector<StudentasClass>& pabiruciai, vector<StudentasClass>& eilinis, int kiekis);
string generuoti_ForClass(int kiekis);
void nuskaityti_ForClass(vector<StudentasClass>& eilinis, int kiekis, string failas);
void rusiuoti_ForClass(vector<StudentasClass>& eilinis);
void skirstytiv3_ForClass(vector<StudentasClass>& eilinis, vector<StudentasClass>& pabiruciai);
void isvedimas_ForClass(vector<Studentas> vektorius, string failoPav);
void calculateFinal_ForClass(vector<StudentasClass>& eilinis, int kiekis);
void isvedimas_ForClass(vector<StudentasClass> vektorius, string failoPav);
bool compare_5_ForClass(const StudentasClass& v);
bool maziau_ForClass(const StudentasClass& a, const StudentasClass& b);

std::ostream& operator<<(std::ostream& offile, vector<StudentasClass>& vektorius);










