#include <stdio.h>
#include <stdlib.h>

typedef struct p {
    int id, at, bt, rt, ct, wt, tat;
    struct p* next;
} p;

p* create(int id, int at, int bt) {
    p* n = (p*)malloc(sizeof(p));
    n->id = id; n->at = at; n->bt = bt; n->rt = bt;
    n->next = NULL;
    return n;
}

void computeSRTF(p* root, int n) {
    int completed = 0, time = 0, min_rt;
    p *best, *temp;

    while (completed < n) {
        best = NULL;
        min_rt = 1e9;
        temp = root;

        while (temp) {
            if (temp->at <= time && temp->rt > 0 && temp->rt < min_rt) {
                min_rt = temp->rt;
                best = temp;
            }
            temp = temp->next;
        }

        if (!best) {
            time++;
            continue;
        }

        best->rt--;
        time++;

        if (best->rt == 0) {
            completed++;
            best->ct = time;
            best->tat = best->ct - best->at;
            best->wt = best->tat - best->bt;
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
    computeSRTF(root, n);
    display(root);
    return 0;
}
