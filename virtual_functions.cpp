#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int student_count = 1;
int professor_count = 1;

class Person {
public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
protected:
    string name;
    int age;
    int cur_id;
};

class Professor: public Person {
private:
    int publications;
public:
    Professor() {
        cur_id = professor_count;
        professor_count ++;
    }
    void getdata() override {
        cin >> name >> age >> publications;
    }
    void putdata() override {
        cout << name << " " << age << " "
             << publications << " " << cur_id << endl;
    }
};

class Student: public Person {
private:
    int marks[6];
public:
    Student() {
        cur_id = student_count;
        student_count ++;
    }
    void getdata() override {
        cin >> name >> age;
        for (int i = 0; i < 6; i ++)
            cin >> marks[i];
    }
    void putdata() override {
        cout << name << " " << age << " ";
        int sum = 0;
        for (int i = 0; i < 6; i ++)
            sum += marks[i];
        cout << sum << " " << cur_id << endl;
    }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
