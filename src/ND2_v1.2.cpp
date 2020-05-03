#include "Header.h"


int main()
{    
    bool check = false, balas = false, arNulis = false, arMediana = false, arFailas = false, arAuto = false, arGeneruoti = false, arClass = false;
    int ndKiekis, stKiekis = 0;
    string ndCheck = "";
    int ndCount = 0;

    StudentasClass studentasClass();

    vector<StudentasClass> eilinisClass;
    vector<StudentasClass> pabiruciaiClass;


    chrono::time_point<chrono::system_clock> start, end;
    chrono::time_point<chrono::system_clock> startEvent, endEvent;

    std::cout << "Ar norite generuoti failus ir atlikti skaiciavimus NAUDOJANT KLASES? (0 - ne, 1 - taip): "; // taip - v1.1
        /* Testing of vector */
        std::cout << "test of vector (class type): \n\n";

        // 100 000 irasu
        eilinisClass = {}; pabiruciaiClass = {}; // vektoriu isvalymas nuo praeitu irasu
        eilinisClass.clear(); pabiruciaiClass.clear();
        containerTestingVector_Class(pabiruciaiClass, eilinisClass, 100000);

        // 1 000 000 irasu
        eilinisClass = {}; pabiruciaiClass = {}; // vektoriu isvalymas nuo praeitu irasu
        eilinisClass.clear(); pabiruciaiClass.clear();
        containerTestingVector_Class(pabiruciaiClass, eilinisClass, 1000000);

                /* Testing of list */
        //        std::cout << "Test of List: \n\n";

        //dEilinis.push_back(studentas);
        //dPabiruciai.push_back(studentas);
        //dProtinguciai.push_back(studentas);

        //// 100 000 irasu
        //lEilinis = {}; lPabiruciai = {}; lProtinguciai = {};
        //lEilinis.clear(); lPabiruciai.clear(); lProtinguciai.clear();
        //containerTesting(lPabiruciai, lProtinguciai, lEilinis, 100000);

        //// 1 000 000 irasu
        //lEilinis = {}; lPabiruciai = {}; lProtinguciai = {};
        //lEilinis.clear(); lPabiruciai.clear(); lProtinguciai.clear();
        //containerTesting(lPabiruciai, lProtinguciai, lEilinis, 1000000);

                                /* Testing of deque */
        //std::cout << "Test of deque: \n\n";
        //dEilinis.push_back(studentas);
        //dPabiruciai.push_back(studentas);
        //dProtinguciai.push_back(studentas);

        // //100 000 irasu
        //dEilinis = {}; dPabiruciai = {}; dProtinguciai = {}; // listu isvalymas nuo praeitu irasu
        //dEilinis.clear(); dPabiruciai.clear(); dProtinguciai.clear();
        //containerTesting(dPabiruciai, dProtinguciai, dEilinis, 100000);

        // //1 000 000 irasu
        //dEilinis = {}; dPabiruciai = {}; dProtinguciai = {}; // listu isvalymas nuo praeitu irasu
        //dEilinis.clear(); dPabiruciai.clear(); dProtinguciai.clear();
        //containerTesting(dPabiruciai, dProtinguciai, dEilinis, 1000000);
    return 0;
}
