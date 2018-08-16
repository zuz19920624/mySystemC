
#ifndef _NAND2_H
#define _NAND2_H
 
#include <systemc.h>
 
SC_MODULE (nand2){			//declare nand2 module
       sc_in<bool> A,B;          		//input signal ports
       sc_out<bool> F;			//output port
       void do_nand(){			//simulate logic function of the nand
              //F.write(!( A.read() && B.read()));
		   if(A.read() != B.read() )
			   F.write(1);

       };
       SC_CTOR(nand2){			//constructor for nand2
              SC_METHOD (do_nand);		//register do_nand with kernel
              sensitive<<A<<B;		//sensitivity list
       }
};
#endif