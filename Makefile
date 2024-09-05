bandit:
	g++ bandit.cpp -pthread -g  -o bandit

algo:
	g++ programm_algo.cpp -pthread -g  -o prog

multimap:
	g++ multimap_find.cpp -pthread -g  -o multi

lambda:
	g++ lambda.cpp -pthread -g  -o lambda

smart:
	g++ smart.cpp -pthread -g  -o smart

file:
	g++ file.cpp -pthread -g  -o file

analizator:
	g++ analizator.cpp -pthread -g  -o analizator

thread:
#	g++ thread.cpp -pthread -g  -o thread

all:
	g++ programm_algo.cpp -pthread -g  -o prog
	g++ multimap_find.cpp -pthread -g  -o multi
	g++ lambda.cpp -pthread -g  -o lambda
	g++ smart.cpp -pthread -g  -o smart
	g++ file.cpp -pthread -g  -o file
	g++ analizator.cpp -pthread -g  -o analizator
#	g++ thread.cpp -pthread -g  -o thread
	g++ bandit.cpp -pthread -g  -o bandit
