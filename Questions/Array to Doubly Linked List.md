## Code
```cpp
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
#define lb cout << endl;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data, Node *next = NULL, Node *prev = NULL) : data(data), next(next), prev(prev) {};
};
Node *insertAtTail(Node *&tail, int val)
{
    Node *tt = new Node(val);
    tail->next = tt;
    tt->prev = tail;
    tail = tt;
    return tail;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v = {5, 3, 7, 9, 1};
    Node *head = new Node(v[0]);
    Node *tail = head;
    // cout << head->next << " " << head->prev << " " << head->data;
    for (int i = 1; i < v.size(); i++)
    {
        tail = insertAtTail(tail, v[i]);
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ", " << temp << endl;
        temp = temp->next;
    }
    return 0;
}
```