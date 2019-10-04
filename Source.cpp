#include<iostream>
#include<string>
using namespace std;

class IntSLLNode
{
public:
	int info;
	IntSLLNode * next;
	IntSLLNode()
	{
		next = 0;
	}
	IntSLLNode(int i, IntSLLNode* n = 0)
	{
		info = i;
		next = 0;
	}

};
class IntCircluarSLL
{
	IntSLLNode *tail;
public:
	IntCircluarSLL()
	{
		tail = NULL;
	}
	~IntCircluarSLL() {}

	void addToHead(int x) {
		if (isEmpty())
		{
			IntSLLNode *temp = new IntSLLNode(x);
			temp->next = temp;
			tail = temp;

		}
		else
		{
			IntSLLNode *temp = new IntSLLNode(x);
			temp->next = tail->next;
			tail->next = temp;

		}

	}
	void deleteFromHead() {

		if (tail == NULL)
		{
			cout << "\t ---------------------------------------------------\n";
			cout << "\t|     Your circularLinkedList is Aready Empty      |\n";
			cout << "\t ---------------------------------------------------\n";
		}
		else if (tail == tail->next)
		{
			tail = tail->next = NULL;

		}
		else {
			IntSLLNode *temp = new IntSLLNode();
			temp->next = tail->next;
			tail->next = tail->next->next;
			delete temp;
		}

	}

	bool isEmpty()
	{
		if (tail == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	void show()
	{
		if (isEmpty())
		{
			cout << "\t --------------------------------------------\n";
			cout << "\t|     Your circularLinkedList is Empty       |\n";
			cout << "\t --------------------------------------------\n";
		}
		else
		{
			cout << "Your list: \n";
			int x;
			x = tail->info;
			while (true)
			{
				cout << tail->info << endl;
				tail = tail->next;
				if (tail->info == x)
				{
					break;
				}
			}
		}

	}

};


int insertaftertail()
{
	int num;
	cout << "Enter a number to the List\n";
	cin >> num;
	return num;

}
int main()
{
	IntCircluarSLL obj;
		while (true)
		{
			cout << "________________________________________\n";
			cout << "         Menu                           \n";
			cout << "________________________________________\n";
			cout << "    '0' to exit                         \n";
			cout << "    '1' show List                       \n";
			cout << "    '2' to insert to head or after tail \n";
			cout << "    '3' to delete from tail             \n";
			cout << "________________________________________\n\n";

			int option;
			cout << "Enter your option \n";
			cin >> option;
		
		
			switch (option)
			{
			case 0:exit(0); break;
			case 1:obj.show(); break;
			case 2:obj.addToHead(insertaftertail()); break;
			case 3:obj.deleteFromHead(); break;

		
			default:cout << "Enter a valid opiton\n"; break;
			}
		
		}

	system("pause");
}