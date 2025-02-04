#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *a, int N, int M){
	int n = N * M;
	cout << fixed << setprecision(2);
	for(int i = 0; i < n; i++){
		cout << *(a + i) << " ";
		if(i % M == M - 1) cout << endl;
	}
}

void randData(double *a, int N, int M){
	int n = N * M;

	for(int i = 0; i < n; i++){
		int r = rand() % 101;
		*(a + i) = r / 100.0;
	}
}

void findRowSum(const double *a, double *sum, int N, int M){
	int n = N * M;
	int count = 0;

	for(int i = 0; i < n; i++){
		if(i % M == 0){
	        *(sum + count) = 0;
	    }
		*(sum + count) += *(a + i);
		if(i % M == M - 1){
			count++;
		}
	}
}

void findColSum(const double *a, double *sum, int N, int M){
	int n = N * M;

	for(int i = 0 ; i < M; i++){
		*(sum + i) = 0;
	}

	for(int i = 0; i < n; i++){
		*(sum + i % M) += *(a + i);
	}
}
