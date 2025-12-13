#include "../bigInt.h"

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <bigint1> <bigint2>\n";
        return 1;
    }

    // File Paths
    const std::string inputFileName = argv[1];
    const std::string outputFileName = argv[2];
    
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
    std::string num1, num2, num3, num4, num5;
    inputFile >> num1 >> num2 >> num3 >> num4 >> num5;
    inputFile.close();
    BigInt p(num1); // prime number p
    BigInt g(num2); // primitive root g
    BigInt x(num3); // private key x
    BigInt c1(num4); // ciphertext part 1
    BigInt c2(num5); // ciphertext part 2

    // Solve for h and m
    BigInt h = powMod(g, x, p); // h = g^x mod p
    BigInt s = powMod(c1, x, p); // s = c1^x mod p
    BigInt s_inv = invMod(s, p); // s_inv = s^(-1) mod p
    BigInt m = (c2 * s_inv) % p; // m = (c2 * s_inv) mod p


    // Output Results
    outputFile << convertToLittleEndian(h) << std::endl;
    outputFile << convertToLittleEndian(m) << std::endl;
    outputFile.close();
    return 0;
}