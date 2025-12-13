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
    std::string num1, num2, num3, num4, num5, num6;
    inputFile >> num1 >> num2 >> num3 >> num4 >> num5 >> num6;

    BigInt p(num1); // prime number p
    BigInt g(num2); // primitive root g
    BigInt y(num3); // positive integer y
    BigInt m(num4); // message m
    BigInt r(num5); // part of the signature r
    BigInt h(num6); // part of the signature h
    inputFile.close();

    if ((r <= 0) || (r >= p) || (h <= 0) || (h >= p) || (m < 0) || (m >= p)) {
        outputFile << "Signature is invalid." << std::endl;
        std::cout << "Signature is invalid." << std::endl;
        outputFile.close();
        return 0;
    }
    BigInt lhs = powMod(g, m, p);
    BigInt part1 = powMod(y, r, p);
    BigInt part2 = powMod(r, h, p);
    BigInt rhs = (part1 * part2) % p;
    bool result = (lhs == rhs);

    outputFile << result << std::endl;
    outputFile.close();
    return 0;
}