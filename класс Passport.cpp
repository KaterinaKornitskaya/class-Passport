// класс Passport.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>

/*
Создайте класс Passport (паспорт), который будет содержать паспортную 
информацию о гражданине Украины. 
С помощью механизма наследования 
реализуйте класс ForeignPassport (загранпаспорт), производный от 
Passport. Напомним, что загранпаспорт содержит помимо паспортных 
данных, также данные о визах, номер загранпаспорта
*/

class Passport  // базовый класс
{
protected:      // protected - доступ к поляи открыт для базового и 
			    // дочернего класса
	std::string first_name;		  // имя
	std::string second_name;	  // фамилия
	std::string passport_series;  // серия
	int passport_number; 		  // номер
public:
	Passport( int noP)  // конструктор с параметрами
		: first_name{ "Ivan" },
		second_name {"Ivanov"},
		passport_series {"AA"}, 
		passport_number{ noP }
	{
		std::cout << "Constructor Passport with param\n";
	}	

	~Passport()
	{
		std::cout << "Destructor Passport\n";
	}
};

class ForeignPassport : public Passport  // дочерний класс
{
	// в дочернем классе поля по умолчанию private - 
	// доступ открыт только для использования этим классом
	std::string usa_visa;  // виза 1
	std::string uk_visa;   // виза 2
	int foreign_no;		   // номер
public:
	ForeignPassport(int noP, int foreign_noP)  // конструктор с параметрами
		: Passport(noP), 
		usa_visa{ "USA visa" }, 
		uk_visa{ "UK visa" },
		foreign_no{ foreign_noP }
	{
		std::cout << "Constructor ForeignPassport with param\n";
	}
	
	~ForeignPassport()
	{
		std::cout << "Destructor ForeignPassport\n";
	}

	void print();  // метод для вывода на экран
};

void ForeignPassport::print()
{
	std::cout << "\nAll data:\n";
	std::cout << "Passport data :\n";
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Second name: " << second_name << std::endl;
	std::cout << "Series: " << passport_series << std::endl;
	std::cout << "Number: " << passport_number << std::endl;
	std::cout << "Foreign Passport data :\n";
	std::cout << "Visas: \n";
	std::cout << usa_visa << std::endl;
	std::cout << uk_visa << std::endl;
	std::cout << "Foreign no: " << foreign_no << std::endl;
}

int main()
{
	ForeignPassport obj1( 1234, 9999);
	obj1.print();
	std::cout << std::endl;

	return 0;
}