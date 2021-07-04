#include<iostream>


int GetLength(char c[]) 
{
	int i;
	for (i = 0; c[i] != '\0'; i++ ) 
	{

	}

	return i;
}
void printVowelsConsonants(char c[])
{
	int i;
	
	int vcount = 0;
	int ccount = 0;
	for(i = 0; c[i] !='\0'; i++)
	{
		if(c[i] == 'a'||c[i] == 'e'||c[i]=='i'||c[i] =='o'||c[i]=='u'|| c[i] == 'A' || c[i] == 'E' || c[i] == 'I' || c[i] == 'O' || c[i] == 'U')
		{
			vcount++;
		}
		else if ((c[i] >= 65 && c[i] <= 90)||(c[i] >= 97 && c[i] <= 122)) 
		{
			ccount++;
		}
	}
	std::cout << "Numbers of Vowels: " << vcount << std::endl;
	std::cout << "Numbers of Consonants: " << ccount << std::endl;
}
void ChangeCase(char c[]) 
{
	int i;
	for (i = 0; c[i] != '\0'; i++) 
	{
		if (c[i] >= 65 && c[i] <= 90)
		{
			c[i] += 32;
		}
		else if (c[i] >= 97 && c[i] <= 122) 
		{
			c[i] -= 32;
		}
	}
}
int wordCount(char c[]) 
{
	int i;
	int word=0;
	for(i=0;c[i]!='\0';i++)
	{
		if (c[i] ==' ' && c[i-1]!=' ') 
		{
			word++;
		}
	}
	return word + 1;
}
bool isValid(char c[]) {
	int i;
	for (i = 0; c[i] != '\0'; i++) 
	{
		if(!(c[i] >= 65 && c[i] <= 90)&& !(c[i]>=97 && c[i]<=122) && !(c[i]>=48 && c[i]<=57))
		{
			return false;
		}
	}
	
	return true;
}
void Reverse(char c[])
{
	char t;
	int i, j;
	for (j = 0; c[j] != '\0'; j++) 
	{
	}
	j = j - 1;
	for (i = 0; i < j; i++, j--) 
	{
		t = c[i];
		c[i] = c[j];
		c[j] = t;
	}
}
bool Compare(char c[], char v[]) {
	int i, j;
	for (i = 0, j = 0; c[i] != '\0' && v[j] != '\0'; i++,j++) 
	{
		if (c[i] != v[j])
			break;
	}
	if (c[i]==v[j]) {
		std::cout << "Equal" << std::endl;
		return true;
	}
	else if(c[i] > v[j]) {
		std::cout << "Greater" << std::endl;
		return false;
	}
	else {
		std::cout << "Smaller" << std::endl;
		return false;
	}
}
void isPalindrome(char c[]) 
{
	char* temp = c;
	Reverse(c);

	if (Compare(c,temp)) {
		
		std::cout << "This word is Palindrome!";
		
	}
}

void FindDuplicate(char c[])
{
	int H = 0;
	int x = 0;
	for (int i = 0; c[i] != '\0'; i++) 
	{
		x = 1;
		x = x << (c[i] - 97);
		if ((x & H) > 0) 
		{
			std::cout << c[i] << " is duplicate" << std::endl;	
		}
		else 
		{
			H = x | H;
		}
	}
}
void Perm(char c[], int k) 
{
	
	static int A[10] = {0};
	static char Res[10];
	int i;
	
	if (c[k] == '\0') 
	{ 
		Res[k] = '\0';
		std::cout << Res << std::endl;
	}
	else 
	{
		for (i = 0; c[i] != '\0'; i++) 
		{
			if (A[i]==0) 
			{
				Res[k] = c[i];
				A[i] = 1;
				Perm(c, k+1);
				A[i] = 0;
			}
			
		}
	}
}

int main()
{
	char cCase[] = "ABCD";
	Perm(cCase, 0);

return 0;
}
