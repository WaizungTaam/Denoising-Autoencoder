/*
Copyright 2016 WaizungTaam.  All rights reserved.

License:       Apache License 2.0
Email:         waizungtaam@gmail.com
Creation time: 2016-07-15
Last modified: 2016-07-15

*/

#include <iostream>
#include <iomanip>
#include "../src/dA.h"
#include "../src/math/matrix.h"
#include "../src/math/utils.h"

int main() {
  int num_epochs = 1000, idx_epoch, 
      num_vis = 8, num_hid_1 = 8, num_hid_2 = 2;
  double lr_1 = 1e-3, cl_1 = 1e-2, lr_2 = 1e-3, cl_2 = 1e-2;
  Matrix data_train(100, num_vis, "binomial", 1.0, 0.5),
         data_test(4, num_vis, "binomial", 1.0, 0.5);
  dA encoder_1(num_vis, num_hid_1),
     encoder_2(num_vis, num_hid_2);
  for (idx_epoch = 0; idx_epoch < num_epochs; ++idx_epoch) {
    encoder_1.train(data_train, lr_1, cl_1);
    encoder_2.train(data_train, lr_2, cl_2);
    std::cout << idx_epoch << "\t";
    std::cout << std::setprecision(8) << std::setw(10) << std::left << std::setfill('0') 
              << nn::pow(data_train - encoder_1.reconstruct(data_train), 2).sum()
                 / data_train.shape()[0] / data_train.shape()[1] << "\t";
    std::cout << std::setprecision(8) << std::setw(10) << std::left << std::setfill('0') 
              << nn::pow(data_train - encoder_2.reconstruct(data_train), 2).sum() 
                 / data_train.shape()[0] / data_train.shape()[1] << "\n";
  }
  std::cout << data_test << std::endl;
  std::cout << encoder_1.reconstruct(data_test) << std::endl;
  std::cout << encoder_2.reconstruct(data_test) << std::endl;
  return 0;
}