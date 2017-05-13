//Include All Header files
#include "header.h"
//Declare matrix as global
int matrix[ROWS][COL];

//Function for input file
void inputFile (char *fileName, ifstream &inFile)
{
    inFile.open (fileName, ifstream::in);
    if (!inFile)
    {
        cerr << "Error: File could not be opened." << endl;
        exit (1);
    }

}
//Function of output file
void outputFile (char *fileName, ofstream &inFile)
{
    inFile.open (fileName, ofstream::app);
    if (!inFile)
    {
        cerr << "Error: File could not be opened." << endl;
        exit (1);
    }
}
//Check if matrix is valid or not.
int valid (int row, int col, int val)
{
	for (int n = 0; n < ROWS; n++)
     {
		if (matrix[n][col] == val || matrix[row][n] == val)
			return 0;
	}

	int sRow = (row / BoxWidth) * BoxWidth;
	int sCol = (col / BoxWidth) * BoxWidth;

	for (int r = sRow; r < sRow + BoxWidth; r++)
     {
		for (int c = sCol; c < sCol + BoxWidth; c++)
        {
			if (matrix[r][c] == val)
				return 0;
		}
	}

	return 1;
}
//Function that solve sudoku using recursion
int solve (int row, int col)
{
    //When row is on last grid then return 1
	if (row == ROWS)
		return 1;
    //If the grid of matrix is not equal to 0
	if (matrix[row][col] != 0)
    {
        //If col is 8 the return matrix with next line
		if (col == 8)
			return solve(row + 1, 0);
        //else, return with next column
		return solve(row, col + 1);
	}

	for (int val = 1; val <= VAL; val++)
    {
        //Go to function valid with values col , rows, and val
		if (valid(row, col, val))
         {
             //if valid function return true the initialise val to matrix
			matrix[row][col] = val;
            //Again if col is 8 the goto next row
			if (col == 8)
            {
				if (solve(row + 1, 0))
					return 1;
			}
            //else go to next col
			else
            {
				if (solve(row, col + 1))
					return 1;
			}
		}
	}
	matrix[row][col] = 0;

	return 0;
}
//Driver Code
int main (int argc, char * argv[])
{
    //Object of File handling
    ifstream inFile;
    ofstream outFile,outFile1;
    //Showing Usage
    if (argc <= 2 || argc > 3)
    {
        cerr << "Error : Usage : " << argv[0] << " <InputFilename> <OutputFilename>" << endl;
        return 0;
    }
    cout << "\n\t\t---------- WELCOME TO SUDOKU ----------\n" ;
    cout<< "\tPlayer ID : 01" <<endl;
    cout<< "\tSudoku To Be Solved : <"<< argv[1] <<"> "<<endl;
    //Open file
    inputFile(argv[1], inFile);
    //Input matrix
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			inFile>>matrix[row][col];
		}
	}
    //closing file
     inFile.close();
     outputFile (argv[2],outFile1);
     outFile1 <<"Input File is <"<< argv[1]<<">"<< endl;
     outFile1 <<"\nSudoku to be Solved is:"<<endl<<endl;
     for (int row = 0; row < ROWS; row++)
     {
         for (int col = 0; col < COL; col++)
         {
             outFile1 << " " << matrix[row][col] << " ";
             if (!((col+1) % 3) && col != 8)
                 outFile1 << " | ";
         }
         if (!((row+1) % 3) && row != 8)
             outFile1<<endl<< endl;
         else
             outFile1 << endl;
     }
     outFile1.close();
     //open output file
	outputFile (argv[2], outFile);
    //calling solve function with 0, 0 values
    if (solve(0, 0))
    {
        //Print on Output File
        //outFile <<"Input From File <"<< argv[1]<<">"<< endl;
        outFile <<"\nSolved Sudoku is :"<<endl<<endl;
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COL; col++)
            {
                outFile << " " << matrix[row][col] << " ";
                if (!((col+1) % 3) && col != 8)
                    outFile << " | ";
            }
            if (!((row+1) % 3) && row != 8)
                outFile<<endl<< endl;
            else
                outFile << endl;
        }

    }
	else
		outFile<<"\nINVALID SUDOKU : CAN'T BE SOLVED"<<endl;
    cout <<endl << "\t\tCheck <"<<argv[2]<<"> File for Output"<<endl <<endl;
    //Close output file
	outFile.close();

	return 0;
}
