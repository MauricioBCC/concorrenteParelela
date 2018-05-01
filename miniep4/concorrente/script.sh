#!/bin/bash

max=10
for ((i = 1; i <= $max; ++i))
{
   ./main 10 3000000 >> defaultSync;
}

