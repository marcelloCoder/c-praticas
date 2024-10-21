/*P13) Faça um teste de mesa com cada método de ordenação estudado até o momento,
utilizando as seguintes sequências de dados de entrada:

a) 2, 4, 6, 8, 10, 12
b) 11, 9, 7, 5, 3, 1
c) 5, 7, 2, 8, 1, 6
d) 2, 4, 6, 8, 10, 12, 11, 9, 7, 5, 3, 1
e) 2, 4, 6, 8, 10, 12, 1, 3, 5, 7, 9, 11
f) 8, 9, 7, 9, 3, 2, 3, 8, 4, 6
g) 89, 79, 32, 38, 46, 26, 43, 38, 32, 79

a) Bubble Sort Entrada: 2, 4, 6, 8, 10, 12

Passo	Array
1	2, 4, 6, 8, 10, 12
2	2, 4, 6, 8, 10, 12
3	2, 4, 6, 8, 10, 12
4	2, 4, 6, 8, 10, 12
5	2, 4, 6, 8, 10, 12
Resultado final: 2, 4, 6, 8, 10, 12

b) Selection Sort Entrada: 11, 9, 7, 5, 3, 1

Passo	Array
1	1, 9, 7, 5, 3, 11
2	1, 3, 7, 5, 9, 11
3	1, 3, 5, 7, 9, 11
4	1, 3, 5, 7, 9, 11
5	1, 3, 5, 7, 9, 11
Resultado final: 1, 3, 5, 7, 9, 11

c) Insertion Sort Entrada: 5, 7, 2, 8, 1, 6

Passo	Array
1	5, 7, 2, 8, 1, 6
2	2, 5, 7, 8, 1, 6
3	1, 2, 5, 7, 8, 6
4	1, 2, 5, 6, 7, 8
Resultado final: 1, 2, 5, 6, 7, 8

d) Merge Sort Entrada: 2, 4, 6, 8, 10, 12, 11, 9, 7, 5, 3, 1

Divida o array em partes até que cada subarray tenha 1 elemento.
Intercale as partes:
Intercalando: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
Resultado final: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12

e) Quick Sort Entrada: 2, 4, 6, 8, 10, 12, 1, 3, 5, 7, 9, 11

Escolha um pivô (por exemplo, 2), divida em menores e maiores.
Recursivamente aplique a mesma lógica.
Resultado final: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12

f) Heap Sort Entrada: 8, 9, 7, 9, 3, 2, 3, 8, 4, 6

Construa um heap máximo.
Remova o elemento do heap e coloque-o no final da lista.
Resultado final: 2, 3, 3, 4, 6, 7, 8, 8, 9, 9

g) Counting Sort (aplicável a este caso) Entrada: 89, 79, 32, 38, 46, 26, 43, 38, 32, 79

Crie um array de contagem baseado no valor máximo.
A partir da contagem, reconstrua o array ordenado.
Resultado final: 26, 32, 32, 38, 38, 43, 46, 79, 79, 89

*/
