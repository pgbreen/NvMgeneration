# NvMgeneration

Brutus: version used in Newton vs the Machine https://arxiv.org/abs/1910.07291

Note: Brutus is availbe as part of AMUSE and please cite https://arxiv.org/abs/1411.6671

You need to install mpfr and gmp and update the library location -L.. in the makefile 

if you have sudo you should be able to install by

sudo apt-get install libmpfr-dev libmpfr-doc libmpfr4 libmpfr4-dbg

These might alread be installed if not you'll have to build form source and update the -L to where you installed them.


If you need to compile mpfr from soruce please follow instructions on https://www.mpfr.org/

To build exe 

$make main.exe

input file:
N  time_end time_step tolerance word_lenght p_max
m1 x1_1 x1_2 x1_3 v1_1 ...
M2 x2_1

see indat, indat2
