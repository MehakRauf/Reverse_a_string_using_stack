#include <iostream>
using namespace std;
//struct for stack
struct stack
{
    char c1;
    struct stack *next;
    struct stack *prev;
};
struct stack *top = NULL;

void push(string str1, int length1)
{
    //itearating through the word
    for (int i = 0; i < length1; i++)
    {
        //storing every character
        char c=str1[i];
        //memory allocation 
        struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
        temp->c1 = c;
        temp->next = NULL;
        //chcking if stack is empty
        if (top == NULL)
        {
            top = temp;
        }
        //if not empty then adding it on top and updating the top
        else
        {
            //adjusting links
            temp->next = top;
            top->prev = temp;
            top = temp;
        }
    }
}
//to pop a character form stack
void pop()
{
    //lifo
    struct stack *curr = top;
    top = top->next;
    free(curr);
}
//to print the stack characters
void print()
{
    if (top == NULL)
    {
        cout << "List is underflow." << endl;
    }
    struct stack *curr = top;
    while (curr != NULL)
    {
        cout << curr->c1 << " ";
        curr = curr->next;
    }
}
int main()
{
    //taking the string as input
    string str1;
    cout << "Enter the sentence:";
    cin>>str1;
    push(str1,str1.length());
    print();
}