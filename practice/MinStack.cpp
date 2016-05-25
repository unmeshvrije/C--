#include<iostream>
#include<climits>
using namespace std;

class MinStack {

    private:

    struct StackNode {

      int data;

      StackNode* next;

      StackNode(int d):data(d) { next = NULL;}

    };

    

    StackNode *TOP = NULL;

    int prevMinimum;

    int minimum;

    int minCount;

public:



    MinStack() {

        TOP = NULL;

        prevMinimum = INT_MAX;

        minimum = INT_MAX;

        minCount = 0;

    }

    

    void push(int x) {

        StackNode *newnode = new StackNode(x);

        if (TOP == NULL) {
            TOP = newnode;
            prevMinimum = x;
            minimum = x;
            return;
        }
        
        if (x < minimum) {
            prevMinimum = minimum;
            minimum = x;
            minCount = 1;
        } else if (x == minimum) {
            minCount++;
        }

        newnode->next = TOP;
        TOP = newnode;
    }

    void display() {
      StackNode *temp = TOP;
      while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }

    void pop() {

        if (TOP == NULL) {
            return;
        }

        StackNode *temp = TOP;

        if (temp->data == minimum) {
            minCount--;
            if (minCount == 0) {
                minimum = prevMinimum;
                minCount = 1;
            }
        }
        TOP = TOP->next;
        delete(temp);
        temp = NULL;

    }

    int top() {
        if (TOP == NULL) {
            return -1;
        }
        return TOP->data;
    }



    int getMin() {

        return minimum;

    }

};

int main(int argc, char *argv[]) {
   MinStack ms;
   ms.push(2);
   ms.push(0);
   ms.push(3);
   ms.push(0);
   ms.display();

   cout << ms.getMin() << endl;
   ms.pop();
   ms.display();

   cout << ms.getMin() << endl;
   ms.pop();
   ms.display();

   cout << ms.getMin() << endl;
   ms.pop();
   ms.display();

   cout << ms.getMin() << endl;

   return 0;
}
