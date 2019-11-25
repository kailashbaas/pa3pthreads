Last name of Student 1: Baas
First name of Student 1: Kailash
Email of Student 1: kailashbaas@ucsb.edu
Last name of Student 2: Gamliel
First name of Student 2: Daniel
Email of Student 2: dgamliel@ucsb.edu



Report for Question 3 with Test 3.a
1 core:
    Block Mapping:
        Sequential time: 15.189627 s
    Block Cyclic Mapping (block size 1):
        Sequential time: 15.192219 s
    Block Cyclic Mapping (block size 16):
        Sequential time: 15.183655 s
2 cores:
    Block Mapping:
        Parallel time: 7.98041 s
        Speedup: 1.903
        Efficiency: 0.9515
    Block Cyclic Mapping (block size 1):
        Parallel time: 8.147946 s
        Speedup: 1.865
        Efficiency: 0.9325
    Block Cyclic Mapping (block size 16):
        Parallel time: 8.131611 s
        Speedup: 1.867
        Efficiency: 0.9335
4 cores:
    Block Mapping:
        Parallel time: 5.181484 s
        Speedup: 2.932
        Efficiency: 0.733
    Block Cyclic Mapping (block size 1):
        Parallel time: 5.445582 s
        Speedup: 2.79
        Efficiency: 0.6975
    Block Cyclic Mapping (block size 16):
        Parallel time: 5.442367 s
        Speedup: 2.79
        Efficiency: 0.6975
Block mapping performs the best, likely because it minimizes false sharing. Block cyclic mapping
has an efficiency drop when the number of cores is increased from 2 to 4, which may be because
false sharing occurs more frequently when there are more cores.

Report for Question 3 with Test 3.b
1 core:
    Block Mapping:
        Sequential time: 0.061202 s
    Block Cyclic Mapping (block size 1):
        Sequential time: 0.061368 s
    Block Cyclic Mapping (block size 16):
        Sequential time: 0.061157 s
2 cores:
    Block Mapping:
        Parallel time: 0.045432 s
        Speedup: 1.347
        Efficiency: 0.674
    Block Cyclic Mapping (block size 1):
        Parallel time: 0.032120 s
        Speedup: 1.91
        Efficiency: 0.955
    Block Cyclic Mapping (block size 16):
        Parallel time: 0.032137 s
        Speedup: 1.903
        Efficiency: 0.951
4 cores:
    Block Mapping:
        Parallel time: 0.027602 s
        Speedup: 2.217
        Efficiency: 0.554
    Block Cyclic Mapping (block size 1):
        Parallel time: 0.022143 s
        Speedup: 2.771
        Efficiency: 0.693
    Block Cyclic Mapping (block size 16):
        Parallel time: 0.021889 s
        Speedup: 2.793
        Efficiency: 0.698
Block cyclic mapping performs the best because it is better at evenly distributing the load among each core. Since
the matrix is upper triangular, block mapping results in the threads with lower ranks doing more work than if
block cyclic mapping is used.
