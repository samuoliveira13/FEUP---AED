
#ifndef PROJETOAED_MENU_H
#define PROJETOAED_MENU_H

#include <string>
#include <vector>
#include <list>
#include "Class.h"
#include "Student.h"
#include "Horario.h"
#include "Request.h"
#include "Reader.h"

class Menu {

public:
    Menu();
    Menu(int x);
    BST<Student> getStudentList();
    vector<Class> getClassList();
private:

    void Wait();
    /**
     * @brief Main Menu. Executes first and asks user what he wants to do
     */
    void mainMenu();

    /**
     * @brief Returns the student's schedule
     */
    void EstudanteHorario();

    /**
     * @brief Returns the class' schedule
     */
    void TurmaHorario();

    /**
     * @brief Returns the UCÂ´s schedule
     */
    void CadeiraHorario();

    /**
     * @brief Returns the UC's schedule in a class
     */
    void CadeirainTurmaHorario();

    /**
     * @brief Returns the name and number of students in a class
     */
    void EstudanteTurma();

    /**
     * @brief Returns the name and number of students in a UC
     */
    void EstudanteCadeira();

    /**
     * @brief Returns the name and number of students in a UC, in a class
     */
    void EstudanteCadeiraTurma();

    /**
     * @brief counts the number of stundents in a UC, in a class
     * @param cadeira
     * @param turma
     * @return
     */
    int EstudanteCadeiraTurmacount(string cadeira,string turma);

    /**
     * @brief Executes in the end of each process. Asks user if he is done using the programm
     */
    void AfterExec();

    /**
     * @brief Returns the name and number of students that have more than n (input) UCs
     * @param aluno
     */
    void MaisCadeiras();

    /**
     * @brief returns the students in a year
     */
    void EstudanteinAno();

    /**
     * @brief removes a student from a class
     * @param aluno
     */
    void LeaveClass(string aluno);

    /**
     * @brief Inserts a student in a class
     * @param aluno
     */
    void JoinClass(string aluno);

    /**
     * @brief Changes a student from one class to another
     * @param aluno
     */
    void ChangeClass(string aluno);

    /**
     * @brief Changes a student from multiples classes to others
     * @param aluno
     */

    void ChangesomeClasses(string aluno);

    /**
     * @brief changes the student if the parameters are met
     * @param request
     * @return
     */
    int ChangeifPossible(pair<Request,int> request);
    pair<int,int> students_per_class(string uc);
    set<string> turmas(string cadeira);

    /**
     * @brief checks if two classes are compatible
     * @param x
     * @param y
     * @return
     */
    bool Compativeis(Class x,Class y);


    /**
     * @brief checks if the class exists
     * @param turma
     * @return
     */
    bool TurmaExists(std::string turma);

    /**
     * @brief Checks if the UC exists in the class
     * @param turma
     * @param cadeira
     * @return
     */
    bool CadeirainTurmaExists(std::string turma, std::string cadeira);

    /**
     * @brief Checks if the student exists
     * @param turma
     * @return
     */
    bool StudentExists(Student aluno);

    /**
     * @brief Checks if the UC exists
     * @param turma
     * @return
     */
    bool CadeiraExists(std::string turma);

    /**
     * @brief Checks if the student exists in the UC
     * @param turma
     * @param aluno
     * @return
     */
    bool AlunoinCadeiraExists(std::string aluno, std::string turma);

    Reader reader = Reader();
    vector<Class> classList = reader.ReadClasses();
    BST<Student> studentList = reader.ReadStudent();
    vector<Classes_per_Uc> classes_per_uc = reader.ReadClasses_per_Uc();
    queue<pair<string,pair<Request,int>>> pedidos;
    list<pair<string,Request>> arquivos;
    Horario horario;
    string aluno;
};


#endif //PROJETOAED_MENU_H
