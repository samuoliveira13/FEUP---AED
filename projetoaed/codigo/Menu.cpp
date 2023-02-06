#include "include/Menu.h"
#include "include/Reader.h"
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include "include/bst.h"
#include "include/Horario.h"
#include "include/Request.h"

using namespace std;
int max_cap=23;
int order;


Menu::Menu() {

}
Menu::Menu(int x){
    mainMenu();
}


void Menu::Wait() {
    int waited;
    cout<<"Pressione 1 se quiser fazer alguma operacao com o seu horario"<<endl;
    cout<<"Pressione 2 se quiser sair (o programa termina)"<<endl;
    cin>>waited;
    switch (waited) {
        case 1:
            mainMenu();
            break;
        default:
            exit(-1);
    }
}

void Menu::mainMenu() {
    if (pedidos.size() >= 1) {
        while (pedidos.size()!=0) {
            pair<Request,int> request = pedidos.front().second;
            int change= ChangeifPossible(request);
            pedidos.pop();
        }
    }
    int input;
    cout << "==============================================================" << endl << endl;
    cout << "Bem Vindo" << endl << endl;
    cout << "1 -> Ver Horarios" << endl;
    cout << "2 -> Ver Estudantes" << endl;
    cout << "3 -> Efetuar Alteracoes" << endl;
    cout << "4 -> Verificar se o pedido de ingressar numa turma foi aceite" << endl;
    cout << "5 -> Sair" << endl << endl;
    cout << "==============================================================" << endl;
    cin >> input;
    cout << endl;
    int count1=0;
    int count2=0;

    switch (input) {
        case 1:
            int input1;
            cout << "==============================================================" << endl << endl;
            cout << "1 -> Ver o Horario de um Estudante." << endl;
            cout << "2 -> Ver o Horario de uma Turma" << endl;
            cout << "3 -> Ver o Horario de uma Cadeira" << endl;
            cout << "4 -> Ver o Horario de uma Cadeira, numa determinada Turma" << endl;
            cout << "Outro numero -> Sair" << endl << endl;
            cout << "==============================================================" << endl;
            cin >> input1;

            switch (input1) {
                case 1:
                    EstudanteHorario();
                    break;
                case 2:
                    TurmaHorario();
                    break;
                case 3:
                    CadeiraHorario();
                    break;
                case 4:
                    CadeirainTurmaHorario();
                    break;
                default:
                    Wait();

            }
        case 2:
            int input2;
            cout << "==============================================================" << endl << endl;
            cout << "1 -> ver os estudantes de uma turma." << endl;
            cout << "2 -> ver os estudantes de uma cadeira" << endl;
            cout << "3 -> ver os estudantes de uma cadeira, numa determinada turma" << endl;
            cout << "4 -> ver os estudantes com mais de n cadeias" << endl;
            cout << "5 -> ver os estudantes num determinado ano"<<endl;
            cout << "6-> Sair" << endl << endl;
            cout << "==============================================================" << endl;
            cin >> input2;

            switch (input2) {
                case 1:
                    EstudanteTurma();
                    break;
                case 2:
                    EstudanteCadeira();
                    break;
                case 3:
                    EstudanteCadeiraTurma();
                    break;
                case 4:
                    MaisCadeiras();
                    break;
                case 5:
                    EstudanteinAno();
                    break;
                default:
                    Wait();
            }

        case 3:
            do {
                cout << "Introduza o seu up" << endl;
                cin >> aluno;
            } while (!StudentExists(Student(aluno, "", {})));

            int input3;
            cout << "==============================================================" << endl << endl;
            cout << "1 -> sair de uma turma"<<endl;
            cout << "2 -> entrar numa turma"<<endl;
            cout << "3 -> modificar uma turma"<<endl;
            cout << "4 -> modificar varias turmas"<<endl;
            cout << "5-> Sair" << endl << endl;
            cout << "==============================================================" << endl;
            cin >> input3;
            switch (input3) {
                case 1:
                    LeaveClass(aluno);
                    break;
                case 2:
                    JoinClass(aluno);
                    break;
                case 3:
                    ChangeClass(aluno);
                    break;
                case 4:
                    ChangesomeClasses(aluno);
                    break;
                default:
                    Wait();
            }

        case 4:
            do {
                cout << "Introduza o seu up" << endl;
                cin >> aluno;
            } while (!StudentExists(Student(aluno,"", {})));
            for(auto x:arquivos){
                if(x.first==aluno){
                    count1++;
                }
            }
            if(count1>0) cout<< count1<< " dos seus pedidos nao puderam ser validados"<<endl;
            for(int m=0;m<pedidos.size();m++){
                pair<string,pair<Request,int>> front=pedidos.front();
                pedidos.pop();
                if (front.first==aluno){
                    count2++;
                }
                pedidos.push(front);
            }
            if(count2>0) cout<<count2<< " dos seus pedidos ainda esta(ao) a espera de ser processado(s)"<<endl;
            if(count1==0 && count2==0) cout<< "Todos os seus pedidos foram processados com exito "<< endl;
            else cout<< "O resto dos seus pedidos foram processados com exito"<<endl;
            mainMenu();
        default:
            Wait();
    }

}


void Menu::EstudanteHorario() {
    cout << "Introduza o numero de estudante:";
    cin >> aluno;
    cout << endl;
    horario.clear();
    Student student = Student(aluno, "", {});
    if (StudentExists(student) == false) {                        //se o up nao existir
        cout << "O numero que introduziu nao e valido" << endl;
        EstudanteHorario();                                     //reiniciar funcao
    } else {
        Student student1 = studentList.find(student);
        vector<vector<string>> classes = student1.getUc_classcode();
        for (int i = 0; i < classes.size(); i++) {
            string uccode = classes[i][0];
            string classcode = classes[i][1];
            for (int j = 0; j < classList.size(); j++) {
                if (classcode == classList[j].getClassCode() && uccode == classList[j].getUccode())
                    horario.push_back(classList[j]);
            }
        }
    }
    order = horario.type_of_order();
    switch (order) {
        case 2:
            sort(horario.begin(), horario.end(), horario.decrescent_order);
            break;
        case 3:
            sort(horario.begin(), horario.end(), horario.theorics_first);
            break;
        case 4:
            sort(horario.begin(), horario.end(), horario.uc_code_order);
            break;
        case 5:
            sort(horario.begin(), horario.end(), horario.class_duration_order);
            break;
        default:
            sort(horario.begin(), horario.end(), horario.default_order);
            break;
    }
    horario.print();
    AfterExec();
}


    void Menu::TurmaHorario() {
        string turma;
        cout << "Introduza o numero da turma: ";
        cin >> turma;
        cout << endl;
        horario.clear();

        if (TurmaExists(turma) == false) {                          //se a turma nao existir
            cout << "A turma que introduziu nao e valida" << endl;
            TurmaHorario();                                         //reiniciar funcao
        } else {
            for (int i = 0; i < classList.size(); i++) {
                if (classList[i].getClassCode() == turma) {         //se a turma for igual
                    horario.push_back(classList[i]);
                }
            }
        }
        order=horario.type_of_order();
        switch(order){
            case 2:
                sort(horario.begin(),horario.end(),horario.decrescent_order);
                break;
            case 3:
                sort(horario.begin(),horario.end(),horario.theorics_first);
                break;
            case 4:
                sort(horario.begin(),horario.end(),horario.uc_code_order);
                break;
            case 5:
                sort(horario.begin(),horario.end(),horario.class_duration_order);
                break;
            default:
                sort(horario.begin(),horario.end(),horario.default_order);
                break;
        }
        horario.print();
        AfterExec();        //perguntar se acabou ou nao
    }


void Menu::CadeiraHorario() {
    string cadeira;
    cout << "Introduza o numero da cadeira: ";
    cin >> cadeira;
    cout << endl;
    horario.clear();

    if (CadeiraExists(cadeira) == false) {                  //se a cadeira nao existir
        cout << "A cadeira que introduziu nao e valida" << endl;
        CadeiraHorario();                                         //reiniciar funcao
    } else {
        for (int i = 0; i < classList.size(); i++) {
            if (classList[i].getUccode() == cadeira) {              //se a cadeira for igual
                horario.push_back(classList[i]);
            }
        }
    }
    order=horario.type_of_order();
    switch(order){
        case 2:
            sort(horario.begin(),horario.end(),horario.decrescent_order);
            break;
        case 3:
            sort(horario.begin(),horario.end(),horario.theorics_first);
            break;
        case 4:
            sort(horario.begin(),horario.end(),horario.uc_code_order);
            break;
        case 5:
            sort(horario.begin(),horario.end(),horario.class_duration_order);
            break;
        default:
            sort(horario.begin(),horario.end(),horario.default_order);
            break;
    }
    horario.print();
    AfterExec();        //perguntar se acabou ou nao
}


void Menu::CadeirainTurmaHorario() {
    string turma;
    string cadeira;
    cout << "Introduza a turma: ";
    cin >> turma;
    cout << endl;
    horario.clear();

    if (TurmaExists(turma) == false) {                          //se a turma nao existir
        cout << "A turma que introduziu não existe" << endl;
        CadeirainTurmaHorario();                                //reiniciar funcao
    } else {
        cout << "Introduza o codigo da cadeira: ";
        cin >> cadeira;
        cout << endl;
        if(CadeiraExists(cadeira) == false){
            cout << "A cadeira que introduziu nao e valida" << endl;
            CadeirainTurmaHorario();
        }
        else if (CadeirainTurmaExists(turma, cadeira) == false) {    //se a cadeira nao existir na turma
            cout << "A cadeira nao existe na turma" << endl;
            CadeirainTurmaHorario();                            //reiniciar funcao
        } else {
            for (int i = 0; i < classList.size(); i++) {
                if (classList[i].getUccode() == cadeira &&                  //se a cadeira e a
                    classList[i].getClassCode() == turma){                  //turma forem iguais
                    horario.push_back(classList[i]);
                }
            }
        }
    }
    order=horario.type_of_order();
    switch(order){
        case 2:
            sort(horario.begin(),horario.end(),horario.decrescent_order);
            break;
        case 3:
            sort(horario.begin(),horario.end(),horario.theorics_first);
            break;
        case 4:
            sort(horario.begin(),horario.end(),horario.uc_code_order);
            break;
        case 5:
            sort(horario.begin(),horario.end(),horario.class_duration_order);
            break;
        default:
            sort(horario.begin(),horario.end(),horario.default_order);
            break;
    }
    horario.print();
    AfterExec();        //perguntar se acabou ou nao
}


void Menu::EstudanteTurma() {
    set<string> classStudents = {};
    string turma;
    cout << "Introduza a turma: ";
    cin >> turma;
    cout << endl;

    if (TurmaExists(turma) == false) {                          //se a turma nao existir
        cout << "A turma que introduziu nao e valida" << endl;
        EstudanteTurma();                                       //reiniciar funcao
    } else {

        for(iteratorBST<Student> it = studentList.begin(); it != studentList.end(); it++){
            Student aluno = studentList.find(*it);
            vector<vector<string>> uc_classcode = aluno.getUc_classcode();
            for(int i = 0; i < uc_classcode.size(); i++)
                if(uc_classcode[i][1] == turma)
                    classStudents.insert(aluno.getStudentname());
        }

        cout << "A turma " << turma << " tem " << classStudents.size() << " alunos:" << endl;

        for (string student: classStudents) {
            cout << student << endl;            //print a cada aluno
        }
    }
    AfterExec();        //perguntar se acabou ou nao
}


void Menu::EstudanteCadeira() {
    set<string> ucStudents = {};
    string cadeira;
    cout << "Introduza a cadeira: ";
    cin >> cadeira;
    cout << endl;

    if (CadeiraExists(cadeira) == false) {                  //se a cadeira nao existir
        cout << "A cadeira que introduziu nao e valida" << endl;
        EstudanteCadeira();                                       //reiniciar funcao
    } else {

        for(iteratorBST<Student> it = studentList.begin(); it != studentList.end(); it++){
            Student aluno = studentList.find(*it);
            vector<vector<string>> uc_classcode = aluno.getUc_classcode();
            for(int i = 0; i < uc_classcode.size(); i++)
                if(uc_classcode[i][0] == cadeira)
                    ucStudents.insert(aluno.getStudentname());
        }

        cout << "A cadeira " << cadeira << " tem " << ucStudents.size() << " alunos:" << endl;

        for (string student: ucStudents) {
            cout << student << endl;            //print a cada aluno
        }
    }
    AfterExec();        //perguntar se acabou ou nao
}


void Menu::EstudanteCadeiraTurma() {
    set<string> ucStudents = {};
    string turma;
    string cadeira;
    cout << "Introduza a turma: ";
    cin >> turma;
    cout << endl;

    if (TurmaExists(turma) == false) {                          //se a turma nao existir
        cout << "A turma que introduziu não existe" << endl;
        EstudanteCadeiraTurma();                              //reiniciar funcao
    } else {
        cout << "Introduza o codigo da cadeira: ";
        cin >> cadeira;
        cout << endl;
        if(CadeiraExists(cadeira) == false){
            cout << "A cadeira que introduziu nao e valida" << endl;
            EstudanteCadeiraTurma();
        }
        else if (CadeirainTurmaExists(turma, cadeira) == false) {    //se a cadeira nao existir na turma
            cout << "A cadeira nao existe na turma" << endl;
            EstudanteCadeiraTurma();                           //reiniciar funcao

        } else {
            cout << endl;

            for(iteratorBST<Student> it = studentList.begin(); it != studentList.end(); it++) {
                Student aluno = studentList.find(*it);
                vector<vector<string>> uc_classcode = aluno.getUc_classcode();
                for (int i = 0; i < uc_classcode.size(); i++) {
                    if (uc_classcode[i][1] == turma && uc_classcode[i][0] == cadeira)
                        ucStudents.insert(aluno.getStudentname());
                }

            }

            cout << "A cadeira " << cadeira << " da turma " << turma << " tem " << ucStudents.size() << " alunos" << endl;

            for (string student: ucStudents) {
                cout << student << endl;            //print a cada aluno
            }
        }
    }
    AfterExec();        //perguntar se acabou ou nao
}


void Menu::MaisCadeiras() {
    int n;
    set<string> ucStudents = {};
    cout << "Introduza o numero de cadeiras: ";
    cin >> n;
    cout << endl;

    for(iteratorBST<Student> it = studentList.begin(); it != studentList.end(); it++){
        Student aluno = studentList.find(*it);
        vector<vector<string>> uc_classcode = aluno.getUc_classcode();
        if(uc_classcode.size() > n ) ucStudents.insert(aluno.getStudentname());
    }

    if (ucStudents.size() == 0) {
        cout << "Nao ha nenhum aluno com mais de " << n << " cadeiras." << endl;
    }
    else {
        cout << "Ha " << ucStudents.size() << " alunos com mais de " << n << " cadeiras: " << endl;

        for (string student: ucStudents) {
            cout << student << endl;
        }
    }
    AfterExec();        //perguntar se acabou ou nao
}
void Menu::EstudanteinAno(){
    char year_searching;
    cout<<"Digite o ano que queira saber quantos alunos existem"<<endl;
    cin >> year_searching;
    if(year_searching!='1' && year_searching!='2' && year_searching!='3'){
        cout<<"O ano que introduziu nao e valido"<<endl;
        EstudanteinAno();
    }
    set<pair<string,string>> alunos_in_ano={};
    for(iteratorBST<Student> it = studentList.begin(); it != studentList.end(); it++){
        Student aluno = studentList.find(*it);
        vector<vector<string>> cadeiras = aluno.getUc_classcode();
        for(auto x:cadeiras) {
            if (x[1][0] == year_searching) {
                alunos_in_ano.insert(make_pair(aluno.getStudentcode(), aluno.getStudentname()));
                break;
            }
        }
    }
    cout<<"Nesse ano existem "<<alunos_in_ano.size()<<" alunos inscritos no curso:"<<endl<<endl;
    for(auto x:alunos_in_ano){
        cout<<x.first<<"|"<<x.second<<endl;
    }
    cout<<endl;
    AfterExec();
}

void Menu::LeaveClass(string aluno) {
    string cadeira;

    Student student = Student(aluno, "", {});

        cout << "Introduza a cadeira: " << endl;
        cin >> cadeira;
        if (AlunoinCadeiraExists(aluno, cadeira) == false) {
            cout << "O aluno nao esta inscrito na cadeira que introduziu" << endl;
            LeaveClass(aluno);
        } else {
            Student student1 = studentList.find(student);
            vector<vector<string>> uc_classcode = student1.getUc_classcode();
            for(auto it = uc_classcode.begin(); it < uc_classcode.end();it++){
                if((*it)[0] == cadeira){
                    uc_classcode.erase(it);
                }
            }
            studentList.remove(student1);
            student1.setUc_classcode(uc_classcode);
            studentList.insert(student1);

            cout << "O aluno " << aluno << " foi removido da " << cadeira << endl;
        }

    AfterExec();
}


void Menu::JoinClass(string aluno) {
    string turma;
    string cadeira;
    Student student = Student(aluno, "", {});

    cout << "Introduza a turma que deseja ingressar: ";
    cin >> turma;
    cout << endl;

    if (!TurmaExists(turma)) {                      //se a turma nao existir
        cout << "A turma que introduziu nao existe" << endl;
        JoinClass(aluno);                            //reiniciar funcao
    } else {
        cout << "Introduza o codigo da cadeira que deseja ingressar: "<<endl;
        cin >> cadeira;
        if (!CadeiraExists(cadeira)) {    //se a cadeira nao existir dentro da turma
            cout << "A cadeira nao existe" << endl;
            JoinClass(aluno);
        }
    }
    if(!TurmaExists(turma) || !CadeiraExists(cadeira)){
        cout << "A cadeira ou turma que introduziu nao e valida" << endl;
        JoinClass(aluno);
    }
    Classes_per_Uc searching={cadeira,turma};
    bool found= false;
    for(vector<Classes_per_Uc>::iterator it=classes_per_uc.begin();it!=classes_per_uc.end();it++){
        if(*it==searching){
            found=true;
            break;
        }
    }
    if (found==false){
        cout<<"A turma que introduziu nao tem essa cadeira"<<endl;
        JoinClass(aluno);
    }
    else if(AlunoinCadeiraExists(aluno,cadeira)){
        int input;
        cout << "Ja esta inscrito nesta cadeira"<< endl << endl;
        cout << "Deseja mudar de turma?" << endl;
        cout << "1->Sim"<< endl;
        cout << "2->Nao e voltar ao menu principal"<< endl;
        cin>>input;
        switch (input) {
            case 1:
                ChangeClass(aluno);
            default:
                Wait();
        }
    }
         else {
            Student student = studentList.find(Student(aluno, "", {}));

            Student asking_to_join=Student(aluno,student.getStudentname(),{{cadeira,turma}});
            Request request = asking_to_join;
            pedidos.push(make_pair(aluno,make_pair(request,1)));
            int repetir;
            cout << "O seu pedido foi registado, volte mais tarde e verifique se foi aceite ou nao."<<endl<<endl;
            cout << "Deseja juntar-se a mais alguma turma?"<< endl;
            cout << "1->Sim"<<endl;
            cout << "2->Nao, mas desejo trocar uma turma atual"<<endl;
            cout << "3->Nao e voltar ao menu principal"<< endl;
            cout << "Outro->Nao e sair"<<endl;
            cin>>repetir;
            switch (repetir) {
                case 1:
                    JoinClass(aluno);
                case 2:
                    ChangeClass(aluno);
                case 3:
                    mainMenu();
                default:
                    Wait();
        }
    }
}


void Menu::ChangeClass(string aluno) {
    string turma;
    string cadeira;
    cout << "Introduza a turma que deseja ingressar: ";
    cin >> turma;
    cout << endl;

    if (!TurmaExists(turma)) {                    //se a turma nao existir
        cout << "A turma que introduziu nao existe" << endl;
        ChangeClass(aluno);                            //reiniciar funcao
    } else {
        cout << "Introduza o codigo da cadeira: "<<endl;
        cin >> cadeira;
        if (!CadeiraExists(cadeira)) {    //se a cadeira nao existir dentro da turma
            cout << "A cadeira nao existe" << endl;
            ChangeClass(aluno);
        }
    }
    if(!AlunoinCadeiraExists(aluno,cadeira)){
        int option;
        cout<< "Nao esta inscrito nessa cadeira"<<endl<<endl;
        cout<< "Deseja ingressar numa turma com essa cadeira?"<<endl;
        cout<< "1->Sim"<<endl;
        cout<< "2->Nao, voltar ao Menu principal"<<endl;
        cin>>option;
        if(option==1) JoinClass(aluno);
        else mainMenu();
    }
    Classes_per_Uc searching={cadeira,turma};
    bool found= false;
    for(vector<Classes_per_Uc>::iterator it=classes_per_uc.begin();it!=classes_per_uc.end();it++){
        if(*it==searching){
            found=true;
            break;
        }
    }
    if (found==false){
        cout<<"A turma que introduziu nao tem essa cadeira"<<endl;
        ChangeClass(aluno);
    }

    Student turma_inicial = studentList.find(Student(aluno, "", {}));
    vector<vector<string>> uc_classcode = turma_inicial.getUc_classcode();
    vector<vector<string>> original;
    for(int i = 0; i < uc_classcode.size();i++){
        if(uc_classcode[i][0] == cadeira){
            original.push_back({cadeira, uc_classcode[i][1]});
            break;
        }
    }
    turma_inicial.setUc_classcode(original);
    Student turma_final = {aluno, turma_inicial.getStudentname(), {{cadeira, turma}}};
    Request request=make_pair(turma_inicial,turma_final);
    pedidos.push(make_pair(aluno,make_pair(request,2)));
    cout << "O seu pedido foi registado, volte mais tarde e verifique se foi aceite ou nao." << endl << endl;
    AfterExec();

}



void Menu::ChangesomeClasses(string aluno) {
    vector<pair<Student,Student>> requests;
    string turma;
    string cadeira;
    bool flag=true;
    while(flag) {
        cout << "Introduza a turma que deseja ingressar: ";
        cin >> turma;
        cout << endl;

        if (!TurmaExists(turma)) {                      //se a turma nao existir
            cout << "A turma que introduziu nao existe" << endl;
            continue;                           //reiniciar funcao
        }
        cout << "Introduza o codigo da cadeira: " << endl;
        cin >> cadeira;
        if (!CadeiraExists(cadeira)) {    //se a cadeira nao existir dentro da turma
            cout << "A cadeira nao existe" << endl;
            continue;
        }
        if (!TurmaExists(turma) || !CadeiraExists(cadeira)) {
            cout << "A cadeira ou turma que introduziu nao e valida" << endl;
            continue;
        }
        Classes_per_Uc searching = {cadeira, turma};
        bool found = false;
        for (vector<Classes_per_Uc>::iterator it = classes_per_uc.begin(); it != classes_per_uc.end(); it++) {
            if (*it == searching) {
                found = true;
                break;
            }
        }
        if (found == false) {
            cout << "A turma que introduziu nao tem essa cadeira" << endl;
            continue;
        }

        Student turma_inicial = studentList.find(Student(aluno, "", {}));
        vector<vector<string>> uc_classcode = turma_inicial.getUc_classcode();
        vector<vector<string>> original;
        for (int i = 0; i < uc_classcode.size(); i++) {
            if (uc_classcode[i][0] == cadeira) {
                original.push_back({cadeira, uc_classcode[i][1]});
                break;
            }
        }
        turma_inicial.setUc_classcode(original);
        Student turma_final = {aluno, turma_inicial.getStudentname(), {{cadeira, turma}}};
        Request request = make_pair(turma_inicial, turma_final);
        pedidos.push(make_pair(aluno, make_pair(request, 2)));

        int repetir;
        cout << "Deseja adicionar mais algum pedido de troca de turma?" << endl << endl;
        cout << "1->Sim" << endl;
        cout << "2->Nao" << endl;
        cin >> repetir;
        if (repetir != 1) flag = false;

    }
    Request request=requests;
    pedidos.push(make_pair(aluno,make_pair(request,3)));
    cout << "O seu pedido foi registado, volte mais tarde e verifique se foi aceite ou nao."<<endl<<endl;
    AfterExec();

}

int Menu::EstudanteCadeiraTurmacount(string uccode,string turma) {
    set<string> ucStudents = {};
    for (iteratorBST<Student> it = studentList.begin(); it != studentList.end(); it++) {
        Student aluno = studentList.find(*it);
        vector<vector<string>> uc_classcode = aluno.getUc_classcode();
        for (int i = 0; i < uc_classcode.size(); i++) {
            if (uc_classcode[i][1] == turma && uc_classcode[i][0] == uccode)
                ucStudents.insert(aluno.getStudentname());
        }
    }
    return ucStudents.size(); //fiz desta maneira porque não estava a funcionar a maneira anterior, e, como o
                              //EstudantesinCadeiraTurma() estava a funcionar, copiei esse método e é só dar return ao size;
}


int Menu::ChangeifPossible(pair<Request, int> request) {
    int min_turma;
    int max_turma;
    int total_da_turma;
    bool compativel = true;
    horario.clear();
    aluno = pedidos.front().first;
    pair<int, int> values;
    //vector<Student>::iterator it=studentList.begin();
    Student finding;
    vector<pair<Student, Student>> to_process;
    if (request.second == 1) {
        Student joining = request.first.getStudenttoJoin();
        horario.getHorario(aluno);
        horario.add(joining);
        for (Class x: horario) {
            if (x.getClassType() == "T") continue;
            if (x.getUccode() != joining.getUc_classcode()[0][0])
                continue;
            for (Class y: horario) {
                if (!(x == y)) compativel = Compativeis(x, y);
                if (compativel == false) break;
            }
            if (compativel == false) break;
        }
        if (compativel == false) {
            arquivos.push_back(make_pair(joining.getStudentcode(), request.first));
        } else {
            values = students_per_class(joining.getUc_classcode()[0][0]);
            min_turma = values.first;
            total_da_turma = EstudanteCadeiraTurmacount(joining.getUc_classcode()[0][0], joining.getUc_classcode()[0][1]) + 1;
            max_turma = max(values.second, total_da_turma);
            if (total_da_turma > max_cap || total_da_turma - min_turma >= 4 || max_turma - total_da_turma >= 4) {
                arquivos.push_back(make_pair(joining.getStudentcode(), request.first));
            } else {
                Student student1 = studentList.find(joining);
                vector<vector<string>> uc_classcode = student1.getUc_classcode();
                for (auto it = uc_classcode.begin(); it < uc_classcode.end(); it++) {
                    if ((*it)[0] == joining.getUc_classcode()[0][0]) {
                        uc_classcode.erase(it);
                    }
                }
                studentList.remove(student1);
                student1.setUc_classcode(uc_classcode);
                studentList.insert(student1);
            }
        }
    } else if (request.second == 2) {
        Student leaving = request.first.changing().first;
        Student joining = request.first.changing().second;
        horario.getHorario(joining.getStudentcode());
        horario.add(joining);
        for (Class x: horario) {
            if (x.getClassType() == "T") continue;
            if (x.getUccode() != joining.getUc_classcode()[0][0] ||
                x.getClassCode() != joining.getUc_classcode()[0][1])
                continue;
            for (Class y: horario) {
                if (!(x == y)) compativel = Compativeis(x, y);
                if (compativel == false) break;
            }
            if (compativel == false) break;
        }
        if (compativel == false) {
            arquivos.push_back(make_pair(joining.getStudentcode(), request.first));
        } else {
            values = students_per_class(leaving.getUc_classcode()[0][0]);
            total_da_turma =
                    EstudanteCadeiraTurmacount(leaving.getUc_classcode()[0][0], leaving.getUc_classcode()[0][1]) - 1;
            max_turma = values.second;
            min_turma = min(values.first, total_da_turma);
            if (total_da_turma - min_turma >= 4 || max_turma - total_da_turma >= 4) {
                arquivos.push_back(make_pair(joining.getStudentcode(), request.first));
            } else {
                total_da_turma =
                        EstudanteCadeiraTurmacount(joining.getUc_classcode()[0][0], joining.getUc_classcode()[0][1]) +
                        1;
                max_turma = max(max_turma, total_da_turma);
                if (total_da_turma > max_cap || total_da_turma - min_turma >= 4 || max_turma - total_da_turma >= 4) {
                    arquivos.push_back(make_pair(joining.getStudentcode(), request.first));
                } else {
                    Student finding = studentList.find(leaving);
                    vector<vector<string>> uc_classcode = finding.getUc_classcode();
                    for (auto it = uc_classcode.begin(); it < uc_classcode.end(); it++) {
                        if ((*it)[0] == joining.getUc_classcode()[0][0]) {
                            uc_classcode.erase(it);
                        }
                    }
                    studentList.remove(finding);
                    finding.setUc_classcode(uc_classcode);
                    studentList.insert(finding);
                }
            }
        }
    } else {
        vector<pair<Student, Student>> changing_list = request.first.vector_changing();
        for (int i = 0; i < changing_list.size(); i++) {
            Student leaving = changing_list[i].first;
            Student joining = changing_list[i].second;
            horario.getHorario(joining.getStudentcode());
            horario.add(joining);
            for (Class x: horario) {
                if (x.getClassType() == "T") continue;
                if (x.getUccode() != joining.getUc_classcode()[0][0] ||
                    x.getClassCode() != joining.getUc_classcode()[0][1])
                    continue;
                for (Class y: horario) {
                    if (!(x == y)) compativel = Compativeis(x, y);
                    if (compativel == false) break;
                }
                if (compativel == false) break;
            }
            if (compativel == false) {
                arquivos.push_back(make_pair(joining.getStudentcode(), request.first));
                break;
            } else {
                values = students_per_class(leaving.getUc_classcode()[0][0]);
                total_da_turma =
                        EstudanteCadeiraTurmacount(leaving.getUc_classcode()[0][0], leaving.getUc_classcode()[0][1]) -
                        1;
                max_turma = values.second;
                min_turma = min(values.first, total_da_turma);
                if (total_da_turma - min_turma >= 4 || max_turma - total_da_turma >= 4) {
                    arquivos.push_back(make_pair(joining.getStudentcode(), request.first));
                    break;
                } else {
                    total_da_turma = EstudanteCadeiraTurmacount(joining.getUc_classcode()[0][0],
                                                                joining.getUc_classcode()[0][1]) + 1;
                    max_turma = max(max_turma, total_da_turma);
                    if (total_da_turma > max_cap || total_da_turma - min_turma >= 4 ||
                        max_turma - total_da_turma >= 4) {
                        arquivos.push_back(make_pair(joining.getStudentcode(), request.first));
                        break;
                    } else {
                        to_process.push_back(changing_list[i]);
                    }
                }
            }
        }
        if (to_process.size() == changing_list.size()) {
            for (int j = 0; j < to_process.size(); j++) {
                Student student1 = studentList.find(to_process[j].first);
                vector<vector<string>> uc_classcode = student1.getUc_classcode();
                for (auto it = uc_classcode.begin(); it < uc_classcode.end(); it++) {
                    if ((*it)[0] == to_process[j].first.getUc_classcode()[0][0]) {
                        uc_classcode.erase(it);
                    }
                }
                studentList.remove(finding);
                finding.setUc_classcode(uc_classcode);
                studentList.insert(finding);
            }
        }
    }
    return 0;
}
pair<int,int> Menu::students_per_class(string cadeira){
    int count;
    pair<int,int> student_minmax ={INT_MAX,0};
    for(auto x: turmas(cadeira)){
        count = 0;
        for(iteratorBST<Student> it = studentList.begin(); it != studentList.end(); it++){
            Student student = studentList.find(*it);
            vector<vector<string>> uc_classcode = student.getUc_classcode();
            for(int i = 0; i < uc_classcode.size(); i++)
                if(uc_classcode[i][0] == cadeira && uc_classcode[i][1] == x)
                    count++;
        }
        student_minmax.first=min(student_minmax.first,count);
        student_minmax.second=max(student_minmax.second,count);
    }
    return student_minmax;
}



bool Menu::StudentExists(Student aluno) {
    Student student = studentList.find(aluno);

    if(student.getStudentname() != "") return true;

    return false;
}

bool Menu::TurmaExists(string turma) {
    for(iteratorBST<Student> it = studentList.begin(); it != studentList.end(); it++){
        Student aluno = studentList.find(*it);
        vector<vector<string>> uc_classcode = aluno.getUc_classcode();
        for(int i = 0; i < uc_classcode.size(); i++) if(uc_classcode[i][1] == turma) return true;

    }
    return false;
}

bool Menu::CadeiraExists(string cadeira) {
    for(iteratorBST<Student> it = studentList.begin(); it != studentList.end(); it++){
        Student aluno = studentList.find(*it);
        vector<vector<string>> uc_classcode = aluno.getUc_classcode();
        for(int i = 0; i < uc_classcode.size(); i++) if(uc_classcode[i][0] == cadeira) return true;

    }
    return false;
}

bool Menu::CadeirainTurmaExists(string turma, string cadeira) {

    for(iteratorBST<Student> it = studentList.begin(); it != studentList.end(); it++){
        Student aluno = studentList.find(*it);
        vector<vector<string>> uc_classcode = aluno.getUc_classcode();
        for(int i = 0; i < uc_classcode.size(); i++) {
            if(uc_classcode[i][1] == turma && uc_classcode[i][0] == cadeira) return true;
        }
    }
    return false;
}

bool Menu::AlunoinCadeiraExists(string aluno, string cadeira) {

    Student student = studentList.find(Student(aluno, "", {}));
    vector<vector<string>> uc_classcode = student.getUc_classcode();
        for(int i = 0; i < uc_classcode.size(); i++) {
            if (uc_classcode[i][0] == cadeira)
                return true;
        }
    return false;
}


set<string> Menu::turmas(string cadeira) {
    set<string> result;
    for(auto x:classes_per_uc){
        if(x.getCadeira()==cadeira) result.insert(x.getTurma());
    }
    return result;
}

bool Menu::Compativeis(Class x,Class y){
    if(x.getClassType()=="T" || y.getClassType()=="T") return true;
    if(x.getWeekDay()!=y.getWeekDay()) return true;
    if(x.getStarthour()+x.getDuration()>y.getStarthour() && x.getStarthour()<y.getStarthour()) return false;
    if(y.getStarthour()+y.getDuration()>x.getStarthour() && y.getStarthour()<x.getStarthour()) return false;
    return true;
}

void Menu::AfterExec() {
    int num;
    cout << endl << "Pretende fazer mais alguma pesquisa?" << endl;
    cout << "1 -> Yes" << endl;
    cout << "2 -> No" << endl;
    cin >> num;
    switch (num) {
        case 1:
            mainMenu();             //voltar ao menu
            break;
        default:
            Wait();         //terminar execucao
    }
}

BST<Student> Menu::getStudentList() {
    return studentList;
}
vector<Class> Menu::getClassList() {
    return classList;
}