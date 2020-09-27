all:
	g++ -Wall Graph.cpp GraphTests.cpp -o graph-tests
	g++ -Wall BetterPriorityQueue.cpp BPQTests.cpp Graph.cpp -o bpq-tests 
	g++ -Wall Dijkstra.cpp Graph.cpp BetterPriorityQueue.cpp -o dijkstra 