echo -n "Telefono: "
read nombre
echo -n "Mensaje: "
read mensaje

curl -X POST https://textbelt.com/text --data-urlencode phone=$nombre --data-urlencode message=$mensaje -d key=textbelt
