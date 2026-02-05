#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class classSection {
	private:
		double averageScore;
		
	public:
		string courseName;
		int CRN;
		int numberOfStudents;
	
		classSection(string cname, int crn) {
			courseName = cname;
			CRN = crn;
		}
		
		double getAverageScore() {
			return averageScore;
		}
		
		void setAverageScore(double avgScore){
			averageScore = avgScore;
		}
		
};


int main() {

	//Declare two variables class1 and class2, that are instances of classSection class 
	//Initialize the two variables using proper valuesw
	// To Do (1 point)
	classSection class1("Math", 123);
	classSection class2("CS", 321);
	
	// Declare and initialize the pointer pclass1 to the address of class1 and pclass2 to the address of class2
	// To Do (1 point)
	classSection* pclass1 = &class1;
	classSection* pclass2 = &class2;

	// Set the numberOfStudents field of class1 to 30 using class. access method
	// Set the numberOfStudents field of class2 to 25 using pointer-> access method
	// To Do (1 points)
	class1.numberOfStudents = 30;
	pclass2->numberOfStudents = 25;
	
	//Change the CRN field of class2 to 24680 using dereference operator* with pointer and . access method
	// To Do (1 point)
	(*pclass2).CRN = 24680;
	
	//Set the averageScore of class1 to 87.5 with class. access method with the help of setAverageScore function
	//Set the averageScore of class2 to 82.0 with pointer-> access method with the help of setAverageScore function
	// To Do (1 points)
	class1.setAverageScore(87.5);
	pclass2->setAverageScore(82.0);
	
	// Print the averageScore of class1 with pointer-> access method and with the help of getAverageScore function
	// To Do (1 point)
	cout << pclass1->getAverageScore() << endl;
	
	//Print the averageScore of class2 using dereference operator* with pointer and . access method and with the help of getAverageScore function
	// To Do (1 point)
	cout << (*pclass2).getAverageScore() << endl;

	return 0;
}
