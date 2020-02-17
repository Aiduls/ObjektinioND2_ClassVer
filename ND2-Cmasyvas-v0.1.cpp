#include <iostream>
#include <algorithm>    // std::any_of
#include <iomanip>      // std::setprecision


using namespace std;

void digitCheck(string& stringas, bool check);
void symbolCheck(double &skaicius, bool check, bool balas);
void symbolCheck(int& skaicius, bool check, bool balas);
void boolCheck(bool& arMediana);
void swap(double* xp, double* yp);


int main()
{
    string vardas = "", pavarde = "";
    double nd[1000], egz = 0, galVid = 0, galMed = 0;
    int n = 0;
    bool check = false, balas = false, arNulis = false, arMediana;

    cout << "Iveskite studento varda: ";
    cin >> vardas;
    digitCheck(vardas, check);

    cout << "\nIveskite studento pavarde: ";
    cin >> pavarde;
    digitCheck(pavarde, check);
    
    cout << "\nIveskite studento namu darbu kieki: ";
    symbolCheck(n,check,balas);
    if (n == 0) arNulis = true;

    balas = true;
    if (!arNulis) {
        for (int i = 0; i < n; i++) {
            cout << "\nIveskite " << i+1 << "-a studento namu darbu bala: ";
            symbolCheck(nd[i], check, balas);
        }
    }
    
    cout << "\nIveskite studento egzamino bala: ";
    symbolCheck(egz, check, balas);
    
    cout << "\nAr galutini bala isvesti kaip aritmetini vidurki (iveskite 0), ar kaip mediana (iveskite 1): ";
    boolCheck(arMediana);

    if (!arMediana) {
        if (arNulis) {
            galVid = 0.4 * 0 + 0.6 * egz;
        }
        else {
            double vidurkis = 0;
            for (int i = 0; i < n; i++)
                vidurkis += nd[i];
            galVid = 0.4 * (vidurkis / n) + 0.6 * egz;
        }
    }
    else {
        if (arNulis) {
            galMed = egz;
        }
        else {
            // susortina masyva
            for (int i = 0; i < n - 1; i++)
                for (int j = 0; j < n - i - 1; j++)
                    if (nd[j] > nd[j + 1])
                        swap(&nd[j], &nd[j + 1]);
            // suranda mediana
            if (n % 2 == 0) { //jei lyginis
                galMed = (galMed + nd[n / 2 - 1] + nd[n / 2]) / 2;
            }
            else galMed = nd[n / 2];
        }

    }

    if (arMediana) {
        cout << "Pavarde:              Vardas:              Galutinis ivert.:\n";
        cout << "------------------------------------------------------------\n";
        cout << pavarde << "                 " << vardas << "                   " <<fixed<< setprecision(2) << galMed << endl;
    }
    else {
        cout << "Pavarde:              Vardas:              Galutinis ivert.:\n";
        cout << "------------------------------------------------------------\n";
        cout << pavarde << "                 " << vardas << "                   " << fixed << setprecision(2) << galVid << endl;
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
void boolCheck(bool &arMediana) 
{
    int ivestis;
    bool ok = false;
    while (!ok) {
        cin >> ivestis;
        if (cin.fail()) {
            cout << "\nIveskite 0(vidurkiui) arba 1(medianai): ";
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
            else cout << "\nIveskite 0(vidurkiui) arba 1(medianai): ";
        }
       
    }
}
void swap(double* xp, double* yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}