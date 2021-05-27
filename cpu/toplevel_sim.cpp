#include <stdio.h>
#include <verilated.h>
#include "Vtoplevel_sim.h"

vluint64_t vtime = 0;
bool clk = false;

int main(int argc, char** argv, char** env)
{
	Verilated::commandArgs(argc, argv);
	Vtoplevel_sim* top = new Vtoplevel_sim;

	while (!Verilated::gotFinish())
	{
		clk = not clk;
		top->clk = int(clk);
		top->eval();
		printf("0x%X\n", top->led);
		vtime++;
	}

        delete top;
        exit(0);
}
