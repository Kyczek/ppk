/*!
* @file plik_s.cpp
* @brief Plik z definicjami funkcji.
*
* Plik plik_s.cpp zawiera implementacje funkcji wykorzystywane w programie.
* Zawiera on funkcje do wczytywanie danych z pliku, tworzenia najkrotszych
* tras do poszczegolnych miast za pomoca algorytmu Dijkstry, 
* wypisywania tras oraz zapisywanie wynikow do pliku wyjsciowego.
* 
* 
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include "plik_s.h"





Graf_in LoadFromFile(const std::string& inputfile, const std::string& centrala)
{
    std::ifstream in(inputfile);
    Graf_in graf_input;
    //zmienna do sprawdzania czy miasto centralne znajduje sie w plikac wejsciowych
    bool centrala_graf = false;
    if (in)
    {   
        std::string line;
        //wczytywanie danych z pliku wejsciowego
        while (std::getline(in, line))
        {            
            std::stringstream ss(line);
            std::string miasto1, miasto2;
            int odl;
            if (!(ss >> miasto1)) continue;
            if (!(ss >> miasto2)) continue;
            if (!(ss >> odl)) continue;
            graf_input[miasto1].insert({ miasto2,odl });
            graf_input[miasto2].insert({ miasto1,odl });
            if (miasto1 == centrala || miasto2 == centrala)
            {
                centrala_graf = true;
            }
        }
        in.close();
        //jesli centrala nie wystepuje w danych, program sie konczy
        if (!centrala_graf)
        {
            std::cout << centrala << " nie posiada zadnych polaczen z innymi miastami" << std::endl << "zakonczono program bez tworzenia tras" << std::endl;
            exit(1);
        }
    }
    else
    {
        std::cout << "Blad pliku wejsciowego" << std::endl;
        exit(1);
    }   
        return graf_input;
}


Graf_out Dijkstra(const Graf_in& graf, std::string miasto)
{
    //mapa przechowujaca wyniki algorytmu
    Graf_out wynik;
    //ustawienie poczatkowych wartosci dlugosi tras na nieskonczonosc
    for (const auto& el : graf) wynik[el.first].first = std::numeric_limits<double>::infinity();
    //zmienna przechwoujaca miasta
    std::set<std::string> wezly;
    //wynik centrali do samej siebie
    wynik[miasto].first = 0;
    //petla algorytmu Dijkstry
    while (true)
    {   //szukanie krotszej sciezki
        for (const auto& el : graf.at(miasto))
        {
            if (wynik[el.first].first > wynik[miasto].first + el.second)
            {
                wynik[el.first].first = wynik[miasto].first + el.second;
                wezly.insert(el.first);
                wynik[el.first].second = miasto;
            }
        }
        //zakoncz petle algorytmu
        if (wezly.empty()) break;
        //wybieranie kolejne miasta
        miasto = *std::min_element(wezly.begin(), wezly.end(),
            [&wynik](const auto& l, const auto& r)
            {
                return wynik[l].first < wynik[r].first; });
        //usun miasto ktore zostalo przetworzone
        wezly.erase(miasto);
    }
    return wynik;
}
// funkcja wypisujaca trase do miasta docelowego
void PrintPath(Graf_out& DijkstraResult, std::string miasto, const std::string& centrala, std::ofstream& out) {
    if (miasto != centrala)
        //rekurencja
        PrintPath(DijkstraResult, DijkstraResult[miasto].second, centrala, out);
    //wypisywanie kolejnych miast
    out << miasto << " -> ";
}



void SaveToFile(Graf_out& DijkstraResult, const std::string& outputfile, const std::string& centrala)
{
    std::ofstream out(outputfile);
    if (out)
    {
        for (const auto& el : DijkstraResult)
        {   
            if (el.first != centrala && DijkstraResult[el.first].first != std::numeric_limits<double>::infinity())      //sprawdzenie czy wynik trasy jest nieskonczony lub trasy do miasta centrali
            {       
                    PrintPath(DijkstraResult, DijkstraResult[el.first].second, centrala, out);
                    out << el.first << ": " << DijkstraResult[el.first].first << std::endl;         //zapisywanie wyniku do pliku wyjsciowego
                
            }
        }
        out.close();
        std::cout << "Pomyslnie utworzono trasy spedycyjne" << std::endl;
    }
    else
    {
        std::cout << "Nie mozna otworzyc pliku wyjsciowego." << std::endl;
    }
}
