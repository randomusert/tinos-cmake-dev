import argparse
import os
import shutil
import subprocess
import sys

# Paths
BUILD_DIR = "build"
ISODIR = os.path.join(BUILD_DIR, "isodir")
GRUB_DIR = os.path.join(ISODIR, "boot", "grub")
KERNEL_OUTPUT = os.path.join(BUILD_DIR, "tinoscmake")
ISO_PATH = os.path.join(BUILD_DIR, "tinoscmake.iso")
GRUB_CFG_SOURCE = "grub.cfg"
TOOLCHAIN_FILE = "toolchain.cmake"

# Utilities
def run_cmd(cmd, cwd=None):
    try:
        print(f"> {' '.join(cmd)}")
        subprocess.run(cmd, check=True, cwd=cwd)
    except subprocess.CalledProcessError as e:
        print(f"[ERROR] Command failed: {' '.join(cmd)}")
        print(f"[ERROR] Return code: {e.returncode}")
        sys.exit(e.returncode)
    except FileNotFoundError as e:
        print(f"[ERROR] Command not found: {cmd[0]}")
        sys.exit(1)

def clean():
    if os.path.exists(BUILD_DIR):
        print("Cleaning build directory...")
        shutil.rmtree(BUILD_DIR)
    print("Clean complete.")

def prepare_dirs():
    try:
        os.makedirs(GRUB_DIR, exist_ok=True)
    except OSError as e:
        print(f"[ERROR] Failed to create directories: {e}")
        sys.exit(1)
    

def build_kernel():
    if not os.path.exists(TOOLCHAIN_FILE):
        print(f"[ERROR] Toolchain file '{TOOLCHAIN_FILE}' not found.")
        sys.exit(1)

    os.makedirs(BUILD_DIR, exist_ok=True)
    run_cmd(["cmake", "-DCMAKE_TOOLCHAIN_FILE=" + TOOLCHAIN_FILE, ".."], cwd=BUILD_DIR)
    run_cmd(["make"], cwd=BUILD_DIR)

def copy_files():
    try:
        print("Copying kernel and GRUB config...")
        if not os.path.isfile(KERNEL_OUTPUT):
            print(f"[ERROR] Kernel output '{KERNEL_OUTPUT}' not found. Build first.")
            sys.exit(1)
        if not os.path.isfile(GRUB_CFG_SOURCE):
            print(f"[ERROR] grub.cfg file not found.")
            sys.exit(1)
        shutil.copy(KERNEL_OUTPUT, os.path.join(ISODIR, "boot", "tinoscmake"))
        shutil.copy(GRUB_CFG_SOURCE, os.path.join(GRUB_DIR, "grub.cfg"))
    except Exception as e:
        print(f"[ERROR] Failed to copy files: {e}")
        sys.exit(1)

def make_iso():
    if not os.path.isdir(ISODIR):
        print("[ERROR] ISO directory not found. Build first.")
        sys.exit(1)
    run_cmd(["grub-mkrescue", "-o", ISO_PATH, ISODIR])

def run_qemu():
    if not os.path.isfile(ISO_PATH):
        print("[ERROR] ISO image not found. Run with --iso first.")
        sys.exit(1)
    run_cmd(["qemu-system-i386", "-cdrom", ISO_PATH])

def ninja():
    if not os.path.isfile(TOOLCHAIN_FILE):
        print("[ERROR] Toolchain file '{TOOLCHAIN_FILE}' not found")
        sys.exit(1)
    os.makedirs(BUILD_DIR, exist_ok=True)
    run_cmd(["cmake", "-DCMAKE_TOOLCHAIN_FILE=" + TOOLCHAIN_FILE, "-G", 'Ninja', ".."], cwd=BUILD_DIR)
    run_cmd(["ninja"], cwd=BUILD_DIR)

def main():
    parser = argparse.ArgumentParser(description="Tinos Cmake build script")
    parser.add_argument("--build", action="store_true", help="Build the kernel")
    parser.add_argument("--iso", action="store_true", help="Build the ISO")
    parser.add_argument("--run", action="store_true", help="Run in QEMU")
    parser.add_argument("--clean", action="store_true", help="Clean the build directory")
    parser.add_argument("--ninja", action="store_true", help="generate and build using ninja")
    args = parser.parse_args()

    try:
        if args.clean:
            clean()
        if args.build:
            prepare_dirs()
            build_kernel()
            copy_files()
        if args.iso:
            make_iso()
        if args.run:
            run_qemu()
        if args.ninja:
            prepare_dirs()
            ninja()
            copy_files()
            make_iso()
        if not (args.build or args.iso or args.run or args.clean):
            parser.print_help()
    except KeyboardInterrupt:
        print("\n[INFO] Interrupted by user.")
        sys.exit(0)

if __name__ == "__main__":
    main()
