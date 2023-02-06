#include <iostream>
#include <algorithm>
#include "include/Horario.h"
#include "include/Menu.h"

Horario::Horario(){}

void Horario::clear(){
    horario.clear();
}
void Horario::push_back(Class x) {
    horario.push_back(x);
}
vector<struct Class> Horario::getHorario(string aluno) {
    Menu menu;
    vector<Class> classList=menu.getClassList();
    BST<Student> studentList=menu.getStudentList();
    Student student1 = studentList.find(Student(aluno,"",{}));
    vector<vector<string>> classes = student1.getUc_classcode();
    for (int i = 0; i < classes.size(); i++) {
        string uccode = classes[i][0];
        string classcode = classes[i][1];
        for (int j = 0; j < classList.size(); j++) {
            if (classcode == classList[j].getClassCode() && uccode == classList[j].getUccode())
                horario.push_back(classList[j]);
        }
    }
}

void Horario::add(Student student) {
    Menu menu;
    vector<Class> classList=menu.getClassList();
    auto x=student.getUc_classcode()[0][1];
    auto z=student.getUc_classcode()[0][0];
    for (auto y: classList) {
        if (y.getClassCode() == x &&  y.getUccode() == z)
    {
        horario.push_back(y);
    }
    }

}


vector<Class>::iterator Horario::begin(){
    vector<Class>::iterator it;
    it=horario.begin();
    return it;
}
vector<Class>::iterator Horario::end(){
    vector<Class>::iterator itf;
    itf=horario.end();
    return itf;
}
void Horario::print() {
    for(auto x:horario) {
        cout << x.getWeekDay() << " | " << x.getUccode()
             << " " << x.getClassType() << " class in "
             << x.getClassCode() << " from "
             << TransformHour(x.getStarthour()) << " to "
             << SumHours(x.getStarthour(), x.getDuration())
             << endl;
    }
}
int Horario::type_of_order() {
    int order;
    std::cout<<"Como deseja ordenar o horario?"<<endl;
    std::cout<<"1(default)-> ordem crescente"<<endl;
    std::cout<<"2-> ordem decrescente"<<endl;
    std::cout<<"3-> primeiro pelas aulas teoricas"<<endl;
    std::cout<<"4-> pelo codigo da UC"<<endl;
    std::cout<<"5-> pela duracao da aula"<<endl;
    cin>> order;
    return order;
}
bool Horario::decrescent_order(Class x, Class y) {
    if (x.orderWeekDay() == y.orderWeekDay()) {
        if (x.getStarthour() == y.getStarthour()) return x.getClassCode() > y.getClassCode();
        else return x.getStarthour() > y.getStarthour();
    }
    return x.orderWeekDay() > y.orderWeekDay();
}
bool Horario::theorics_first(Class x, Class y) {
    if (x.orderTypeClasses() == y.orderTypeClasses()) {
        if (x.orderWeekDay() == y.orderWeekDay()) {
            if (x.getStarthour() == y.getStarthour()) return x.getClassCode() < y.getClassCode();
            else return x.getStarthour() < y.getStarthour();
        }
        return x.orderWeekDay() < y.orderWeekDay();
    }
    return x.orderTypeClasses() < y.orderTypeClasses();
}
bool Horario::uc_code_order(Class x,Class y){
    if (x.getUccode() == y.getUccode()) {
        if (x.orderTypeClasses() == y.orderTypeClasses()) {
            if (x.orderWeekDay() == y.orderWeekDay()) {
                if (x.getStarthour() == y.getStarthour()) return x.getClassCode() < y.getClassCode();
                else return x.getStarthour() < y.getStarthour();
            }
            return x.orderWeekDay() < y.orderWeekDay();
        }
        return x.orderTypeClasses() < y.orderTypeClasses();
    }
    return (x.getUccode() < y.getUccode());
}
bool Horario::class_duration_order(Class x, Class y) {
    if (x.getDuration() == y.getDuration()) {
        if (x.orderWeekDay() == y.orderWeekDay()) {
            if (x.orderWeekDay() == y.orderWeekDay()) return x.getClassCode() < y.getClassCode();
            else return x.getStarthour() < y.getStarthour();
        }
        return x.orderWeekDay() < y.orderWeekDay();
    }
    return x.getDuration() < y.getDuration();
}
bool Horario::default_order(Class x, Class y) {
    if (x.orderWeekDay() == y.orderWeekDay()) {
        if (x.getStarthour() == y.getStarthour()) return x.getClassCode() < y.getClassCode();
        else return x.getStarthour() < y.getStarthour();
    }
    return x.orderWeekDay() < y.orderWeekDay();
}

string Horario::TransformHour(float hour) {
    int hours = int(hour);
    int minutes = (hour - hours) * 6;
    string time = to_string(hours) + ":" + to_string(minutes) + "0";
    return time;
}

string Horario::SumHours(float starthour, float duration) {
    float finalhour = starthour + duration;
    return TransformHour(finalhour);
}