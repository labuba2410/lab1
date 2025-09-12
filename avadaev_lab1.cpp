#include <iostream>
using namespace std;

struct Pipe {
    string name;
    float length;
    int diametr;
    bool status;
};

struct CS {
    string name;
    int number_work;
    int number_work_online;
    string class_cs;
};

void ShowMenu(Pipe t, CS cs)
{
    int option;
    while (1) {
        cout << "Chooose options: \n1. Add pipe \n2. Add CS \n3. Show all objects";
        cin >> option;
        switch (option) {
        case 1:
            cout << "Insert pipe name pls: ";
            cin >> t.name;
            break;
        case 2:
            break;
        case 3:
            cout << "\nPipe name: " << t.name;
            break;
        }
    }
};

int main()
{
    cout << "Hello World!\n";
    Pipe truba;
    CS comp_station;
    ShowMenu(truba, comp_station);
    return 1;
}

//Ввод имени трубы с пробелом, отрицательные значения, нулевое значение в кол-ве цехов и др
//