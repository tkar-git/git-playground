# Parton Showering with Pythia8

The steps detailed below are used to produce a root file as an output given a lhe file as input.
<br />The scripts present in this directory are used to decay SM higgs to b's and hence shower them 
<br />This can be easily modified in the file shower.cmnd
<br />The root file contains a TTree named CollectionTree and contains kinematic varibles of the final state particles(HEPMC status = 1)
including the b's and higgs

## Essentials

This program needs the following:

* MadGraph5: Simulation of fixed-order matrix element.
* Pythia8: Simulation of parton shower based on perturbative QCD.
* FastJet: Jet definition and -reconstruction.
* Root: A modular scientific software toolkit.

#### Install Instructions on lxplus and naf

Setup ATLAS environment and some random Athena release to configure gcc, root, lhapdf and fast-jet
<br /> source the env_setup script in mc-generator
<br /> if you are installing pythia8 for the first time you might want to comment out the execution of export.sh 
<br /> export.sh will be generated in the requirements folder during your very first installation of pythia8 and must be executed every time you login to use pythia and also after installing pythia for the first time.
<br /> assuming that you are in forPythia directory
```
cd ../
source env_setup
```

Install pythia8 on lxplus using the same instruction as on the main page i.e.
```
cd ./requirements
./install-pythia8.2
source export.sh
```

Next copy some modified example files from forPythia to the examples directory of the installed pythia
```
cd ../pythia8243/examples/
cp ../../forPythia/shower.cmnd .
cp ../../forPythia/shower.cc .
cp ../../forPythia/MakeFile .
```

Modify the number of events and what the higgs must decay to in the shower.cmnd file
<br /> The default number of events is set to 100. You can modify it on the line with 'Main:numberOfEvents = 100'
<br /> The decay product of both the higgs have been set to b quarks and can be modified on line starting with
<br />25:onIfMatch = 5 -5
<br />If you want for example one of the higgs to decay into b's and the other to tau's, you raplace the above with the following
```
25:onIfAny=5 15
```

Compile shower.cc by executing the following command
```
make shower
```

You can now pythia by providing an lhe file as first argument and an output file name as second argument
<br />Make sure you have a copy of the cmnd file in the directory from where you execute the command
```
cd ../../
cp ./pythia8243/examples/shower.cmnd .
```

To run locally call 
```
./pythia8243/examples/shower ./<path_to_input_lhe_file>/unweighted_events.lhe <path_to_store_output>/output.root
```
This will produce an output root file output.root with a TTree named CollectionTree and some kinematic variables
<br /> you can modify the TTree in the file shower.cc

To run on grid do
```
cp ./forPythia/prun_submit_pythia.sh .
cp ./forPythia/run_it_pythia.sh
```

Modify the CERN_USER, input dataset name following the word 'inDS', and output dataset name following the word 'outDS'  in prun_submit_pythia.sh
```
./prun_submit_pythia.sh
```
Note: the above requires a valid grid certificate. If you don't have one follow the intructions here:
https://ca.cern.ch/ca/user/Request.aspx?template=EE2User

