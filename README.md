# FdF @ 42
![screenshot](/screen/Screen1.png?raw=true)
## Objectif
Description :

Ce projet consiste à créer graphiquement la representation schématique (en “fils de
fer” ou “wireframe” en anglais) d’un terrain en relief en reliant différents points (x, y,
z) par des segments. Les coordonnées du terrain sont stockées dans un fichier passé en
paramètre.

Fonction autoriser :
- `open`, `read`, `write`, `close`, `malloc`, `free`, `perror`, `strerror`, `exit`
- Toutes les fonctions de la lib math
- Toutes les fonctions de la miniLibX.
## Features
- Rotation 3D
- Controle camera (deplacement, zoom)
- Degradée de couleur
- Posibilitée de changer de projection

## Usgage
```
make
./fdf [map]
```
![screenshot](/screen/Screen2.png?raw=true)
