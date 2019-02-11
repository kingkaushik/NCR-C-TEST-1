#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void file_matching_word_rotator(char *);
void file_matching_word_rotator(char *str)
{
	FILE *fptr = NULL, *fptr2 = NULL;
	fopen_s(&fptr, "rotate_read.txt", "r");
	fopen_s(&fptr2, "rotate_write.txt", "w");
	if (fptr != NULL)
	{
		int str_len = strlen(str);
		char *file_content = (char *)calloc(str_len + 1, sizeof(char));
		int count = 0, i = 0, k = 0,flag=0;
	
		while (!feof(fptr))
		{
			char ch = fgetc(fptr);
			if (ch == ' ' || ch== '\t' || ch=='\n')
			{
				flag = 0;
				*(file_content + i) = '\0';
				int content_length = (strlen(file_content) + 2);
				if (strcmp(file_content, str) == 0)
				{
					_strrev(file_content);					
					realloc(file_content, content_length * sizeof(char));
					*(file_content + i) = ch;
					*(file_content + i + 1) = '\0';
					fputs(file_content, fptr2);
					i = 0;
				}
				else
				{
					realloc(file_content, content_length * sizeof(char));
					*(file_content + i) = ch;
					*(file_content + i + 1) = '\0';					
					fputs(file_content, fptr2);
					i = 0;
				}
				file_content = (char *)calloc(str_len + 1, sizeof(char));
			}
			else
			{
				if (i < str_len)
				{
					*(file_content + i) = ch;
				}
				else
				{
					realloc(file_content, (i + 1) * sizeof(char));
					*(file_content + i) = ch;					
				}
				i++;
			}
		}
		*(file_content + i) = '\0';		
		if (strcmp(file_content, str) == 0)
		{
			_strrev(file_content);
			realloc(file_content, (i + 1) * sizeof(char));
			for (int m = 0; *(file_content + m); m++)
			{
				fputc(*(file_content + m), fptr2);
			}
		}
		else
		{
			realloc(file_content, (i + 1) * sizeof(char));
			for (int m = 0; *(file_content + m +1); m++)
			{
				fputc(*(file_content+m),fptr2);
			}
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