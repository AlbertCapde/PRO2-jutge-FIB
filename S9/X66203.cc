#ifndef SOL_14_1
#define SOL_14_1

T maxim() const {
  // Pre: el p.i. no es vacío
  // Post: el resultado es el valor más grande del p.i.
  return maximo_node(primer_node)->info; 
}

static node_arbreNari* maximo_node(node_arbreNari *m) {
  // Pre: m no es NULL
  node_arbreNari *max = m; 
  int ari = (m->seg).size(); 
  for (int i = 0; i < ari; ++i) {
     if (m->seg[i] != NULL) { 
        node_arbreNari *max_i = maximo_node(m->seg[i]);
        if (max_i->info > max->info) max = max_i;
     }
  }
  return max;
}

#endif
