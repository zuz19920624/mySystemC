// sc_helloworld.cpp : 定义控制台应用程序的入口点。
//

#include "systemc.h"
#include "nand2.h"
#include "stim.h"
SC_MODULE(hello)
{
    sc_in<bool> clock;
    void run()
    {
        cout << "@"<<sc_simulation_time<<" hello world" <<endl;
    }

    SC_CTOR(hello)
    {
        SC_METHOD(run);
        sensitive<<clock.pos();
    }
};

int sc_main(int argc, char* argv[])
{
    sc_clock clk("clock",20,SC_NS);
	sc_signal<bool> a,b,f;
    hello h("hello");
	nand2 N2("Nand2"); N2.A(a); N2.B(b); N2.F(f);
	stim tb("tb");     tb.clk(clk); tb.A(a); tb.B(b); tb.f(f);
    h.clock(clk);
	sc_trace_file *tf = sc_create_vcd_trace_file("Nand2");
	sc_trace(tf,N2.A,"A");sc_trace(tf,N2.B,"B");sc_trace(tf,N2.F,"F");
    sc_start(200,SC_NS);
	sc_close_vcd_trace_file(tf);
    system("pause");
    return 0;
}