#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


struct Plug
{
    int currentWeight;
    int destructionWeight;
};
// ---------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<Plug*> plugsArray;
    
    ifstream file("C:\\Users\\Dorian\\Desktop\\Sources"
                  "\\Olympiad\\O7\\Исходный файл.txt");
    if(file.is_open())
    {
        string  line;
        int     lineNum = 0;

        while(file.good())
        {
            lineNum++;
            getline(file,line);

            if(lineNum!=1)
            {
                for(unsigned int i = 0; i < line.size(); ++i)
                {
                    if(line.at(i) == ' ')
                    {
                        string  strVar1,strVar2;
                        strVar1.append(line.begin(),    line.begin()+i);
                        strVar2.append(line.begin()+i+1,line.end());

                        plugsArray.push_back(new Plug());
                        plugsArray.back()->currentWeight     = atoi(strVar1.c_str());
                        plugsArray.back()->destructionWeight = atoi(strVar2.c_str());
                    }
                }
            }
        }

        int minResult  = 0;

        for(int j = 0; j < plugsArray.size(); ++j)
        {
            int min     = 0;
            int current = 0;
            for(unsigned int i = j; i < plugsArray.size(); ++i)
            {
                current += plugsArray.at(i)->currentWeight;
                if(current >= plugsArray.at(i)->destructionWeight)
                {
                    continue;
                }
                else
                {
                    min += plugsArray.at(i)->destructionWeight -
                           current;
                    current += min;
                }
            }

            if(j == 0)
            {
                minResult = min;
            }
            else
            {
                minResult = minResult < min ? minResult : min;
            }
            cout << current << " " << min << endl;
        }

        cout << "Result is : " << minResult;

        file.close();
    }

    return a.exec();
}
