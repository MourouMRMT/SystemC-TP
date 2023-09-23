#include "altbit.h"

void AltBit::altbit()
{
	etat=E0;
	//Err.write(0);
	
	while(1)
	{
		wait(H.posedge_event());
		switch(etat)
		{
			case E0:
				
				if(E.read()==1)
				{
					etat=E2;
					Err.write(0);
				}else{
					etat=E1;
					Err.write(0);
				}
				break;
			case E1:
				if(E.read()==1)
				{
					etat=E2;
					Err.write(0);
				}else
				{
					Err.write(1);
				}
				break;

			case E2:
				if(E.read()==1)
				{
					Err.write(1);					
				}else
				{
					Err.write(0);
					etat=E0;
					
				}
				break;			
		}
	}
}
