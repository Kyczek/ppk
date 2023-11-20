
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


typedef std::vector<std::vector<double>> Matrix;
typedef std::vector<double> wektor;




void Show(const wektor& v)
{
    for (const auto el : v)
    {
        std::cout << el << std::endl;
    }
}


void Show(const Matrix& m)
{
    for (const auto& row : m)
    {
        for (const auto el : row)
        {
            std::cout << el << '\t';
        }
        std::cout <<   std::endl;
    }
}


Matrix LoadMatrixFromFile(const std::string& fileName)
{
    Matrix m;
    std::ifstream in(fileName);
    if (in) {
        std::string line;
        while (std::getline(in, line)) {
            m.push_back(wektor());
            std::stringstream ss(line);
            std::string x;
            while (std::getline(ss, x, ','))
            {
                m.back().push_back(std::stod(x));
            }
        }

        in.close();
    }
    return m;
}







void SaveToFile(const std::string& fileName, const Matrix& m)
{
    std::ofstream out(fileName);
    if (out) {
        for (const auto& row : m)
        {
            for (const auto el : row)
            {
                out << el << std::endl;
            }
            
        }
        out.close();

    }



}


void SaveToFile(const std::string& fileName, const std::vector<double>& v)
{
    std::ofstream out(fileName);
    if (out) {
        for (const auto el : v)
        {
            out << el << std::endl;
        }
        out.close();

    }



}

std::vector<double> LoadFromFile(const std::string& fileName)
{
    std::vector<double> result;
    std::ifstream in(fileName);
    double x;
    if (in) {
        while (in >> x)
        {
            result.push_back(x);
        }
        in.close();

    }
}







void p2()
{
    const size_t rows = 10;
    const size_t cols = 8;
    Matrix m(rows, wektor(cols));
    for (size_t i = 0; i < m.size(); ++i)
    {
        for (size_t j = 0; j < m[i].size(); ++j)
        {
            m[i][j] = 100.0 * i + 1.0 * j;
        }
    }

}


auto m1 = LoadMatrixFromFile("matrix.txt");


int main()
{
    const size_t size = 10;
    std::vector<double> v(size);
    for (size_t i = 0; i < size; i++)
    {

        v[i] = 1.0 + i;
    }
    Show(v);
    SaveToFile("vector.txt", v);

}

