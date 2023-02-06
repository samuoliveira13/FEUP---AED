#ifndef PROJETOAED_STUDENT_H
#define PROJETOAED_STUDENT_H

#include <string>
#include <vector>
#include <set>

using namespace std;


class Student {
public:
    Student();
    Student(string studentcode, string studentname,  vector<vector<string>> uc_classcode);

    /**
     * @brief Setter and Getter for studentcode
     * @param studentcode
     * @return the studentcode
     */
    void setStudentcode(string studentcode);
    string getStudentcode();

    /**
     * @brief Setter and Getter for studentname
     * @param studentname
     * @return the studentname
     */
    void setStudentname(string studentname);
    string getStudentname();

    /**
     * @brief Setter and Getter for uc_class_code
     * @param uc_class_code
     * @return the uc_class_code
     */
    void setUc_classcode(vector<vector<string>> uc_class_code);
    vector<vector<string>> getUc_classcode();

    bool operator< (const Student & s) const;
    bool operator==(const Student & s) const;

private:
    string studentcode;
    string studentname;
    vector<vector<string>> uc_classcode;
};

#endif //PROJETOAED_STUDENT_H
