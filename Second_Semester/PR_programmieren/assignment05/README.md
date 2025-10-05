# Aufgabe 05

Diese Aufgabe beschäftigt sich mit Zeigern (engl. _Pointer_) in _C_.

Zeiger sind Variablen die Speicheradressen enthalten. Wie bei "normalen" Variablen, die Werte enthalten, ist es auch bei Zeigern nötig den Datentyp anzugeben, der an der Speicheradresse zu finden ist. Nur so kann später im Programm richtig auf diesen Speicher zugegriffen werden.

Ein Zeiger wird folgendermaßen definiert:

```c
Daten-Typ *Zeigername;
```

also zum Beispiel so:

```c
int   *var1;
float *var2;
```

Der `*`-Operator legt hier fest, dass es sich bei `var1` und `var2` um Zeiger handelt.

"Normale" Variablen haben auch eine Adresse im Speicher, auf welche mit dem `&`-Operator zugegriffen werden kann:

```c
int *zeiger;
int variable = 23;
zeiger = &variable;
```

Der Zeiger `zeiger` zeigt damit auf die Speicheradresse der Variable `variable`.

Die Speicheradresse, auf die der Zeiger verweist, kann so ausgegeben werden:

```c
printf("%p\n", zeiger);
printf("%p\n", &variable);
```

Die beiden ausgegebenen Adressen sind ident.

Auf den Inhalt des Speichers kann bei dem Zeiger wiederum mit dem `*`-Operator zugegriffen werden (dieser Vorgang wird Dereferenzierung genannt):

```c
*zeiger = 42;
printf("%i\n", *zeiger);
printf("%i\n", variable);
```

Hier ist zu sehen, dass sich tatsächlich auch die Ausgabe von `variable` verändert, da auf den selben Speicherbereich zugegriffen wird!

## Teilaufgabe a) (1 Punkt)

Vervollständigen Sie `intro_pointer.c`, um den Umgang mit Zeigern nachzuvollziehen.

## Teilaufgabe b) (1 Punkt)

Diese Teilaufgabe beschäftigt sich mit Zeigern als Funktionsparameter.

Bei Funktionsaufrufen werden die Werte der Parameter kopiert. Es wird also innerhalb der Funktionen nicht mit den originalen Variablen gearbeitet sondern mit Kopien. Die Ergebnisse können daher nur mit `return` zurückgegeben werden (siehe Aufgabe 3b). Das kann vermieden werden, indem ein Zeiger als Parameter an die Funktion übergeben wird. Teilaufgabe b) von Aufgabe 03 des Praktikums ließe sich damit wie folgt lösen:

```c
#include <stdio.h>
#include <stdlib.h>

// Funktionsdeklaration
void hochdrei(int *zahl);

// Main Funktion
int main(int argc, char *argv[]) {

    int a;

    a = atoi(argv[1]);

    // Funktionsaufruf
    hochdrei(&a);

    printf("Wert = %d\n", a);

    return 0;
}

// Funktionsdefinition
void hochdrei(int *zahl) {
    *zahl = (*zahl) * (*zahl) * (*zahl); // Die Klammern dienen nur der Lesbarkeit.
    printf("Wert = %d\n", *zahl);
}
```

Die Funktion muss also angepasst werden, damit sie einen Zeiger als Übergabeparameter akzeptiert. In der `main` Funktion ändert sich nur der Funktionsaufruf, wo jetzt die Adresse der Variable anstelle des Werts übergeben wird.

Komplettieren Sie nun das Programm in `swap.c`. Mit Hilfe der Funktion `swap` sollen die Werte von zwei Variablen vertauscht werden. Wie Sie sehen, werden die jeweiligen Adressen der Variablen an die Funktion übergeben. Verwenden Sie innerhalb der Funktion Zeiger, um die beiden Werte zu vertauschen.

## Teilaufgabe c) (1 Punkt)

Bis jetzt haben wir Zeiger auf bereits initialisierte Variablen gerichtet, deren Speicherbedarf bereits vor dem kompilieren feststeht. Wenn man Speicher dynamisch verwalten möchte, ist das mit der Funktion `malloc` möglich. Dynamische Speicherbelegung bedeutet, dass während des Ausführens des Programms Speicher vom Betriebssystem angefordert wird. Auf diesen kann dann über Zeiger zugegriffen werden.

Um Speicher für einen einzelnen Integer Wert zu bekommen kann `malloc` folgendermaßen verwendet werden:

```c
int *p = malloc(sizeof(int));
```

Zum Ablegen von `N` Ganzzahlen funktioniert folglich:

```c
int *p = malloc(N*sizeof(int));
```

Wenn Speicher für mehrere Werte angefordert wird, kann auf diesen wie auf ein Array zugegriffen werden

```c
p[0] = 23;
p[1] = 42;
```

oder mit dem Dereferenzierungsoperator (`*`):

```c
*p = 23;
*(p+1) = 42;
```

Die Zeigeradresse kann also einfach inkrementiert werden um auf die weiteren Elemente Zugriff zu erlangen. Arrays sind im Grunde also nichts Anderes als Zeiger, Sie verbergen nur ein wenig die Komplexität.

> Warnung: Sie sollten entsprechend auch hier nicht außerhalb des angeforderten Bereichs lesen/schreiben!

Wenn der Speicherbereich nicht mehr benötigt wird, **muss** er außerdem mit `free` wieder freigegeben werden, sonst können Sie im schlimmsten Fall Ihren gesamten Speicher voll schreiben und Ihr Computer stürzt ab! Um das zu Vermeiden verwenden Sie

```c
free(p)
```

für jeden (!) dynamisch erzeugten Zeiger am Ende der Main-Funktion.

Zudem ist es sinnvoll wenn Sie nach dem Belegen des Speichers abfragen, ob dies funktioniert hat und gegebenenfalls eine Fehlermeldung ausgeben. Dies lässt sich folgendermaßen bewerkstelligen:

```c
int *p = malloc(sizeof(int));
if(p == NULL) {
    printf("Kein Speicher mehr verfügbar ...\n");
    exit(1); // Programm beenden
} else {
    *p=42;
    printf("Speicherbelegung erfolgreich ... \n");
}
```

Wie man hier erkennt, wird der sogenannte `NULL`-Zeiger von `malloc` zurückgegeben falls die Speicherbelegung fehl schlägt.

Der Quelltext in `fibonacci_pointer.c` ist nicht _offensichtlich_ falsch, er funktioniert aber nicht so wie gewollt. Beim richtigen Kompilieren werden auch entsprechende Warnungen ausgegeben.

Verwenden Sie `malloc`, um das Problem zu lösen und vergessen Sie nicht den Speicher mit `free` wieder freizugeben.

Der Speicherbereich sollte dabei innerhalb der Funktion `berechne_fibonacci` belegt und im Hauptprogramm (`main`) wieder freigegeben werden.

## Teilaufgabe d) (2 Punkte)

In dieser Aufgabe wollen wir das Gelernte anwenden, um da Integral einer Funktion numerisch zu berechnen. Verwenden Sie hierfür die Vorlage `integrate.c` in ihrem Repository und erweitern Sie den dort befindlichen Programmcode in drei Schritten.

1. Implementieren Sie die Funktion `erzeuge_intervall`, welche ein Intervall `[a, b]` in `anzahl_punkte` äquidistante Punkte zerlegt, deren Position in ein Array speichert und den Zeiger auf dieses Array zurückgibt. Beachten Sie hierbei, dass dieses Array dynamisch erzeugt werden muss. Der Funktionsaufruf von `erzeuge_intervall` ist bereits in der `main` Funktion vorhanden und kann, wie alle anderen Aufrufe, für Testzwecke auskommentiert werden.
2. Implementieren Sie `funktion_auswerten`, welche die Funktion `y(x) = x^4 + 2x` für alle Punkte im vorher erzeugten Intervall (x Werte) auswertet und in ein neues Array (y Werte) speichert. Geben Sie wiederum den Zeiger zurück.
3. Implementieren Sie `integral_berechnen`, welche das numerische Integral zu den vorherigen Wertepaaren `(x, y)`, und damit im Interval `[a, b]` berechnet. Das Integral kann numerisch auf verschiedene Arten durchgeführt werden. Wir verwenden heute die sogenannte Trapezregel. Diese nähert die Fläche unter einer Funktion mit der Fläche des Trapezes der Stützpunkte an:

  ```math
  \begin{aligned}
  \int_a^b f(x) dx \approx (b-a) \frac{f(a) + f(b)}{2}.
  \end{aligned}
  ```

  Werden wie in unserem Fall mehrere Stützpunkte verwendet, kann das Integral in mehrere Subintervalle

  ```math
  a = x_0 < x_1 < ... < x_n = b
  ```

  aufgeteilt werden und somit die Genauigkeit der numerischen Integration erhöht werden:

  ```math
  \begin{aligned}
  \int_a^b f(x) dx \approx \sum_{k=1}^{N} \Delta x_k \frac{f(x_{k-1}) + f(x_k)}{2} \quad \quad {\rm wobei} \quad \Delta x_k  = x_k - x_{k-1} 
  \end{aligned}
  ```

Nutzen sie das erstellte Programm, um die Genauigkeit der Trapezregel zu untersuchen. Ab welcher `anzahl_punkte` hat das Ergebnis für `a=0` und `b=1` eine Genauigkeit von `0.0000010` erreicht?

--------------------------------------------------------------------------------

Es gibt natürlich noch weitere Anwendungsgebiete für Zeiger, etwa Listen und Baumstrukturen, außerdem gibt es noch weitere Funktionen zum Speichermanagement, etwa `calloc` und `realloc`, auf welche wir im Rahmen dieses Praktikums nicht weiter eingehen wollen, da es sich dabei um weiterführende Themen handelt.

Es sollte bei der Verwendung von Zeigern und dynamischem Speichermanagement stets bedacht werden, dass durch die zusätzliche Komplexität:

1. schwieriger zu verstehender Programmcode und
2. mehr Fehlerquellen entstehen.

Deshalb sollte bei deren Verwendung sichergestellt sein, dass diese tatsächlich benötigt werden.

### Nicht vergessen: gcc -Wall -Werror -std=gnu90
