/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to cut the ntuples by polarity.

*/

void polarityCuts(){ 


  // -- define tuple file name, tuple name and cut to apply
  // -- and also the name of the output file
  const std::string filename = "~/cern/ntuples/Lb2chicpK_MC_2011_2012_signal.root";
  const std::string treename("HistosAndTuples/MyTuple");
  const std::string cuts = " polarity > 0. " ;
  const std::string outFilename("~/cern/ntuples/Lb2chicpK_MC_2011_2012_signal_MagUp.root");

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
  tree->SetBranchStatus("minann_K",1);
  tree->SetBranchStatus("ann_proton",1);
  tree->SetBranchStatus("minann_P",1);
  tree->SetBranchStatus("ann_mu",1);
  tree->SetBranchStatus("minann_mu",1);
  tree->SetBranchStatus("m_chicp",1);//not in MC
  tree->SetBranchStatus("m_pK",1);//not in MC
  tree->SetBranchStatus("m_jpsi",1);
  tree->SetBranchStatus("polarity",1);
  




  // -- this file is just here to make the 'CopyTree' happy
  TFile* dummyFile = new TFile("~/cern/ntuples/dummy.root","RECREATE");
  TTree* rTree1 = tree->CopyTree( cuts.c_str() );






  float mass, mass_chicp, mass_pK, mass_jpsi, mass_chic, dtf_b, c2ip_b, dls_b, c2ip_kminus, c2ip_pplus, minCl_gamma, trgh_track, ann_kaon, minann_K, ann_proton, minann_P, ann_mu, minann_mu, polarity;

  float trig_b_l0tos_tos, trig_b_l1tos_tos, trig_b_l2tos_tos;

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
  rTree1->SetBranchAddress("minann_K", &minann_K);
  rTree1->SetBranchAddress("ann_proton", &ann_proton);
  rTree1->SetBranchAddress("minann_P", &minann_P);
  rTree1->SetBranchAddress("ann_mu", &ann_mu);
  rTree1->SetBranchAddress("minann_mu", &minann_mu);
  rTree1->SetBranchAddress("polarity", &polarity);
  




  TFile* rFile = new TFile( outFilename.c_str() ,"RECREATE");
  TTree* rTree2 = new TTree();
  rTree2->SetName("sideband");
  //rTree2->SetName("signal");
  rTree2->Branch("mass", &mass, "mass");
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
  rTree2->Branch("trig_b_l0tos_tos", &trig_b_l0tos_tos, "trig_b_l0tos_tos/F");
  rTree2->Branch("trig_b_l1tos_tos", &trig_b_l1tos_tos, "trig_b_l1tos_tos/F");
  rTree2->Branch("trig_b_l2tos_tos", &trig_b_l2tos_tos, "trig_b_l2tos_tos/F");
  rTree2->Branch("trgh_track", &trgh_track, "trgh_track/F");
  rTree2->Branch("ann_kaon", &ann_kaon, "ann_kaon/F");
  rTree2->Branch("minann_K", &minann_K, "minann_K/F");
  rTree2->Branch("ann_proton", &ann_proton, "ann_proton/F");
  rTree2->Branch("minann_P", &minann_P, "minann_P/F");
  rTree2->Branch("ann_mu", &ann_mu, "ann_mu/F");
  rTree2->Branch("minann_mu", &minann_mu, "minann_mu/F");
  rTree2->Branch("polarity", &polarity, "polarity/F");





  int percentCounter = 1;

  for(int i = 0; i < rTree1->GetEntries(); ++i){

    const int percent = (int)(rTree1->GetEntries()/100.0);
    
    if( i == percent*percentCounter ){
      //std::cout << percentCounter << " %" << std::endl;
      percentCounter++;
    }

    rTree1->GetEntry(i);
    rTree2->Fill();
    //std::cout << mass << std::endl;   
  }




  rTree2->Print();
  rTree2->Write();
  rFile->Save();




}



