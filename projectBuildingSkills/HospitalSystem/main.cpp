#ifndef __MAIN_H__
#define __MAIN_H__

#include <iostream>
#include <string>
#include <map>

using namespace std;

// Global variables
const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;
map<bool, string> state{{0, "regular"}, {1, "urgent"}};

string names[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1];
int status[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1]; // 0 REGULAR, 1 URGENT
int queue_length[MAX_SPECIALIZATION + 1];          // For each speacialisation: how many patients so far

int menu()
{
    int choice{-1};
    while (choice == -1)
    {
        cout << "Enter your choice" << endl;
        cout << "1) Add new patient" << endl;
        cout << "2) Print all patients" << endl;
        cout << "3) Get next patien" << endl;
        cout << "4) Exit" << endl;

        cin >> choice;

        if (!(choice <= 4 && choice >= 1))
        {
            cout << "Invalid choice. Try again" << endl;
            choice = -1;
        }
    }

    return choice;
}

// Move each patient to the left. E.g if patient in position 5, it will be in 4
// Help in removing patient
void shift_left(int spec, string names_sp[], int status_sp[])
{
    int len{queue_length[spec]};
    for (int i{1}; i < len; ++i)
    {
        names_sp[i - 1] = names_sp[i];
        status_sp[i - 1] = status_sp[i - 1];
    }
    queue_length[spec]--;
}

// Move each patient to the right. E.g if patient in position 5, it will be in 6
// Help in adding patient
void shift_right(int spec, string names_sp[], int status_sp[])
{
    int len{queue_length[spec]};
    for (int i = len; i >= 0; --i)
    {
        names_sp[i + 1] = names_sp[i];
        status_sp[i + 1] = status_sp[i];
    }
    queue_length[spec]++;
}

bool add_new_patient()
{
    int specialization;
    string name;
    bool state;
    cout << "Enter Speacialization" << endl;
    cin >> specialization;
    cout << "Enter name" << endl;
    cin >> name;
    cout << "Enter  status" << endl;
    cin >> state;
    if (queue_length[specialization] > 5)
    {
        cout << "Sorry we can't add more patients for this specialization" << endl;
        return false;
    }

    if (state == 0) // regular state,  add  to end
    {
        names[specialization][queue_length[specialization]] = name;
        status[specialization][queue_length[specialization]] = state;
        queue_length[specialization]++;
    }
    else // Urgent, add  to begin. Shift , then add
    {
        shift_right(specialization, names[specialization], status[specialization]);
        names[specialization][0] = name;
        status[specialization][0] = state;
    }
    return true;
}

void print_patient(int spec, string names_sp[], int status_sp[])
{
    int len = queue_length[spec];
    if (len == 0)
        return;

    cout << "There are " << len << " patients  in specialization " << spec << endl;

    for (int i{0}; i < len; ++i)
    {
        cout << names_sp[i] << " " << state[status_sp[i]] << endl;
    }
    cout << endl;
}

void print_all_patients() // string &names[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1], int &status[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1], int &queue_length[MAX_SPECIALIZATION + 1])
{
    cout << "*************************" << endl;

    for (int spec{0}; spec < MAX_SPECIALIZATION; ++spec)
    {
        print_patient(spec, names[spec], status[spec]);
    }
}

void get_next_patient()
{
    cout << "***********************************" << endl;
    cout << "Enter specialization: ";
    int specia;
    cin >> specia;
    int len{queue_length[specia]};
    if (len == 0)
    {
        cout << "No patients at the moments. Have rest, Dr" << endl;
        return;
    }

    // Let patient goes to dr
    cout << names[specia][0] << "Please go with the Dr" << endl;

    // Delete  the patient in position 0;
    shift_left(specia, names[specia], status[specia]);

    cout << "***********************************" << endl
         << endl;
}

void hospital_system()
{
    while (true)
    {
        int choice = menu();

        if (choice == 1)
            add_new_patient();
        else if (choice == 2)
        {
            print_all_patients(); // names, status, queue_length);
        }
        else if (choice == 3)
        {
            get_next_patient();
        }
        else
            break;
    }
}

int main(int argc, const char **argv)
{
    hospital_system();
    return 0;
}
#endif // __MAIN_H__