#include <iostream>
using namespace std;

class inventory
{
private:
    struct queueNode
    {
        int serialNum=0;
        int manufactDate;
        int lotNum;
        queueNode *next;
    };

    queueNode *front;
    queueNode *rear;

    int numItems;

public:
    //constructor
    inventory();

    //destructor
    ~inventory();

    void enQueue(int); // pushes value to top of queue
    void deQueue(int &); //removes value from top of queue
    bool isEmpty(); // checks if queue is empty
    bool isFull();// checks if queue is full
    void clear(); //clears queue
};

inventory::inventory()
{
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

inventory::~inventory()
{
    clear();
}

void inventory::enQueue(int num)
{
    queueNode *newNode = nullptr; // points to new node

    //allocate a new node and store a number there
    newNode = new queueNode;
    newNode->serialNum = num;
    newNode->next = nullptr;

    //if there are no nodes in the list, make newNode the first node
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }

    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    numItems++; //updates the number of items in the queue
}
void inventory::deQueue(int &num)
{
    queueNode *temp = nullptr;

    if (isEmpty())
    {
        cout<<"The queue has no values.\n";
    }
    else
    {
        num = front->serialNum; //removes value front the front of the queue and deletes it
        temp = front;
        front = front->next;
        delete temp;

        numItems--; //updates the amount of items in the queue

    }

}
bool inventory::isEmpty()
{
    bool status;

    if(numItems>0)
        status=false;

    else
        status=true;

    return status;
}

void inventory::clear()
{
    int value; //dummy variable for dequeue

    while(!isEmpty())
        deQueue(value);
}

int main()
{
    int catchVar;
    int serialNum;

    inventory queue;

    while(serialNum != 0)
        {
    cout<<"Please enter your serial number. Enter 0 to exit, or 1 to use the previously used serial number. : ";
    cin>>serialNum;

    if(serialNum == 0)
    {
     break;
    }

    else if (serialNum ==1)
    {
        queue.deQueue(serialNum);
        cout<<serialNum<<" used."<<endl;
    }

    else
    {
        queue.enQueue(serialNum);
        cout<<"Queuing last entered serial number: ";

        cout<<serialNum<<endl;;
    }
        }
    return 0;
}
