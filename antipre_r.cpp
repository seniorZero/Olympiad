#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string str;
    cout <<"Enter string: ";
    cin >> str;
    //cout << str.size() << endl;

    string adstr;
    int ct = 0;
    bool isInterrupt = false;

    for (int i=1; i <= str.size(); i++)
    {
        adstr.append(str.begin(), str.begin()+i);

        for (int k=0; k < adstr.size(); k++)
        {
            if (adstr[k] == adstr[adstr.size()-1-k])
            {
                ct++;
            }
            else
            {
                cout << ct << " ";
                isInterrupt = true;
                ct = 0;
                break;
            }
        }
        if(!isInterrupt)
        {
            cout << ct << " ";
        }
        isInterrupt = false;
        ct = 0;
        adstr.clear();
    }

    return a.exec();
}
