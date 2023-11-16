#include "fir.h"

void __attribute__ ( ( section ( ".mprjram" ) ) ) initfir() {
	//initial your fir
	for(int i = 0 ; i < N ; i++){
		inputbuffer[i] = 0;
	}
}

int* __attribute__ ( ( section ( ".mprjram" ) ) ) fir(){
	initfir();
	//write down your fir
	for(int i = 0 ; i < N ; i++){
		
		for(int j = 0 ; j < N-1 ; j++)
			inputbuffer[j] = inputbuffer[j+1];
		inputbuffer[N-1] = inputsignal[i];
	
	
		int mult,acc=0;
		
		for(int i = 0 ; i < N ; i++){
			mult = taps[i] * inputbuffer[N-i-1];
			acc += mult;	
		}
	
		outputsignal[i] = acc;
	}
	return outputsignal;
}
		

		