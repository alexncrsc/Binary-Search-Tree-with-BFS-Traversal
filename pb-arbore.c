#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <fcntl.h> 

struct nod { 
    int id; 
    struct nod *st, *dr; 
};

struct nod *nod_nou(int id) {
    struct nod *temp = (struct nod*)malloc(sizeof(struct nod));
    if (temp == NULL) {
        perror("malloc");
        return NULL;
    }
    temp->id = id;
    temp->st = temp->dr = NULL;
    return temp;
}

struct nod *inserare(struct nod *nod, int id) {
    if (nod == NULL) {
        return nod_nou(id);
    }

    if (id < nod->id) {
        nod->st = inserare(nod->st, id);
    } else if (id > nod->id) {
        nod->dr = inserare(nod->dr, id);
    }

    return nod;
}

void sterge_arbore(struct nod *head) { 
    if (head) { 
        sterge_arbore(head->st); 
        sterge_arbore(head->dr); 
        free(head); 
    } 
}


int cautare_bfs(struct nod* rad) { 
    if(rad != NULL) { 
        struct nod* temp; 

        int d[2]; 
        if (pipe(d) == -1) {
            perror("pipe");
            return 1;
        }

        fcntl(d[0], F_SETFL, O_NONBLOCK); 
        write(d[1], &rad, sizeof(rad)); 

        while (read(d[0], &temp, sizeof(temp)) > 0) { 
            printf("%d ", temp->id); 

            if(temp->st != 0) {
                write(d[1], &temp->st, sizeof(temp->st));
            } 

            if(temp->dr != 0) {
                write(d[1], &temp->dr, sizeof(temp->dr)); 
            }   
        } 
        close(d[0]); 
        close(d[1]); 
    }
    return 0;
} 

int main() { 
    struct nod *rad = NULL; 
    int n, id; 
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++) { 
        scanf("%d", &id); 
        rad = inserare(rad, id);
    } 
    cautare_bfs(rad); 
    printf("\n"); 
    sterge_arbore(rad);
    return 0; 
}
