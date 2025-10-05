# Aufgabe 01 

*Clonen* Sie wie im letzten Beispiel *Repository* 'assignment01' von GitLab auf Ihren lokalen PC und wechseln Sie in das so erzeugte Verzeichnis. Achten Sie dabei darauf, dass alle Änderungen in diesem Verzeichnis gemacht werden müssen, damit Sie auch im Abgabeordner landen.

## Teilaufgabe a) (1 Punkt)

In der heutigen Aufgabe sollen Sie sich mit den grundlegenden arithmetischen Operationen in *C* vertraut machen.
In Ihrem Aufgaben-*Repository* befindet sich eine Datei mit dem Namen `basic_operations.c`.
Sie beinhaltet einen Beispielcode in dem zwei Ganzzahlen `a` und `b` auf einen vordefinierten Wert gesetzt werden.
> INFO: Wie jegliche andere Information werden auch die zwei Variablen `a` und `b` vom Computer als Kette von 0 und 1 kodiert und im Speicher abgelegt.
Wie genau diese *Codierung* gemacht wird ist vom *Variablentyp* abhängig.  
Ganzzahlen beispielsweise werden in *C* mit dem Variablentyp `int` (engl. integer) bezeichnet.

Orientieren Sie sich an dem Beispiel für die Addition um die anderen Rechenoperationen mit Ihren Variablen `a` und `b` durchzuführen. Programmieren Sie dafür die entsprechenden Operationen, ggf. mit Hilfe des Internets, in die zweite Kommentarzeile. 
Kompilieren sie den Code anschließend mit
```
    gcc -Wall -Werror -std=gnu90 -o basic_operations basic_operations.c
```
und beheben Sie eventuelle Fehler, die der Compiler findet.
Führen Sie anschließend die erzeugte Datei aus - hier können sie nun selbst überprüfen, ob Ihre Implementierungen korrekt sind.  
Fallen Ihnen Besonderheiten auf? Wenn ja, welche? 
> Tipp: Behalten Sie im Hinterkopf, dass Sie mit ganzen Zahlen operieren.

*Commiten* Sie anschließend die Änderungen an der Quellcode-Datei.
Führen Sie hierfür beispielsweise die Befehle
```
    git add basic_operations.c
    git commit -m 'Teilaufgabe a'
```
aus.

## Teilaufgabe b) (1 Punkt)

Verwenden Sie nun anstelle von ganzen Zahlen (integern) Gleitkommazahlen, welche in *C* `float` heißen.  
Kopieren Sie zunächst den Quelltext der vorherigen Teilaufgabe in eine neue Datei mit dem Namen `basic_operations_float.c`.
Der einfachste Weg dafür ist den Kopierbefehl von Linux `cp` (kurz für *copy*) zu verwenden.
Führen Sie dazu den Befehl
```
    cp basic_operations.c basic_operations_float.c
```
im Terminal im *passenden* Ordner aus.
Ersetzten Sie nun in `basic_operations_float.c` alle Ganzzahlen-Deklaration durch Gleitkomma-Deklarationen.
> INFO: Eine *Deklaration* bezeichnet die Festlegung des Typs einer Variable.
Sie folgt immer dem Syntax: `<typ> <Name der Variable>;`.
Wird der Variable zusätzlich ein Wert zugewiesen `<typ> <Name der Variable> = <wert>;` so gilt sie als *initialisiert*.

Ändern Sie also den Typ der Variablen `a`, `b` und `c` von `int` zu `float`.
Zudem müssen Sie auch noch die Ausgabe an den geänderten Variablentyp anpassen.
Die Formatvorlage `%i` innerhalb von `printf` wird zum Darstellen von `int` verwendet - ändern Sie diese also zu `%f` für `floats`.  
Speichern und kompilieren Sie den geänderten Quelltext und führen die erzeugte Datei aus.   
Was hat die Änderung des Variablentyps bewirkt? Schreiben Sie Ihre Beobachtungen auch hier wieder als Kommentar in den Code.

Bei der Verwendung von `git status` wird Ihnen auffallen, dass die zuvor neu erzeugte Datei `basic_operations_float.c` von *git* noch nicht *getrackt*, also beobachtet, wird.
Fügen Sie also auch diese Datei mittels `git add basic_operations_float` zu Ihrem Repository hinzu und erzeugen Sie einen `Commit`.


## Teilaufgabe c) (1 Punkt)

Man kann einem Programm auch Werte übergeben ohne dass diese im Quelltext explizit erscheinen.
Das hat den Vorteil, dass das Programm nicht jedes mal neu kompiliert werden muss, wenn sich ein Wert ändert.
Eine Methode zur Werteübergabe sind sogenannte *Kommandozeilen-Argumente* oder *Aufrufparameter*.
Sie können einem Programm beispielsweise zwei Parameter mittels
```
    [Benutzername@Rechnername ~]$ ./<programm-name> <parameter 1> <parameter 2>
```
übergeben.  
Probieren Sie dies selbst aus indem Sie die Datei `parameter.c` kompilieren - das Programm berechnet die Division zweier Zahlen.
* Was passiert wenn ein Benutzer hier unsinnige Eingaben macht (Division durch Null, Buchstaben, etc.)? Schreiben Sie Ihre Antwort als Kommentar in das .c-File!
* Ändern Sie nun das Programm so, dass es stattdessen zwei Fließkommazahlen addiert.
* Laden Sie auch diese Änderungen ins Repository hoch.


## Teilaufgabe d) (1 Punkt)

Schreiben Sie ein Programm in die Datei `quader.c`, welches die Oberfläche eines Quaders berechnet.
Dem Programm sollen hierfür drei Fließkommazahlen - die drei Seitenlängen des Quaders - übergeben werden.

Hier ein kleines Beispiel, wie der Input und der Output eines solchen Programms aussehen könnten:
```
    [Benutzername@Rechnername ~]$ ./quader 1.2 2.5 3.2
    Ein Quader mit den Seitenlängen 1.200000, 2.500000 und 3.200000 hat die Oberfläche 29.680000
```

> Vergessen Sie nicht Ihren Fortschritt zu *commiten* und ins *GitLab*-Repository zu *pushen*!
