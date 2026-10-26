class Solution {
public:
 long long bfs(vector<vector<int>> &grid,int i,int j){
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 0) {
            return 0;
    }
    long long sum = grid[i][j];
    grid[i][j]=0;
    sum+=bfs(grid,i+1,j);
    sum+=bfs(grid,i-1,j);
    sum+=bfs(grid,i,j+1);
    sum+=bfs(grid,i,j-1);
    return sum;
 }
    int countIslands(vector<vector<int>>& grid, int k) {
        long long a=0,b=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]!=0){
                    b=bfs(grid,i,j);
                  if(b%k==0) a++;
                  }
                }
        }
        return a;
    }
};