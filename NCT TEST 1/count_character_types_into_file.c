#include<stdio.h>
#include<conio.h>
void count_character_types_into_file();
void count_character_types_into_file()
{
	FILE *fptr, *fptr1;
	//opening file with write permision
	fopen_s(&fptr,"character_count_write.txt","w");
	fopen_s(&fptr1, "character_count_read.txt", "r");
	int digits_count = 0, alphabets_count = 0, spaces_count = 0, tabs_count = 0, special_characters_count = 0;
	if (fptr != NULL && fptr1 != NULL)
	{
		char ch;
		while (!feof(fptr1))
		{
			ch = fgetc(fptr1);
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
				alphabets_count++;
			else if (ch >= '0' && ch <= '9')
				digits_count++;
			else if (ch == ' ')
				spaces_count++;
			else if (ch == '\t')
				tabs_count++;
			else
				special_characters_count++;
		}
		printf("DIGITS COUNT = %d\n", digits_count);
		printf("ALPHABETS COUNT = %d\n", alphabets_count);
		printf("SPACES COUNT = %d\n", spaces_count);
		printf("TABS COUNT = %d\n", tabs_count);
		printf("SPEICAL CHARCATERS COUNT = %d\n", special_characters_count);
		printf("CONTENTS SUCESSFULLY WRITTEN INTO FILE\n");
		//WRITING CONTENT INTO FILE
		fprintf(fptr, "DIGITS COUNT = %d\n", digits_count);
		fprintf(fptr, "ALPHABETS COUNT = %d\n", alphabets_count);
		fprintf(fptr, "SPACES COUNT = %d\n", spaces_count);
		fprintf(fptr, "TABS COUNT = %d\n", tabs_count);
		fprintf(fptr, "SPEICAL CHARCATERS COUNT = %d\n", special_characters_count);
		fclose(fptr);
		printf("\nSUCCESSFULLY WRITTEN TO FILE");
	}
	else
	{
		printf("\nERROR OCCURED!");
	}
}