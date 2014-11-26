 PROGRAM Principal;
 
BEGIN
  INTERVALO[ 0 .. 20 ]
    =>FILTER[ (x*x) % 3 == 0 ] =>FILTER[ x % 2 == 0 ]
    =>FOREACH[ COUT << x << "\n" ]; 
END.

