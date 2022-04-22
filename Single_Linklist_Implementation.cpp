#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    node *ptr;
};
class Linklist
{
private:
    node *start, *current, *next;
    int node_count,position;

public:
    Linklist()
    {
        start = current = next = NULL;
        node_count = 0;
        position = 0;
    }
    void create_node()
     {
        if (start == NULL)
        {
            start = new node;
            cin >> start -> data;
            start->ptr = NULL;
            current = start;
            node_count++;
        }
        else
        {
            next = new node;
            cin >> next -> data;
            next->ptr = NULL;
            current->ptr = next;
            current = next;
            node_count++;
        }
    }
    void insert_start()
    {
        next = new node;
        cout << "\nEnter Integer:";
        cin >> next -> data;
        next->ptr = start;
        start = next;
        node_count++;
    }
    void insert_specific()
    {
        next = new node;
        cout << "\nEnter Integer:";
        cin >> next -> data;
        next ->ptr = NULL;
        current = next;
        node_count++;
        cout<<"\nEnter Position Of Node To Inserted."<<endl;
        cin >> position;
        if(position>node_count || position<0)
        {
            cout<<"\nInvalid Position"<<endl;
        }
        else
        {
            current = start;
            for (int i = 1; i < position-1; i++)
            {
                current = current -> ptr;
            }
            next -> ptr = current -> ptr;
            current -> ptr = next; 
            node_count++;
        }
    }
     void insert_end()
    {
        current = start;
        while (current->ptr != NULL)  
        {
            current = current->ptr;
        }
        next = new node;
        cout << "\nEnter Integer:";
        cin >> next -> data;
        current->ptr = next;
        next->ptr = NULL;
        current = next;
    }
    void delete_start()
    {
        node *temp = NULL;
        temp = start;
        start = start->ptr; //making second node as start
        delete (temp);
        node_count--;
    }
    void delete_specific()
    {
    	cout<<"\nEnter Position Of Node To Deleted.";
        cin >> position;
        if(position>node_count || position<0)
        {
            cout<<"\nInvalid Position"<<endl;
        }
        else
        {
            current = start;
            for (int i = 1; i < position-1; i++)
            {
                current = current -> ptr;
            }
				node *temp = NULL;
				temp = current -> ptr;
				current->ptr = current->ptr->ptr;
				delete (temp);
				node_count--;
        }
	}
    void delete_end()
    {
        current = start;
        while (current->ptr->ptr != NULL)
        {
            current = current->ptr;
        }
        node *temp = NULL;
        temp = current->ptr;
        current->ptr = NULL;
        delete (temp);
    }
    void traverse()
    {
    	int count = 1;
    	if(start==NULL)
    	{
    		cout<<"\nNo Node Left....\n";
		}
		else
        current = start;
        while (current != NULL)
        {
            cout << "Node [" << count << "] = " << current->data << endl;
            count = count + 1;
            current = current->ptr;
        }
    }
    void search()
	{
		int number;
		bool flag = false;
		if (start == NULL)
		{
			cout << "No Linked List Created\n";
		}
		else
		current  = start;
		cout << "Enter Data You want to Search: ";
		cin >> number;
		while (current != NULL)
		{
			if (current->data == number)
			{
				cout <<"\nValue Found :  "<< current->data << endl;
				flag = true;
			}
			current  = current ->ptr;
		}
		if (flag == false)
		{
			cout << "Its not in List\n";
		}
	}
}; 
int main()
{
    Linklist obj;
    int size;
    cout << "==================================================\n";
    cout << "Enter The Size Of Linked List: ";
    cin >> size;
    cout << "==================================================\n";
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter value (Integer) of Node " << i << ": ";
        obj.create_node();
    }
    cout << "Linked List Created Successfully..." << endl;
    system("CLS");
    int op = -1;
    int op2;
    while (op != 6)
    {
        cout << "==================================================\n";
        cout << "Linked List Operations\n";
        cout << "==================================================\n";
        cout << "Enter operation you want to perform: \n1. Traverse\n2. Inserting\n3. Deleteting\n4. Searching \n5. Clear Screen\n6. Exit\n";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Linked List:\n";
            obj.traverse();
            break;
		case 2:
			cout<<"1. Insert At Start\n2. Insert At Specific Position\n3. Insert At End\n";
			cin>>op2;
			if(op2==1)
			{
				obj.insert_start();
            	obj.traverse();
            	cout << "Node Inserted Successfully....\n\n";
            	break;
			}
			else if(op2==2)
			{
			    obj.insert_specific();
            	obj.traverse();
            	cout << "Node Inserted Successfully....\n\n";
            	break;		
			}
			else
			{
				obj.insert_end();
            	obj.traverse();
            	cout << "Node Inserted Successfully....\n\n";
            	break;		
			}	
		case 3:
			cout<<"1. Delete At Start\n2. Delete At Specific Position\n3. Delete At End\n";
			cin>>op2;
			if(op2==1)
			{
            	obj.delete_start();
            	obj.traverse();
            	cout << "Node Deleted Successfully....\n\n";
            	break;
			}
			else if(op2==2)
			{
				obj.delete_specific();
				obj.traverse();
				cout << "Node Deleted Successfully....\n\n";
				break;		
			}
			else
			{
            	obj.delete_end();
            	obj.traverse();
            	cout << "Node Deleted Successfully....\n\n";
            	break;	
			}
        case 4:
            obj.traverse();
            obj.search();
            cout << "Search Done Successfully....\n\n";
            break;
        case 5:
            system("CLS");
            break;

        default:
            break;
        }
    }
}
