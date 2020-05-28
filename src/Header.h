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

/// Tėvinė žmogaus klasė 
class Zmogus {
protected:
    string vardas;
    string pavarde;
public:
    virtual string getVardas() = 0;
    virtual string getPavarde() = 0;
};

/// Dukterinė žmogaus klasė - Studentas
///
/// Joje aprašomi konkrečiai studento kintamieji
class StudentasClass: public Zmogus {
private:
    int ndKiekis;
    vector<double> ND;
    int egz;
    double vidurkis, galutinis;

public:
    // konstruktoriai
    StudentasClass() { 
        setValues("", "", 0, 0); 
    }
    
    // destruktoriai
    ~StudentasClass() {}

    // priskyrimo opratorius
    StudentasClass& operatorASSIGN(const StudentasClass& that);

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
    string getVardas() override { return vardas; }
    string getPavarde() override { return pavarde; }
    double getGalutinis() const { return galutinis; }  
};

// nuo v1.1
void containerTestingVector_Class(vector<StudentasClass>& pabiruciai, vector<StudentasClass>& eilinis, int kiekis);
string generuoti_ForClass(int kiekis);
void nuskaityti_ForClass(vector<StudentasClass>& eilinis, int kiekis, string failas);
void rusiuoti_ForClass(vector<StudentasClass>& eilinis);
void skirstytiv3_ForClass(vector<StudentasClass>& eilinis, vector<StudentasClass>& pabiruciai);
void calculateFinal_ForClass(vector<StudentasClass>& eilinis, int kiekis);
void isvedimas_ForClass(vector<StudentasClass> vektorius, string failoPav);
bool compare_5_ForClass(const StudentasClass& v);
bool maziau_ForClass(const StudentasClass& a, const StudentasClass& b);

std::ostream& operator<<(std::ostream& offile, vector<StudentasClass>& vektorius);










