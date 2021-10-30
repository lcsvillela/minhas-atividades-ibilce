int avl_insert ( AVL_Tree **tree, AVL_Node *pai, AVL_Node **node, void *info ) 
{    
    AVL_Node *novo;
    int aux;
    
    if ( *tree == NULL ) return -1;
    if ( *node == NULL ) 
    // Se for o local correto para a inserção
    {
        novo = ( AVL_Node * ) malloc ( sizeof ( AVL_Node ));
        if ( novo == NULL ) return -1;
        novo->info  = info;
        novo->bal   = 0;
        novo->pai   = pai;
        novo->esq   = NULL;
        novo->dir   = NULL;
        
        *node = novo;
        (*tree)->num_nodes++;
        return 1;
    }
    
    /* 
     *  Procura o local apropriado. Na volta da pilha do processador, o 
     *  algoritmo vai atualizando o fator de balanceamento de cada nó. 
     *  São feitas rotações, se necessárias, para que a árvore se rebalanceie.
     */
     
    if ( (*tree)->compara_info( info, (*node)->info ) == +1 ) {
    
        aux = avl_insert ( tree, *node, &((*node)->dir), info );
        if ( aux != 1 ) return 0;
        
        if ( ++((*node)->bal) == 2 ) {
            if ( (*node)->dir->bal == 1 ) {
                *node = rotacao_esquerda ( *node );
                return 0;
            }
            (*node)->dir = rotacao_direita ( (*node)->dir );
            *node = rotacao_esquerda ( *node );
            
            return 0;
        }
        
        return ( (*node)->bal == 0 )? 0: 1;  
    }
    
    if ( (*tree)->compara_info( info, (*node)->info ) == -1 ) {
        
        aux = avl_insert ( tree, *node, &((*node)->esq), info );
        if ( aux != 1 ) return 0;
        
        if ( --((*node)->bal) == -2 ) {
            if ( (*node)->esq->bal == -1 ) {
                *node = rotacao_direita ( *node );
                return 0;
            }
            (*node)->esq = rotacao_esquerda ( (*node)->esq );
            *node = rotacao_direita ( *node );
            
            return 0;
        }
        
        return ( (*node)->bal == 0 )? 0: 1;        
    }
    
    return 0;
}