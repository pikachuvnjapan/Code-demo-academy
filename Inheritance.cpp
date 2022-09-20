#include <iostream>

using namespace std;

class Employee{
    protected:
        string name;
        int age;
        double basic;
    public:

        Employee(string name, int age, double basic){
            this->name = name;
            this->age = age;
            this->basic = basic;
        }
        virtual double calculateSalary() = 0;


};

class Manager:public Employee{
    private:
        double hra;

    public:
       Manager(string name, int age, double basic):Employee(name, age, basic){
        hra = basic * 0.15;
       }

       double calculateSalary(){
           double salary = basic * 0.15;
           salary = salary + hra;
           return salary;
       }
};


class FactoryWorker:public Employee{

    private:
            double tiffinAllowences;
    public:
            FactoryWorker(string name, int age, double basic):Employee(name, age, basic){
                tiffinAllowences = 0.05 * basic;
            }
            double calculateSalary(){
                double salary = basic * 0.08;
                salary += tiffinAllowences;
                return salary;
            }
};


class Clerk:public Employee{
    private:
        int otHours;
        double otRate;
    public:
        Clerk(string name, int age, double basic, int otHours, double otRate):Employee(name, age, basic){
            this->otHours = otHours;
            this->otRate = otRate;
        }
        double calculateSalary(){
            double salary = basic * 0.1;
            salary += otRate * otHours;
            return salary;
        }
};

class Club{

    public:
        string getMembershipType(Employee *p){
            double salary = p->calculateSalary();
            if (salary >= 10000.0){
                return "Red";
            }
            else if (salary >= 7500.0){
                return "Blue";
            }
            else{
                return "Gray";
            }

        }
};

int main()
{
    /*
    Employee *p = new Manager("Alice", 25, 8000.0);
    double salary = p->calculateSalary();
    cout << salary << endl;
    */
    Club club;
    cout << "Alice has "
          << club.getMembershipType(new Manager("Alice", 25, 8000.0))
          << " membership" << endl;

    cout << "John has " << club.getMembershipType(new Clerk("John", 25, 5000.0, 10, 12.5))
         << " membership" << endl;


    return 0;
}
