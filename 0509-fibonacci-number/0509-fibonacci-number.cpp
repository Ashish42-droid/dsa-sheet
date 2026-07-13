class Solution {
public:
    int fib(int n) {
    double sqrt5 = std::sqrt(5);
    double phi = (1 + sqrt5) / 2;
    double psi = (1 - sqrt5) / 2;

    // Apply Binet's formula and round to the nearest integer
    return std::round((std::pow(phi, n) - std::pow(psi, n)) / sqrt5);
}

};