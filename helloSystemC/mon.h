#ifndef _MON_H
#define _MON_H
#include <systemc.h>
SC_MODULE(mon){
	sc_in<bool> A,B,F;
	sc_in_clk Clk;
	void monitor(){	//watch the inport and outport signal until simulatus stop	
		while(1){
			wait();
			cout<<sc_time_stamp()<<"\t"<<A.read()
		    	<<"	"<<B.read()<<"	"<<F.read()<<endl;
		}
	}
	SC_CTOR(mon){
		SC_THREAD(monitor);
		sensitive<<Clk.pos();
		cout<<"Time\tA	B	F"<<endl;
	}
};
#endif
