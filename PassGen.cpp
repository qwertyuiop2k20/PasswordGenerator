#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>

//ifstream fin;	//створюємо об'єкт для зчитування файлу
ofstream fout;	//створюємо об'єкт для запису в файл

int count_passwords, count_symvols, rnd;
char s[] = {"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!@#$%^&*()_+-=[]{}?><:;"};
void PassGen(int count_p, int count_s);

int main(int argc, char** argv)
{
    count_passwords = count_symvols = rnd = 0;
    fout.open("Passwords.txt", ios_base::out | ios_base::trunc);	//зв'язуємо об'єкт з файлом

    cout << "Passwords Generator!\n\n";
    do { cout << "Enter count of passwords: ";
    cin >> count_passwords;} while (count_passwords < 1);
    do { cout << "Enter count of symvols in password: ";
    cin >> count_symvols; } while (count_symvols < 1);
    cout << "\n";

    PassGen(count_passwords, count_symvols);
    printf("File \"Passwords.txt\" created!\n\n");

    fout.close();	//close file
    return 0;
}

void PassGen(int count_p, int count_s)
{
    srand(time(NULL));	//забезпечує кожен раз нові значення рандому
    for (int i = 0; i < count_p; ++i)
    {
        for (int j = 0; j < count_s; ++j)
        {
            rnd = (int)rand() % 86;	//86 - count of all symvols in array s[]
            /*cout << s[rnd];*/ fout << s[rnd];
        }
        /*cout << endl;*/ //fout << "\n";
        if (i < count_p - 1) /*cout << endl;*/ fout << "\n";
    }
}
