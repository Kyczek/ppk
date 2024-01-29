/*!
* @file spedycja.cpp
* @brief Plik główny programu wykonujacego zadanie spedycja.
*
* Plik spedycja.cpp zawiera implementacje glownego programu. 
* Wykorzystuje on funkcje zdeklarowane w pliku "plik_s.h" oraz zdefiniowane w pliku "plik_s.cpp".
* Program wczytuje dane na temat polaczen miast i ich odleglosci z pliku wejsciowego oraz na podstawie podanego miasta startowego,
* gdzie znajduje sie centrala, a nastepnie oblicza najkrotsze mozliwe trasy korzystajac z algorytmu Dijkstry.
* Wyniki programu zapisywane są do pliku wyjsciowego.
* 
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include "plik_s.h"





/**
* @brief Glowna funkcja programu.
*
* Funkcja poczatkowo sprawdza poprawnosc argumentow przekazanych do programu. W przypadku niepoprawnej liczby argumentow, 
* program wyswietla informacje o poprawnym wpisaniu argumentow i konczy swoje wykonanie z kodem bledu.
* W sytuacji prawidlowego odczytu tworzy zmienne w celu przechowywania nazwy pliku wejsciowego,wyjsciowego oraz miasta centrali.
* Nastepnie dla odpowiednich przelacznikow zapisywane sa podane nazwy do zmiennych, w przypadku blednych przelacznikow program sie zakonczy z kodem bledu.
* Po podaniu wlasciwych przelacznikow program wywoluje funkcje niezbedne do prawidlowego dzialania programu.
* Po zakonczeniu dzialania funkcji "SaveToFile" wyniki zostaną zapisane do pliku wyjsciowego a program zakonczy sie kodem sukcesu.
*  
* 
* @param argc Liczba argumentow przekazanych do programu.
* @param carg Tablica argumentow przekazanych do programu.
* @return Program zwraca 0 w sytuacji poprawnego wykonania oraz 1 w przypadku wystapienia bledu.
* @see LoadFromFile
* @see Dijkstra
* @see SaveToFile
*/ 
int main(int argc, char** carg)
{
    
    if (argc != 7)
    {
        std::cout << carg[0] << " -i plik wejsciowy z drogami, -o plik wyjsciowy z trasami spedycyjnymi, -s nazwa miasta startowego, gdzie znajduje sie centrala" << std::endl;
        return 1;
    }


    std::string inputfile, outputfile, centrala;        
    for (int i = 1; i < argc; i += 2)
    {

        if (std::string(carg[i]) == "-i")
        {
            inputfile = carg[i + 1];
            std::cout << "pobrano nazwe pliku wejsciowego" << std::endl;
        }
        else if (std::string(carg[i]) == "-o")
        {
            outputfile = carg[i + 1];
            std::cout << "pobrano nazwe pliku wyjsciowego" << std::endl;
        }
        else if (std::string(carg[i]) == "-s")
        {
            centrala = carg[i + 1];
            std::cout << "pobrano nazwe miasta centrali" << std::endl;
        }
        else
        {
            std::cout << "Wpisano bledne argumenty" << std::endl;
            return 1;
        }
    }
    auto Graf = LoadFromFile(inputfile, centrala);
    auto dijkstra = Dijkstra(Graf, centrala);
    SaveToFile(dijkstra, outputfile, centrala);

    return 0;

}