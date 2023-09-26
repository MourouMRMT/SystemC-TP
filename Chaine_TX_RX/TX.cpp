#include "TX.h"

void TX::transmit()
{
	TxD.write(SC_LOGIC_1);
	while(1)
	{
		wait(clk.posedge_event());
		switch(state)
		{
			case att:
				
				temp = din.read();
				if(temp == NULL){
					TxD.write(SC_LOGIC_1);
				}
				else{
					state = envoie;
					TxD.write(SC_LOGIC_0);
	 
					parite = temp.xor_reduce();
					i = 0;
				}
				break;
			case envoie:
				if(i < 8)
				{
					i++;
					TxD.write(temp[7]);
					temp.range(7,1) = temp.range(6,0); //<<
					temp[0] = 0;	
				}
				else{
					state = att;
					TxD.write(parite);
				}
				break;
		}
	}
}