#include "Header.h"


int main()
{    
    bool check = false, balas = false, arNulis = false, arMediana = false, arFailas = false, arAuto = false, arGeneruoti;
    int ndKiekis, stKiekis = 0;
    string ndCheck = "";
    int ndCount = 0;

    Studentas studentas;

    vector<Studentas> eilinis;
    vector<Studentas> pabiruciai;
    vector<Studentas> protinguciai;

    list<Studentas> lEilinis;
    list<Studentas> lPabiruciai;
    list<Studentas> lProtinguciai;

    deque<Studentas> dEilinis;
    deque<Studentas> dPabiruciai;
    deque<Studentas> dProtinguciai;

    chrono::time_point<chrono::system_clock> start, end;
    chrono::time_point<chrono::system_clock> startEvent, endEvent;

    cout << "Ar norite generuoti studento failus automatiskai ir is ju skaityti duomenis, ar duomanu negeneruoti? (0 - negeneruoti, 1 - generuoti): ";
    boolCheck(arGeneruoti);
    chrono::duration<double> elapsed_seconds;

    if (arGeneruoti) {

                /* Testing of vector */
        cout << "test of vector: \n\n";

               /* 1000 irasu */
        eilinis.push_back(studentas);
        pabiruciai.push_back(studentas);
        protinguciai.push_back(studentas);

        containerTesting(pabiruciai, protinguciai, eilinis, 1000);

            // 10 000 irasu
        eilinis = {}; pabiruciai = {}; protinguciai = {}; // vektoriu isvalymas nuo praeitu irasu
        eilinis.clear(); pabiruciai.clear(); protinguciai.clear();
        containerTesting(pabiruciai, protinguciai, eilinis, 10000);

        // 100 000 irasu
        eilinis = {}; pabiruciai = {}; protinguciai = {}; // vektoriu isvalymas nuo praeitu irasu
        eilinis.clear(); pabiruciai.clear(); protinguciai.clear();
        containerTesting(pabiruciai, protinguciai, eilinis, 100000);

        // 1 000 000 irasu
        eilinis = {}; pabiruciai = {}; protinguciai = {}; // vektoriu isvalymas nuo praeitu irasu
        eilinis.clear(); pabiruciai.clear(); protinguciai.clear();
        containerTesting(pabiruciai, protinguciai, eilinis, 1000000);
        
        // 10 000 000 irasu
        eilinis = {}; pabiruciai = {}; protinguciai = {}; // vektoriu isvalymas nuo praeitu irasu
        eilinis.clear(); pabiruciai.clear(); protinguciai.clear();
        containerTesting(pabiruciai, protinguciai, eilinis, 10000000);

                        /* Testing of list */
        //        cout << "Test of List: \n\n";
        //lEilinis.push_back(studentas);
        //lPabiruciai.push_back(studentas);
        //lProtinguciai.push_back(studentas);
        //// 1 000 irasu
        //containerTesting(lPabiruciai, lProtinguciai, lEilinis, 1000);

        //// 10 000 irasu
        //lEilinis = {}; lPabiruciai = {}; lProtinguciai = {}; // listu isvalymas nuo praeitu irasu
        //lEilinis.clear(); lPabiruciai.clear(); lProtinguciai.clear();
        //containerTesting(lPabiruciai, lProtinguciai, lEilinis, 10000);

        //// 100 000 irasu
        //lEilinis = {}; lPabiruciai = {}; lProtinguciai = {};
        //lEilinis.clear(); lPabiruciai.clear(); lProtinguciai.clear();
        //containerTesting(lPabiruciai, lProtinguciai, lEilinis, 100000);

        //// 1 000 000 irasu
        //lEilinis = {}; lPabiruciai = {}; lProtinguciai = {};
        //lEilinis.clear(); lPabiruciai.clear(); lProtinguciai.clear();
        //containerTesting(lPabiruciai, lProtinguciai, lEilinis, 1000000);

        //lEilinis = {}; lPabiruciai = {}; lProtinguciai = {};
        //lEilinis.clear(); lPabiruciai.clear(); lProtinguciai.clear();
        //// 10 000 000 irasu
        //lEilinis = {}; lPabiruciai = {}; lProtinguciai = {};
        //lEilinis.clear(); lPabiruciai.clear(); lProtinguciai.clear();
        //containerTesting(lPabiruciai, lProtinguciai, lEilinis, 10000000);

                                /* Testing of deque */ 
        //cout << "Test of deque: \n\n";
        //dEilinis.push_back(studentas);
        //dPabiruciai.push_back(studentas);
        //dProtinguciai.push_back(studentas);
        //// 1 000 irasu
        //containerTesting(dPabiruciai, dProtinguciai, dEilinis, 1000);

        // //10 000 irasu
        //dEilinis = {}; dPabiruciai = {}; dProtinguciai = {}; // listu isvalymas nuo praeitu irasu
        //dEilinis.clear(); dPabiruciai.clear(); dProtinguciai.clear();
        //containerTesting(dPabiruciai, dProtinguciai, dEilinis, 10000);

        // //100 000 irasu
        //dEilinis = {}; dPabiruciai = {}; dProtinguciai = {}; // listu isvalymas nuo praeitu irasu
        //dEilinis.clear(); dPabiruciai.clear(); dProtinguciai.clear();
        //containerTesting(dPabiruciai, dProtinguciai, dEilinis, 100000);

        // //1 000 000 irasu
        //dEilinis = {}; dPabiruciai = {}; dProtinguciai = {}; // listu isvalymas nuo praeitu irasu
        //dEilinis.clear(); dPabiruciai.clear(); dProtinguciai.clear();
        //containerTesting(dPabiruciai, dProtinguciai, dEilinis, 1000000);

        // //10 000 000 irasu
        //dEilinis = {}; dPabiruciai = {}; dProtinguciai = {}; // listu isvalymas nuo praeitu irasu
        //dEilinis.clear(); dPabiruciai.clear(); dProtinguciai.clear();
        //containerTesting(dPabiruciai, dProtinguciai, dEilinis, 10000000);
        
    }
    else {
        cout << "\nAr norite suvesti studento duomenis patys, ar nuskaityti juos is failo? Iveskite '0' jei norite ivesti patys, ir '1' jei norite vykdyti nuskaityma is failo: ";
        boolCheck(arFailas);

        if (arFailas) { // skaitomi is failo
            //failoNuskaitymas(eilinis, ndCheck, ndCount, stKiekis);
            ifstream infile("Studentai10000.txt");
            if (infile.is_open()) { // paprastuju failu nuskaitymas
                string line, ignore;
                try {
                    infile >> ignore >> ignore;
                    infile >> line;
                }
                catch (std::exception & e) {
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
                    catch (exception & e) {
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
            
                chrono::time_point<chrono::system_clock> start, end;
                start = chrono::system_clock::now();
                isvedimas(eilinis);                         // isvedimas
                end = std::chrono::system_clock::now();
                chrono::duration<double> elapsed_seconds = end - start;
                cout << "Time elapsed: " << elapsed_seconds.count() << "s\n";
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

    }

    return 0;
}
