#include <iostream>
#include <time.h>
#include <Windows.h>
#include <cmath>
#include <conio.h>

using namespace std; //Код Дена

int euler(int n)
{
    int i, m = 1; //Код Дена
    for (i = 2; i <= n / 2; i++)
        if (n % i == 0)
        {
            n /= i; //Код Дена
            while (n % i == 0)
            {
                m *= i; //Код Дена
                n /= i; //Код Дена
            }
            if (n == 1) return m * (i - 1); //Код Дена
            else return m * (i - 1) * euler(n); //Код Дена
        }
    return n - 1; //Код Дена
}

int euklidfunc(unsigned long int shtuka1, unsigned long int shtuka2)
{
    int shtuka3 = shtuka1 % shtuka2; //Код Дена
    if (shtuka3 == 0) return shtuka2; //Код Дена
    return euklidfunc(shtuka2, shtuka3); //Код Дена
}

bool isitsimple(int n, int hard)
{
    bool simple = true; //Код Дена
    int times = hard * 5; //Код Дена
    for (int i = 2; i < times; i++) if (n % i == 0 && simple == true) { if (i == n) { i = times; } else simple = false;} //Код Дена 
    return simple; //Код Дена

    /*
    if (n > 999 || n < 2) return false; //Код Дена
    {
        double shtuka; //Код Дена
        double shtuka1; //Код Дена
        int times = 6; //Код Дена

        if ((n % 10 == 0 || n % 10 == 2 || n % 10 == 4 || n % 10 == 6 || n % 10 == 8) && n != 2) simple = false; //Код Дена

        if ((n % 10 == 5 || n % 10 == 0) && n != 5) simple = false; //Код Дена

        if ((n % 10 + (n % 100 / 10) + (n % 1000 / 100)) % 3 == 0 && n != 3) simple = false; //Код Дена

        if (abs((n % 100 / 10) + (n % 10) * 2) % 7 == 0 && n != 7) simple = false; //Код Дена

        if (abs((n % 10 + n % 1000 / 100) - (n % 100 / 10)) == 0 && n != 11) simple = false; //Код Дена

        if (simple == true)
            {
                if (n > times) shtuka = times; //Код Дена
                else shtuka = n; //Код Дена

                for (int i = 1; //Код Дена i < shtuka; //Код Дена i++)
                {
                    shtuka1 = i; //Код Дена

                    for (int u = 1; //Код Дена u < n - 1; //Код Дена u++)
                    {
                        shtuka1 = shtuka1 * i; //Код Дена
                    }

                    if (moddouble(shtuka1, n) != 1)
                    {
                        simple = false; //Код Дена
                        if (true)
                        {
                            cout << "\nn = " << n; //Код Дена
                            cout << "\nа = " << i; //Код Дена
                            cout << "\nа ^ n - 1 = " << shtuka1; //Код Дена
                            cout << "\n"; //Код Дена
                        }
                    }
                }
            }

        return simple; //Код Дена
    }*/
}

int main()
{
    srand(time(NULL)); //Код Дена
    setlocale(LC_ALL, "rus"); //Код Дена
    bool again = true; //Код Дена
    int hard = 50; //Код Дена
    int fails = 0; //Код Дена
    int minshtuka = 2; //Код Дена
    int maxshtuka = 35; //Код Дена
    string chooseshtuka; //Код Дена
    int speed = 4; //Код Дена
    unsigned long long secretkey[2] = { 0, 0 }; //Код Дена
    unsigned long long publickey[2] = { 0, 0 }; //Код Дена
    string lang; //Код Дена
    cout << "Choose language Выберите язык (eng / rus) \n"; //Код Дена
    cin >> lang; //Код Дена
    while (lang != "eng" && lang != "rus")
    {
        cout << "\n"; //Код Дена
        cin >> lang; //Код Дена
    }
    cout << "\n"; //Код Дена
    while (true)
    {
        if (lang == "rus")
        cout << "Выберете действие \n1 - Генерация новых ключей\n2 - Шифрование сообщения\n3 - Расшифрование сообщения\n"; //Код Дена
        else
            cout << "Choose function \n1 - Generation of new keys\n2 - Encoding\n3 - Decoding\n"; //Код Дена
        if (lang == "rus")
        cout << "Секретный ключ " << secretkey[0] << " " << secretkey[1]; //Код Дена
        else
        {
            cout << "Secret key " << secretkey[0] << " " << secretkey[1]; //Код Дена
        }
        if (lang == "rus")
        cout << "\nПубличный ключ " << publickey[0] << " " << publickey[1] << endl; //Код Дена
        else
        {
            cout << "\nPublic key " << publickey[0] << " " << publickey[1] << endl; //Код Дена
        }

        cin >> chooseshtuka; //Код Дена

        if (chooseshtuka[0] == '1')
        {
            if (lang == "rus")
            std::cout << "\nВведите лимит для генерации входных чисел (квадрат этого числа - максимальное значение второй части ключей) "; //Код Дена
            else
            {
                cout << "\Enter a maximum for input random numbers (square of this number will be a maximum of second part of keys) "; //Код Дена
            }
            cin >> hard; //Код Дена
            while (hard < 8)
            {
                if (lang == "rus")
                {
                    std::cout << "\nЛимит должен быть больше или равен восьми "; //Код Дена cin >> minshtuka; //Код Дена
                }
                else
                {
                    cout << "\nMaximum must be bigger or same of 8 "; //Код Дена cin >> minshtuka; //Код Дена
                }
            }
            if (lang == "rus")
            std::cout << "\nВведите минимальный размер первых частей ключей (не меньше трех) "; //Код Дена
            else
            {
                cout << "\nEnter a minimum of first parts of keys (bigger then 2) "; //Код Дена
            }
            cin >> minshtuka; //Код Дена
            while (minshtuka < 2)
            {
                if (lang == "rus")
                {
                    std::cout << "\nКлюч должен быть больше или равен двум "; //Код Дена cin >> minshtuka; //Код Дена
                }
                else
                {
                    cout << "\nKey must be bigger then 2 "; //Код Дена cin >> minshtuka; //Код Дена
                }
            }
            if (lang == "rus")
            std::cout << "\nВведите максимальный размер первых частей ключей "; //Код Дена
            else
            {
                cout << "\nEnter a maximum of first parts of keys "; //Код Дена
            }
            cin >> maxshtuka; //Код Дена
            while (maxshtuka < minshtuka)
            {
                if (lang == "rus")
                {
                    std::cout << "\nМаксимум должен быть больше минимума "; //Код Дена cin >> maxshtuka; //Код Дена
                }
                else
                {
                    cout << "\nMax must be bigger of min "; //Код Дена cin >> maxshtuka; //Код Дена
                }
            }
            if (lang == "rus")
            std::cout << "\nСтартуем\n"; //Код Дена
            else
                cout << "\nStarting\n"; //Код Дена
            while (again)
            {
                unsigned long long p = 4, q = 4; //Код Дена
                if (lang == "rus")
                std::cout << "\nГенерация первого числа"; //Код Дена
                else
                {
                    cout << "\nGenerating first number"; //Код Дена
                }
                while (!isitsimple(p, hard))
                {
                    p = (rand() % (hard - 3)) + 3; //Код Дена std::cout << "."; //Код Дена Sleep(speed); //Код Дена
                }
                std::cout << p; //Код Дена
                if (lang == "rus")
                std::cout << "\nГенерация второго числа"; //Код Дена
                else
                {
                    cout << "\nGenerating second number"; //Код Дена
                }
                while (!isitsimple(q, hard))
                {
                    q = (rand() % (hard - 3)) + 3; //Код Дена std::cout << "."; //Код Дена Sleep(speed); //Код Дена
                }std::cout << q; //Код Дена
                if (lang == "rus")
                std::cout << "\nСоздание дополнительных переменных "; //Код Дена
                else
                {
                    cout << "\nCreating additional numbers "; //Код Дена
                }
                unsigned long long n = p * q; //Код Дена std::cout << n << " "; //Код Дена
                unsigned long long eulershtuka = (p - 1) * (q - 1); //Код Дена std::cout << eulershtuka; //Код Дена
                unsigned long long d; //Код Дена
                unsigned long long i; //Код Дена
                if (lang == "rus")
                std::cout << "\nВыбор числа d"; //Код Дена
                else
                {
                    cout << "\nChoosing d"; //Код Дена
                }
                do
                {
                    std::cout << "."; //Код Дена Sleep(speed); //Код Дена
                    d = (rand() % maxshtuka - minshtuka) + minshtuka; //Код Дена
                } while (euklidfunc(d, eulershtuka) != 1); //Код Дена std::cout << d; //Код Дена
                unsigned long long e = maxshtuka + 2; //Код Дена
                if (lang == "rus")
                std::cout << "\nВыбор числа e"; //Код Дена
                else
                {
                    cout << "\nChoosing e"; //Код Дена
                }
                if (true)
                {
                    bool done = false; //Код Дена
                    const int shtukashtuka = 10; //Код Дена
                    unsigned long long mbit[shtukashtuka + 1]; //Код Дена
                    for (i = 0;  i < shtukashtuka; i++) mbit[i] = 0; //Код Дена
                    int times = 0; //Код Дена
                    int stopit = 0; //Код Дена
                    for (i = minshtuka; !done; i++)
                    {
                        if ((i * d) % eulershtuka == 1) { done = true; //Код Дена mbit[0] = i; //Код Дена }
                    }
                    done = false; //Код Дена
                    bool stooop = false; //Код Дена
                    do
                    {
                        for (i = mbit[times]; !done && !stooop; i++)
                        {
                            if ((i * d) % eulershtuka == 1)
                            {
                                done = true; //Код Дена
                                mbit[times + 1] = i; //Код Дена
                                if (i > maxshtuka)
                                {
                                    stopit = times + 1; //Код Дена
                                    stooop = true; //Код Дена
                                    for (int g = i; g < shtukashtuka; g++) mbit[g] = maxshtuka + 2; //Код Дена
                                    times = shtukashtuka - 1; //Код Дена
                                }
                            }
                        }
                        times++; //Код Дена std::cout << "."; //Код Дена done = false; //Код Дена Sleep(speed); //Код Дена
                    } while (times != shtukashtuka && !stooop); //Код Дена
                    times = 0; //Код Дена
                    if (stopit == 0) 
                        while (e > maxshtuka)
                    {
                        e = mbit[rand() % shtukashtuka]; times++; //Код Дена
                        if (times > shtukashtuka * 2) e = 0; //Код Дена
                    }
                    else while (e > maxshtuka)
                    {
                        e = mbit[rand() % stopit]; times++; //Код Дена
                        if (times > shtukashtuka * 2) e = 0; //Код Дена
                    }
                    std::cout << e; //Код Дена
                }
                if (e > 0)
                {
                    if (lang == "rus")
                    {
                        std::cout << "\nОткрытый ключ: " << e << " " << n << endl; //Код Дена
                        std::cout << "Закрытый ключ: " << d << " " << n << endl; //Код Дена
                    }
                    else
                    {
                        std::cout << "\nPublic key: " << e << " " << n << endl; //Код Дена
                        std::cout << "Secret key: " << d << " " << n << endl; //Код Дена
                    }
                    secretkey[0] = d; //Код Дена
                    secretkey[1] = n; //Код Дена
                    publickey[0] = e; //Код Дена
                    publickey[1] = n; //Код Дена
                    again = false; //Код Дена
                }
                else
                {
                    if (lang == "rus")
                    std::cout << "\n\nНеудачный подбор\n\n"; //Код Дена
                    else
                    {
                        cout << "\n\nError\n\n"; //Код Дена
                    }
                    again = true; //Код Дена
                    fails++; //Код Дена
                }
                if (fails > 9)
                {
                    again = false; //Код Дена
                    if (lang == "rus")
                    std::cout << "Допущено 10 неправильных подборов, попробуйте сменить критерии ключа\n"; //Код Дена
                    else
                    {
                        cout << "\n\nThere are 10 erros, change options\n\n"; //Код Дена
                    }
                }
            }
            again = true; //Код Дена
        }

        if (chooseshtuka[0] == '2')
        {
            unsigned long long actpublickey[2] = { 0, 0 }; //Код Дена
            if (lang == "rus")
            cout << "Использовать уже имеющийся публичный ключ?(Y/N) "; //Код Дена
            else
            {
                cout << "Use your public key?(Y/N) "; //Код Дена
            }
            cin >> chooseshtuka; //Код Дена
            if (chooseshtuka[0] == 'y' || chooseshtuka[0] == 'Y')
            {
                actpublickey[0] = publickey[0]; //Код Дена
                actpublickey[1] = publickey[1]; //Код Дена
            }
            else
            {
                if (lang == "rus")
                {
                    cout << "\nВведите первую часть публичного ключа "; //Код Дена
                    cin >> actpublickey[0]; //Код Дена
                    cout << "\nВведите вторую часть публичного ключа "; //Код Дена
                    cin >> actpublickey[1]; //Код Дена
                }
                else
                {
                    cout << "\nEnter first part of public key "; //Код Дена
                    cin >> actpublickey[0]; //Код Дена
                    cout << "\nEnter second part of public key "; //Код Дена
                    cin >> actpublickey[1]; //Код Дена
                }
            }
            if (lang == "rus")
            cout << "\nВведите число, которое хотите зашифровать "; //Код Дена
            else
            {
                cout << "\nEnter number for encoding "; //Код Дена
            }
            int shhtuka; //Код Дена
            cin >> shhtuka; //Код Дена
            unsigned long long shhhtuka = pow(shhtuka, actpublickey[0]); //Код Дена
            cout << "\n" << shhhtuka; //Код Дена
            shhhtuka = shhhtuka % actpublickey[1]; //Код Дена
            if (lang == "rus")
            cout << "\n" << "Зашифрованное число:"; //Код Дена
            else
            {
                cout << "\n" << "Encoding number:"; //Код Дена
            }
            cout << "\n" << shhhtuka; //Код Дена
            cout << "\n"; //Код Дена
        }

        if (chooseshtuka[0] == '3')
        {
            unsigned long long actsecretkey[2] = { 0, 0 }; //Код Дена
            if (lang == "rus")
            cout << "Использовать уже имеющийся секретный ключ?(Y/N) "; //Код Дена
            else
            {
                cout << "Use your secret key?(Y/N) "; //Код Дена
            }
            cin >> chooseshtuka; //Код Дена
            if (chooseshtuka[0] == 'y' || chooseshtuka[0] == 'Y')
            {
                actsecretkey[0] = secretkey[0]; //Код Дена
                actsecretkey[1] = secretkey[1]; //Код Дена
            }
            else
            {
                if (lang == "rus")
                {
                    cout << "\nВведите первую часть секретного ключа "; //Код Дена
                    cin >> actsecretkey[0]; //Код Дена
                    cout << "\nВведите вторую часть секретного ключа "; //Код Дена
                    cin >> actsecretkey[1]; //Код Дена
                }
                else
                {
                    cout << "\nEnter first part of secret key "; //Код Дена
                    cin >> actsecretkey[0]; //Код Дена
                    cout << "\nEnter second part of secret key "; //Код Дена
                    cin >> actsecretkey[1]; //Код Дена
                }
            }
            if (lang == "rus")
            cout << "\nВведите зашифрованное число "; //Код Дена
            else
            {
                cout << "\nEnter number for decoding "; //Код Дена
            }

            unsigned long long shhhtuka; //Код Дена

            cin >> shhhtuka; //Код Дена

            shhhtuka = pow(shhhtuka, actsecretkey[0]); //Код Дена

            cout << "\n" << shhhtuka; //Код Дена

            shhhtuka = shhhtuka % actsecretkey[1]; //Код Дена
            if (lang == "rus")
            cout << "\n" << "Расшифрованное сообщение:"; //Код Дена
            else
            {
                cout << "\n" << "Decoding number:"; //Код Дена
            }
            cout << "\n" << shhhtuka; //Код Дена cout << "\n"; //Код Дена
        }

        system("pause"); //Код Дена
        system("ClS"); //Код Дена
        chooseshtuka.clear(); //Код Дена
    }
    return 0; //Код Дена
}