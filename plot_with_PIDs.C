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
    const std::string   filename_signal = "~/cern/ntuples/signal.root";
    const std::string filename_sideband = "~/cern/ntuples/sideband.root";
    const std::string       filename_MC = "~/cern/ntuples/reducedTreeMC.root";
    const std::string   filename_corr_p = "~/cern/Lb2chicpK_MC_2011_2012_signal_fixed_PID-corrected_new_proton.root";
    const std::string   filename_corr_k = "~/cern/Lb2chicpK_MC_2011_2012_signal_fixed_PID-corrected_new_kaon.root";
    const std::string   treename_signal = "signal";
    const std::string treename_sideband = "sideband";
    const std::string       treename_MC = "reducedTree";
    const std::string     treename_corr = "MyTuple";
    const std::string             yaxis = "Candidates";
  
    // Opening files and trees
    TFile* f_sg = TFile::Open( filename_signal.c_str() );
    if( !f_sg ) std::cout << "file " << filename_signal << " does not exist" << std::endl;

    TTree* t_sg = (TTree*)f_sg->Get( treename_signal.c_str() );
    if( !t_sg ) std::cout << "tree " << treename_signal << " does not exist" << std::endl;

    TFile* f_sb = TFile::Open( filename_sideband.c_str() );
    if( !f_sb ) std::cout << "file " << filename_sideband << " does not exist" << std::endl;

    TTree* t_sb = (TTree*)f_sb->Get( treename_sideband.c_str() );
    if( !t_sb ) std::cout << "tree " << treename_sideband << " does not exist" << std::endl;

    TFile* f_MC = TFile::Open( filename_MC.c_str() );
    if( !f_MC ) std::cout << "file " << filename_MC << " does not exist" << std::endl;

    TTree* t_MC = (TTree*)f_MC->Get( treename_MC.c_str() );
    if( !t_MC ) std::cout << "tree " << treename_MC << " does not exist" << std::endl;

    TFile* f_pc = TFile::Open( filename_corr_p.c_str() );
    if( !f_pc ) std::cout << "file " << filename_MC << " does not exist" << std::endl;
    
    TTree* t_pc = (TTree*)f_pc->Get( treename_corr.c_str() );
    if( !t_pc ) std::cout << "tree " << treename_MC << " does not exist" << std::endl;
    
    TFile* f_kc = TFile::Open( filename_corr_k.c_str() );
    if( !f_kc) std::cout << "file " << filename_MC << " does not exist" << std::endl;

    TTree* t_kc = (TTree*)f_kc->Get( treename_corr.c_str() );
    if( !t_kc ) std::cout << "tree " << treename_MC << " does not exist" << std::endl;
    
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
    TH1D* h_sg_p = new TH1D ("h_sg_p", "P_ProbNNp", 40, 0., 1.);
    TH1D* h_sb_p = new TH1D ("h_sb_p", "P_ProbNNp", 40, 0., 1.);
    TH1D* h_MC_p = new TH1D ("h_MC_p", "P_ProbNNp", 40, 0., 1.);    
    TH1D* h_pc = new TH1D ("h_pc", "P_ProbNNpcorr", 40, 0., 1.);

    t_sg->Draw("P_ProbNNp>>h_sg_p", "", "goff"); 	
    t_sb->Draw("P_ProbNNp>>h_sb_p", "", "goff");
    t_MC->Draw("P_ProbNNp>>h_MC_p", "", "goff");   
    t_pc->Draw("P_ProbNNpcorr>>h_pc", "", "goff"); 


    // Defining histograms, drawing, for kaon
    TH1D* h_sg_k = new TH1D ("h_sg_k", "K_ProbNNk", 40, 0., 1.);
    TH1D* h_sb_k = new TH1D ("h_sb_k", "K_ProbNNk", 40, 0., 1.);
    TH1D* h_MC_k = new TH1D ("h_MC_k", "K_ProbNNk", 40, 0., 1.);    
    TH1D* h_kc = new TH1D ("h_kc", "K_ProbNNkcorr", 40, 0., 1.);

    t_sg->Draw("K_ProbNNk>>h_sg_k", "", "goff"); 	
    t_sb->Draw("K_ProbNNk>>h_sb_k", "", "goff");
    t_MC->Draw("K_ProbNNk>>h_MC_k", "", "goff");
    t_kc->Draw("K_ProbNNkcorr>>h_kc", "", "goff");

/*    
    // Plotting the results of the signal selection
    TCanvas* c1 = new TCanvas("c1");
    c1->Divide(1,1);
    c1->cd(1);

    h1->Draw();
    h1->GetXaxis()->SetTitle("P_ProbNNp");
    h2->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();
    
    c1->SaveAs("~/cern/plots/signal_region_P_ProbNNp.png");

    // Plotting the results of the sideband selection
    TCanvas* c2 = new TCanvas("c2");
    c2->Divide(1,1);
    c2->cd(1);

    h2->Draw();
    h2->GetXaxis()->SetTitle("P_ProbNNp");
    h2->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();

    c2->SaveAs("~/cern/plots/sideband_region_P_ProbNNp.png");
*/



    // Scaling the sideband histo to the signal histo, and subtracting, for proton
    h_sb_p->Scale(0.5);
    h_sg_p->Add(h_sb_p, -1);

    // Scaling the Monte Carlo data
    int Ndata = h_sg_p->GetEntries();
    int NMC = h_MC_p->GetEntries();  
    int Npc = h_pc->GetEntries();
    h_MC_p->Scale(Ndata / float(NMC));
    h_pc->Scale (Ndata / float(Npc));

    // Scaling the sideband histo to the signal histo, and subtracting, for kaon
    h_sb_k->Scale(0.5);
    h_sg_k->Add(h_sb_k, -1);

    // Scaling the Monte Carlo data
    int Nkc = h_pc->GetEntries();    
    h_MC_k->Scale(Ndata / float(NMC));
    h_kc->Scale (Ndata / float(Nkc));


    // Plotting the results of the sideband subtraction alongside the scaled MC data, for proton
    h_sg_p->Sumw2();
    h_MC_p->SetMarkerColor(kRed);
    h_MC_p->SetLineColor(kRed);   
    h_pc->SetMarkerColor(kGreen);
    h_pc->SetLineColor(kGreen);       

    TCanvas* c_p = new TCanvas("c_p");
    c_p->Divide(1,1);
    c_p->cd(1);

    h_MC_p->Draw();
    h_pc->Draw("same");
    h_sg_p->Draw("same");
    h_MC_p->GetXaxis()->SetTitle("P_ProbNNp");	
    h_MC_p->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();

    c_p->SaveAs("~/cern/plots/P_ProbNNp_sideband_subtracted_PID-corrected.png");

    // Plotting the results of the sideband subtraction alongside the scaled MC data, for kaon
    h_sg_k->Sumw2();
    h_MC_k->SetMarkerColor(kRed);
    h_MC_k->SetLineColor(kRed);   
    h_kc->SetMarkerColor(kGreen);
    h_kc->SetLineColor(kGreen);       

    TCanvas* c_k = new TCanvas("c_k");
    c_k->Divide(1,1);
    c_k->cd(1);

    h_MC_k->Draw();
    h_kc->Draw("same");
    h_sg_k->Draw("same");
    h_MC_k->GetXaxis()->SetTitle("K_ProbNNk");	
    h_MC_k->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();

    c_k->SaveAs("~/cern/plots/K_ProbNNk_sideband_subtracted_PID-corrected.png");
    
    
    
std::cout << Ndata << " events after sideband subtraction" << std::endl;
std::cout << NMC << " Monte Carlo events" << std::endl;

}










