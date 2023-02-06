#ifndef PROJETOAED_REQUEST_H
#define PROJETOAED_REQUEST_H

#include <vector>
#include "Student.h"

class Request{
public:
    Request();
    Request(Student join_class);
    Request(pair<Student,Student> change_class);
    Request(vector<pair<Student,Student>> change_some_classes);
    Student getStudenttoJoin();
    pair<Student,Student> changing();
    vector<pair<Student,Student>> vector_changing();

private:
    Student join_class;
    pair<Student,Student> change_class;
    vector<pair<Student,Student>> change_some_classes;
};
#endif //PROJETOAED_REQUEST_H
