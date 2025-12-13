#include "../bigInt.h"

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <bigint1> <bigint2>\n";
        return 1;
    }

    // File Paths
    const std::string inputFileName  = argv[1];
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
    std::string num1, num2, num4;
    inputFile >> num1 >> num2;
    
    std::vector<BigInt> arr; // Array to store n numbers of U(prime)
    BigInt prime(num1); // prime number p
    BigInt n(num2); // n numbers in U(prime)
    int count = stoi(n.to_string()); // Convert BigInt n to int count
    for(int i = 0; i < count; i++) {
        std::string singleNum;
        inputFile >> singleNum; // Read each number in U(prime) in one line and store it in the array
        arr.push_back(BigInt(singleNum));
    }
    inputFile >> num4; // Read the g number
    BigInt g(num4);
    inputFile.close();

    BigInt primeMinus1 = prime - BigInt("1"); // p - 1
    // Check if g is a primitive root modulo prime
    for (int i = 0; i < count; i++){
        BigInt exp = (primeMinus1) / arr[i]; // exp = (p - 1) / k where k is each element in U(prime)
        if(powMod(g, exp, prime) == 1){ // If g^exp mod prime == 1 for any k in U(prime), then g is not a primitive root modulo prime
            outputFile << "0" << std::endl;
            outputFile.close();
            return 0;
        }
    }


    outputFile << "1" << std::endl;
    outputFile.close();
    return 0;
}