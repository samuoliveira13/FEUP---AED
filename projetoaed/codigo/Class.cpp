#include "include/Class.h"
Class::Class(string classcode, string uccode, string weekday, float starthour, float duration, string classtype) {
    this -> classcode = classcode;
    this -> uccode = uccode;
    this -> weekday = weekday;
    this -> starthour = starthour;
    this -> duration = duration;
    this -> classtype = classtype;
}

void Class::setUccode(string uccode){
    this -> uccode = uccode;
}

void Class::setClasstype(string classtype){
    this -> classtype = classtype;
}

void Class::setStarthour(float starthour){
    this -> starthour = starthour;
}

void Class::setDuration(float duration){
    this -> duration = duration;
}

string Class::getUccode() {
    return uccode;
}

string Class::getClassCode() {
    return classcode;
}

string Class::getWeekDay() {
    return weekday;
}

float Class::getStarthour() {
    return starthour;
}

float Class::getDuration() {
    return duration;
}

string Class::getClassType() {
    return classtype;
}
int Class::orderWeekDay() {
    if(weekday=="Monday") return 1;
    else if(weekday=="Tuesday") return 2;
    else if(weekday=="Wednesday") return 3;
    else if(weekday=="Thursday") return 4;
    else if(weekday=="Friday") return 5;
    return 0;
}
bool Class::operator<(Class &other){
    if(orderWeekDay()==other.orderWeekDay()){
        if(starthour==other.starthour) return classcode<other.classcode;
        else return starthour<other.starthour;
    }
    return orderWeekDay()<other.orderWeekDay();
}

int Class::orderTypeClasses(){
    if (classtype=="T") return 1;
    return 2;
}

bool Class::operator==(Class &other){
    return(starthour==other.starthour && duration==other.duration
           && classtype==other.classtype && weekday==other.weekday
           && classcode==other.classcode && uccode==other.uccode);
}