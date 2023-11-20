

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


struct tlumaczenie { 
    std::string pl;
    std::string en;
};
typedef std::vector<tlumaczenie> wektor;


wektor load (const std::string& fileName)
{
    wektor w1;
    std::ifstream in(fileName);
    double x;
    while(in >> x)
    {
        w1.push_back(x);
        w1.push_back(x);
    }
    in.close();
    return w1;
}




int main()
{
    
}

