#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* name;
    int isDirectory;
    struct Node** edges;
    int numEdges;
} Node;

Node* createNode(char* name, int isDirectory, int numEdges) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->name = name;
    node->isDirectory = isDirectory;
    node->numEdges = numEdges;
    node->edges = (Node**)malloc(numEdges * sizeof(Node*));
    return node;
}

void addEdge(Node* node, Node* edge) {
    node->edges[node->numEdges++] = edge;
}

void traverse(Node* node, int depth) {
    for(int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s\n", node->name);
    for(int i = 0; i < node->numEdges; i++) {
        traverse(node->edges[i], depth+1);
    }
}

int main() {
    Node* root = createNode("/", 1, 2);
    Node* usr = createNode("usr", 1, 2);
    Node* bin = createNode("bin", 1, 1);
    Node* lib = createNode("lib", 1, 1);
    Node* file1 = createNode("file1.txt", 0, 0);
    Node* file2 = createNode("file2.txt", 0, 0);
    Node* file3 = createNode("file3.txt", 0, 0);

    addEdge(root, usr);
    addEdge(usr, bin);
    addEdge(usr, lib);
    addEdge(bin, file1);
    addEdge(lib, file2);
    addEdge(root, file3);

    traverse(root, 0);

    return 0;
}

