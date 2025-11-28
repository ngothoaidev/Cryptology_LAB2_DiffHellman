#include "../bigInt.h"

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <bigint1> <bigint2>\n";
        return 1;
    }

    // File Paths
    const std::string inputFileName = "data\\Project_02_DiscreteLogarithm\\project_02_01\\test_00.inp";
    const std::string outputFileName = "test_00.out";
    
    // Open input and output file
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);


    // Check Errors
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file: " << inputFileName << "\n";
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file: " << outputFileName << "\n";
        return 1;
    }


    // Read Data
    std::string num1, num2, num4;
    inputFile >> num1 >> num2;
    std::vector<BigInt> arr; // Array to store n numbers of U(prime)
    BigInt prime(num1); // prime number p
    BigInt n(num2); // n numbers in U(prime)
    for(int i = 0; i < num2.length(); i++) {
        std::string singleNum;
        inputFile >> singleNum; // Read each number in U(prime) in one line and store it in the array
        arr.push_back(BigInt(singleNum));
    }
    inputFile >> num4; // Read the g number
    BigInt g(num4);
    inputFile.close();


    

    return 0;
}