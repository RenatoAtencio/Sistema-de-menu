import os
import sys
import re

pathProcessedFiles = os.getenv('PATH_PROCESSEDFILES')
fileName = sys.argv[1]
processedFilePath = os.path.join(pathProcessedFiles,'processed_' + fileName)

# Abre el archivo 
with open(processedFilePath, 'r') as file:
    contenido = file.read()

# Divide el contenido en palabras
palabras = contenido.split()

# Crea un diccionario para realizar un seguimiento de las ocurrencias de cada palabra
conteo_palabras = {}
for palabra in palabras:
    # Incrementa el contador para la palabra o inicialízalo en 1 si es la primera aparición
    if palabra in conteo_palabras:
        conteo_palabras[palabra] += 1
    else:
        conteo_palabras[palabra] = 1

pathOutputFiles = os.getenv('PATH_OUTPUTFILES')
outputFileName = 'output_' + fileName
outputFilePath = os.path.join(pathOutputFiles,outputFileName)

# Crea y escribe en el archivo de salida si NO existe
if not os.path.exists(outputFilePath):
    with open(outputFilePath,'w') as outputFile:
        for palabra, cantidad in conteo_palabras.items():
            outputFile.write(f"{palabra};{cantidad}\n")
    if os.path.exists(processedFilePath):
        os.remove(processedFilePath)
