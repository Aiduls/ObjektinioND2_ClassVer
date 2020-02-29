#include <iostream>
#include <algorithm>    // std::any_of
#include <iomanip>      // std::setprecision
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <iterator>
//#include <string>

using namespace std;

void digitCheck(string& stringas, bool check);
void symbolCheck(double &skaicius, bool check, bool balas);
void symbolCheck(int& skaicius, bool check, bool balas);
void boolCheck(bool &arMediana);
double vectorSymbolCheck(); 
double mediana(vector<double>& nd);
double vidurkis(vector<double>& nd, double egz);
void isvedimas(string vardas, string pavarde, double vid, double med);



struct Studentas {

    string vardas="", pavarde="";
    int n=0;
    vector<double> ND;
    double egz = 0, galVid = 0, galMed = 0;
};

int main()
{
    bool check = false, balas = false, arNulis = false, arMediana=false, arFailas=false, arAuto=false;
    int ndKiekis, stKiekis=0;
    Studentas studentas;
    string ndCheck="";
    int ndCount=0;
    cout << "Ar norite suvesti studento duomenis patys, ar nuskaityti juos is failo? Iveskite '0' jei norite ivesti patys, ir '1' jei norite vykdyti nuskaityma is failo: ";
    boolCheck(arFailas);

    vector<Studentas> eilinis;
        
    if (arFailas) { // skaitomi is failo
        ifstream infile("Studentai10000.txt");
        if (infile.is_open()) { 
            string line;

            infile >> studentas.vardas >> studentas.pavarde;
            infile >> line;
            ndCheck = ndCheck + line[0] + line[1];
            if (line.substr(0,1)!="E" || line.substr(0, 1) != "e") { // tikrina ar pirmasis skaicius po pavardes nera egzaminas
                ndCount++;
                infile >> line;
                while (line.substr(0, 2) == ndCheck) { // skaiciuoja, kiek bus nd
                    infile >> line;
                    ndCount++;
                }
            }
            int ndPazymys;
            while (!infile.eof()) {
                eilinis.push_back(Studentas());
                infile >> eilinis[stKiekis].vardas;
                infile >> eilinis[stKiekis].pavarde;

                for (int i = 0; i < ndCount; i++) {
                    infile >> ndPazymys;
                    eilinis[stKiekis].ND.push_back(ndPazymys);
                }
                infile>>eilinis[stKiekis].egz;
                stKiekis++;
            }
            infile.close();

    /*        cout << eilinis[0].vardas << " " << eilinis[0].pavarde << "\n";
            for (int i = 0; i < ndCount; i++) {
                cout << eilinis[0].ND[i] << " ";
            }
            cout << endl << eilinis[0].egz<<endl; */

            for (int i = 0; i < stKiekis; i++) {
                if (ndCount == 0) {
                    eilinis[i].galMed = 0;
                    eilinis[i].galVid = eilinis[i].egz * 0.6;
                }
                else {
                    eilinis[i].galMed = mediana(eilinis[i].ND);
                    eilinis[i].galVid = vidurkis(eilinis[i].ND, eilinis[i].egz);
                }
            }
            // isvedimas
            cout << "Pavarde             Vardas              Galutinis (vid.)    Galutinis (med.)    \n";
            cout << "--------------------------------------------------------------------------------\n";
            for (int i = 0; i < stKiekis; i++) {
               // cout << left << eilinis[i].galVid << right << eilinis[i].galMed << endl;
                isvedimas(eilinis[i].pavarde, eilinis[i].vardas, eilinis[i].galVid, eilinis[i].galMed);
            }
        }
        else {
            cout << "Problema su failu.\n";
        }
    }
    else { // ivedami ranka
        cout << "\nIveskite studento varda: ";
        cin >> studentas.vardas;
        digitCheck(studentas.vardas, check);

        cout << "\nIveskite studento pavarde: ";
        cin >> studentas.pavarde;
        digitCheck(studentas.pavarde, check);
        
        cout << "\nAr norite generuoti pazymius automatiskai? 0 - ne, 1- taip.";
        boolCheck(arAuto);

        if (arAuto) { // generavimas automatiskai
            random_device rd;
            mt19937 mt(rd());
            uniform_int_distribution<int> kiekis(0, 5);
            uniform_real_distribution<double> balai(1.0, 10.0);
            ndKiekis = kiekis(mt);
            double balas;
            for (int i = 0; i < ndKiekis; i++) {
                balas = balai(mt);
                studentas.ND.push_back(balas);
            }
            balas = balai(mt);
            studentas.egz = balas;
            if (ndKiekis == 0) arNulis = true;
        }
        else { // vedimas ranka

            cout << "\nIveskite studento namu darbu kieki: ";
            symbolCheck(studentas.n, check, balas);
            if (studentas.n == 0) arNulis = true;

            balas = true;
            if (!arNulis) {
                for (int i = 0; i < studentas.n; i++) {
                    cout << "\nIveskite " << i + 1 << "-a studento namu darbu bala: ";
                    studentas.ND.push_back(vectorSymbolCheck());
                }
            }

            cout << "\nIveskite studento egzamino bala: ";
            symbolCheck(studentas.egz, check, balas);
        }
        cout << "\nAr galutini bala isvesti kaip aritmetini vidurki (iveskite 0), ar kaip mediana (iveskite 1): ";
        boolCheck(arMediana);

        // Mediana/Vidurkis:
            if (arNulis) {
                cout << "nulis\n";
                studentas.galMed = studentas.egz;
                studentas.galVid = studentas.egz * 0.6;
            }
            else {
                studentas.galMed = mediana(studentas.ND);
                studentas.galVid = vidurkis(studentas.ND, studentas.egz);
            }

         if (arMediana) {
          cout << "Pavarde:            Vardas:             Galutinis ivert.:\n";
          cout << "---------------------------------------------------------\n";
          cout <<left<< setw(20)<<studentas.pavarde << setw(20)<< studentas.vardas << setw(20) <<fixed<< setprecision(2) << studentas.galMed << endl;
         }
         else {
          cout << "Pavarde:            Vardas:             Galutinis ivert.:\n";
          cout << "---------------------------------------------------------\n";
          cout << left << setw(20) << studentas.pavarde << setw(20) << studentas.vardas << setw(20) << fixed << setprecision(2) << studentas.galVid << endl;
         }
  
    }
    return 0;
}
void isvedimas(string pavarde, string vardas, double vid, double med)
{
   // ofstream offile("rezultatai.txt", ios::app);
    cout << left << setw(20) << pavarde << setw(20) << vardas << setw(20) << setprecision(3) << vid << setw(20) << setprecision(2) << med << endl;

}
double vidurkis(vector<double>& nd, double egz) 
{
        double vidurkis = 0;
        int dydis = nd.size();
        for (int i = 0; i < dydis; i++) {
            vidurkis += nd[i];
        }

        return vidurkis = 0.4 * (vidurkis / dydis) + 0.6 * egz;
}
double mediana(vector<double>& nd)
{
    int dydis = nd.size();
    // susortina masyva
    sort(nd.begin(), nd.end());
    // suranda mediana
    if  (dydis % 2 == 0)
    {
        return (nd[dydis / 2 - 1] + nd[dydis / 2]) / 2;
    }
    else
    {
        return nd[dydis / 2];
    }
}
void digitCheck(string& stringas, bool check)
{
    while (!check) {
        if (std::any_of(stringas.begin(), stringas.end(), isdigit))
        {
            cout << "\nVardas ir pavarde negali tureti skaiciu! Prasome ivesti is naujo: ";
            cin >> stringas;
        }
        else {
            check = true;
        }
    }
}
void symbolCheck(double &skaicius, bool ok,bool balas) 
{
    ok = false;
    cin >> skaicius;
    while (cin.fail()) { // tikrina ar tikrai ivestas double tipo skaicius
        cout << "\nIvesta reiksme gali buti tik skaicius. Iveskite skaiciu is naujo: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> skaicius;
    }

        while (!ok) {
            if (cin.fail()) symbolCheck(skaicius, ok, balas); 
            if (balas) {
                if (skaicius >= 0.0 && skaicius <= 10.0)
                {
                    ok = true;
                }
                else {
                    cout << "\nBalas turi buti desimtbaleje sistemoje. Iveskite skaiciu is naujo: ";
                    cin >> skaicius;
                }
            }
            else {
                if (skaicius < 0.0) {
                    cout << "\nNamu darbu kiekis turi buti neneigiamas skaicius. Iveskite skaiciu is naujo: ";
                    cin >> skaicius;
                }
                else ok = true;
            }
        }
}
void symbolCheck(int& skaicius, bool ok, bool balas)
{
    ok = false;
    cin >> skaicius;
    while (cin.fail()) { // tikrina ar tikrai ivestas double tipo skaicius
        cout << "\nIvesta reiksme gali buti tik skaicius. Iveskite skaiciu is naujo: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> skaicius;
    }

    while (!ok) {
        if (cin.fail()) symbolCheck(skaicius, ok, balas);
        if (balas) {
            if (skaicius >= 0.0 && skaicius <= 10.0)
            {
                ok = true;
            }
            else {
                cout << "\nBalas turi buti desimtbaleje sistemoje. Iveskite skaiciu is naujo: ";
                cin >> skaicius;
            }
        }
        else {
            if (skaicius < 0.0) {
                cout << "\nNamu darbu kiekis turi buti neneigiamas skaicius. Iveskite skaiciu is naujo: ";
                cin >> skaicius;
            }
            else ok = true;
        }
    }
}
double vectorSymbolCheck() // PAKEISTI KAD TIKTU VEKTORIUI
{
    double skaicius;
    bool ok = false;
    cin >> skaicius;
    while (cin.fail()) { // tikrina ar tikrai ivestas double tipo skaicius
        cout << "\nIvesta reiksme gali buti tik skaicius. Iveskite skaiciu is naujo: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> skaicius;
    }

    while (!ok) {
        if (cin.fail()) vectorSymbolCheck();
            if (skaicius >= 0.0 && skaicius <= 10.0)
            {
                ok = true;
            }
            else {
                cout << "\nBalas turi buti desimtbaleje sistemoje. Iveskite skaiciu is naujo: ";
                cin >> skaicius;
            }
    }

    return skaicius;
}
void boolCheck(bool &check) 
{
    int ivestis;
    bool ok = false;
    while (!ok) {
        cin >> ivestis;
        if (cin.fail()) {
            cout << "\nIveskite 0 arba 1: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        else {
            if (ivestis == 0) {
                check = false;
                ok = true;
            }
            else if (ivestis == 1) {
                check = true;
                ok = true;
            }
            else cout << "\nIveskite 0 arba 1: ";
        }
       
    }
}