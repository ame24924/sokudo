#include<Eigen/Core>
#include<Eigen/SparseCore>
#include<chrono>
#include<random>
#include<iostream>
using EigenMat = Eigen::MatrixXd;
using EigenSparseMat = Eigen::SparseMatrix<double>;

template<typename D, typename F>
auto measure_time( F const& func  ){

  const auto start = std::chrono::steady_clock::now();
  func();
  return std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now()-start).count();

}

int main(){
	const uint num_element = 1000;
	const uint average = 100;
  EigenMat eigenmat = EigenMat::Random(num_element, num_element);

  std::cout << "start\n";
  auto func = [eigenmat](){
        for(uint i = 0; i < 1E+0; ++i)
          auto m = eigenmat*eigenmat;
      };

  auto time = measure_time<std::chrono::duration<double>>(
      func
      );

  std::cout << "time =  " << time << "[sec]\n";
  return 0;
}
