/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to subtract the sideband background from   
	the signal region. Then plots the desired variables including the PID corrected.
	Sideband and signal are preselected using 
	sidebandSelection.C

*/

void plot_with_PIDs(){

    // Run this at the command line by doing
    // root -l sidebandSubtraction.C
    
    // Import formatting template
    gROOT->ProcessLine(".L ~/cern/scripts/lhcbStyle.C");


    // Definition of variables
    const std::string    filename_signal = "~/cern/ntuples/signal.root";
    const std::string  filename_sideband = "~/cern/ntuples/sideband.root";
    const std::string        filename_MC = "~/cern/ntuples/new_tuples/Lb2chicpK_MC_2011_2012_signal_cut.root";
    const std::string filename_MC_uncorr = "~/cern/ntuples/new_tuples/Lb2chicpK_MC_2011_2012_signal_uncorrected.root";
    const std::string           treename = "DecayTree";
    const std::string              yaxis = "Candidates";
  
    // Opening files and trees
    TFile* f_sg = TFile::Open( filename_signal.c_str() );
    if( !f_sg ) std::cout << "file " << filename_signal << " does not exist" << std::endl;

    TTree* t_sg = (TTree*)f_sg->Get( treename.c_str() );
    if( !t_sg ) std::cout << "tree " << treename << " does not exist" << std::endl;

    TFile* f_sb = TFile::Open( filename_sideband.c_str() );
    if( !f_sb ) std::cout << "file " << filename_sideband << " does not exist" << std::endl;

    TTree* t_sb = (TTree*)f_sb->Get( treename.c_str() );
    if( !t_sb ) std::cout << "tree " << treename << " does not exist" << std::endl;

    TFile* f_MC = TFile::Open( filename_MC.c_str() );
    if( !f_MC ) std::cout << "file " << filename_MC << " does not exist" << std::endl;

    TTree* t_MC = (TTree*)f_MC->Get( treename.c_str() );
    if( !t_MC ) std::cout << "tree " << treename << " does not exist" << std::endl;

    TFile* f_un = TFile::Open( filename_MC_uncorr.c_str() );
    if( !f_un ) std::cout << "file " << filename_MC_uncorr << " does not exist" << std::endl;
    
    TTree* t_un = (TTree*)f_un->Get( treename.c_str() );
    if( !t_un ) std::cout << "tree " << treename << " does not exist" << std::endl;
    
    
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

    // Defining histograms, drawing, for proton
    TH1D* h_sg_p = new TH1D ("h_sg_p", "proton_ProbNNp", 25, 0., 1.);
    TH1D* h_sb_p = new TH1D ("h_sb_p", "proton_ProbNNp", 25, 0., 1.);
    TH1D* h_MC_p = new TH1D ("h_MC_p", "proton_ProbNNpcorr", 25, 0., 1.);    
    TH1D* h_un_p = new TH1D ("h_un_p", "proton_ProbNNp", 25, 0., 1.);

    t_sg->Draw("proton_ProbNNp>>h_sg_p", "", "goff"); 	
    t_sb->Draw("proton_ProbNNp>>h_sb_p", "", "goff");
    t_MC->Draw("proton_ProbNNpcorr>>h_MC_p", "", "goff");   
    t_un->Draw("proton_ProbNNp>>h_un_p", "", "goff"); 


    // Defining histograms, drawing, for kaon
    TH1D* h_sg_k = new TH1D ("h_sg_k", "kaon_ProbNNk", 25, 0., 1.);
    TH1D* h_sb_k = new TH1D ("h_sb_k", "kaon_ProbNNk", 25, 0., 1.);
    TH1D* h_MC_k = new TH1D ("h_MC_k", "kaon_ProbNNkcorr", 25, 0., 1.);    
    TH1D* h_un_k = new TH1D ("h_un_k", "kaon_ProbNNk", 25, 0., 1.);

    t_sg->Draw("kaon_ProbNNk>>h_sg_k", "", "goff"); 	
    t_sb->Draw("kaon_ProbNNk>>h_sb_k", "", "goff");
    t_MC->Draw("kaon_ProbNNkcorr>>h_MC_k", "", "goff");
    t_un->Draw("kaon_ProbNNk>>h_un_k", "", "goff");

/*    
    // Plotting the results of the signal selection
    TCanvas* c1 = new TCanvas("c1");
    c1->Divide(1,1);
    c1->cd(1);

    h1->Draw();
    h1->GetXaxis()->SetTitle("proton_ProbNNp");
    h2->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();
    
    c1->SaveAs("~/cern/plots/signal_region_proton_ProbNNp.png");

    // Plotting the results of the sideband selection
    TCanvas* c2 = new TCanvas("c2");
    c2->Divide(1,1);
    c2->cd(1);

    h2->Draw();
    h2->GetXaxis()->SetTitle("proton_ProbNNp");
    h2->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();

    c2->SaveAs("~/cern/plots/sideband_region_proton_ProbNNp.png");
*/



    // Scaling the sideband histo to the signal histo, and subtracting, for proton
    h_sb_p->Scale(0.5);
    h_sg_p->Add(h_sb_p, -1);

    // Scaling the Monte Carlo data
    int Ndata = h_sg_p->GetEntries();
    int NMC = h_MC_p->GetEntries();  
    int Nuncorr = h_un_p->GetEntries();
    float ratio = 754.0/237701.0;
    h_MC_p->Scale(754.0/237701.0);
    h_un_p->Scale(754.0/237701.0);


    // Plotting the results of the sideband subtraction alongside the scaled MC data, for proton
    h_sg_p->Sumw2();
    h_sg_p->SetMarkerStyle(20);
    h_sg_p->SetMarkerColor(1);
    h_MC_p->SetMarkerColor(kRed);
    h_MC_p->SetLineColor(kRed);   
    h_un_p->SetMarkerColor(8);
    h_un_p->SetLineColor(8);       

    TCanvas* c_p = new TCanvas("c_p");
    c_p->Divide(1,1);
    c_p->cd(1);
    
    h_un_p->Draw();
    h_MC_p->Draw("same");
    h_sg_p->Draw("same");
    h_un_p->GetXaxis()->SetTitle("proton_ProbNNp");	
    h_un_p->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();

    c_p->SaveAs("~/cern/plots/sideband_subtractions/proton_ProbNNp_sideband_subtracted_PID-corrected.png");


    // Scaling the sideband histo to the signal histo, and subtracting, for kaon
    h_sb_k->Scale(0.5);
    h_sg_k->Add(h_sb_k, -1);

    // Scaling the Monte Carlo data   
    h_MC_k->Scale(754.0/237701.0);
    h_un_k->Scale(754.0/237701.0);
    //int new_NMC = h_un_p->GetEntries();




    // Plotting the results of the sideband subtraction alongside the scaled MC data, for kaon
    h_sg_k->Sumw2();
    h_sg_k->SetMarkerStyle(20);
    h_sg_k->SetMarkerColor(1);
    h_MC_k->SetMarkerColor(kRed);
    h_MC_k->SetLineColor(kRed);   
    h_un_k->SetMarkerColor(8);
    h_un_k->SetLineColor(8);       

    TCanvas* c_k = new TCanvas("c_k");
    c_k->Divide(1,1);
    c_k->cd(1);

    h_un_k->Draw();
    h_MC_k->Draw("same");
    h_sg_k->Draw("same");
    h_un_k->GetXaxis()->SetTitle("kaon_ProbNNk");	
    h_un_k->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();

    c_k->SaveAs("~/cern/plots/sideband_subtractions/kaon_ProbNNk_sideband_subtracted_PID-corrected.png");
  
    
    
std::cout << Ndata << " events after sideband subtraction" << std::endl;
std::cout << NMC << " Monte Carlo events" << std::endl;
//std::cout << new_NMC << std::endl;
}










