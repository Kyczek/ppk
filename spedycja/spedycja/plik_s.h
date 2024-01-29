/*!
* @file plik_s.h
* @brief Plik naglowkowy(z deklaracjami).
* 
* Plik zawiera deklaracje funkcji potrzebnych do dzialania programu.
*/

#pragma once
#include <functional>						

/**
* @brief Typ danych reprezentujacy dane wejsciowe.
* 
* Struktura danych w postaci mapy, wykorzystywana przy tworzeniu grafu z danych pliku wejsciowego,
* gdzie kluczem jest pierwsze miasto odczytane w danym wierszu, a jego wartosciami jest kolejne miasto oraz odleglosc miedzy nimi.
*/
typedef std::map<std::string, std::set<std::pair<std::string, int>>> Graf_in;  

/**
* @brief Typ danych reprezentujacy wyniki dzialania programu. 
*
* Struktura danych w postaci mapy, przechowujaca dane o najkrotszych trasach utworzonych za pomoca algorytmu Dijkstry.
* Kluczem struktury jest miasto docelowe, a jego wartosciami najkrotsza odleglosc centrali do tego miasta i miasto najblizej poprzednie.
*/
typedef std::map<std::string, std::pair<double, std::string>> Graf_out;

/**
* @brief Funkcja sluzaca do wczytywania danych z pliku wejsciowego.
*
* Funkcja wczytuje dane, dotyczace polaczenia i odleglosci poszczeglonych, z pliku wejsciowego.
* Nastepnie sa one dodawane do zmiennej "graf_input", z racji tego ze graf nie jest skierowany funkcja dodaje obustronnie.
* Funkcja rowniez sprawdza czy centrala posiada polaczenie z jakimkolwiek miastem.
* Jezeli nie wystepuje zadne polaczenie program konczy sie z kodem bledu.
*
*
* @param fileName Nazwa pliku wejsciowego z danymi potrzebnymi do utworzenia grafu.
* @param centrala Nazwa miasta centrali, od ktorej maja powstac najkrotsze trasy do pozostalych miast.
*
* @return Graf w postaci mapy reprezentujacej polaczenia pomiedzy miastami na podstawie pliku wejsciowego.
*/
Graf_in LoadFromFile(const std::string& fileName, const std::string& centrala);

/**
* @brief Funkcja znajdujaca najkrotsze trasy miast za pomoca algorytmu Dijkstry.
*
* Funkcja zaczyna sie od stworzenia zmiennej ktora bedzie przechowywala wyniki. Nastepnie inicjalizuje koszty dojscia do kazdego miasta jako nieskonczonosc,
* wyjatkiem jest miasto centrali, poniewaz wlasnie ono jest punktem startowym(jego koszt wynosi 0). W petli nieskonczonej program stosuje algorytm Dijkstry.
* Dla kazdego sasiedniego miasta aktualnego miasta, funkcja sprawdza czy odleglosc jest krotsza niz obecnie znana odleglosc do miasta sasiedniego, jesli tak to jest ona aktualizowana.
* Nastepnie zostaje wybrane nastepne miasto do sprawdzenia, ktore odleglosc jest najmniejsza sposrod niesprawdzonych wezlow. Sprawdzone miasta usuwamy ze zbioru "wezly".
* Gdy wszystkie miasta zostaly sprawdzone petla nieskonczona zostaje przerwana.
* 
* @param graf Graf utworzony z plikow wejsciowych, na ktorym ma byc wykonany algorym Dijkstry.
* @param miasto miasto startowe dla algorytmu.
*
* @return Graf w postaci mapy reprezentujacy najkrotsze trasy od centrali do pozostalych miast, posiadajacych polaczenie z miastem centrali.
*/
Graf_out Dijkstra(const Graf_in& graf, std::string miasto);

/**
* @brief Funkcja pomocnicza tworzaca trase przez jakie miasta trzeba przejechac, by dostac sie do miasta docelowego najkrotsza trasa.
*
* Funkcja polega na rekurencji, ktora za kazdym wywolaniem wypisuje kolejne miasta najkrotszej trasy.
* 
* @param DijkstraResult Wynik funkcji uzywajacej algorytmu Dijkstry do znajdywania najkrotszych tras miast.
* @param miasto Miasto punktem najkrotszej trasy. 
* @param centrala Nazwa miasta centrali, od ktorej maja powstac najkrotsze trasy do pozostalych miast.
* @param out Strumien wyjsciowy, do ktorego ma byc wypisany wynik funkcji.
*
*/
void PrintPath(Graf_out& DijkstraResult, std::string miasto, const std::string& centrala, std::ofstream& out);

/**
* @brief Funkcja tworzaca plik wyjsciowy z wynikami dzialania programu.
*
* Funkcja otwiera plik wyjsciowy do zapisu. Nastepnie dla wszystkich wynikow, oprocz wyniku dla centrali oraz miast z nieskonczona odlegloscia(miast ktore nie maja polaczen),
* korzysta z funkcji "PrintPath" i wypisuje najkrotsze trasy do poszczegolnych miast. Na koniec funkcja zamyka plik wyjsciowy i wypisuje komunikat.
* 
* @param DijkstraResult Wynik funkcji uzywajacej algorytmu Dijkstry do znajdywania najkrotszych tras miast.
* @param outputfile Nazwa pliku wyjsciowego, do ktorego maja zostac zapisane wyniki.
* @param centrala Nazwa miasta centrali, od ktorej maja powstac najkrotsze trasy do pozostalych miast.
*
*/
void SaveToFile(Graf_out& DijkstraResult, const std::string& outputfile, const std::string& centrala);
