#include "Header.h"


int main()
{
    bool check = false, balas = false, arNulis = false, arMediana = false, arFailas = false, arAuto = false;
    int ndKiekis, stKiekis = 0;
    Studentas studentas;
    string ndCheck = "";
    int ndCount = 0;

    vector<Studentas> eilinis;

    cout << "Ar norite suvesti studento duomenis patys, ar nuskaityti juos is failo? Iveskite '0' jei norite ivesti patys, ir '1' jei norite vykdyti nuskaityma is failo: ";
    boolCheck(arFailas);

    if (arFailas) { // skaitomi is failo
        //failoNuskaitymas(eilinis, ndCheck, ndCount, stKiekis);
        ifstream infile("Studentai10000.txt");
        if (infile.is_open()) {
            string line, ignore;
            try {
                infile >> ignore >> ignore;
                infile >> line;
            }
            catch (std::exception &e){
                cout << "Ivyko klaida failo pirmos eilutes nuskaityme. \n";
            }
            
            ndCheck = ndCheck + line[0] + line[1];
            if (line.substr(0, 1) != "E" || line.substr(0, 1) != "e") { // tikrina ar pirmasis skaicius po pavardes nera egzaminas
                ndCount++;
                infile >> line;
                while (line.substr(0, 2) == ndCheck) { // skaiciuoja, kiek bus nd
                    infile >> line;
                    ndCount++;
                }
            }
            int ndPazymys;
            while (!infile.eof()) {
                try {
                    eilinis.push_back(Studentas());
                    infile >> eilinis[stKiekis].vardas;
                    infile >> eilinis[stKiekis].pavarde;

                    for (int i = 0; i < ndCount; i++) {
                        infile >> ndPazymys;
                        eilinis[stKiekis].ND.push_back(ndPazymys);
                    }
                    infile >> eilinis[stKiekis].egz;
                    stKiekis++;
                }
                catch (exception &e){
                    cout << "Klaida nuskaitant failo duomenis\n";
                }
                
            }
            infile.close();

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

        sort(eilinis.begin(), eilinis.end(), compareByLength); //sortas

        if (arMediana) {
            cout << "Pavarde:            Vardas:             Galutinis ivert.:\n";
            cout << "---------------------------------------------------------\n";
            cout << left << setw(20) << studentas.pavarde << setw(20) << studentas.vardas << setw(20) << fixed << setprecision(2) << studentas.galMed << endl;
        }
        else {
            cout << "Pavarde:            Vardas:             Galutinis ivert.:\n";
            cout << "---------------------------------------------------------\n";
            cout << left << setw(20) << studentas.pavarde << setw(20) << studentas.vardas << setw(20) << fixed << setprecision(2) << studentas.galVid << endl;
        }

    }
    return 0;
}
