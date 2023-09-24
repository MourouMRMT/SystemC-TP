#include "TX.h"

void TX_::transmit()
{
	switch(state)
	{
        case att:
            
            temp = din.read();
            if(temp == NULL){
                TxD.write(1);
            }
            else{
                state = envoie;
                TxD.write(0);
 
                parite = temp.xor_reduce();
                i = 0;
            }
            break;
        case envoie:
            if(i < 8)
			{
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