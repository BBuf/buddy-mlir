memref.global "private" @gv : memref<6x4xf32> = dense<[[0. , 1. , 2. , 3. ],
                                                       [10., 11., 12., 13.],
                                                       [20., 21., 22., 23.],
                                                       [30., 31., 32., 33.],
                                                       [40., 41., 42., 43.],
                                                       [50., 51., 52., 53.]]>

func.func @main() {
  %mem = memref.get_global @gv : memref<6x4xf32>
  %c0 = arith.constant 0 : index
  %c1 = arith.constant 1 : index
  %c2 = arith.constant 2 : index
  %load_vec1 = vector.load %mem[%c0, %c0] : memref<6x4xf32>, vector<[4]xf32>
  vector.print %load_vec1 : vector<[4]xf32>
  return
}
