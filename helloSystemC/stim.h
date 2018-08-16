
#ifndef _STIM_H
#define _STIM_H
 
#include <systemc.h>
 
SC_MODULE(stim){
	sc_out<bool> A,B;				//declare outport signal
	sc_in<bool> f;
	sc_in_clk clk;				//declare clock
 
	void gen_stim(){				//function to generate the test bench
		A.write(0);
		B.write(0);
		wait();
		A.write(1);
		B.write(1);
		wait();
		A.write(0);
		B.write(0);
		wait();
		A.write(1);
		B.write(1);
		wait();
		sc_stop();
	}

	void display_variable();

	SC_CTOR(stim){
		SC_CTHREAD( gen_stim,clk.pos() );
		SC_METHOD( display_variable );
		sensitive<<f<<A<<B;
		dont_initialize();
	}
};

#endif