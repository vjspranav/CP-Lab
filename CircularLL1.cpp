#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int info;
	node *link;
};
node *listptr = NULL;
node *listptr2 = NULL;
node *listptr3 = NULL;
node *listptr4 = NULL;
node *listptr5 = NULL;
node *listptr10 = NULL;
node *listptr11 = NULL;
int g[10];
int size4 = 0;
void insert2()
{

	int n;
	cout << "Enter item: ";
	cin >> n;
	node *newnode = new node;
	newnode->info = n;
	newnode->link = NULL;
	if (listptr2 == NULL)
	{
		listptr2 = newnode;
		newnode->link = newnode;
	}
	else
	{
		node *track;
		track = listptr2;
		while (track->link != listptr2)
		{
			track = track->link;
		}
		track->link = newnode;
		newnode->link = listptr2;
	}
}
void insert3()
{

	int n;
	cout << "Enter item: ";
	cin >> n;
	node *newnode = new node;
	newnode->info = n;
	newnode->link = NULL;
	if (listptr3 == NULL)
	{
		listptr3 = newnode;
		newnode->link = newnode;
	}
	else
	{
		node *track;
		track = listptr3;
		while (track->link != listptr3)
		{
			track = track->link;
		}
		track->link = newnode;
		newnode->link = listptr3;
	}
}
void insert4()
{

	int n;
	cout << "Enter item: ";
	cin >> n;
	node *newnode = new node;
	newnode->info = n;
	newnode->link = NULL;
	if (listptr4 == NULL)
	{
		listptr4 = newnode;
		newnode->link = newnode;
	}
	else
	{
		node *track;
		track = listptr4;
		while (track->link != listptr4)
		{
			track = track->link;
		}
		track->link = newnode;
		newnode->link = listptr4;
	}
}
void insert5()
{

	int n;
	cout << "Enter item: ";
	cin >> n;
	node *newnode = new node;
	newnode->info = n;
	newnode->link = NULL;
	if (listptr5 == NULL)
	{
		listptr5 = newnode;
		newnode->link = newnode;
	}
	else
	{
		node *track;
		track = listptr5;
		while (track->link != listptr5)
		{
			track = track->link;
		}
		track->link = newnode;
		newnode->link = listptr5;
	}
}
void rev()
{
	node *start;
	start = listptr2;
	node *head;
	node *prev;
	node *curr;
	node *next;
	prev = NULL;
	curr = listptr2;
	next = listptr2->link;
	while (curr->link != listptr2)
	{
		curr->link = prev;
		prev = curr;
		curr = next;
		next = next->link;
	}
	next = NULL;
	curr->link = prev;
	head = curr;
	start->link = head;
	cout << "\nReversed list is:\n";
	node *track;
	track = head;
	cout << "HEAD->";
	while (track->link != listptr2)
	{
		cout << track->info << "->";
		track = track->link;
	}
	cout << track->info << "->LISTPTR";
}
void insert_end()
{
	system("cls");
	int n;
	node *newnode = new node;
	cout << "\nEnter item: ";
	cin >> n;
	newnode->info = n;
	newnode->link = NULL;
	if (listptr == NULL)
	{
		listptr = newnode;
		newnode->link = newnode;
	}
	else
	{
		node *track;
		track = listptr;
		while (track->link != listptr)
		{
			track = track->link;
		}
		track->link = newnode;
		newnode->link = listptr;
	}
	cout << "Node Inserted successfully";
}
void insert_beg()
{
	system("cls");
	int n;
	node *newnode = new node;
	cout << "\nEnter item: ";
	cin >> n;
	newnode->info = n;
	newnode->link = NULL;
	if (listptr == NULL)
	{
		listptr = newnode;
		newnode->link = newnode;
	}
	else
	{
		newnode->link = listptr;
		listptr = newnode;
		node *temp;
		temp = listptr;
		while (temp->link != listptr)
		{
			temp = temp->link;
		}
		temp->link = newnode;
	}
	cout << "Node inserted in the beginning";
}
void insert_mid()
{
	system("cls");
	int j;
	j = 1;
	node *count;
	count = listptr;
	if (listptr == NULL)
	{
		cout << "Cannot insert in the middle, insert in the beginning or end first";
		return;
	}
	while (count->link != NULL)
	{
		count = count->link;
		j++;
	}
	if (j < 2)
	{
		cout << "Cannot insert in the middle, insert in the beginning or end first";
		return;
	}
	int n, i, a;
	node *newnode = new node;
	cout << "\nEnter item: ";
	cin >> n;
	newnode->info = n;
	newnode->link = NULL;
	cout << "\nEnter position where node should be inserted: ";
	cin >> a;
	i = 1;
	node *track;
	track = listptr;
	while (i != a)
	{
		track = track->link;
		i++;
	}
	newnode->link = track;
	i = 1;
	track = listptr;
	while (i != a - 1)
	{
		track = track->link;
		i++;
	}
	track->link = newnode;
	cout << "Node inserted";
}
void Print()
{
	system("cls");
	node *track;
	track = listptr;
	if (listptr == NULL)
	{
		cout << "No elements to show!";
	}
	else
	{
		cout << "\nHEAD->";
		while (track->link != NULL)
		{
			cout << track->info << "->";
			track = track->link;
		}
		cout << track->info << "->NULL";
	}
}
void del_beg()
{
	system("cls");
	if (listptr == NULL)
	{
		cout << "\nNo item to delete!!";
		return;
	}
	node *temp;
	node *track;
	track = listptr;
	temp = listptr;
	while (temp->link != listptr)
	{
		temp = temp->link;
	}
	listptr = listptr->link;
	free(track);
	temp->link = listptr;
	cout << "\nNode at the beginning is deleted";
}
void del_end()
{
	system("cls");
	if (listptr == NULL)
	{
		cout << "\nNo item to delete!!";
		return;
	}
	node *temp;
	node *track;
	temp = listptr;
	track = listptr;
	while (track->link->link != listptr)
	{
		track = track->link;
	}
	while (temp->link != listptr)
	{
		temp = temp->link;
	}
	track->link = listptr;
	free(temp);
	cout << "\nNode at the end deleted";
}
void del_mid()
{
	system("cls");
	int n, i;
	node *track;
	node *temp;
	cout << "\nEnter position number of item to be deleted: ";
	cin >> n;
	i = 1;
	track = listptr;
	temp = listptr;
	if (n == 1)
	{
		del_beg();
		return;
	}
	while (i != n - 1)
	{
		track = track->link;
		i++;
	}
	i = 1;
	while (i != n)
	{
		temp = temp->link;
		i++;
	}
	track->link = temp->link;
	free(temp);
	cout << "\nItem deleted";
}
void del_by_val()
{
	system("cls");
	int n, i, pos, flag = 0;
	cout << "Enter item: ";
	cin >> n;
	node *track;
	node *temp;
	node *q;
	node *p;
	if (listptr->info == n)
	{
		cout << "It is the first node";
		del_beg();
		return;
	}
	node *count;
	count = listptr;
	while (count->link != NULL)
	{
		count = count->link;
	}
	if (count->info == n)
	{
		cout << "Node at last position";
		del_end();
		return;
	}
	track = listptr;
	i = 1;
	while (track->link != NULL)
	{
		if (track->info == n)
		{
			flag = 1;
			pos = i;
		}
		track = track->link;
		i++;
	}
	if (flag == 0)
	{
		cout << "Sorry! Item could not be found";
		return;
	}
	i = 1;
	track = listptr;
	q = listptr;
	while (i != pos + 1)
	{
		track = track->link;
		i++;
	}
	i = 1;
	while (i != pos - 1)
	{
		q = q->link;
		i++;
	}
	temp = listptr;
	i = 1;
	while (i != pos)
	{
		temp = temp->link;
		i++;
	}
	p = temp;
	q->link = track;
	free(p);
	cout << "\nItem deleted successfully";
}
void len()
{
	int i;
	node *track;
	track = listptr;
	i = 1;
	while (track->link != listptr)
	{
		track = track->link;
		i++;
	}
	cout << "\n\nNumber of items in the list: " << i;
}
void insert()
{
	int n;
	system("cls");
	cout << "\nMenu";
	cout << "\n1. Insert in the beginning";
	cout << "\n2. Insert in the end";
	cout << "\n3. Insert in the middle";
	cout << "\n4. Back";
	cout << "\n\nEnter your choice(1-4): ";
	cin >> n;
	switch (n)
	{
	case 1:
		insert_beg();
		break;
	case 2:
		insert_end();
		break;
	case 3:
		insert_mid();
		break;
	case 4:
		return;
	}
}
void del()
{
	int n;
	system("cls");
	cout << "\nMenu";
	cout << "\n1. Delete from the beginning";
	cout << "\n2. Delete from the end";
	cout << "\n3. Delete from the middle";
	cout << "\n4. Delete by value";
	cout << "\n5. Back";
	cout << "\n\nEnter your choice(1-5): ";
	cin >> n;
	switch (n)
	{
	case 1:
		del_beg();
		break;
	case 2:
		del_end();
		break;
	case 3:
		del_mid();
		break;
	case 4:
		del_by_val();
		break;
	case 5:
		return;
	}
}
void search()
{
	int n, i, flag = 0, pos;
	cout << "Enter the item you want to search for: ";
	cin >> n;
	node *temp;
	temp = listptr3;
	i = 1;
	while (temp->link != listptr3)
	{
		if (temp->info == n)
		{
			flag = 1;
			pos = i;
		}
		i++;
	}
	if (flag == 0)
	{
		cout << "\nSorry! Item could not be found";
	}
}
void to_array_for_sort()
{
	int n, i;
	node *track;
	track = listptr5;
	while (track->link != listptr)
	{
		n = track->info;
		g[size4] = n;
		size4++;

		track = track->link;
	}
	n = track->info;
	g[size4] = n;
	size4++;
}
int sort()
{
	int i, j, t;
	for (i = 0; i < size4 - 1; i++)
	{
		for (j = 0; j < size4 - i - 1; j++)
		{
			if (g[j] > g[j + 1])
			{
				t = g[j];
				g[j] = g[j + 1];
				g[j + 1] = t;
			}
		}
	}
}
void to_newll4()
{
	int i;
	for (i = 0; i < size4; i++)
	{
		node *newnode = new node;
		newnode->info = g[i];
		newnode->link = NULL;
		if (listptr10 == NULL)
		{
			listptr10 = newnode;
			newnode->link = newnode;
		}
		else
		{
			node *temp;
			temp = listptr10;
			while (temp->link != listptr10)
			{
				temp = temp->link;
			}
			temp->link = newnode;
			newnode->link = listptr10;
		}
	}
}
void Printfinal()
{
	node *track;
	track = listptr10;
	if (listptr10 == NULL)
	{
		cout << "No elements to show!";
	}
	else
	{
		cout << "\nHEAD->";
		while (track->link != NULL)
		{
			cout << track->info << "->";
			track = track->link;
		}
		cout << track->info << "->LISTPTR";
	}
}
void copy()
{
	node *track;
	track = listptr4;
	while (track->link != listptr4)
	{
		node *newnode = new node;
		newnode->info = track->info;
		newnode->link = NULL;
		if (listptr11 == NULL)
		{
			listptr11 = newnode;
			newnode->link = newnode;
		}
		else
		{
			node *temp;
			temp = listptr11;
			while (temp->link != listptr11)
			{
				temp = temp->link;
			}
			temp->link = newnode;
			newnode->link = listptr11;
		}
		track = track->link;
	}
	cout << "\nCircular link list is successfully copied";
	cout << "\nThe copied list is as follows: ";
	node *p;
	p = listptr11;
	cout << "HEAD->";
	while (p->link != listptr11)
	{
		cout << p->info << "->";
		p = p->link;
	}
	cout << p->info << "->LISTPTR";
}
int main()
{
	int i, j, k, m, l, d, e;
	cout << "Welcome to Circular Link List!";
	cout << "\nPress any key to continue...";
	system("cls");
	do
	{
		system("cls");
		cout << "Menu";
		cout << "\n1. Insert item in Link list";
		cout << "\n2. Delete item from link list";
		cout << "\n3. Display list";
		cout << "\n4. Find length of list";
		cout << "\n5. Reverse link list";
		cout << "\n6. Search in Link list";
		cout << "\n7. Copy Link list";
		cout << "\n8. Sort Link list";
		cout << "\n9. Exit";
		cout << "\n\nEnter your choice(1/9): ";
		cin >> i;
		switch (i)
		{
		case 1:
			insert();
			break;
		case 2:
			del();
			break;
		case 3:
			Print();
			break;
		case 4:
			len();
			break;
		case 5:
			cout << "How many items do you want to enter?";
			cin >> k;
			for (m = 0; m < k; m++)
			{
				insert2();
			}
			rev();
			break;
		case 6:
			cout << "How many items do you want to enter?";
			cin >> l;
			for (m = 0; m < l; m++)
			{
				insert3();
			}
			search();
			break;
		case 7:
			cout << "How many items do you want to enter?";
			cin >> d;
			for (m = 0; m < d; m++)
			{
				insert4();
			}
			copy();
			break;
		case 8:
			cout << "How many items do you want to enter?";
			cin >> e;
			for (m = 0; m < e; m++)
			{
				insert5();
			}
			to_array_for_sort();
			sort();
			to_newll4();
			Printfinal();
		case 9:
			cout << "\nTerminating...!";
			return 0;
		}
		cout << "\n\nDo you want to continue?";
		cout << "\n1. YES";
		cout << "\n2. NO";
		cout << "\nEnter your choice(1/2): ";
		cin >> j;
	} while (j == 1);
	return 0;
}
