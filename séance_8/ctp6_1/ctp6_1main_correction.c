#include <stdio.h>
#include <stdlib.h>

#include "ctp6_1.h"

extern euro mon_compte_international;
// extern car il s'agit de la variable déclarée dans le fichier "ctp6_1.c"

int main()
{
jeconsomme(mon_compte_international);   // appel correct : fonction et variable accessible.
printf(" -1- \n");
jeconsomme(mon_compte_secret); // appel incorrect : fonction accessible mais variable ""mon_compte_secret"
    // n'est accessible que dans le fichier "ctp6_1.c"

jeconsommelocal(mon_compte_international); // appel incorrect : fonction non accessible mais variable accessible
jeconsommelocal(mon_compte_secret); // appel incorrect : fonction et variable non accessibles

jeteste(); // appel correct : fonction accessible
    // cette fonction peut appeler dans sa définition la fonction "jeconsommelocal" car elle fait partie du même fichier "ctp6_1.c".
    // Elle peut accéder à tout ce qui est déclaré "static" dans le fichier "ctp6_1.c" : euro mon_compte_secret et jeconsommelocal.

return 0;
}

