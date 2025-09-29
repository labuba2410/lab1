#include <iostream>
#include <fstream>
#include <string>
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
    system("cls");
    cout << "Add Pipe" << endl;

    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Insert pipe name: ";
    getline(cin, t.name);
    while (t.name.empty()) {
        cout << "Error! Pipe name can not be empty. Pls enter again: ";
        getline(cin, t.name);
    }

    cout << "Insert pipe length (km): ";
    while (!(cin >> t.length) || t.length <= 0 || cin.peek() != '\n') {
        cout << "Error! Pls enter positive number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Insert pipe diametr (mm): ";
    while (!(cin >> t.diametr) || t.diametr <= 0 || cin.peek() != '\n') {
        cout << "Error! Pls enter poositive integer: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Insert pipe status (0 - working, 1 - in repair): ";
    int pipe_st;
    while (!(cin >> pipe_st) || (pipe_st != 0 && pipe_st != 1) || cin.peek() != '\n') {
        cout << "Error! Pls enter 0 or 1: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    t.status = (pipe_st == 1);

    cin.ignore(1000, '\n');
}

void AddCS(CS& cs) {
    system("cls");
    cout << "Add CS" << endl;

    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Insert CS name: ";
    getline(cin, cs.name);
    while (cs.name.empty()) {
        cout << "Error! CS name can not be empty. Pls enter again: ";
        getline(cin, cs.name);
    }

    cout << "Insert number of workshops: ";
    while (!(cin >> cs.number_work) || cs.number_work <= 0 || cin.peek() != '\n') {
        cout << "Error! Pls enter poositive integer: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Insert number of workshops online: ";
    while (!(cin >> cs.number_work_online) || cs.number_work_online < 0 || cs.number_work_online > cs.number_work || cin.peek() != '\n') {
        if (cin.fail()) {
            cout << "Error! Pls enter positive number: ";
        }
        else if (cs.number_work_online > cs.number_work) {
            cout << "Error! The number of operating workshops cannot exceed the total number of workshops: (" << cs.number_work << "). Pls enter again: ";
        }
        else {
            cout << "Error! Pls enter non-negative number: ";
        }
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore(1000, '\n');

    cout << "Insert CS class: ";
    getline(cin, cs.class_cs);
    while (cs.class_cs.empty()) {
        cout << "Error! Cs class can not be empty. Pls enter again: ";
        getline(cin, cs.class_cs);
    }
}

void ShowAllObjects(const Pipe& t, const CS& cs) {
    system("cls");
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

void Edit_the_Pipe(Pipe& t) {
    system("cls");
    cout << "Status: " << (t.status ? "In repair" : "Working");
    cout << "\nChange pipe's status (0 - working, 1 - in repair): ";
    cin >> t.status;
    cout << "The pipe status has been successfully changed.";
}

void Edit_CS(CS& cs) {
    cout << "Current workshops online: " << cs.number_work_online << " / " << cs.number_work;
    cout << "\nChoose action:\n1. Start workshop\n2. Stop workshop ";
    int action;
    cin >> action;
    if (action == 1 && cs.number_work_online < cs.number_work) {
        cs.number_work_online++;
        cout << "Workshop started!\n";
    }
    else if (action == 2 && cs.number_work_online > 0) { 
        cs.number_work_online--;
        cout << "Workshop stopped!\n";
    }
    else {
        cout << "Action not possible!\n";
    }
}

void SaveToFile(const Pipe& t, const CS& cs) {
    ofstream file("laba1.txt");
    if (file.is_open()) {
        file << "PIPE\n";
        file << t.name << "\n";
        file << t.length << "\n";
        file << t.diametr << "\n";
        file << t.status << "\n";

        file << "CS\n";
        file << cs.name << "\n";
        file << cs.number_work << "\n";
        file << cs.number_work_online << "\n";
        file << cs.class_cs << "\n";

        file.close();
        cout << "Data of Pipe and CS saved to file!\n";
    }
    else {
        cout << "Error saving file!\n";
    }
}

void FromFile(Pipe& t, CS& cs) {
    ifstream file("laba1.txt");
    if (file.is_open()) {
        string line;
        getline(file, line);
        getline(file, t.name);
        file >> t.length;
        file >> t.diametr;
        file >> t.status;
        file.ignore();

        getline(file, line);
        getline(file, cs.name);
        file >> cs.number_work;
        file >> cs.number_work_online;
        file.ignore();
        getline(file, cs.class_cs);

        file.close();
        cout << "Data loaded from file!\n";
    }
    else {
        cout << "Error loading file!\n";
    }
}

void ShowMenu(Pipe t, CS cs)
{
    system("cls");
    int option;
    while (1) {
        cout << "\n\n   MENU";
        cout << "\n1. Add pipe";
        cout << "\n2. Add CS";
        cout << "\n3. Show all objects";
        cout << "\n4. Edit pipe";
        cout << "\n5. Edit CS";
        cout << "\n6. Save";
        cout << "\n7. Load";
        cout << "\n0. Exit";
        cout << "\nChoose option: \n";
        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error! Please enter a number 0-7\n";
            continue;
        }

        if (option < 0 || option > 7) {
            cout << "Error! Please enter number 0-7\n";
            continue;
        }
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
        case 4:
            Edit_the_Pipe(t);
            break;
        case 5:
            Edit_CS(cs);
            break;
        case 6:
            SaveToFile(t, cs);
            break;
        case 7:
            FromFile(t, cs);
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