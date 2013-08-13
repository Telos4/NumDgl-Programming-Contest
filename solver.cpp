/**
  *
  *	@author: Simon Pirkelmann
  *
  */
#include "solver.hpp"

// Statisches Objekt erstellen
CProg CProg::solver;

/**
    Tableau für ode78
    */
#define a0  0.05555555555555555
#define a1  0.02083333333333333
#define a2  0.0625
#define a3  0.03125
#define a5  0.09375
#define a6  0.3125
#define a8  -1.171875
#define a9  1.171875
#define a10  0.0375
#define a13  0.1875
#define a14  0.15
#define a15  0.04791013711111111
#define a18  0.1122487127777778
#define a19  -0.02550567377777778
#define a20  0.01284682388888889
#define a21  0.01691798978729228
#define a24  0.3878482784860432
#define a25  0.03597736985150033
#define a26  0.1969702142156661
#define a27  -0.1727138523405018
#define a28  0.0690957533591923
#define a31  -0.6342479767288541
#define a32  -0.1611975752246041
#define a33  0.1386503094588253
#define a34  0.9409286140357562
#define a35  0.211636326481944
#define a36  0.1835569968390454
#define a39  -2.468768084315593
#define a40  -0.2912868878163005
#define a41  -0.02647302023311738
#define a42  2.8478387641928
#define a43  0.2813873314698498
#define a44  0.1237448998633147
#define a45  -1.215424817395888
#define a48  16.67260866594577
#define a49  0.9157418284168179
#define a50  -6.056605804357471
#define a51  -16.00357359415618
#define a52  14.84930308629766
#define a53  -13.37157573528985
#define a54  5.134182648179638
#define a55  0.2588609164382643
#define a58  -4.774485785489205
#define a59  -0.4350930137770325
#define a60  -3.049483332072242
#define a61  5.5779200399361
#define a62  6.15583158986104
#define a63  -5.062104586736939
#define a64  2.193926173180679
#define a65  0.1346279986593349
#define a66  0.8224275996265075
#define a69  -11.65867325727766
#define a70  -0.7576221166909362
#define a71  0.7139735881595816
#define a72  12.07577498689006
#define a73  -2.127659113920403
#define a74  1.990166207048955
#define a75  -0.2342864715440403
#define a76  0.1758985777079423

#define b10  0.04174749114153024
#define b15  -0.05545232861123931
#define b16  0.2393128072011801
#define b17  0.703510669403443
#define b18  -0.7597596138144609
#define b19  0.6605630309222863
#define b110  0.1581874825101233
#define b111  -0.2381095387528628
#define b112  0.25

#define b20  0.0295532136763535
#define b25  -0.8286062764877971
#define b26  0.3112409000511183
#define b27  2.467345190599887
#define b28  -2.546941651841909
#define b29  1.443548583676775
#define b210  0.07941559588112729
#define b211  0.04444444444444445

void CProg::approximate ( double * x_res )
{
    // Startwerte setzen
    x_start[0] = 0.5;
    x_start[1] = 0.0;

    m_h = 0.01195937975973669;   // Startschrittweite optimal gewählt

    t_temp = 0.0;

    while ( t_temp < 10.0 )
    {
        if ( t_temp + m_h > 10.0 )
        {
            m_h = 10.0 - t_temp;
        }


        do
        {
            // Neuer Zeitpunkt
            t_neu = t_temp + m_h;

            // k0 berechnen
            f ( x_start[0], x_start[1], k0[0], k0[1] );

            // k's berechnen

            // k1:
            f ( x_start[0] + m_h * a0 * k0[0], x_start[1] + m_h * a0 * k0[1], k1[0], k1[1] );

            // k2:
            f ( x_start[0] + m_h * ( a1 * k0[0] + a2 * k1[0] ), x_start[1] + m_h * ( a1 * k0[1] + a2 * k1[1] ), k2[0], k2[1] );

            // k3:
            f ( x_start[0] + m_h * ( a3 * k0[0] + a5 * k2[0] ), x_start[1] + m_h * ( a3 * k0[1] + a5 * k2[1] ), k3[0], k3[1] );

            // k4:
            f ( x_start[0] + m_h * ( a6 * k0[0] + a8 * k2[0] + a9 * k3[0] ), x_start[1] + m_h * ( a6 * k0[1] + a8 * k2[1] + a9 * k3[1] ), k4[0], k4[1] );

            // k5:
            f ( x_start[0] + m_h * ( a10 * k0[0] + a13 * k3[0] + a14 * k4[0] ), x_start[1] + m_h * ( a10 * k0[1] + a13 * k3[1] + a14 * k4[1] ), k5[0], k5[1] );

            // k6:
            f ( x_start[0] + m_h * ( a15 * k0[0] + a18 * k3[0] + a19 * k4[0] + a20 * k5[0] ), x_start[1] + m_h * ( a15 * k0[1] + a18 * k3[1] + a19 * k4[1] + a20 * k5[1] ), k6[0], k6[1] );

            // k7:
            f ( x_start[0] + m_h * ( a21 * k0[0] + a24 * k3[0] + a25 * k4[0] + a26 * k5[0] + a27 * k6[0] ), x_start[1] + m_h * ( a21 * k0[1] + a24 * k3[1] + a25 * k4[1] + a26 * k5[1] + a27 * k6[1] ), k7[0], k7[1] );

            // k8:
            f ( x_start[0] + m_h * ( a28 * k0[0] + a31 * k3[0] + a32 * k4[0] + a33 * k5[0] + a34 * k6[0] + a35 * k7[0] ), x_start[1] + m_h * ( a28 * k0[1] + a31 * k3[1] + a32 * k4[1] + a33 * k5[1] + a34 * k6[1] + a35 * k7[1] ), k8[0], k8[1] );

            // k9:
            f ( x_start[0] + m_h * ( a36 * k0[0] + a39 * k3[0] + a40 * k4[0] + a41 * k5[0] + a42 * k6[0] + a43 * k7[0] + a44 * k8[0] ), x_start[1] + m_h * ( a36 * k0[1] + a39 * k3[1] + a40 * k4[1] + a41 * k5[1] + a42 * k6[1] + a43 * k7[1] + a44 * k8[1] ), k9[0], k9[1] );

            // k10:
            f ( x_start[0] + m_h * ( a45 * k0[0] + a48 * k3[0] + a49 * k4[0] + a50 * k5[0] + a51 * k6[0] + a52 * k7[0] + a53 * k8[0] + a54 * k9[0] ), x_start[1] + m_h * ( a45 * k0[1] + a48 * k3[1] + a49 * k4[1] + a50 * k5[1] + a51 * k6[1] + a52 * k7[1] + a53 * k8[1] + a54 * k9[1] ), k10[0], k10[1] );

            // k11:
            f ( x_start[0] + m_h * ( a55 * k0[0] + a58 * k3[0] + a59 * k4[0] + a60 * k5[0] + a61 * k6[0] + a62 * k7[0] + a63 * k8[0] + a64 * k9[0] + a65 * k10[0] ), x_start[1] + m_h * ( a55 * k0[1] + a58 * k3[1] + a59 * k4[1] + a60 * k5[1] + a61 * k6[1] + a62 * k7[1] + a63 * k8[1] + a64 * k9[1] + a65 * k10[1] ), k11[0], k11[1] );

            // k12:
            f ( x_start[0] + m_h * ( a66 * k0[0] + a69 * k3[0] + a70 * k4[0] + a71 * k5[0] + a72 * k6[0] + a73 * k7[0] + a74 * k8[0] + a75 * k9[0] + a76 * k10[0] ), x_start[1] + m_h * ( a66 * k0[1] + a69 * k3[1] + a70 * k4[1] + a71 * k5[1] + a72 * k6[1] + a73 * k7[1] + a74 * k8[1] + a75 * k9[1] + a76 * k10[1] ), k12[0], k12[1] );


            // Lösung des 1. Verfahrens berechnen
            x_1[0] = x_start[0] + m_h * ( b10 * k0[0] + b15 * k5[0] + b16 * k6[0] + b17 * k7[0] + b18 * k8[0] + b19 * k9[0] + b110 * k10[0] + b111 * k11[0] + b112 * k12[0] );
            x_1[1] = x_start[1] + m_h * ( b10 * k0[1] + b15 * k5[1] + b16 * k6[1] + b17 * k7[1] + b18 * k8[1] + b19 * k9[1] + b110 * k10[1] + b111 * k11[1] + b112 * k12[1] );


            // Lösung des 2. Verfahrens berechnen
            x_2[0] = x_start[0] + m_h * ( b20 * k0[0] + b25 * k5[0] + b26 * k6[0] + b27 * k7[0] + b28 * k8[0] + b29 * k9[0] + b210 * k10[0] + b211 * k11[0] );
            x_2[1] = x_start[1] + m_h * ( b20 * k0[1] + b25 * k5[1] + b26 * k6[1] + b27 * k7[1] + b28 * k8[1] + b29 * k9[1] + b210 * k10[1] + b211 * k11[1] );


            // Fehlerschätzer
            // Fehlerschranken atol = 2.91e-10 und rtol = 1e-8 liefern die gewünschte Genauigkeit
            err  = fabs ( x_1[0] - x_2[0] ) / ( 2.91e-10 + fabs ( x_2[0] ) * 1e-8 );
            temp = fabs ( x_1[1] - x_2[1] ) / ( 2.91e-10 + fabs ( x_2[1] ) * 1e-8 );

            // Maximale Komponente finden
            if ( temp > err )
            {
                err = temp;
            }

            // Mit rho = 0.725 ist er nochmal einen Tick schneller
            m_h *= pow ( 0.725 / err, 0.125 );
        }
        while ( err > 1.0 );

        // Neu berechnete Lösung übernehmen
        x_start[0] = x_1[0];
        x_start[1] = x_1[1];

        // Neuen Zeitpunkt übernehmen
        t_temp = t_neu;
    }

    // Berechnete Lösung speichern
    x_res[0] = x_1[0];
    x_res[1] = x_1[1];
}
