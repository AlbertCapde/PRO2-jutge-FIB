#ifndef SOL_X15014
#define SOL_X15014


public:

void arb_sumes(Arbre<int> &asum) const {
  /* Pre: cert */
  /* Post: l'arbre asum es l'arbre suma del p.i. */
  asum.primer_node = aux_sumas(primer_node);
}



private:

static node_arbre* aux_sumas(node_arbre* m) {
/* Pre: cierto */
/* Post: Si m es NULL, el resultado es NULL; en otro caso, m apunta al nodo 
raíz de una jerarquía de nodos que representa un árbol A, y n apunta al nodo 
raíz de una jerarquía de nodos que representa el árbol de sumas de A. */
   node_arbre *n;
   if (m == NULL) n = NULL;
   else {
      n = new node_arbre; 
      n->info = m->info;
      n->segE = aux_sumas(m->segE); 
      if (n->segE != NULL) n->info += (n->segE)->info; 
      n->segD = aux_sumas(m->segD); 
      if (n->segD != NULL) n->info += (n->segD)->info;
   }
   return n;
}

#endif
