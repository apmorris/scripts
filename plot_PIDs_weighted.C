/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to subtract the sideband background from   
	the signal region. Then plots the desired variables including the PID corrected.
	Sideband and signal are preselected using 
	sidebandSelection.C

*/

void plot_PIDs_weighted(){

    // Run this at the command line by doing
    // root -l sidebandSubtraction.C
    
    // Import formatting template
    gROOT->ProcessLine(".L ~/cern/scripts/lhcbStyle.C");


    // Definition of variables

    const std::string    filename_corr = "~/cern/ntuples/new_tuples/reduced_Lb2chicpK_MC_2011_2012_signal.root";
    const std::string filename_weights = "~/cern/ntuples/new_tuples/weighted_data.root";
    const std::string         treename = "DecayTree";
    const std::string treename_weights = "ds";
    const std::string            yaxis = "Candidates";
  
    // Opening files and trees


    TFile* f_co = TFile::Open( filename_corr.c_str() );
    if( !f_co ) std::cout << "file " << filename_corr << " does not exist" << std::endl;
    
    TTree* t_co = (TTree*)f_co->Get( treename.c_str() );
    if( !t_co ) std::cout << "tree " << treename << " does not exist" << std::endl;
    
    TFile* f_sw = TFile::Open( filename_weights.c_str() );
    if( !f_sw ) std::cout << "file " << filename_weights << " does not exist" << std::endl;
    
    TTree* t_sw = (TTree*)f_sw->Get( treename_weights.c_str() );
    if( !t_sw ) std::cout << "tree " << treename_weights << " does not exist" << std::endl;
    

    
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

    TH1D* h1_p = new TH1D ("h1_p", "proton_ProbNNp", 25, 0., 1.);
    TH1D* h2_p = new TH1D ("h2_p", "proton_ProbNNp", 25, 0., 1.);    
    
 	
    t_co->Draw("proton_ProbNNp>>h1_p", "", "goff");
    t_sw->Draw("proton_ProbNNp>>h2_p", "sigYield_sw", "goff");   
    


    // Defining histograms, drawing, for kaon
    TH1D* h1_k = new TH1D ("h1_k", "kaon_ProbNNk", 25, 0., 1.);
    TH1D* h2_k = new TH1D ("h2_k", "kaon_ProbNNk", 25, 0., 1.);    
   

    t_co->Draw("kaon_ProbNNk>>h1_k", "", "goff"); 	
    t_sw->Draw("kaon_ProbNNk>>h2_k", "sigYield_sw", "goff");
 

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
    //h_sb_p->Scale(0.5);
    //h_sg_p->Add(h_sb_p, -1);

    // Scaling the Monte Carlo data
    int NMC = t_co->GetEntries();
    int Ndata = t_sw->GetEntries();  


    h1_p->Scale( 784. / double(NMC));
   


    // Plotting the results of the sideband subtraction alongside the scaled MC data, for proton
    h2_p->Sumw2();
    h2_p->SetMarkerStyle(20);
    h2_p->SetMarkerColor(1);
    h1_p->SetMarkerColor(kRed);
    h1_p->SetLineColor(kRed);      

    TCanvas* c_p = new TCanvas("c_p");
    c_p->Divide(1,1);
    c_p->cd(1);
    
    h1_p->Draw();
    h2_p->Draw("same");
    h1_p->GetXaxis()->SetTitle("proton_ProbNNp");	
    h1_p->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();

    c_p->SaveAs("~/cern/plots/sideband_subtractions/proton_ProbNNp_sweights_PID-corrected.png");


    // Scaling the sideband histo to the signal histo, and subtracting, for kaon
    //h_sb_k->Scale(0.5);
    //h_sg_k->Add(h_sb_k, -1);

    // Scaling the Monte Carlo data   
    int NMCk = t_co->GetEntries();
    int Ndatak = t_sw->GetEntries();
    
    h1_k->Scale( 784. / double(NMCk));
    //h3_k->Scale(float(Ndata)/float(NMC_sw));
    //int new_NMC = h_un_p->GetEntries();




    // Plotting the results of the sideband subtraction alongside the scaled MC data, for kaon
    h2_k->Sumw2();
    h2_k->SetMarkerStyle(20);
    h2_k->SetMarkerColor(1);
    h1_k->SetMarkerColor(kRed);
    h1_k->SetLineColor(kRed);   
    
    TCanvas* c_k = new TCanvas("c_k");
    c_k->Divide(1,1);
    c_k->cd(1);

    h1_k->Draw();
    h2_k->Draw("same");
    h1_k->GetXaxis()->SetTitle("kaon_ProbNNk");	
    h1_k->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();

    c_k->SaveAs("~/cern/plots/sideband_subtractions/kaon_ProbNNk_sweights_PID-corrected.png");
  
    
    
std::cout << Ndata << " data events" << std::endl;
std::cout << NMC << " Monte Carlo events" << std::endl;
//std::cout << new_NMC << std::endl;
}










