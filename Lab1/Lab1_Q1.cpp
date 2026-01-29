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
