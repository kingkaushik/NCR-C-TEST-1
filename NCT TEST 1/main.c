#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
extern void count_character_types_into_file();
extern void remove_comments_from_a_file(char *);
extern void file_matching_word_rotator(char *);
extern void replace_tabs();
int main()
{
	int choice = -1;
	printf("PRESS 1:COUNT NO OF ALPHABETS DIGITS SPACES AND SPECIAL CHARACTERS IN TO A FILE\n");
	printf("      2:REMOVE ALL COMMENTS FROM THE FILE CONTENT\n");
	printf("      3:FIND A MATCHING WORD IN THE FILE AND ROTATE THE WORD AND PLACE IT IN THE SAME FILE\n");
	printf("      4:REPLACE ALL THE TABS PRESENT IN THE FILE WITH \\t.\n");
	printf("ENTER UR CHOICE:");
	scanf_s("%d", &choice);
	int string_length = -1;
	char file_path[] = "comments_file.c";
	switch (choice)
	{
	case 1:
		//COUNTS NO OF ALPHABETS DIGITS SPACES AND SPEICAL CHARACTERS INTO A FILE
		count_character_types_into_file();
		break;
	case 2:
		remove_comments_from_a_file(file_path);
		break;
	case 3:
		printf("ENTER NO OF CHARACTERS U WANT TO ENTER:");
		scanf_s("%d", &string_length);
		printf("\nENTER A STRING TO FIND IN A FILE AND ROTATE IT:");
		char *str1 = (char*)calloc(string_length + 1, sizeof(char));
		gets_s(str1, 1);
		gets_s(str1, string_length + 1);
		file_matching_word_rotator(str1);
		break;
	case 4:
		replace_tabs();
		break;
	default:
		break;
	}
	_getch();
	return 0;
}