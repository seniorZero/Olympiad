#include <QCoreApplication>
#include <iostream>
#include <fstream>

using namespace std;

/** ��������� ������ ����*/
struct Cell
{
    int  value;
    bool isValid;
};
// ---------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ifstream file("C:\\Users\\Dorian\\Desktop\\Sources"
                  "\\Olympiad\\O8\\�������� ����.txt");

    /** ������� ���� � ��������� ������ **/

    if(file.is_open())
    {
        string  line;
        int     lineNumber = 0;

        /**
         * N - ����� �����
         * M - ������ �����
         * K - ���������� �������
         */

        int     N,M,K;
        Cell  **boardArray;

        while(file.good())
        {
            getline(file,line);
            lineNumber++;

            // ---------------------------------------------------------------------
            if(lineNumber == 1)
            {
                char *pch = strtok(const_cast<char*>(line.c_str())," ");
                /** �������������� ���������� N,M,K*/
                for(int i = 0;pch != NULL; ++i)
                {
                    switch(i)
                    {
                    case 0 : N = atoi(pch);
                    case 1 : M = atoi(pch);
                    case 2 : K = atoi(pch);
                    }
                    pch = strtok(NULL, " ");
                }
                /** ������� ������ ��� �������*/
                boardArray = new Cell*[N];
                for(int i = 0; i <= N; ++i)
                {
                    boardArray[i] = new Cell[M];
                }
                cout << N << " " << M << " " << K << endl;
            }
            // ---------------------------------------------------------------------
            else
            {
                char *pch = strtok(const_cast<char*>(line.c_str())," ");
                /** �������������� ������ ����������*/
                for(int i = 0;pch != NULL; ++i)
                {
                    boardArray[lineNumber-2][i].value   = atoi(pch);
                    boardArray[lineNumber-2][i].isValid = true;
                    pch = strtok(NULL, " ");
                }
            }
            // ---------------------------------------------------------------------
        }
        cout << endl;
        /** ������� ����� �� ����� � ������ ���������� �������*/
        /** ���������� ����������� �������� ����*/
        int X_max_v,Y_max_v;
        int max_v = 0;
        for(int i = 0; i < N; ++i)
        {
            for(int k = 0; k < M; ++k)
            {
                if(boardArray[i][k].value >= 0)
                {
                    cout << " " << boardArray[i][k].value << "\t";
                }
                else
                {
                    cout << boardArray[i][k].value << "\t";
                }

                if(max_v < boardArray[i][k].value)
                {
                    max_v   = boardArray[i][k].value;
                    X_max_v = i;
                    Y_max_v = i;
                }
            }
            cout << endl;
        }

        /**
         * ������ ����������� ������ �� ����� ����
         * ���� � �� ���������� �� ����� ��� ������
         * ������� �����
         */

        int S = 0;
        int NumOfStatuette = K;
        for(int TYPE = 2; TYPE < 3 && NumOfStatuette!=0; --TYPE)
        {
            for(int i = 0; i < N; ++i)
            {
                for(int k = 0; k < M; ++k)
                {
                    // ---------------------------------------------------------------------
                    if(TYPE == 0)
                    {
                        if(k+1 != M)
                        {
                            if(boardArray[i][k].value > 0 &&
                               boardArray[i][k].isValid)
                            {
                                if(boardArray[i][k+1].value > 0 &&
                                   boardArray[i][k+1].isValid)
                                {
                                    /** ����� �������� "���������" �������������*/
                                    NumOfStatuette--;
                                    S += boardArray[i][k+1].value +
                                         boardArray[i][k].value;

                                    boardArray[i][k].isValid   = false;
                                    boardArray[i][k+1].isValid = false;
                                }
                            }
                        }
                        if(i+1 != N)
                        {
                            if(boardArray[i][k].value > 0 &&
                               boardArray[i][k].isValid)
                            {
                                if(boardArray[i+1][k].value > 0 &&
                                   boardArray[i+1][k].isValid)
                                {
                                    /** ����� �������� "���������" �����������*/
                                    NumOfStatuette--;
                                    S += boardArray[i+1][k].value +
                                         boardArray[i][k].value;

                                    boardArray[i][k].isValid   = false;
                                    boardArray[i+1][k].isValid = false;
                                }
                            }
                        }
                    }
                    // ---------------------------------------------------------------------
                    if(TYPE == 1)
                    {
                        if((k+1 != M) && (i+1 != N))
                        {
                            if(boardArray[i][k].value > 0 &&
                               boardArray[i][k].isValid)
                            {
                                if(boardArray[i][k+1].value > 0 &&
                                   boardArray[i][k+1].isValid)
                                {
                                    if(boardArray[i+1][k].value > 0 &&
                                       boardArray[i+1][k].isValid)
                                    {
                                        if(boardArray[i+1][k+1].value > 0 &&
                                           boardArray[i+1][k+1].isValid)
                                        {
                                            /** ����� �������� "���������"*/
                                            NumOfStatuette--;
                                            S +=    boardArray[i]  [k+1].value  +
                                                    boardArray[i+1][k+1].value  +
                                                    boardArray[i+1][k].value    +
                                                    boardArray[i]  [k].value;

                                            boardArray[i]  [k].isValid   = false;
                                            boardArray[i]  [k+1].isValid = false;
                                            boardArray[i+1][k+1].isValid = false;
                                            boardArray[i+1][k].isValid   = false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    // ---------------------------------------------------------------------
                }
            }
        }
        cout << "S = " << S;
        file.close();
    }
    
    return a.exec();
}
