#include <iostream>

using namespace std;
int giaithua ( int n){
    int ketqua = 1;
    for ( int i=1; i<=n;i++){
        ketqua*=i;
    }
    return ketqua;
}


int main(int narg, char** argv)
{
    int N;
    cin >> N;
    long result;
    result = giaithua(N); 
    cout << result << endl;
    return 0;
}