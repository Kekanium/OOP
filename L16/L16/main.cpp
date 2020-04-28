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
	
	while ((ch = std::cin.get()) != '\n')
	{
		temp = new SymLink(ch);
		tail->insertBefore(temp);
		count++;
	}
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
	return 0;
}