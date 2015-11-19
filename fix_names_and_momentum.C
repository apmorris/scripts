/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to calculate the momentum amplitude from the exsiting MC ntuple, 
	and rename the variables of interest while we're at it.

*/




#include <TLorentzVector.h>


void fix_names_and_momentum() {

    // -- define tuple file name, tuple name and cuts to apply-----------------------
    // -- and also the name of the output file
    const std::string filename = "~/cern/ntuples/Lb2chicpK_MC_2011_2012_signal.root";
    const std::string treename = "HistosAndTuples/MyTuple";
    const std::string outFilename("~/cern/ntuples/Lb2chicpK_MC_2011_2012_signal_fixed.root");
   
   
    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;

    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;

    // -- activate the branches you need---------------------------------------------
  
    tree->SetBranchStatus("*", 0);
    tree->SetBranchStatus("m_b_DTF_jpsi_chic1_constr",1);
    tree->SetBranchStatus("dtf_b",1);
    tree->SetBranchStatus("c2ip_b",1);
    tree->SetBranchStatus("dls_b",1);
    tree->SetBranchStatus("c2ip_kminus",1);
    tree->SetBranchStatus("c2ip_pplus",1);
    tree->SetBranchStatus("minCl_gamma",1);
    tree->SetBranchStatus("m_chic",1);  
    tree->SetBranchStatus("trig_b_l0tos_tos",1);
    tree->SetBranchStatus("trig_b_l1tos_tos",1);
    tree->SetBranchStatus("trig_b_l2tos_tos",1);
    tree->SetBranchStatus("trgh_track",1);
    tree->SetBranchStatus("ann_kaon",1);
    tree->SetBranchStatus("minann_K",1);
    tree->SetBranchStatus("ann_proton",1);
    tree->SetBranchStatus("minann_P",1);
    tree->SetBranchStatus("ann_mu",1);
    tree->SetBranchStatus("minann_mu",1);
    tree->SetBranchStatus("p4_pplusE",1);
    tree->SetBranchStatus("p4_pplusX",1);
    tree->SetBranchStatus("p4_pplusY",1); 
    tree->SetBranchStatus("p4_pplusZ",1);
    tree->SetBranchStatus("p4_kminusE",1);
    tree->SetBranchStatus("p4_kminusX",1);  
    tree->SetBranchStatus("p4_kminusY",1);  
    tree->SetBranchStatus("p4_kminusZ",1);     
    //tree->SetBranchStatus("m_chicp",1);//not in MC
    //tree->SetBranchStatus("m_pK",1);//not in MC
    tree->SetBranchStatus("m_jpsi",1);
    tree->SetBranchStatus("bkgcat_b",1);//only in MC
    tree->SetBranchStatus("bkgcat_chic",1); //only in MC
    tree->SetBranchStatus("bkgcat_gamma",1);//only in MC
    tree->SetBranchStatus("bkgcat_jpsi",1);//only in MC
    tree->SetBranchStatus("bkgcat_kaon",1);//only in MC
    tree->SetBranchStatus("bkgcat_proton",1);//only in MC   
    
    
    
    
     // -- this file is just here to make the 'CopyTree' happy
    TFile* dummyFile = new TFile("~/cern/ntuples/dummy.root","RECREATE");
    TTree* rTree1 = tree->CopyTree("");


    //this is the important renaming bit---------------------------------------------

    float m_b_DTF_jpsi_chic1_constr, m_chicp, m_pK, m_jpsi, m_chic; 
    float dtf_b, c2ip_b, dls_b, c2ip_kminus, c2ip_pplus, minCl_gamma, trgh_track;  
    float ann_kaon, ProbNNK, ann_proton, ProbNNp, ann_mu, minann_mu; 
    double P_PX, P_PY, P_PZ, P_PE;
    double K_PX, K_PY, K_PZ, K_PE;
    bool trig_b_l0tos_tos, trig_b_l1tos_tos, trig_b_l2tos_tos;
    float bkgcat_b, bkgcat_chic, bkgcat_gamma, bkgcat_jpsi, bkgcat_kaon, bkgcat_proton;
    
        
    rTree1->SetBranchAddress("m_b_DTF_jpsi_chic1_constr", &m_b_DTF_jpsi_chic1_constr);
    //rTree1->SetBranchAddress("m_chicp", &m_chicp);//not in MC
    //rTree1->SetBranchAddress("m_pK", &m_pK);//not in MC
    rTree1->SetBranchAddress("m_jpsi", &m_jpsi);
    rTree1->SetBranchAddress("m_chic", &m_chic);
    rTree1->SetBranchAddress("dtf_b", &dtf_b);
    rTree1->SetBranchAddress("c2ip_b", &c2ip_b);
    rTree1->SetBranchAddress("dls_b", &dls_b);
    rTree1->SetBranchAddress("c2ip_kminus", &c2ip_kminus);
    rTree1->SetBranchAddress("c2ip_pplus", &c2ip_pplus);
    rTree1->SetBranchAddress("minCl_gamma", &minCl_gamma);
    rTree1->SetBranchAddress("trig_b_l0tos_tos", &trig_b_l0tos_tos);
    rTree1->SetBranchAddress("trig_b_l1tos_tos", &trig_b_l1tos_tos);
    rTree1->SetBranchAddress("trig_b_l2tos_tos", &trig_b_l2tos_tos);
    rTree1->SetBranchAddress("trgh_track", &trgh_track);
    rTree1->SetBranchAddress("ann_kaon", &ann_kaon);
    rTree1->SetBranchAddress("minann_K", &ProbNNK);//K_ProbNNk???
    rTree1->SetBranchAddress("ann_proton", &ann_proton);
    rTree1->SetBranchAddress("minann_P", &ProbNNp);//P_ProbNNp???
    rTree1->SetBranchAddress("ann_mu", &ann_mu);
    rTree1->SetBranchAddress("minann_mu", &minann_mu);
    rTree1->SetBranchAddress("p4_pplusX", &P_PX);
    rTree1->SetBranchAddress("p4_pplusY", &P_PY);
    rTree1->SetBranchAddress("p4_pplusZ", &P_PZ);
    rTree1->SetBranchAddress("p4_pplusE", &P_PE);
    rTree1->SetBranchAddress("p4_kminusX", &K_PX);
    rTree1->SetBranchAddress("p4_kminusY", &K_PY);
    rTree1->SetBranchAddress("p4_kminusZ", &K_PZ);
    rTree1->SetBranchAddress("p4_kminusE", &K_PE);
    rTree1->SetBranchAddress("bkgcat_b", &bkgcat_b);//only in MC
    rTree1->SetBranchAddress("bkgcat_chic", &bkgcat_chic);//only in MC
    rTree1->SetBranchAddress("bkgcat_gamma", &bkgcat_gamma);//only in MC
    rTree1->SetBranchAddress("bkgcat_jpsi", &bkgcat_jpsi);//only in MC
    rTree1->SetBranchAddress("bkgcat_kaon", &bkgcat_kaon);//only in MC
    rTree1->SetBranchAddress("bkgcat_proton", &bkgcat_proton);//only in MC
    rTree1->SetBranchAddress("bkgcat_chic", &bkgcat_chic);//only in MC

    //-------------------------------------------------------------------------------

    //this is the important renaming bit---------------------------------------------

    TFile* rFile = new TFile( outFilename.c_str() ,"RECREATE");
    TTree* rTree2 = new TTree();
    rTree2->SetName("MyTuple");
    rTree2->Branch("m_b_DTF_jpsi_chic1_constr", &m_b_DTF_jpsi_chic1_constr, "m_b_DTF_jpsi_chic1_constr/F");
    //rTree2->Branch("m_chicp", &m_chicp, "m_chicp/F");//not in MC
    //rTree2->Branch("m_pK", &m_pK, "m_pK/F");//not in MC
    rTree2->Branch("m_jpsi", &m_jpsi, "m_jpsi/F");
    rTree2->Branch("m_chic", &m_chic, "m_chic/F");
    rTree2->Branch("dtf_b", &dtf_b, "dtf_b/F");
    rTree2->Branch("c2ip_b", &c2ip_b, "c2ip_b/F");
    rTree2->Branch("dls_b", &dls_b, "dls_b/F");
    rTree2->Branch("c2ip_kminus", &c2ip_kminus, "c2ip_kminus/F");
    rTree2->Branch("c2ip_pplus", &c2ip_pplus, "c2ip_pplus/F");
    rTree2->Branch("minCl_gamma", &minCl_gamma, "minCl_gamma/F");
    rTree2->Branch("trig_b_l0tos_tos", &trig_b_l0tos_tos, "trig_b_l0tos_tos/B");
    rTree2->Branch("trig_b_l1tos_tos", &trig_b_l1tos_tos, "trig_b_l1tos_tos/B");
    rTree2->Branch("trig_b_l2tos_tos", &trig_b_l2tos_tos, "trig_b_l2tos_tos/B");
    rTree2->Branch("trgh_track", &trgh_track, "trgh_track/F");
    rTree2->Branch("ann_kaon", &ann_kaon, "ann_kaon/F");
    rTree2->Branch("K_ProbNNK", &ProbNNK, "K_ProbNNK/F");
    rTree2->Branch("ann_proton", &ann_proton, "ann_proton/F");
    rTree2->Branch("P_ProbNNp", &ProbNNp, "P_ProbNNp/F");
    rTree2->Branch("ann_mu", &ann_mu, "ann_mu/F");
    rTree2->Branch("minann_mu", &minann_mu, "minann_mu/F");
    rTree2->Branch("P_PX", &P_PX, "P_PX/D");
    rTree2->Branch("P_PY", &P_PY, "P_PY/D");
    rTree2->Branch("P_PZ", &P_PZ, "P_PZ/D");
    rTree2->Branch("P_PE", &P_PE, "P_PE/D");
    rTree2->Branch("K_PX", &K_PX, "K_PX/D");
    rTree2->Branch("K_PY", &K_PY, "K_PY/D");
    rTree2->Branch("K_PZ", &K_PZ, "K_PZ/D");
    rTree2->Branch("K_PE", &K_PE, "K_PE/D");
    rTree2->Branch("bkgcat_b", &bkgcat_b, "bkgcat_b/F");//only in MC
    rTree2->Branch("bkgcat_gamma", &bkgcat_gamma, "bkgcat_gamma/F");//only in MC
    rTree2->Branch("bkgcat_jpsi", &bkgcat_jpsi, "bkgcat_jpsi/F");//only in MC
    rTree2->Branch("bkgcat_kaon", &bkgcat_kaon, "bkgcat_kaon/F");//only in MC
    rTree2->Branch("bkgcat_proton", &bkgcat_proton, "bkgcat_proton/F");//only in MC
    rTree2->Branch("bkgcat_chic", &bkgcat_chic, "bkgcat_chic/F");//only in MC




    //This is where the momentum is calculated for P and K---------------------------
    
    //TLorentzVector * p_mom = new TLorentzVector(P_PX, P_PY, P_PZ, P_PE);
    //TLorentzVector * k_mom = new TLorentzVector(K_PX, K_PY, K_PZ, K_PE);    

    double p_momentum, k_momentum, p_eta, k_eta;

    rTree2->Branch("P_P", &p_momentum, "P_P/D");
    rTree2->Branch("K_P", &k_momentum, "K_P/D");
    rTree2->Branch("P_ETA", &p_eta, "P_ETA/D");
    rTree2->Branch("K_ETA", &k_eta, "K_ETA/D");
    for(int i = 0; i < rTree1->GetEntries(); ++i){    
    //for event in tree
    
        rTree1->GetEntry(i);
        
        TLorentzVector * p_mom = new TLorentzVector(P_PX, P_PY, P_PZ, P_PE);
        TLorentzVector * k_mom = new TLorentzVector(K_PX, K_PY, K_PZ, K_PE);  
              
        k_momentum = k_mom->P();
        p_momentum = p_mom->P();
        k_eta = k_mom->Eta();
        p_eta = p_mom->Eta();
        
        rTree2->Fill();
        
    }

   
    rTree2->Print();
    rTree2->Write();
    rFile->Save();



}









