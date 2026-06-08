# Representações de Grafos

As **representações de grafos** são formas diferentes de armazenar e manipular um grafo na memória. A escolha depende da **densidade do grafo**, do **algoritmo utilizado** e das **operações mais frequentes**.

---

# 1. Matriz de Adjacência

Representa o grafo por uma matriz `V × V`.

\[
M[i][j]=
\begin{cases}
1 & \text{se existe aresta}\\
0 & \text{caso contrário}
\end{cases}
\]

Exemplo:

```text
A → B
↓
C
```

Matriz:

```text
    A B C
A [ 0 1 1 ]
B [ 0 0 0 ]
C [ 0 0 0 ]
```

Estrutura em C:

```c
int M[V][V];
```

### Complexidade

| Operação | Custo |
|---|---|
| Verificar aresta | O(1) |
| Inserir aresta | O(1) |
| Buscar vizinhos | O(V) |
| Espaço | O(V²) |

### Uso
- Grafos densos
- Floyd-Warshall
- Fecho transitivo

---

# 2. Lista de Adjacência

Cada vértice armazena uma lista de vizinhos.

Exemplo:

```text
A → B → C
B →
C →
```

Estrutura:

```c
struct No {
    int destino;
    struct No *prox;
};

struct No *lista[V];
```

### Complexidade

| Operação | Custo |
|---|---|
| Inserir | O(1) |
| Buscar aresta | O(grau) |
| Espaço | O(V+E) |

### Uso
- Grafos esparsos
- BFS
- DFS
- Dijkstra

---

# 3. Lista de Arestas (Edge List)

Armazena somente as arestas.

Exemplo:

```text
(A,B)
(A,C)
(C,D)
```

Estrutura:

```c
struct Aresta {
    int origem;
    int destino;
};
```

### Complexidade

| Operação | Custo |
|---|---|
| Inserção | O(1) |
| Consulta | O(E) |
| Espaço | O(E) |

### Uso
- Entrada de dados
- Kruskal

---

# 4. Matriz de Incidência

Linhas → vértices  
Colunas → arestas

Exemplo:

```text
A--B
|
C
```

```text
      e1 e2
A      1  1
B      1  0
C      0  1
```

Dimensão:

\[
V \times E
\]

### Espaço

\[
O(VE)
\]

### Uso
- Fluxo em redes
- Álgebra de grafos

---

# 5. Lista de Incidência

Cada vértice mantém referências para arestas incidentes.

Exemplo:

```c
vertice[3]:
→ e1
→ e7
→ e12
```

### Uso
- Grafos com muitas propriedades nas arestas

---

# 6. CSR — Compressed Sparse Row

Compactação por linhas para matrizes esparsas.

Vetores:

```text
values
col_index
row_ptr
```

Exemplo:

```text
0 1 0 1
1 0 1 0
```

Representação:

```text
values    [1 1 1 1]
col_index [1 3 0 2]
row_ptr   [0 2 4]
```

### Espaço

\[
O(V+E)
\]

### Uso
- Grafos grandes
- GPU
- Multiplicação de matrizes esparsas

---

# 7. CSC — Compressed Sparse Column

Compactação por colunas.

Vetores:

```text
values
row_index
col_ptr
```

### Espaço

\[
O(V+E)
\]

### Uso
- PageRank
- Álgebra linear

---

# 8. COO — Coordinate Format

Armazena coordenadas explícitas.

```text
row[]
col[]
value[]
```

Exemplo:

```text
(0,1)
(0,3)
(1,0)
```

### Espaço

\[
O(E)
\]

### Uso
- Construção incremental
- Conversão para CSR/CSC

---

# 9. DOK — Dictionary of Keys

Tabela hash.

```text
(0,2)=1
(3,1)=1
```

### Espaço

\[
O(E)
\]

### Uso
- Inserções frequentes

---

# 10. LIL — List of Lists

Cada linha possui sua própria lista.

Exemplo:

```text
0 → [1,3]
1 → [0]
```

### Espaço

\[
O(V+E)
\]

### Uso
- Construção dinâmica

---

# 11. ELLPACK (ELL)

Regulariza a matriz.

Exemplo:

```text
col=
[1 3]
[0 2]
```

### Espaço

\[
O(V \times grau_{max})
\]

### Uso
- GPU
- CUDA

---

# 12. Representação Ortogonal (Cross Linked)

Cada aresta participa simultaneamente da lista de origem e destino.

```text
→ direita
↓ baixo
```

### Uso
- Grafos direcionados dinâmicos

---

# 13. Forward Star

Muito utilizada em programação competitiva.

Estrutura:

```c
head[]
to[]
next[]
```

### Espaço

\[
O(V+E)
\]

### Uso
- Inserção rápida
- Algoritmos competitivos

---

# 14. Compressed Adjacency Array

Versão vetorizada da lista de adjacência.

```text
adj[]
offset[]
```

### Espaço

\[
O(V+E)
\]

### Uso
- Sistemas distribuídos

---

# 15. Estruturas Híbridas

Combinações de representações.

Exemplos:

- Matriz + Lista
- CSR + Lista
- Hash + Vetores
- Bitmap + Lista

### Uso
- Bancos de grafos
- Sistemas de navegação

---

# Resumo

| Representação | Espaço | Busca |
|---|---:|---:|
| Matriz adjacência | O(V²) | O(1) |
| Lista adjacência | O(V+E) | O(grau) |
| Lista de arestas | O(E) | O(E) |
| Matriz incidência | O(VE) | O(E) |
| CSR | O(V+E) | O(grau) |
| CSC | O(V+E) | O(grau) |
| COO | O(E) | O(E) |
| DOK | O(E) | O(1) médio |
| LIL | O(V+E) | O(grau) |
| ELL | O(V·grau_max) | O(1) |

---

## Organização mental

### Clássicas
- Matriz de Adjacência
- Lista de Adjacência
- Lista de Arestas

### Matrizes Esparsas
- CSR
- CSC
- COO
- DOK
- LIL
- ELL

### Alto desempenho
- Forward Star
- Compressed Adjacency Array

### Teóricas
- Incidência
- Ortogonal