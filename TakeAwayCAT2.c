#include <stdio.h>
#include <stdlib.h>

struct tree 
{
 int val;
 struct tree *l;
 struct tree *r;
};

struct tree* mknode(int val) 
{
 struct tree* newN = malloc(sizeof(struct tree));
 if(newN==NULL){
  printf("err\n");
  exit(1);
 }
 newN->val = val;
 newN->l = NULL;
 newN->r = NULL;
 return newN;
}

int cnode(struct tree* n) 
{
 if(n==NULL){return 0;}
 int l = 0;
 if(n->l){ l = cnode(n->l); } 
 int r = 0;
 if(n->r != NULL){
  r = cnode(n->r);
 }
 return 1 + l + r;
}

struct tree* bigTree(struct tree* a, struct tree* b, struct tree* c)
{
 int na = cnode(a); int nb = cnode(b); int nc = cnode(c);
 printf("A nodes: %d\n", na);
 printf("B nodes: %d\n", nb);
 printf("C nodes: %d\n", nc);

 if(na>=nb && na>=nc)
 { 
	return a; 
 }
 else if(nb>=na && nb>=nc)
 { 
	return b;
 }
 else 
 {
	return c;
 }

}

void printTree(struct tree* head)
{
 if(head==NULL){return;}
 printTree(head->l);
 printf("%d ", head->val);
 printTree(head->r);
}

int main()
{
 struct tree* A = mknode(5);
 A->l = mknode(2);
 A->r = mknode(8);
 A->l->l = mknode(1); 

 struct tree* B = mknode(10);
 B->l = mknode(7);
 B->r = mknode(12);

 struct tree* C = mknode(3);
 C->l = mknode(2);
 C->r = mknode(4);
 C->r->r = mknode(6);
 C->r->l = mknode(5);

 struct tree* result = bigTree(A, B, C);

 printf("Biggest tree (in-order):\n");
 printTree(result);
 printf("\n");

 return 0;
}