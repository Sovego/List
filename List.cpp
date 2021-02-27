#include <iostream>
#include <cstdlib>
#include <conio.h>
struct Node
{
    int value;
    Node* next;
};

Node* make_list()
{
    int b;
    Node* current = new Node;
    std::cout << "Input first element ";
    std::cin >> b;
    current->value = b;
    current->next = nullptr;
    return current;
}

Node* add_element(Node* front)
{
	Node* current = new Node{};
	int b;
	std::cout << "Input element ";
	std::cin >> b;
	current->value = b;
	current->next = front;
	return current;
}

 Node* del_front(Node* front)
{
	Node* temp;
	temp = front->next;
	delete front;
	return(temp); // новый корень списка
}
Node* del_element(Node *front)
{
	Node* temp = front;
	Node* current;
	int a;
	std::cout << "Input value to del ";
	std::cin >> a;
	if ((temp==front) &&(temp->value==a))
	{
		return del_front(temp);
	}
	while ((temp->next->value != a) && (temp->next != nullptr))
	{
		temp = temp->next;
	}
	if (temp->next == nullptr)
	{
		current = temp;
		delete current;
		return front;
	}
	else {
		current = temp->next;
		temp->next = current->next;
		delete current;
		return front;
	}
}


void del_all(Node* front)
{
	Node* temp = front;
    Node* current;
	while (temp->next != nullptr)
	{
		temp = temp->next;
		if (temp->next==nullptr)
		{
			current = temp;
			delete current;
			return;
		}
		else
		{
			current = temp->next;
			temp->next = current->next;
			delete current;
		}
	}
}

void output_list(Node* front)
{
	for (Node* current{front}; current != nullptr; current = current->next)
	{
		std::cout << current->value << "  ";
	}
	std::cout << std::endl;
}

void clear()
{
	std::cout << "\x1B[2J\x1B[H";
}

int main()
{
    Node* front = new Node;
    auto a = 0;
    auto b = 0;
    while (a != 6)
    {
	    std::cout << "1 Make list (1 element)" << std::endl << "2 add element" << std::endl << "3 del element"
		    << std::endl;
	    std::cout << "4 del all" << std::endl << "5 Output list" << std::endl << "6 end work and exit" << std::endl;
	    std::cout << "Select ";
	    std::cin >> a;
	    switch (a)
	    {
	    case 1:
			if (b==0)
			{
		    front = make_list();
		    b = 1;
			}else
			{
				std::cout << "List is created";
			}
		    break;
	    case 2:
		    if (b == 0)
		    {
			    std::cout << "List not create";
			    break;
		    }
		    else
		    {
			    front = add_element(front);
		    }
		    break;
	    case 3:
		    if (b == 0)
		    {
			    std::cout << "List not create";
			    break;
		    }
		    else
		    {
			    output_list(front);
			     front=del_element(front);
		    	if (front==nullptr)
		    	
			    {
				    b = 0;
			    }
		    }
		    break;
	    case 4:
		    if (b == 0)
		    {
			    std::cout << "List not create";
			    break;
		    }
		    else
		    {
			    del_all(front);
		    }
		    b = 0;
		    break;
	    case 5:
		    if (b == 0)
		    {
			    std::cout << "List not create";
			    break;
		    }
		    else { output_list(front); }
		    break;
	    default:
		    break;
	    }
	    std::cout << std::endl << "Press any key to continue " << std::endl;
	    //getchar();
	    _getch();
	    //clear();
	    system("cls");
    }
}
