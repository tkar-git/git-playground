/*
 * Examples for simple ROOT tasks - definition of a TTree and data filling
 * Authors: Simon Corrodi, Dorothea vom Bruch, Alessandro Calandri, Luigi Vigiani, Lukas Gerritzen, Tamasi Kar
 * Last Update: August 2023
 *
 * Open a ROOT session by typing 'root -l' in your terminal.
 * Read through the comments and instructions below and copy them into the terminal.
 * Whenever you see the words 'To Do' you have to complete the code on your own.
 */

{
  

  /* 
     To Do
     Define a TTree t with name mytree and define four branches of this tree with the given variables (float): energy1, energy2, time1, time2
     Your code
*/


  
 
       
  TRandom3  *r3 = new TRandom3(0);   // Random number generator
 
  
  TF1 *exponential1 = new TF1("exponential","exp([0]*x)",-50,50);   // Define an exponential function in the range from -50 to 50
  TF1 *exponential2 = new TF1("exponential","exp([0]*x)",-50,50);   
  
  exponential1->SetParameter(0,-0.05);              // Set two different decay constants 
  exponential2->SetParameter(0,-0.02);             


/*
   * To Do
   * Fill tree 't' with 1000 numbers using random numbers for the following configurations:

   - gaussian distribution (mean=0, sigma=10)
   - gaussian distribution (mean=2, sigma=5)
   - exponential distribution following the functional form of 'exponential1'
   - exponential distribution following the functional form of 'exponential2'
   * 
   * Your code 
   *
   */
 
  

  TFile *f = new TFile("ExampleOutput_tree.root","RECREATE",""); 
  t->Write();
  f->Close();
}
