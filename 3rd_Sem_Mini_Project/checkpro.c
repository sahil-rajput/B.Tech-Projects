#include "header.h"

int checkpro(char te[])
{
	int incr=0;
	FILE *c1;
	char charac;
	c1=fopen(te,"r");
	while((charac=fgetc(c1))!=EOF)
	{
		if((charac>=33 && charac<=44) || (charac>=58 && charac<=126) || (charac>=46 && charac<=47))
		{
			incr++;
		}
	}
	if(incr>0)
		return 0;
	else 
		return 1;
}