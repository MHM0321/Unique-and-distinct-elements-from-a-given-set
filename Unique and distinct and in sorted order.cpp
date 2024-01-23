#include<iostream>
using namespace std;
int take(int a[], int n);
void distinct(int a[], int n);
void unique(int a[], int n);
void increaseSort(int a[], int n);
void decreaseSort(int a[], int n);
int main()
{
	int displayable = 0;	//It is used to only show the values of array that have been assigned an input, saving our output from
							//garbage values of the unassigned values of the array
	int array[20] = {};
	displayable = take(array, 20);
	if (displayable > 0)
	{
		distinct(array, displayable);
		cout << endl;
		unique(array, displayable);
		cout << endl;
	}

	return 0;
	system("pause");
}
int take(int a[], int n)
{	//we use show variable as the indexes that we wanna show in the ouptup,
	//as when -99 is entered, the laterer indexes will not get assigned, thus
	//they will give garbage values. To prevent this, we only display the index
	// values of array that have been assigned
	cout << "Enter integers, and use -99 to exit : " << endl;
	int show = 0, temp = 0;
	bool exit_loop = false;
	for (int i = 0; ((i < n) && (exit_loop == false)); i++)
	{
		cin >> temp;
		if (temp == -99)
		{
			exit_loop = true;
		}         //this will allow us to exit the loop
		a[show] = temp;
		show++;
	}
	show--;     //it is done as the exit_loop does not immediately let us exit
	//the loop (unlike break) and completes one run, thus we reduce
	//one index that can be displayed, as it contains the -99
	return show;
}

void distinct(int a[], int n)
{
	int newsize = 0, array2[100] = {};		//initially, we will make array2 the same size as input array, and we will
											//take a counter i.e newsize for setting its new size. New size is just set to 
											//avoid the garbage values

	bool distinct = true, keeprun = true; //keeprun is used as a break, while distinct is used for our condition
	for (int i = 0; i < n; i++)
	{
		distinct = true;
		for (int j = i + 1; j < n; j++)
		{
			if (keeprun = true)
			{
				if (a[i] == a[j])			//if any equal is found, its distinctness
				{							//does not hold due to repetiton
											//thus we leave the inner loop
					distinct = false;
					keeprun = false;
				}
			}
		}
		if (distinct == true)
		{
			array2[newsize] = a[i];	//Here we simply put the distinct values in the array2
			newsize++;	//this is done to keep the size for only distinct values basically to avoid garbage values
		}
	}
	increaseSort(array2, newsize);
}

void increaseSort(int a[], int n)
{										//compared to initially next value and 
	int temp = 0;						//then to laterer index values, when the 
	for (int i = 0; i < n; i++)			//fixed one is compared to the complete 
	{									//array,its index value +1, and then it
		for (int j = i + 1; j < n; j++)	//is compared with index values after it.
		{								//if condition is fulfilled, it is 
			if (a[i] > a[j])			//swapped, and thus the greatest
			{							//value of array reaches rightmost one by
				temp = a[i];			//one.
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout << "Distinct Element in Sorted (Increasing order) are:";
	for (int k = 0; k < n; k++)
	{
		cout << a[k] << " ";
	}
}

void unique(int a[], int n)
{
	int newsize = 0, array3[100] = {};		//initially, we will make array2 the same size as input array, and we will
											//take a counter i.e newsize for setting its new size. New size is just set to 
											//avoid the garbage values (like array2)
	bool unique = true, keeprun = true;	//also same as array2, keeprun will be used as break, and unique for conditions
	for (int i = 0; i < n; i++)
	{
		unique = true;
		for (int j = 0; j < n; j++)
		{
			if (keeprun = true)
			{
				if (i != j && a[i] == a[j])	// i not equal to j is done to make 100% sure that it is not comparing
											//with itself, and it is made sure that that it is compared with all array values
				{							
					unique = false;
					keeprun = false;
				}
			}
		}

		if (unique == true)
		{
			array3[newsize] = a[i];	//the achieved values will be stored in the array3
			newsize++; //used to avoid garbage values
		}
	}
	decreaseSort(array3, newsize);
}


void decreaseSort(int a[], int n)
{										//compared to initially next value and 
	int temp = 0;						//then to laterer index values, when the 
	for (int i = 0; i < n; i++)			//fixed one is compared to the complete 
	{									//array,its index value +1, and then it
		for (int j = i + 1; j < n; j++)	//is compared with index values after it.
		{								//if condition is fulfilled, it is 
			if (a[i] < a[j])			//swapped, and thus the smallest
			{							//value of array reaches rightmost one by
				temp = a[i];			//one.
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	cout << "Unique Element in Sorted(Decreasing order ) are:";
	for (int k = 0; k < n; k++)
	{
		cout << a[k] << " ";
	}
}