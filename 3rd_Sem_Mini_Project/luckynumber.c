        /*		SAHIL RAJPUT
         * 		SECTION C
         * 		ROLL NO 53		*/

//User Defined header file.
#include"header.h"
//Function of lucky number.
int luckynumber()
{
    long int i,j,k,test,n;
    
    //Read number of Test Cases.
    scanf("%ld",&test);
    while(test--)
    {
        //Read digit.
        scanf("%ld",&n);
        long int count=0,a[n],t,t2;
        t=n;
        t2=n;

        //Count Numbers in a digit.
        while(t2!=0)
        {
            t2/=10;     // or t2=t2/10;
            count++;
        }
        
        //Make an array of numbers of a digit.
        for(j=0;j<count;j++)
        {
            a[j]=t%10;
            t/=10;      // or t=t/10;
        }
        
        int max=0;
        
        //Find maximum number in a digit.
        for(k=0;k<count;k++)
        {
            if(max<a[k])
                max=a[k];
            
        }
        //Call function which print Lucky number.
        printlucky(a,n,count,max);

    }
    
    return 0;
}
