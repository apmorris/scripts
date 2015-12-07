/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to fit models to the data.


*/



void fit_and_weights(){

    gROOT->ProcessLine(".L lhcbstyle.C");
    //lhcbStyle();



    const std::string filename("~/cern/ntuples/new_tuples/reduced_Lb2chicpK_2011_2012_signal.root");
    const std::string treename = "DecayTree";
    const std::string out_file_mass("~/cern/plots/fitting/Lb2chicpK_2011_2012_mass_fit_weights.png");
    

    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;
    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;



    // -- signal, mass shape
    RooRealVar Lambda_b0_DTF_MASS_constr1("Lambda_b0_DTF_MASS_constr1","m(#chi_{c}pK^{-})", 5550., 5700., "MeV/c^{2}"); 
    RooRealVar Jpsi_M("Jpsi_M","m(#mu#mu)", 3000., 3200., "MeV/c^{2}"); 
    RooRealVar chi_c_M("chi_c_M","m(J/#psi#gamma)", 3400., 3700., "MeV/c^{2}"); 
    RooRealVar mean("mean","mean", 5630., 5610., 5650.);
    RooRealVar sigma1("sigma1","sigma1", 10., 1., 100.);
    RooRealVar sigma2("sigma2","sigma2", 30.0, 5.0, 300.0);
    RooRealVar alpha1("alpha1","alpha1", 1.0, 0.5, 5.0);
    RooRealVar n1("n1","n1", 1.8, 0.2, 15.0);
    RooRealVar alpha2("alpha2","alpha2", -0.5, -5.5, 0.0);
    RooRealVar n2("n2","n2", 0.7, 0.2, 10.0);
    RooRealVar bkgcat_chic("bkgcat_chic","bkgcat_chic", 0, 100);
    //RooRealVar bdtg3("bdtg3", "bdtg3", -1.0, 1.0);
    RooRealVar frac2("frac2","frac2", 0.3, 0., 1.);
    
    
    RooRealVar proton_ProbNNp("proton_ProbNNp","proton_ProbNNp",0.0,1.0);
    RooRealVar proton_ProbNNk("proton_ProbNNk","proton_ProbNNk",0.0,1.0);
    RooRealVar kaon_ProbNNp("kaon_ProbNNp","kaon_ProbNNp",0.0,1.0);
    RooRealVar kaon_ProbNNk("kaon_ProbNNk","kaon_ProbNNk",0.0,1.0);
    
    
    RooGaussian gauss1("gauss1","gauss1", Lambda_b0_DTF_MASS_constr1, mean, sigma1);
    RooGaussian gauss2("gauss2","gauss2", Lambda_b0_DTF_MASS_constr1, mean, sigma2);
    RooCBShape cb1("cb1","cb1", Lambda_b0_DTF_MASS_constr1, mean, sigma1, alpha1, n1); 
    RooCBShape cb2("cb2","cb2", Lambda_b0_DTF_MASS_constr1, mean, sigma2, alpha2, n2); 
    RooAddPdf sig("sig", "sig", RooArgList(cb1, cb2), RooArgList( frac2 ));
    RooRealVar cbRatio("cbRatio","cb Ratio", 0.8, 0.1, 1.0);
    RooRealVar sigYield("sigYield","sig Yield", 4e2, 1e1, 1e4);
    RooRealVar bgYield("bgYield","bg Yield", 1e4, 1e1, 1e5);

    
    //put in values from fit_MC here
 
    alpha1.setVal( 2.12259e+00 );
    alpha2.setVal( -2.07568e+00  );
    n1.setVal( 9.17484e+00 );
    n2.setVal( 2.48592e+00 );
    frac2.setVal( 7.96312e-01 );
    sigma1.setVal( 4.18248e+00 );
    sigma2.setVal( 8.98812e+00 );
    
    alpha1.setConstant( true );
    alpha2.setConstant( true );
    frac2.setConstant( true );
    n1.setConstant( true );
    n2.setConstant( true );
    sigma1.setConstant( true );
    sigma2.setConstant( true );

    // -- bg, mass shape
    RooRealVar a1("a1","a1", -0.1, -0.5, 0.5);
    RooChebychev comb("comb","comb", Lambda_b0_DTF_MASS_constr1, a1);
    RooRealVar mean3("mean3","mean3", 5560., 5500., 5600.);
    RooRealVar sigma3("sigma3","sigma3", 5., 1., 10.);
    RooRealVar frac3("frac3","frac", 0.2, 0.0, 0.3);
    RooGaussian gauss3("gauss3","gauss3", Lambda_b0_DTF_MASS_constr1, mean3, sigma3);
    RooAddPdf bg("bg","bg", RooArgList(gauss3, comb), RooArgList(frac3));

    // -- add signal & bg
    RooAddPdf pdf("pdf", "pdf", RooArgList(sig, bg), RooArgList( sigYield, bgYield));  

    RooArgSet obs;
    obs.add(Lambda_b0_DTF_MASS_constr1);
    //obs.add(chi_c_Mp);
    //obs.add(mass_pK);
    obs.add(Jpsi_M);
    obs.add(chi_c_M);
    obs.add(proton_ProbNNp);
    obs.add(proton_ProbNNk);
    obs.add(kaon_ProbNNp);
    obs.add(kaon_ProbNNk);
    //obs.add(bdtg3);    
    
    RooDataSet ds("ds","ds", obs, RooFit::Import(*tree)); 

    RooPlot* plot = Lambda_b0_DTF_MASS_constr1.frame();

    RooFitResult * result = pdf.fitTo( ds, RooFit::Extended() );
    ds.plotOn( plot );
    pdf.plotOn( plot );

    RooPlot* plotPullMass = Lambda_b0_DTF_MASS_constr1.frame();

    plotPullMass->addPlotable( plot->pullHist() );
    //plotPullMass->SetMinimum();
    //plotPullMass->SetMaximum();

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

    c->SaveAs(out_file_mass.c_str());

    RooStats::SPlot* sData = new RooStats::SPlot("sData","An SPlot",
            ds, &pdf, RooArgList(sigYield, bgYield) );


    RooDataSet * dataw_z = new RooDataSet(ds.GetName(),ds.GetTitle(),&ds,*(ds.get()),0,"sigYield_sw") ;
    
    TTree *tree_data = (TTree*)dataw_z->tree();
    TFile * newfile = TFile::Open("~/cern/ntuples/new_tuples/weighted_data.root","RECREATE");
    tree_data->Write();
    newfile->Close();   
 /* 
    TCanvas* d = new TCanvas();
    RooPlot* w_chi_c_Mp = chi_c_Mp.frame();
    dataw_z->plotOn(w_chi_c_Mp, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_chi_c_Mp->Draw();
    d->SaveAs("m_chicp_sweighted.png");
 
    TCanvas* e = new TCanvas();
    RooPlot* w_mass_pK = mass_pK.frame();
    dataw_z->plotOn(w_mass_pK, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_mass_pK->Draw();
    e->SaveAs("m_pK_sweighted.png");
*/
/*
    TCanvas* f = new TCanvas();
    RooPlot* w_Jpsi_M = Jpsi_M.frame();
    dataw_z->plotOn(w_Jpsi_M, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_Jpsi_M->Draw();
    f->SaveAs("~/cern/plots/m_Jpsi_sweighted.png");

    TCanvas* g = new TCanvas();
    RooPlot* w_chi_c_M = chi_c_M.frame();
    dataw_z->plotOn(w_chi_c_M, RooFit::DataError(RooAbsData::SumW2), RooFit::Binning(20)) ;
    w_chi_c_M->Draw();
    g->SaveAs("~/cern/plots/m_Chic_sweighted.png");
    */
}
