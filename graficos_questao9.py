import matplotlib.pyplot as plt


# Tamanhos dos vetores utilizados nos testes
tamanhos = [5000, 50000, 500000]


# =========================================================
# MELHOR CASO
# =========================================================

linear_iterativa_melhor = [64, 41, 48]
linear_recursiva_melhor = [56, 40, 54]
sequencial_iterativa_melhor = [66, 40, 52]
sequencial_recursiva_melhor = [80, 36, 52]
binaria_iterativa_melhor = [62, 40, 38]
binaria_recursiva_melhor = [82, 43, 41]
ternaria_iterativa_melhor = [64, 46, 52]
ternaria_recursiva_melhor = [80, 40, 48]


# Cria o gráfico do melhor caso
plt.figure(figsize=(10, 6))


# Plota os tempos da busca linear iterativa
plt.plot(
    tamanhos,
    linear_iterativa_melhor,
    marker="o",
    label="Linear iterativa"
)


# Plota os tempos da busca linear recursiva
plt.plot(
    tamanhos,
    linear_recursiva_melhor,
    marker="o",
    label="Linear recursiva"
)


# Plota os tempos da busca sequencial alternativa iterativa
plt.plot(
    tamanhos,
    sequencial_iterativa_melhor,
    marker="o",
    label="Sequencial alternativa iterativa"
)


# Plota os tempos da busca sequencial alternativa recursiva
plt.plot(
    tamanhos,
    sequencial_recursiva_melhor,
    marker="o",
    label="Sequencial alternativa recursiva"
)


# Plota os tempos da busca binária iterativa
plt.plot(
    tamanhos,
    binaria_iterativa_melhor,
    marker="o",
    label="Binária iterativa"
)


# Plota os tempos da busca binária recursiva
plt.plot(
    tamanhos,
    binaria_recursiva_melhor,
    marker="o",
    label="Binária recursiva"
)


# Plota os tempos da busca ternária iterativa
plt.plot(
    tamanhos,
    ternaria_iterativa_melhor,
    marker="o",
    label="Ternária iterativa"
)


# Plota os tempos da busca ternária recursiva
plt.plot(
    tamanhos,
    ternaria_recursiva_melhor,
    marker="o",
    label="Ternária recursiva"
)


# Usa escala logarítmica no eixo X.
# Os tamanhos dos vetores aumentam de 10 em 10.
plt.xscale("log")


# Define os valores que serão mostrados no eixo X.
plt.xticks(
    tamanhos,
    ["5.000", "50.000", "500.000"]
)


# Define o título do gráfico
plt.title("Comparação dos algoritmos - Melhor caso")


# Define o nome do eixo X
plt.xlabel("Tamanho do vetor (n)")


# Define o nome do eixo Y
plt.ylabel("Tempo médio (ns)")


# Mostra a legenda com o nome de cada algoritmo
plt.legend()


# Mostra uma grade para facilitar a leitura
plt.grid(True)


# Ajusta automaticamente os elementos do gráfico
plt.tight_layout()


# Salva o gráfico em um arquivo PNG
plt.savefig("melhor_caso.png", dpi=300)


# Mostra o gráfico na tela
plt.show()


# =========================================================
# PIOR CASO
# =========================================================

linear_iterativa_pior = [8610, 81091, 878605]

linear_recursiva_pior = [80259, 971899, None]

sequencial_iterativa_pior = [8776, 68103, 514983]

sequencial_recursiva_pior = [43026, 368992, None]

binaria_iterativa_pior = [136, 140, 106]

binaria_recursiva_pior = [168, 160, 190]

ternaria_iterativa_pior = [122, 112, 170]

ternaria_recursiva_pior = [170, 152, 202]


# Cria o gráfico do pior caso
plt.figure(figsize=(10, 6))


# Plota os tempos da busca linear iterativa
plt.plot(
    tamanhos,
    linear_iterativa_pior,
    marker="o",
    label="Linear iterativa"
)


# Plota os tempos da busca linear recursiva.
# O valor None indica que não houve resultado para n = 500000.
plt.plot(
    tamanhos,
    linear_recursiva_pior,
    marker="o",
    label="Linear recursiva"
)


# Plota os tempos da busca sequencial alternativa iterativa
plt.plot(
    tamanhos,
    sequencial_iterativa_pior,
    marker="o",
    label="Sequencial alternativa iterativa"
)


# Plota os tempos da busca sequencial alternativa recursiva.
# O valor None indica que não houve resultado para n = 500000.
plt.plot(
    tamanhos,
    sequencial_recursiva_pior,
    marker="o",
    label="Sequencial alternativa recursiva"
)


# Plota os tempos da busca binária iterativa
plt.plot(
    tamanhos,
    binaria_iterativa_pior,
    marker="o",
    label="Binária iterativa"
)


# Plota os tempos da busca binária recursiva
plt.plot(
    tamanhos,
    binaria_recursiva_pior,
    marker="o",
    label="Binária recursiva"
)


# Plota os tempos da busca ternária iterativa
plt.plot(
    tamanhos,
    ternaria_iterativa_pior,
    marker="o",
    label="Ternária iterativa"
)


# Plota os tempos da busca ternária recursiva
plt.plot(
    tamanhos,
    ternaria_recursiva_pior,
    marker="o",
    label="Ternária recursiva"
)


# Usa escala logarítmica no eixo X.
# Isso facilita a visualização dos diferentes tamanhos de vetor.
plt.xscale("log")


# Usa escala logarítmica no eixo Y.
# Isso facilita a comparação entre tempos muito diferentes.
plt.yscale("log")


# Define os valores que serão mostrados no eixo X.
plt.xticks(
    tamanhos,
    ["5.000", "50.000", "500.000"]
)


# Define o título do gráfico
plt.title("Comparação dos algoritmos - Pior caso")


# Define o nome do eixo X
plt.xlabel("Tamanho do vetor (n)")


# Define o nome do eixo Y
plt.ylabel("Tempo médio (ns) - escala logarítmica")


# Mostra a legenda com o nome de cada algoritmo
plt.legend()


# Mostra uma grade para facilitar a leitura
plt.grid(True)


# Ajusta automaticamente os elementos do gráfico
plt.tight_layout()


# Salva o gráfico em um arquivo PNG
plt.savefig("pior_caso.png", dpi=300)


# Mostra o gráfico na tela
plt.show()