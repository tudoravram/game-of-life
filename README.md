Programul se invarte in jurul Game of Life (mai multe informatii aici: https://site-pa.netlify.app/proiecte/game_of_life/). Acesta e impartit in 4 taskuri principale si un subtask bonus:

Task 1: Implementarea regulilor Game of Life in functie de un numar de "K" generatii date

Task 2: In functie de regulile Game of Life, se retin intr-o stiva de liste adresele (indicii i si j) celulelor care isi schimmba starea.

Task 2 - bonus: Inversul Task-ului 2; in functie de stiva care contine pozitiile celulelor care isi schimba starea, se ajunge la matricea initiala

Task 3: Se creaza un arbore binar perfect de inaltimea K, unde K este numarul de generatii date, in care, in fiecare nod se va tine minte generatia curenta a matricei dupa aplicarea regulilor. Apare o noua regula (regula B), oricare celula cu exact 2 vecini vii devine vie. La fiecare nod, fiului din stanga i se va aplica regula B, iar celui din dreapta regula A.

Task 4: Matricea acum va fi vazuta ca un graf. Toate celulele care au vecini vii vor compune o componenta conexa. Scopul este cautarea celui mai lung lant Hamiltonian.

Proiectul este impartit in mai multe fisiere ".c" si ".h". 
game_of_life.c este main-ul programului. 
functions.c contine functiile principale folosite in Task 1, 2 si 3. 
stive_liste.c contine functii folosite pentru Task 2, iar stive_liste.h structurile folosite acolo
bonus.c si bonus.h sunt folosite strict pentru Task 2 - bonus

Functiile principale folosite in program sunt: 
- aplicare_reguli() care modifica o matrice folosind regula A, adica cea standard (Game of Life)
- aplicare_reguli2() care modifica o matrice folosind regula B, adica cea de la Task 3
- generatie_matrice() care creeaza o matrice in care, pe fiecare pozitie, tin minte numarul vecinilor fiecarui element
- numar_vecini() care calculeaza cate celule vii invecineaza celula curenta

Pentru rulare trebuie instalat checker-ul, alaturi de InputData si RefData (pentru verificare).
