# Kompilieren mit Optimierungsoption -O2, dadurch läuft das Programm nochmal fast doppelt so schnell
all:
	g++ -O2 solver.cpp impl.cpp main.cpp -o solver

clean:
	rm solver
