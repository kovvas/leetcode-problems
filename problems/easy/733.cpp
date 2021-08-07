// Number: 733
// Name: Flood Fill
// Tags: flood fill

class Solution {
public:
void helper(vector<vector<int>>& image, int sr, int sc, int newColor, int startColor) {
  int max_x = image[0].size();
  int max_y = image.size();
  // sr - y
  // sc - x
  // checks
  if (sr < 0 || sc < 0 || sr >= max_y || sc >= max_x) return;
  if (image[sr][sc] != startColor) return;
  // flooding
  image[sr][sc] = newColor;
  helper(image, sr + 1, sc, newColor, startColor);
  helper(image, sr - 1, sc, newColor, startColor);
  helper(image, sr, sc + 1, newColor, startColor);
  helper(image, sr, sc - 1, newColor, startColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
  int max_x = image[0].size();
  int max_y = image.size();
  // sr - x
  // sc - y
  // checks
  if (sr < 0 || sc < 0 || sr >= max_y || sc >= max_x) return image;
  if (image[sr][sc] == newColor) return image;
  // flooding
  int curColor = image[sr][sc];
  image[sr][sc] = newColor;
  helper(image, sr + 1, sc, newColor, curColor);
  helper(image, sr - 1, sc, newColor, curColor);
  helper(image, sr, sc + 1, newColor, curColor);
  helper(image, sr, sc - 1, newColor, curColor);
  return image;
}

