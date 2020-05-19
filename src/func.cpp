#include "Header.h"

/// Vektoriaus klasės testavimas
/// Iš šios pagrindinės funkcijos kviečiami visi kiti procesai kaip duomenų generavimas, sortinimas, išvedimas ir t.t.
void containerTestingVector_Class(vector<StudentasClass>& pabiruciai, vector<StudentasClass>& eilinis, int kiekis)
{
    eilinis.reserve(kiekis);
    pabiruciai.reserve(kiekis);

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
        // Antra strategija (pabiruciu ir originalaus vektoriaus (vietoj protinguciu)) isvedimas - reikalinga naudoti skirstytiv3()
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

/// Overloadintas operatorius, išvedantis visus studentus
std::ostream& operator<<(std::ostream& offile, vector<StudentasClass>& vektorius) {
    offile << "Pavarde             Vardas              Galutinis balas \n";
    offile << "--------------------------------------------------------\n";
    for (int i = 0; i < vektorius.size(); i++) {
        offile << left << setw(20) << vektorius[i].getPavarde() << setw(20) << vektorius[i].getVardas() << setw(20) << setprecision(3) << vektorius[i].getGalutinis() << endl;
    }
    return offile;
}

/// Funkcija, grąžinanti nuo kurio nr. studento prasideda vidurkiai, lygūs 5
bool compare_5_ForClass(const StudentasClass& v)
{
    return v.getGalutinis() == 5.00;
}

/// Išskirsto bendrą studentų sąrašą į prastesnių ir geresnių
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
/// Surūšiuoja bendrą studentų sąrašą nuo prasčiausio pažymio iki geriausio
void rusiuoti_ForClass(vector<StudentasClass>& eilinis)
{
    try {
        sort(eilinis.begin(), eilinis.end(), maziau_ForClass);
    }
    catch (std::exception & e) {
        cout << "Ivyko klaida vector failo rusiavime \n";
    }
}

/// Apskaičiuoja galutinį balą kiekvienam studentui
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

/// Nuskaito sugeneruotą studentų failą
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

/// Sugeneruoja studentų failą
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

/// Loginė funkcija, nurodanti kuris iš duotų studentų turi mažesnį galutinį balą
bool maziau_ForClass(const StudentasClass& a, const StudentasClass& b)
{
    return a.getGalutinis() < b.getGalutinis();
}

/// Išveda paduotą studentų sarašą
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

/// Overloadintas operatorius, prilyginantis dabartiniam studentui paduotus duomenis
StudentasClass& StudentasClass::operatorEQUALS(const StudentasClass& gc1) {
    if (this == &gc1)
        return *this;
    this->vardas = gc1.vardas;
    this->pavarde = gc1.pavarde;
    this->vidurkis = gc1.vidurkis;
    this->egz = gc1.egz;
    return *this;
}