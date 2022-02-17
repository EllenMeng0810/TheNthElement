#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findNthNumber(vector<int> &arr1, vector<int> &arr2, int firstA, int lastA, int firstB, int lastB, int n);
//int findNthNumber(vector<int> &arr1, vector<int> &arr2, int first, int last, int n);

int main()
{
	vector<int> A;
	vector<int> B;
	int temp;
	int result;	
	char flag;
	int lenA;
	int lenB;

	cout << "Project2_Zhaoying Meng" << endl;
	cout << "Professor: Dr.Lin Chiu" << endl;
	cout << "COMP620-Q1FF" << endl;
	cout << "Apr 15, 2020" << endl;
	cout << endl;
	   
	do 
	{
		do
		{
			cout << "Please input the array A: ";
			do
			{
				cin >> temp;
				A.push_back(temp);
			} while (getchar() != '\n');

			cout << "Please input the array B: ";
			do
			{
				cin >> temp;
				B.push_back(temp);
			} while (getchar() != '\n');

			lenA = A.size();
			lenB = B.size();
			
			//cout << "The length of A: " << len1 << endl;
			//cout << "The length of B: " << len2 << endl;

			if (lenA != lenB)
			{
				cout << "A and B must in same size, please input again." << endl;
				cout << endl;
				A.clear();//清除容器中所有数据
				B.clear();
			}
			
			//cout << "Please input n: ";
			//cin >> n;

		} while (lenA != lenB);

		result = findNthNumber(A, B, 0, lenA - 1, 0, lenB - 1, lenA);
		//result = findNthNumber(A, B, 0, lenA - 1, lenA);
		cout << "The nth (" << lenA << "th) smallest integer is: " << result << endl;
		cout << endl;

		A.clear();//清除容器中所有数据
		B.clear();

		cout << "Would you like to continue?(Y = yes or N = no): ";
		cin >> flag;
		if (flag == 'N' || flag == 'n') 
		{
			cout << "Good Bye!!!" << endl;
		}

	} while (flag == 'Y' || flag == 'y');
	cout << endl;

	system("pause");
	return 0;
}


int findNthNumber(vector<int> &arr1, vector<int> &arr2, int firstA, int lastA, int firstB, int lastB, int n)
//int findNthNumber(vector<int> &arr1, vector<int> &arr2, int first, int last, int n)
{
	int numN;

	if (arr2[0] > arr1[n - 1])
	{
		numN = arr1[n - 1];
		return numN;
	}			
	else if (arr1[0] > arr2[n - 1])
	{
		numN = arr2[n - 1];
		return numN;
	}
	else 
	{
		int i = (firstA + lastA) / 2;//中间数:第(n+1)/2个数是arr1[(n-1)/2]的值		
		int j = (firstB + lastB - 1) / 2;//用-1控制一下奇数偶数的选数情况
		//int i = (first + last) / 2;//
		//int j = (n - 1) - (i + 1);//int j =(n-1)-(n+1)/2;

		if (arr1[i] < arr2[j])
		{
			if (arr1[i + 1] > arr2[j])
			{
				numN = arr2[j];
				return numN;
			}
			else if (arr1[i + 1] < arr2[j])
			{
				return findNthNumber(arr1, arr2, i + 1, lastA, firstB, j, n);
			    //return findNthNumber(arr1, arr2, i + 1, last, n);
			}				
		}
		else if(arr1[i] > arr2[j])
		{
			if (arr1[i] < arr2[j + 1])
			{
				numN = arr1[i];
				return numN;
			}
			else if (arr1[i] > arr2[j + 1])
			{
				return findNthNumber(arr1, arr2, firstA, i, j + 1, lastB, n);
			    //return findNthNumber(arr1, arr2, first, i - 1, n);
			}				
		}
	}
}
