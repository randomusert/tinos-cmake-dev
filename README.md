# tinos-cmake
this os is made in c with cmake

# prerequisets
* gcc with cross platform compiler
* ninja (windows)
* cmake
* wsl (windows, and not neccery)

# building

1. 
 ```bash
      mkdir build
   ```

this will make a folder called build where we can run cmake
2. 
```bash
      cd build
   ```

3. 
 ```bash
      cmake ..
   ```
this will generate the makefile for make or if you chose ninja and are building in windows it will generate build.ninja

4. 
```bash
      make
   ```
or

4. 
```bash
      ninja
   ```

