#include <bits/stdc++.h>
using namespace std;

// Function to print Huffman codes from the root of the Huffman Tree
void printCodes(vector<int>& left, vector<int>& right, vector<char>& chars, int node, string code)
{
    if (left[node] == -1 && right[node] == -1)   // Leaf node
    {
        cout << chars[node] << ": " << code << endl;
        return;
    }
    if (left[node] != -1)
        printCodes(left, right, chars, left[node], code + "0");
    if (right[node] != -1)
        printCodes(left, right, chars, right[node], code + "1");
}

// Function to build Huffman Tree and generate codes
void huffmanCoding(unordered_map<char, int>& freq)
{
    // Check for empty input
    if (freq.empty())
    {
        cout << "Frequency map is empty. Cannot build Huffman Tree." << endl;
        return;
    }

    // Handle edge case with a single character
    if (freq.size() == 1)
    {
        cout << freq.begin()->first << ": 0" << endl;
        return;
    }

    int n = freq.size();

    // Priority queue to store (frequency, index)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Vectors to store characters, frequencies, and tree structure
    vector<char> chars(2 * n - 1);
    vector<int> freqArr(2 * n - 1);
    vector<int> left(2 * n - 1, -1);
    vector<int> right(2 * n - 1, -1);

    // Initialize leaf nodes
    int index = 0;
    for (auto& entry : freq)
    {
        chars[index] = entry.first;
        freqArr[index] = entry.second;
        minHeap.push({entry.second, index});
        index++;
    }

    // Build the Huffman Tree
    int internalNode = n; // Start adding internal nodes
    while (minHeap.size() > 1)
    {
        int leftNode = minHeap.top().second;
        minHeap.pop();
        int rightNode = minHeap.top().second;
        minHeap.pop();

        // Create internal node
        freqArr[internalNode] = freqArr[leftNode] + freqArr[rightNode];
        left[internalNode] = leftNode;
        right[internalNode] = rightNode;

        // Add the internal node to the priority queue
        minHeap.push({freqArr[internalNode], internalNode});
        internalNode++;
    }

    // Root of the Huffman Tree
    int root = minHeap.top().second;

    // Print the Huffman codes
    printCodes(left, right, chars, root, "");
}

int main()
{
    unordered_map<char, int> freq = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};
    huffmanCoding(freq);
    return 0;
}
