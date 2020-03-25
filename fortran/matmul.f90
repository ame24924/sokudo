program main
  implicit none
  integer, parameter :: num_element=1000
  double precision :: mat(num_element, num_element)
  double precision :: mat2(num_element, num_element)
  double precision :: rnd=4d0
  integer  :: i, j
  integer :: t1, t2, t_rate, t_max, diff

  do i = 1, num_element; do j = 1, num_element
    call random_number(rnd)
    mat(i,j) = rnd
  enddo; enddo



  !mat(:,:) = 0d0
  mat2(:,:) = 0d0
  write(*,*) "end matrix"
  call system_clock(t1)
  do i = 1, 1
    !mat2 = matrix_mult(num_element, mat,mat)
    mat2 = matmul(mat,mat)
    !call dgemm('N', 'N', num_element, num_element, num_element, 1d0, mat, num_element, mat, num_element, 0d0, mat2, num_element)
    !call gemm(mat, mat, mat2)
  enddo
  call system_clock(t2, t_rate, t_max)
  if(t2 < t1) then
    diff = (t_max-t1) + t2 + 1
  else
    diff = t2 - t1
  endif

  write(*,"(A, F20.16)")"time = ", (t2-t1)/dble(t_rate)
  contains
    function matrix_mult(n, a, b)
      integer, intent(in) :: n
      double precision, intent(in) :: a(n,n), b(n,n)
      double precision matrix_mult(n, n)
      integer i, j, k
      matrix_mult(:,:) = 0d0
      do i = 1, n; do j = 1, n; do k=1, n
        matrix_mult(i, j) = matrix_mult(i, j) + a(i, k) * b(k, j)
      enddo; enddo; enddo
    end function matrix_mult
end program main
