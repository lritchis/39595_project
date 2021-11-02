#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main(int argc, char *argv[]) {
    std::vector<std::string> vec { "dumb", "frick", "I'm gonna", "pop off"};
      
    // Iterator used to store the position 
    // of searched element
    std::vector<std::string>::iterator it;
      
    // Element to be searched
    std::string ser = "pop off";
      
    // std::find function call
    it = std::find (vec.begin(), vec.end(), ser);
    int posit;
    if (it != vec.end())
    {
        posit = it - vec.begin();
        std::cout << "Element " << ser <<" found at position : " ;
        std::cout << vec[posit] << " (counting from zero) \n" ;
    }
    else
        std::cout << "Element not found.\n\n";

    std::cout << vec[3];
    return 0;
}