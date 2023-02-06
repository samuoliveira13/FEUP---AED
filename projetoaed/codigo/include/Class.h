#ifndef PROJETOAED_CLASS_H
#define PROJETOAED_CLASS_H

#include <string>
using namespace std;

class Class {
public:
    Class(string classcode, string uccode, string weekday, float starthour, float duration, string classtype);

    /**
     * @brief Setter and Getter for uccode
     * @param uccode
     * @return uccode
     */
    void setUccode(string uccode);
    string getUccode();

    /**
     * @brief Setter and Getter for classtype
     * @param classtype
     * @return classtype
     */
    void setClasstype(string classtype);
    string getClassType();

    /**
     * @brief Setter and Getter for starthour
     * @param starthour
     * @return starthour
     */
    void setStarthour(float starthour);
    float getStarthour();

    /**
     * @brief Setter and Getter for duration
     * @param duration
     * @return duration
     */
    void setDuration(float duration);
    float getDuration();

    /**
     * @brief Getter for WeekDay
     * @return WeekDay
     */
    string getWeekDay();

    /**
     * @brief Getter for ClassCode
     * @return ClassCode
     */
    string getClassCode();

    /**
     * @brief Weekday Order (Monday -> Tuesday -> Wednesday, etc)
     * @return ordered weekdays
     */
    int orderWeekDay();

    /**
     * @brief Different ways or ordering the schedules
     * @return the ordered schedules
     */
    int orderTypeClasses();

    bool operator<(Class &other);
    bool operator==(Class &other);

private:
    string classcode;
    string uccode;
    string weekday;
    float starthour;
    float duration;
    string classtype;

};


#endif //PROJETOAED_CLASS_H