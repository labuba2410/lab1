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

void AddPipe(Pipe& t) {
    cout << "Insert pipe name: ";
    cin >> t.name;
    cout << "Insert pipe length (km): ";
    cin >> t.length;
    cout << "Insert pipe diametr (mm): ";
    cin >> t.diametr;
    cout << " Insert pipe status (0 - working, 1 - in repair): ";
    cin >> t.status;
}

void AddCS(CS& cs) {
    cout << "Insert CS name: ";
    cin >> cs.name;
    cout << "Insert number of workshops: ";
    cin >> cs.number_work;
    cout << "Insert number of workshops online: ";
    cin >> cs.number_work_online;
    cout << "Insert CS class: ";
    cin >> cs.class_cs;
}

void ShowAllObjects(const Pipe& t, const CS& cs) {
    cout << "\n    PIPE";
    cout << "\nName: " << t.name;
    cout << "\nLength: " << t.length << " km";
    cout << "\nDiametr: " << t.diametr << " mm";
    cout << "\nStatus: " << (t.status ? "In repair" : "Working");

    cout << "\n\n    COMPRESSOR STATION";
    cout << "\nName: " << cs.name;
    cout << "\nTotal workshops: " << cs.number_work;
    cout << "\nWorkshops online: " << cs.number_work_online;
    cout << "\nClass: " << cs.class_cs;
}

void ShowMenu(Pipe t, CS cs)
{
    int option;
    while (1) {
        cout << "\n   MENU";
        cout << "\n1. Add pipe";
        cout << "\n2. Add CS";
        cout << "\n3. Show all objects";
        cout << "\n4. Edit pipe";
        cout << "\n5. Edit CS";
        cout << "\n6. Save";
        cout << "\n7. Load";
        cout << "\n0. Exit";
        cin >> option;
        switch (option) {
        case 1:
            AddPipe(t);
            break;
        case 2:
            AddCS(cs);
            break;
        case 3:
            ShowAllObjects(t, cs);
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