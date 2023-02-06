#ifndef PROJETOAED_CLASSES_PER_UC_H
#define PROJETOAED_CLASSES_PER_UC_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Classes_per_Uc{
public:

    Classes_per_Uc();

    /**
     * @brief
     * @param cadeira
     * @param turma
     */
    Classes_per_Uc(string cadeira,string turma);

    /**
     * @brief Getter for Turma
     * @return
     */
    string getTurma();

    /**
     * @brief Getter for Cadeira
     * @return
     */
    string getCadeira();


    bool operator<(Classes_per_Uc &other);
    bool operator==(Classes_per_Uc &y);

private:
    string turma;
    string cadeira;
};
#endif //PROJETOAED_CLASSES_PER_UC_H