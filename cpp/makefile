CPP = g++
OBJ = eigen.cpp
EIGEN_ROOT=/usr/include/eigen3

%.o: %.cpp

buld: O1 O1_NDEB O2 O2_NDEB O3 O3_NDEB

O1: ${OBJ}
	${CPP} -O1 -I${EIGEN_ROOT} -o o1 ${OBJ} -DDEBUG

O1_NDEB: ${OBJ}
	${CPP} -O1 -I${EIGEN_ROOT} -o o1_ndeb ${OBJ} -DNDEBUG

O2: ${OBJ}
	${CPP} -O2 -I${EIGEN_ROOT} -o o2 ${OBJ} -DDEBUG

O2_NDEB: ${OBJ}
	${CPP} -O2 -I${EIGEN_ROOT} -o o2_ndeb ${OBJ} -DNDEBUG

O3: ${OBJ}
	${CPP} -O3 -I${EIGEN_ROOT} -o o3 ${OBJ} -DDEBUG

O3_NDEB: ${OBJ}
	${CPP} -O3 -I${EIGEN_ROOT} -o o3_ndeb ${OBJ} -DNDEBUG

