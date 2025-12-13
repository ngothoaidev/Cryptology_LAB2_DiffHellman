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
    BigInt g(num2); // base g
    BigInt y(num3);
    BigInt m(num4);
    BigInt r(num5);
    BigInt h(num6);
    inputFile.close();

    // Output Results
    std::cout << "Input Data:\n";
    std::cout << "p: " << p.to_hex_string() << std::endl;
    std::cout << "g: " << g.to_hex_string() << std::endl;
    std::cout << "y: " << y.to_hex_string() << std::endl;
    std::cout << "m: " << m.to_hex_string() << std::endl;
    std::cout << "r: " << r.to_hex_string() << std::endl;
    std::cout << "h: " << h.to_hex_string() << std::endl;

    if ((r <= 0) || (r >= p) || (h <= 0) || (h >= p) || (m < 0) || (m >= p)) {
        outputFile << "Signature is invalid." << std::endl;
        std::cout << "Signature is invalid." << std::endl;
        outputFile.close();
        return 0;
    }
    BigInt gm = powMod(g, m, p);
    BigInt yr = powMod(y, r, p);
    BigInt rh = powMod(r, h, p);
    BigInt v = (yr * rh) % p;
    bool result = (gm == v);

    outputFile << result << std::endl;
    outputFile.close();
    return 0;
}