#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Factorial(int i) {
    int p=1;
    if (i>=0) {
        for (int s=1; s<=i; ++s) {
	    p=p*s;
        }
    return p;
    }
    else 
        return 1;
}
