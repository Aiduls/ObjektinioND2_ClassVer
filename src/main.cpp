#include "Header.h"

/// Pagrindinė programos funkcija
///
/// Deklaruojamos reikiamos reikšmės, klasės, pradedamas skaičiuoti bendras laikas. Kviečiamos testavimo funkcijos.
int main()
{    
    StudentasClass studentasClass();

    vector<StudentasClass> eilinisClass;
    vector<StudentasClass> pabiruciaiClass;


    //chrono::time_point<chrono::system_clock> start, end;
    //chrono::time_point<chrono::system_clock> startEvent, endEvent;

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

    return 0;
}
