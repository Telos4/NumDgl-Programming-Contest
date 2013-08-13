#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

std::string multi_horner(std::string polynomial);
std::string horner(std::string polynomial, char variable);

int main()
{
    string f1 = "-160.0*x*x*y*y*y*y+160.0*x*x*x*y*y+4.0*y*x-\
180.0*y*y*y*y*y*y*y*y*y*y*x*x-100.0*x*y*y+220.0*x*x*y*y*y*y*y*y-\
20.0*y*y*y*y*y*y*y*y*y*y*y*y*y*y-240.0*x*x*x*x*y*y-2.0*y+40.0*x-20.0*x*x*x*x*x*x*x+\
80.0*x*x*x*x*x-100.0*x*x*x-60.0*y*y*y*y*y*y*y*y*y*y*y*y-100.0*y*y*y*y+140.0*y*y*y*y*y*y*y*y-\
20.0*y*y*y*y*y*y+20.0*y*y*y*y*y*y*y*y*y*y-60.0*x*x*x*x*x*y*y+180.0*x*x*x*x*y*y*y*y-\
120.0*x*x*x*y*y*y*y*y*y+100.0*x*x*x*y*y*y*y-180.0*x*y*y*y*y*y*y*y*y-\
120.0*y*y*y*y*y*y*y*y*x*x+180.0*y*y*y*y*y*y*y*y*y*y*x+100.0*x*x*x*y*y*y*y*y*y*y*y+\
100.0*x*x*y*y-180.0*x*y*y*y*y*y*y+180.0*x*y*y*y*y+\
100.0*x*x*x*x*y*y*y*y*y*y-180.0*x*x*x*x*x*y*y*y*y+100.0*y*y*y*y*y*y*y*y*y*y*y*y*x+\
100.0*x*x*x*x*x*x*y*y+40.0*y*y-4.0*y*y*y";

    string f2 = "40.0*y+2.0*x+240.0*x*y*y*y*y*y*y*y*y*y-300.0*x*x*x*x*y*y*y*y*y+\
120.0*x*x*x*x*x*y*y*y-360.0*x*x*y*y*y*y*y*y*y+400.0*x*x*x*y*y*y*y*y*y*y-\
100.0*y*x*x-200.0*x*y*y*y*y*y*y*y-60.0*x*x*x*x*y*y*y-\
320.0*x*x*x*y*y*y+160.0*x*x*y*y*y-20.0*y*x*x*x*x*x*x-\
300.0*y*y*y*y*y*y*y*y*y*x*x+200.0*x*y*y*y+80.0*y*x*x*x*x+\
420.0*x*x*y*y*y*y*y-320.0*x*y*y*y*y*y+240.0*x*x*x*y*y*y*y*y+\
120.0*y*y*y*y*y*y*y*y*y*y*y*x-20.0*y*y*y*y*y*y*y*y*y*y*y*y*y-60.0*y*y*y*y*y*y*y*y*y*y*y-20.0*y*y*y*y*y+20.0*y*y*y*y*y*y*y*y*y+\
140.0*y*y*y*y*y*y*y-2.0*y*y-100.0*y*y*y";


    /**
        Horner-Schema für f1
        */
    int number_of_multiplications = 0;
    int number_of_additions = 0;

    for (int i = 0; i < f1.length(); i++)
    {
        if (f1[i] == '*')
            number_of_multiplications++;
        if (f1[i] == '-' || f1[i] == '+')
            number_of_additions++;
    }

    cout << "number of multiplications for f1: " << number_of_multiplications << endl;
    cout << "number of additions for f1: " << number_of_additions << endl;

    std::string f_new = multi_horner(f1);
    cout << "result of multi-variant horner: " << endl << f_new << endl;

    number_of_multiplications = 0;
    number_of_additions = 0;

    for (int i = 0; i < f_new.length(); i++)
    {
        if (f_new[i] == '*')
            number_of_multiplications++;
        if (f_new[i] == '-' || f_new[i] == '+')
            number_of_additions++;
    }

    cout << "number of multiplications with multivariant horner for f1: " << number_of_multiplications << endl;
    cout << "number of additions with multivariant horner for f1: " << number_of_additions << endl << endl; // <- Zahl ist nicht ganz korrekt, da auch Negationen und Positionen (sagt man das so?) mitgezählt werden


    /**
        Horner-Schema für f2
        */
    number_of_multiplications = 0;
    number_of_additions = 0;

    for (int i = 0; i < f2.length(); i++)
    {
        if (f2[i] == '*')
            number_of_multiplications++;
        if (f2[i] == '-' || f2[i] == '+')
            number_of_additions++;
    }

    cout << "number of multiplications for f2: " << number_of_multiplications << endl;
    cout << "number of additions for f2: " << number_of_additions << endl;

    f_new = multi_horner(f2);
    cout << "result of multi-variant horner: " << endl << f_new << endl;

    number_of_multiplications = 0;
    number_of_additions = 0;

    for (int i = 0; i < f_new.length(); i++)
    {
        if (f_new[i] == '*')
            number_of_multiplications++;
        if (f_new[i] == '-' || f_new[i] == '+')
            number_of_additions++;
    }

    cout << "number of multiplications with multivariant horner for f2: " << number_of_multiplications << endl;
    cout << "number of additions with multivariant horner for f2: " << number_of_additions << endl; // <- Zahl ist nicht ganz korrekt, da auch Negationen und Positionen (sagt man das so?) mitgezählt werden

    return 0;
}

/**
    Algorithmus für ein Multivariantes Hornerschema eines Polynoms in zwei Variablen.
    Es wäre auch möglich den Algorithmus für > 2 Variablen umzusetzen, für den Zweck der Aufgabe reicht es aber.
    Das Ganze funktioniert nach einer Greedy-Heuristik, d.h. es wird immer die Variable ausgeklammert, die in den meisten Monomen vorkommt (vgl. auch das beiliegende Paper).
    Besonders effizient ist der Algorithmus nicht (viele String-Operationen und Rekursion), aber es müssen ja auch nur zwei Polynome vereinfacht werden.
    */
std::string multi_horner(std::string polynomial)
{
    vector<string> monomials;
    string temp;

    // Das Polynom in Monome aufteilen
    for (int i = 0; i < polynomial.length(); i++)
    {
        if ((polynomial[i] == '-' || polynomial[i] == '+') && temp.size() > 0)
        {
            monomials.push_back(temp);
            temp = polynomial[i];
        }
        else
        {
            temp += polynomial[i];
        }
    }
    monomials.push_back(temp);

    int monomials_with_x = 0, monomials_with_y = 0;

    // Zähle in wie vielen Monomen x bzw. y vorkommen
    for (int i = 0; i < monomials.size(); i++)
    {
        if (monomials[i].find('x') != string::npos)
            monomials_with_x++;
        if (monomials[i].find('y') != string::npos)
            monomials_with_y++;
    }

    // Abbruchkriterium für die Rekursion: Falls das verbleibende Polynom nur noch x- oder y-Variablen enthält ist man fertig
    if (monomials_with_x == 0 || monomials_with_y == 0)
    {
        // Dann auf den Rest noch einmal das normale Hornerschema anwenden
        if (monomials_with_x == 0)
            return horner(polynomial, 'y');
        else
            return horner(polynomial, 'x');
    }

    string result;
    stringstream new_polynomial;
    string A0, A1;

    // Wenn es mehr Monome mit x als mit y gibt
    if (monomials_with_x > monomials_with_y)
    {
        for (int i = 0; i < monomials.size(); i++)
        {
            // Es wird x ausgeklammert
            size_t pos = monomials[i].find('x');
            if (pos != string::npos)
            {
                // Variable löschen, es wird auch das Multiplikationszeichen '*' gelöscht
                monomials[i].erase(pos-1,2);

                // In A1 werden die Monome gespeichert, in denen die Variable vorkam
                A1 += monomials[i];
            }
            else
            {
                // In A0 werden Monome gespeichert, in denen die Variable nicht vorkam
                A0 += monomials[i];
            }
        }

        // Das Ergebnis wird in einen neuen String gespeichert
        // In A0 kommt nur eine Variable vor, also wird hier das normale Hornerschema angewendet
        // In A1 kommen eventuell wieder mehrere Variablen vor, also wird nochmal das multivariante Hornerschmema angewendet
        new_polynomial << horner(A0, 'y') << " + x * ( " << multi_horner(A1) << " )";
        result = new_polynomial.str();
    }
    else
    {
        for (int i = 0; i < monomials.size(); i++)
        {
            // Es wird y ausgeklammert
            size_t pos = monomials[i].find('y');
            if (pos != string::npos)
            {
                // Variable löschen, es wird auch das Multiplikationszeichen '*' gelöscht
                monomials[i].erase(pos-1,2);

                // In A1 werden die Monome gespeichert, in denen die Variable vorkam
                A1 += monomials[i];
            }
            else
            {
                // In A0 werden Monome gespeichert, in denen die Variable nicht vorkam
                A0 += monomials[i];
            }
        }

        // Das Ergebnis wird in einen neuen String gespeichert
        // In A0 kommt nur eine Variable vor, also wird hier das normale Hornerschema angewendet
        // In A1 kommen eventuell wieder mehrere Variablen vor, also wird nochmal das multivariante Hornerschmema angewendet
        new_polynomial << horner(A0, 'x') << " + y * ( " << multi_horner(A1) << " )";
        result = new_polynomial.str();
    }

    return result;
}

/**
    Algorithmus für das herkömmliche Hornerschema
    */
std::string horner(std::string polynomial, char variable)
{
    vector<string> monomials;
    string temp;
    string b;

    // Polynom in Monome aufteilen
    for (int i = 0; i < polynomial.length(); i++)
    {
        if ((polynomial[i] == '-' || polynomial[i] == '+') && temp.size() > 0)
        {
            monomials.push_back(temp);
            temp = polynomial[i];
        }
        else
        {
            temp += polynomial[i];
        }
    }
    monomials.push_back(temp);

    int monomials_with_variable = 0;
    for (int i = 0; i < monomials.size(); i++)
    {
        if (monomials[i].find(variable) != string::npos)
            monomials_with_variable++;
    }

    // Abbruchbedingung für Rekursion: Wenn nur noch konstante Monome übrig sind ist man fertig
    if (monomials_with_variable == 0)
    {
        return polynomial;
    }


    string result;
    string A0, A1;

    // Alle Monome durchlaufen
    for (int i = 0; i < monomials.size(); i++)
    {
        // Überprüfen ob das Monom die Variable enthält
        size_t pos = monomials[i].find(variable);

        // Wenn ja, dann wird die Variable ausgeklammert
        if (pos != string::npos)
        {
            // Variable löschen
            monomials[i].erase(pos-1,2);

            A1 += monomials[i];
        }
        else
        {
            A0 += monomials[i];
        }
    }

    stringstream new_polynomial;
    // Das neue Polynom besteht aus einem konstanten Teil A0 und einem Teil A1, aus dem die Variable ausgeklammert wurde
    // Auf A1 wird rekursiv wieder das Hornerschema angewendet
    new_polynomial << A0 << " + " << variable << " * ( " << horner(A1, variable) << " )";

    result = new_polynomial.str();

    return result;
}
