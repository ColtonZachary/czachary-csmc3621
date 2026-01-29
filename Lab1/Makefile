a.out: Lab1_Q1.o Lab1_Q2.o Lab1_Q3.o Lab1_Q4.o
	g++ -g Lab1_Q1.o Lab1_Q2.o Lab1_Q3.o Lab1_Q4.o -o a.out

Lab1_Q1.o: Lab1_Q1.cpp
	g++ -g -c Lab1_Q1.cpp

Lab1_Q2.o: Lab1_Q2.cpp
	g++ -g -c Lab1_Q2.cpp

Lab1_Q3.o: Lab1_Q3.cpp
	g++ -g -c Lab1_Q3.cpp

Lab1_Q4.o: Lab1_Q4.cpp
	g++ -g -c Lab1_Q4.cpp

clean:
	rm -f *.o a.out

run: a.out
	./a.out 8 #<- place number here for Lab1_Q4