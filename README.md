# segundo_parcial_ped-

ANALISIS DE ALGORITMOS
int CountMatches(const int values[], int n) {
  int count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (values[i] == j) {
        count++;
      }
    }
  }

  return count;
}
1. En este caso seria un O(n^2 ), puesto a que primero empieza con un for(n), seguido de otro y dentro de ese otro se encuentra un if, que se repetira n veces dependiendo del tamano del arreglo, al sumar esos dos: (O(n)+O(n)=2O(n), las constantes se eliminan y como nos queda uno anidado, se multiplican	(O(n)×O(n)), lo que resulta en O(n^2 ).


