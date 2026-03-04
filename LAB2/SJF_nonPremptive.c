#include <stdio.h>
#include <stdlib.h>

typedef struct p {
    int id, at, bt, ct, wt, tat, done;
    struct p* next;
} p;

p* create(int id, int at, int bt) {
    p* n = (p*)malloc(sizeof(p));
    n->id = id; n->at = at; n->bt = bt; n->done = 0;
    n->next = NULL;
    return n;
}

void computeSJF(p* root, int n) {
    int count = 0, time = 0;
    while (count < n) {
        p *best = NULL, *temp = root;
        int min_bt = 1e9;
        while (temp) {
            if (temp->at <= time && !temp->done && temp->bt < min_bt) {
                min_bt = temp->bt;
                best = temp;
            }
            temp = temp->next;
        }
        if (!best) {
            time++;
        } else {
            best->ct = time + best->bt;
            best->tat = best->ct - best->at;
            best->wt = best->tat - best->bt;
            best->done = 1;
            time = best->ct;
            count++;
        }
    }
}

void display(p* root) {
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    while (root) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", root->id, root->at, root->bt, root->ct, root->tat, root->wt);
        root = root->next;
    }
}

int main() {
    int n, a, b;
    p *root = NULL, *tail = NULL;
    printf("Processes: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        p* nn = create(i + 1, a, b);
        if (!root) root = tail = nn;
        else { tail->next = nn; tail = nn; }
    }
    computeSJF(root, n);
    display(root);
    return 0;
}
