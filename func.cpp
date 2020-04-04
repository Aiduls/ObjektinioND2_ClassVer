#include "Header.h"

void containerTesting(deque<Studentas>& pabiruciai, deque<Studentas>& protinguciai, deque<Studentas>& eilinis, int kiekis)
{

    chrono::time_point<chrono::system_clock> start, end;
    chrono::time_point<chrono::system_clock> startEvent, endEvent;
    chrono::duration<double> elapsed_seconds;

    int protKiekis, pabirKiekis;
    string failas;

    eilinis.clear();
    pabiruciai.clear();
    protinguciai.clear();
    startEvent = std::chrono::system_clock::now();
    try {
        failas = generuoti(eilinis, kiekis); // process
    }
    catch(std::exception & e) {
        cout << "Ivyko klaida deque failo generavime \n";
    }
    eilinis.clear();
    pabiruciai.clear();
    protinguciai.clear();
    try {
        start = chrono::system_clock::now();
        nuskaityti(eilinis, kiekis, failas);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        cout << "Failo su " << kiekis << " duomenu nuskaitymas uztruko: " << elapsed_seconds.count() << "s\n";
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida deque failo nuskaityme \n";
    }

    try {
        start = chrono::system_clock::now();
        rusiuoti(eilinis, kiekis);
        pabirKiekis = 0;
        protKiekis = 0;
        skirstyti(eilinis, kiekis, pabirKiekis, protKiekis, pabiruciai, protinguciai);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        cout << "Failo su " << kiekis << " duomenu rusiavimas ir skirstymas i protingus ir pabirucius uztruko: " << elapsed_seconds.count() << "s\n";
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida deque failo rusiavime/skirstyme \n";
    }
    

    string pavadinimasPabir = "pabiruciai" + to_string(kiekis) + ".txt";
    string pavadinimasProt = "protinguciai" + to_string(kiekis) + ".txt";

    try {
        isvedimas(protinguciai, protKiekis, pavadinimasProt);
        isvedimas(pabiruciai, pabirKiekis, pavadinimasPabir);
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida deque failo isvedime \n";
    }


    endEvent = std::chrono::system_clock::now();
    elapsed_seconds = endEvent - startEvent;
    cout << "Failo su " << kiekis << " duomenu procesai uztruko: " << elapsed_seconds.count() << "s\n\n";
}

// list testing
void containerTesting(list<Studentas>& pabiruciai, list<Studentas>& protinguciai, list<Studentas>& eilinis, int kiekis)
{

    chrono::time_point<chrono::system_clock> start, end;
    chrono::time_point<chrono::system_clock> startEvent, endEvent;
    chrono::duration<double> elapsed_seconds;

    int protKiekis, pabirKiekis;
    string failas;

    eilinis.resize(kiekis);

    startEvent = std::chrono::system_clock::now();
    try {
        failas = generuoti(eilinis, kiekis); // process
    }
    catch(std::exception & e) {
        cout << "Ivyko klaida list failo generavime \n";
    }
    eilinis.clear();
    try {
        start = chrono::system_clock::now();
        nuskaityti(eilinis, kiekis, failas);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        cout << "Failo su " << kiekis << " duomenu nuskaitymas uztruko: " << elapsed_seconds.count() << "s\n";
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida list failo nuskaityme \n";
    }

    try {
        start = chrono::system_clock::now();
        rusiuoti(eilinis, kiekis);
        pabirKiekis = 0;
        protKiekis = 0;
        skirstytiList(eilinis, pabiruciai, protinguciai);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        cout << "Failo su " << kiekis << " duomenu rusiavimas ir skirstymas i protingus ir pabirucius uztruko: " << elapsed_seconds.count() << "s\n";
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida list failo rusiavime ir skaityme \n";
    }


    string pavadinimasPabir = "pabiruciai" + to_string(kiekis) + ".txt";
    string pavadinimasProt = "protinguciai" + to_string(kiekis) + ".txt";

    try {
        isvedimas(pabiruciai, pabirKiekis, pavadinimasPabir);
        isvedimas(protinguciai, protKiekis, pavadinimasProt);
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida list failo rusiavime ir skaityme \n";
    }


    endEvent = std::chrono::system_clock::now();
    elapsed_seconds = endEvent - startEvent;
    cout << "Failo su " << kiekis << " duomenu procesai uztruko: " << elapsed_seconds.count() << "s\n\n";
}

// vector testing 
void containerTesting(vector<Studentas>& pabiruciai, vector<Studentas>& protinguciai, vector<Studentas>& eilinis, int kiekis) 
{
    eilinis.reserve(kiekis + 1);
    eilinis.resize(kiekis + 1);
    pabiruciai.reserve(kiekis + 1);
    protinguciai.reserve(kiekis + 1);
    pabiruciai.resize(kiekis + 1);
    protinguciai.resize(kiekis + 1); // rezervuota viena vieta daugiau, kad butu paprasciau skaiciuoti irasus nuo 1

    chrono::time_point<chrono::system_clock> start, end;
    chrono::time_point<chrono::system_clock> startEvent, endEvent;
    chrono::duration<double> elapsed_seconds;

    int protKiekis, pabirKiekis;
    string failas;

    startEvent = std::chrono::system_clock::now();
    try {
        failas = generuoti(eilinis, kiekis); // process
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo generavime \n";
    }

    try {
        start = chrono::system_clock::now();
        nuskaityti(eilinis, kiekis, failas);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        cout << "Failo su " << kiekis << " duomenu nuskaitymas uztruko: " << elapsed_seconds.count() << "s\n";
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo nuskaityme \n";
    }

    try {
        start = chrono::system_clock::now();
        rusiuoti(eilinis, kiekis);
        pabirKiekis = 0;
        protKiekis = 0;
        skirstyti(eilinis, kiekis, pabirKiekis, protKiekis, pabiruciai, protinguciai);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        cout << "Failo su " << kiekis << " duomenu rusiavimas ir skirstymas i protingus ir pabirucius uztruko: " << elapsed_seconds.count() << "s\n";
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo rusiavime/skirstyme \n";
    }


    string pavadinimasPabir = "pabiruciai" + to_string(kiekis) + ".txt";
    string pavadinimasProt = "protinguciai" + to_string(kiekis) + ".txt";

    try {
        isvedimas(pabiruciai, pabirKiekis, pavadinimasPabir);
        isvedimas(protinguciai, protKiekis, pavadinimasProt);
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo isvedime \n";
    }

    endEvent = std::chrono::system_clock::now();
    elapsed_seconds = endEvent - startEvent;
    cout << "Failo su " << kiekis << " duomenu procesai uztruko: " << elapsed_seconds.count() << "s\n\n";
}
void dalykai(vector<Studentas>& pabiruciai, vector<Studentas>& protinguciai, vector<Studentas>& eilinis, int kiekis)
{
    eilinis.reserve(kiekis + 1);
    eilinis.resize(kiekis + 1);
    pabiruciai.reserve(kiekis + 1);
    protinguciai.reserve(kiekis + 1);
    pabiruciai.resize(kiekis + 1);
    protinguciai.resize(kiekis + 1); // rezervuota viena vieta daugiau, kad butu paprasciau skaiciuoti irasus nuo 1

    chrono::time_point<chrono::system_clock> start, end;
    chrono::time_point<chrono::system_clock> startEvent, endEvent;
    chrono::duration<double> elapsed_seconds;

    int protKiekis, pabirKiekis;
    string failas;

    start = chrono::system_clock::now();
    startEvent = chrono::system_clock::now();
    failas = generuoti(eilinis, kiekis); // process
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su "<< kiekis<<" duomenu sugeneravimas uztruko: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();
    nuskaityti(eilinis, kiekis, failas);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << kiekis << " duomenu nuskaitymas uztruko: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();
    rusiuoti(eilinis, kiekis);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << kiekis << " duomenu rusiavimas uztruko: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();
    pabirKiekis = 0;
    protKiekis = 0;
    skirstyti(eilinis, kiekis, pabirKiekis, protKiekis, pabiruciai, protinguciai);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << kiekis << " duomenu skirstymas i protingus ir pabirucius uztruko: " << elapsed_seconds.count() << "s\n";

    string pavadinimasPabir = "pabiruciai" + to_string(kiekis) + ".txt";
    string pavadinimasProt = "protinguciai" + to_string(kiekis) + ".txt";

    start = chrono::system_clock::now();
    isvedimas(pabiruciai, pabirKiekis, pavadinimasPabir);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << pabirKiekis << " duomenu irasymas i pabirucius uztruko: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();
    isvedimas(protinguciai, protKiekis, pavadinimasProt);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << protKiekis << " duomenu irasymas i protingucius uztruko: " << elapsed_seconds.count() << "s\n";

    endEvent = std::chrono::system_clock::now();
    elapsed_seconds = endEvent - startEvent;
    cout << "Failo su " << kiekis << " duomenu procesai uztruko: " << elapsed_seconds.count() << "s\n\n";
}
void skirstyti(deque<Studentas>& eilinis, int kiekis, int& pabirKiekis, int& protKiekis, deque<Studentas>& pabiruciai, deque<Studentas>& protinguciai)
{
    for (int i = 0; i < eilinis.size(); i++) {
        if (eilinis[i].egz < 5.00) {
            pabiruciai.push_back(eilinis[i]);
        }
        else if (eilinis[i].egz >= 5.00){
            protinguciai.push_back(eilinis[i]);
        }
    }
}
void skirstytiList(list<Studentas>& eilinis, list<Studentas>& pabiruciai, list<Studentas>& protinguciai)
{
    for (Studentas l : eilinis) {
        if (l.egz >= 5.00) {
            protinguciai.push_back(l);
        }
        else {
            pabiruciai.push_back(l);
        }
    }
}
bool compare_5(const Studentas& v)
{
    return v.egz == 5.00;
}
void skirstyti(list<Studentas>& eilinis, int kiekis, int& pabirKiekis, int& protKiekis, list<Studentas>& pabiruciai, list<Studentas>& protinguciai)
{
    list <Studentas>::iterator it;
    list <Studentas>::iterator pait;
    list <Studentas>::iterator prit;
    it = eilinis.begin();
    pait = pabiruciai.begin();
    prit = protinguciai.begin();
    int counter = 0;
    while (it != eilinis.end()) {
        if (it->egz < 5.00) {
            pait->vardas = it->vardas;
            pait->pavarde = it->pavarde;
            pait->egz = it->egz;
            pait++;
        }
        else {
            prit->vardas = it->vardas;
            prit->pavarde = it->pavarde;
            prit->egz = it->egz;
            prit++;
        }
        counter++;
        it++;
    }
}
void skirstyti(vector<Studentas>& eilinis, int kiekis, int& pabirKiekis, int& protKiekis, vector<Studentas> &pabiruciai, vector<Studentas> &protinguciai)
{
    for (int i = 1; i <= kiekis; i++) {
        if (eilinis[i].egz < 5.00) {
            pabiruciai[pabirKiekis].vardas = eilinis[i].vardas;
            pabiruciai[pabirKiekis].pavarde = eilinis[i].pavarde;
            pabiruciai[pabirKiekis].egz = eilinis[i].egz;
            pabirKiekis++;
        }
        else {
            protinguciai[protKiekis].vardas = eilinis[i].vardas;
            protinguciai[protKiekis].pavarde = eilinis[i].pavarde;
            protinguciai[protKiekis].egz = eilinis[i].egz;
            protKiekis++;
        }
    }
}
void rusiuoti(deque<Studentas>& eilinis, int kiekis)
{
    sort(eilinis.begin(), eilinis.end(), maziau);
}
void rusiuoti(list<Studentas>& eilinis, int kiekis)
{
    eilinis.sort(maziau);
}
void rusiuoti(vector<Studentas>& eilinis, int kiekis)
{
    sort(eilinis.begin(), eilinis.end(), maziau);
}
void nuskaityti(deque<Studentas>& eilinis, int kiekis, string failas)
{
    ifstream autoIn(failas);
    for (int i = 0; i < kiekis; i++) {
        eilinis.push_back(Studentas());
        autoIn >> eilinis[i].pavarde >> eilinis[i].vardas >> eilinis[i].egz;
    }
}
void nuskaityti(list<Studentas>& eilinis, int kiekis, string failas)
{
    ifstream autoIn(failas);
    string ignore;
    autoIn >> ignore >> ignore >> ignore;

    for (int i = 0; i < kiekis; i++) {
        Studentas S;
        autoIn >> S.vardas >> S.pavarde >> S.egz;
        eilinis.push_back(S);
    }
}
void nuskaityti(vector<Studentas>& eilinis, int kiekis, string failas)
{
    ifstream autoIn(failas);
    eilinis = {}; // nunullinam struktura
    eilinis.reserve(kiekis + 1);
    eilinis.resize(kiekis + 1);

    for (int i = 1; i <= kiekis; i++) {
        autoIn >> eilinis[i].pavarde >> eilinis[i].vardas >> eilinis[i].egz;
    }
}
string generuoti(deque<Studentas> eilinis, int kiekis)
{
    int ndKiekis = 3;
    eilinis = {}; // nunullinam struktura
    eilinis.resize(kiekis);
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> balai(1.0, 10.0);
    double vidurkis = 0;
    int iCounter = 0;
    string outFileName = "autoOut" + to_string(kiekis) + ".txt";
    ofstream autoOut(outFileName);
    for (int i = 0; i < kiekis; i++) {
        for (int j = 0; j < ndKiekis; j++) {
            vidurkis += balai(mt);
        }
        vidurkis /= 3.00;
        iCounter++;
        eilinis[i].vardas = "Vardas" + to_string(iCounter);
        eilinis[i].pavarde = "Pavarde" + to_string(iCounter);
        eilinis[i].egz = vidurkis;
        autoOut << left << setw(20) << eilinis[i].pavarde << setw(20) << eilinis[i].vardas << setw(20) << setprecision(3) << eilinis[i].egz << endl;
        vidurkis = 0;
    }
    return outFileName;
}
string generuoti(list<Studentas> eilinis, int kiekis)
{
    int ndKiekis = 3, iCounter = 0;
    eilinis = {}; // nunullinam struktura
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> balai(1.0, 10.0);
    //double egzas;
    string outFileName = "autoOut" + to_string(kiekis) + ".txt";
    double vidurkis=0;
    ofstream autoOut(outFileName);
    list <Studentas>::iterator it;
    it = eilinis.begin();
    autoOut << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(5) << "Vidurkis" << endl;
    for (int i = 0; i < kiekis; i++) {
        for (int j = 0; j < ndKiekis; j++) {
            vidurkis += balai(mt);
        }
        vidurkis /= 3.00;
        iCounter++;
        autoOut << left << setw(20) << "Vardas"+to_string(iCounter) << setw(20) << "Pavarde" + to_string(iCounter) << setw(5) << setprecision(3) <<  vidurkis <<  endl;
        vidurkis = 0;
    }
    return outFileName;
}
string generuoti(vector<Studentas>& eilinis, int kiekis)
{
    int ndKiekis = 3;
    eilinis = {}; // nunullinam struktura
    eilinis.reserve(kiekis+1);
    eilinis.resize(kiekis+1);
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> balai(1.0, 10.0);
    double vidurkis = 0;
    string outFileName = "autoOut" + to_string(kiekis)+".txt";
    ofstream autoOut(outFileName);
    for (int i = 1; i <= kiekis; i++) {
        for (int j = 0; j < ndKiekis; j++) {
            vidurkis += balai(mt);
        }
        vidurkis /= 3.00;
        eilinis[i].vardas = "Vardas" + to_string(i);
        eilinis[i].pavarde = "Pavarde" + to_string(i);
        eilinis[i].egz = vidurkis;
        autoOut << left << setw(20) << eilinis[i].pavarde << setw(20) << eilinis[i].vardas << setw(20) << setprecision(3) << eilinis[i].egz << endl;
        vidurkis = 0;
    }
    return outFileName;
}
bool compareByLength(const Studentas& a, const Studentas& b)
{
    return a.vardas < b.pavarde;
}
bool maziau(const Studentas& a, const Studentas& b)
{
    return a.egz < b.egz;
}
void isvedimas(deque<Studentas> dekas, int kiekis, string failoPav = "rezultatai.txt") // isvedimas auto sugeneruotiems
{
    ofstream offile(failoPav);
    offile << "Pavarde             Vardas              Galutinis (egz.)\n";
    offile << "--------------------------------------------------------\n";

    for (Studentas d : dekas) {
        offile << left << setw(20) << d.vardas << setw(20) << d.pavarde << setw(20) << setprecision(3) << d.egz << endl;
    }

}
void isvedimas(list<Studentas>& listas, int kiekis, string failoPav = "rezultatai.txt") // isvedimas auto sugeneruotiems
{
    ofstream offile(failoPav);
    offile << "Pavarde             Vardas              Galutinis (egz.)\n";
    offile << "--------------------------------------------------------\n";

    for (Studentas l : listas) {
        offile << left << setw(20) << l.vardas << setw(20) << l.pavarde << setw(20) << setprecision(3) << l.egz << endl;
    }
}
void isvedimas(vector<Studentas> vektorius, int kiekis, string failoPav= "rezultatai.txt") // isvedimas auto sugeneruotiems
{
    ofstream offile(failoPav);
    offile << "Pavarde             Vardas              Galutinis (egz.)\n";
    offile << "--------------------------------------------------------\n";
    for (int i = 0; i < kiekis; i++) {
        offile << left << setw(20) << vektorius[i].pavarde << setw(20) << vektorius[i].vardas << setw(20) << setprecision(3) << vektorius[i].egz << endl;
    }

}
void isvedimas(vector<Studentas>& eilinis)
{
        ofstream offile("rezultatai.txt");
        offile << "Pavarde             Vardas              Galutinis (vid.)    Galutinis (med.)    \n";
        offile << "--------------------------------------------------------------------------------\n";
        for (int i = 0; i < eilinis.size(); i++) {
            offile << left << setw(20) << eilinis[i].pavarde << setw(20) << eilinis[i].vardas << setw(20) << setprecision(3) << eilinis[i].galVid << setw(20) << setprecision(2) << eilinis[i].galMed << endl;
        }
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
    if (dydis % 2 == 0)
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
void symbolCheck(double& skaicius, bool ok, bool balas)
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
double vectorSymbolCheck()
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
void boolCheck(bool& check)
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