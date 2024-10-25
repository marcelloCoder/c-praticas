/*
1. Bubble Sort (Ordenação por bolha)
Estabilidade: Sim, é um algoritmo estável. Elementos com valores iguais mantêm a sua ordem original.
Complexidade de comparações:
Melhor caso (já ordenado): O(n) — apenas uma passada para verificar que o array está ordenado.
Pior caso: O(n²) — ocorre quando o array está ordenado de forma inversa.
Complexidade de movimentações:
O(n²) no pior caso, pois envolve trocas repetidas.
Vantagens:

Simples de implementar e entender.
Desvantagens:

Ineficiente para grandes conjuntos de dados.
2. Selection Sort (Ordenação por seleção)
Estabilidade: Não, não é estável, pois pode trocar elementos com o mesmo valor.
Complexidade de comparações:
O(n²) no melhor e pior caso — sempre faz n comparações para cada elemento.
Complexidade de movimentações:
O(n) trocas no pior caso (troca cada elemento ao menos uma vez).
Vantagens:

Simples de implementar.
Faz um número mínimo de trocas (no máximo n-1 trocas).
Desvantagens:

Mesmo para arrays já ordenados, o tempo de execução não melhora.
3. Insertion Sort (Ordenação por inserção)
Estabilidade: Sim, é estável, pois elementos iguais mantêm sua ordem relativa.
Complexidade de comparações:
Melhor caso (quase ordenado): O(n) — apenas n-1 comparações.
Pior caso: O(n²) — quando o array está em ordem inversa.
Complexidade de movimentações:
O(n²) no pior caso, pois cada inserção envolve deslocar todos os elementos à frente.
Vantagens:

Bom desempenho em arrays pequenos ou parcialmente ordenados.
Simples de implementar.
Desvantagens:

Ineficiente em grandes conjuntos de dados desordenados.
4. Merge Sort (Ordenação por intercalação)
Estabilidade: Sim, é estável, pois não altera a ordem dos elementos iguais.
Complexidade de comparações:
Melhor caso: O(n log n).
Pior caso: O(n log n) — sempre divide o array ao meio e faz comparações para intercalar.
Complexidade de movimentações:
O(n log n) — cada passo de divisão e intercalamento envolve movimentações de elementos.
Vantagens:

Estável e tem tempo de execução garantido de O(n log n), mesmo no pior caso.
Desvantagens:

Usa O(n) de espaço extra para intercalar as sublistas.
É mais complexo de implementar.
5. Quick Sort (Ordenação rápida)
Estabilidade: Não, não é estável, pois a troca de elementos pode alterar a ordem relativa dos elementos iguais.
Complexidade de comparações:
Melhor caso (pivô ideal): O(n log n).
Pior caso (pivô ruim, como em uma lista já ordenada): O(n²).
Complexidade de movimentações:
O(n log n) no melhor caso; O(n²) no pior caso.
Vantagens:

Excelente desempenho médio com O(n log n).
Em geral, mais rápido que o Merge Sort, pois a constante associada é menor.
Desvantagens:

Não é estável.
O pior caso (pivô mal escolhido) tem desempenho O(n²), mas pode ser mitigado com técnicas como a escolha de pivôs aleatórios.
6. Heap Sort (Ordenação por montes)
Estabilidade: Não, não é estável, pois a operação de heapificação pode alterar a ordem de elementos iguais.
Complexidade de comparações:
O(n log n) no melhor e no pior caso — envolve a construção do heap e a remoção dos maiores elementos.
Complexidade de movimentações:
O(n log n) no pior caso.
Vantagens:

Tempo garantido de O(n log n).
Não necessita de espaço extra além de O(1) (ordenando no local).
Desvantagens:

Não é estável.
Mais difícil de implementar do que algoritmos como Insertion Sort ou Selection Sort.
*/