#include "acutest.h"
#include "Header.h"

    /// setValues() testas
    ///
    /// Testas, skirtas patikrinti ar teisingai priskiriamos reikšmės klasei - vardas
    void test_setVardas(void) {
        StudentasClass studentasClass;
        vector<StudentasClass> eilinisClass;

        eilinisClass.clear();
        eilinisClass.push_back(studentasClass);

        eilinisClass[0].setValues("Kvailelis", "Testauskas", 2, 3);

        TEST_CHECK(eilinisClass[0].getVardas() == "Kvailelis");
    }

    /// setValues() testas
    ///
    /// Testas, skirtas patikrinti ar teisingai priskiriamos reikšmės klasei - pavarde
    void test_setPavarde(void) {
        StudentasClass studentasClass;
        vector<StudentasClass> eilinisClass;

        eilinisClass.clear();
        eilinisClass.push_back(studentasClass);

        eilinisClass[0].setValues("Kvailelis", "Testauskas", 2, 3);

        TEST_CHECK(eilinisClass[0].getPavarde() == "Testauskas");
    }

    /// maziau_ForClass() testas
    ///
    /// Testas, skirtas patikrinti ar teisingai apskaičiuojama, kurio studento galutinis pažymys didesnis
    void test_maziau(void) {
        StudentasClass studentasClass;
        vector<StudentasClass> eilinisClass;

        eilinisClass.clear();
        eilinisClass.push_back(studentasClass);
        eilinisClass.push_back(studentasClass);

        eilinisClass[0].setValues("Kvailelis", "Testauskas", 2, 3);
        eilinisClass[1].setValues("Protingas", "Testauskas", 10, 9);
        eilinisClass[0].setGalutinis();
        eilinisClass[1].setGalutinis();

        bool arMaziau = maziau_ForClass(eilinisClass[0], eilinisClass[1]);

        TEST_CHECK(arMaziau == true);
    }

    TEST_LIST = {
        {"setVardas()_tikrinimas;", test_setVardas },
        {"setPavarde()_tikrinimas;", test_setPavarde },
        {"maziau()_tikrinimas;", test_maziau },
        {0}
    };