cpu_consume: cpu_consume.cpp
	g++ cpu_consume.cpp -o cpu_consume -fopenmp

clean:
	rm cpu_consume
