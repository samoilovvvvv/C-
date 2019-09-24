#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

ofstream fout;
ifstream fin;
fstream file;

const int N = 256;
struct Zap {
    string surname;
    string initials;
    int group;
    int aver_point;
    int fathers_salary;
    int mothers_salary;
} students[100];

void menu(){
    cout << "1 - Добавить студента" << endl;
    cout << "2 - Вывести всех" << endl;
    cout << "3 - Вывести список приоритетности" << endl;
    cout << "0 - Выйти" << endl;
    cout << endl << "Введите цифру: ";
}

void WriteToFile(int i){
    fout.open("students.txt", ios_base::app);
    fout << "Фамилия и инициалы: " << students[i].surname << " " << students[i].initials  << endl << "Номер группы: " << students[i].group << endl << "Средний балл: " << students[i].aver_point << endl << "Зарплата отца: " << students[i].fathers_salary << endl << "Зарплата матери: " << students[i].mothers_salary << endl << "Порядковый номер: " << i+1 << endl << endl;
    fout.close();
}

int main(int argc, const char * argv[]) {
    setlocale(LC_ALL, "Russian");
    int digit, i = 0;
    char s[N];
    while(true){
        menu();
        //записываем всё из файла в структуру
        fin.open("students.txt");
        if(fin.peek() == EOF){
            cout << "Файл пуст. Добавьте информацию в файл." << endl;
        }
        else {
            int j = 1;
            int k = 0;
            string temp;
            while (!fin.eof()){
                while(fin){
                    if(j == 1 + k) {
                        getline(fin, students[i].surname);
                        cout << students[i].surname << endl;
                    }
                    if(j == 2 + k) {
                        getline(fin, students[i].initials);
                        cout << students[i].initials << endl;
                    }
                    if(j == 3 + k) {
                        getline(fin, temp);
                        students[i].group = stoi(temp);
                        cout << students[i].group << endl;
                    }
                    if(j == 4 + k) {
                        getline(fin, temp);
                        students[i].aver_point = stoi(temp);
                        cout << students[i].aver_point << endl;
                    }
                    if(j == 5 + k) {
                        getline(fin, temp);
                        students[i].fathers_salary = stoi(temp);
                        cout << students[i].fathers_salary << endl;
                    }
                    if(j == 6 + k) {
                        getline(fin, temp);
                        students[i].mothers_salary = stoi(temp);
                        cout << students[i].mothers_salary << endl;
                    }
                    if(j == 7 + k){
                        getline(fin, temp);
                        cout << temp << endl;
                        //cout << "End of " << i << " k = " << k;
                        j++;
                        break;
                    }
                    j++;
                }
                k += 7;
                i++;
            }
        }
        fin.close();
        cout << "Ваше число: ";
        cin >> digit;
        if (digit == 1){
            cout << "Введите фамилию и инициалы: ";
            cin >> students[i].surname >> students[i].initials;
            cout << "Введите номер группы: ";
            cin >> students[i].group;
            cout << "Введите средний балл: ";
            cin >> students[i].aver_point;
            cout << "Введите зарплату отца: ";
            cin >> students[i].fathers_salary;
            cout << "Введите зарплату матери: ";
            cin >> students[i].mothers_salary;
            cout << endl;
            WriteToFile(i);
            i++;
        }
        if(digit == 2){
            cout << endl;
            /*fin.open("students.txt");
            if(fin.peek() == EOF){
                cout << "Файл пуст. Добавьте информацию в файл." << endl;
            }
            else{
                while (!fin.eof()){
                    fin.getline(s, N);
                    cout << s << endl;
                }
            }
            fin.close();*/
            
        }
        if (digit == 3){
            int i = 0, j = 0;
            fin.open("students.txt", ios_base::binary);
            string surname_initials;
            string group_str;
            int group;
            if(fin.eof()){
                cout << "Пусто" << endl;
                //break;
            }
            while(fin)
            {
                if(j == 0){
                    getline(fin, surname_initials);
                    cout << surname_initials << endl;
                }
                if (j == 1) {
                    getline(fin, group_str);
                    group = stoi(group_str);
                    cout << group << endl;
                }
                if (j == 3){
                    break;
                }
                j++;
            }
            
            fin.close();
        }
        if (digit == 0){
            cout << "Bye" << endl;
            return 0;
        }
    }
    return 0;
}
