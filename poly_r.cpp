#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

struct Point
{
    int     X,Y;
    float   angle,distance;
    int     num;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<Point*>  pointArray;

    ifstream file("C:\\Users\\Dorian\\Desktop\\Sources"
                  "\\Olympiad\\O10\\Исходный файл.txt");

    /** Откроем файл и распарсим строку **/

    if(file.is_open())
    {
        string  line;
        int     lineNumber = 0;

        while(file.good())
        {
            getline(file,line);
            lineNumber++;

            // ---------------------------------------------------------------------
            if(lineNumber > 1)
            {
                pointArray.push_back(new Point());
                pointArray.back()->num = lineNumber-1;
                char *pch = strtok(const_cast<char*>(line.c_str())," ");
                /** Инициализируем переменные */
                for(int i = 0;pch != NULL; ++i)
                {
                    switch(i)
                    {
                    case 0 : pointArray.back()->X = atoi(pch);
                    case 1 : pointArray.back()->Y = atoi(pch);
                    }
                    pch = strtok(NULL," ");
                }
            }
            // ---------------------------------------------------------------------
        }
        /** Найдем правую нижнюю точку*/
        int rX = pointArray.at(0)->X,
            dY = pointArray.at(0)->Y;
        for(unsigned int i = 0; i < pointArray.size(); ++i)
        {
            rX = rX < pointArray.at(i)->X ? pointArray.at(i)->X : rX;
            dY = dY > pointArray.at(i)->Y ? pointArray.at(i)->Y : dY;

            cout <<  "X: " << pointArray.at(i)->X
                 << " Y:"  << pointArray.at(i)->Y << endl;
        }

        /** Перенесем координаты центра так,
         *  что бы все точки оказались левее
         *  и выше.
         */

        rX++;dY--;

        cout << rX << " " << dY << endl;
        /** Найдем углы и расстояния*/
        for(unsigned int i = 0; i < pointArray.size(); ++i)
        {
            pointArray.at(i)->angle = atan((static_cast<double>(dY - pointArray.at(i)->Y))/
                                           (static_cast<double>(rX - pointArray.at(i)->X)));
            pointArray.at(i)->distance=sqrt(pow(static_cast<double>(pointArray.at(i)->X-rX),2)+
                                            pow(static_cast<double>(pointArray.at(i)->Y-dY),2));
        }
        /** Сортируем массив по убыванию угла*/
        for(unsigned int i = 0; i < pointArray.size()-1; ++i)
        {
            for(unsigned int k = 0; k < pointArray.size()-1; ++k)
            {
                if(pointArray.at(k)->angle >
                   pointArray.at(k+1)->angle)
                {
                    Point *temp         = pointArray.at(k);
                    pointArray.at(k)    = pointArray[k+1];
                    pointArray.at(k+1)  = temp;
                }
            }
        }

        /** Выведем ответ*/
        cout << "Answer is:" << endl;
        for(unsigned int i = 0; i < pointArray.size(); ++i)
        {
            cout << pointArray.at(i)->num << " ";
        }

        file.close();
    }

    return a.exec();
}
