This is an implementation of a software framework for the ILD experiment which is based on FairRoot. To use this software you need:

1. In case you use SLC6 where the GitHub cert is missing, first do (only once):

    ```bash
    mkdir ~/certs
    curl http://curl.haxx.se/ca/cacert.pem -o ~/certs/cacert.pem
    git config --global http.sslcainfo ~/certs/cacert.pem
    ```

2. Set the basic environment variables. Put these in your shell's rc file (~/.bashrc or ~/.cshrc).


   For bash:

    ```bash
    export SIMPATH=~/FairSoft/FairSoftInst
    export FAIRROOTPATH=~/FairRoot/FairRootInst
    ```

    or for the csh:

    ```bash
    setenv SIMPATH ~/FairSoft/FairSoftInst
    setenv FAIRROOTPATH ~/FairRoot/FairRootInst
    ```


2. Install [FairSoft](https://github.com/FairRootGroup/FairSoft/tree/dev)


    ```bash
    git clone -b dev https://github.com/FairRootGroup/FairSoft.git
    cd FairSoft
    # On SLC6 do: export FC=gfortran 
    ./configure.sh
    # 1) custom installation ...
    # 1) gcc (on Linux) 5) Clang (on OSX)
    # 3) Optimization
    # 1) Yes (install Simulation) 
    # 2) Internet (install G4 files from internet)
    # 2) No (do not install python bindings)
    # path: $SIMPATH
    ```

3. Install [FairRoot](http://fairroot.gsi.de/?q=node/82)

    ```bash
    cd ~
    git clone -b dev https://github.com/FairRootGroup/FairRoot.git
    cd FairRoot
    mkdir build
    cd build
    cmake -DCMAKE_INSTALL_PREFIX=$FAIRROOTPATH ..
    make
    make install
    ```


4. Install the [FccSoft](https://github.com/kresan/FccSoft.git) software:

    ```bash
    cd ~
    git clone https://github.com/kresan/FccSoft.git
    mkdir build
    cd build
    cmake ../FccSoft
    make
    . config.sh    [or source config.csh]
    (there is an issue with check_system.csh, does return wrong answer, should be removed from config.csh, otherwise setup stops
    ```

5. Now you can for example simulate some events and run the event display:

    ```bash
    cd ~/FccSoft/macro
    root -l
      .L run_sim.C
      run_sim(2)
      .q
    root -l eventDisplay.C
    // Click on "FairEventManager" (in the top-left pane)
    // Click on the "Info" tab (on top of the bottom-left pane)
    // Increase the "Current Event" to >0 to see the events
    Use .q to exit
