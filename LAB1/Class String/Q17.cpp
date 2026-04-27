int primeColumns(int arr[][1000], int row, int col) {
    int count = 0;
    for ( int i = 0; i<col;i++){
           int sum = 0;
        bool flag = 0;
        for ( int j = 0 ; j<row;j++){
            sum+=arr[j][i];
        }
        if (sum<2) continue;
        flag = 1;
        for ( int k = 2; k*k<=sum;k++){
                if (sum%k == 0 ){
                    flag = 0;
                    break;  
                }
        }
        if(flag) count++;
        }
    return count;
}