#include"stack.h"
using namespace std;
int main()
{
	Stack st;//create an empty stack
	char ch;
	Item po;
	cout << "Please enter A to add a purchase order,\n"
		<< "P to process a PO ,or Q to quit,\n"
		<< "R to clear the stack,\n"
		<< "C to query\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
		{
			continue;
		}
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
			SElemType topElem;
		case 'A':
		case 'a':
			cout << "Enter a PO number to add: ";
			cin >> po;
			if (st.isfull())
			{
				cout << "stack is already full\n";
			}
			else
			{
				st.push(po);
			}
			//
			cout << "stack len is " << st.stackLength() <<endl;
			if (st.GetTop(&topElem))
			{
				cout << "stack top is " << topElem << endl;
				cout << "visit from bottom to top" << endl;
				st.stackTraverse();
			}
			break;

		case 'R':
		case 'r':
			cout << "Clear the Stack\n";
			st.ClearStack();
			//TODO copy below sentences to other options
			cout << "stack len is " << st.stackLength() << endl;
			if (st.GetTop(&topElem))
			{
				cout << "stack top is " << topElem << endl;
				cout << "visit from bottom to top" << endl;
				st.stackTraverse();
			}
			break;
		case 'P':
		case 'p':
			if (st.isempty())
			{
				cout << "stack is already empty\n";
			}
			else
			{
				st.pop(po);
				cout << "PO#" << po << " poped\n";
			}
			cout << "stack len is " << st.stackLength() << endl;
			if (st.GetTop(&topElem))
			{
				cout << "stack top is " << topElem << endl;
				cout << "visit from bottom to top" << endl;
				st.stackTraverse();
			}
			break;
		case'C':
		case'c':
			cout << "stack len is " << st.stackLength() << endl;
			if (st.GetTop(&topElem))
			{
			cout << "stack top is " << topElem << endl;
			cout << "visit from bottom to top" << endl;
			st.stackTraverse();
			}

		}
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO ,or Q to quit,\n"
			<< "R to clear the stack,\n"
			<< "C to query\n";

	}
	cout << "BYE\n";
	return 0;
}