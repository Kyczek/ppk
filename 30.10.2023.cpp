

#include <iostream>
#include <vector>

int GetSize(const std::string& text)
{
	int n;
	do {
		std::cout << " n = ";
		std::cin >> n;
	} while (n < 1);
	return n;

}
int NWD(int n, int m);

int Rand(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int RGB(char R, char G, char B)
{




}



int main()
{
	/*
	int lw = GetSize(" n = ");
	int lk = GetSize(" m = ");
	auto m = CreateMatrix(lw, lk);
	Show(m);
	
	Swap(&a, &b);
	SwapR(a, b);
	*/
	int n = 56;
	int m = 16;
	int l = 16;
	std::cout << NWD(n, m) << std::endl ;
	std::cout << NWD(NWD(n, m) , l) << std::endl;


	srand((unsigned int)time(NULL));
	std::cout << Rand(0,100);

}

/*
std::vector < std::vector<double>> CreateMatrix(const size_t rows, const size_t cols) {
	std::vector<std::vector<double>>m(rows,std::vector<double>(cols));


	return m;
}

void Show(const std::vector < std::vector<double>>& matrix)
{
	for (const auto& row : matrix)
	{
		for (const auto& el : row)
		{
			std::cout << el << "\t" << std::endl;
		}
		
	}



}

double Add(const double x, const double y)
{
	return x + y;

}

void Swap(double x, double y)
{
	double x2 = x;
	x = y;
	y = x2;



}

void Swap(double* x, double* y)
{
	double x2 = *x;
	*x = *y;
	*y = x2;



}
void SwapR(double& x, double& y)
{
	double x2 = x;
	x = y;
	y = x2;



}

int Silnia(const int n) {
	int result = 1;
	for (int i = 2; i <= n; ++i)
	{
		result *= i;
	}
	return result;

}
int SilniaR(const int n)
{
	if (n < 2)
		return 1;
	else
		return n * SilniaR(n - 1);


		}
		*/
int NWD( int n, int m)
{
	if (n == m)
		return n;
	else if (n > m)
		return NWD( n-m, m);
	else
		return NWD(n, m-n);
}
