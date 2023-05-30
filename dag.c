#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 50
#define MAX_EDGES 10

typedef struct Node {
    char filename[MAX_FILENAME_LEN];
    struct Node* edges[MAX_EDGES];
    int num_edges;
} Node;

void add_edge(Node* node, Node* edge) {
    if (node->num_edges >= MAX_EDGES) {
        printf("Error: maximum number of edges exceeded\n");
        exit(1);
    }
    node->edges[node->num_edges++] = edge;
}

void print_node(Node* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s\n", node->filename);
    for (int i = 0; i < node->num_edges; i++) {
        print_node(node->edges[i], depth + 1);
    }
}

int main() {
    Node root = {"root", {NULL}, 0};
    Node dir1 = {"dir1", {NULL}, 0};
    Node dir2 = {"dir2", {NULL}, 0};
    Node file1 = {"file1.txt", {NULL}, 0};
    Node file2 = {"file2.txt", {NULL}, 0};
    Node file3 = {"file3.txt", {NULL}, 0};
    Node file4 = {"file4.txt", {NULL}, 0};

    add_edge(&root, &dir1);
    add_edge(&root, &dir2);
    add_edge(&dir1, &file1);
    add_edge(&dir1, &file2);
    add_edge(&dir2, &file3);
    add_edge(&dir2, &file4);

    print_node(&root, 0);

    return 0;
}

