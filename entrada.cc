 PROGRAM Principal;
 
BEGIN
  INTERVALO[ 1.0 .. 20.0 ]
    //=>FILTER[ x % 2 == 0 ]
    =>FOREACH[ COUT << x << "\n" ]; 
END.

