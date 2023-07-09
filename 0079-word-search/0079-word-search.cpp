class Solution {
public:
    bool solve(int i,int x,int y,vector<vector<char>>& board,string word){
        if(i==word.size()) return true;
        int n=board.size(),m=board[0].size();
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        char temp=board[x][y];
        board[x][y]='.';
        for(int j=0;j<4;j++){
            int nx=x+dx[j],ny=y+dy[j];
            if(nx>=0 && ny>=0 && nx<n && ny<m && board[nx][ny]==word[i]){
                if(solve(i+1,nx,ny,board,word)) return true;
            }
        }
        board[x][y]=temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    // board[i][j]='.';
                    if(solve(1,i,j,board,word)) return true;
                }
            }
        }
        return false;
    }
};