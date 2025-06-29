# Setting Up i686 GCC Compiler from Source

This guide explains how to build and install the i686 GCC compiler from source using `make`.

## Notes
Make sure you are going to build 13.2.0 version of gcc as the OS building is working on that version.


## Prerequisites

Before starting, ensure you have the following installed on your system:
- `build-essential` (includes `make`, `gcc`, etc.)
- `libgmp-dev`, `libmpfr-dev`, `libmpc-dev` (required for GCC)
- `wget` or `curl` (to download source files)
- Sufficient disk space (at least 10 GB)

You can install these dependencies using the following command:

```bash
sudo apt update
sudo apt install build-essential libgmp-dev libmpfr-dev libmpc-dev wget
```

## Step 1: Download GCC Source Code

Visit the [GCC releases page](https://gcc.gnu.org/releases.html) and download the desired version of GCC. Alternatively, use `wget` to download the source:

```bash
wget https://ftp.gnu.org/gnu/gcc/gcc-<version>/gcc-<version>.tar.gz
```

Replace `<version>` with the desired GCC version (e.g., `12.3.0`).

## Step 2: Extract the Source Code

Extract the downloaded tarball:

```bash
tar -xvzf gcc-<version>.tar.gz
cd gcc-<version>
```

## Step 3: Create a Build Directory

It is recommended to build GCC in a separate directory to keep the source directory clean:

```bash
mkdir build
cd build
```

## Step 4: Configure GCC for i686 Target

Run the `configure` script to set up the build environment for the i686 target:

```bash
../configure --target=i686 --prefix=/usr/local/gcc-i686 --enable-languages=c,c++ --disable-multilib
```

- `--target=i686`: Specifies the target architecture.
- `--prefix=/usr/local/gcc-i686`: Specifies the installation directory.
- `--enable-languages=c,c++`: Builds support for C and C++ languages.
- `--disable-multilib`: Disables multilib support (optional).

## Step 5: Build GCC

Start the build process using `make`. This step can take several hours depending on your system's performance:

```bash
make -j$(nproc)
```

The `-j$(nproc)` flag uses all available CPU cores to speed up the build.

## Step 6: Install GCC

Once the build is complete, install GCC to the specified prefix directory:

```bash
sudo make install
```

## Step 7: Verify Installation

Add the GCC binary directory to your `PATH`:

```bash
export PATH=/usr/local/gcc-i686/bin:$PATH
```

Verify the installation by checking the GCC version:

```bash
i686-gcc --version
```

You should see the installed GCC version.

## Step 8: Cleanup

Optionally, you can remove the source and build directories to free up space:

```bash
cd ../..
rm -rf gcc-<version>
```

## Notes

- Ensure you have write permissions for the installation directory.
- If you encounter errors during the build process, consult the GCC documentation or check for missing dependencies.

This completes the setup process for the i686 GCC compiler.