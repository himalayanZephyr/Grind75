#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int start_color = image[sr][sc];
        int rows = image.size();
        int cols = image[0].size();

        if(start_color != color){ //Causes an infinite loop otherwise
            dfs(image, sr, sc, rows, cols, start_color, color);
        }

        return image;

    }

    void dfs(vector<vector<int>>& image, int i, int j, int r, int c, int start_color, int color) {

        if ((0 <= i && i < r) && (0 <= j && j < c) && (image[i][j] == start_color)) {

            image[i][j] = color;

            int neighbours[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

            for(int k=0; k<4; k++) {
                int di = neighbours[k][0];
                int dj = neighbours[k][1];
                dfs(image, i+di, j+dj, r, c, start_color, color);
            }
            
        } 
    }
};