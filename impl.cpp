/**
  *
  *	@author: Simon Pirkelmann
  *
  */
#ifndef IMPL
#define IMPL

#include "solver.hpp"

// Init braucht man nicht, da Konstruktor vorhanden ist, in dem bereits alles gemacht wird
inline void ode_init()
{

}

inline void ode_calc ( double * x )
{
    // Zum Lösen rufe approximate-Methode der Klasse auf
    CProg::solver.approximate ( x );
}

#endif
