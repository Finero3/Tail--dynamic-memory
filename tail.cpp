#include <iostream>

using namespace std;

struct elem
{
    int key;
    elem* next;
}*first = NULL, * last = NULL;

int pop(int& n)
{
    elem* p;
    if (first) {
        p = first;
        n = first->key;
        first = first->next;
        if (first == NULL)
            last = first;
        delete p;
        return 1;
    }
    else {
        return 0;
    }
}

void push(int n)
{
    elem* p;
    p = last;
    last = new elem;
    last->key = n;
    last->next = NULL;
    if (p != NULL)
        p->next = last;
    else
        first = last;
}

int main()
{
    cout << "Input your lucky number- ";
    int lNum;
    cin >> lNum;
    int num, counter = 0;
    int flag = 0;
    while (cin >> num)
    {
        push(num);
        counter++;
    }
    cout << "Numbers are: \t";
    while (pop(num))
    {
        cout << num << "\t";
        if (num == lNum)
            flag = 1;
    }
    cout << endl << "Counter is: " << counter << endl;
    if (flag == 1)
    {
        cout << "Yes!" << endl;
    }
    else
        cout << "No!" << endl;
}