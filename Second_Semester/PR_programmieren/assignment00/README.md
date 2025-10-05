# Aufgabe 00 (2 Punkte)

Wie bereits angekündigt verwenden wir zum Verteilen der Aufgaben und zum Upload Ihrer Arbeiten den _GitLab_ Server der Universität. Wenn Sie diese Seite in Ihrem Browser lesen können sind Sie also schon auf dem richtigen Weg.

Die Seite die Sie hier auf _GitLab_ sehen ist ein sogenanntes _Repository_, welches nicht nur aus dieser "Aufgabenseite" besteht, sondern auch aus einer Ordnerstruktur und darin befindlichen Dateien. Dieses _Repository_ können Sie "clonen", das heißt, Sie können sich davon eine lokale Kopie auf Ihren Rechner laden. Mit dieser Kopie können Sie dann arbeiten. Wenn Ihre Arbeit einen Zustand erreicht hat den Sie gerne zentral speichern (d.h. abgeben) würden, können Sie Ihre lokal bearbeitete Kopie wieder zum _GitLab_ _Repository_ "pushen", das heißt Ihre lokalen Änderungen werden in das zentrale _Repository_ übernommen. Schlussendlich wird Ihr _Repository_ in dem Zustand von uns bewertet, den Sie innerhalb des Zeitrahmens als letztes "gepusht" haben.

Um ein _Repository_ "clonen" zu können müssen Sie zuerst eine Kommandozeile (_Terminal_) öffnen, hierzu bietet sich etwa das `gnome-terminal` an. In vielen Linux Benutzeroberflächen lässt sich dieses, oder eine vergleichbares Terminal, mit der Tastenkombination `Strg`+`Alt`+`t` öffnen. Alternativ können Sie auch das Starter-Menü nach einem entsprechenden Eintrag durchsuchen, und so zu einem Terminal kommen.

Nachdem Sie das _Terminal_ gestartet haben, sehen Sie ein Fenster, in dem so etwas wie:

```
Benutzername@Rechnername:~$
```

steht. Rechts davon sollte der Cursor blinken, was bedeutet, dass das _Terminal_ auf Ihre Eingaben wartet. Es lassen sich Befehle eingeben. Diese Befehle beziehen sich immer auf das derzeitige Arbeitsverzeichnis. Das aktuelle Arbeitsverzeichnis lässt sich mit dem Befehl `pwd` ausgeben. Wenn Sie das jetzt ausprobieren sollten Sie den Pfad Ihres _Home_ Verzeichnisses ausgegeben bekommen. Also so etwas wie:

```
/home/Benutzername
```

Mit dem Befehl `ls` können Sie sich anzeigen lassen was sich im aktuellen Arbeitsverzeichnis befindet. Das können zum Einen andere Verzeichnisse, aber auch Dateien sein. In den meisten Linux Umgebungen ist voreingestellt das Verzeichnisse mit einer anderen Farbe ausgegeben werden als Dateien. Um sicher zu gehen können Sie aber auch `ls -l` eingeben, woraufhin Sie eine Liste des Verzeichnisinhalts mit mehr Details bekommen. Wenn das erste Zeichen in einer Zeile ein `d` ist, handelt es sich bei dem Verzeichniseintrag um ein weiteres Verzeichnis, bei einem `-` um eine Datei.

Zum Anlegen eines neuen Verzeichnisses können Sie den Befehl

```
mkdir Verzeichnisname
```

verwenden. Um in ein anderes Verzeichnis zu wechseln, geben Sie

```
cd Verzeichnisname
```

ein. In das übergeordnete Verzeichnis gelangen Sie jeweils mit `cd ..` zurück.

> Tipp: Verwenden Sie die Autovervollständigung des _Terminals_ indem Sie die `Tabulator`-Taste drücken. Wenn Sie z.B. von Ihrem _Home_ Verzeichnis ins darunter liegende _Documents_ (bzw. _Dokumente_) Verzeichnis wechseln wollen, geben Sie erst `cd D` ein und drücken dann auf `Tabulator`. Sie werden einen Piepton vernehmen, der bedeutet dass die Autovervollständigung kein eindeutiges Resultat geliefert hat. Nach nochmaligem Drücken der `Tabulator`-Taste werden die verbleibenden Optionen angezeigt. Wenn Sie nun `oc` (bzw. `ok`) an das zuvor getippte `D` anhängen und nochmals auf `Tabulator` drücken, sollte das _Terminal_ Ihre Eingabe zu `cd Documents/` (bzw. `cd Dokumente/`) komplettieren.

## Teilaufgabe a)

Wechseln Sie in das _Documents_ (bzw. _Dokumente_) Verzeichnis in Ihrem _Home_ Verzeichnis und legen Sie ein Verzeichnis `PR_programmieren` an. Wechseln Sie nun in das neu erstellte Verzeichnis.

Um Ihr _Repository_ von _GitLab_ zu "clonen" brauchen Sie zunächst den zugehörigen Link. Klicken Sie dazu auf das blau unterlegte Feld _Clone_ am rechten oberen Rand der Seite und kopieren Sie den Link der unter _Clone with HTTPS_ angegeben ist. Geben Sie nun

```
git clone
```

im _Terminal_ ein und fügen danach den eben kopierten _Clone_-Link ein. Das sollte in etwas so ausschauen

```
git clone https://git.uibk.ac.at/astro/PFP/SS2025/<GruppenNr>/<BenutzerID>/assignment00.git
```

wobei `<GruppenNr>` und `<BenutzerID>` hier natürlich als Platzhalter für Ihre Daten fungieren.

Um zu überprüfen ob das "Clonen" richtig funktioniert hat, verwenden Sie wieder `ls`. Sie sollten nun ein neues Unterverzeichnis haben, das den selben Namen wie Ihr _Repository_ hat. Wechseln Sie mit `cd` in das erzeugte Verzeichnis des _Repository_.

## Teilaufgabe b)

In dem neuen Unterverzeichnis finden Sie nun alle Dateien wieder, die auch in Ihrem _GitLab_ _Repository_ sind. Es ist also eine lokale Kopie. Öffnen Sie nun die Datei `hello.c` mit dem Befehl:

```
code hello.c
```

Dabei starten Sie mittels `code` den Editor _Visual Studio Code_, also ein Programm mit dem man Code bearbeiten kann.

Wie Sie sehen sollten, ist die Datei `hello.c` leer. Schreiben Sie nun Ihren ersten C-Quellcode in die Datei

```c
#include <stdio.h>

int main() {
        printf("Hello world!\n");
return 0;        
}
```

und speichern Sie diese. Die Datei die den C-Quellcode enthält lässt sich nicht direkt ausführen, denn der Quellcode muss in der Programmiersprache C erst, mit Hilfe eines _Compilers_, in Maschinencode übersetzt werden. Geben Sie dazu den Befehl

```
gcc -Wall -Werror -std=gnu90 hello.c
```

in das _Terminal_ ein. Mit dem Befehl `gcc` startet man den _GNU C Compiler_, den wir in diesem Praktikum grundsätzlich verwenden werden, und lässt Sie Ihren Quellcode kompilieren. Wenn Sie alles richtig gemacht haben, sollten Sie keine Ausgabe von `gcc` erhalten, sondern nur erneut eine Eingabeaufforderung des _Terminals_. Falls Sie einen Fehler im Quellcode haben, wird `gcc` versuchen mit Fehlermeldungen darauf hinzuweisen. Die ausführbare Datei, das Programm, das den Maschinencode enthält, finden Sie nun im selben Verzeichnis. Da wir es nicht anders spezifiziert haben sollte es `a.out` heißen. Führen Sie Ihr erstes eigenes Programm nun mit

```
./a.out
```

im _Terminal_ aus. Dabei gibt man mit `./` an, dass man das Programm `a.out` aus dem aktuellen Verzeichnis ausführen will. Der Punkt `.` bezeichnet immer das aktuelle Verzeichnis, genauso wie `..` immer das übergeordnete Verzeichnis symbolisiert.

Sie sollen nun selbstständig herausfinden wie man `gcc` aufrufen muss damit das _compilierte_ Programm den Namen `ls` anstatt von `a.out` erhält. Um das herauszufinden können Sie z.B. `man gcc` im _Terminal_ ausführen. Der Befehl `man` liefert, falls vorhanden, eine Beschreibung zum nachgestellten Befehl. Falls Sie mit `man` nicht fündig werden, bemühen Sie bitte die Internet-Suchmaschine Ihres Vertrauens.

Probieren Sie nun aus was passiert wenn Sie `ls` ausführen.

Um tatsächlich sicher sein zu können welcher Befehl vom _Terminal_ ausgeführt wird, kann man `which <Befehl>` verwenden. Es wird einem dann der Speicherort des jeweiligen Befehls zurückgegeben anhand dessen man mehrere Befehle auch bei gleichen Namen unterscheiden kann.

## Teilaufgabe c)

Nun sollen Sie Ihr erstes Programm `hello.c` abgeben bzw. in Ihr _GitLab-Repository_ "pushen". Dazu können Sie sich erst von _Git_ über getätigte Änderungen aufklären lassen. Geben Sie dazu

```
git status
```

ins _Terminal_ ein. Sie sollten sehen, dass sich `hello.c` seit dem letzten versionierten Stand geändert hat. Um _Git_ mitzuteilen, dass diese Änderungen Teil der nächsten Version werden sollen, geben Sie

```
git add hello.c
```

ein. Ein nochmaliges Ausführen von `git status` sollte die Änderung widerspiegeln. Um nun die neue Version festzuhalten, geben Sie

```
git commit -m "kurze Beschreibung der Änderung"
```

ein.

Tipp: Wenn Sie alle geänderten Dateien in die neue Version übernehmen wollen, können Sie sich `git add` sparen und die neue Version direkt mit `git commit -a -m "kurze Beschreibung"` festhalten. Dabei steht `-a` für alle Dateien in dem Verzeichnis.

Die neueste Version ist bis jetzt nur in Ihrem lokalem _Repository_ festgehalten, das ja ursprünglich ein Klon Ihres _Repositorys_ auf _GitLab_ war. Man erfährt, erneut durch die Eingabe von `git status`, wie sich das lokale _Repository_ zum Zentralen auf _GitLab_ verhält. Am Anfang der Ausgabe sollte etwas ähnliches stehen wie:

```
Ihr Branch ist 1 Commit vor 'origin/main'.
```

`origin` bezeichnet hierbei den Ursprung, also woher Sie Ihren lokalen Klon abgeleitet haben. Um das zentrale _Repository_ auf _GitLab_, den `origin`, auf den aktuellen Stand der Entwicklung zu bringen, geben Sie

```
git push
```

ein. Erst wenn dieser Schritt erfolgreich durchgeführt wurde haben wir Einblick in Ihre Arbeit und können diese benoten, vergessen Sie das also nicht! Um sicher zu gehen dass Sie alles richtig gemacht haben, können Sie nun auch in der Web-Oberfläche von _GitLab_ nachsehen ob Ihre geänderten Dateien wirklich da sind.

Für solch einfache Programme wie unser `hello.c` ist _Git_ zugegebenermaßen etwas übertrieben. Sobald die Programme komplizierter werden und Sie möglicherweise in einem Team arbeiten, werden Sie nicht mehr ohne die Features einer Versionsverwaltung wie _Git_ arbeiten können und wollen. Zudem findet _Git_ Anwendung in (fast) allen Arbeitsgruppen der Physik-Institute in Innsbruck, in (fast) allen Softwareentwicklungsfirmen und vielen anderen Bereichen der Privatwirtschaft weltweit. Die Verwendung von _Git_ ist also ein Skill den Sie noch oft anwenden können.
