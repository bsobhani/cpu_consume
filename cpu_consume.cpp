#include <cstdio>
#include <cstdlib>
#include <omp.h>

int nth_prime(int n){
	if(n<2)	return 2;
	int p = nth_prime(n-1) + 1;
	while(true){
		//const int N=100;
		bool is_prime = true;
		//int is_not_prime_arr[N] = {0};
		//omp_set_num_threads(N);
		for(int i=1; i<n-1; ++i){
			//printf("here\n");
			//printf("thread num %d\n", omp_get_thread_num());
			int d = nth_prime(i);
			//if(p%d==0) is_not_prime_arr[omp_get_thread_num()] = 1;
			if(p%d==0) is_prime = false;
		}
		//for(int i=0; i<N; ++i){
		//	if(is_not_prime_arr[i]==1) is_prime = false;
		//}
		if(is_prime) return p;
		p += 1;
	}
	return -1;
}

int main(){
	//printf("test\n");
	int shift=0;
	omp_set_num_threads(10);
	#pragma omp parallel for
	for(int i=shift+1; i<shift+1000; ++i) printf("%d\n", nth_prime(i));
	//printf("%d\n", nth_prime(7777));
	return 0;
}
