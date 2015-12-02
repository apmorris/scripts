/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to plot mass, mass_chic and mass_jpsi from 
	trees reduced using reduceTree.C

*/


{

    // Run this at the command line by doing
    // root -l plot_reduced.C
    
    // Import formatting template
    gROOT->ProcessLine(".L ~/cern/scripts/lhcbStyle.C");


    // Definition of variables
    const std::string filename =    "~/cern/ntuples/reducedTree.root";
    const std::string filename_MC = "~/cern/ntuples/reducedTreeMC.root";
    const std::string treename =    "reducedTree";
    const std::string yaxis =       "Candidates";
  
    // Opening files and trees
    TFile* f1 = TFile::Open( filename.c_str() );
    if( !f1 ) std::cout << "file " << filename << " does not exist" << std::endl;

    TTree* t1 = (TTree*)f1.Get( treename.c_str() );
    if( !t1 ) std::cout << "tree " << treename << " does not exist" << std::endl;

    TFile* f2 = TFile::Open( filename_MC.c_str() );
    if( !f2 ) std::cout << "file " << filename_MC << " does not exist" << std::endl;

    TTree* t2 = (TTree*)f2.Get( treename.c_str() );
    if( !t1 ) std::cout << "tree " << treename << " does not exist" << std::endl;


    // Need to scale the Monte Carlo data to the same number of entries as the data
    // So define two integers and scale accordingly later
    int Ndata = t1->GetEntries();
    int NMC = t2->GetEntries();


    // Including the LHCb name, formatting
    lhcbName = new TPaveText(gStyle->GetPadLeftMargin() + 0.03,
            0.87 - gStyle->GetPadTopMargin(),
            gStyle->GetPadLeftMargin() + 0.13,
            0.95 - gStyle->GetPadTopMargin(),
            "BRNDC");
    lhcbName->AddText("LHCb");
    lhcbName->SetFillColor(0);
    lhcbName->SetTextAlign(12);
    lhcbName->SetBorderSize(0);

    gStyle->SetOptStat(0);	





    // plotting mass ------------------------------------------------------------------- 

    // Define the histograms
    TH1D* h1 = new TH1D ("h1", "mass", 100, 5.55, 5.7);
    TH1D* h1_MC = new TH1D ("h1_MC", "mass", 100, 5.55, 5.7);
    
    
    // Differentiating the MC histo from the data histo
    h1->Sumw2(); 	//with this get markers, without get a line
    h1_MC->SetMarkerColor(kRed);
    h1_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("mass>>h1", "", "goff"); 	
    t2->Draw("mass>>h1_MC", "", "goff");


    // Scaling MC to data
    h1_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c1 = new TCanvas();
    c1->Divide(1,1);
    c1->cd(1);


    // Plotting 
    h1_MC->Draw();
    h1->Draw("same"); 	// draws on same pad
    h1_MC->GetXaxis()->SetTitle("#Lambdab mass [GeV/#it{c^2}]");	
    h1_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c1->SaveAs("~/cern/plots/plot_reduced/mass.png");




    // plotting mass_chic -------------------------------------------------------------- 

    // Define the histograms
    TH1D* h2 = new TH1D ("h2", "mass_chic", 100, 3.4, 3.7);
    TH1D* h2_MC = new TH1D ("h2_MC", "mass_chic", 100, 3.4, 3.7);
    
    
    // Differentiating the MC histo from the data histo
    h2->Sumw2(); 	//with this get markers, without get a line
    h2_MC->SetMarkerColor(kRed);
    h2_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("mass_chic>>h2", "", "goff"); 	
    t2->Draw("mass_chic>>h2_MC", "", "goff");


    // Scaling MC to data
    h2_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c2 = new TCanvas();
    c2->Divide(1,1);
    c2->cd(1);


    // Plotting 
    h2_MC->Draw();
    h2->Draw("same"); 	// draws on same pad
    h2_MC->GetXaxis()->SetTitle("#chic1 mass [GeV/#it{c^2}]");	
    h2_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c2->SaveAs("~/cern/plots/plot_reduced/mass_chic.png");



    // plotting mass_jpsi -------------------------------------------------------------- 

    // Define the histograms
    TH1D* h3 = new TH1D ("h3", "mass_jpsi", 100, 2.95, 3.25);
    TH1D* h3_MC = new TH1D ("h3_MC", "mass_jpsi", 100, 2.95, 3.25);
    
    
    // Differentiating the MC histo from the data histo
    h3->Sumw2(); 	//with this get markers, without get a line
    h3_MC->SetMarkerColor(kRed);
    h3_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("mass_jpsi>>h3", "", "goff"); 	
    t2->Draw("mass_jpsi>>h3_MC", "", "goff");


    // Scaling MC to data
    h3_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c3 = new TCanvas();
    c3->Divide(1,1);
    c3->cd(1);


    // Plotting 
    h3_MC->Draw();
    h3->Draw("same"); 	// draws on same pad
    h3_MC->GetXaxis()->SetTitle("J/#psi mass [GeV/#it{c^2}]");	
    h3_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c3->SaveAs("~/cern/plots/plot_reduced/mass_jpsi.png");




std::cout << Ndata << " events total (after cuts)" << std::endl;
std::cout << NMC << " simulated events total (after cuts)" << std::endl;


}










