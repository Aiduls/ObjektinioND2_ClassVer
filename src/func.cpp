#include "Header.h"

// deque testing
//void containerTesting(deque<Studentas>& pabiruciai, deque<Studentas>& protinguciai, deque<Studentas>& eilinis, int kiekis)
//{
//
//    chrono::time_point<chrono::system_clock> start, end;
//    chrono::time_point<chrono::system_clock> startEvent, endEvent;
//    chrono::duration<double> elapsed_seconds;
//
//    int protKiekis, pabirKiekis;
//    string failas;
//
//    eilinis.clear();
//    pabiruciai.clear();
//    protinguciai.clear();
//    startEvent = std::chrono::system_clock::now();
//    try {
//        failas = generuoti(eilinis, kiekis); // process
//    }
//    catch(std::exception & e) {
//        cout << "Ivyko klaida deque failo generavime \n";
//    }
//    eilinis.clear();
//    pabiruciai.clear();
//    protinguciai.clear();
//    try {
//        start = chrono::system_clock::now();
//        nuskaityti(eilinis, kiekis, failas);
//        end = std::chrono::system_clock::now();
//        elapsed_seconds = end - start;
//        cout << "Failo su " << kiekis << " duomenu nuskaitymas uztruko: " << elapsed_seconds.count() << "s\n";
//    }
//    catch (std::exception & e) {
//        cout << "Ivyko klaida deque failo nuskaityme \n";
//    }
//
//    try {
//        start = chrono::system_clock::now();
//        rusiuoti(eilinis);
//        //skirstyti(eilinis, pabiruciai, protinguciai);
//        skirstytiv2(eilinis, pabiruciai);
//        end = std::chrono::system_clock::now();
//        elapsed_seconds = end - start;
//        cout << "Failo su " << kiekis << " duomenu rusiavimas ir skirstymas i protingus ir pabirucius uztruko: " << elapsed_seconds.count() << "s\n";
//    }
//    catch (std::exception & e) {
//        cout << "Ivyko klaida deque failo rusiavime/skirstyme \n";
//    }
//    
//
//    string pavadinimasPabir = "pabiruciai" + to_string(kiekis) + ".txt";
//    string pavadinimasProt = "protinguciai" + to_string(kiekis) + ".txt";
//
//    try {
//        // 1 strat.
//        //isvedimas(protinguciai, pavadinimasProt);
//        //isvedimas(pabiruciai, pavadinimasPabir);
//
//        // 2 strat.
//        isvedimas(pabiruciai, pavadinimasProt);
//        isvedimas(eilinis, pavadinimasProt);
//    }
//    catch (std::exception & e) {
//        cout << "Ivyko klaida deque failo isvedime \n";
//    }
//
//
//    endEvent = std::chrono::system_clock::now();
//    elapsed_seconds = endEvent - startEvent;
//    cout << "Failo su " << kiekis << " duomenu procesai uztruko: " << elapsed_seconds.count() << "s\n\n";
//}

// list testing
//void containerTesting(list<Studentas>& pabiruciai, list<Studentas>& protinguciai, list<Studentas>& eilinis, int kiekis)
//{
//
//    chrono::time_point<chrono::system_clock> start, end;
//    chrono::time_point<chrono::system_clock> startEvent, endEvent;
//    chrono::duration<double> elapsed_seconds;
//
//    int protKiekis, pabirKiekis;
//    string failas;
//
//    eilinis.resize(kiekis);
//
//    startEvent = std::chrono::system_clock::now();
//    try {
//        failas = generuoti(eilinis, kiekis); // process
//    }
//    catch(std::exception & e) {
//        cout << "Ivyko klaida list failo generavime \n";
//    }
//    eilinis.clear();
//    try {
//        start = chrono::system_clock::now();
//        nuskaityti(eilinis, kiekis, failas);
//        end = std::chrono::system_clock::now();
//        elapsed_seconds = end - start;
//        cout << "Failo su " << kiekis << " duomenu nuskaitymas uztruko: " << elapsed_seconds.count() << "s\n";
//    }
//    catch (std::exception & e) {
//        cout << "Ivyko klaida list failo nuskaityme \n";
//    }
//
//    try {
//        start = chrono::system_clock::now();
//        rusiuoti(eilinis);
//        //skirstyti(eilinis, pabiruciai, protinguciai);
//        skirstytiv2(eilinis, pabiruciai);
//        end = std::chrono::system_clock::now();
//        elapsed_seconds = end - start;
//        cout << "Failo su " << kiekis << " duomenu rusiavimas ir skirstymas i protingus ir pabirucius uztruko: " << elapsed_seconds.count() << "s\n";
//    }
//    catch (std::exception & e) {
//        cout << "Ivyko klaida list failo rusiavime ir skaityme \n";
//    }
//
//
//    string pavadinimasPabir = "pabiruciai" + to_string(kiekis) + ".txt";
//    string pavadinimasProt = "protinguciai" + to_string(kiekis) + ".txt";
//
//    try {
//        // 1-oji strategija
//       // isvedimas(pabiruciai, pavadinimasPabir);
//       // isvedimas(protinguciai, pavadinimasProt);
//
//        // 2-oji strategija 
//        isvedimas(pabiruciai, pavadinimasPabir);
//        isvedimas(eilinis, pavadinimasProt);
//    }
//    catch (std::exception & e) {
//        cout << "Ivyko klaida list failo rusiavime ir skaityme \n";
//    }
//
//
//    endEvent = std::chrono::system_clock::now();
//    elapsed_seconds = endEvent - startEvent;
//    cout << "Failo su " << kiekis << " duomenu procesai uztruko: " << elapsed_seconds.count() << "s\n\n";
//}

// vector testing 
void containerTesting(vector<Studentas>& pabiruciai, vector<Studentas>& protinguciai, vector<Studentas>& eilinis, int kiekis) 
{
    eilinis.reserve(kiekis);
    pabiruciai.reserve(kiekis);
    //protinguciai.reserve(kiekis);

    chrono::time_point<chrono::system_clock> start, end;
    chrono::time_point<chrono::system_clock> startEvent, endEvent;
    chrono::duration<double> elapsed_seconds;

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
        rusiuoti(eilinis);
       // skirstyti(eilinis, pabiruciai, protinguciai);
       //skirstytiv2(eilinis, pabiruciai);
        skirstytiv3(eilinis, pabiruciai);
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
        // Pirma strategija (2 nauju vektoriu isvedimas) - reikalinga naudoti skirstyti()
        //isvedimas(pabiruciai, pavadinimasPabir);
        //isvedimas(protinguciai, pavadinimasProt);

        // Antra strategija (pabiruciu ir originalaus vektoriaus (vietoj protinguciu)) isvedimas - reikalinga naudoti skirstytiv2()
        isvedimas(pabiruciai, pavadinimasPabir);
        isvedimas(eilinis, pavadinimasProt);
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo isvedime \n";
    }

    endEvent = std::chrono::system_clock::now();
    elapsed_seconds = endEvent - startEvent;
    cout << "Failo su " << kiekis << " duomenu procesai uztruko: " << elapsed_seconds.count() << "s\n\n";
}
void containerTestingVector_Class(vector<StudentasClass>& pabiruciai, vector<StudentasClass>& eilinis, int kiekis)
{
    eilinis.reserve(kiekis);
    pabiruciai.reserve(kiekis);
    //protinguciai.reserve(kiekis);

    chrono::time_point<chrono::system_clock> start, end;
    chrono::time_point<chrono::system_clock> startEvent, endEvent;
    chrono::duration<double> elapsed_seconds;

    string failas;

    startEvent = std::chrono::system_clock::now();
    try {
        failas = generuoti_ForClass(kiekis); // process
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo generavime \n";
    }

    try {
        start = chrono::system_clock::now();
        nuskaityti_ForClass(eilinis, kiekis, failas);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        cout << "Failo su " << kiekis << " duomenu nuskaitymas uztruko: " << elapsed_seconds.count() << "s\n";
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo nuskaityme \n";
    }
    try {
        calculateFinal_ForClass(eilinis,kiekis);
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo rusiavime/skirstyme \n";
    }

    try {
        start = chrono::system_clock::now();
        rusiuoti_ForClass(eilinis);
        // skirstyti(eilinis, pabiruciai, protinguciai);
        //skirstytiv2(eilinis, pabiruciai);
        skirstytiv3_ForClass(eilinis, pabiruciai);
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
        // Pirma strategija (2 nauju vektoriu isvedimas) - reikalinga naudoti skirstyti()
        //isvedimas(pabiruciai, pavadinimasPabir);
        //isvedimas(protinguciai, pavadinimasProt);

        // Antra strategija (pabiruciu ir originalaus vektoriaus (vietoj protinguciu)) isvedimas - reikalinga naudoti skirstytiv2()
        isvedimas_ForClass(pabiruciai, pavadinimasPabir);
        isvedimas_ForClass(eilinis, pavadinimasProt);
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo isvedime \n";
    }

    endEvent = std::chrono::system_clock::now();
    elapsed_seconds = endEvent - startEvent;
    cout << "Failo su " << kiekis << " duomenu procesai uztruko: " << elapsed_seconds.count() << "s\n\n";
}

std::ostream& operator<<(std::ostream& offile, vector<StudentasClass>& vektorius) {
    offile << "Pavarde             Vardas              Galutinis balas \n";
    offile << "--------------------------------------------------------\n";
    for (int i = 0; i < vektorius.size(); i++) {
        offile << left << setw(20) << vektorius[i].getPavarde() << setw(20) << vektorius[i].getVardas() << setw(20) << setprecision(3) << vektorius[i].getGalutinis() << endl;
    }
    return offile;
}

void skirstytiv2(deque<Studentas>& eilinis, deque<Studentas>& pabiruciai)
{
    try {
        for (int i = 0; i < eilinis.size(); i++) {
            if (eilinis[i].egz < 5.00) {
                pabiruciai.push_back(eilinis[i]);
            }
            else {
                eilinis.erase(eilinis.begin(), eilinis.begin() + i);
                break;
            }
        }
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo skirstyme \n";
    }
}
void skirstyti(deque<Studentas>& eilinis, deque<Studentas>& pabiruciai, deque<Studentas>& protinguciai)
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
void skirstytiv2(list<Studentas>& eilinis, list<Studentas>& pabiruciai)
{
        //iteratorius, rodantis i pirma listo elementa, kuriame egz = 5
    list<Studentas>::iterator it = std::find_if(eilinis.begin(), eilinis.end(), compare_5);
    // splice'as i pabirucius (nes pabiruciai.splice() ) iraso kazkiek irasu (pradedant nuo [0]) is [1], kuriame pradeda nuo [2] ir baigia [3]
    pabiruciai.splice(pabiruciai.begin(), eilinis, eilinis.begin(), it);

}
void skirstyti(list<Studentas>& eilinis, list<Studentas>& pabiruciai, list<Studentas>& protinguciai)
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
bool compare_5_ForClass(const StudentasClass& v)
{
    return v.getGalutinis() == 5.00;
}
bool compare_5(const Studentas& v)
{
    return v.egz == 5.00;
}
void skirstytiv3_ForClass(vector<StudentasClass>& eilinis, vector<StudentasClass>& pabiruciai)
{
    try {
        vector<StudentasClass>::iterator it = std::find_if(eilinis.begin(), eilinis.end(), compare_5_ForClass); // iteratorius, rodantis i reikiama perkirsti vieta

        pabiruciai = std::vector<StudentasClass>(eilinis.begin(), it); // nukopijuoja
        eilinis.erase(eilinis.begin(), it);                      // istrina is eilinio pabirucius, kad gautusi protinguciai
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo skirstyme \n";
    }
}
void skirstytiv3(vector<Studentas>& eilinis, vector<Studentas>& pabiruciai)
{
    try {
        vector<Studentas>::iterator it = std::find_if(eilinis.begin(), eilinis.end(), compare_5); // iteratorius, rodantis i reikiama perkirsti vieta

        pabiruciai = std::vector<Studentas>(eilinis.begin(),it); // nukopijuoja
        eilinis.erase(eilinis.begin(), it);                      // istrina is eilinio pabirucius, kad gautusi protinguciai
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo skirstyme \n";
    }
}
void skirstytiv2(vector<Studentas>& eilinis, vector<Studentas>& pabiruciai)
{
    try {
        for (int i = 0; i < eilinis.size(); i++) {
            if (eilinis[i].egz < 5.00) {
                pabiruciai.push_back(eilinis[i]);
            }
            else {
                eilinis.erase(eilinis.begin(), eilinis.begin() + i);
                break;
            }
        }
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo skirstyme \n";
    }
}
void skirstyti(vector<Studentas>& eilinis, vector<Studentas> &pabiruciai, vector<Studentas> &protinguciai)
{
    for (int i = 0; i < eilinis.size(); i++) {
        if (eilinis[i].egz < 5.00) {
            pabiruciai.push_back(eilinis[i]);
        }
        else {
            protinguciai.push_back(eilinis[i]);
        }
    }
}

void rusiuoti(deque<Studentas>& eilinis)
{
    sort(eilinis.begin(), eilinis.end(), maziau);
}
void rusiuoti(list<Studentas>& eilinis)
{
    eilinis.sort(maziau);
}
void rusiuoti_ForClass(vector<StudentasClass>& eilinis)
{
    try {
        sort(eilinis.begin(), eilinis.end(), maziau_ForClass);
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo rusiavime \n";
    }
}
void rusiuoti(vector<Studentas>& eilinis)
{
    try {
        sort(eilinis.begin(), eilinis.end(), maziau);
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo rusiavime \n";
    }
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
void calculateFinal_ForClass(vector<StudentasClass>& eilinis, int kiekis)
{
    try {
        for (int i = 0; i < kiekis; i++) {
            eilinis[i].setGalutinis();
        }
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo galutinio balo set'inime \n";
    }
}
void nuskaityti_ForClass(vector<StudentasClass>& eilinis, int kiekis, string failas)
{
    try {
        std::ifstream autoIn(failas);
        eilinis.clear(); // nunullinam struktura
        eilinis.reserve(kiekis);
        eilinis.resize(kiekis);
        string vardas, pavarde;
        double vidurkis;
        int egzaminas;

        for (int i = 0; i < kiekis; i++) {
            autoIn >> pavarde >> vardas >> vidurkis >> egzaminas;
            eilinis[i].setValues(vardas, pavarde, vidurkis, egzaminas);
        }
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo nuskaityme \n";
    }
}
void nuskaityti(vector<Studentas>& eilinis, int kiekis, string failas)
{
    try {
        ifstream autoIn(failas);
        eilinis = {}; // nunullinam struktura
        eilinis.reserve(kiekis);
        eilinis.resize(kiekis);

        for (int i = 0; i < kiekis; i++) {
            autoIn >> eilinis[i].pavarde >> eilinis[i].vardas >> eilinis[i].egz;
        }
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo nuskaityme \n";
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
string generuoti_ForClass(int kiekis)
{
    int ndKiekis = 3, iCounter = 0;
    try {
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> balai(1.0, 10.0);
        double vidurkis = 0, egzaminas;
        string outFileName = "autoOut" + to_string(kiekis) + ".txt";
        ofstream autoOut(outFileName);

        string vardas, pavarde;
        for (int i = 0; i < kiekis; i++) {
            for (int j = 0; j < ndKiekis; j++) {
                vidurkis += balai(mt);
            }
            iCounter++;
            vidurkis /= 3.00;
            vardas = "Vardas" + to_string(iCounter);
            pavarde = "Pavarde" + to_string(iCounter);
            egzaminas = balai(mt);

            autoOut << left << setw(20) << pavarde << setw(20) << vardas << setw(20) << setprecision(3) << vidurkis << egzaminas << endl;
            vidurkis = 0;
        }
        return outFileName;
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo generavime \n";
    }
}
string generuoti(vector<Studentas>& eilinis, int kiekis)
{
    int ndKiekis = 3, iCounter = 0;
    eilinis = {}; // nunullinam struktura
    try {
        random_device rd;
        mt19937 mt(rd());
        uniform_real_distribution<double> balai(1.0, 10.0);
        double vidurkis = 0;
        string outFileName = "autoOut" + to_string(kiekis) + ".txt";
        ofstream autoOut(outFileName);
        for (int i = 0; i < kiekis; i++) {
            for (int j = 0; j < ndKiekis; j++) {
                vidurkis += balai(mt);
            }
            iCounter++;
            vidurkis /= 3.00;
            eilinis[i].vardas = "Vardas" + to_string(iCounter);
            eilinis[i].pavarde = "Pavarde" + to_string(iCounter);
            eilinis[i].egz = vidurkis;
            autoOut << left << setw(20) << eilinis[i].pavarde << setw(20) << eilinis[i].vardas << setw(20) << setprecision(3) << eilinis[i].egz << endl;
            vidurkis = 0;
        }
        return outFileName;
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo generavime \n";
    }
    
}
bool compareByLength(const Studentas& a, const Studentas& b)
{
    return a.vardas < b.pavarde;
}
bool maziau_ForClass(const StudentasClass& a, const StudentasClass& b)
{
    return a.getGalutinis() < b.getGalutinis();
}
bool maziau(const Studentas& a, const Studentas& b)
{
    return a.egz < b.egz;
}
void isvedimas(deque<Studentas> dekas, string failoPav = "rezultatai.txt") // isvedimas auto sugeneruotiems
{
    ofstream offile(failoPav);
    offile << "Pavarde             Vardas              Galutinis (egz.)\n";
    offile << "--------------------------------------------------------\n";

    for (Studentas d : dekas) {
        offile << left << setw(20) << d.vardas << setw(20) << d.pavarde << setw(20) << setprecision(3) << d.egz << endl;
    }

}
void isvedimas(list<Studentas>& listas, string failoPav = "rezultatai.txt") // isvedimas auto sugeneruotiems
{
    ofstream offile(failoPav);
    offile << "Pavarde             Vardas              Galutinis (egz.)\n";
    offile << "--------------------------------------------------------\n";

    for (Studentas l : listas) {
        offile << left << setw(20) << l.vardas << setw(20) << l.pavarde << setw(20) << setprecision(3) << l.egz << endl;
    }
}
void isvedimas_ForClass(vector<StudentasClass> vektorius, string failoPav = "rezultatai.txt") // isvedimas auto sugeneruotiems
{
    try {
        std::ofstream offile(failoPav);
        offile << vektorius;
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo isvedime \n";
    }
}
void isvedimas(vector<Studentas> vektorius, string failoPav= "rezultatai.txt") // isvedimas auto sugeneruotiems
{
    try {
        ofstream offile(failoPav);
        offile << "Pavarde             Vardas              Galutinis (egz.)\n";
        offile << "--------------------------------------------------------\n";
        for (int i = 0; i < vektorius.size(); i++) {
            offile << left << setw(20) << vektorius[i].pavarde << setw(20) << vektorius[i].vardas << setw(20) << setprecision(3) << vektorius[i].egz << endl;
        }
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo isvedime \n";
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