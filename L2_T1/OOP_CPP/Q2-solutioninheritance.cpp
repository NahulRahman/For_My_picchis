#include<iostream>
#include<stdio.h>
using namespace std;

class Person
{
private:
    double contact_number;
protected:
    string designation;

public:
    string full_name;

    virtual int getsal()=0; //2 marks

    Person(double c_no, string desig, string f_n)
    {
        contact_number=c_no;
        designation=desig;
        full_name=f_n;
    }

};

class Employee: virtual public Person //1.5 marks
{
private:
    int basic_sal;

protected:
    int bonus;

public:

    Employee(double c_no, string desig, string f_n, int b_sal, int bon): Person(c_no, desig, f_n)
    {
        basic_sal=b_sal;
        bonus=bon;
    }

    int getbasicsal()
    {
        return basic_sal;
    }

};

class Operator: virtual public Person //1.5 marks
{
protected:
    int overtime_rate;
    int overtime_hour;

public:

     Operator (double c_no, string desig, string f_n, int o_r, int o_h): Person(c_no, desig, f_n)
    {
       overtime_rate = o_r;
       overtime_hour = o_h;
    }

    string getfullname()
    {
        return full_name;
    }


};

class Managers: protected Employee, protected Operator
{
private:
    int line_number;

public:
    Managers(double c_no, string desig, string f_n, int o_r, int o_h, int b_sal, int bon, int l_n): Employee(c_no, desig, f_n, b_sal, bon), Operator(c_no, desig, f_n, o_r, o_h), Person(c_no, desig, f_n)
    {
        line_number= l_n;
    }

    int getsal() //3 marks
    {
        return getbasicsal()+ bonus + overtime_rate * overtime_hour;

    }

    string getfullname()
    {
        return full_name;
    }
};

class Machine
{
private:
    string Machine_name;
    int M_ID;

public:
   virtual float power()=0; //1 mark
   virtual string operated_by()=0; //1 mark

   Machine(string m_name, int m_id)
   {
       Machine_name = m_name;
       M_ID = m_id;
   }

   string getMachinename()
   {
       return Machine_name;
   }
};

class Production_Machine: public Machine, private Operator
{
private:
    int operator_fee;
protected:
    float power_rate, hours_active;

public:
    float power()
    {
        return power_rate * hours_active;
    }

    string operated_by()
    {
        return getfullname();
    }

    Production_Machine (float p_r, float h_active, string m_name, int m_id, double c_no, string desig, string f_n, int o_r, int o_h): Machine(m_name, m_id), Operator(c_no, desig, f_n, o_r, o_h), Person(c_no, desig, f_n)
    {
        power_rate = p_r;
        hours_active = h_active;
    }

    int getsal()
    {
        return operator_fee;
    }

    string getmachine_name_del()
    {
        return getMachinename();
    }

};



int main()
{

    Managers M1(01730777777, "Manager (productions)", "Sunam Al Shafayet", 200, 4, 25000, 5000, 5);
    cout << "Salary of " << M1.getfullname() << " is: " << M1.getsal();
    //output should be Salary of Sunam Al Shafayet is 30800

    Production_Machine P1(500, 10.5, "Boring Machine", 2501, 01730555555, "Boring Machine Operator", "Farhan Nasif", 250, 10);
    cout<<"\n\nPower consumed by " << P1.getmachine_name_del() << " is: "<<P1.power() <<endl;
    //Power consumed by Boring Machine is 5250

}
