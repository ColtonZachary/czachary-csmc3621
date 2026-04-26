#include <iostream>
#include <string>
using namespace std;

struct struct3 {
    int mv5;
    string mv6;
};

struct struct2 {
    struct3* mv3; // A pointer that points to a variable whose type is struct3
    int mv4;
};

struct struct1 {
    string mv1;
    struct2 mv2; // The data type of mv2 is struct2
};

int main() {
    // Initialize struct3
    struct3 s3;
    s3.mv5 = 42;
    s3.mv6 = "Hello from mv6";

    // Initialize struct2, pointing mv3 to s3
    struct2 s2;
    s2.mv3 = &s3;
    s2.mv4 = 10;

    // Initialize struct1
    struct1 s1;
    s1.mv1 = "struct1 member";
    s1.mv2 = s2;

    // Access mv6 through struct1 and output it
    cout << "Value of mv6 accessed through struct1: " 
         << s1.mv2.mv3->mv6 << endl;

    return 0;
}