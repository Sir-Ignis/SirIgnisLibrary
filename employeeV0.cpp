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
  
private:
  void setYearsOfService(unsigned int yearsOfService);
  void setAge(unsigned int age);
  void setSalary(unsigned int salary);

  unsigned int itsYearsOfService;
  unsigned int itsAge;
  unsigned int itsSalary;
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

int main()
{
  cout << "Hello there." << endl;

  Employee Greg(5,30,40000);
  Employee Smith(20,50,100000);

  cout << "Your name is Greg." << endl;
  cout << "You have been working for " << Greg.getYearsOfService() << " years." << endl;
  cout << "You are " << Greg.getAge() << " years old." << endl;
  cout << "You earn $" << Greg.getSalary() << " per year." << endl;

  cout << "\n";

  cout << "Your name is Smith." << endl;
  cout << "You have been working for " << Smith.getYearsOfService() << " years." << endl;
  cout << "You are " << Smith.getAge() << " years old." << endl;
  cout << "You earn $" << Smith.getSalary() << " per year." << endl;

  cout << "\n";  

  return 0;
}
