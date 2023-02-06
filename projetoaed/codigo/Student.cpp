#include "include/Student.h"

Student::Student() {}

Student::Student(string studentcode, string studentname, vector<vector<string>> uc_classcode) {
    this -> studentcode = studentcode;
    this -> studentname = studentname;
    this -> uc_classcode = uc_classcode;
}

void Student::setStudentcode(string studentcode) {
    this -> studentcode = studentcode;
}

string Student::getStudentcode() {
    return studentcode;
}

void Student::setStudentname(std::string studentname) {
    this -> studentname = studentname;
}

string Student::getStudentname() {
    return studentname;
}

void Student::setUc_classcode(vector<vector<string>> uc_class_code) {
    this -> uc_classcode = uc_class_code;
}

vector<vector<string>> Student::getUc_classcode() {
    return uc_classcode;
}

bool Student::operator< (const Student & s) const {
    return (this->studentcode < s.studentcode);
}

