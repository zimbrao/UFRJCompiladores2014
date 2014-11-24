 PROGRAM Principal;

BEGIN
  INTERVALO[ 0..10 ]=>FILTER[ 1 % 2 == 0 ]=>FOREACH[ COUT << 1 << "\n" ]; 
END.

