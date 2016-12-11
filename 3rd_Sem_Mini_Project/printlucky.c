        /*		        SAHIL RAJPUT
         * 	        	SECTION C
         *       		ROLL NO 53		*/


//User defined header file.
#include "header.h"

//Print Result of Lucky Number.
void printlucky(long int a[],long int n,long int count,long int max)
{
		long int sum=0,maxDiff=0,l,m,diff=0,i;
        //If Maximum number is 1 in a digit(i.e Other elements are ZERO).
        if(max == a[0] && a[0] == 1)
        {

            //Maximum diffrence is 1 if maximum number is 1 in a digit.
            maxDiff=1;
            
            for(l=0;l<count;l++)
            {
                sum+=a[l];      // or sum=sum+a[l];
            }
            
            //Pring maximum diffrence and sum.
            printf("%ld,%ld\n",maxDiff,sum);
        }
        
        //If number is lucky number(i.e It satify the definition of lucky number).
        else if(max == a[0])
        {
            
            //Find max diffrence.
            for(i=0;i<count;i++)
            {
                for(m=0;m<count;m++)
                {
                    //Take diffrence.
                    diff=a[i]-a[m];
                    //Find maximum diffrence.
                    if(maxDiff<=diff)
                        maxDiff=diff;
                }
            }
            
            //Find sum of digits
            for(l=0;l<count;l++)
            {
                sum+=a[l];   
            }
            
            //Print Maxmimum diffrence and Sum.
            printf("%ld,%ld\n",maxDiff,sum);
        }
       
        //If digit does not satisfy the lucky number definition.
        else if(max !=a[0])
            printf("NA\n");

}
