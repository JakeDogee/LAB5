#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int const MAX = 4;
/* Створити базовий клас НАСТІЛЬНА ГРА (задається назва). Створити похідні класи ШАХИ
(задаються вага кожної з 32 фігур 6 типів, вага дошки для гри розміром 8x8) та ДОМІНО
(задаються вага кожної з 28 однотипних фігур, вага коробки для зберігання). Для заданих
прикладів різних комплектів настільних ігор відсортувати їх за зростанням ваги і обчислити
сумарну вагу всіх комплектів і окремо для кожного з похідних класів. Для перевірки
використати масив вказівників на об’єкти базового класу, яким присвоїти адреси
об’єктів похідних класів.*/



class dekstop_game {
    string name;
    double wSubjects;
public:
    dekstop_game() :wSubjects(0), name("-")
    {}
    dekstop_game(string names, double wSubject) : name(names), wSubjects(wSubject)
    {}
    ~dekstop_game() {}
    virtual void print() {
        std::cout << name << "\nЗагальна вага : " << wSubjects;
    }
    double return_value() {
        return wSubjects;
    }
};


class chess : public dekstop_game {
private:
    double wBoards;
    double wFigure;
public:
    chess() :wFigure(0), wBoards(0), dekstop_game("-", 0)    //конструктор без параметр
    {}
    chess(string name, double wPawn, double wQueen, double wKing, double wHourse, double wElephant, double wCastle, double wBoards) : dekstop_game(name, (wPawn * 16 + wKing * 2 + wQueen * 2 + wHourse * 4 + wElephant * 4 + wCastle * 4 + wBoards)) {
        this->wBoards = wBoards;
        this->wFigure = wPawn * 16 + wKing * 2 + wQueen * 2 + wHourse * 4 + wElephant * 4 + wCastle * 4;
    }
    ~chess() {}
    void print() {
        dekstop_game::print();
        std::cout << "\n\t Вага фігур :" << this->wFigure << endl;
        std::cout << "\t Вага коробки :" << this->wBoards << endl;
    }


};
class domino : public dekstop_game {
    double wBones;
    double wBox;
public:
    domino() : dekstop_game("-", 0)    //конструктор без параметр
    {
        wBones = 0;
        wBox = 0;
    }
    domino(string name, double wBone, double wBoxes) : dekstop_game(name, (wBone * 28 + wBoxes)) {
        wBones = wBone * 28;
        wBox = wBoxes;
    }
    ~domino() {};
    void print() {
        dekstop_game::print();
        std::cout << "\n\t Вага фігур :" << this->wBones << endl;
        std::cout << "\t Вага коробки :" << this->wBox << endl;
    }

};

int main()
{
    system("chcp 1251");
    dekstop_game* P_mass[MAX];
    dekstop_game* temp;
    double sum = 0;

    P_mass[0] = new chess("Шахи-1", 8804.25, 2332.3, 69, 4.2, 56.2, 3.7, 32.8);
    P_mass[1] = new chess("Шахи-2", 322.7, 7.5, 14.2, 3.3, 12.4, 10.9, 50.5);
    P_mass[2] = new domino("Доміно-1", 12.2, 32.9);
    P_mass[3] = new domino("Доміно-2", 228.5, 38.3);
    cout << "Початкові дані :" << endl;
    for (int i = 0; i < MAX; i++) {
        P_mass[i]->print();
    }
    cout << "\nВідсортовані дані: " << endl;


    //Сортування пузирьком
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX - 1; j++) {
            if (P_mass[j]->return_value() > P_mass[j + 1]->return_value()) {
                temp = P_mass[j];
                P_mass[j] = P_mass[j + 1];
                P_mass[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < MAX; i++) {
        P_mass[i]->print();
    }
    //Макс сумма

    for (int j = 0; j < MAX; j++) {
        sum += P_mass[j]->return_value();
    }
    cout << "\nЗагальна вага :" << sum << endl;
    for (int i = 0; i < MAX; i++) {
        delete P_mass[i];
    }
}