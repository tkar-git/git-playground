/*
 * Examples for simple ROOT tasks
 * Authors: Simon Corrodi, Dorothea vom Bruch, Alessandro Calandri, Luigi Vigiani, Lukas Gerritzen, Tamasi Kar
 * Last Update: August 2023
 *
 * Open a ROOT session by typing 'root -l' in your terminal.
 * Read through the comments and instructions below and copy them into the terminal.
 * Whenever you see the words 'To Do' you have to complete the code on your own.
 */

{
  /* 
   * Declare histograms 
   * From  http://root.cern.ch/root/html/TH1F.html
   * TH1F(const char* name, const char* title, Int_t nbinsx, Double_t xlow, Double_t xup)
   * The ROOT histogram base class is called TH1. All avaiable hisograms are derived from this class. 
   * Here we use TH1F, a one dimensional histogram which stores float values.
   */

  TH1F *gaus = new TH1F("gaus","Gaussian",100,-50,50);  // Declare histogram called "gaus", with title "Gaussian", with 100 bins ranging from -50 to 50
  TH1F *expo = new TH1F("expo","Exponential",100,-50,50);
  TH1F *sum  = new TH1F("sum","Sum of Gaussian and Exponential",100,-50,50);
  TH1F *test = new TH1F("test","Test how it works",20,0,10);
 
  /*
   * Fill histogram manually and draw it on a canvas.
   */

  test->Fill(2);     // Fill one event with value 2 into the histogram 'test'.
  test->Fill(5.5);   // Fill another event with value 5.5.
  test->Fill(7);

  TCanvas *c = new TCanvas("c","My first canvas",800,600); // Create canvas called c, titled "My first canvas", with dimensions x = 800 pixel, y = 600 pixel
  test->Draw();


  /*
    To Do
   * To produce data with random number generator, define the random number generator using class TRandom3.
   * from https://root.cern.ch/doc/master/classTRandom.html
 
   Your code

   */
  
  
  /*
   * Exponential
   * TF1 is a class for 1-dim functions. 
   * We use the predefined function "exp" and assign parameter [0] to it. 
   * With the function GetRandom, the TF1 class provides the possiblity to 
   * shoot random numbers with a distribution according to the function's shape. 
   * The "expo" hisogram is filled with 1000 such random numbers.
   */

  
  TF1 *exponential1 = new TF1("exponential","exp([0]*x)",-50,50);   // Define an exponential function in the range from -50 to 50
  exponential1->SetParameter(0,-0.05);              // Set decay constant, the exponential is in the form exp(p0+p1*x)
 

/*
   * To Do
   * Fill expo and gaus histograms defined above with 1000 numbers generated with exponential1->GetRandom() and with TRandom3 respectively
   * 
   * Your code 
   *
   */
 
  
    
  
  // Sum of Gaussian and Exponential
  sum = (TH1F*)gaus->Clone("sum");         // Clone gaus histogram into sum histogram (just copy it)
  sum->Add(expo,1);                        // Add exponential to Gaussian with a scale of 1 
  

  
  /*
   * Draw histograms
   * Create a Canvas and draw the 3 histograms on it
   * Divide it into pads, switch to pads with cd command
   * from http://root.cern.ch/root/html/TCanvas.html
   * TCanvas(const char* name, const char* title, Int_t wtopx, Int_t wtopy, Int_t ww, Int_t wh)
   */

  

  TCanvas *c1 = new TCanvas("c1","Canvas for Gauss",100,100,1200,600);  // Create canvas called c1, titled "Canvas for Gauss", with dimensions x = 1200 pixel, y = 600 pixel, left top corner at x = 100 pixel, y = 100 pixel
  c1->Divide(3,1);    // Divide canvas into 3 pads horizontally

  c1->cd(1);          // Switch to first pad
  gaus->Draw();
  gaus->SetLineColor(kRed);
  gaus->GetXaxis()->SetTitle("Random numbers generated according to Gaussian distribution");
  gaus->GetYaxis()->SetTitle("Number of entries");


  /* To Do
   * Draw expo and sum on pads 2 and 3 in green (kGreen) and blue (kBlue), label the axes
   *
   * Your code
   */
 
  /*
   * Fitting
   * From http://root.cern.ch/root/html/TH1.html
   * Fit(TF1* f1, Option_t* option = "", Option_t* goption = "", Double_t xmin = 0, Double_t xmax = 0)
   */

  // Fit Gaussian
  c1->cd(1);      // Switch back to first pad on canvas
  gaus->Fit("gaus");   // Fit histogram 'gaus' with predefined function "gaus"
  
  // Fit Exponential
  c1->cd(2);

  /* To Do
   * Fit an exponential function to histogram called 'expo'
   * Use the pre-defined funciton "expo", similar to "gaus" in the previous example
   * Look at at the output
   *
   * Your code
   */
 
  // Fit combined histogram
  c1->cd(3);
  TF1* gaus_fit = new TF1("gaus_fit","[0]*exp(-0.5*((x-[1])/[2])^2)",-20,20);   // user-defined Gaussian in certain range
  gaus_fit->SetParameter(0,4);         // Initialize 1st, 2nd and 3rd parameters
  gaus_fit->SetParameter(1,0.009);
  gaus_fit->SetParameter(2,1);
  sum->Fit("gaus_fit","R");            // Fit histogram 'sum' with user-defined Gaussian in sub-range ("R")
  
  TF1* expo_fit = new TF1("expo_fit","exp([0]+[1]*x)",-50,-20);   // user-defined exponential in certain range

  /* To Do
   * In addition, fit expo_fit to the data in histogram 'sum'
   * the option "R+" draws the current fit in addition to previous fits
   * Set the parameter 0 to 0 and parameter 1 to -0.05.
   *
   * Your code
   */


  //gaus(0) is a substitute for [0]*exp(-0.5*((x-[1])/[2])**2) and (0) means start numbering parameters at 0. expo(3) is a substitute for exp([3]+[4]*x).
  TF1* total = new TF1("total","gaus(0) + expo(3)",-50,20);  // Define combined function
  Double_t par[5];
  gaus_fit->GetParameters(&par[0]);         // Get parameters from Gaussian fit
  expo_fit->GetParameters(&par[3]);         // Get parameters from exponential fit
  total->SetParameters(par);                // Initialize parameters of combined function with those from previous fits
  total->SetLineColor(kBlack);
  sum->Fit(total,"R+");                     // Fit histogram to combined function 

  /* 
   * Extract information from histograms
   */

  cout << "**************************************" << endl;
  cout << "Some information about the combined histogram .... : " << endl;
  cout << "Bin content of bin # 10: " << sum->GetBinContent(10) << endl;      // # of entries in bin # 10
  cout << "Integral of summed histogram = " << sum->Integral() << endl;       // Total integral of histogram
  cout << "Upper edge of bin # 50 = " << sum->GetXaxis()->GetBinUpEdge(50) << endl;   // Upper limit of bin # 50
  cout << "Integral of summed histogram below 0 = " << sum->Integral(0,50) << endl;   // Integral of x-axis range [-50,0], corresponding to bins [0,50]
  cout << "**************************************" << endl;


  /*
    To Do 
   * Save histograms / canvas. Define a TFile, save the TH1F objects gaus and expo inside as well as the sum. Save TCanvas c1 in the same root file and print the TCanvas on a PDF file.
   
   Your code 

   */
 

  /*
   * Some remarks on plotting styles:
   * The TStyle class, accessible by the (pre-defined) gStyle pointer, 
   * handels global style settings. 
   * For example: Logarithmic axes, labels, colors, borders, options for fitting,
                  pallette for 2D plots, so much more....
   *    Show fit results in the plot:
   *    From http://root.cern.ch/root/html/TStyle.html
   *    SetOptFit(Int_t fit = 1)
   *    The parameter mode can be = pcev  (default = 0111)
   *       p = 1;  print Probability
   *       c = 1;  print Chisquare/Number of degress of freedom
   *       e = 1;  print errors (if e=1, v must be 1)
   *       v = 1;  print name/values of parameters
   *       gStyle.SetOptFit(1111)
   */

  }
  




