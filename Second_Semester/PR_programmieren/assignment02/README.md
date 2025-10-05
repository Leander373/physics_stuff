# Aufgabe 02
Die aktuelle Aufgabe wird sich mit so genannten Kontrollstrukturen beschäftigen, welche ein essentieller Bestandteil jeder Programmiersprache sind. 
Dazu gehören zum Beispiel Verzweigungen und Schleifen. 

## Verzweigungen
Verzweigungen werden in *C* mit den Codewörtern `if` und `else` realisiert.
Dabei muss nach `if` immer eine Bedingung angegeben werden. Falls diese zutrifft (Bedingung wird mit *Wahr* evaluiert), wird der nachgestellte Codeblock abgearbeitet. 
Wenn die Bedingung allerdings mit *Falsch* evaluiert wird, kommt der nachgestellte Codeblock nicht zur Ausführung und das Programm läuft nach diesem weiter.
Exemplarisch sieht das etwa so aus
``` C
if (x > 10) {
    printf("x ist größer als 10!\n");
}
printf("x ist %i\n",x);
```
Hier wird überprüft ob x größer als 10 ist. Falls das zutrifft, wird der nachstehende Codeblock (eingefasst durch die geschwungenen Klammern `{ ... }`) ausgeführt und die Meldung *x ist größer als 10!* am Bildschirm ausgegeben.
Falls x kleiner oder gleich 10 ist, kommt der Codeblock in der `if`-Bedingung nicht zur Ausführung. In beiden Fällen wird der Wert von x ausgegeben.

Es könnte sein, dass Sie nun auch in dem Fall, dass x kleiner oder gleich 10 ist, eine Meldung diesbezügliche ausgeben wollen. Das könnte beispielsweise folgendermaßen aussehen:
``` C
if (x > 10) {
    printf("x ist größer als 10!\n");
}
if (x <= 10) {
    printf("x ist kleiner oder gleich 10!\n");
}
printf("x ist %i\n",x);
```
Viel eleganter und bei komplexeren Problemen auch effizienter ist es allerdings, wenn Sie dazu das Codewort `else` verwenden:
``` C
if (x > 10) {
    printf("x ist größer als 10!\n");
}
else {
    printf("x ist kleiner oder gleich 10!\n");
}
printf("x ist %i\n",x);
```
Mit Hilfe von `else` lässt sich also der konträre Fall zu der `if` Bedingung abfragen.
Das spart nicht nur Schreibarbeit, sondern ist auch weniger fehleranfällig. 
Zusätzlich führt die Verwendung von `else` natürlich auch zu einer kürzeren Rechenzeit, da im Vergleich zur vorherigen Implementierung mit zwei `if` Statements, nur eine Bedingung überprüft werden muss.
Bei einem derart kurzen Beispiel wird der Rechenzeitunterschied jedoch sehr gering ausfallen.



## Mehrfachverzweigungen

Es lassen sich auch mehrere `if/else` Verzweigungen hintereinander reihen, um eine feinere Abstufung erreichen zu können. Also z.B. so:
``` C
if (x > 10) {
    printf("x ist größer als 10!\n");
}
else if (x < 10) {
    printf("x ist kleiner als 10!\n");
}
else {
    printf("x ist genau 10!\n");
}
```

## Speichern von Wahrheitsvariablen

Wahrheitswerte werden üblicherweise in Variablen vom Typ `bool` gespeichert. Allerdings ist dieser Typ **nicht** Teil des *C*-Standards. Um ihn dennoch nutzen zu können, fügen Sie die Header-Datei `stdbool.h` hinzu. Damit können Sie Variablen vom Typ `bool` nutzen und diesen die Werte `true` oder `false` zuweisen. Das müssen Sie hier nicht nutzen, mag aber eventuell irgendwann hilfreich sein.

### Teilaufgabe a) (1 Punkt)
Clonen Sie wie üblich das Repository zur heutigen Teilaufgabe auf Ihren Rechner.
Legen Sie eine neue Quellcodedatei mit dem Namen `vergleich.c` an. 
Programmieren Sie darin ein Programm, das die Information darüber zurück gibt, ob von zwei übergebenen Ganzzahlen die erste oder die zweite Zahl größer ist, oder ob beide gleich sind.

>Noch einige Anmerkungen:
> - Ganzzahlen können Sie mit der Funktion `atoi` aus der `<stdlib.h>` Bibliothek aus den Argumenten einlesen.
> - Vergessen Sie nicht, die Fragen aus den Teilaufgaben als Kommentare in den Quellcodedateien (nicht in den Anmerkungen zu den Commits) und fügen Sie jeweils eine Kommentarzeile mit Ihrem Namen in die Programme ein.
> - Bitte laden Sie nur Quellcodedateien (`.c`) und keine ausführbaren Dateien auf GitLab hoch.


### Teilaufgabe b) (1 Punkt)
In diesem Repository finden Sie die Datei `quader.c` (auch zur Auflösung, falls dieses Beispiel in der letzten Woche von Ihnen nicht komplettiert wurde).
Bauen Sie eine Verzweigung in das Programm ein, die sicherstellt, dass genau drei Parameter übergeben wurden. Falls das nicht zutrifft, sollte eine Erklärung ausgegeben werden, die besagt, dass genau drei Parameter nötig sind.

## Schleifen
Schleifen sind dazu da, um bestimmte Codeblöcke mehrfach auszuführen. 
In *C* steht Ihnen dazu unter anderem die so genannte `while` Schleife zur Verfügung.
Sie wiederholt die Ausführung des nachgestellten Codeblockes, solange eine Bedingung mit *Wahr* evaluiert wird. Also z.B. so:
```C
int number = 10;

while (number > 0) {
    printf("%i\n", number);
    number--;
}

while (number < 11) {
    printf("%i\n", number);
    number++;
}
```
Falls Sie die Variable, die in der Bedingung überprüft wird, nur innerhalb der Schleife, oder nur zum Zählen der Schleifendurchgänge benötigen, könnten Sie auch eine `for` Schleife verwenden:
```C
int i;

for (i = 0; i <= 10; i++) {
    printf("%i\n", i);
}
```
Auf den Inhalt der verwendete Variable `i` kann in diesem Fall allerdings nur innerhalb der `for` Schleife zugegriffen werden.
>Generell ist es so, dass Variablen, die in übergeordneten Codeblöcken definiert wurden, auch in eingebetteten Codeblöcken benutzbar sind. 
Variablen, die in eingebetteten Codeblöcken definiert wurden, sind jedoch in übergeordneten Codeblöcken nicht verfügbar.

### Teilaufgabe c) (1 Punkt)
Legen Sie eine neue Quellcodedatei mit dem Namen `fakultaet.c` an. 
Programmieren Sie darin ein Programm, das die Fakultät einer, mittels Parameter im Terminal übergebenen, ganzen Zahl berechnet. 
Überprüfen Sie vorher noch, dass genau ein Parameter übergeben wurde und geben Sie andernfalls einen Hinweis aus.
Stimmen die Ergebnisse? Ab welcher Zahl stimmt das Ergebnis nicht mehr?
Vermerken Sie diese Zahlen am Ende des Quellcodes in einem Kommentar.

Der Grund dafür ist, dass eine `int` variable nur einen beschränkten Speicherbereich zur Verfügung hat.
Wie groß der Speicherbereich tatsächlich ist, hängt vom Compiler (bei uns gcc) und dessen Version ab. 
Der Speicherbereich von `int` ist aber mindestens 16 Bit groß, womit Zahlen von −32767 bis +32767 abgespeichert werden können. 
Wenn diese Grenzen über- bzw. unterschritten werden, fängt die Variable von der anderen Seite zu zählen an und das Ergebnis wird dadurch unvorhersehbar, da man auch nicht wissen kann, wie oft schon iteriert wurde.
Typischerweise stehen auf heutigen Systemen eher 4 Byte, also 32 Bit (Ein Byte sind 8 Bits), zur Verfügung. 
Um sicher zu sein, können Sie die Anzahl der Bytes mit der Funktion `sizeof` ausgeben lassen.
Bauen Sie das ebenfalls in Ihr Programm ein:
```C
printf("Anzahl der Bytes von zahl: %i\n", sizeof(zahl));
```
### Teilaufgabe d) (0.5 Punkte)
Kopieren Sie nun Ihr Programm aus Teilaufgabe c in die Datei `fakultaet_long.c` und verwenden Sie statt des Datentyps `int` den Datentyp `long` (CAVEAT: Dies hat Auswirkungen an mehreren Stellen im Programm!).
Wie verhält sich jetzt der Speicherbereich und welche maximale Fakultät können Sie berechnen?
Vermerken Sie diese Zahlen am Ende des Quellcodes in einem Kommentar.
Es gibt natürlich noch weitere Datentypen. Diese können Sie bei Bedarf gerne im Internet recherchieren. 

### Teilaufgabe e) (1.5 Punkte)
Erstellen Sie nun ein Programm `primzahl.c`, das überprüft ob eine übergebene Zahl eine Primzahl ist.
Dazu werden Sie natürlich eine Schleife und `if/else` benötigen.
Um das Programm schneller zu machen, empfiehlt es sich die Schleife mit `break;` abzubrechen, wenn es den ersten Beweis dafür gibt, dass es sich nicht um eine Primzahl handelt.
>Tipp: Starten Sie dafür die Inkrementierung Ihrer Variable bei 2, wobei Sie jeweils den Modulo mit der zu überprüfenden Zahl bilden.
Ist der Modulo Null, ist die zu überprüfenden Zahl durch diese teilbar, wodurch sich leicht sehen lässt, ob sie eine Primzahl ist. 

### freiwillige Bonusaufgabe (1 Extrapunkt)
Erstellen Sie ein Programm `sinh_reihe.c`, das den Sinus hyperbolicus mit Hilfe der Definition:

$\sinh\left(x\right) = \sum_{n=0}^\infty \frac{x^{2n+1}}{\left(2n+1\right)!} = x + \frac{x^3}{3!} + \frac{x^5}{5!} + ...$

berechnet. 
Sie müssen dafür *Unendlich* natürlich durch eine endliche Zahl ersetzen (experimentieren Sie zB. mit 100, 200, oder legen Sie eine Toleranz bzw. Genauigkeit fest. Sie können zum Beispiel testen, ob die Änderung durch den nächsten Term hinreichend klein ist). Es handelt sich also um eine numerische Näherung.
Für dieses Beispiel würde sich ausserdem eine `do/while` Schleife sehr gut eignen, welche Sie natürlich im Internet nachschlagen können. Verwenden Sie NICHT die Funktionen der `math.h` library!
