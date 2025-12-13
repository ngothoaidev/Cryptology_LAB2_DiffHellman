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
    std::string num1, num2, num3, num4;
    inputFile >> num1 >> num2 >> num3 >> num4;

    BigInt p(num1); // prime number p
    BigInt g(num2); // primitive root g
    BigInt a(num3); // Alice's private key a
    BigInt b(num4); // Bob's private key b
    inputFile.close();

    BigInt A = powMod(g, a, p); // A = g^a mod p
    BigInt B = powMod(g, b, p); // B = g^b mod p
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