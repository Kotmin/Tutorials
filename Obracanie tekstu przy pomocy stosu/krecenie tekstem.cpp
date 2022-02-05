#include <iostream>
#include <fstream>
#include <string>
#include<sstream>


using namespace std;

struct element
{
    char data;
    element * next = nullptr;
};


void invertWords(string path, element* &stack);


void push(element* &stack, char value);
void pop(element* &stack);
bool isEmpty(element* stack);
char top(element* stack);
void deletewholestos(element* &stack);


int main()
{
    element* stack_top = nullptr;

    invertWords("source.txt",stack_top);
    return 0;
}


void invertWords(string path, element* &stack)
{


    ifstream source(path);
    ofstream target("inverted_"+path);
    char znak;
    string pom;



while(getline(source,pom,'\n')){

    stringstream ss(pom);


      while(getline(ss,pom,' '))
      {
          deletewholestos(stack);

          for(int i=0;i<pom.length();i++){
            push(stack,pom[i]);
          }
          while(!(isEmpty(stack)))
          {
              znak=top(stack);
              pop(stack);
              target <<znak;
          }
        target <<' ';
      }
    target<<'\n';

}

    source.eof();
    source.close();

    target.flush();
    target.close();
}


void push(element* &stack, char value)
{
    element* el = new element;
    el->data = value;
    el->next = stack;
    stack = el;
}

void pop(element* &stack)
{
if(!(isEmpty(stack)))
{


        element* temp= stack;
        stack = stack->next;
        delete temp;
}
else
    cout<<"\n Nie mozna usunac kolejnego elementu stos jest juz pusty\n";
}

bool isEmpty(element* stack)
{
    return stack == nullptr;
}

char top(element* stack)
{
    return stack->data;
}

void deletewholestos(element* &stack)
{
    while(!(isEmpty(stack)))
    {
        pop(stack);
    }
    //cout<<"\nWyczyscilem stosa\n";
}
