# building
you need the following installed:
1. gcc compiled with cross platform compiler
2. cmake
3. make (used in the build.py)
4. ninja (not completly neccesry, requires manual compilation!)
5. python3 (not required but recomended for easy compilation)
6. qemu (also not required but recomended if you want to run it from the build.py)

when you have all of the required stuff installed follow the guide:
## manual
1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make`

## automatic
1. `python3 build.py --build` (build, check the -h tag for more info on it!)

