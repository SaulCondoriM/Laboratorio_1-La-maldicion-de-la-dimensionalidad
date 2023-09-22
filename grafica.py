import matplotlib.pyplot as plt  


dimension = int(input("Que dimension desea ver su histograma?: "))

distancias = []  # Crea una lista vacía para almacenar las distancias

# Abre el archivo correspondiente basado en la dimensión ingresada
with open(f"distancias_{dimension}.txt", "r") as archivo:
    for linea in archivo:  # Recorre cada línea del archivo
        distancia = float(linea.strip())  # Convierte la línea en un número flotante (distancia)
        distancias.append(distancia)  # Agrega la distancia a la lista distancias

# Genera el histograma de las distancias con 20 bins
plt.hist(distancias, bins=20)


plt.title(f"Histograma de distancias (Dimensión : {dimension})")
plt.xlabel("Distancia")
plt.ylabel("Frecuencia")

plt.show()
