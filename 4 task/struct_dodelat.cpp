
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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


struct Student {
    vector<Lesson*> lesson_list;
    string name;

    Student(string name_) : name(name_) {}

    void add_lesson(Lesson* tmp);
};


struct Lesson {
    vector<Student*> student_list;
    string name;

    Lesson(string name_) : name(name_) {}

    void add_student(Student* tmp);
};



int main() {

    vector<Student> s;
    vector<Lesson> l;
    s.push_back(Student("Ваня"));
    s.push_back(Student("Сергей"));

    l.push_back(Lesson("Математика"));
    l.push_back(Lesson("Физика"));

    s[0].add_lesson(&l[0]);
    s[0].add_lesson(&l[1]);
    s[1].add_lesson(&l[0]);

    std::cout << "Математика: ";
    for (int i = 0; i < l[0].student_list.size(); ++i)
    {
        std::cout << l[0].student_list[i]->name;
        if (i != l[0].student_list.size() - 1) std::cout << ", ";
    }

    std::cout << '\n';

    std::cout << "Ваня: ";
    for (int i = 0; i < s[0].lesson_list.size(); ++i)
    {
        std::cout << s[0].lesson_list[i]->name;
        if (i != s[0].lesson_list.size() - 1) std::cout << ", ";
    }

    std::cout << '\n';

    cout << endl;
}