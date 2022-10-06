// Single Linked List
#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename type>

class linkedList
{
    struct Node
    {
        type data;
        Node *Next;
    };

    Node *Begin = NULL;

public:
    void traverse()
    {
        if (Begin == NULL)
        {
            cout << "List Is Empty";
        }

        else
        {
            Node *ptr = Begin;
            while (ptr != NULL)
            {
                cout << "-> | " << ptr->data << " " << ptr->Next << " | ";
                ptr = ptr->Next;
            }
        }
    }

    void insertBeg(type x)
    {
        Node *tmp = new Node;
        tmp->data = x;
        tmp->Next = Begin;
        Begin = tmp;
    }

    void search(type x)
    {
        Node *ptr = Begin;
        bool flag = 0;
        while (ptr != NULL)
        {
            if (ptr->data == x)
            {
                cout << "Element Found At Address : " << ptr << endl;
                flag = 1;
            }
            ptr = ptr->Next;
        }

        if (!flag)
        {
            cout << "Element Not Found";
        }
    }

    void maximum()
    {
        type max = Begin->data;
        Node *ptr = Begin->Next;
        while (ptr != NULL)
        {
            if (ptr->data > max)
            {
                max = ptr->data;
            }
            ptr = ptr->Next;
        }

        cout << "Maximum : " << max;
    }
};

int main()
{
    linkedList<int> obj;
    int val, ch;
    while (true)
    {
        cout << "\nMenu : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter Value To Insert : ";
            cin >> val;
            obj.insertBeg(val);
            cout << endl;
            obj.traverse();
            break;

        case 2:
            cout << "\nEnter Value To Search : ";
            cin >> val;
            obj.search(val);
            cout << endl;
            break;

        case 3:
            obj.maximum();
            break;

        default:
            break;
        }
    }
}

//-----------------------------------------------------------------------------
// Doubly Linked List
#include <iostream>
#include <stdlib.h>
using namespace std;
template <typename type>

class doublelinkedList
{
    struct Node
    {
        type Data;
        Node *Next;
        Node *Prev;
    };
    Node *Begin = NULL;
    Node *End = NULL;

public:
    void insertBeg(type x)
    {
        Node *tmp = new Node;
        tmp->Data = x;
        tmp->Next = Begin;
        tmp->Prev = NULL;
        if (Begin == NULL)
        {
            End = tmp;
        }

        else
        {
            Begin->Prev = tmp;
        }

        Begin = tmp;
    }

    void backwardTraverse()
    {
        Node *tmp = End;
        while (tmp != NULL)
        {
            cout << "-> | " << tmp->Prev << " " << tmp->Data << " " << tmp->Next << " | ";
            tmp = tmp->Prev;
        }
    }
};

int main()
{
    int val;
    doublelinkedList<int> obj;
    while (true)
    {
        cin >> val;
        obj.insertBeg(val);
        obj.backwardTraverse();
    }
}

//--------------------------------------------------------------------------
// Stack
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
template <typename type>

class Stack
{
    int Top, Max;
    type *list;

public:
    Stack(int size)
    {
        Max = size;
        list = new type[Max];
        Top = -1;
    }

    isFull()
    {
        return (Top == Max - 1);
    }

    isEmpty()
    {
        return (Top == -1);
    }

    void push(type value)
    {
        if (isFull())
        {
            cout << "Stack Overflow";
        }

        else
        {
            list[++Top] = value;
            cout << Top;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow";
        }

        else
        {
            Top--;
        }
    }

    void Peek()
    {
        if (isEmpty())
        {
            cout << "Underflow";
        }

        else
        {
            cout << "\n Top Element Of The Stack : " << list[Top];
        }
    }

    void Display()
    {
        cout << "\nStack Elements : \n";
        for (int i = Top; i >= 0; i--)
        {
            cout << list[i] << endl;
        }
    }
};

int main()
{
    int ch, val;
    Stack<int> obj(5);

    while (true)
    {
        cout << "\nMenu 1.Push 2.Pop 3.Peek : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter Value : ";
            cin >> val;
            obj.push(val);
            break;

        case 2:
            obj.pop();
            break;

        case 3:
            obj.Peek();
            break;
        }

        obj.Display();
    }

    return 0;
}

//----------------------------------------------------------------
// Binary Search
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int binarySearch(int A[], int size, int value)
{
    int start = 0, end = size - 1, flag = 0;
    int Middle = ((start + end) / 2);
    while (start <= end)
    {
        if (A[Middle] == value)
        {
            return Middle;
        }

        else if (A[Middle] > value)
        {
            end = Middle - 1;
        }

        else
        {
            start = Middle + 1;
        }
    }
    return -1;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int flag = binarySearch(A, size, 5);
    if (flag != -1)
    {
        cout << "Element Found At Location : " << flag;
    }
    return 0;
}

//---------------------------------------------------------------------------
// Bubble Sort
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

void bubbleSort(int A[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (A[j] > A[j + 1])
            {
                int tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
    }
}

void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    int A[] = {-10, 50, 40, 80, 70, -100, 65};
    cout << "Array Before Sorting : " << endl;
    display(A, 7);
    bubbleSort(A, 7);
    cout << endl;
    display(A, 7);
    return 0;
}

//-------------------------------------------------------------------------------------
// Insertion Sort
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

void insertionSort(int A[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    int A[] = {-10, 50, 40, 80, 70, -100, 65};
    cout << "Array Before Sorting : " << endl;
    display(A, 7);
    insertionSort(A, 7);
    cout << endl;
    display(A, 7);
    return 0;
}
//-----------------------------------------------------------------------------------
// selectionsort
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

void selectionSort(int A[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
            int tmp = A[i];
            A[i] = A[min];
            A[min] = tmp;
        }
    }
}

void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    int A[] = {-10, 50, 40, 80, 70, 100, 65};
    cout << "Array Before Sorting : " << endl;
    display(A, 7);
    selectionSort(A, 7);
    cout << endl;
    display(A, 7);
    return 0;
}

//------------------------------------------------------------------------
// Queue
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Queue
{
    int Front, Rear, Max;
    int *list;

public:
    Queue(int size)
    {
        list = new int[size];
        Front = 0;
        Rear = 0;
        Max = size;
    }
    ~Queue()
    {
        delete[] list;
    }

    bool isFull()
    {
        return (Rear == Max);
    }

    bool isEmpty()
    {
        return (Front == Rear);
    }

    void enQueue(int val)
    {
        if (isFull())
        {
            cout << "Queue Is Full";
        }

        else
        {
            list[Rear] = val;
            Rear++;
        }
    }

    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow";
        }
        else
        {
            for (int i = Front; i < Rear - 1; i++)
            {
                list[i] = list[i + 1];
            }
            Rear--;
        }
    }

    void getFront()
    {
        if (!isEmpty())
        {
            cout << "\nFront : " << list[Front];
        }
    }

    void Traverse()
    {
        for (int i = Front; i < Rear; i++)
        {
            cout << list[i] << " ";
        }
    }
};

int main()
{
    int ch, val;
    Queue obj(5);
    while (true)
    {
        cout << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter Value : ";
            cin >> val;
            obj.enQueue(val);
            break;
        case 2:
            obj.deQueue();
            break;
        case 3:
            obj.getFront();
            break;
        }
        obj.Traverse();
    }
}

//-----------------------------------------------------------------------------------
// Circular Queue

#include <iostream>
#include <stdlib.h>
using namespace std;
template <class type>
class CQueue
{
private:
    int Max;
    int Front, Rear;
    type *List;

public:
    CQueue(int queuesize)
    {
        if (queuesize <= 0)
        {
            cout << "Queue size cannot be negative. Default size is 10";
            queuesize = 10;
        }
        Max = queuesize;
        Front = -1;
        Rear = -1;
        List = new type[Max];
        for (int i = 0; i < Max; i++)
            List[i] = NULL;
    }
    ~CQueue()
    {
        delete[] List;
    }
    bool isEmpty()
    {
        return (Front == -1 && Rear == -1);
    }
    bool isFull()
    {
        return ((Rear + 1) % Max == Front);
    }
    void enQueue(type newitem)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
        }
        else
        {
            if (Front == -1)
                Front = 0;
            Rear = (Rear + 1) % Max;
            List[Rear] = newitem;
        }
    }
    void deQueue()
    {
        if (isEmpty())
            cout << "Queue Underflow" << endl;
        else
        {
            List[Front] = NULL;
            if (Front == Rear)
                Front = Rear = -1;
            else
                Front = (Front + 1) % Max;
        }
    }
    type getFront()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return NULL;
        }
        else
            return List[Front];
    }
    void display()
    {
        cout << "\n Front:" << Front;
        cout << "\n Rear:" << Rear;
        cout << endl;
        if (isEmpty())
        {
            cout << "Circular Queue:";
            for (int i = 0; i < Max; i++)
                cout << List[i] << "\t";
        }
    }
};
int main()
{
    CQueue<int> obj(5);
    int ch, val;
    while (true)
    {
        cout << "\n\n\t Circular Queue Operations (1. enQueue 2. deQueue 3. getFront 4. Exit):";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n\t Enter integer:";
            cin >> val;
            obj.enQueue(val);
            break;

        case 2:
            obj.deQueue();
            break;

        case 3:
            val = obj.getFront();
            if (val != NULL)
                cout << "Top element of the Queue:" << val;
            break;

        case 4:
            exit(0);
        }
        obj.display();
    }
    return 0;
}
//----------------------------------------------------------------------
// 1. For a given(any) binary tree do inorder/preorder/postorder

#include <iostream>
using namespace std;
template <typename type>
class Tree
{
    struct Node
    {
        type data;
        Node *left;
        Node *right;
        Node(type d)
        {
            this->data = d;
            this->left = this->right = NULL;
        }
    };

public:
    Node *Root = NULL;
    Tree()
    {
        Node *f = new Node('F');
        Node *b = new Node('B');
        Node *g = new Node('G');
        Node *a = new Node('A');
        Node *d = new Node('D');
        Node *i = new Node('I');
        Node *c = new Node('C');
        Node *e = new Node('E');
        Node *h = new Node('H');
        f->left = b;
        f->right = g;
        b->left = a;
        b->right = d;
        g->right = i;
        d->left = c;
        d->right = e;
        i->left = h;

        Root = f;
    }
    void preorder(Node *ptr)
    {
        if (ptr != NULL)
        {
            cout << " " << ptr->data;
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }
    void inorder(Node *ptr)
    {
        if (ptr != NULL)
        {
            inorder(ptr->left);
            cout << " " << ptr->data;
            inorder(ptr->right);
        }
    }
    void postorder(Node *ptr)
    {
        if (ptr != NULL)
        {
            postorder(ptr->left);
            postorder(ptr->right);
            cout << " " << ptr->data;
        }
    }
};

int main()
{
    Tree<char> obj;
    if (obj.Root == NULL)
        cout << "Tree is empty!!";
    else
    {
        cout << "\nPreorder Traversal\t:\t";
        obj.preorder(obj.Root);
        cout << "\nInorder Traversal\t:\t";
        obj.inorder(obj.Root);
        cout << "\nPostorder Traversal\t:\t";
        obj.postorder(obj.Root);
    }
    return 0;
}