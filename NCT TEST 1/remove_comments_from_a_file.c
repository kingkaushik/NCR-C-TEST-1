#include<stdio.h>
#include<conio.h>
void remove_comments_from_a_file(char *);
void remove_comments_from_a_file(char file_path[])
{
	FILE *fptr = NULL, *fptr2 = NULL;
	fopen_s(&fptr, "comments_file_read.txt", "r");
	fopen_s(&fptr2, "comment_file_write.txt", "w");
	if (fptr != NULL && fptr2 != NULL)
	{
		char ch1 = '\0', ch2 = '\0';
		while (!feof(fptr))
		{
			ch2 = fgetc(fptr);
			if (ch1 == '/' && ( ch2 == '/' || ch2 == '*'))
			{
				if (ch2 == '/')
				{
					while (fgetc(fptr) != '\n');
					ch2 = fgetc(fptr);
				}
				else if(ch2 == '*')
				{
					while (fgetc(fptr) != '*');
					if (fgetc(fptr) == '/');
					ch2 = fgetc(fptr);
				}
				ch1 = '\0';
			}
			if (ch2 == '/')
				ch1 = '/';
			else if(ch1 == '/' &&  ch2!='/')
			{
				if (ch1 != EOF)
					fputc(ch1, fptr2);
				ch1 = '\0';
				if (ch2 != EOF)
					fputc(ch2, fptr2);
			}
			else
			{
				if (ch2 != EOF)
					fputc(ch2, fptr2);
			}
		}
		printf("\nSUCCESSFULLY COMMENTS REMOVED");
	}
	else
	{
		printf("\nERROR OCCURED!");
	}
}