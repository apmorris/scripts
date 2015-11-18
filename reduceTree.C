/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to apply manual cuts to the data in order to 
	single out the signal. These can be plotted using
	plot_reduced.C

*/


void reduceTree(){ 

    // -- define tuple file name, tuple name and cuts to apply
    // -- and also the name of the output file
    const std::string filename = "~/cern/ntuples/Lb2chicpK_2011_2012_signal_fixed.root";//change
    const std::string treename("MyTuple");
    const std::string cuts = "m_b_DTF_jpsi_chic1_constr > 5.55 && m_b_DTF_jpsi_chic1_constr < 5.7 && dtf_b < 7 && dtf_b > 0 && c2ip_b < 25 && dls_b > 10 && c2ip_kminus > 4 && c2ip_pplus > 4 && minCl_gamma > 0.03 && m_chic > 3.4 && m_chic < 3.7  && trgh_track[0] < 0.3 && trgh_track[1] < 0.3 && trgh_track[2] < 0.3 && trgh_track[3] < 0.3 && ProbNNk > 0.15 && minann_mu > 0.1 && trig_b_l0tos_tos == 1 && trig_b_l1tos_tos == 1 && trig_b_l2tos_tos == 1";
// && bkgcat_chic < 10 && bkgcat_b < 10" 
// && trig_b_l0tos_tos == 1.0 && trig_b_l1tos_tos == 1.0 && trig_b_l2tos_tos == 1.0
    const std::string outFilename("~/cern/ntuples/reducedTree.root");//change
  

    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;

    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;
  
    // -- activate the branches you need
  
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
    tree->SetBranchStatus("ProbNNk",1);
    tree->SetBranchStatus("ann_proton",1);
    tree->SetBranchStatus("ProbNNp",1);
    tree->SetBranchStatus("ann_mu",1);
    tree->SetBranchStatus("minann_mu",1);
    tree->SetBranchStatus("m_chicp",1);//not in MC
    tree->SetBranchStatus("m_pK",1);//not in MC
    tree->SetBranchStatus("m_jpsi",1);
    //tree->SetBranchStatus("bkgcat_b",1);//only in MC
    //tree->SetBranchStatus("bkgcat_chic",1); //only in MC
    //tree->SetBranchStatus("bkgcat_gamma",1);//only in MC
    //tree->SetBranchStatus("bkgcat_jpsi",1);//only in MC
    //tree->SetBranchStatus("bkgcat_kaon",1);//only in MC
   // tree->SetBranchStatus("bkgcat_proton",1);//only in MC
    tree->SetBranchStatus("P_PX",1);
    tree->SetBranchStatus("P_PY",1);    
    tree->SetBranchStatus("P_PZ",1);    
    tree->SetBranchStatus("P_PE",1);    
    tree->SetBranchStatus("P_P",1);    
    tree->SetBranchStatus("K_PX",1);    
    tree->SetBranchStatus("K_PY",1);    
    tree->SetBranchStatus("K_PZ",1);    
    tree->SetBranchStatus("K_PE",1);    
    tree->SetBranchStatus("K_P",1);    
    
    
    // -- this file is just here to make the 'CopyTree' happy
    TFile* dummyFile = new TFile("~/cern/ntuples/dummy.root","RECREATE");
    TTree* rTree1 = tree->CopyTree( cuts.c_str() );

    float mass, mass_chicp, mass_pK, mass_jpsi, mass_chic, dtf_b, c2ip_b, dls_b, c2ip_kminus, c2ip_pplus, minCl_gamma, trgh_track, ann_kaon, ProbNNk, ann_proton, ProbNNp, ann_mu, minann_mu, bkgcat_b, bkgcat_chic, bkgcat_gamma, bkgcat_jpsi, bkgcat_kaon, bkgcat_proton;
    double P_PX, P_PY, P_PZ, P_PE, P_P, K_PX, K_PY, K_PZ, K_PE, K_P;

    bool trig_b_l0tos_tos, trig_b_l1tos_tos, trig_b_l2tos_tos;

    rTree1->SetBranchAddress("m_b_DTF_jpsi_chic1_constr", &mass);
    rTree1->SetBranchAddress("m_chicp", &mass_chicp);//not in MC
    rTree1->SetBranchAddress("m_pK", &mass_pK);//not in MC
    rTree1->SetBranchAddress("m_jpsi", &mass_jpsi);
    rTree1->SetBranchAddress("m_chic", &mass_chic);
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
    rTree1->SetBranchAddress("ProbNNk", &ProbNNk);
    rTree1->SetBranchAddress("ann_proton", &ann_proton);
    rTree1->SetBranchAddress("ProbNNp", &ProbNNp);
    rTree1->SetBranchAddress("ann_mu", &ann_mu);
    rTree1->SetBranchAddress("minann_mu", &minann_mu);
    //rTree1->SetBranchAddress("bkgcat_b", &bkgcat_b);//only in MC
    //rTree1->SetBranchAddress("bkgcat_chic", &bkgcat_chic);//only in MC
    //rTree1->SetBranchAddress("bkgcat_gamma", &bkgcat_gamma);//only in MC
    //rTree1->SetBranchAddress("bkgcat_jpsi", &bkgcat_jpsi);//only in MC
    //rTree1->SetBranchAddress("bkgcat_kaon", &bkgcat_kaon);//only in MC
    //rTree1->SetBranchAddress("bkgcat_proton", &bkgcat_proton);//only in MC
    rTree1->SetBranchAddress("P_PX",&P_PX);
    rTree1->SetBranchAddress("P_PY",&P_PY);    
    rTree1->SetBranchAddress("P_PZ",&P_PZ);    
    rTree1->SetBranchAddress("P_PE",&P_PE);    
    rTree1->SetBranchAddress("P_P",&P_P);    
    rTree1->SetBranchAddress("K_PX",&K_PX);    
    rTree1->SetBranchAddress("K_PY",&K_PY);    
    rTree1->SetBranchAddress("K_PZ",&K_PZ);    
    rTree1->SetBranchAddress("K_PE",&K_PE);    
    rTree1->SetBranchAddress("K_P",&K_P); 




    TFile* rFile = new TFile( outFilename.c_str() ,"RECREATE");
    TTree* rTree2 = new TTree();
    rTree2->SetName("reducedTree");
    rTree2->Branch("mass", &mass, "mass/F");
    rTree2->Branch("mass_chicp", &mass_chicp, "mass_chicp/F");//not in MC
    rTree2->Branch("mass_pK", &mass_pK, "mass_pK/F");//not in MC
    rTree2->Branch("mass_jpsi", &mass_jpsi, "mass_jpsi/F");
    rTree2->Branch("mass_chic", &mass_chic, "mass_chic/F");
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
    rTree2->Branch("ProbNNk", &ProbNNk, "ProbNNk/F");
    rTree2->Branch("ann_proton", &ann_proton, "ann_proton/F");
    rTree2->Branch("ProbNNp", &ProbNNp, "ProbNNp/F");
    rTree2->Branch("ann_mu", &ann_mu, "ann_mu/F");
    rTree2->Branch("minann_mu", &minann_mu, "minann_mu/F");
    //rTree2->Branch("bkgcat_b", &bkgcat_b, "bkgcat_b/F");//only in MC
    //rTree2->Branch("bkgcat_chic", &bkgcat_chic, "bkgcat_chic/F");//only in MC
    //rTree2->Branch("bkgcat_gamma", &bkgcat_gamma, "bkgcat_gamma/F");//only in MC
    //rTree2->Branch("bkgcat_jpsi", &bkgcat_jpsi, "bkgcat_jpsi/F");//only in MC
    //rTree2->Branch("bkgcat_kaon", &bkgcat_kaon, "bkgcat_kaon/F");//only in MC
    //rTree2->Branch("bkgcat_proton", &bkgcat_proton, "bkgcat_proton/F");//only in MC
    rTree2->Branch("P_PX",&P_PX, "P_PX/D");
    rTree2->Branch("P_PY",&P_PY, "P_PY/D");    
    rTree2->Branch("P_PZ",&P_PZ, "P_PZ/D");    
    rTree2->Branch("P_PE",&P_PE, "P_PE/D");    
    rTree2->Branch("P_P",&P_P, "P_P/D");    
    rTree2->Branch("K_PX",&K_PX, "K_PX/D");    
    rTree2->Branch("K_PY",&K_PY, "K_PY/D");    
    rTree2->Branch("K_PZ",&K_PZ, "K_PZ/D");    
    rTree2->Branch("K_PE",&K_PE, "K_PE/D");    
    rTree2->Branch("K_P",&K_P, "K_P/D"); 






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



