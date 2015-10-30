/*	Alice Morris
	MPhys Project 2015/16

Script to plot the following variables:
1 pt_b
2 m_b_DTF_jpsi_chic1_constr 
3 dtf_b 
4 c2ip_b 
5 dls_b
6 c2ip_kminus 
7 c2ip_pplus 
8 minCl_gamma 
9 m_chic 
10 trig_b_l0tos_tos 
11 trig_b_l1tos_tos 
12 trig_b_l2tos_tos 
13 trgh_track[0] 
14 trgh_track[1] 
15 trgh_track[2] 
16 trgh_track[3] 
17 ann_kaon[0] 
18 minann_mu
19 m_jpsi

*/



{

    // Run this at the command line by doing
    // root -l plot_distributions.C
    
    // Import formatting template
    gROOT->ProcessLine(".L ~/cern/scripts/lhcbStyle.C");


    // Definition of variables
    const std::string filename =    "~/cern/ntuples/Lb2chicpK_2011_2012_signal.root";
    const std::string filename_MC = "~/cern/ntuples/Lb2chicpK_MC_2011_2012_signal.root";
    const std::string treename =    "HistosAndTuples/MyTuple";
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




    // pt_b plot section ----------------------------------------------------------------------------------------------------1

    // Define the histograms
    TH1D* h1 = new TH1D ("h1", "pt_b", 100, 0., 40.0);
    TH1D* h1_MC = new TH1D ("h1_MC", "pt_b", 100, 0., 40.0);
    
    
    // Differentiating the MC histo from the data histo
    h1->Sumw2(); 	//with this get markers, without get a line
    h1_MC->SetMarkerColor(kRed);
    h1_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("pt_b>>h1", "", "goff"); 	
    t2->Draw("pt_b>>h1_MC", "", "goff");


    // Scaling MC to data
    h1_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c1 = new TCanvas();
    c1->Divide(1,1);
    c1->cd(1);


    // Plotting 
    h1->Draw();
    h1_MC->Draw("same"); 	// draws on same pad
    h1->GetXaxis()->SetTitle("Lb pT [GeV/#it{c}]");	
    h1->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c1->SaveAs("~/cern/plots/pt_b.png");





    // m_b_DTF_jpsi_chic1_constr plot section ----------------------------------------------------------------------------------------------------2

    // Define the histograms
    TH1D* h2 = new TH1D ("h2", "m_b_DTF_jpsi_chic1_constr", 100, 4.5,  7.0);
    TH1D* h2_MC = new TH1D ("h2_MC", "m_b_DTF_jpsi_chic1_constr", 100, 4.5, 7.0);
    
    
    // Differentiating the MC histo from the data histo
    h2->Sumw2(); 	//with this get markers, without get a line
    h2_MC->SetMarkerColor(kRed);
    h2_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("m_b_DTF_jpsi_chic1_constr>>h2", "", "goff"); 	
    t2->Draw("m_b_DTF_jpsi_chic1_constr>>h2_MC", "", "goff");


    // Scaling MC to data
    h2_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c2 = new TCanvas();
    c2->Divide(1,1);
    c2->cd(1);


    // Plotting 
    h2_MC->Draw();
    h2->Draw("same"); 	// draws on same pad
    h2_MC->GetXaxis()->SetTitle( "Lb m constr [GeV/#it{c{^2}}]" );	
    h2_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c2->SaveAs("~/cern/plots/m_b_DTF_jpsi_chic1_constr.png");





    // dtf_b plot section ----------------------------------------------------------------------------------------------------3

    // Define the histograms
    TH1D* h3 = new TH1D ("h3", "dtf_b", 100, 0., 12.0);
    TH1D* h3_MC = new TH1D ("h3_MC", "dtf_b", 100, 0., 12.0);
    
    
    // Differentiating the MC histo from the data histo
    h3->Sumw2(); 	//with this get markers, without get a line
    h3_MC->SetMarkerColor(kRed);
    h3_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("dtf_b>>h3", "", "goff"); 
    t2->Draw("dtf_b>>h3_MC", "", "goff");


    // Scaling MC to data
    h3_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c3 = new TCanvas();
    c3->Divide(1,1);
    c3->cd(1);


    // Plotting 
    h3_MC->Draw();
    h3->Draw("same"); 	// draws on same pad
    h3_MC->GetXaxis()->SetTitle( "Lb dtf" );	
    h3_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c3->SaveAs("~/cern/plots/dtf_b.png");





    // c2ip_b plot section ----------------------------------------------------------------------------------------------------4

    // Define the histograms
    TH1D* h4 = new TH1D ("h4", "c2ip_b", 100, 0., 30.0);
    TH1D* h4_MC = new TH1D ("h4_MC", "c2ip_b", 100, 0., 30.0);
    
    
    // Differentiating the MC histo from the data histo
    h4->Sumw2(); 	//with this get markers, without get a line
    h4_MC->SetMarkerColor(kRed);
    h4_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("c2ip_b>>h4", "", "goff"); 	
    t2->Draw("c2ip_b>>h4_MC", "", "goff");


    // Scaling MC to data
    h4_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c4 = new TCanvas();
    c4->Divide(1,1);
    c4->cd(1);


    // Plotting 
    h4_MC->Draw();
    h4->Draw("same"); 	// draws on same pad
    h4_MC->GetXaxis()->SetTitle( "Lb c2ip" );	
    h4_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c4->SaveAs("~/cern/plots/c2ip_b.png");




    // dls_b plot section ----------------------------------------------------------------------------------------------------5

    // Define the histograms
    TH1D* h5 = new TH1D ("h5", "dls_b", 100, 0., 80.0);
    TH1D* h5_MC = new TH1D ("h5_MC", "dls_b", 100, 0., 80.0);
    
    
    // Differentiating the MC histo from the data histo
    h5->Sumw2(); 	//with this get markers, without get a line
    h5_MC->SetMarkerColor(kRed);
    h5_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("dls_b>>h5", "", "goff"); 
    t2->Draw("dls_b>>h5_MC", "", "goff");


    // Scaling MC to data
    h5_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c5 = new TCanvas();
    c5->Divide(1,1);
    c5->cd(1);


    // Plotting 
    h5->Draw();
    h5_MC->Draw("same"); 	// draws on same pad
    h5->GetXaxis()->SetTitle( "Lb dls" );	
    h5->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();	


    c5->SaveAs("~/cern/plots/dls_b.png");




    // c2ip_kminus plot section ----------------------------------------------------------------------------------------------------6

    // Define the histograms
    TH1D* h6 = new TH1D ("h6", "c2ip_kminus", 100, 0., 50.0);
    TH1D* h6_MC = new TH1D ("h6_MC", "c2ip_kminus", 100, 0., 50.0);
    
    
    // Differentiating the MC histo from the data histo
    h6->Sumw2(); 	//with this get markers, without get a line
    h6_MC->SetMarkerColor(kRed);
    h6_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("c2ip_kminus>>h6", "", "goff"); 	
    t2->Draw("c2ip_kminus>>h6_MC", "", "goff");


    // Scaling MC to data
    h6_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c6 = new TCanvas();
    c6->Divide(1,1);
    c6->cd(1);


    // Plotting 
    h6->Draw();
    h6_MC->Draw("same"); 	// draws on same pad
    h6->GetXaxis()->SetTitle( "K c2ip" );	
    h6->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c6->SaveAs("~/cern/plots/c2ip_kminus.png");



    // c2ip_pplus plot section ----------------------------------------------------------------------------------------------------7

    // Define the histograms
    TH1D* h7 = new TH1D ("h7", "c2ip_pplus", 100, 0., 50.0);
    TH1D* h7_MC = new TH1D ("h7_MC", "c2ip_pplus", 100, 0., 50.0);
    
    
    // Differentiating the MC histo from the data histo
    h7->Sumw2(); 	//with this get markers, without get a line
    h7_MC->SetMarkerColor(kRed);
    h7_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("c2ip_pplus>>h7", "", "goff"); 	
    t2->Draw("c2ip_pplus>>h7_MC", "", "goff");


    // Scaling MC to data
    h7_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c7 = new TCanvas();
    c7->Divide(1,1);
    c7->cd(1);


    // Plotting 
    h7->Draw();
    h7_MC->Draw("same"); 	// draws on same pad
    h7->GetXaxis()->SetTitle( "p c2ip" );	
    h7->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c7->SaveAs("~/cern/plots/c2ip_pplus.png");


    // minCl_gamma plot section ----------------------------------------------------------------------------------------------------8

    // Define the histograms
    TH1D* h8 = new TH1D ("h8", "minCl_gamma", 100, 0., 1.0);
    TH1D* h8_MC = new TH1D ("h8_MC", "minCl_gamma", 100, 0., 1.0);
    
    
    // Differentiating the MC histo from the data histo
    h8->Sumw2(); 	//with this get markers, without get a line
    h8_MC->SetMarkerColor(kRed);
    h8_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("minCl_gamma>>h8", "", "goff"); 	
    t2->Draw("minCl_gamma>>h8_MC", "", "goff");


    // Scaling MC to data
    h8_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c8 = new TCanvas();
    c8->Divide(1,1);
    c8->cd(1);


    // Plotting 
    h8_MC->Draw();
    h8->Draw("same"); 	// draws on same pad
    h8_MC->GetXaxis()->SetTitle( "minCl_gamma" );	
    h8_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c8->SaveAs("~/cern/plots/minCl_gamma.png");


    // m_chic plot section ----------------------------------------------------------------------------------------------------9

    // Define the histograms
    TH1D* h9 = new TH1D ("h9", "m_chic", 100, 3., 4.0);
    TH1D* h9_MC = new TH1D ("h9_MC", "m_chic", 100, 3., 4.0);
    
    
    // Differentiating the MC histo from the data histo
    h9->Sumw2(); 	//with this get markers, without get a line
    h9_MC->SetMarkerColor(kRed);
    h9_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("m_chic>>h9", "", "goff"); 	
    t2->Draw("m_chic>>h9_MC", "", "goff");


    // Scaling MC to data
    h9_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c9 = new TCanvas();
    c9->Divide(1,1);
    c9->cd(1);


    // Plotting 
    h9_MC->Draw();
    h9->Draw("same"); 	// draws on same pad
    h9_MC->GetXaxis()->SetTitle( "m_Chic" );	
    h9_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c9->SaveAs("~/cern/plots/m_chic.png");

    // trig_b_l0tos_tos plot section ---------------------------------------------------------------------------------------------------10

    // Define the histograms
    TH1D* h10 = new TH1D ("h10", "trig_b_l0tos_tos", 100, 0., 1.0);
    TH1D* h10_MC = new TH1D ("h10_MC", "trig_b_l0tos_tos", 100, 0., 1.0);
    
    
    // Differentiating the MC histo from the data histo
    h10->Sumw2(); 	//with this get markers, without get a line
    h10_MC->SetMarkerColor(kRed);
    h10_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("trig_b_l0tos_tos>>h10", "", "goff"); 	
    t2->Draw("trig_b_l0tos_tos>>h10_MC", "", "goff");


    // Scaling MC to data
    h10_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c10 = new TCanvas();
    c10->Divide(1,1);
    c10->cd(1);


    // Plotting 
    h10->Draw();
    h10_MC->Draw("same"); 	// draws on same pad
    h10->GetXaxis()->SetTitle( "trig_b_l0tos_tos" );	
    h10->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c10->SaveAs("~/cern/plots/trig_b_l0tos_tos.png");



    // trig_b_l1tos_tos plot section ---------------------------------------------------------------------------------------------------11

    // Define the histograms
    TH1D* h11 = new TH1D ("h11", "trig_b_l1tos_tos", 100, 0., 1.0);
    TH1D* h11_MC = new TH1D ("h11_MC", "trig_b_l1tos_tos", 100, 0., 1.0);
    
    
    // Differentiating the MC histo from the data histo
    h11->Sumw2(); 	//with this get markers, without get a line
    h11_MC->SetMarkerColor(kRed);
    h11_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("trig_b_l1tos_tos>>h11", "", "goff"); 	
    t2->Draw("trig_b_l1tos_tos>>h11_MC", "", "goff");


    // Scaling MC to data
    h11_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c11 = new TCanvas();
    c11->Divide(1,1);
    c11->cd(1);


    // Plotting 
    h11_MC->Draw();
    h11->Draw("same"); 	// draws on same pad
    h11_MC->GetXaxis()->SetTitle( "trig_b_l1tos_tos" );	
    h11_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c11->SaveAs("~/cern/plots/trig_b_l1tos_tos.png");



    // trig_b_l2tos_tos plot section ---------------------------------------------------------------------------------------------------12

    // Define the histograms
    TH1D* h12 = new TH1D ("h12", "trig_b_l2tos_tos", 100, 0., 1.0);
    TH1D* h12_MC = new TH1D ("h12_MC", "trig_b_l2tos_tos", 100, 0., 1.0);
    
    
    // Differentiating the MC histo from the data histo
    h12->Sumw2(); 	//with this get markers, without get a line
    h12_MC->SetMarkerColor(kRed);
    h12_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("trig_b_l2tos_tos>>h12", "", "goff"); 	
    t2->Draw("trig_b_l2tos_tos>>h12_MC", "", "goff");


    // Scaling MC to data
    h12_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c12 = new TCanvas();
    c12->Divide(1,1);
    c12->cd(1);


    // Plotting 
    h12_MC->Draw();
    h12->Draw("same"); 	// draws on same pad
    h12_MC->GetXaxis()->SetTitle( "trig_b_l2tos_tos" );	
    h12_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c12->SaveAs("~/cern/plots/trig_b_l2tos_tos.png");



    // trgh_track[0] plot section ---------------------------------------------------------------------------------------------------13

    // Define the histograms
    TH1D* h13 = new TH1D ("h13", "trgh_track[0]", 100, 0., 1.0);
    TH1D* h13_MC = new TH1D ("h13_MC", "trgh_track[0]", 100, 0., 1.0);
    
    
    // Differentiating the MC histo from the data histo
    h13->Sumw2(); 	//with this get markers, without get a line
    h13_MC->SetMarkerColor(kRed);
    h13_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("trgh_track[0]>>h13", "", "goff"); 	
    t2->Draw("trgh_track[0]>>h13_MC", "", "goff");


    // Scaling MC to data
    h13_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c13 = new TCanvas();
    c13->Divide(1,1);
    c13->cd(1);


    // Plotting 
    h13_MC->Draw();
    h13->Draw("same"); 	// draws on same pad
    h13_MC->GetXaxis()->SetTitle( "trgh_track[0]" );	
    h13_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c13->SaveAs("~/cern/plots/trgh_track[0].png");



    // trgh_track[1] plot section ---------------------------------------------------------------------------------------------------14

    // Define the histograms
    TH1D* h14 = new TH1D ("h14", "trgh_track[1]", 100, 0., 1.0);
    TH1D* h14_MC = new TH1D ("h14_MC", "trgh_track[1]", 100, 0., 1.0);
    
    
    // Differentiating the MC histo from the data histo
    h14->Sumw2(); 	//with this get markers, without get a line
    h14_MC->SetMarkerColor(kRed);
    h14_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("trgh_track[1]>>h14", "", "goff"); 	
    t2->Draw("trgh_track[1]>>h14_MC", "", "goff");


    // Scaling MC to data
    h14_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c14 = new TCanvas();
    c14->Divide(1,1);
    c14->cd(1);


    // Plotting 
    h14_MC->Draw();
    h14->Draw("same"); 	// draws on same pad
    h14_MC->GetXaxis()->SetTitle( "trgh_track[1]" );	
    h14_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c14->SaveAs("~/cern/plots/trgh_track[1].png");



    // trgh_track[2] plot section ---------------------------------------------------------------------------------------------------15

    // Define the histograms
    TH1D* h15 = new TH1D ("h15", "trgh_track[2]", 100, 0., 1.0);
    TH1D* h15_MC = new TH1D ("h15_MC", "trgh_track[2]", 100, 0., 1.0);
    
    
    // Differentiating the MC histo from the data histo
    h15->Sumw2(); 	//with this get markers, without get a line
    h15_MC->SetMarkerColor(kRed);
    h15_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("trgh_track[2]>>h15", "", "goff"); 	
    t2->Draw("trgh_track[2]>>h15_MC", "", "goff");


    // Scaling MC to data
    h15_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c15 = new TCanvas();
    c15->Divide(1,1);
    c15->cd(1);


    // Plotting 
    h15_MC->Draw();
    h15->Draw("same"); 	// draws on same pad
    h15_MC->GetXaxis()->SetTitle( "trgh_track[2]" );	
    h15_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c15->SaveAs("~/cern/plots/trgh_track[2].png");



    // trgh_track[3] plot section ---------------------------------------------------------------------------------------------------16

    // Define the histograms
    TH1D* h16 = new TH1D ("h16", "trgh_track[3]", 100, 0., 1.0);
    TH1D* h16_MC = new TH1D ("h16_MC", "trgh_track[3]", 100, 0., 1.0);
    
    
    // Differentiating the MC histo from the data histo
    h16->Sumw2(); 	//with this get markers, without get a line
    h16_MC->SetMarkerColor(kRed);
    h16_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("trgh_track[3]>>h16", "", "goff"); 	
    t2->Draw("trgh_track[3]>>h16_MC", "", "goff");


    // Scaling MC to data
    h16_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c16 = new TCanvas();
    c16->Divide(1,1);
    c16->cd(1);


    // Plotting 
    h16_MC->Draw();
    h16->Draw("same"); 	// draws on same pad
    h16_MC->GetXaxis()->SetTitle( "trgh_track[3]" );	
    h16_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c16->SaveAs("~/cern/plots/trgh_track[3].png");



    // ann_kaon[0] plot section ---------------------------------------------------------------------------------------------------17

    // Define the histograms
    TH1D* h17 = new TH1D ("h17", "ann_kaon[0]", 100, 0., 1.0);
    TH1D* h17_MC = new TH1D ("h17_MC", "ann_kaon[0]", 100, 0., 1.0);
    
    
    // Differentiating the MC histo from the data histo
    h17->Sumw2(); 	//with this get markers, without get a line
    h17_MC->SetMarkerColor(kRed);
    h17_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("ann_kaon[0]>>h17", "", "goff"); 	
    t2->Draw("ann_kaon[0]>>h17_MC", "", "goff");


    // Scaling MC to data
    h17_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c17 = new TCanvas();
    c17->Divide(1,1);
    c17->cd(1);


    // Plotting 
    h17_MC->Draw();
    h17->Draw("same"); 	// draws on same pad
    h17_MC->GetXaxis()->SetTitle( "ann_kaon[0]" );	
    h17_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c17->SaveAs("~/cern/plots/ann_kaon[0].png");



    // minann_mu plot section ---------------------------------------------------------------------------------------------------18

    // Define the histograms
    TH1D* h18 = new TH1D ("h18", "minann_mu", 100, 0., 1.0);
    TH1D* h18_MC = new TH1D ("h18_MC", "minann_mu", 100, 0., 1.0);
    
    
    // Differentiating the MC histo from the data histo
    h18->Sumw2(); 	//with this get markers, without get a line
    h18_MC->SetMarkerColor(kRed);
    h18_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("minann_mu>>h18", "", "goff"); 	
    t2->Draw("minann_mu>>h18_MC", "", "goff");


    // Scaling MC to data
    h18_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c18 = new TCanvas();
    c18->Divide(1,1);
    c18->cd(1);


    // Plotting 
    h18_MC->Draw();
    h18->Draw("same"); 	// draws on same pad
    h18_MC->GetXaxis()->SetTitle( "minann_mu" );	
    h18_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c18->SaveAs("~/cern/plots/minann_mu.png");


    // m_jpsi plot section ---------------------------------------------------------------------------------------------------19

    // Define the histograms
    TH1D* h19 = new TH1D ("h19", "m_jpsi", 100, 2.9, 3.3);
    TH1D* h19_MC = new TH1D ("h19_MC", "m_jpsi", 100, 2.9, 3.3);
    
    
    // Differentiating the MC histo from the data histo
    h19->Sumw2(); 	//with this get markers, without get a line
    h19_MC->SetMarkerColor(kRed);
    h19_MC->SetLineColor(kRed);


    // Draw the histogram for the data and the MC 
    t1->Draw("m_jpsi>>h19", "", "goff"); 	
    t2->Draw("m_jpsi>>h19_MC", "", "goff");


    // Scaling MC to data
    h19_MC->Scale(Ndata / float(NMC)); 


    // Setting up canvas
    TCanvas* c19 = new TCanvas();
    c19->Divide(1,1);
    c19->cd(1);


    // Plotting 
    h19_MC->Draw();
    h19->Draw("same"); 	// draws on same pad
    h19_MC->GetXaxis()->SetTitle( "Jpsi m [GeV/#it{c{^2}}]" );	
    h19_MC->GetYaxis()->SetTitle( yaxis.c_str() );
    lhcbName->Draw();		


    c19->SaveAs("~/cern/plots/m_jpsi.png");


    
std::cout << Ndata << " events total (without cuts)" << std::endl;
std::cout << NMC << " simulated events total (without cuts)" << std::endl;


}




/*
TO DO:

-- set up a script to do plots for me -- DONE
-- plot variables: 

1 pt_b
2 m_b_DTF_jpsi_chic1_constr 
3 dtf_b 
4 c2ip_b 
5 dls_b
6 c2ip_kminus 
7 c2ip_pplus 
8 minCl_gamma 
9 m_chic 
10 trig_b_l0tos_tos 
11 trig_b_l1tos_tos 
12 trig_b_l2tos_tos 
13 trgh_track[0] 
14 trgh_track[1] 
15 trgh_track[2] 
16 trgh_track[3] 
17 ann_kaon[0] 
18 minann_mu 
19 m_jpsi                                   -- DONE

20 m_pK
21 m_chicp
						
-- adapt reduceTree.C with cuts
-- record efficiency for each cut for both data and monte carlo, in a table. efficiency = N(after cut)/N(before cut)
-- want high signal (MC) efficiency and low background efficiency
*/






