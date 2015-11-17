/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to subtract the sideband background from   
	the signal region. Then plots the desired variables.
	Sideband and signal are preselected using 
	sidebandSelection.C

*/

void sidebandSubtraction(){

    // Run this at the command line by doing
    // root -l sidebandSubtraction.C
    
    // Import formatting template
    gROOT->ProcessLine(".L ~/cern/scripts/lhcbStyle.C");


    // Definition of variables
    const std::string filename_signal=    "~/cern/ntuples/signal.root";
    const std::string filename_sideband = "~/cern/ntuples/sideband.root";
    const std::string filename_MC = 	  "~/cern/ntuples/reducedTreeMC.root";
    const std::string treename_signal =   "signal";
    const std::string treename_sideband = "sideband";
    const std::string treename_MC = 	  "reducedTree";
    const std::string yaxis =      	  "Candidates";
  
    // Opening files and trees
    TFile* f1 = TFile::Open( filename_signal.c_str() );
    if( !f1 ) std::cout << "file " << filename_signal << " does not exist" << std::endl;

    TTree* t1 = (TTree*)f1->Get( treename_signal.c_str() );
    if( !t1 ) std::cout << "tree " << treename_signal << " does not exist" << std::endl;

    TFile* f2 = TFile::Open( filename_sideband.c_str() );
    if( !f2 ) std::cout << "file " << filename_sideband << " does not exist" << std::endl;

    TTree* t2 = (TTree*)f2->Get( treename_sideband.c_str() );
    if( !t2 ) std::cout << "tree " << treename_sideband << " does not exist" << std::endl;

    TFile* f3 = TFile::Open( filename_MC.c_str() );
    if( !f3 ) std::cout << "file " << filename_MC << " does not exist" << std::endl;

    TTree* t3 = (TTree*)f3->Get( treename_MC.c_str() );
    if( !t3 ) std::cout << "tree " << treename_MC << " does not exist" << std::endl;


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

    // Defining histograms, drawing and scaling
    TH1D* h1 = new TH1D ("h1", "ProbNNp", 40, 0., 1.);
    TH1D* h2 = new TH1D ("h2", "ProbNNp", 40, 0., 1.);
    TH1D* h3 = new TH1D ("h3", "ProbNNp", 40, 0., 1.);    

    t1->Draw("ProbNNp>>h1", "", "goff"); 	
    t2->Draw("ProbNNp>>h2", "", "goff");
    t3->Draw("ProbNNp>>h3", "", "goff");   

    
    // Plotting the results of the signal selection
    TCanvas* c1 = new TCanvas("c1");
    c1->Divide(1,1);
    c1->cd(1);

    h1->Draw();
    h1->GetXaxis()->SetTitle("ProbNNp");
    h2->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();
    
    c1->SaveAs("~/cern/plots/signal_region_ProbNNp.png");

    // Plotting the results of the sideband selection
    TCanvas* c2 = new TCanvas("c2");
    c2->Divide(1,1);
    c2->cd(1);

    h2->Draw();
    h2->GetXaxis()->SetTitle("ProbNNp");
    h2->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();

    c2->SaveAs("~/cern/plots/sideband_region_ProbNNp.png");

    // Scaling the sideband histo to the signal histo, and subtracting
    h2->Scale(0.5);
    h1->Add(h2, -1);

    // Scaling the Monte Carlo data
    int Ndata = h1->GetEntries();
    int Ndata2 = h1->Integral();
    int NMC = h3->GetEntries();  
    int NMC2 = h3->Integral();
    h3->Scale(Ndata / float(NMC));

    // Plotting the results of the sideband subtraction alongside the scaled MC data
    h1->Sumw2();
    h3->SetMarkerColor(kRed);
    h3->SetLineColor(kRed);   

    TCanvas* c3 = new TCanvas("c3");
    c3->Divide(1,1);
    c3->cd(1);

    h3->Draw();
    h1->Draw("same");
    h3->GetXaxis()->SetTitle("ProbNNp");	
    h3->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();

    c3->SaveAs("~/cern/plots/sideband_subtracted_ProbNNp.png");


std::cout << Ndata << " events after sideband subtraction" << std::endl;
std::cout << Ndata2 << std::endl;
std::cout << NMC << std::endl;
std::cout << NMC2 << std::endl;

}










