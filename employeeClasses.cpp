#include <iostream>
using namespace std;

class Employee
{
public: 
  Employee(unsigned int yearsOfService, unsigned int age, unsigned int salary);
  ~Employee();
  
  unsigned int getYearsOfService();
  unsigned int getAge();
  unsigned int getSalary();
  unsigned int getRoundedSalary();
  
private:
  void setYearsOfService(unsigned int yearsOfService);
  void setAge(unsigned int age);
  void setSalary(unsigned int salary);
  void setRoundedSalary(unsigned int salary);

  unsigned int itsYearsOfService;
  unsigned int itsAge;
  unsigned int itsSalary;
  unsigned int itsRoundedSalary;
};

Employee::Employee(unsigned int yearsOfService, unsigned int age, unsigned int salary)
{
  itsYearsOfService = yearsOfService;
  itsAge = age;
  itsSalary = salary;
}

Employee::~Employee()
{
}

void Employee::setYearsOfService(unsigned int yearsOfService)
{
  itsYearsOfService = yearsOfService;
}

void Employee::setAge(unsigned int age)
{
  itsAge = age;
}

void Employee::setSalary(unsigned int salary)
{
  itsSalary = salary;
}

void Employee::setRoundedSalary(unsigned int salary)
{
  unsigned int temp;
  temp = salary+500;
  temp = temp / 1000;
  salary = temp*1000;
  itsRoundedSalary= salary;
}

unsigned int Employee::getYearsOfService()
{
  return itsYearsOfService;
}

unsigned int Employee::getAge()
{
  return itsAge;
}

unsigned int Employee::getSalary()
{
  return itsSalary;
}

unsigned int Employee::getRoundedSalary()
{
  return itsRoundedSalary;
}

int main()
{

  cout << "Hello there." << endl;

  Employee Greg(5,30,47970);
  Employee Smith(20,50,191909);

  cout << "Your name is Greg." << endl;
  cout << "You have been working for " << Greg.getYearsOfService() << " years." << endl;
  cout << "You are " << Greg.getAge() << " years old." << endl;

  std::cout << "You earn $" << Greg.getRoundedSalary() << " per year." << endl;

  cout << "\n";

  cout << "Your name is Smith." << endl;
  cout << "You have been working for " << Smith.getYearsOfService() << " years." << endl;
  cout << "You are " << Smith.getAge() << " years old." << endl;

  std::cout << "You earn $" << Smith.getSalary() << " per year." << endl;

  cout << "\n";  

  return 0;
}


