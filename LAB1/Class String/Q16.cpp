int ascendingRows(int arr[][1000], int row, int col) {
    int count = 0;
    for ( int i = 0 ; i<row;i++){
        bool flag = 1;
        for ( int j = 0; j<col-1;j++){
            if (arr[i][j] > arr[i][j+1]) {
                flag = 0;
                break;
            }
        }
        if ( flag) count ++;
    }
    return count;
}