void i_arbsuma(node_arbreNari* n, node_arbreNari*& n_asum, int& sum) {
  if (n == NULL) {
    sum = 0;
  }
 
  else {
    sum = n->info;
    n_asum = new node_arbreNari;
    n_asum->seg = vector<node_arbreNari*>(n->seg.size());   //reservem n_seg.size() espai per al nostre node auxiliar
   
    for (int i = 0; i < int(n->seg.size()); ++i) {
      node_arbreNari* n_asum1 = NULL;
      int sum1;                //sum1 contindrà la info de cada node
      i_arbsuma(n->seg[i], n_asum1, sum1);
      sum += sum1;
      n_asum->seg[i] = n_asum1;
    }
    n_asum->info = sum;
  }
}
 
 
 
/* Pre: cert */
/* Post: asum és l'arbre suma del p.i. */
void arbsuma(ArbreNari& asum) {
  int sum;
  node_arbreNari* n_asum = NULL;
  i_arbsuma(this->primer_node, n_asum, sum);
 
  asum.primer_node = n_asum;
}
