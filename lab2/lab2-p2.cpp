#include <iostream>
#include <string>

using namespace std;

struct struct3{
	int mv5;
	string mv6;
};

struct struct2{
	struct3 * mv3; 
	int mv4;
};

struct struct1{
	string mv1;
	struct2 mv2;
};


int main() {

	//Declare three variables: s1, s2, and s3
	//The date type of them are struct1, struct2, and struct3, respectively.
	//To Do (3 points)
	struct1 s1;
	struct2 s2;
	struct3 s3;
	
	
	//Initialize s1, s2, and s3 using suitable values for all the member variables.
	//To Do (3 points)
    s3.mv5 = 10;
    s3.mv6 = "Hello structs!";

    s2.mv3 = &s3; 
    s2.mv4 = 20;

    s1.mv1 = "Outer struct";
    s1.mv2 = s2;

	
	
	//Access the value of mv6 through s1, and output the value. 
	//In other words, you cannot use s2 or s3 explictly in your code.
	//To Do (2 points)
	cout << s1.mv2.mv3->mv6 << endl;

}
	
