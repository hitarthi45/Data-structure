#include<iostream>
using namespace std;

class employee
{
public:
  string name;
  int empID;
  char gender;
  double salary;
  void set_salary(double s)
  {
      salary=s;
  }
  void diaplay_salary(){
   cout<<"Salary is "<<salary<<endl;
  }
};
int main()
{
    employee e1;
    cout<<"Enter your name : "<<endl;
    cin>>e1.name;
    cout<<"Enter the empID : "<<endl;
    cin>>e1.empID;
    cout<<"Enter the gender : "<<endl;
    cin>>e1.gender;
    cout<<"Enter the salary: "<<endl;
    cin>>e1.salary;

    cout<<"The name is: "<<e1.name<<endl;
    cout<<"The empID is: "<<e1.empID<<endl;
    cout<<"The Gender is: "<<e1.gender<<endl;
    cout<<"The Salary is: "<<e1.salary<<endl;
}
