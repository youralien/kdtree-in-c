# kdtree-in-c
a kdtree in the C programming language

inspired by the format of [this assignment](http://web.stanford.edu/class/cs106l/handouts/assignment-3-kdtree.pdf) requiring the implementation of a kd-tree

# Requirements
Required `czmq`, a library that makes Scalable-C work.  The following instructions comes from Chapter 1 of the Scalable-C book ([link](https://hintjens.gitbooks.io/scalable-c/content/chapter1.html) please don't be broken in the future)

You can get it by cloning master

    cd $HOME/apps
    git clone https://github.com/zeromq/czmq

Then we build and install CZMQ. There are two ways.

More traditional way:

    ./autogen.sh && ./configure
    make -j 4 && make check
    make install && sudo ldconfig

More modern way:

    cmake .
    make -j 4 && make test
    make install && sudo ldconfig

Ah it might fail. You might need to install its dependencies, `libzmq` and `libsodium`

    cd $HOME/apps

    # Install libsodium
    git clone https://github.com/jedisct1/libsodium
    cd libsodium
    ./autogen.sh && ./configure
    make -j 4 && make check
    make install && sudo ldconfig
    cd ..

    # Install libzmq
    git clone https://github.com/zeromq/libzmq
    cd libzmq
    ./autogen.sh && ./configure
    make -j 4 && make check
    make install && sudo ldconfig
    cd ..

    # Build CZMQ again...
    cd czmq
    ./autogen.sh && ./configure
    make -j 4 && make check
    make install && sudo ldconfig
    cd ..

It might fail one more time because of permission errors.  We can use the brutally effective solution of making /usr/local writable

    cd /usr/local
    sudo chmod -R a+w *
    cd $HOME/apps/libsodium
    make install

#Testing
To compile the files and run the tests, run the bash script `build.sh`, i.e. `./build.sh`
