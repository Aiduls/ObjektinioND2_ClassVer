# Studentų rezultatų skaičiavimo programa
### Diegimo instrukcija (UNIX platformoms):

1. Parsisiųskite naujausią release'ą

2. Terminale parašykite komandą `make`

3. Jei naujai sukurtas Application paleidžiamasis failas nepasileidžia, Terminale padarykite jį paleidžiamuoju - komanda `chmod a+x hello`

4. Paleiskite programą komanda `./Application` arba rankiniu būdu.

5. Norėdami išvalyti sukurtus failus naudokite komandą `make clean`

   Jei diegimas nepavyksta ar programą norite pasileisti ant Windows platformos, po pirmo punkto reiktų susidėti ND2_1.0.cpp, func.cpp ir Header.h failus į naudojamo IDE projektą (rekomenduojama Visual Studio 2019, x64 versija) ir pasileisti taip.

### Versijų registras:

### v0.1:

1. Programa surenka žmogaus įrašytus duomenis: vardą, pavardę, namų darbų kiekį ir jų pažymius, egzamino pažymį. 
2. Programoje yra apsauga nuo neteisingo formato duomenų įvedimo, tad kai vietoj skaičius bus įvedamas simbolis, programa apie tai praneš ir lieps įvesti dar kartą, o ne 'suluš'. 

#### v0.1.1

1. Papildomai prie ankstesnių programos galimybių, dabar, vartotojui pasirinkus, studento pažymiai ir jų kiekiai gali būti sugeneruojami atsitiktinai
2. Vietoje C masyvo naudojamas vektorius.
3. Studento duomenys saugojami struktūroje.

### v0.2

1. Dabar studentų duomenys taip pat gali būti nuskaitomi iš failo.
2. Išvedamos visų studentų medianos bei vidurkiai.

### v0.3

1. Naudojami exceptionai, try ir catch metodai.
2. Programa suskirstyta į kelis failus: ND2 v0.3.cpp, kuris atlieka pagrindines funkcijas, funkcijų faila func.cpp ir antraščių faila Header.h .

### v0.4

1. Pasirinkus parinktį, programa automatiškai:
	1. Sugeneruos 5 studentų failus (1k, 10k, 100k, 1M, 10M failus);
	2. Nuskaitys iš failų duomenis į struktūras;
	3. Surūšiuos studentus pagal pažymius;
	4. Išskirstys studentus į pabiručius (vidurkis < 5) ir protingučius (vidurkis >= 5);
	5. Išves atskirus pabiručių ir protingučių failus.
2. Norint pasileisti programą: 
	1. Rekomenduojama tiesiog pasileisti "VS_ND2.exe" failą. Nieko daugiau redaguoti nereikia.
	2. Taip pat galima susidėti 3 failus (ND2_v0.4.cpp, func.cpp, Header.h) į bendrą projektą ir jį pasileisti programavimo aplinkoje, pvz. Visual Studio 2019.
	3. Terminale pasigaminti (make) makefile'ą ir jį parunninti
3. Programos veikimo laiką kūrimo aplinkoje galima rasti nuotraukoje "konsolev0.4.png"

### v0.5

1. Dabar duomenys talpinami ne tik vektoriuje, bet ir list bei deque konteineriuose.
2. Skaičiuojami programos veikimo procesai atskirai kiekviename konteineryje (nuskaitymas, rusiavimas ir skirstymas, bendras apdorojimo laikas). Rezultatai, gauti ant testavimo sistemos, matomi faile konsolev0.5.png.
3. Testavimo sistemos parametrai:
   CPU: Intel Core i7-9750H, 6 cores
   RAM: 16GB RAM, 1 Socket
   SSD: 512GB.
4. Programa kurta ir testuota ant Windows 64bit platformos, MS Visual Studio x64. Rekomenduojama bandyti ant tokių pačių (x64) parametrų.

####  v0.5.1

1. Pataisyta 0.5 versija. Dabar programa kokybiškai apdoroja duomenis ir list, ir deque sąrašuose.
2. Pridėtas programos procesų veikimo laiko screenshot'as - konsolev0.5.png.

### v1.0

1. Procesams vykdyti naudojamos dvi strategijos: iš bendro konteinerio išskirstyti į du papildomus ir iš bendro konteinerio išrinkti prastesnius, o bendrame palikti geresnius. Visi šie skirtumai laiko ir atminties atžvilgiu aprašyti additionalData/usageData.txt faile, o papildomos nuotraukos su rezultatais yra additionalData aplanke.
2. Vektorių konteineriuose skirstant studentus padidintas efektyvumas naudojant find_if() ir iteratorius.
3. Pridėtas Makefile, skirtas UNIX sistemoms.