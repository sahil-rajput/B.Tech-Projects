
        /*		SAHIL RAJPUT
         * 		SECTION C
         * 		ROLL NO 53		*/

//User defined header file.
#include"header.h"

//Main function.
int main(int argc, char *argv[])
{
    //Integers Variables.
    int c,size;
    //File pointers.
    FILE *f1,*f2;
    printf("\n\t\t****THIS IS THIRD SEMESTER MINI PROJECT****\n");
    do
    {

    	//Print Choices.
        printf("\nWhich One You Want To Run :\n\tEnter Your Choices:\n\t\t1.Angry Professor\n\t\t2.Lucky Number\n");
        printf("\n**INPUT**\t:");

        //Take Input choice from user.
        scanf("%d",&c);
        if(c==1 || c==2)
        {
            //Choice is equal to 1.
            if(c==1)
            {
        	   //Open File.
                f1=freopen(argv[1],"r",stdin);
                    //Calculate Size of FILE.
                    fseek (f1, 0, SEEK_END);
                     size = ftell(f1);
                    //Call check function to check inputs in file.
                    if(checkpro(argv[1])==1)
                    {
                        //If File is Empty.
                        if (0 == size)
                        {
                            printf("ERROR: File is Empty.Please try again with some Elements.\n");
                            break;
                        }
                                            }
                    //If File is not empty.
                    else if(checkpro(argv[1])==0)
                    {
                        printf("\nERROR: Input is not an Integer.Please try again with desired inputs.\n");
                        break;
                    }
                    //Close FILE.
                    fclose(f1);
                
                    //Open File.
                    f1=freopen(argv[1],"r",stdin);
                    //Call angrypro().
                    angrypro();
                    //Close File.
                    fclose(f1);
                    break;
                
            }

            //Choice is equal to 2.
            else if(c==2)
            {
                 //Open File
                f2=freopen(argv[1],"r",stdin);
                    //Calculate the size of the file.
                    fseek (f2, 0, SEEK_END);
                    size = ftell(f2);
                    if(checklucky(argv[1])==1)
                    {
                        //If file is empty.
                        if(0 == size)
                        {
                                printf("ERROR: File is Empty.Please try again with some elements\n");
                                break;
                        }
                    }
                    else
                    {
                        printf("\nERROR: Input is not an Integer.Please try again with desired inputs.\n");
                        break;
                    }
                //Close File.
                fclose(f2);
                //Open File.
                f2=freopen(argv[1],"r",stdin);
                //Class luckynumber().
                luckynumber();
                //Close File
                fclose(f2);
                break;
            }
        }
        else
        {
            printf("\nERROR: Wrong Choice.\n");
        }
    }while(c!=3);
    
    return 0;
}
