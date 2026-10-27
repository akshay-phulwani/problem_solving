class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> arr(m, string(n, '#'));
        int i=0,j=0;
        while(i!=m-1||j!=n-1){
            arr[i][j]='.';
            if(i < m-1 && (j == n-1 || m-i >= n-j))
            i++;
            else
            j++;
        }
        arr[m-1][n-1] = '.';
        return arr;
    }
};