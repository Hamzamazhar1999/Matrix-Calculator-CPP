#include<stdio.h>
#include<Windows.h>
void header();//function prototype for header
void fullscreen();//function prototype for fullscreen function
void scan_print(float arr[][100], int a, int b);//function prototype for scanning and printing matrices by user
void summation(float mat1[][100], float mat2[][100],float mat3[][100], int row, int col);//function prototype for summation of matrices
void subtraction(float mat1[][100], float mat2[][100], float mat3[][100], int row, int col);//function prototype for subtraction of matrices
void multiplication(float mat[][100], float mat1[][100], float res[][100], int a1, int a2, int b1, int b2);//function prototype for multiplication of matrices
void division(float mat[][100], float mat1[][100], float mat3[][100], int row, int col);//function prototype for division of matrices
void transpose(float mat[][100], float tmat[][100],int row,int col);//function prototype for transpose of matrix
void scalar_mul(float mat[][100], float mat3[][100], int row, int col, float n);//function prototype for scalar multiplication of matrices
void fileread(float fmat[][100], int a1, int b1);//function prototype to read matrices from "Text.txt" file
void filewrite(float wmat[][100],int a1,int b1);//function prototype to write answers of operations to matrices to external .txt file
void filewriteuser(float wumat[][100], int a1, int b1);//function prototype to enter user defined matrices to external Text.txt file
void start();
void red();void yellow();void green();void blue();void reset();//colour configuration functions
int main()//main
{
	fullscreen();//function call for fullscreen function
	start();//Function call for start(coverpage)
	system("cls");
	header();
	int a1, b1, a2, b2, choice;
	float num;
	float arr1[100][100], arr2[100][100];
	float mul[100][100] = { 0 }; float tmat[100][100] = { 0 }; float sum[100][100] = { 0 }; float wumat[100][100] = { 0 };
	float sub[100][100] = { 0 }; float div[100][100] = { 0 }; float smul[100][100] = { 0 }; float fmat[100][100] = { 0 }; float wmat[100][100] = { 0 };
	system("cls");
	header();
	int selection;
	printf("Enter the corresponding number for yor desired action:\n");
	green();//Text colour change
	printf("1)Addition\n2)Subtraction\n3)Multiplication\n4)Division\n5)Transpose\n6)Scalar Multiplication\n7)Read from file\n8)Write to file\n");
	reset();//Text colour reset
	printf("Enter any number or -1 to exit:");
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &selection);
	while (selection != EOF)//sentinel controlled loop by user
	{//while start
		switch (selection)
		{//switch start
		case 1://addition
			system("cls");
			header();
			printf("Enter rows and columns for 1:");
			scanf("%d %d", &a1, &b1);
			printf("Enter rows and columns for 2:");
			scanf("%d %d", &a2, &b2);
			while (!((a1 == a2) && (b1 == b2)))//checks whether given matrices are conformable for addition
			{
				system("cls");
				header();
				red();//Text colour change
				puts("Error 002:Both matrices should have the same dimensions.");
				reset();//Text colour reset
				printf("Enter rows and columns for 1:");
				scanf("%d %d", &a1, &b1);
				printf("Enter rows and columns for 2:");
				scanf("%d %d", &a2, &b2);
			}
			system("cls");
			header();
			yellow();
			printf("Matrix:\n");
			reset();
			scan_print(arr1, a1, b1);
			yellow();
			printf("Matrix:\n");
			reset();
			scan_print(arr2, a2, b2);
			summation(arr1, arr2, sum, a1, b1);//summation function
			printf("Do you want to write matrix elements to file?\nPress 1 to print or any other number to continue!\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				filewrite(sum, a1, b1);//writes answer matrix to external text file
				yellow();
				printf("Matrix elements have been loaded to text file.\n");
				reset();
			}
			printf("Press enter to continue!");
			getchar();
			getchar();
			system("cls");
			header();
			break;


		case 2://subtraction
			system("cls");
			header();
			printf("Enter rows and columns for 1:");
			scanf("%d %d", &a1, &b1);
			printf("Enter rows and columns for 2:");
			scanf("%d %d", &a2, &b2);
			while (!((a1 == a2) && (b1 == b2)))//checks whether given matrices are conformable for subtraction
			{
				system("cls");
				red();
				puts("Error 002:Both matrices should have the same dimensions.");
				reset();
				printf("Enter rows and columns for 1:");
				scanf("%d %d", &a1, &b1);
				printf("Enter rows and columns for 2:");
				scanf("%d %d", &a2, &b2);
			}
			system("cls");
			header();
			yellow();
			printf("Matrix:\n");
			reset();
			scan_print(arr1, a1, b1);
			yellow();
			printf("Matrix:\n");
			reset();
			scan_print(arr2, a2, b2);
			subtraction(arr1, arr2, sub, a1, b1);//call for subtraction function
			printf("Do you want to write matrix elements to file?\nPress 1 to print or any other number to continue!\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				filewrite(sub, a1, b1);//writes answer matrix to external text file
				yellow();
				printf("Matrix elements have been loaded to text file.\n");
				reset();
			}
			printf("Press enter to continue!");
			getchar();
			getchar();
			system("cls");
			header();
			break;
		case 3://multiplication

			system("cls");
			header();
			printf("Enter rows and columns for 1: ");
			scanf("%d %d", &a1, &b1);
			printf("Enter rows and column for 2: ");
			scanf("%d %d", &a2, &b2);
			while (b1 != a2)//checks whether the columns of first = rows of second
			{
				system("cls");
				red();
				puts("Error 003:Columns of first matrix not equal to the rows of second.");
				reset();
				printf("Enter rows and column for 1: ");
				scanf("%d %d", &a1, &b1);
				printf("Enter rows and column for 2: ");
				scanf("%d %d", &a2, &b2);
			}
			system("cls");
			header();
			yellow();
			printf("Matrix:\n");
			reset();
			scan_print(arr1, a1, b1);
			yellow();
			printf("Matrix:\n");
			reset();
			scan_print(arr2, a2, b2);
			multiplication(arr1, arr2, mul, a1, b1, a2, b2);//multiplication function call
			printf("Do you want to write matrix elements to file?\nPress 1 to print or any other number to continue!\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				filewrite(mul, a1, b2);//writes answer matrix to external text file
				yellow();
				printf("Matrix elements have been loaded to text file.\n");
				reset();
			}
			printf("Press enter to continue!");
			getchar();
			getchar();
			system("cls");
			header();
			break;
		case 4://division
			system("cls");
			header();
			printf("Enter rows and columns for 1:");
			scanf("%d %d", &a1, &b1);
			printf("Enter rows and columns for 2:");
			scanf("%d %d", &a2, &b2);
			while (!((a1 == a2) && (b1 == b2)))//checks whether given matrices are conformable for division
			{
				system("cls");
				header();
				red();
				puts("Error 002:Both matrices should have the same dimensions.\n");
				reset();
				printf("Enter rows and columns for 1:");
				scanf("%d %d", &a1, &b1);
				printf("Enter rows and columns for 2:");
				scanf("%d %d", &a2, &b2);
			}
			system("cls");
			header();
			yellow();
			printf("Matrix:\n");
			reset();
			scan_print(arr1, a1, b1);
			yellow();
			printf("Matrix:\n");
			reset();
			scan_print(arr2, a2, b2);
			division(arr1, arr2, div, a1, b1);//division function call
			printf("Do you want to write matrix elements to file?\nPress 1 to print or any other number to continue!\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				filewrite(div, a1, b1);//writes matrix to text file
				yellow();
				printf("Matrix elements have been loaded to text file.\n");
				reset();
			}
			printf("Press enter to continue!");
			getchar();
			getchar();
			system("cls");
			header();
			break;
		case 5://transpose
			system("cls");
			header();
			printf("Enter rows and columns:");
			scanf("%d %d", &a1, &b1);
			system("cls");
			header();
			yellow();
			printf("Matrix:\n");
			reset();
			scan_print(arr1, a1, b1);
			transpose(arr1, tmat, a1, b1);//transpose function call
			printf("Do you want to write matrix elements to file?\nPress 1 to print or any other number to continue!\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				filewrite(tmat, b1, a1);//writes to external file
				yellow();
				printf("Matrix elements have been loaded to text file.\n");
				reset();
			}
			printf("Press enter to continue!");
			getchar();
			getchar();
			system("cls");
			header();
			break;
		case 6://scalar multiplication
			system("cls");
			header();
			printf("Enter rows and columns:");
			scanf("%d %d", &a1, &b1);
			system("cls");
			header();
			yellow();
			printf("Matrix:\n");
			reset();
			scan_print(arr1, a1, b1);
			printf("Enter number to multiply:");
			scanf("%f", &num);//asks user to enter number to multiply(num is in integer form)
			scalar_mul(arr1, smul, a1, b1, num);//scalar multiply call
			printf("Do you want to write matrix elements to file?\nPress 1 to print or any other number to continue!\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				filewrite(smul, a1, b1);//writes matrix to external file
				yellow();
				printf("Matrix elements have been loaded to text file.\n");
				reset();
			}
			printf("Press enter to continue!");
			getchar();
			getchar();
			system("cls");
			header();
			break;
		case 7://reads matrix from external file(format for external file =>enter elements in one row )
			system("cls");
			header();
			printf("Enter rows and columns:");//asks for dimensions of matrix
			scanf("%d %d", &a1, &b1);
			fileread(fmat, a1, b1);//function call to fileread
			printf("Press enter to continue!");
			getchar();
			getchar();
			system("cls");
			header();
			break;
		case 8://write a user defined matrix to external file
			system("cls");
			header();
			printf("Enter rows and columns:");
			scanf("%d %d", &a1, &b1);//dimensions of matrix
			filewriteuser(wumat, a1, b1);//function call
			yellow();
			printf("Matrix elements have been loaded to text file.\n");
			reset();
			printf("Press enter to continue!");
			getchar();
			getchar();
			system("cls");
			header();
			break;
		default://default (if user enters anyother number then numbers b/w 1&8)
			system("cls");
			header();
			red();
			printf("%s", "Error 001:Not a valid option.\n");
			reset();
			break;
		}//switch end
		printf("Enter the corresponding number for yor desired action:\n");
		green();
		printf("1)Addition\n2)Subtraction\n3)Multiplication\n4)Division\n5)Transpose\n6)Scalar Multiplication\n7)Read from file\n8)Write to file\n");
		reset();
		printf("Enter any number or -1 to exit:");
		fseek(stdin, 0, SEEK_END);
		scanf("%d", &selection);
	}//while end
	yellow();
	printf("Good Bye!\n");
	reset();
	system("pause");
}
void header()
{
	blue();
	printf("\t\t\t\t\t\t\t\t     __________________________________________________________________________________________\n");
	printf("\t\t\t\t\t\t\t\t    |                                                        ____                              |         \n");
	printf("\t\t\t\t\t\t\t\t    |   |\\    /|  ______  _______  _____   _____            /      _____          _____        |                          \n");
	printf("\t\t\t\t\t\t\t\t    |   | \\  / | |      |    |    |     \\    |   \\  /      |      |     | |      /             |                        \n");
	printf("\t\t\t\t\t\t\t\t    |   |  \\/  | |______|    |    |_____/    |    \\/       |      |_____| |      |        __   |                        \n");
	printf("\t\t\t\t\t\t\t\t    |   |      | |      |    |    |    \\   __|__  /\\        \\____ |     | |_____ \\_____  |__|  |                                \n");
	printf("\t\t\t\t\t\t\t\t    |__________________________________________________________________________________________|\n");
	reset();
}
void fullscreen()
{
	//these are found in windows.h library
	//this function starts the console in fullscreen mode
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}
void start()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t         /|\\         ***         ***   * * * * **   ***************   *********     **********      *         *\n");
	printf("\t\t\t\t\t\t        / | \\        *  *       *  *   *        *          *          *         *       *            *       *                                                  \n");
	Sleep(300);
	printf("\t\t\t\t\t\t       /  |  \\       *   *     *   *   *        *          *          *          *      *             *     *                     _       _               \n");
	printf("\t\t\t\t\t\t      /   |   \\      *    *   *    *   *        *          *          *         *       *              *   *                     |         |       \n");
	Sleep(300);
	printf("\t\t\t\t\t\t     /    |    \\     *     * *     *   *        *          *          *********         *               * *                      | 45 56 67|                     \n");
	printf("\t\t\t\t\t\t    /     |     \\    *      *      *   ** ** ** *          *          * *               *                *                 A  =  | 4   5  6|                  \n");
	Sleep(300);
	printf("\t\t\t\t\t\t   /______|______\\   *             *   *        *          *          *   *             *               * *                      | 7   7  7|                  \n");
	printf("\t\t\t\t\t\t          |          *             *   *        *          *          *    *            *              *   *                     |_       _|                \n");
	Sleep(300);
	printf("\t\t\t\t\t\t                     *             *   *        *          *          *     *       ***********       *     *                                                   \n");
	puts("");
	printf("\t\t\t\t\t\t          |\\          ************       ****       *        *                 *  ************    *********					                         \n");
	Sleep(300);
	printf("\t\t\t\t\t\t          | \\         *                *      *     *         *               *   *               *         *                                        \n");
	printf("\t\t\t\t\t\t          |  \\        *               *        *    *          *             *    *               *          *            |\\________________/|           \n");
	Sleep(300);
	printf("\t\t\t\t\t\t          |   \\       *              *          *   *           *           *     *               *         *             | \\     ****     / |           \n");
	printf("\t\t\t\t\t\t     _____|    \\      *              *          *   *            *         *      ************    *********               |  \\   ******   /  |           \n");
	Sleep(300);
	printf("\t\t\t\t\t\t     \\    |_____\\     ************   *          *   *             *       *       *               * *                     |   \\ ******** /   |           \n");
	printf("\t\t\t\t\t\t      \\   |                      *   *          *   *              *     *        *               *   *                   |   /\\********/\\   |         \n");
	Sleep(300);
	printf("\t\t\t\t\t\t       \\  |                      *    *        *    *               *   *         *               *     *                 |  /  \\      /  \\  |          \n");
	printf("\t\t\t\t\t\t        \\ |                      *     *      *     *                * *          *               *       *               | /    \\    /    \\ |       \n");
	Sleep(300);
	printf("\t\t\t\t\t\t         \\|           ************       ****       *************     *           ************    *         *             |/      \\  /      \\|       \n");
	printf("\t\t\t\t\t\t                                                                                                                                   \\/                \n");
	Sleep(300);
	puts("\n\n\n");
	SetConsoleTextAttribute(h, wOldColorAttrs);
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t   Press Enter to continue!");
	getchar();
}
void scan_print(float arr[][100], int a, int b)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			printf("Enter element number [%d][%d]: ", i + 1, j + 1);
			scanf("%f", &arr[i][j]);//scanning elementys from user by keyboard
		}
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j <b; j++)
		{
			printf(" %6.2f ", arr[i][j]);//printing elements entered by user
		}
		puts("");
	}
}
void summation(float mat1[][100], float mat2[][100], float mat3[][100], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mat3[i][j] = mat1[i][j] + mat2[i][j];//adding elements of two matrices and storing them in the third matrix
		}
	}
	yellow();
	printf("Answer:\n");
	reset();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			blue();
			printf(" %6.2f ", mat3[i][j]);//printing the third matrix elements in formatted pattern
			reset();
		}
		puts("");
	}
}
void subtraction(float mat1[][100], float mat2[][100], float mat3[][100], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mat3[i][j] = mat1[i][j] - mat2[i][j];//adding elements of two matrices and storing them in the third matrix
		}
	}
	yellow();
	printf("Answer:\n");
	reset();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			blue();
			printf(" %6.2f ",mat3[i][j]);//printing the third matrix elements in formatted pattern
			reset();
		}
		puts("");
	}
}
void multiplication(float mat[][100], float mat1[][100], float res[][100], int a1, int a2, int b1, int b2)
{
		for (int i = 0; i < a1; i++)
		{
			for (int j = 0; j < b2; j++)
			{
				for (int k = 0; k < b1; k++)
				{
					res[i][j] += mat[i][k] * mat1[k][j];//multiplication of matrix elements and storage in res matrix
				}
			}
		}
		yellow();
		printf("Answer:\n");
		reset();
		for (int i = 0; i < a1; i++)
		{
			for (int j = 0; j < b2; j++)
			{
				blue();
				printf(" %6.2f ", res[i][j]);//printing res matrix in formatted pattern
				reset();
			}
			puts("");
		}
}
void division(float mat[][100], float mat1[][100], float mat3[][100], int row, int col)
{
	int con=0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (mat1[i][j] == 0)
			{
				red();//colour change
				printf("Error 004:Division by zero\n");//error
				reset();//colour reset
				con++;//increment of con so that division does not occur and only error is printed
				break;
			}
		}
	}
	if (con == 0)//only enters when con has not been incremented
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				mat3[i][j] =mat[i][j] / mat1[i][j];//dividing elements and storing in mat3
			}
		}
		yellow();
		printf("Answer:\n");
		reset();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				blue();
				printf(" %6.2f ", mat3[i][j]);//printing elements of division matrix in formatted pattern
				reset();
			}
			puts("");
		}
	}
}
void transpose(float mat[][100], float tmat[][100], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j <col; j++)
		{
			tmat[j][i] = mat[i][j];//storing elements in transpose matrix
		}
	}
	yellow();
	printf("Transpose:\n");
	reset();
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			blue();
			printf(" %6.2f ", tmat[i][j]);//printing stored elements in formatted pattern
			reset();
		}
		puts("");
	}
}
void scalar_mul(float mat[][100], float mat3[][100], int row, int col, float n)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mat3[i][j] = n*mat[i][j];//multiply every element by scalar number and stores them in mat3
		}
	}
	yellow();
	printf("Answer:\n");
	reset();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			blue();
			printf(" %6.2f ", mat3[i][j]);//printing elements of mat3 in formatted pattern
			reset();
		}
		puts("");
	}
}
void fileread(float fmat[][100],int a1,int b1)
{
	FILE *ptr;//assigns a pointer "ptr" of type FILE
	ptr = fopen("Text.txt", "r");//opens file,this function requires two parameters i.e file name/address and the type of access, in this case (r) stands for read access
	for (int i = 0; i < a1; i++)
	{
		for (int j = 0; j < b1; j++)
		{
			fscanf(ptr, "%f ", &fmat[i][j]);//scanning every element from txt file
		}
	}
	yellow();
	printf("Read matrix is:\n");
	reset();
	for (int i = 0; i < a1; i++)
	{
		for (int j = 0; j < b1; j++)
		{
			blue();
			printf(" %6.2f ", fmat[i][j]);//printing them in matrix form
			reset();
		}
		puts("");
	}
	fclose(ptr);//file is closed after process
}
void filewrite(float wmat[][100],int a1,int b1)
{
	/*The difference between filewrite and filewriteuser is that filewrite is printing answer matrices(sum,sub,mul e.t.c)
	while filewriteuser asks the user to enter the matrix on console and then prints the matrix to txt file.*/
	static int x = 1;//static integer x which specifies the matrix number
	FILE *ptr;//assigning ptr to FILE pointer
	ptr = fopen("Text.txt", "a+");//opens file,this function requires two parameters i.e file name/address and the type of access, in this case (a+) stands for appending access i.e data is not overwritten
	fprintf(ptr, "Matrix %d:\n",x);//prints matrix number
		for (int i = 0; i < a1; i++)
		{
			for (int j = 0; j < b1; j++)
			{
				fprintf(ptr, " %6.2f ", wmat[i][j]);//prints element on txt file
			}
			fprintf(ptr, "\n");//prints new line on txt file
		}
		fprintf(ptr, "\n");
		x++;//increment of x
		fclose(ptr);//file is closed after process

}
void filewriteuser(float wumat[][100], int a1, int b1)
{
	/*The difference between filewrite and filewriteuser is that filewrite is printing answer matrices(sum,sub,mul e.t.c)
	while filewriteuser asks the user to enter the matrix on console and then prints the matrix to txt file.*/
	static int x = 1;//static integer x which specifies the matrix number
	for (int i = 0; i < a1; i++)
	{
		for (int j = 0; j < b1; j++)
		{
			printf("Enter element number [%d][%d]: ", i + 1, j + 1);
			scanf("%f", &wumat[i][j]);//scanning elements to be printed to txt file by user
		}
	}
	FILE *ptr;//assingning pointer "ptr" of FILE type to txt file
	ptr = fopen("Text.txt", "a+");//opens file,this function requires two parameters i.e file name/address and the type of access, in this case (a+) stands for appending access i.e data is not overwritten
	fprintf(ptr, "Matrix %d:(From user)\n", x);
	for (int i = 0; i < a1; i++)
	{
		for (int j = 0; j < b1; j++)
		{
			fprintf(ptr, " %6.2f ", wumat[i][j]);//printing elements to txt file
		}
		fprintf(ptr, "\n");//new line after columns end
	}
	fprintf(ptr, "\n");//new line
	x++;//increment in static int x
	fclose(ptr);
}
void red()
{
	printf("\033[1;31m");//here \033 is escape sequence that tells the programm to change colour to COLOUR CODE [1;31m;this is for red
}
void yellow()
{
	printf("\033[1;33m");//here \033 is escape sequence that tells the programm to change colour to COLOUR CODE [1;33m;this is for yellow
}
void green()
{
	printf("\033[1;32m");//here \033 is escape sequence that tells the programm to change colour to COLOUR CODE [1;32m;this is for green
}
void blue()
{
	printf("\033[1;36m");//here \033 is escape sequence that tells the programm to change colour to COLOUR CODE [1;36m;this is for cyan
}
void reset()
{
	printf("\033[0m");//here \033 is escape sequence that tells the programm to change the colour back to original with code[0m
}
