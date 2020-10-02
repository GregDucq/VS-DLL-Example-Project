#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "SubtractionLibrary.h"

typedef float (*SubtractPtr) (float, float);
SubtractPtr subtractFunc = NULL;

int main()
{
	float x, y, answer = 0;
	printf("Enter two numbers: ");
	scanf_s("%f%f", &x, &y);

	HMODULE subtractionDLL = LoadLibrary(L"../Debug/SubtractionDLL.dll");
	
	if (subtractionDLL) {
		printf("Library Loaded\n");

		subtractFunc = (SubtractPtr) GetProcAddress(subtractionDLL, "subtract");
		answer = subtractFunc(x, y);
		FreeLibrary(subtractionDLL);

		printf("%f - %f = %f", x, y, answer);
	}

	else {
		printf("Error Loading Library");
	}

	return 0;
}	

/*
#include<stdio.h>
#include<stdlib.h>
#include "SubtractionLibrary.h"

int main()
{
	float x, y;
	printf("Enter two numbers: ");
	scanf_s("%f%f", &x, &y);

	float answer = subtract(x, y);

	printf("%f - %f = %f", x, y, answer);

	return 0;
}
*/