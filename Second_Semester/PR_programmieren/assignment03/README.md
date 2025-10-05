# Aufgabe 03

Die aktuelle Aufgabe befasst sich mit Funktionen in C.

Eine Funktion ist ein Block von Anweisungen, der in einem Programm aufgerufen werden kann.
Dies erhöht die Lesbarkeit des Quellcodes, da sich komplexe Aufgaben in separate Codeblöcke auslagern lassen.
Auch wenn diese häufig wiederholt werden, hilft das Auslagern natürlich dabei sich nicht ständig wiederholen zu müssen.

Bis jetzt haben wir schon einige Funktionen in unseren Programmen verwendet, zB: `printf`, `atof`, usw.
Daher sollten Sie schon wissen, dass man Funktionen Parameter übergeben kann.
Im Fall von `printf` wird zum Beispiel der Text als Parameter übergeben, der am Bildschirm angezeigt werden soll.
Wir haben aber selbst auch schon eine Funktion programmiert, nämlich die `main` Funktion die ein notwendiger Bestandteil jedes *C*-Programms ist.
Diese wird beim Ausführen eines Programms grundsätzlich gestartet.
Wie Sie sich erinnern sollten muss man bei der Definition der `main` Funktion auch einen Datentyp angeben (für `main` in der Regel `int`).

Somit haben wir alle Bestandteile zur Definition weiterer Funktionen beisammen:
```c
Rückgabe_Datentyp Funktionsname(Parameterliste) {   
    Anweisungen
    return Rückgabewert;
}
```
Dabei enthält die Parameterliste für jeden Parameter einen Datentypen und einen Variablennamen.
Die `return`-Anweisung am Ende des Funktions-Codeblocks wird benötigt, um das Ergebnis der Funktion an das aufrufende Programm zurückzugeben.
Dabei muss der Datentyp des Rückgabewerts natürlich dem Rückgabe-Datentyp der Funktion entsprechen.
Des Weiteren ist zu beachten, dass der `return`-Befehl die letzte Anweisung der Funktion sein sollte, da alle danach folgenden Instruktionen nicht ausgeführt werden.

Falls die Funktion nichts zurück geben soll, muss man als Rückgabe-Datentyp `void` wählen.

Hier zwei Beispiele:
```c
float quadrieren(float x) {
    float ergebnis;
    ergebnis = x*x;
    return ergebnis;
}

void rufen(int wie_oft, int wie_laut) {
    for (int i = 0; i < wie_oft; i++) {
        printf("HILFE");
        for (int j = 0; j < wie_laut; j++) {
            printf("!");
        }
        printf("\n");
    }
}
```
Die Funktion des ersten Beispiels gibt das Quadrat einer Gleitkommazahl zurück und das zweite Beispiel ruft um Hilfe, wobei man angeben kann, wie oft und wie laut.

Bevor man eine Funktion (innerhalb der `main` Funktion) aufrufen kann, muss man diese definieren.
Der Compiler arbeitet sich in der Regel von oben nach unten durch den Quellcode, weshalb man auf die Reihenfolge der Funktionsdefinitionen achten muss, falls diese voneinander abhängen.
Dieses Problem lässt sich umgehen, indem man am Anfang des Quellcodes, direkt nach dem Einbinden der Bibliotheken, Funktionsprototypen deklariert.
Diese enthalten nur die erste Zeile der Funktionsdefinition, also Rückgabedatentyp, Funktionsname und Parameterliste.
Die Reihenfolge der Funktionsdefinitionen ist dann irrelevant.
Insgesamt sollte das zum Beispiel so aussehen:
```c
#include<stdio.h>

//Funktionsdeklaration
float quadrieren(float x);                               

//Main Funktion
int main( ) {
    float m = 5.0;    
    float n;
    // Funktionsaufruf  
    n = quadrieren(m);                          
    printf ("Das Quadrat von %f ist %f\n", m, n);
    return 0;
}

// Funktionsdefinition
float quadrieren(float x) {
    float ergebnis;
    ergebnis = x*x;
    return ergebnis;
}
```
## Teilaufgabe a) (1 Punkt)

Erweitern Sie den Quellcode in `max.c` um die Definition der Funktion `max`, die den größeren der zwei übergebenen Werte zurückgeben soll.

## Teilaufgabe b) (1 Punkt)

Kompilieren Sie den Quellcode in `hochdrei.c` und führen Sie das resultierende Programm aus.
Anhand der Ausgabe des Programs sollten Sie sehen, dass innerhalb von Funktionen normalerweise nur mit Kopien der übergebenen Parameter gearbeitet wird.
Das bedeutet, dass sich etwaige Änderungen an deren Wert nicht automatisch auf deren Original auswirken.
Ändern Sie das Programm so ab, dass die Änderung in das Original zurück geschrieben wird.
Damit sollte auch in beiden Zeilen der gleiche Wert ausgegeben werden.

## Teilaufgabe c) (0.5 Punkte)

Wie wir in Aufgabe b) gesehen haben, sind Variablen immer lokale Variablen, d.h. sie gelten nur innerhalb einer entsprechenden Funktion. C bietet die
Möglichkeit, globale Variablen zu definieren. Diese gelten dann im gesamten C-Programm (siehe Vorbereitungslinks).

Verändern Sie das Programm `globale_var.c` so, dass die Ganzzahl `ZAHL_GLOBAL` eine solche globale Variable wird.

Frage (im C-File als Kommentar zu beantworten): Warum müssen diese globalen Variablen, im Gegensatz zu Lokalen, nicht mit einem Wert initialisiert werden?

## Teilaufgabe d) (1.5 Punkte)

 Eine sehr hilfreiche Eigenschaft von Funktionen ist, dass sie sich auch selbst aufrufen können.
 Diesen Aufruf nennt man Rekursion.
 Nutzen Sie dies, um ein Programm zu schreiben das die n-te Fibonacci-Zahl ausrechnet.
 Benutzen sie dabei die Vorlage in `fibonacci_rekursion.c` aber **keine Schleifen!**
