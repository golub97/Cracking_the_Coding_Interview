//Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4 
//bytes, write a method to rotate the image by 90 degrees. Can you do this in place? 

#include <iostream>
#include <vector>

using namespace std;
 
int n = 3; //size

vector<vector<int>> rotate_matrix(vector<vector<int>> matrix)
{
    vector<vector<int>> temp
    { 
        { 0, 0, 0 },
        { 0, 0, 0 },
        { 0, 0, 0 }
    };
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            temp[j][n - i - 1] = matrix[i][j];
            
    return temp;
};

int main()
{
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
    
    vector<vector<int>> rotated_matrix = rotate_matrix(matrix);
    
    cout << endl;

    for(int i = 0; i < n; ++i)  
    {
        for(int j = 0; j < n; ++j)  
        {
            cout << rotated_matrix[i][j] << " "; 
        }
        cout << endl;  
    }
    return 0;
}
