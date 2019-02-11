#include<stdio.h>
#include<conio.h>
void replace_tabs();
void replace_tabs()
{
	FILE *fptr = NULL, *fptr2 = NULL;
	fopen_s(&fptr, "tabs_read.txt", "r");
	fopen_s(&fptr2, "tabs_write.txt", "w");
	if (fptr != NULL)
	{
		while (!feof(fptr))
		{
			char ch = fgetc(fptr);
			if ( ch == '\t')
			{
				
				fputs("\\t", fptr2);
			}
			if(ch!='ÿ')
				fputc(ch,fptr2);
		}
		printf("\nSUCCESSFULLY WRITTEN TO FILE");
		fclose(fptr);
		fclose(fptr2);
	}
	else
	{
		printf("\nERROR OCCURED!");
	}
}