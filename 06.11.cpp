
#include <iostream>
#include <string>
#include <vector>

struct PersonalData {
	std::string firstname;
	std::string lastname;
	int age;
	
};


void show(const PersonalData& pd)
{

	std::cout << "Imie" << pd.firstname << std::endl;
	std::cout << "nazwisko" << pd.lastname << std::endl;
	std::cout << "wiek" << pd.age << std::endl;

}

PersonalData wczytaj()
{

	PersonalData b;
	std::cout << "wpisz Imie" << std::endl;
	std::cin >> b.firstname;
	std::cout << "wpisz Nazwisko" << std::endl;
	std::cin >> b.lastname;

	std::cout << "wpisz wiek" << std::endl;
	std::cin >> b.age;

	return b;
}

void show(const PersonalData* const pd)
{
	std::cout << "Imie" << pd->firstname << std::endl;
	std::cout << "nazwisko" << pd->lastname << std::endl;
	std::cout << "wiek" << pd->age << std::endl;
	//std::cout << "wiek" << (*pd).age << std::endl;

}




void show(const std::vector<PersonalData>& v)
{
	for (const auto& el : v)
	{
		show(el);
		std::cout << std::endl;
	}

}



std::vector<PersonalData> wczytaj(const int n)
{
	std::vector<PersonalData> pd(n);
	for (int i = 0; i < n; i++)
		pd[i] = wczytaj();
	return pd;
}

//wyszukaj kogos w tablicy o imieniu Kacper


PersonalData szukaj(std::vector<PersonalData>, std::vector<PersonalData> pd)
{
	
	for (int i = 0; i < n; i++)
		if (pd(i).firstname == "Kacper")
			
	return pd(i);
}


int main()
{
	PersonalData pd;
	pd.firstname = "Jan";
	pd.lastname = "Kowalski";
	pd.age = 18;
	

	show(pd);
	std::cout << std::endl;
	show(&pd);

	std::vector<PersonalData> pds = wczytaj(2);
	show(pds);
	std::vector<PersonalData> 
	//show(wczytaj());





}
