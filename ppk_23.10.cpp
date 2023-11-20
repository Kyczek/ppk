
#include <iostream>
#include <vector>

int main()
{
	/*
	const int size = 10;
	int tab[size] = {0};

	for (int i = 0; i < size; i++)	
		std::cin >> tab[i];
	

	for (int i = 0; i < size; i++)
		std::cout << tab[i] << std::endl;
	

	
	int* tab = nullptr;
	tab = new int[65];


	for (int i = 0; i < 65; i++)
		std::cin >> tab[i];


	for (int i = 0; i < 65; i++)
		std::cout << tab[i] << std::endl;

	delete[] tab;
	

	
	std::vector <int> tab();
	


	const int rows = 4;
	const int col = 4;
	double tab[rows][col];

	int r, c;
	std::cin >> r >> c;


	for(int i= 0 ; i< r;r++)
		for (int j = 0; j < c; j++)
		{
			std::cout << "tab[" << i << "][" << j << "]";
			std::cin >> tab[i][j];
		}

		
	int r, c;

	double** m = new double* [r];
	for (int i = 0; i < r; i++)
		m[i] = new double[c];





		

	int r, c;

	std::vector < std::vector <double>> m(r, std::vector<double>(c));

	*/

	/*

	//zad 1
	int n;
	std::cout << "Podaj liczbę elementów:";
	std::cin >> n;
	
	std::vector <int> tab(n);
	int min, max;
	for (int i = 0; i < n; i++)
	{
		std::cout << "T[" << i + 1 << "] = ";
		std::cin  >> tab[i];
		
	
	}
	min = tab[0];
	int min_poz;
	int max_poz;
	max = tab[0];
	for (int i = 1; i < n; i++)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			max_poz = i+1;
		}
			
		if (tab[i] < min)
		{
			min = tab[i];
			min_poz = i + 1;
		}
			


	}

	std::cout << "Wartosc najmniejsza to =" << min << " na pozycji " << min_poz << std::endl;
	std::cout << "Wartosc najwieksza to =" << max << " na pozycji " << max_poz << std::endl;


	*/
	//zad2
	int w,k;
	std::cout << "Podaj liczbę wierszy:";
	std::cin >> w;
	std::cout << "Podaj liczbę kolumn:";
	std::cin >> k;

	std::vector < std::vector <int>> tab(w, std::vector<int>(k));

	
	int min, max;
	for (int i = 0; i < w; i++)
		for (int j = 0; j < k; j++)
		{
			std::cout << "tab[" << i+1 << "][" << j+1 << "]";
			std::cin >> tab[i][j];
		}
	min = tab[0][0];
	int min_poz_x , min_poz_y;
	int max_poz_x, max_poz_y;
	max = tab[0][0];
	for (int i = 1; i < w; i++)
		for (int j = 0; j < k; j++)
		{
			if (tab[i][j] > max)
			{
				max = tab[i][j];
				max_poz_x = i + 1;
				max_poz_y = j + 1;
			}

			if (tab[i][j] < min)
			{
				min = tab[i][j];
				min_poz_x = i + 1;
				min_poz_y = j + 1;
			}



		}

	std::cout << "Wartosc najmniejsza to =" << min << " na pozycji " << min_poz_x << min_poz_y << std::endl;
	std::cout << "Wartosc najwieksza to =" << max << " na pozycji " << max_poz_x << max_poz_y << std::endl;

	



}

