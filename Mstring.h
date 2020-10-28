#include <stdio.h> 
#include <stdlib.h>

#define true 1
#define false 0


int power_int (int x, int y)
{
    if (y == 0)
        return 1;
    else if ((y % 2) == 0)
        return power_int (x, y / 2) * power_int (x, y / 2);
    else
        return x * power_int (x, y / 2) * power_int (x, y / 2);

}


struct MstringElement__
{
	char letter;
	struct MstringElement__* nextletter;
};

typedef struct MstringElement__ MstringElement;

struct Mstring__
{
	int size;
	MstringElement* firstletter;
};

typedef struct Mstring__ Mstring;

Mstring** Mstring_new()
{
	Mstring** returned_pointer = (Mstring**)malloc(sizeof(Mstring*));
	Mstring* node = (Mstring*)malloc(sizeof(Mstring));
	(*node).firstletter = (MstringElement*)malloc(sizeof(MstringElement));
	(*node).size = 0;
	(*(*node).firstletter).letter = '\0';
	*returned_pointer = node;
	return returned_pointer;
}

void Mstring_addLetter(Mstring** string, char char_you_want_to_insert)
{
	MstringElement* helper = (*(*string)).firstletter;
	for (int x = 0; x < ((*(*string)).size); x++)
	{
		helper = (*helper).nextletter;
	}
	(*helper).letter = char_you_want_to_insert;
	(*helper).nextletter = (MstringElement*)malloc((sizeof (MstringElement)) * (1 + ((*(*string)).size) + 1));
	(*(*helper).nextletter).letter = '\0';
	(*(*string)).size = (*(*string)).size + 1;
}

void Mstring_read(Mstring** string)
{
	MstringElement* helper = (*(*string)).firstletter;
	for (int i = 0; i < (*(*string)).size; i++)
	{
		printf("%c", (*helper).letter);
		helper = (*helper).nextletter;
	}
}

void Mstring_removeLast(Mstring** string)
{
	(*(*string)).size = (*(*string)).size - 1;
}

void Mstring_removeElementByNumber(Mstring** string, int number)
{
	MstringElement* helper = (*(*string)).firstletter;
	for (int i = -1; i < number - 2; i++)
	{
		helper = (*helper).nextletter;
	}
	(*helper) = (*(*helper).nextletter);
	(**string).size = (**string).size - 1;

}

void Mstring_replaceElementByNumber(Mstring** string, int number, char newchar)
{
	MstringElement* helper = (*(*string)).firstletter;
	for (int i = 0; i < number - 1; i++)
	{
		helper = (*helper).nextletter;
	}
	(*helper).letter = newchar;

}

char Mstring_returnCharacterByNumber(Mstring** string, int number)
{
	MstringElement* helper = (*(*string)).firstletter;
	for (int i = 0; i < number - 1; i++)
	{
		helper = (*helper).nextletter;
	}
	return (*helper).letter;
}

void Mstring_appendToFirst(Mstring** string_first, Mstring** string_last)
{
	MstringElement* helper = (*(*string_first)).firstletter;
	for (int i = 0; i < (*(*string_first)).size - 1; i++)
	{
		helper = (*helper).nextletter;
	}
	(*helper).nextletter = (**string_last).firstletter;
	(**string_first).size = (**string_first).size + (**string_last).size;
}

struct MstringList_element__ {
	Mstring** content;
	struct MstringList_element__* next;
};

typedef struct MstringList_element__ MstringList_element;

struct MstringList__ {
	int size;
	MstringList_element* first;
};

typedef struct MstringList__ MstringList;

void Mstring_convertstring(Mstring** string_to, const char* string_from)
{
	int trigger = 1;
	for (int i=0; trigger; i++)
	{
		if (string_from[i] == 0)
		{
			trigger = 0;
		}
		if (trigger)
		{
			Mstring_addLetter(string_to,string_from[i]);
		}

	}
}

int Mstring_check_substring(Mstring ** string_checked, Mstring** substring)
{
	int size = (**string_checked).size;
	int sub_size = (**substring).size;
	int returnbool = 0;

	int booltemp = 0;

	for (int LocationInWord=1;LocationInWord<=size;LocationInWord++)
	{
		for (int locationInSubString=1; locationInSubString<=sub_size;locationInSubString++)
		{
			
			if (Mstring_returnCharacterByNumber(string_checked,LocationInWord) == Mstring_returnCharacterByNumber(substring,locationInSubString))
			{
				booltemp = 1;
				for (int z = 0; z < sub_size; z++)
				{
					if (booltemp)
					{
						booltemp = (Mstring_returnCharacterByNumber(string_checked,LocationInWord + z) == Mstring_returnCharacterByNumber(substring,locationInSubString + z));
						if (booltemp == true && z == sub_size - 1)
						{
							return 1;
						}
					}
				}
			}
		}
	}

	return returnbool;
}

int Mstring_check_substring_exact_match(Mstring** string_checked, Mstring** substring)
{
	int size = (**string_checked).size;
	int sub_size = (**substring).size;
	int returnbool = 0;
	if (sub_size != size)
	{
		return false;
	}
	int booltemp = 0;

	int LocationInWord = 1;
		for (int locationInSubString = 1; locationInSubString <= sub_size; locationInSubString++)
		{

			if (Mstring_returnCharacterByNumber(string_checked, LocationInWord) == Mstring_returnCharacterByNumber(substring, locationInSubString))
			{
				booltemp = 1;
				for (int z = 0; z < sub_size; z++)
				{
					if (booltemp)
					{
						booltemp = (Mstring_returnCharacterByNumber(string_checked, LocationInWord + z) == Mstring_returnCharacterByNumber(substring, locationInSubString + z));
						if (booltemp == true && z == sub_size - 1)
						{
							return 1;
						}
					}
				}
			}
		
	}

	return returnbool;
}

MstringList** MstringList_new()
{
	MstringList** return_address = (MstringList**)malloc(sizeof(MstringList*));
	MstringList* node = (MstringList*)malloc(sizeof(MstringList));
	(*node).first = (MstringList_element*)malloc(sizeof(MstringList_element));
	(*node).size = 0;
	*return_address = node;
	return return_address;
}

void MstringList_add(MstringList** name_of_array, Mstring** name_of_string)
{
	MstringList_element* helper = (**name_of_array).first;
	for (int x = 0; x < (**name_of_array).size; x++)
	{
		helper = (*helper).next;
	}
	(*helper).content = name_of_string;
	(*helper).next = (MstringList_element*)malloc((sizeof (MstringList_element)) * (1 + ((*(*name_of_array)).size) + 1));
	(**name_of_array).size = (**name_of_array).size + 1;
}

void MstringList_readEntire(MstringList** name_of_array)
{
	MstringList_element* helper = (**name_of_array).first;
	for (int x = 0; x < (**name_of_array).size; x++)
	{
		Mstring_read((*helper).content);
		printf("\n\n");
		helper = (*helper).next;
	}
}

Mstring** MstringList_return_element_by_number(MstringList** name_of_array, int number)
{
	if (number >= 1 && number < (**name_of_array).size)
		{
		MstringList_element* helper = (**name_of_array).first;

		for (int i = 1; i < number; i++)
		{
			helper = (*helper).next;
		}
		return (*helper).content;
	}
	else
	{
		return (*(**name_of_array).first).content;
	}
}

void MstringList_removeLast(MstringList** name_of_array)
{
	(**name_of_array).size = (**name_of_array).size - 1;
}


const char ascii_stevila[] = "0123456789";
const int ascii_stevila_int[] = { 0,1,2,3,4,5,6,7,8,9 };

int convert_char_to_int(char convert)
{
	for (int count = 0; count < sizeof(ascii_stevila_int); count++)
	{
		if (ascii_stevila[count] == convert)
		{
			return ascii_stevila_int[count];
		}
	}
	return 0;
}

int convert_Mstring_to_int(Mstring** string_in)
{
	int power_of = (**(string_in)).size;
	int return_val = 0;
	int a = (**(string_in)).size;
	for (int i = 1; i <= a; i++)
	{
		return_val = return_val + convert_char_to_int(Mstring_returnCharacterByNumber(string_in, i)) * power_int(10, power_of - 1);
		power_of = power_of - 1;
	}
	return return_val;
}

struct Omnilist
{
	int size;
	int content;
	struct Omnilist* newElement;
	struct Omnilist* beginning;
};

struct Omnilist* Omnilist_new()
{
	struct Omnilist* newlist = (struct Omnilist*)malloc((sizeof(struct Omnilist)));
	(*newlist).beginning = newlist;
	(*newlist).size = 0;
	return newlist;
}

void Omnilist_push(struct Omnilist* list_pushed_to, int insert)
{
	struct Omnilist* helper = list_pushed_to;
	for (int count = 0; count < (*(*list_pushed_to).beginning).size; count++)
	{
		helper = (*helper).newElement;
	}
	(*helper).newElement = (struct Omnilist*)malloc((sizeof(struct Omnilist)));
	(*(*helper).newElement).content = insert;
	(*(*list_pushed_to).beginning).size = (*(*list_pushed_to).beginning).size + 1;
	(*(*helper).newElement).beginning = (*list_pushed_to).beginning;
}

void Omnilist_print(struct Omnilist* list_pushed_to)
{
	struct Omnilist* helper = (*list_pushed_to).newElement;
	for (int count = 0; count < (*(*list_pushed_to).beginning).size; count++)
	{
		printf("%d", (*helper).content);
		helper = (*helper).newElement;
	}
}

int Omnilist_returnint_by_index(struct Omnilist* list_pushed_to, int index)
{
	struct Omnilist* helper = (*list_pushed_to).newElement;
	for (int count = 0; count < index; count++)
	{
		helper = (*helper).newElement;
	}
	return (*helper).content;
}
