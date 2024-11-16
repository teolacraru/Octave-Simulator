Copyright 2023 Lacraru Teodora-Ioana 2023-2024

Simulator Octave

Programul efectueaza diferite operatii cu matrice stocate in memorie prin alocare dinamica.

Fiecarei operatii ii corespunde o litera ce va fi citita de la tastatura.
'L' este pentru incarcarea matricei in memorie, citind si dimensiunile
acesteia. Pentru afisarea dimensiunilor se foloseste operatia cu litera 'D'.
Afisarea matricei se face la citirea literei 'P' si a indexului corespunzator.
Redimensionarii ii corespunde litera 'C', inmultirea a doua matrice se face
la citirea literei 'M', sortarea matricelor din memorie cu 'O', transpunerea
cu 'T', ridicarea la putere in timp logaritmic cu 'R', eliberarea memoriei
unei matrice cu 'F' si eliberearea resurselor cu 'Q'.

Am folosit diferite functii pentru modularizarea codului, precum free_mat
ce elibereaza memoria alocate unei matrice, swap_matrice2 ce interschimba 2
matrice, suma_elem ce calculeaza elementele unei matrice si I ce creeaza
matricea identitate.
