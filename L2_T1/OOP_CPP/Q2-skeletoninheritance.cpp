#include<iostream>
#include<stdio.h>
using namespace std;

class Person
{
private:
    int contact_num;
protected:
    string desig;
public:
    string name;
    //int id;
   int get_sal()=0;
    Person(int contact_num, string desig, string name)
    {
        this->contact_num=contact_num;
        this->desig=desig;
        this->name=name;
        //this->id=id;
    }
};

class Employee: virtual public Person //1.5 marks
{
private:
    double basic_salary;
protected:
    double bonus;
public:
    Employee(int contact_num, string desig, string name,double b_s,double b):Person(contact_num,desig,name,id)
    {
        basic_salary=b_s;
        bonus=b;
    }
    int get_basic_salary()
    {
        return basic_salary;
    }


};

class Operator: virtual public Person //1.5 marks
{
protected:
    double overtime_rate;
    double overtime_hour;
public:
    Operator(int contact_num, string desig, string name,double o_r, double o_h ):Person(contact_num,desig,name)
    {
        overtime_rate=o_r;
        overtime_hour=o_h;
    }

};

class Managers: protected Employee, protected Operator
{
private:
    int line_number;
public:
    double   get_sal()
    {
     return basic_salary()+bonus+overtime_rate *overtime_hour;
    }
 Managers(int contact_num, string desig, string name,double b_s,double b,double o_r, double o_h ,int l_n):  Employee(contact_num,desig,name,b_s,b) ,Operator(contact_num,desig,name,o_r, o_h ) ,Person(contact_num,desig,name,id)
 {
     line_number=l_n;
 }
};

class Machine
{
private:
    string machine_name;
    int m_id;
public:
    power()=0;
    operated_by()=0;
    Machine(string m_n, int m_id)
    {
        machine_name=m_n;
        this->m_id=m_id;
    }
};

class Production_Machine: public Machine, private Operator
{
private:
    double op_fee;
protected:
    double power_rate;
    double hours_active;
public:
    power()
    {

    }
    get_sal(){

    }
    get_machine_name_del()
    {

    }
    Production_Machine(string m_n, int m_id,int contact_num, string desig, string name,double o_r, double o_h ,double op_fee,double power_rate,double hours_active):Machine(m_n,m_id),Operator(contact_num,desig,name,o_r, o_h)
    {
       this->op_fee=op_fee;
       this->power_rate=power_rate;
       this->hours_active=hours_active;
    }
)

};



int main()
{

/*
    Managers M1(01730777777, "Manager (productions)", "Sunam Al Shafayet", 200, 4, 25000, 5000, 5);
    cout << "Salary of " << M1.getfullname() << " is: " << M1.getsal(); //write a func to get the full name
    ///output should be - Salary of Sunam Al Shafayet is 30800

    Production_Machine P1(500, 10.5, "Boring Machine", 2501, 01730555555, "Boring Machine Operator", "Farhan Nasif", 250, 10);
    cout<<"\n\nPower consumed by " << P1.getmachine_name_del() << " is: "<<P1.power() <<endl; //write a func to get the machine name
    ///output should be - Power consumed by Boring Machine is 5250

*/

}
