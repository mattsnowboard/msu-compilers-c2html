#include <iostream>

/**
 * @author user@msu.edu
 */
void func()
{
    std::cout << "In func" << std::endl;
}

int main(int argc, char **argv) {
    // An example with a different brace style
    int i;
    std::cin >> i;
    if (i < 2){
        std::cout << "<b>It's less than 2</b>";
    } else{
        // make sure escape sequences work in strings
        std::cout << "Other string";
        std::cout << "\"\\" << std::endl
                  << "\\\\" << std::endl
                  << "\\\"\\" << std::endl;
    }
    return 0;
}
