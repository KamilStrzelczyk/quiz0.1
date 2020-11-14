//Program wczytuje plik 
//Losuje zestaw pytan 
//Sumuje punkty 
//Wymazuje komunikaty
//zmienia automatycznie wpisana odpowiedz uzytkownika

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <time.h>
#include <windows.h>
std::string imie, linia, zestaw;
std::string odpA[5], odpB[5], odpC[5], odpD[5], poprawna[5], odpowiedz, tresc[5];
int  punkty = 0, nr_pytania = 0, nr_lini = 1, liczba;


int main()
{

	std::cout << "Witaj w naszym quizzie\n";
	Sleep(1000);
	system("cls");
	std::cout << "Powiedz nam jak sie nazywasz: \n";
	std::cin >> imie;
	Sleep(1500);
	system("cls");
	std::cout << "Dobrze " << imie << " czas zaczynac nasz teleturniej!" << std::endl;
	Sleep(1500);
	system("cls");
	std::cout << "Teraz nastapi wylosowanie puli pytan\n";
	Sleep(2000);
	system("cls");
	// inicjator liczb losowych
	srand(time(NULL));
	liczba = rand() % 2 + 1;
	auto konwertliczby = std::to_string(liczba);
	zestaw = konwertliczby + "milionerzy.txt";
	std::cout << "Wylosowales zestaw nr: " << liczba;
	Sleep(1500);
	system("cls");
	std::fstream plik; // instrukcja otwarcia pliku i komunikatu o błedzie 
	plik.open(zestaw, std::ios::in);
	{
		if (plik.good() == false)
		{
			std::cout << "ooooooj poczekaj poczekaj mamy problem \n";
			exit(0);
		}
	}



	while (getline(plik, linia)) // pętla wczytująca dane z pliku tekstowego 
	{
		switch (nr_lini)
		{
		case    1: tresc[nr_pytania] = linia; break;
		case    2: odpA[nr_pytania] = linia; break;
		case    3: odpB[nr_pytania] = linia; break;
		case    4: odpC[nr_pytania] = linia; break;
		case    5: odpD[nr_pytania] = linia; break;
		case    6: poprawna[nr_pytania] = linia; break;
		}
		if (nr_lini == 6)
		{
			nr_lini = 0; nr_pytania++;
		}
		nr_lini++;

	}
	plik.close();

	for (int i = 0; i <= 4; i++)
	{
		std::cout << std::endl << tresc[i] << std::endl;
		std::cout << "A. " << odpA[i] << std::endl;
		std::cout << "B. " << odpB[i] << std::endl;
		std::cout << "C. " << odpC[i] << std::endl;
		std::cout << "D. " << odpD[i] << std::endl;

		std::cout << "twoja odpowiedz: ";
		std::cin >> odpowiedz;
		transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(), ::tolower);

		if (odpowiedz == poprawna[i])
		{
			std::cout << "dobrze zdobywasz punkt!" << std::endl;
			punkty++;
		}
		else {
			std::cout << "Zle! Brak punktu! Poprawna odpowiedz: " << poprawna[i] << std::endl;
		}
		Sleep(1000);
		system("cls");
	}
	std::cout << "Koniec quizu! Zdobyte punkty: " << punkty;
	if (punkty == 5)
	{
		std::cout << "\n Gratulujemy wygrales okragla banke!\n";
	}
	else
	{
		std::cout << "\n No niestety nie udzielenie na wszyskie pytania poprawnie skutkuje usunienciem Cie ze studia";
	}
	getchar(); getchar();

}

