#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
int checkID(int idSP[],int priceSP[],int nID, int idBuy){
    for (int i = 0; i<nID;i++){
        if ( idSP[i] == idBuy) return priceSP[i];
    }
    return 0;
}
void calMoney(string price, string buy){
    ifstream f1 (price);
    ifstream f2 (buy);
    if (!f1.is_open()||!f2.is_open()) return;
    else {
        int nID;
        int idSP[100];
        int priceSP[100];
        int nKH;
        int idBuy;
        int count;
        f1 >> nID;
        for ( int i = 0;i<nID;i++){
            f1 >> idSP[i] >> priceSP[i];
        }
        f2 >> nKH;
        f2.ignore(100,'\n');
        for (int i = 0; i<nKH;i++){
            string line;
            getline(f2,line);
            int cost = 0;
            string nameKH ="";
            int pos = 0;
            while (line[pos] !=' ' && pos < (int)line.length())
                nameKH+=line[pos++];
            pos++;
            while (pos < (int)line.length()) {
            string s1 = "", s2 = "";
            while (pos < (int)line.length() && line[pos] != ' ')
                s1 += line[pos++];
            pos++; 
            while (pos < (int)line.size() && line[pos] != ' ')
                s2 += line[pos++];
            pos++; 
            int idBuy = stoi(s1);
            int count = stoi(s2);
           cost += checkID(idSP, priceSP, nID, idBuy) * count;
        }
cout<<nameKH<<" "<<cost<<endl;
    }
}}
int main() {
    
    return 0;
}