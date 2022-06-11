func.func @main() {
  %0 = arith.constant dense<2.0> : vector<3x2xf32>
  vector.print %0 : vector<3x2xf32>

  %1 = arith.constant dense<3.0> : vector <3x2xf32>
  vector.print %1 : vector<3x2xf32>

  %2 = vector.shuffle %0, %1[1, 0, 3, 2] : vector<3x2xf32>, vector<3x2xf32>
  vector.print %2 : vector<4x2xf32>
    
  %3 = arith.constant dense<4.0> : vector<4x3xf32>
  vector.print %3 : vector<4x3xf32>

  %4 = arith.constant dense<5.0> : vector<5x3xf32>
  vector.print %4 : vector<5x3xf32>

  %5 = vector.shuffle %3, %4[1, 7, 5, 3, 4, 2] : vector<4x3xf32>, vector<5x3xf32>
  vector.print %5 : vector<6x3xf32>

  %6 = arith.constant dense<4.0> : vector<2x2xf32>
  vector.print %6 : vector<2x2xf32>

  %7 = arith.constant dense<10.0> : vector<2x2xf32>
  vector.print %7 : vector<2x2xf32>

  %8 = vector.shuffle %6, %7[0, 1, 2, 3] : vector<2x2xf32>, vector<2x2xf32>
  vector.print %8 : vector<4x2xf32>

  return
}
