#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    double salary;
    static int employeeCount;

public:
    Employee(string n, double s) {
        name = n;
        salary = s;
        employeeCount++;
    }

    static void getcount() {
        cout << "Total Number of Employees: " << employeeCount << endl;
    }

    virtual void displayInfo() const {
        cout << "Employee's Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    virtual ~Employee() {
        cout << "Destroying Employee" << endl;
    }
};

int Employee::employeeCount = 0;

class Staff : public Employee {
private:
    string department;

public:
    Staff(string n, double s, string d) : Employee(n, s) {
        department = d;
    }

    virtual void displayInfo() const override {
        cout << "Employee's Name: " << name << " (Staff)" << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
    }

    virtual ~Staff() {
        cout << "Destroying Staff" << endl;
    }
};

class Faculty : public Employee {
private:
    string department;

public:
    Faculty(string n, double s, string d) : Employee(n, s) {
        department = d;
    }

    virtual void displayInfo() const override {
        cout << "Employee's Name: " << name << " (Faculty)" << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
    }

    virtual ~Faculty() {
        cout << "Destroying Faculty" << endl;
    }
};

int main() {
    int n;
    cout << "Enter Number of Employees: ";
    cin >> n;

    Employee* arr[n]; 

    for (int i = 0; i < n; i++) {

        string type, name, dept;
        double salary;

        cout << "Enter type (Staff/Faculty): " << endl;
        cin >> type;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter salary: ";
        cin >> salary;

        cout << "Enter department: ";
        cin >> dept;

        if (type == "Staff")
            arr[i] = new Staff(name, salary, dept);
        else
            arr[i] = new Faculty(name, salary, dept);
    }

    cout << "--- Employee Details ---" << endl;
    for (int i = 0; i < n; i++) {
        arr[i]->displayInfo();
        cout << endl;
    }

    Employee::getcount();

    for (int i = 0; i < n; i++) {
        delete arr[i];
    }

    return 0;
}
