#include "../bigInt.h"

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <bigint1> <bigint2>\n";
        return 1;
    }

    // File Paths
    const std::string inputFileName = "data\\Project_02_DiscreteLogarithm\\project_02_02\\test_00.inp";
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
    std::string num1, num2, num3, num4;
    inputFile >> num1 >> num2 >> num3 >> num4;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    reverse(num3.begin(), num3.end());
    reverse(num4.begin(), num4.end());

    BigInt p(num1); // prime number p
    BigInt a(num2); // number a
    BigInt b(num3); // number b
    BigInt g(num4); // primitive root g
    inputFile.close();

    // Output Results
    std::cout << "Input Data:\n";
    std::cout << "p: " << p.to_string() << std::endl;
    std::cout << "a: " << a.to_string() << std::endl;
    std::cout << "b: " << b.to_string() << std::endl;
    std::cout << "g: " << g.to_string() << std::endl;

    // outputFile << p.to_string() << std::endl;
    // outputFile << a.to_string() << std::endl;
    // outputFile << b.to_string() << std::endl;
    // outputFile << g.to_string() << std::endl;
    BigInt A = powMod(g, a, p); // A = g^a mod p
    BigInt B = powMod(g, b, p); // B = g^b
    BigInt sharedKeyA = powMod(B, a, p); // sharedKeyA = B^a mod p
    BigInt sharedKeyB = powMod(A, b, p); // sharedKeyB = A^b mod p

    if (sharedKeyA != sharedKeyB) {
        std::cerr << "Error: Shared keys do not match!\n";
        return 1;
    }
    outputFile << A.to_string() << std::endl;
    outputFile << B.to_string() << std::endl;
    outputFile << sharedKeyA.to_string() << std::endl;
    outputFile.close();
    return 0;
}