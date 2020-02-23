#include <iostream>
#include <algorithm>    // std::any_of
#include <iomanip>      // std::setprecision
#include <vector>
#include <random>


using namespace std;

void digitCheck(string& stringas, bool check);
void symbolCheck(double &skaicius, bool check, bool balas);
void symbolCheck(int& skaicius, bool check, bool balas);
void boolCheck(bool& arMediana);
void swap(double* xp, double* yp);
double vectorSymbolCheck();

struct Studentas {

    string vardas="", pavarde="";
    int n=0;
    vector<double> ND;
    double egz = 0, galVid = 0, galMed = 0;
};

int main()
{
    //string vardas = "", pavarde = "";
   // double nd[1000], egz = 0, galVid = 0, galMed = 0;
    //int n = 0;
    bool check = false, balas = false, arNulis = false, arMediana, arFailas, arAuto;
    int ndKiekis;
    Studentas studentas;

    cout << "Ar norite suvesti studento duomenis patys, ar nuskaityti juos is failo? Iveskite '0' jei norite ivesti patys, ir '1' jei norite vykdyti nuskaityma is failo: ";
    boolCheck(arFailas);
        
    if (arFailas) { // skaitomi is failo

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
            cout << "kiekis: " << ndKiekis <<endl;
            for (int i = 0; i < ndKiekis; i++) {
                balas = balai(mt);
                studentas.ND.push_back(balas);
                cout << studentas.ND[i] << endl;    
            }
            balas = balai(mt);
            studentas.egz = balas;
            cout << "egz: " << studentas.egz << endl;
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

    }


    
    
    cout << "\nAr galutini bala isvesti kaip aritmetini vidurki (iveskite 0), ar kaip mediana (iveskite 1): ";
    boolCheck(arMediana);
    if (!arMediana) {
        if (arNulis) {
            studentas.galVid = 0.4 * 0 + 0.6 * studentas.egz;
        }
        else {
            double vidurkis = 0;
            for (int i = 0; i < studentas.ND.size(); i++) {
                vidurkis += studentas.ND[i];
                cout << "nd: " << studentas.ND[i];
            }
            cout << vidurkis << endl;
                
            studentas.galVid = 0.4 * (vidurkis / studentas.ND.size()) + 0.6 * studentas.egz;
        }
    }
    else {
        if (arNulis) {
            studentas.galMed = studentas.egz;
        }
        else {
            // susortina masyva
            for (int i = 0; i < studentas.ND.size() - 1; i++)
                for (int j = 0; j < studentas.ND.size() - i - 1; j++)
                    if (studentas.ND[j] > studentas.ND[j + 1])
                        swap(&studentas.ND[j], &studentas.ND[j + 1]);
            // suranda mediana
            if (studentas.ND.size() % 2 == 0) { //jei lyginis
                studentas.galMed = (studentas.galMed + studentas.ND[studentas.n / 2 - 1] + studentas.ND[studentas.n / 2]) / 2;
            }
            else studentas.galMed = studentas.ND[studentas.n / 2];
        }

    }

    if (arMediana) {
        cout << "Pavarde:              Vardas:              Galutinis ivert.:\n";
        cout << "------------------------------------------------------------\n";
        cout << studentas.pavarde << "                 " << studentas.vardas << "                   " <<fixed<< setprecision(2) << studentas.galMed << endl;
    }
    else {
        cout << "Pavarde:              Vardas:              Galutinis ivert.:\n";
        cout << "------------------------------------------------------------\n";
        cout << studentas.pavarde << "                 " << studentas.vardas << "                   " << fixed << setprecision(2) << studentas.galVid << endl;
    }

    return 0;
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
void boolCheck(bool &arMediana) 
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
                arMediana = false;
                ok = true;
            }
            else if (ivestis == 1) {
                arMediana = true;
                ok = true;
            }
            else cout << "\nIveskite 0 arba 1: ";
        }
       
    }
}
void swap(double* xp, double* yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}
