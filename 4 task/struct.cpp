
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Lesson;

struct Student {
    vector<Lesson*> lesson_list;
    string name;

    Student(string n){
        name = n;
    }
    void add_lesson(Lesson* tmp);
};


struct Lesson {
    vector<Student*> student_list;
    string name;

    Lesson(string n) {
        name = n;
    }
    void add_student(Student* tmp);
};


void Student::add_lesson(Lesson* tmp)
{
    lesson_list.push_back(tmp);
    tmp->student_list.push_back(this);
}


void Lesson::add_student(Student* tmp)
{
    student_list.push_back(tmp);
    tmp->lesson_list.emplace_back(this);
}


int main() {

    vector<Student> s;
    vector<Lesson> l;
    s.push_back(Student("Petr"));
    s.push_back(Student("Erik"));

    l.push_back(Lesson("Mathematics"));
    l.push_back(Lesson("Physics"));

    s[0].add_lesson(&l[0]);
    s[0].add_lesson(&l[1]);
    s[1].add_lesson(&l[0]);

    cout << "Mathematics: ";
    for (int i = 0; i < l[0].student_list.size(); ++i)
        cout << l[0].student_list[i]->name << ((i != l[0].student_list.size() - 1)?", " : "");


    cout << endl;

    cout << "Petr: ";
    for (int i = 0; i < s[0].lesson_list.size(); ++i)
        cout << s[0].lesson_list[i]->name << ((i != s[0].lesson_list.size() - 1) ? ", " : "");

    cout << endl;
}