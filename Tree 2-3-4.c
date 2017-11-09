void insert(int value){
  node* current = root;                           // Nó atual será a raiz
  while(current){                                 // Enquanto o nó atual nao for nulo
    if(is_full(current)){                         // Se o no estiver cheio, entra na função split
      split(current);                             // e é dividido
      current = get_parent(current);              // Após a divisão, pega o novo parent do nó atual
      current = get_next_child(current, value);   // e procura no seu filho, para ver se é uma folha
    } else if(is_leaf(current)){                  // Se nao estiver cheio, checa se é uma folha
      break;                                      // Se for uma folha ótimo, podemos adicionar
    } else{                                       // Se for um nó interno, procura se seu filho é folha
      current = get_next_child(current, value);
    }
    
    insert_item(current, value);                  // Quando uma folha for encontrada, adicionamos
  }
}

//---------------------------------------------------------------------------------------------------------

int insert_item(node *node, int value){ 	// Assume que o nó não esteja completo
  (node->size)++;                        	// Aumenta a quantidade
  
  for(int i = 1; i >= 0; i--){          	// Começa à direita do nó, na segunda posição
    if(node->items[i] != NULL){         	// se não for nulo 
      int cur_item = node->items[i];    	// verifica se ele é menor que o valor da posição atual
      if(value < cur_item){
        node->items[i+1] = cur_item;    	// Se for desloca o valor atual para a prox posição, e adiciona
      } else{                       	    // se não, ele é maior, e é adicionado na prox posição 
        node->items[i+1] = value;	       	// e retornar
        return i+1;
      }                                 	// Ou repete o processo
    }
  }                                      	// Se todo o loop foi percorrido significa que 'value'
    node->items[0] = value;             	// é o menor valor de todos, então adicionamos no inicio
    return 0;
}

//---------------------------------------------------------------------------------------------------------

void split(node *cur_node){                                   	// Divisao do nó
  int itemB, itemC, itemIndex;                                	//
  node  *child2, *child3, *new_right;                         	//
                                                              	//
  itemC = remove_item(cur_node);                              	// Remove o ultimo item do nó e armazena
  itemB = remove_item(cur_node);                              	// Remove o segundo item do nó e armazena
  child2 = disconnect_child(cur_node, 2);                     	// Desconecta o penultimo e ultimo nós e 
  child3 = disconnect_child(cur_node, 3);                     	// armazena
                                                              	//
  if(cur_node == root){                                       	// Se o nó atual for a raiz
    node *new_root;                                           	// criamos uma nova raiz 
    cur_node->parent = new_root;                              	// e definimos ela como novo pai de nó atual
    connect_child(new_root, 0, cur_node);                     	// dps conectamos o nó atual na nova raiz
  }                                                           	//
    itemIndex = insert_item(cur_node->parent, itemB);         	// Pegamos a posição onde o nó B foi adicionado
    int n = get_num_items(cur_node->parent);                  	// Pegamos o numeros de itens que tem no nó pai
                                                              	//
    for(int i = n - 1; i > itemIndex; i--){                   	// Da direita pra esquerda deslocamos as ligaçoes
      node *temp = disconnect_child(cur_node->parent, i);     	// Desconecta o filho da posição
      connect_child(cur_node->parent, i + 1, temp);           	// e conecta na prox
    }                                                         	//
                                                              	//
    connect_child(cur_node->parent, itemIndex + 1, new_right);	// Adiciona um novo nó que sera a direita do no atual
                                                              	//
    insert_item(new_right, itemC);                            	// Inserimos o valor C no nó direita
    connect_child(new_right, 0, child2);                      	// e adicionamos os filhos dele
    connect_child(new_right, 1, child3);                      	// pode ser null tbm
  
}
