
21PD38 - VAMSI KRISHNA U <21pd38@psgtech.ac.in>
Jun 20, 2022, 1:23 PM
to me

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// A Tree node
struct Node
{
char ch;
int freq;
Node *left, *right;
};

//Create a new node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
Node* node = new Node();

    node->ch = ch;
node->freq = freq;
node->left = left;
node->right = right;

    return node;
}

// Comparing objects and returning the node with least frequency
struct compare
{
bool operator()(Node* l, Node* r)
{
// lowest frequency has the highest priority
return l->freq > r->freq;
}
};

// traversing the Huffman Tree and storing its codes
void encode(Node* root, string str, unordered_map<char,string> &huffmanCode)
{
if (root == nullptr)
return;

// found a leaf node
if (!root->left && !root->right)
    {
huffmanCode[root->ch] = str;
}
    encode(root->left, str + "0", huffmanCode);
encode(root->right, str + "1", huffmanCode);
}

// decoding the encoded string
// traversing from root to leaf node
void decode(Node* root, int &index, string str)
{
if (root == nullptr)
    {
return;
}

// checking for leaf node
if (!root->left && !root->right)
{
cout << root->ch;
return;
}

index++;

if (str[index] =='0')
decode(root->left, index, str);
else
decode(root->right, index, str);
}

// Building Huffman Tree and decode given input text
void buildHuffmanTree(string text)
{
// counting the frequency of each character and alloting it in unordered map
unordered_map<char, int> freq;
for (char ch: text)
    {
freq[ch]++;
}

// Create a priority queue to store nodes
priority_queue<Node*, vector<Node*>, compare> pq;

// Create a leaf node for each character and add it to the priority queue.
for (auto pair: freq)
    {
pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
}

// do till number of nodes is 1
// if number of nodes = 1, then push the next least frequency element
while (pq.size() != 1)
{
// Remove the two nodes
Node *left = pq.top(); pq.pop();
Node *right = pq.top(); pq.pop();

// Create a new node with current left and right as children
// also new node frequency = sum of the two children frequency
int sum = left->freq + right->freq;
pq.push(getNode('\0', sum, left, right));
}

// top = current root
Node* root = pq.top();

// traversing the Huffman Tree and storing its Codes
unordered_map<char, string> huffmanCode;
encode(root, "", huffmanCode);

cout << "Huffman Codes are :\n" << '\n';
for (auto pair: huffmanCode)
    {
cout << pair.first << " " << pair.second << '\n';
}

cout << "\nOriginal string was :\n" << text << '\n';

// printing encoded string
string str = "";
for (char ch: text)
    {
str += huffmanCode[ch];
}

cout << "\nEncoded string is :\n" << str << '\n';

// traversing the tree and decoding the encoded string
int index = -1;
cout << "\nDecoded string is: \n";
while (index < (int)str.size() - 2)
    {
decode(root, index, str);
}
}

// Huffman coding algorithm
int main()
{
    cout<<"/*---------------------------------------------------------------------*/"<<endl;
    cout<<"/*-=-=-=-=-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-=-=-=-=-*/"<<endl;
    cout<<"/*-=-=-=-x                                                     x-=-=-=-*/"<<endl;
    cout<<"/*-=-=-=-x                                                     x-=-=-=-*/"<<endl;
    cout<<"/*-=-=-=-x       DATA STRUCTURE PACKAGE (2ND SEMESTER)         x-=-=-=-*/"<<endl;
    cout<<"/*-=-=-=-x                                                     x-=-=-=-*/"<<endl;
    cout<<"/*-=-=-=-x                                                     x-=-=-=-*/"<<endl;
    cout<<"/*-=-=-=-=-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-=-=-=-=-*/"<<endl;
    cout<<"/*---------------------------------------------------------------------*/"<<endl;
    cout<<"/*||                                                                 ||*/"<<endl;
    cout<<"/*||                                                                 ||*/"<<endl;
    cout<<"/*||             Members : 1) Kaif Shaheem . J   (21pd16)            ||*/"<<endl;
    cout<<"/*||                       2) Vamsi Krishna . U  (21pd38)            ||*/"<<endl;
    cout<<"/*||                                                                 ||*/"<<endl;
    cout<<"/*||              Topic : Huffman coding (encoding and decoding)     ||*/"<<endl;
    cout<<"/*||                                                                 ||*/"<<endl;
    cout<<"/*||                                                                 ||*/"<<endl;
    cout<<"/*---------------------------------------------------------------------*/"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

string text = "Psg college of technology is in coimbatore";

buildHuffmanTree(text);

return 0;
}
