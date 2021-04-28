#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node *next;     //v sture lahko vstavljamo razlicneste podatkov kot npr kazalec na druge strukture   
} node;
//node lahko uporabljam kot ime tipa te strukture                      

node* inserta(int n, node *lst) {
    node* l = (node*) malloc (sizeof(node));
    l -> value = n;          //vrednost v novo ustvarjeni skatli
    l -> next = lst;         //sosednja skatla na katero kaze
    return l;               //vrnemo kazalec na novo skatlo
}

//dodajanje elementa na konec verige
node* insertz_itr(int n, node *lst) {
    // if (lst == NULL) {
    //     lst = (node*) malloc (sizeof(node));
    //     lst->value = n;
    //     lst->next = NULL;
    //     return lst;
    // }
    // else {
    //     node *l = lst;
    //     while (l->next != NULL) {
    //         l = lst->next;
    //     }
    //     l->next = (node*)malloc (sizeof(node));
    //     l = l->next;
    //     l -> value = n;
    //     l -> next = NULL;
    //     //vrnemo kazalec na zacetno vozlisce (l je kazalec na zadnje vozlisce)
    //     return lst;
    // }
    node **l = &lst;
    while (*l != NULL) 
        l = &((*l)->next);
    // l sedaj kaze na neko komponento next, ki hrani vrednost NULL
    // (*l) je ta komponenta next, ki hrani vrednost NULL
    (*l) = (node*) malloc (sizeof(node));
    (*l)->value = n;
    (*l)->next = NULL;
    return lst;
}

node *insertz_rek(int n, node *lst) 
{
    if (lst == NULL) {
        lst = (node*) malloc (sizeof(node));
        lst->value = n;
        lst->next = NULL;
        return lst;
    }
    else 
        lst -> next = insertz_rek(n, lst->next);
        return lst;
}
void delete_all_rek_ (node **lst) {
    if (*lst == NULL)
        return;
    delete_all_rek_(&((*lst)->next));
    free (*lst);
    *lst = NULL;
}

void delete_all_rek(node *lst) {
    if (lst == NULL)
        return;
    delete_all_rek(lst->next);
    printf("DEL: %d\n", lst->value);
    free(lst);
}

void print_itr(node *lst) {
    node *l = lst;
    while (l != NULL) {
        printf("%d ", l-> value);
        l = l -> next;
    }
    printf("\n");
}

void print_rek(node *lst) {
    if (lst == NULL)
        printf("NULL\n");
    else {
        printf("%d -> ", lst->value);
        print_rek(lst->next);
    }    
}

//  node* find_node(int n, node *lst));
//  bool exists (int n, node *lst)
//  node* reverse(node *lst)
//  node* delete(int n, node* lst)


int main()
{
    node* l = NULL;
    l = inserta(2, l);  // v seznam dodamo 2, njen sosed bo kazalec l;
    l = inserta(5, l);
    l = inserta(6, l);
    print_rek(l);   // 6 -> 5 -> 2 -> NULL

    node* l2 = l;
    

    l = insertz_rek(9, l);  
    l = insertz_rek(123, l);
    l = insertz_rek(18, l);
    print_rek(l);


    //delete_all_rek(l);
    delete_all_rek_(&l);

    // l = NULL (zaradi delete_all_rek_)
    // l2 != NULL (o njem delete_all_rek_ ne ve nicesar)
    print_itr(l2);  // tezave Bostjan Slivko nam je fkradel odmor :)

    return 0;
}