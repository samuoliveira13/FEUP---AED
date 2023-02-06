#ifndef PROJETOAED_READER_H
#define PROJETOAED_READER_H

#include <string>
#include <vector>
#include "Class.h"
#include "Student.h"
#include "bst.h"
#include "Classes_per_uc.h"

using namespace std;

class Reader {
public:
    vector<Class> ReadClasses();
    BST <Student> ReadStudent();
    vector<Classes_per_Uc> ReadClasses_per_Uc();
};


#endif //PROJETOAED_READER_H
