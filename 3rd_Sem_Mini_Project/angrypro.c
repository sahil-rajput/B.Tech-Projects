        /*		SAHIL RAJPUT
         * 		SECTION C
         * 		ROLL NO 53		*/

//User defined header file.
#include"header.h"

//Function Defination.
int angrypro()
{
    long int no_of_students,p;
    long int test_cases=0;
    long int j,i,count ;

    //Number of test cases run.
    scanf("%ld",&test_cases);
    //Run number of test cases.
    while(test_cases--)
    {
        //Initialize Count 0.
        count =0;   
        //Number of students
        scanf("%ld",&no_of_students);

        //Make Student Time of size no_of_students.
        long int student_time[no_of_students] ;

        //Number of students have to present.
        scanf("%ld",&p);

        //Run until no_of_students exceed.
        for(j=0;j<no_of_students;j++)
        {  
            //Students Time.
            scanf("%ld",&student_time[j]);

                 if(student_time[j]<=0)
                 //Count number of students present.
                 count++;
        }
       
        //Call print function.
         printangry(count,p);
    }
        return 0;
}
