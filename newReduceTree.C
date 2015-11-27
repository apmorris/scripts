/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to apply manual cuts to the new data. 

*/


void newReduceTree(){ 

    // -- define tuple file name, tuple name and cuts to apply
    // -- and also the name of the output file
    const std::string filename = "";//change
    const std::string treename("");
    const std::string cuts = "";

    const std::string outFilename("");//change
  

    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;

    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;
  
    // -- activate the branches you need
  
    tree->SetBranchStatus("*", 0);
    
    tree->SetBranchStatus("chi_c_M",1);
    tree->SetBranchStatus("chi_c_P",1);
    tree->SetBranchStatus("chi_c_PE",1);      
    tree->SetBranchStatus("chi_c_PT",1);
    tree->SetBranchStatus("chi_c_PX",1);
    tree->SetBranchStatus("chi_c_PY",1);
    tree->SetBranchStatus("chi_c_PZ",1);
    tree->SetBranchStatus("chi_c_ETA",1);
    
    tree->SetBranchStatus("kaon_M",1);
    tree->SetBranchStatus("kaon_P",1);
    tree->SetBranchStatus("kaon_PE",1);
    tree->SetBranchStatus("kaon_PT",1);
    tree->SetBranchStatus("kaon_PX",1);
    tree->SetBranchStatus("kaon_PY",1);
    tree->SetBranchStatus("kaon_PZ",1);
    tree->SetBranchStatus("kaon_ETA",1);
    tree->SetBranchStatus("kaon_IPCHI2_OWNPV",1);
    tree->SetBranchStatus("kaon_TRACK_GhostProb",1);
    tree->SetBranchStatus("kaon_ProbNNp",1);
    tree->SetBranchStatus("kaon_ProbNNk",1);
    
    tree->SetBranchStatus("proton_M",1);
    tree->SetBranchStatus("proton_P",1);
    tree->SetBranchStatus("proton_PE",1);
    tree->SetBranchStatus("proton_PT",1);
    tree->SetBranchStatus("proton_PX",1);
    tree->SetBranchStatus("proton_PY",1);
    tree->SetBranchStatus("proton_PZ",1);
    tree->SetBranchStatus("proton_ETA",1);
    tree->SetBranchStatus("proton_IPCHI2_OWNPV",1);
    tree->SetBranchStatus("proton_TRACK_GhostProb",1);
    tree->SetBranchStatus("proton_ProbNNp",1);
    tree->SetBranchStatus("proton_ProbNNk",1);
    
    tree->SetBranchStatus("Jpsi_M",1);
    tree->SetBranchStatus("Jpsi_P",1);
    tree->SetBranchStatus("Jpsi_PE",1);
    tree->SetBranchStatus("Jpsi_PT",1);
    tree->SetBranchStatus("Jpsi_PX",1);
    tree->SetBranchStatus("Jpsi_PY",1);
    tree->SetBranchStatus("Jpsi_PZ",1);
    tree->SetBranchStatus("Jpsi_ETA",1);
    
    tree->SetBranchStatus("gamma_M",1);
    tree->SetBranchStatus("gamma_P",1);
    tree->SetBranchStatus("gamma_PE",1);
    tree->SetBranchStatus("gamma_PT",1);
    tree->SetBranchStatus("gamma_PX",1);
    tree->SetBranchStatus("gamma_PY",1);
    tree->SetBranchStatus("gamma_PZ",1);
    tree->SetBranchStatus("gamma_ETA",1);
    tree->SetBranchStatus("gamma_CL",1);
    
    tree->SetBranchStatus("muminus_M",1);
    tree->SetBranchStatus("muminus_P",1);
    tree->SetBranchStatus("muminus_PE",1);
    tree->SetBranchStatus("muminus_PT",1);
    tree->SetBranchStatus("muminus_PX",1);
    tree->SetBranchStatus("muminus_PY",1);
    tree->SetBranchStatus("muminus_PZ",1);
    tree->SetBranchStatus("muminus_ETA",1);
    tree->SetBranchStatus("muminus_ProbNNmu",1);
    tree->SetBranchStatus("muminus_TRACK_GhostProb",1); 
    
    tree->SetBranchStatus("muplus_M",1);
    tree->SetBranchStatus("muplus_P",1);
    tree->SetBranchStatus("muplus_PE",1);
    tree->SetBranchStatus("muplus_PT",1);
    tree->SetBranchStatus("muplus_PX",1);
    tree->SetBranchStatus("muplus_PY",1);
    tree->SetBranchStatus("muplus_PZ",1);
    tree->SetBranchStatus("muplus_ETA",1);
    tree->SetBranchStatus("muplus_ProbNNmu",1);
    tree->SetBranchStatus("muplus_TRACK_GhostProb",1);
    
    tree->SetBranchStatus("Lambda_b0_DTF_MASS_constr1",1);
    tree->SetBranchStatus("Lambda_b0_DTF_CHI2NDOF",1);
    tree->SetBranchStatus("Lambda_b0_IPCHI2_OWNPV",1);
    tree->SetBranchStatus("Lambda_b0_FDS",1);
    tree->SetBranchStatus("Lambda_b0_L0MuonDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_L0DiMuonDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt1DiMuonHighMassDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt1DiMuonLowMassDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt1TrackMuonDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt2DiMuonDetachedDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS",1);
    tree->SetBranchStatus("Lambda_b0_pi0veto",1);
    
 /*   
    //for MC only
    tree->SetBranchStatus("chi_c_BKGCAT",1);
    tree->SetBranchStatus("kaon_BKGCAT",1);
    tree->SetBranchStatus("proton_BKGCAT",1);
    tree->SetBranchStatus("Jpsi_BKGCAT",1);
    tree->SetBranchStatus("muminus_BKGCAT",1);
    tree->SetBranchStatus("muplus_BKGCAT",1);
    tree->SetBranchStatus("gamma_BKGCAT",1);
    tree->SetBranchStatus("Lambda_b0_BKGCAT",1);
 */  
    
    
    // -- this file is just here to make the 'CopyTree' happy
    TFile* dummyFile = new TFile("~/cern/ntuples/dummy.root","RECREATE");
    TTree* rTree1 = tree->CopyTree( cuts.c_str() );

    double chi_c_M,  chi_c_P, chi_c_PE, chi_c_PT, chi_c_PX, chi_c_PY, chi_c_PZ, chi_c_ETA;
    double kaon_M,  kaon_P, kaon_PE, kaon_PX, kaon_PT, kaon_PY, kaon_PZ, kaon_ETA, kaon_IPCHI2_OWNPV, kaon_TRACK_GhostProb;
    double proton_M,  proton_P, proton_PE, proton_PT, proton_PX, proton_PY, proton_PZ, proton_ETA, proton_IPCHI2_OWNPV, proton_TRACK_GhostProb;
    double Jpsi_M, Jpsi_P, Jpsi_PE, Jpsi_PT, Jpsi_PX, Jpsi_PY, Jpsi_PZ, Jpsi_ETA;
    double gamma_M, gamma_P, gamma_PE, gamma_PT, gamma_PX, gamma_PY, gamma_PZ, gamma_ETA, gamma_CL;
    double muminus_M, muminus_P, muminus_PE, muminus_PT, muminus_PX, muminus_PY, muminus_PZ, muminus_ETA, muminus_ProbNNmu, muminus_TRACK_GhostProb;
    double muplus_M, muplus_P, muplus_PE, muplus_PT, muplus_PX, muplus_PY, muplus_PZ, muplus_ETA, muplus_ProbNNmu, muplus_TRACK_GhostProb;
    double Lambda_b0_DTF_MASS_constr1, Lambda_b0_DTF_CHI2NDOF, Lambda_b0_IPCHI2_OWNPV;
    double Lambda_b0_FDS, Lambda_b0_L0MuonDecision_TOS, Lambda_b0_L0DiMuonDecision_TOS;
    double Lambda_b0_Hlt1DiMuonHighMassDecision_TOS, Lambda_b0_Hlt1DiMuonLowMassDecision_TOS;
    double Lambda_b0_Hlt1TrackMuonDecision_TOS;
    double Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS, Lambda_b0_Hlt2DiMuonDetachedDecision_TOS;
    double Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS, Lambda_b0_pi0veto;
    
    
    rTree1->SetBranchAddress("chi_c_M", &chi_c_M);
    rTree1->SetBranchAddress("chi_c_P", &chi_c_P);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    rTree1->SetBranchAddress("", &);
    
    
    

    TFile* rFile = new TFile( outFilename.c_str() ,"RECREATE");
    TTree* rTree2 = new TTree();
    rTree2->SetName("MyTuple");
    rTree2->Branch("mass", &mass, "mass/F");
    //rTree2->Branch("mass_chicp", &mass_chicp, "mass_chicp/F");//not in MC
    //rTree2->Branch("mass_pK", &mass_pK, "mass_pK/F");//not in MC
    rTree2->Branch("mass_jpsi", &mass_jpsi, "mass_jpsi/F");
    rTree2->Branch("mass_chic", &mass_chic, "mass_chic/F");
    rTree2->Branch("dtf_b", &dtf_b, "dtf_b/F");
    

    int percentCounter = 1;

    for(int i = 0; i < rTree1->GetEntries(); ++i){
  
      /*const int percent = (int)(rTree1->GetEntries()/100.0);
    
      if( i == percent*percentCounter ){
        //std::cout << percentCounter << " %" << std::endl;
        percentCounter++;
      }
      */
      rTree1->GetEntry(i);
      rTree2->Fill();
      //std::cout << mass << std::endl;   
    }
    rTree2->Print();
    rTree2->Write();
    rFile->Save();

}


/*
m_b_DTF_jpsi_chic1_constr>5.55&&m_b_DTF_jpsi_chic1_constr<5.7&&dtf_b<5 && c2ip_b <15 && dls_b>12 && c2ip_kminus>5 && c2ip_pplus > 5 && minCl_gamma > 0.05 && m_chic>3.4 && m_chic < 3.7&&trig_b_l0tos_tos == 1 &&trig_b_l1tos_tos == 1 && trig_b_l2tos_tos == 1 && trgh_track[0] < 0.3 && trgh_track[1] < 0.3 && trgh_track[2] < 0.3 && trgh_track[3] < 0.3&& ann_kaon[0]>0.3&&minann_mu>0.3
*/



