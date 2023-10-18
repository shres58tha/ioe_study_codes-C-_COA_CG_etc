#!/bin/bash
# compress all files individually using 
find "./"  -type f -exec 7za a {} {} \;

