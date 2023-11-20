// 16.10.23.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

int main()
{

    
    
    int n;
    std::cout << "wpisz n";
    std::cin >> n;
    double sum = 0;
    double max = -2147483647;
    double min = 2147483647;
    double d;
    for (int i = 0; i < n; i++)
    {
        std::cout << "liczby =";
        std::cin >> d;
                
        sum = sum + d;
        if (max < d)
            max = d;
        if (min > d)
            min = d;
       

        
    }std::cout << "suma = " << sum;
    std::cout << "srednia = " << sum / n;
    std::cout << "max = " << max;
    std::cout << "min = " << min;

}

