#!/bin/bash

# Nombre de archivo a crear
file="archivo.txt"

GITHUB_USER="julizaldana"
URL=https://api.github.com/users/
# Concatenar el user de github en la URL con +=
URL+="$GITHUB_USER"

# Realizar la solicitud HTTP con curl a la página de GitHub y guardar la respuesta en un archivo txt
curl -s "$URL" -o $file

# Usar jq para leer el json y obtener los atributos id y created_at
USER_ID=$(jq '.id' $file)
CREATED_AT=$(jq '.created_at' $file)

# Se almacena el comando date en la variable DATE, con el formato de YYYY-MM-DD-HH:MM:SS
DATE=$(date +%Y-%m-%d-%H:%M:%S) 

# Se crea el directorio con mkdir y la flag -p (parents) 
DIR="/tmp/$DATE"
mkdir -p $DIR

archivo_salida="$DIR/saludos.log"

# Crear un archivo saludos.log y ponerle el date  /tmp/date/saludos.log

echo "La url es $URL"
echo "La fecha es $DATE"
# Se redirige la salida de echo al archivo de salida
echo "Hola, $GITHUB_USER. User ID: $USER_ID. Cuenta fue creada el: $CREATED_AT." > "$archivo_salida"
echo "Hola, $GITHUB_USER. User ID: $USER_ID. Cuenta fue creada el: $CREATED_AT."


# Y para ejecutar el script cada 5 minutos, se realizó lo siguiente.
# Se utiliza el comando crontab -e
# Se selecciona el formato nano para editar el crontab. [1]
# Y se agrega el siguiente comando:
# */5 * * * * cd Escritorio/SOPES1/so1_actividades_202110206/actividad2 ; ./script.sh
# Los asteriscos significan minutos, horas, dia del mes, mes del año, dia de la semana y se agrega solamente */5, significando que se debe de ejecutar cada 5 minutos.
# con cd Escritorio/SOPES1/so1_actividades_202110206/actividad2, se accede al directorio donde se encuentra el script
# Y así poder ejecutarlo con ./script.sh