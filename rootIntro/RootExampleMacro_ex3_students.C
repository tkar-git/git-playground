/*
 * Examples to show how to load trees
 * Authors: Simon Corrodi, Dorothea vom Bruch, Alessandro Calandri, Luigi Vigiani, Lukas Gerritzen, Tamasi Kar
 * Last update: August 2023


 */

{
  /*
   * Load data from file
   * TFile(const char* fname, Option_t* option = "", const char* ftitle = "", Int_t compress = 1)
   */

  TFile *file = new TFile("ExampleOutput_tree.root","READ");

  /* To Do
   *
   * The easiest way to get a first look at a root file is the TBrowser (http://root.cern.ch/root/html/TBrowser.html)
   * Typing 'new TBrowser' into the Root terminal opens it.
   * Explore the file ExampleOutput.root: It contains a histogram and a TTree ('mytree') with four branches:
   * energy1, energy2, time1, time2).
   * Explore the editor: View->Editor and the Statusbar: View->Event Statusbar
   * Many options are available by clicking / right clicking onto various parts of the canvas within the TBrowser.
   */

  /*
    To Do
    Load the tree, show the # of entries and its branches
    Get the tree produced in exercise2, print the total number of entries (GetEntries()) and the name of each branch in the tree (GetName()) 
   */
 
 
  TCanvas *c1 = new TCanvas("c1","My energies",1200,1000);
  c1->Divide(2,2);

  c1->cd(1);
  tree->Draw("energy1");

  
  c1->cd(2);

  /* To Do
   * Create histogram he2 with 601 bins from 0 to 600 directly from the Draw() command
   * Your code
   */

  
  /* By default, histograms created by tree->Draw() are called htemp.
   * By adding ">>hname" to the drawing command, the histogram is called
   * hname and stored in gDirectory.
   *
   * Load histograms form gDirectory
   */

  TH1F *he2 = (TH1F*)gDirectory->Get("he2");
  TH1F *he1 = (TH1F*)gROOT->FindObject("htemp")->Clone("he1");


  c1->cd(3);

  /*
   * Scatter Plots
   *
   * Draw correlations (name the TH2F) between the two energy channels (energy1 and energy2)
   * Draw("x:y") plots x versus y
   * Third option is the drawing option.
   * Your code
   */

  he->GetXaxis()->SetTitle("energy1");
  he->GetYaxis()->SetTitle("energy2");



  /*
   * Create an alias
   */

  c1->cd(4);
  tree->SetAlias("deltaT","time1");    // time1 is given in 51 ps bins
  
  
  /*
   * To Do
   * Add Cuts to the Draw() option: add the condition energy1>0 && energy2>0. 
   * Your code
   */


  
 
  
  c1->Draw("");
 

  /*
   * Alternative way to Fill Histograms
   *
   * by looping through all events
   */


  TCanvas *c2 = new TCanvas("c2","",800,600);
  TH1F *enew = new TH1F("enew","enew",50,-40,40);
  float energy1;

 
  tree->SetBranchAddress("energy1",&energy1);  //accessing the position of the branch through function SetBranchAddress

  for (int i = 0; i < tree->GetEntries(); i ++) 
    {
      tree->GetEntry(i); //accessing the value of the energy to be filled in the histogram below 
      enew->Fill(energy1);
    }
  
 
  enew->Draw();
  
}
