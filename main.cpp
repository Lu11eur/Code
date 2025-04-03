#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>

/*int main() {
    int n;
    std::string input;

    while (true) {
        std::cout << "Enter a number (or empty to exit): ";
        std::getline(std::cin, input);
        if (input.empty()) break;

        try {
            n = std::stoi(input);
            if (n < 1) throw std::invalid_argument("Number must be positive");

            for (int a = 2; a <= n; ++a) {
                for (int b = 2; b <= n; ++b) {
                    int c2 = a * a + b * b;
                    int c = static_cast<int>(sqrt(c2));
                    if (c * c == c2 && c <= n) {
                        std::cout << "a: " << a << "\tb: " << b << "\tc: " << c << '\n';
                    }
                }
            }

        } catch (std::exception& e) {
            std::cout << "Invalid input: " << e.what() << "\n";
        }
    }

    return 0;
}
*/

void printPascalsTriangle(int n) {
    std::vector<std::vector<int>> triangle(n);

    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1);      
        triangle[i][0] = triangle[i][i] = 1; 

        for (int j = 1; j < i; ++j)
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; 
        
        std::cout << std::string((n - i - 1) * 2, ' ');
        for (int num : triangle[i])
            std::cout << std::setw(4) << num;
        std::cout << "\n";
    }
}

int main() {
    int rows;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;

    if (rows < 1) {
        std::cout << "Number must be positive." << std::endl;
        return 1;
    }

    printPascalsTriangle(rows);
    return 0;
}