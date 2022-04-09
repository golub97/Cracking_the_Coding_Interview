//Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
//column are set to 0. 
#include <iostream>
#include <vector>

using namespace std;

void zer_matrix(vector<vector<int>> &matrix) 
{
    int row_size    = matrix.size();
    int column_size = matrix[0].size();
    
    bool* row    = new bool[row_size];
    bool* column = new bool[column_size]; 
    
    for(int i = 0; i < row_size; ++i) //initialize rows
        row[i] = false;
        
    for(int j = 0; j < column_size; ++j) //initialize columns
        column[j] = false;
    
    for(int i = 0; i < row_size; ++i)  
        for(int j = 0; j < column_size; ++j)  
        {
            if(matrix[i][j] == 0)
            {
                row[i] = true;
                column[j] = true;
            }
        }
        
    for(int i = 0; i < row_size; ++i)  
        for(int j = 0; j < column_size; ++j)  
        {
            if(matrix[i][j] == 0)
            {
                row[i] = true;
                column[j] = true;
            }
        }

    // Nullify rows
    for (int i = 0; i < row_size; ++i)
        if (row[i])
            for(int j = 0; j < column_size; ++j)
                matrix[i][j] = 0;
                
    // Nullify columns
    for (int i = 0; i < column_size; ++i)
        if (column[i])
            for(int j = 0; j < column_size; ++j)
                matrix[j][i] = 0;
}

int main()
{
    vector<vector<int>> matrix
    { 
        { 5, 2, 3 },
        { 4, 0, 6 },
        { 7, 8, 5 }
    };
    
    for(int i = 0; i < matrix.size(); ++i)  
    {
        for(int j = 0; j < matrix[i].size(); ++j)  
        {
            cout << matrix[i][j] << " "; 
        }
        cout << endl;  
    }
    
    cout << endl;
    zer_matrix(matrix);
    
    for(int i = 0; i < matrix.size(); ++i)  
    {
        for(int j = 0; j < matrix[i].size(); ++j)  
        {
            cout << matrix[i][j] << " "; 
        }
        cout << endl;  
    }
    
    return 0;
}
