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

    // Output Results
    std::cout << "Input Data:\n";
    std::cout << "p: " << p.to_hex_string() << std::endl;
    std::cout << "g: " << g.to_hex_string() << std::endl;
    std::cout << "a: " << a.to_hex_string() << std::endl;
    std::cout << "b: " << b.to_hex_string() << std::endl;

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