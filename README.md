# Algoritmos de Ordenação

Este projeto implementa três algoritmos de ordenação escolhidos para lidar com diferentes tipos de listas (ordenadas, aleatórias e inversamente ordenadas) de forma eficiente.

## Algoritmos utilizados

1. Shell Sort (sequência de Knuth)
Escolhido como o algoritmo mais versátil. Apresenta bom desempenho em listas ordenadas, desordenadas e inversamente ordenadas graças à sequência de incrementos de Knuth (h(i+1) = 3h(i) + 1), que reduz o número de comparações e trocas, mantendo o custo próximo de O(n¹·²⁵).

2. Quick Sort (partição de Hoare)
Utilizado por sua eficiência prática e bom desempenho em listas inversamente ordenadas. A partição de Hoare, que utiliza dois ponteiros (i e j), minimiza trocas desnecessárias e evita a degradação para O(n²) em muitos casos.

3. Quick Sort (pivô mediana de 3)
Implementado como uma variação adicional do Quick Sort para evitar os piores casos de desempenho. A escolha do pivô como a mediana entre o primeiro, o meio e o último elemento torna o algoritmo mais estável, especialmente em listas parcialmente ou inversamente ordenadas.

## Justificativa da ordem

1º – Shell Sort (Knuth): excelente desempenho em qualquer tipo de lista.

2º – Quick Sort (Hoare): mantém bom tempo de execução em listas inversas e grandes volumes de dados.

3º – Quick Sort (Mediana de 3): reforça a robustez contra casos extremos, garantindo equilíbrio no desempenho.
