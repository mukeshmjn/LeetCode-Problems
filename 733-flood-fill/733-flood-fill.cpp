class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor) dfs(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
    
    private: void dfs(vector<vector<int>>& img, int i,int j,int oC,int nC){
        if(i<0 || j<0 || i>=img.size() || j>=img[0].size() || img[i][j]!=oC) return;
        img[i][j] = nC;
        dfs(img,i+1,j,oC,nC); dfs(img,i-1,j,oC,nC);
        dfs(img,i,j+1,oC,nC); dfs(img,i,j-1,oC,nC);
    }
};