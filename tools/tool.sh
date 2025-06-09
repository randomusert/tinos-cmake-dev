#!/bin/sh

case "$1" in
  build)
    echo "Running build logic..."
    # Put your build-related commands here
    python3 build.py --build
    ;;
  clean)
    echo "Running clean logic..."
    python3 build.py --clean
    # Put your clean-related commands here
    ;;
  mkiso)
    echo "building iso"
    python3 build.py --build --iso
    ;;
  run)
    echo "running"
    python3 build.py --build --iso --run
    ;;
  *)
    echo "Usage: $0 {mkiso|build|clean|run}"
    exit 1
    ;;
  
esac
