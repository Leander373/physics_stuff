# Automatisches Kompilieren mit _Makefiles_ - 15 Punkte

Heute geht es um die Erstellung eines _Makefiles_.<br>
Wie Sie den Präsentationen über Bibliotheken und Header-Dateien bereits entnehmen konnten, kann das manuelle Kompilieren simpler Programme zu recht aufwendigen Abfolgen von Befehlen in der Kommandozeile führen. Dies ist nicht sehr praktikabel, insbesondere da es schwierig ist, diese Abfolge an andere Personen weiterzugeben und man die nötigen Befehle nach einiger Zeit sicherlich wieder vergessen hat. Für komplexere Programme und Programmpakete trifft das umso mehr zu.

Hier sollen so genannte `Makefiles` Abhilfe schaffen. Ein _Makefile_ ist eine Bauanleitung, die beschreibt wie ein Programm aus einzelnen Quelltextdateien zusammengebaut werden muss. Mit dem Kommandozeilenbefehl `make` wird das `Makefile` im aktuellen Verzeichnis abgearbeitet und im Normalfall eine ausführbare Datei erstellt.

Als Anwendung dient uns die Analyse einer Zeitreihe von Messwerten die Sie mit `./datagen` erzeugen können. Sie wird Ihnen auch gleich als Diagramm am Bildschirm angezeigt. Falls Sie das Fenster schließen, können Sie sich das Diagramm später nochmals mit `./viewdata` anzeigen lassen. Die eigentlichen Daten befinden sich in der Textdatei `timeseries.dat`, die jedes Mal überschrieben wird wenn Sie `./datagen` ausführen.<br>
Wir wollen in dieser Aufgabe ein Programm schreiben, das diesen Datensatz auswertet. Als erster Schritt soll der Maximalwert der Daten und seine zeitliche Position bestimmt werden. Danach sollen Ereignisse, bei denen das Messsignal ausschlägt, sogenannte _Peaks_, identifiziert werden.

## Achtung!

In allen der folgenden Teilaufgaben ist es unbedingt nötig, sich an die vorgegebenen Dateinamen und Formatierungen zu halten!

## a) Einlesen des Datensatzes und suchen des Maximums in `maxfinder.c`. (6 Punkte)

Zuerst soll die grundlegende Funktionalität des Programms implementiert werden. Schreiben Sie dazu eine Funktion die die Daten aus `timeseries.dat` einliest und in zwei Arrays, jeweils eines für den Zeitpunkt `t` und eines für den Messwert `m`, speichert. Implementieren Sie auch eine Funktion, die den maximalen Wert $`m_\textrm{max}`$ im Array und den zugehörigen Zeitpunkt $`t_\textrm{max}`$ ausgibt.

Das Ausführen von `./maxfinder` sollte eine Ausgabe wie

```
Maximalwert von 220.272 bei 152 Sekunden gefunden.
```

liefern.

Sie können Ihr Ergebnis überprüfen, indem Sie es visuell mit dem Diagramm, das von `./viewdata` erzeugt wird, vergleichen.

Lagern Sie nun die Funktion fürs Einlesen der Dateien nach `util.c` und `util.h` und die Funktion zur Maximumsberechnung nach `stats.c` und `stats.h` aus. Achten Sie darauf, dass sich dadurch der Kompilierbefehl ändert!

## b) Schreiben Sie das `Makefile` für `maxfinder.c`. (1.5 Punkte)

Machen Sie sich zuerst mit den Grundlagen von `make` vertraut. Hier ein Link als mögliche Referenz: <https://www.c-howto.de/tutorial/makefiles/> (weitere Links siehe OLAT). Sie können natürlich auch jede andere Internetseite bzw. Quelle zu Rate ziehen.

Schreiben Sie ein _Makefile_, das die Abfolge von Kompilierbefehlen aus Teilaufgabe a beinhaltet. Durch die Eingabe von `make` soll man die ausführbare Datei `maxfinder` erhalten, deren Funktion die selbe wie zuvor sein soll.

## c) Implementieren Sie die Funktionen `mean` und `std_dev` in `stats.c`. (1.5 Punkte)

Dabei soll die Funktion `mean` den Mittelwert über ein übergebenes Werte-Array mit gegebener Länge bilden. Mathematisch ist dieser folgendermaßen

```math
\text{mean}(x) = \frac{1}{N} \sum^{N-1}_{i=0} x_i
```

definiert.

Für `std_dev` verhält es sich ähnlich, nur, dass eben die Standardabweichung

```math
\text{std\_dev}(x) = \sqrt{\frac{1}{N} \sum^{N-1}_{i=0} \left[ x_i - \text{mean}(x) \right]^2}
```

berechnet werden soll.

Dabei kann natürlich gleich die Funktion `mean` wiederverwendet werden. Für die Wurzelfunktion können Sie `<math.h>` einbinden.

## d) Schreiben Sie das Programm `peakfinder.c`. (4 Punkte)

In der `main` Funktion sollen zuerst, analog zu `maxfinder.c`, die Daten aus `timeseries.dat` eingelesen werden. Dafür können Sie natürlich wieder die selbe Funktion aus `util.c` einbinden. Als nächster Schritt soll die Anzahl der Datenpunkte ausgegeben werden und die Gesamtdauer, welche diese abdecken. Aussehen soll die Ausgabe wie folgt:

```
Anzahl der Punkte: 500, Abgedeckte Zeitdauer: 499.0 Sekunden
```

Binden Sie jetzt die Funktionen aus `stats.c` ein und geben Sie anschließend den Mittelwert und die Standardabweichung von `timeseries.dat` am Bildschirm in der Form

```
Mittelwert: 79.955466, Standardabweichung: 2.968561
```

aus.

Sie können Ihre Werte wieder mit den Angaben, die Ihnen von `./viewdata` gezeigt werden, überprüfen.

Schreiben Sie nun eine Funktion `find_peaks`, der die Messwerte übergeben werden. Die Funktion soll ein Array der gleichen Länge zurückgeben. Dieses soll zu Beginn mit Nullen gefüllt sein. Dann soll für jeden Messwert überprüft werden, ob dieser mehr als drei Standardabweichungen über oder unter dem Mittelwert liegt. Ist dies der Fall, soll im zurückgegebenen Array der zugehörige Wert auf `1` gesetzt werden, da an diesem Zeitpunkt ein Ereignis gefunden wurde.

Verwenden Sie das zurückgegebene Array nun in der `main`-Funktion, um dort eine Ausgabe der Form

```
Ereignis bei:  33.0 s
Ereignis bei: 272.0 s
Ereignis bei: 422.0 s
Insgesamt wurden 3 Ereignisse detektiert.
```

zu erzeugen.

Vergleichen Sie Ihre Ergebnis mit dem Diagramm von `./viewdata` und stellen Sie sicher, dass alle _Ereignisse_ erkannt wurden.

## e) Erstellen Sie ein gemeinsames Makefile für `peakfinder.c` und `maxfinder.c`. (2 Punkte)

Erweitern Sie das _Makefile_ so, dass der Befehl `make` neben `maxfinder` auch eine ausführbare Datei namens `peakfinder` aus dem Programmcode in `peakfinder.c` erzeugt.

> Tipp: Sie können ein _Target_ `make clean` definieren, das die `.o` Dateien und ausführbaren Dateien löscht, bevor sie neu erzeugt werden.
