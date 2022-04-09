//Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
//bytes, write a method to rotate the image by 90 degrees. Can you do this in place? 
#include <iostream>
#include <vector>

using namespace std;

bool rotate(vector<vector<int>> matrix) 
{
    if (matrix.size() == 0) return false;
    
    int n = matrix.size();
    int first = 0;
    int last  = 0;
    int offset = 0; 
    int top = 0;

    for (int layer = 0; layer < n / 2; layer++)
    {
        int first = layer;                
        int last = n - 1 - layer;
        
        for(int i = first; i < last; i++)
        {
            int offset = i - first; 
            int top = matrix[first][i]; //save top

            // left -> top
            matrix[first][i] = matrix[last - offset][first];
            
            // bottom -> left
            matrix[last - offset][first] = matrix[last][last - offset];

            //right -> bottom
            matrix[last][last - offset] = matrix[i][last];
            
            // top -> right
            matrix[i][last] = top; // right <- saved top 
        }
    }
    
    for(int i = 0; i < n; ++i)  
    {
        for(int j = 0; j < n; ++j)  
        {
            cout << matrix[i][j] << " "; 
        }
        cout << endl;  
    }
    
    return true;
}

int main()
{
    int n = 3;
    
    vector<vector<int>> matrix
    { 
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    
    for(int i = 0; i < n; ++i)  
    {
        for(int j = 0; j < n; ++j)  
        {
            cout << matrix[i][j] << " "; 
        }
        cout << endl;  
    }
    
    cout << endl;
    
    rotate(matrix);
    
    return 0;
}
