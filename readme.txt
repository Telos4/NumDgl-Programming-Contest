Lösung für den Programmierwettbewerb:
=====================================

Mein Programm (C++) verwendet ein 12-stufiges Runge-Kutta-Verfahren der Ordnung 8 mit Schrittweitensteuerung (ode78).

Dafür hab ich eine Klasse geschrieben, die speziell auf Verfahren und Problem zugeschnitten ist.
Die Funktion für die Dgl ist direkt als Methode der Klasse implementiert, Start- und Endzeit, sowie Startwert sind fest reingehackt.
Startschrittweite ist so gewählt, dass der erste Schritt schon die gewünschte Genauigkeit hat. Die Fehlertoleranzen sind mit atol = 2.91e-10 und rtol = 1e-8 auch maximal gewählt.
Das Programm berechnet für einen Durchlauf genau 72 Zeitschritte.
Die Dgl selbst wurde durch ein multivariantes Horner-Schema vereinfacht, s.d. weitaus weniger Rechenoperationen zur Funktionsauswertung nötig sind.
Den dafür verwendeten Algorithmus habe ich mit abgegeben, ebenso das Paper auf dem der Algorithmus aufbaut.

Zum Verwenden des Programms muss man im main-Programm die Datei "impl.cpp" einbinden.
In dieser werden die Funktionen ode_init() und ode_calc() definiert, die das main-Programm aufruft.
Die ode_calc() Funktion ruft zum Lösen der Dgl die approximate()-Methode an einem statischen Objekt der Klasse auf.
ode_init() wird eigentlich nicht gebraucht, da der Konstruktor der Klasse alles übernimmt.

Es sind auch zwei makefiles bei der Abgabe, einmal für das vorgegebene main-Programm, und einmal für das Programm zum Horner-Schema.
Das makefile zum main-Programm benutzt die Optimierungsoption -O3, die sollte man ggfs. ausschalten.

Zum Schluss noch ein paar Zeitmessungen, die ich bei mir gemacht habe:
    Programm mit allen Optimierungsoptionen:
        durchschnittlich    0.0000767  sec

    Programm ohne Optimierungsoptionen:
        durchschnittlich    0.00014    sec
