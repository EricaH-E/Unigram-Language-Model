all: UnigramLM StringProbability

UnigramLM:
	g++ -o UnigramLM main.cpp UnigramLM.cpp

StringProbability:
	g++ -o StringProbability main2.cpp 

clean:
	rm UnigramLM StringProbability  *.o
