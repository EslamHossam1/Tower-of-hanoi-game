#include <iostream>
#include <iomanip>
using namespace std;

class tower
{
private:
    char data[20];

public:
    int top;
    tower();
    char peak();
    void reset();
    void push(char);
    char pop();
    void display(int);
};
tower::tower()
{
    top = 0;
}
void tower::reset()
{
    top = 0;
}
void tower::push(char x)
{
    if (top < 20)
    {
        data[top] = x;
        top++;
    }
}
char tower::pop()
{
    top--;
    return data[top];
}
char tower::peak()
{
    char x = top - 1;
    return data[x];
}
void tower::display(int tag)
{
    int i;
    cout << "---------------------------------------" << endl;
    cout << "  " << tag + 1 << " |";
    for(int i = 0; i < top; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
