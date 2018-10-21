# Project Dynamite
Project Dynamite is a 2d framework based on OpenGL, It supports multiple features such as a Targa Loader, <br/>
Component System, Resource Manager and much more.

Project Dynamite uses a Scene Loading system that can load .dynamite files from anywhere on the system, <br/>
you can also use Core::Instance()->GetResourcePath("FILENAME"), to load a .dynamite file (Or any other file) <br/>
from the resources directory.

Project Dynamite also contains a simple build-in Physics Library, note that this is just a library and <br/>
it is up to the developer if he/she wishes to use the functionality

As of 10/15/2018 it only compiles for windows systems (should be changed in the future).

# How to compile for VS2015
  Step 1: Download and Install CMAKE <br/>
  Step 2: Clone the repository <br/>
  Step 3: Run this command from the root directory: <br/>
          ```cmake . -DCMAKE_GENERATOR_PLATFORM=x64```

# License

Copyright (C) 2018  Jens Heukers

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
