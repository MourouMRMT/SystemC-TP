#include "altbit.h"

void AltBit::altbit()
{
	state=E0;
	Err.write(0);
	while(1)
	{
		wait(H.posedge_event());
		switch(etat)
		{
			case E0:
				if(E.read()=1)
				{
					etat=E1;
				}else
				{
					s.write(0);	
					etat=E0;
				}
				break;
			case E1:
				if(E.read()=1)
				{
					s.write(1);
					etat=E2;
					
				}else
				{
					s.write(0);	
					etat=E0;
				}
				break;

			case E2:
				if(E.read()=1)
				{
					s.write(1);					
				}else
				{
					s.write(0);	
					etat=E0;
				}
				break;			
		}
	}
}
