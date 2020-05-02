#include <iostream>
#include <vector>
#include <iomanip>

void Print(const std::vector<std::vector<int>>& arr2d) {
    
    for (size_t i { 0 }; i < arr2d.size(); i++) {
        for (size_t j { 0 }; j < arr2d[i].size(); j++) {
            std::cout << std::setw(5) << arr2d[i][j];
        }
        std::cout << "\n";
    }
}

void SpiralOrder(const std::vector<std::vector<int>>& arr2d) {
    int row_size = arr2d.size();
    int col_size = arr2d[0].size();
    int row = 0, col = 0;
    while (row < row_size && col < col_size) {
        
        for (int i = col; i < col_size; i++) {
            std::cout << std::setw(3) << arr2d[row][i];
        }
        row++;

        for (int i = row; i < row_size; i++) {
            std::cout << std::setw(3) << arr2d[i][col_size - 1];
        }
        col_size--;

        if (row < row_size) {
            for (int i = col_size - 1; i >= col; i--) {
                std::cout << std::setw(3) << arr2d[row_size - 1][i];
            }
            row_size--;
        }
    
        if (col < col_size) {
            for (int i = row_size - 1; i >= row; i--) {
                std::cout << std::setw(3) << arr2d[i][col];
            }
            col++;
        }
    }
    std::cout << "\n";
}

int main (int argc, char *argv[]) {
    std::vector<std::vector<int>> arr2d { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    Print(arr2d);

    SpiralOrder(arr2d);
    return 0;
}

