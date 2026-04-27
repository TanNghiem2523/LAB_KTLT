#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
void studendGrading(string fileName)
{
    int n;
    double average = 0;
    int countA = 0;
    int countB = 0;
    int countC = 0;
    int countD = 0;
    ifstream file(fileName);
    if (!file.is_open())
        return;
    else
    {
        file >> n;
        for (int i = 0; i < n; i++)
        {
            bool flag = 0;
            double temp = 0;
            double sum = 0;
            for (int j = 0; j < 4; j++)
            {
                file >> temp;
                sum += temp;
                if (temp < 5) flag = 1;
            }
            if (flag == 1) countD++;
            if (flag != 1)
            {
                average = sum / 4.0;
                if (average >= 8.0) countA++;
                else if ( average < 8.0 && average >= 6.5) countB++;
                else if ( average >= 5 && average < 6.5) countC++;
                else countD++;
            }
        }
    }
    cout <<"A"<<" "<<countA<<endl;
    cout<<"B"<<" "<<countB<<endl;
    cout <<"C"<<" "<<countC<<endl;
    cout<<"D"<<" "<<countD;
}
int main()
{

    return 0;
}