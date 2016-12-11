#include "header.h"

int checklucky(char t[])
{
	int increment=0;
	FILE *c;
	char character;
	c=fopen(t,"r");
	while((character=fgetc(c))!=EOF)
	{
		if((character>=34 && character<=44) || (character>=58 && character<=126) || (character>=46 && character<=47))
		{
			increment++;
		}
	}
	if(increment>0)
		return 0;
	else 
		return 1;
}