#include "include/Classes_per_uc.h"
Classes_per_Uc::Classes_per_Uc() {}

Classes_per_Uc::Classes_per_Uc(std::string cadeira, std::string turma) {
    this->cadeira=cadeira;
    this->turma=turma;
}
string Classes_per_Uc::getCadeira() {
    return cadeira;
}
string Classes_per_Uc::getTurma() {
    return turma;
}


bool Classes_per_Uc::operator<(Classes_per_Uc &other) {
    if(cadeira==other.cadeira) return turma<other.turma;
    return cadeira<other.cadeira;
}

bool Classes_per_Uc::operator==(Classes_per_Uc &other){
    return(cadeira==other.cadeira && turma==other.turma);
}