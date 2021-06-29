
#include <iostream>

using namespace std;
template<class T>
class Array {
private:
	T* A;
	int size;
	int length;
	void swap(T* x, T* y);
public:
	Array() 
	{
		size = 10;
		length = 0;
		A = new T[size];
	}
	Array(int sz) 
	{
		size = sz;
		length = 0;
		A = new T[size];
	}

	~Array() 
	{
		delete[] A;
	}
	void Display();

	bool isPresent(T x);

	void Append(T x);

	void Insert(int index, T x);

	T Delete(int index);

	

	T LinearSearch(T key);
	T BinarySearch(T key);

	T RBinarySearch(T low, T high, T key);

	T Get(int index);
	T GetLength();
	T GetSize();

	void Set(int index, T x);

	T Max();
							  
	T Min();

	T Sum();

	T RSum(int n);

	T Average();
	void Reverse();
	void Reverse2();
	void LeftShift();
	void LeftRotate();
	void SortInsert(int x);

	bool IsSorted(int n);

	void ShiftNegatives();

	Array* Merge(Array arr2);
	// Following functions are implemented only for sorted arrays using Merge Function above 
	Array* Union(Array* arr2);
	Array* Intersection(Array* arr2);
	Array* Difference(Array* arr2);
	//set operations on unsorted array
	Array* UnionUn(Array* arr2);

	Array* IntersectionUn(Array* arr2);
	Array* DifferenceUn(Array* arr2);
};
template<class T>
void Array<T>:: Display() {

	int i;
	cout << "\nElements are given\n\n";
	for (i = 0; i < length; i++) {
		cout << A[i] <<" ";
	}
 }
template<class T>
bool Array<T>:: isPresent(T x)
{
	int i;
	int count = 0;

	for (i = 0; i < length; i++) 
	{
		if (A[i] == x) 
		{
			count++;
		}
	}
	if (count > 0)
	{
		return true;
	}
	else if (count == 0)
	{ 
		return false; 
	}
}
template<class T>
void Array<T>:: Append(T x) 
{
	if (length < size)
		A[length++] = x;
}
template<class T>
void Array<T>:: Insert(int index, T x)
{
	if (index >= 0 && index <= length)
	{
		int i;
		for (i = length; i > index; i--) 
		{
			A[i] = A[i - 1];
		}
		A[index] = x;
		length++;
	}
}
template<class T>
T Array<T>::Delete(int index)
{
	T x = 0;
	if (index >= 0 && index <= length) 
	{
		x = A[index];
		for (int i = index; i < length - 1; i++) 
		{
			A[i] = A[i + 1];
		}
		length--;
		return x;
	}

	
}
template<class T>
void Array<T>::swap(T* x, T* y) {
	int key = *x;
	*x = *y;
	*y = key;
}
template<class T>
T Array<T>::LinearSearch(T key) {
	for (int i = 0; i < length; i++) 
	{
		if (key == A[i])
		{
			swap(&A[i], &A[0]);
			return i;
		}
	}
	return -1;
}
template<class T>
T Array<T>::BinarySearch(T key)
{
	int mid;
	int low = 0;
	int high = length;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == A[mid]) { return mid; }
		else if (key < A[mid]) { high = mid - 1; }
		else { low = mid + 1; }
	} return -1;
}
template<class T>
T Array<T>::RBinarySearch(T low, T high, T key) {
	int mid;
	
	if(low <= high)
	{
		mid = (low+high)/2;

		if (key == A[mid]) { return mid; }
		
		else if (key < A[mid]) 
		{	
			return RBinarySearch(low, (mid-1), key); 
		}

		else 
		{ 
			return RBinarySearch(mid+1, high, key); 
		}
	}
	return -1;
}
template<class T>
T Array<T>::Get(int index)
{
	if (index >= 0 && index < length)
		return A[index];
}
template<class T>
T Array<T>::GetLength() {
	return length;
}
template<class T>
T Array<T>::GetSize() {
	return size;
}
template<class T>
void Array<T>:: Set(int index, T x) 
{
	if (index >= 0 && index < length)
		A[index] = x;
}
template<class T>
T Array<T>::Max()
{
	int max = A[0];
	for (int i = 1; i < length; i++) 
	{
		if (A[i] > max)
		{
			max = A[i];
		}
	}
	return max;
}
template<class T>
T Array<T>::Min()
{
	int min = A[0];
	for (int i = 1; i < length; i++)
	{
		if (A[i] < min)
		{
			min = A[i];
		}
	}
	return min;
}
template<class T>
T Array<T>::Sum()
{
	int total = 0;
	for (int i = 0; i < length; i++) 
	{
		total = total + A[i];
	}
	return total;
}
template<class T>
T Array<T>::RSum(int n) 
{
	
	if (n < 0)
	{
		return 0;
	}
	else 
	{ 
		return RSum((n - 1)) + A[n]; 
	}
}
template<class T>
T Array<T>::Average ()
{
	return (float)Sum()/(length);
}
template<class T>
void Array<T>::Reverse() 
{
	int *B;
	int i, j;
	B = new int [length];
	for(i = length-1, j = 0; i >=0; i--,j++)
	{
		B[j] = A[i];
	}
	for (int i = 0; i < length; i++) 
	{
		A[i] = B[i];
	}
	delete[] B;
}
template<class T>
void Array<T>::Reverse2()
{
	int i, j;
	for (i = 0, j = length-1; i<j; i++,j--) 
	{
		swap(&A[i], &A[j]);
	}
}
template<class T>
void Array<T>::LeftShift() 
{
	for (int i = 0; i < length - 1; i++) {
		A[i] = A[i + 1];
	}
	A[length - 1] = 0;
}
template<class T>
void Array<T>::LeftRotate()
{
	int firstElem = A[0];
	for (int i = 0; i < length - 1; i++) {
		A[i] = A[i + 1];
	}
	A[length - 1] = firstElem;
}
template<class T>
void Array<T>::SortInsert(int x) 
{
	int i = length - 1;
	while (A[i] > x) 
	{
		A[i + 1] = A[i];
		i--;
	}
	A[i + 1] = x;
}
template<class T>
bool Array<T>::IsSorted(int n)
{
	for (int i = 0; i < n - 1; i++) 
	{ 
		if (A[i] > A[i + 1]) 
		{
			return false; 
		}
	}
	return true;
}
template<class T>
void Array<T>::ShiftNegatives() 
{
	int i = 0;
	int j = length - 1;
	while (i < j) 
	{
		while (A[i] < 0) { i++; }
		while (A[j] >= 0) { j--; }
		if(i<j)
		{swap(&A[i], &A[j]);}
	}
}
template<class T>
Array<T>* Array<T>::Merge(Array arr2) 
{
	int i, j, k;
	i = j = k = 0;

	Array* arr3 = new Array(length + arr2.length);
	while (i < length && j < arr2.length) 
	{
		if (A[i] < arr2.A[j]) 
		{
			arr3->A[k++] = A[i++];
		}
		else 
		{
			arr3->A[k++] = arr2.A[j++];
		}
	}

	for (; i < length; i++) 
	{
		arr3->A[k++] = A[i];
	}
	for (; j < arr2.length; j++) 
	{
		arr3->A[k++] = arr2.A[j];
	}
	arr3->length = length + arr2.length;
	arr3->size = 10;
	return arr3;
	
}
template<class T>
// Following functions are implemented only for sorted arrays using Merge Function above 
Array<T>* Array<T>::Union(Array* arr2)
{
	int i, j, k;
	i = j = k = 0;

	 Array* arr3 = new Array(length + arr2->length);
	while (i < length && j < arr2->length)
	{
		if (A[i] < arr2->A[j])
		{
			arr3->A[k++] = A[i++];
		}
		else if(arr2->A[j] < A[i])
		{
			arr3->A[k++] = arr2->A[j++];
		} 
		else 
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}

	for (; i < length; i++)
	{
		arr3->A[k++] = A[i];
	}
	for (; j < arr2->length; j++)
	{
		arr3->A[k++] = arr2->A[j];
	}
	arr3->length = k;
	
	return arr3;

} 
template<class T>
Array<T>* Array<T>::Intersection(Array* arr2)
{
	int i, j, k;
	i = j = k = 0;

	 Array* arr3 = new Array(length + arr2->length);
	while (i < length && j < arr2->length)
	{
		if (A[i] < arr2->A[j])
		{
			i++;
		}
		else if (arr2->A[j] < A[i])
		{
			j++;
		}
		else if(A[i] == arr2->A[j])
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}

	
	arr3->length = k;

	return arr3;

}
template<class T>
Array<T>* Array<T>::Difference(Array* arr2)
{
	int i, j, k;
	i = j = k = 0;

	 Array* arr3 = new Array(length + arr2->length);
	while (i < length && j < arr2->length)
	{
		if (A[i] < arr2->A[j])
		{
			arr3->A[k++] = A[i++];
		}
		else if (arr2->A[j] < A[i])
		{
			j++;
		}
		else
		{
			i++;
			j++;
		}
	}

	for (; i < length; i++)
	{
		arr3->A[k++] = A[i];
	}
	
	arr3->length = k;
	
	return arr3;

}
//set operations on unsorted array
template<class T>
Array<T>* Array<T>::UnionUn(Array* arr2) 
{
	 Array* arr3 = new Array(length + arr2->length);
	arr3->length = 0;
	for (int i = 0; i < length; i++) 
	{
		arr3->A[i] = A[i];
		arr3->length++;
	}
	
	for (int j = 0; j < arr2->length; j++)
	{
		bool c = arr3->isPresent(arr2->A[j]);
		if (!c)
		{
			Append(arr2->A[j]);
		}
	}
	
	return arr3;
}
template<class T>
Array<T>* Array<T>::IntersectionUn(Array* arr2)
{
	 Array* arr3 = new Array(length + arr2->length);
	arr3->length = 0;

	for (int j = 0; j < length; j++)
	{
		bool c = arr2->isPresent(A[j]);
		if (c)
		{
			arr3->Append(A[j]);
		}
	}

	return arr3;
}
template<class T>
Array<T>* Array<T>::DifferenceUn(Array* arr2)
{
	 Array* arr3 = new Array(length + arr2->length);
	arr3->length = 0;
	
	for (int j = 0; j < length; j++)
	{
		bool c = arr2->isPresent(A[j]);
		if (!c)
		{
			arr3->Append(A[j]);
		}
	}

	return arr3;
}

int main()

{
	Array<int> A;
	A.Append(5);
	A.Append(1);
	A.Append(7);
	A.Append(9);
	A.Append(8);

	cout << A.GetSize() << endl;
	
	return 0;
   

}
