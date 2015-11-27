/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to fit models to the data.

Script needs to go through different bdt cuts and record the S and B values to a new
tree perhaps, errors too. Do this in a loop. Then needs to plot the value of 
S/sqrt(S+B) with errors versus bdt cut value. This outside the loop.

First try this manually to get an idea of what needs to be done and in what order.

*/


#include <sstream>


void BDT_cuts(char * input_file = "~/cern/ntuples/withbdt.root", char * out_file = "~/cern/plots/Lb2chicpK_2011_2012_BDT_cuts.png"){

    gROOT->ProcessLine(".L lhcbstyle.C");
    //lhcbStyle();

    const std::string filename(input_file);
    const std::string treename = "withbdt";
    

    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;
    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;


    // -- signal, mass shape
    RooRealVar mass("mass","m(#chi_{c}pK^{-})", 5.55, 5.7); 
    //RooRealVar mass_chicp("mass_chicp","m(#chi_{c}p)", 4.35, 5.35, "GeV/c^{2}"); 
    //RooRealVar mass_pK("mass_pK","m(pK)", 1.3, 2.3, "GeV/c^{2}"); 
    RooRealVar mass_Jpsi("mass_Jpsi","m(#mu#mu)", 3.0, 3.2, "GeV/c^{2}"); 
    RooRealVar mass_Chic("mass_Chic","m(J/#psi#gamma)", 3.4, 3.7, "GeV/c^{2}"); 
    RooRealVar mean("mean","mean", 5.63, 5.61, 5.65);
    RooRealVar sigma1("sigma1","sigma1", 0.010, 0.001, 0.1);
    RooRealVar sigma2("sigma2","sigma2", 30.0, 5.0, 300.0);
    RooRealVar alpha1("alpha1","alpha1", 1.0, 0.5, 5.0);
    RooRealVar n1("n1","n1", 1.8, 0.2, 15.0);
    RooRealVar alpha2("alpha2","alpha2", -0.5, -5.5, 0.0);
    RooRealVar n2("n2","n2", 0.7, 0.2, 10.0);
    RooRealVar bkgcat_chic("bkgcat_chic","bkgcat_chic", 0, 100);
    RooRealVar bdtg3("bdtg3", "bdtg3", -1.0, 1.0);
    RooRealVar frac2("frac2","frac2", 0.3, 0., 1.);

    
    RooGaussian gauss1("gauss1","gauss1", mass, mean, sigma1);
    RooGaussian gauss2("gauss2","gauss2", mass, mean, sigma2);
    RooCBShape cb1("cb1","cb1", mass, mean, sigma1, alpha1, n1); 
    RooCBShape cb2("cb2","cb2", mass, mean, sigma2, alpha2, n2); 
    RooAddPdf sig("sig", "sig", RooArgList(cb1, cb2), RooArgList( frac2 ));
    RooRealVar cbRatio("cbRatio","cb Ratio", 0.8, 0.1, 1.0);
    RooRealVar sigYield("sigYield","sig Yield", 4e2, 1e1, 1e4);
    RooRealVar bgYield("bgYield","bg Yield", 1e4, 1e1, 1e5);

    
    //put in values from fit_MC here
 
    alpha1.setVal( 2.04670e+00  );
    alpha2.setVal( -2.01178e+00 );
    n1.setVal( 2.39553e+00 );
    n2.setVal( 3.08386e+00 );
    frac2.setVal( 6.18979e-01 );
    sigma1.setVal(3.84460e-03);
    sigma2.setVal(6.80489e-03);
    
    alpha1.setConstant( true );
    alpha2.setConstant( true );
    frac2.setConstant( true );
    n1.setConstant( true );
    n2.setConstant( true );
    sigma1.setConstant( true );
    sigma2.setConstant( true );

    // -- bg, mass shape
    RooRealVar a1("a1","a1", -0.1, -0.5, 0.5);
    RooChebychev comb("comb","comb", mass, a1);
    RooRealVar mean3("mean3","mean3", 5.56, 5.5, 5.6);
    RooRealVar sigma3("sigma3","sigma3", 0.005, 0.001, 0.01);
    RooRealVar frac3("frac3","frac", 0.2, 0.0, 0.3);
    RooGaussian gauss3("gauss3","gauss3", mass, mean3, sigma3);
    RooAddPdf bg("bg","bg", RooArgList(gauss3, comb), RooArgList(frac3));

    // -- add signal & bg
    RooAddPdf pdf("pdf", "pdf", RooArgList(sig, bg), RooArgList( sigYield, bgYield));  

    double efficiencies[40];
    double efficiencies_error[40];
    double bdt_cuts[40];


    //loop starting here
    for(int i=0; i < 40; i=i+1) 
    {
        double cut_val = -1.0 + i*0.05;
        bdt_cuts[i] = cut_val;
        
        std::stringstream c;
        c << "bdtg3" << " >= " << cut_val;
        const std::string cut = c.str();
        
        //std::cout << cut;

        RooArgSet obs;
        obs.add(mass);
        //obs.add(mass_chicp);
        //obs.add(mass_pK);
        obs.add(mass_Jpsi);
        obs.add(mass_Chic);
        obs.add(bdtg3);
        //obs.add(sigYield);
        //obs.add(bgYield);
        
        RooDataSet ds("ds","ds", obs, RooFit::Import(*tree), RooFit::Cut(cut.c_str())); 

        RooPlot* plot = mass.frame();
    
        RooFitResult * result = pdf.fitTo( ds, RooFit::Extended() );
        
        double sig_val = sigYield.getVal();
        double bg_val = bgYield.getVal();
        double sig_error = sigYield.getError();
        double bg_error = bgYield.getError();
        
        double efficiency = (sig_val)/(TMath::Sqrt(sig_val + bg_val));
        efficiencies[i] = efficiency;
        
        double efficiency_error_sq = (pow(sig_error,2)/(sig_val+bg_val) + (pow(sig_val,2)*(pow(sig_error,2)+pow(bg_error,2))/(4*pow((sig_val+bg_val),3))));
        
        double efficiency_error = TMath::Sqrt(efficiency_error_sq);
        efficiencies_error[i] = efficiency_error;
        
        
        //std::cout << "\n\n" << "BDT cut value = " << cut_val << "\n" ;
        //std::cout << "S = " << sig_val << " +/- " << sig_error << "\n" ;
        //std::cout << "B = " << bg_val << " +/- " << bg_error << "\n" ;
        //std::cout << "S/sqrt(S+B) = " << efficiency << " +/- " << efficiency_error << "\n\n" ;
        
        //ds.plotOn( plot );
        //pdf.plotOn( plot );




        //RooPlot* plotPullMass = mass.frame();

        //plotPullMass->addPlotable( plot->pullHist() );
        //plotPullMass->SetMinimum();
        //plotPullMass->SetMaximum();
        
        //std::cout << cut_val;
    }


    TCanvas *c1 = new TCanvas(); 
    
    
    
    //double zeros[20];
    //for (i=0, i<20, i++) zeros[i]=0.0;
    
    TGraphErrors* graph = new TGraphErrors(40, bdt_cuts, efficiencies, 0, efficiencies_error);
    
    graph->SetTitle("Efficiency vs BDTG3 cut");
    graph->SetMarkerColor(4);
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(1.0);
    graph->GetXaxis()->SetTitle("BDTG3 cut (>)");
    graph->GetXaxis()->SetRangeUser(-1.0,1.0);
    graph->GetYaxis()->SetTitle("S/sqrt(S+B)");
    //graph->Fit("pol5"); 
    graph->Draw("AP");
    
    return c1;
    c1->SaveAs(out_file.c_str);
    
/*
    TCanvas* c = new TCanvas();

    TPad* pad1 = new TPad("pad1","pad1", 0, 0.3, 1, 1.0);
    pad1->SetBottomMargin(0.1);
    pad1->SetTopMargin(0.1);
    pad1->Draw();
    c->cd();
    TPad* pad2 = new TPad("pad2","pad2", 0, 0, 1, 0.3);
    pad2->SetBottomMargin(0.1);
    pad2->SetTopMargin(0.0);
    pad2->Draw();


    //pdf.plotOn( plot, RooFit::Components( DfbPdf ), RooFit::LineColor( kRed ), RooFit::LineStyle(kDashed) );
    //pdf.plotOn( plot, RooFit::Components( promptPdf ), RooFit::LineColor( kBlue ), RooFit::LineStyle(kDotted) );
    //pdf.plotOn( plot, RooFit::Components( bgPdf ), RooFit::LineColor( kOrange ), RooFit::LineStyle(kDashDotted) );

    pad1->cd();
    plot->Draw();

    pad2->cd();
    plotPullMass->Draw("AP");

    c->SaveAs(out_file_mass);

    RooStats::SPlot* sData = new RooStats::SPlot("sData","An SPlot",
            ds, &pdf, RooArgList(sigYield, bgYield) );


    RooDataSet * dataw_z = new RooDataSet(ds.GetName(),ds.GetTitle(),&ds,*(ds.get()),0,"sigYield_sw") ;
*/
/*   
    TCanvas* d = new TCanvas();
    RooPlot* w_mass_chicp = mass_chicp.frame();
    dataw_z->plotOn(w_mass_chicp, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_mass_chicp->Draw();
    d->SaveAs("m_chicp_sweighted.png");
 
    TCanvas* e = new TCanvas();
    RooPlot* w_mass_pK = mass_pK.frame();
    dataw_z->plotOn(w_mass_pK, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_mass_pK->Draw();
    e->SaveAs("m_pK_sweighted.png");
*/
/*
    TCanvas* f = new TCanvas();
    RooPlot* w_mass_Jpsi = mass_Jpsi.frame();
    dataw_z->plotOn(w_mass_Jpsi, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_mass_Jpsi->Draw();
    f->SaveAs("m_Jpsi_sweighted.png");

    TCanvas* g = new TCanvas();
    RooPlot* w_mass_Chic = mass_Chic.frame();
    dataw_z->plotOn(w_mass_Chic, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_mass_Chic->Draw();
    g->SaveAs("m_Chic_sweighted.png");
    */
}