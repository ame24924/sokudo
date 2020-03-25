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

template<typename T>
auto make_matrix(uint num_row, uint num_col, T value_min, T value_max, double sparseness)
{
  std::vector<std::vector<T>> mat(num_row, std::vector<T>(num_col));
  std::mt19937 e; // engine
  std::uniform_real_distribution<T> v_rand(value_min, value_max);
  std::uniform_real_distribution<double> sp_rand(0, 1);
  for (auto& vec : mat){
    for (auto& v : vec){
      if (sp_rand(e) < sparseness) continue;
      v = v_rand(e);
    }
  }

  return mat;
}

int main(){
	const uint num_element = 1E+5;
	const uint average = 100;
  EigenMat eigenmat = EigenMat::Random(num_element, num_element);
  //EigenMat eigenmat(num_element, num_element);
  //EigenSparseMat eigensmat(num_element, num_element);
  //printf("matrix start\n");
  //auto src = make_matrix<double>(num_element, num_element, 0.0, 1.0, 0.0);
  //printf("matrix end\n");

  //printf("initialize matrix...\n");
  //for (uint i = 0; i < num_element; ++i) {
  //	for (uint j = 0; j < num_element; ++j) {
  //		eigenmat(i, j) = src[i][j];
  //		if (src[i][j] != 0) {
  //			eigensmat.insert(i, j) = src[i][j];
  //		}
  //	}
  //}
  //printf("end initialize matrix\n");


  auto func = [eigenmat](){
        for(uint i = 1; i < 1E+5; ++i)
          auto m = eigenmat*eigenmat;
      };

  //auto func_smat = [eigensmat](){
  //      for(uint i = 1; i < 10000; ++i)
  //        auto m = eigensmat*eigensmat;
  //    };

  auto time = measure_time<std::chrono::duration<double>>(
      func
      );
  //auto time_smat = measure_time<std::chrono::duration<double>>(
  //    func_smat
  //    );


  std::cout << "time =  " << time << "[sec]\n";
  //std::cout << "time_smat =  " << time_smat << "[sec]\n";
  return 0;
}
