#ifndef PROJETOAED_HORARIO_H
#define PROJETOAED_HORARIO_H

#include <vector>
#include "Class.h"
#include "Student.h"

class Horario{
public:
    Horario();
    vector<Class> getHorario(string aluno);

    /**
     * @brief clears schedule
     */
    void clear();

    /**
     * @brief inserts x in horario
     * @param x
     */
    void push_back(Class x);

    /**
     * @brief asks the type of schedule order
     * @return
     */
    int type_of_order();

    /**
     * @brief prints schedule
     */
    void print();
    vector<Class>::iterator begin();
    vector<Class>::iterator end();

    /**
     * @brief Orders the class in default order (Monday -> Tuesday -> Wednesday, etc)
     * @param x
     * @param y
     * @return
     */
    bool static default_order(Class x,Class y);

    /**
     * @brief Orders schedule in reverse (Friday -> Thursday -> Wednesday,etc)
     * @param x
     * @param y
     * @return
     */
    bool static decrescent_order(Class x,Class y);

    /**
     * @brief Orders schedule with theoric classes first
     * @param x
     * @param y
     * @return
     */
    bool static theorics_first(Class x,Class y);

    /**
     * @brief Orders schedule by the UcCode
     * @param x
     * @param y
     * @return
     */
    bool static uc_code_order(Class x,Class y);

    /**
     * @brief Orders the schedule by the class duration
     * @param x
     * @param y
     * @return
     */
    bool static class_duration_order(Class x,Class y);

    void add(Student student);
private:
    vector<Class> horario;

    string SumHours(float starthour, float duration);

    string TransformHour(float hour);
};

#endif //PROJETOAED_HORARIO_H
