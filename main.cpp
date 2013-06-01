#include <QCoreApplication>
#include <iostream>
#include <fstream>

using namespace std;

int
getFibonacciNum(int n);
// ---------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /**
     * n - размер гипер куба
     * k - размерность.
     */

    int n = 0, k = 0;

    ifstream file("C:\\Users\\Dorian\\Desktop\\Sources"
                  "\\Olympiad\\O6\\Исходный файл.txt");
    if(file.is_open())
    {
        string  line,strVar1,strVar2;

        while(file.good())
        {
            getline(file,line);

            for(unsigned int i = 0; i < line.size(); ++i)
            {
                if(line.at(i) == ' ')
                {
                    strVar1.append(line.begin(),    line.begin()+i);
                    strVar2.append(line.begin()+i+1,line.end());

                    n = atoi(strVar1.c_str());
                    k = atoi(strVar2.c_str());
                }
            }
        }

        cout << n << " " << k << endl;

        unsigned long int S = 0ul;

        if(n == 1)
        {
            S = 1;
        }
        else
        {
            for(int i = 0; i < n*k; ++i)
            {
                S += getFibonacciNum(i);
                cout << getFibonacciNum(i) << " ";
            }
        }

        cout << endl << "S mod 1000000007 = " << S%1000000007 << endl;

    }

    return a.exec();
}
// ---------------------------------------------------------------------
int
getFibonacciNum(int n)
{
    if(n==0||n==1)
    {
        return n;
    }
    else
    {
        //в этой строке вызываем функцию рекурсивно
        return getFibonacciNum(n-1)+getFibonacciNum(n-2);
    }
}
