#include "include/Request.h"

Request::Request(){}

Request::Request(Student join_class){
    this->join_class=join_class;
}
Request::Request(pair<Student,Student> change_class) {
    this->change_class=change_class;
}
Request::Request(vector<pair<Student,Student>> change_some_classes){
    this->change_some_classes=change_some_classes;
}

Student Request::getStudenttoJoin(){
    return join_class;
}
pair<Student,Student> Request::changing() {
    return change_class;
}
vector<pair<Student,Student>> Request::vector_changing(){
    return change_some_classes;
}
