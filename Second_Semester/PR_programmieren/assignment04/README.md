# Aufgabe 04

Die aktuelle Aufgabe befasst sich mit Listen in _C_, auch _Arrays_ genannt.

Manchmal will man Variablen des selben Datentyps nummerieren, wie zum Beispiel bei den Einträgen eines Vektors. Das kann man, wie wir bereits in den letzten Wochen gesehen haben, mit separaten Variablen erreichen, die man dem Programm z.B. als

```c
float Eintrag1;
float Eintrag2;
float Eintrag3;
```

übergibt. Wenn die Einträge jedoch eine logische Einheit bilden und in Berechnungen oft gemeinsam verwendet werden, speichert man sie besser als _Array_:

```c
float Vektor[3];
```

Das bedeutet, dass die Liste `Vektor` drei Elemente vom Datentyp `float` aufnehmen kann.

Initialisieren lässt sich ein solches _Array_ in _C_ indem man ihm die gewünschten Werte in einer geschwungenen Klammer zuweist:

```c
float Vektor[3] = {1.2, 3.4, 5.6};
```

In diesem Fall könnte man die Anzahl der Elemente auch weg lassen, also nur

```c
float Vektor[] = {1.2, 3.4, 5.6};
```

schreibt. Hier wird das _Array_ mit einer Länge angelegt, die der Anzahl an Initialwerten entspricht.

Wenn die Anzahl jedoch bei der Initialisierung festgelegt wurde, kann man maximal so viele Initialwerte angeben, wie spezifiziert wurde. Wenn man trotzdem mehr angibt, bekommt man eine entsprechende Fehlermeldung, wenn man weniger angibt wird der Rest des _Arrays_ mit Nullen gefüllt.

Wenn das _Array_ nicht initialisiert wird, kann es (wie Variablen) zufällige Werte beinhalten, welche zuvor schon im Speicher waren.

Auf die einzelnen Elemente eines _Arrays_ kann man über eckige Klammern zugreifen. Dabei ist zu beachten, dass die Indexierung hier mit Null begonnen wird. Das erste Element hat also den Index 0, das Dritte den Index 2\. Einem `Vektor` kann man also auch folgendermaßen Werte zuweisen:

```c
float Vektor[3];
Vektor[0]=1.2;
Vektor[1]=2.3;
Vektor[2]=3.4;
```

bzw., ausgeben:

```c
printf("%f\n",Vektor[0]);
printf("%f\n",Vektor[1]);
printf("%f\n",Vektor[2]);
```

Alternativ lassen sich solche Ausgaben mit den bereits bekannten Schleifen eleganter lösen. Zum Beispiel mit einer `for` Schleife:

```c
for (int i = 0; i < 3; i++) {
    printf("%f\n",Vektor[i]);
}
```

## Teilaufgabe a) (1 Punkt)

Verwenden Sie die bereitgestellte Vorlage `skalarprodukt.c` in Ihrem _Repository_, um das Skalarprodukt zweier Vektoren zu implementieren. In der Vorlage wird dabei bereits überprüft, ob genügend Parameter übergeben werden. Bei diesen soll es sich natürlich um die Einträge der Vektoren handeln. Legen Sie zwei Vektoren an, dessen Werte Sie über eine Schleife zuweisen. Berechnen Sie in einer zweiten Schleife das Skalarprodukt der beiden Vektoren und geben Sie das Ergebnis schlussendlich am Bildschirm aus.

## Teilaufgabe b) (1 Punkt)

Verwenden Sie die bereitgestellte Vorlage `kreuzprodukt.c` in Ihrem _Repository_, um das Kreuzprodukt zweier Vektoren zu implementieren. Gehen Sie beim Einlesen der Vektoren gleich vor wie in Teilaufgabe a), berechnen Sie jedoch das Kreuzprodukt der beiden Vektoren, schreiben Sie das Ergebnis in ein _Array_ und geben Sie dieses in einer Schleife aus.

## Teilaufgabe c) (0.5 Punkte)

Verwenden Sie die bereitgestellte Vorlage `fibonacci.c` in Ihrem _Repository_, um die Fibonacci-Folge zu implementieren. Berechnen Sie nun die ersten 20 Elemente der Folge, speichern diese in einem _Array_ ab und geben Sie sie anschließend mit Hilfe einer Schleife am Bildschirm aus.

## Teilaufgabe d) (1 Punkt)

Im bereitgestellten Quellcode `summe.c` finden Sie ein fehlerhaftes Programm, dass die Summe der Werte in einem _Array_ berechnen soll. Finden und beheben Sie alle Fehler, sodass die Berechnungen korrekt sind. Schreiben Sie kurze Kommentare, wie die jeweiligen Fehler das Programm beeinträchtigt haben.

## Teilaufgabe e) (1.5 Punkte)

Verwenden Sie die bereitgestellte Vorlage `eigenvektor.c` in Ihrem _Repository_. In dieser Aufgabe soll überprüft werden, ob es sich bei einem übergebenen Vektor um einen Eigenvektor der vordefinierten Matrix

```math
A = \begin{pmatrix}
1 & 2 & 0 \\
0 & 3 & 0 \\
2 & -4 & 2
\end{pmatrix}
```

handelt. Ein einfaches Kriterium hierfür lässt sich durch die Eigenwertgleichung

```math
A v = \lambda v
```

finden. Somit gilt, dass sich der, aus der Multiplikation von $`A`$ mit $`v`$ resultierende Vektor, durch den konstanten Faktor $`\lambda`$ von $`v`$ unterscheidet. Implementieren Sie hierfür zunächst die Matrix-Vektor-Multiplikation und überprüfen Sie dann, ob dieser Faktor wirklich für alle Komponenten der beiden Vektoren der gleiche ist.<br>
Beachten Sie dabei, dass absolute Gleichheit in der Numerik praktisch nie erreicht wird. Aus diesem Grund ist es sinnvoll eine maximale Abweichung bzw. Toleranz zu definieren unter welcher zwei Zahlen noch als gleich angesehen werden.

Testfälle: (1.1, 1.1, -2.2) ist ein Eigenvektor, (1, 1, 1) ist keiner.

Hinweis: Beim Kompilieren nicht vergessen die Optionen `-Wall`, `-Werror` und `-std=gnu90` zu verwenden!
