#include <QtCore/QCoreApplication>
#include <iostream>
#include <fstream>

using namespace std;

string
generateName(const int&n,const int&k);

int
main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    ifstream file("C:\\Users\\Dorian\\Desktop\\Sources"
                  "\\Olympiad\\O2\\Исходный файл.txt");

    /** Откроем файл и распарсим строку **/

    if(file.is_open())
    {
        string  line,strVar1,strVar2;

        int     n,k;/**
                     * n - количество букв в слове
                     * k - количество букв использ. алфавита
                     */

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

                    cout << "n = " << n << ";k = " << k  << ";" << endl;

                    if(n > 100000 || n < 0)
                    {
                        cout << "n limit is exceeded!" << endl;
                    }
                    if(k > 26 || k < 0)
                    {
                        cout << "k limit is exceeded!" << endl;
                    }

                    cout << generateName(n,k) << endl;
                }
            }

            /**
             * Необходимо обеспечить вывод в файл слова
             * с наименьшим количеством палиндромов
             */
        }
        file.close();
    }
    else
    {
        cout << "File dont found!" << endl;
    }

    return a.exec();
}

string
generateName(const int&n,const int&k)
{
            string name;
    static  string ABS = "absdefghijklmnopqrstuvwxyz";

    if(n <= k)
    {
        ABS.resize(n);
        return ABS;
    }
    else
    {
        int c = 0;
        for(int i = 0; i < n; ++i)
        {
            name.push_back(ABS[c]);
            c = c==k-1?0:c+1;
        }
    }

    return name;
}
