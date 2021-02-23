#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int checkInput(char ** a, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < strlen(a[i]); j++)
		{
			if((a[i][j] < 'a' ) || (a[i][j] > 'z' && a[i][j] < 'a') || (a[i][j] > 'z'))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}


void swap(char ** a, char ** b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// function to pass values by reference, comparing both strings and returning the difference when the first unmatch character appears
int lexicographic_sort(const char* a, const  char* b) 
{
    return strcmp(a, b);
}

/* the same as lexicographic_sort function, with the difference of comparing backwards "b against a".*/
int lexicographic_sort_reverse(const char* a, const char* b) 
{
    return strcmp(b, a);
}

int distinct_characters(const char* a)
{
    // store number of characters alphabetically
    int alphabet[25];

    // initicalize alphabet indexes to 0
    for(int i = 0; i <= sizeof(alphabet)/sizeof(int); i++)
    {
        alphabet[i] = 0;
    }

    // loop to add up number of characters alphabetically
    while(*a != '\0')
    {
        if((*a >= 'a') || (*a <= 'z') || (*a >= 'a') || (*a <= 'z'))
        {
            alphabet[*a - 'a'] += 1;
        }

        *(a++);
    }    

    int count = 0;
    // loop to count number of distinct characters in alphabet array
    for(int i = 0; i <= sizeof(alphabet)/sizeof(int); i++)
    {
        if(alphabet[i] > 0)
        {
            count++;
        }
    }

    return count;
}



int sort_by_number_of_distinct_characters(const char* a, const char* b) 
{

    int dista = distinct_characters(a);         
    int distb = distinct_characters(b);
	int result = (distinct_characters(a) - distinct_characters(b));
    
    // detemine sorting by distinct characters or lexicographiclly     
    if(result != 0)
    {
        return result;
    }
    else
    {
        return strcmp(a, b);
    }
        
}

int sort_by_length(const char* a, const char* b) 
{
    int lenghta = strlen(a);
    int lenghtb = strlen(b);
    int result = (lenghta - lenghtb);
    
    if(result != 0)
    {
        return result;
    }
    else
    {
        return lexicographic_sort(a, b); 
 	}        


}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{
	if(checkInput(arr, len))
	{
		exit(0);
	}
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0;j < len - i - 1; j++)
        {
            if(cmp_func(arr[j], arr[j+1]) > 0)
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }

}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
	
	printf("\n\n");

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
    
    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
	
}
