#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"
#include "error.h"



/*func*/
node_pointer list_create_node(char* name,int address,short attributes)
{
	node_pointer newNode;

	newNode = (node_pointer)malloc(sizeof(symbol_node));
	if (!newNode)
		fatal_error(ErrorMemoryAlloc);
	newNode->symbol_name = name;
	newNode->symbol_address = address;
	newNode->symbol_attributes = attributes;
}




List list_add_to_list(node_pointer list, char* name, int address, short attributes)
{
	node_pointer node, temp;

	node = _list_create_node(name, address, attributes);

	temp = list;
	if (!list)
		list = node;
	else
	{
		while (temp->next)
			temp = temp->next;

		temp->next = node;
	}
}

/*
* ������� ������ ��� ��� ��� ���� , �� �� �� ������ 1
* ����� �� ����� ������
*/
int list_search_symbol(node_pointer* List,const char* name)
{
	symbol_node* temp = List;

	while (temp)
	{
		if (strcmp(name, temp->symbol_name))
			return 1;
		temp = temp->next;
	}
}



/*������� ������� ����� ���� �����.*/
void list_free_symbol_list(node_pointer List)
{
	symbol_node* curr = List;
	node_pointer* temp;

	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	return;
}