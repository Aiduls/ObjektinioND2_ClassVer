#include "acutest.h"
#include "Header.h"

StudentasClass studentasClass();
vector<StudentasClass> eilinisClass;

/// setValues() testas
///
/// Testas, skirtas patikrinti ar teisingai priskiriamos reikšmės klasei
void test_setValues(void){

    eilinisClass[0].setValues("Kvailelis", "Testauskas", 2, 3);

    TEST_CHECK(eilinisClass[0].getVardas() == "Kvailelis");
    TEST_CHECK(eilinisClass[0].getPavarde() == "Testauskas");
}

/// setGalutinis() testas
///
/// Testas, skirtas patikrinti ar teisingai apskaičiuojamas ir priskiriamas galutinis balas
void test_setGalutinis(void){

    eilinisClass[0].setValues("Kvailelis", "Testauskas", 2, 3);

    eilinisClass[0].setGalutinis();
    // Galutinis pažymys, kai vidurkis = 2, o egzaminas = 3, turi būti 
    // galutinis = 0.4 * vidurkis + 0.6 * egz = 0.4 * 2 + 0.6 * 3 = 2.6

    TEST_CHECK(eilinisClass[0].getGalutinis() == 2.6);
}

/// maziau_ForClass() testas
///
/// Testas, skirtas patikrinti ar teisingai apskaičiuojama, kurio studento galutinis pažymys didesnis
void test_maziau(void){

    eilinisClass[0].setValues("Kvailelis", "Testauskas", 2, 3);
    eilinisClass[1].setValues("Protingas", "Testauskas", 10, 9);
    eilinisClass[0].setGalutinis();
    eilinisClass[1].setGalutinis();

    bool arMaziau = maziau_ForClass(eilinisClass[0],eilinisClass[1]);

    TEST_CHECK(arMaziau == true);
}

TEST_LIST = {
    {"setValues()_tikrinimas;", test_setValues },
    {"setGalutinis()_tikrinimas;", test_setGalutinis },
    {"maziau()_tikrinimas;", test_maziau },
    {0}
};

