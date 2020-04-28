/*
����������� ��������� ��� ���������� ����� �������� ���������� 
������ �� 2 ������ ��������, �������� ���� ������� ������������� 
������� � ��������� ��������. ������� ������ �������� ������ 
������������ ��������� ����� ����� ������������ �����. 
��������� ����������� �������� ������ ������������ ������� ������ 
������������ ������, ��� ��� ������� ������ ������ ����������� 
�����, � ��� ��������� �������� ������ ������ ������� �������� 
�������� ������� ��� ��������� ����. 

���������� ��������� ������ ���� �������� �� ������������� 
�������������� ��������� ���������� ������ � ������������� 
�������� ���������, �������� � ������� ��� ���������.
*/

#include "SymLink.h"
#include "DualLink.h"
#include <iostream>
#include <cstdio>

int main()
{
	//Init module
	char ch;
	int count = 0;
	int countOnes = 0;
	SymLink* head;
	SymLink* tail;
	SymLink* watch[2];
	SymLink* temp;
	watch[0] = head = new SymLink('\n');
	watch[1] = tail = new SymLink('\n');
	head->insertAfter(tail);
	//Input module
	while ((ch = std::cin.get()) != '\n')
	{
		temp = new SymLink(ch);
		tail->insertBefore(temp);
		count++;
	}
	//Processing module
	temp = head->getNext();
	for (int i = 0; i < count; i++)
	{
		if ((temp->getSymbol()) % 2 == 1)
		{
			SymLink* t = temp->getPrev();
			temp->exception();
			tail->insertBefore(temp);
			temp = t->getNext();
			countOnes++;
		}
		else
			temp = temp->getNext();
	}
	//Output module
	head->printList();
	if (count != 0)
	{
		if ((count - countOnes) == 0)
			printf("1");
		else if (countOnes == 0)
			printf("0");
		else
			printf("0%*c1", (count - countOnes - 1), ' ');
	}
	temp = watch[0];
	//Clear memory
	while (temp != NULL)
	{
		head = temp->getNext();
		temp->exception();
		delete temp;
		temp = head;
	}

	return 0;
}