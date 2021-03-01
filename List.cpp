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
	Node* current { new Node};
    std::cout << "Input first element ";
    std::cin >> b;
    current->value = b;
    current->next = nullptr;
    return current;
}
void add_element_any (Node* front,int num)
{
	Node* current{new Node};
	current->value=num;
	Node* temp=front;
	while (temp->next->value<num)
	{
		temp=temp->next;
	}
	current->next=temp->next;
	temp->next=current;
}
void add_element_last(Node* front,int num)
{
	Node* last{front};
	Node* current{new Node};
	current->value=num;
	current->next=nullptr;
	while (last->next!=nullptr)
	{
		last=last->next;
	}
	last->next=current;
}
Node* add_element_front(Node* front,int num)
{
	Node* current { new Node};
	current->value = num;
	current->next = front;
	return current;
}
Node* add_element_switch(Node* front,int num)
{
	Node* temp {front};
	
	if ((temp->next==nullptr)&&(temp->value==num)||(front->value==num))
	{
			std::cout << "ERROR element already exists ";
			return front;
	}
	while (temp->next != nullptr)
	{
		temp = temp->next;
		if (temp->value == num)
		{
			std::cout << "ERROR element already exists ";
			return front;
		}
	}
	if (front->value > num)
	{
		return add_element_front(front, num);
	}
	else

		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
	if (temp->value < num)
	{
		add_element_last(front, num);
		return front;
	}
	else
	{
		add_element_any(front, num);
		return front;
	}
}

 Node* del_front(Node* front)
{
	 Node* temp {front->next};
	delete front;
	return(temp); // новый корень списка
}
Node* del_element(Node *front)
{
	Node* temp {front};
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
	Node* temp {front};
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
	Node* front {new Node};
    auto a = 0;
    auto b = 0;
    while (a != 7)
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
		    	int num;
		        std::cout << "Enter element";
		        std::cin >> num;
			    front = add_element_switch(front,num);
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
		case 6: if(b==1) del_all(front);
	    		a=7;
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
