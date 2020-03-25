CPP = gfortran
OBJ = matmul.f90
#MKL =  -L${MKLROOT}/lib/intel64 -Wl,--no-as-needed -lmkl_gf_ilp64 -lmkl_sequential -lmkl_core -lpthread -lm -ldl #-Wall -fbacktrace -g
#LFLAGS = -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_gf_ilp64.a ${MKLROOT}/lib/intel64/libmkl_sequential.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -lpthread -lm -ldl -fdefault-integer-8 -m64 -I${MKLROOT}/include
MKL=


%.o: %.cpp

buld: O1 O2 O3

O1: ${OBJ}
	${CPP} -O1 ${MKL} -o o1 ${OBJ}

O2: ${OBJ}
	${CPP} -O2 ${MKL} -o o2 ${OBJ}

O3: ${OBJ}
	${CPP} -O3 ${MKL} -o o3 ${OBJ}
