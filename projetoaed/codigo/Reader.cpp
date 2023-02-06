#include "include/Reader.h"
#include "include/Class.h"
#include "include/Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "include/bst.h"
#include "include/Classes_per_uc.h"

using namespace std;


vector<Class> Reader::ReadClasses() {
    int firstLine = 0;
    bool fim = true;
    fstream fin;
    fin.open("../schedule/classes.csv", ios::in);
    vector<Class> classList = {};
    vector<string> row;
    string line, word, temp;

    while (fim) {
        row.clear();
        getline(fin, line);
        if(line== "") break;
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        //para passar a primeira linha
        if (firstLine == 0){
            firstLine++;
            continue;
        }

        classList.push_back(Class(row[0], row[1], row[2], stof(row[3]), stof(row[4]), row[5]));
    }
    return classList;
}


BST<Student> Reader::ReadStudent() {
    int firstLine = 0;
    bool fim = true;
    fstream fin;
    fin.open("../schedule/students_classes.csv", ios::in);
    BST<Student> studentList = BST<Student>(Student("","",{{}}));
    vector<string> row;
    string line, word, temp;
    Student student_code = Student("", "", {{}});
    vector<vector<string>> uc_classcode;

    while(fim) {
        row.clear();
        getline(fin, line);
        if(line == "") break;
        stringstream s(line);
        while(getline(s, word, ',')){
            row.push_back(word);
        }

        if(firstLine == 0){
            firstLine++;
            continue;
        }
        if(student_code.getStudentcode() == row[0]) {
            Student curr = studentList.find(student_code);
            uc_classcode = curr.getUc_classcode();
            uc_classcode.push_back({row[2],row[3]});
            studentList.remove(curr);
            curr.setUc_classcode(uc_classcode);
            studentList.insert(curr);
            continue;
        }

        student_code.setStudentcode(row[0]);
        Student student = Student(row[0], row[1], {{row[2], row[3]}});
        studentList.insert(student);
    }

    return studentList;
}

vector<Classes_per_Uc> Reader::ReadClasses_per_Uc() {
    int firstLine = 0;
    fstream fin;
    fin.open("../schedule/classes_per_uc.csv", ios::in);
    vector<Classes_per_Uc> classes_per_uc = {};
    vector<string> row;
    string line, word, temp;
    while(true){
        row.clear();
        getline(fin, line);
        if(line == "") break;
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        //para passar a primeira linha
        if (firstLine == 0){
            firstLine++;
            continue;
        }
        classes_per_uc.push_back(Classes_per_Uc(row[0], row[1]));
    }
    sort(classes_per_uc.begin(),classes_per_uc.end());
    return classes_per_uc;
}