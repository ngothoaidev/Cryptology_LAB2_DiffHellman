#include "../bigInt.h"

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <bigint1> <bigint2>\n";
        return 1;
    }

    // File Paths
    const std::string inputFileName = "data\\Project_02_DiscreteLogarithm\\project_02_01\\test_01.inp";
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
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    std::vector<BigInt> arr; // Array to store n numbers of U(prime)
    BigInt prime(num1); // prime number p
    BigInt n(num2); // n numbers in U(prime)
    int count = std::stoi(num2, nullptr, 16); // Convert hex string to integer
    for(int i = 0; i < count; i++) {
        std::string singleNum;
        inputFile >> singleNum; // Read each number in U(prime) in one line and store it in the array
        reverse(singleNum.begin(), singleNum.end());
        arr.push_back(BigInt(singleNum));
    }
    inputFile >> num4; // Read the g number
    reverse(num4.begin(), num4.end());
    BigInt g(num4);
    inputFile.close();

    // Check if g is a primitive root modulo prime
    for (int i = 0; i < count; i++){
        BigInt tmp = (prime - BigInt("1")) / arr[i]; // tmp = (p - 1) / k where k is each element in U(prime)
        if(powMod(g, tmp, prime) == 1){ // If g^tmp mod prime == 1 for any k in U(prime), then g is not a primitive root modulo prime
            outputFile << "0" << std::endl;
            outputFile.close();
            return 0;
        }
    }


    outputFile << "1" << std::endl;
    outputFile.close();
    return 0;
}