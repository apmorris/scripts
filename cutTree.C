/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to apply manual cuts to the new data. 

*/


void cutTree(){ 

    // -- define tuple file name, tuple name and cuts to apply
    // -- and also the name of the output file
 
    
    //data
    //const std::string filename = "/afs/cern.ch/work/g/gcowan/gangadir/workspace/gcowan/LocalXML/352/output/Lb2chicpK_2011_2012_signal.root";//change
    //const std::string outFilename("~/cern/ntuples/new_tuples/Lb2chicpK_2011_2012_signal_cut.root");
    
    //MC 2012 MagUp
    //const std::string filename = "/afs/cern.ch/work/g/gcowan/gangadir/workspace/gcowan/LocalXML/354/output/DVTuples1.root";
    //const std::string outFilename("~/cern/ntuples/new_tuples/Lb2chicpK_MC_2012_MagUp_signal_cut.root");
    
    //MC 2012 MagDown
    const std::string filename = "/afs/cern.ch/work/g/gcowan/gangadir/workspace/gcowan/LocalXML/355/output/DVTuples1.root";
    const std::string outFilename("~/cern/ntuples/new_tuples/Lb2chicpK_MC_2012_MagDown_signal_cut.root");
    
    //MC 2011 MagUp
    //const std::string filename = "/afs/cern.ch/work/g/gcowan/gangadir/workspace/gcowan/LocalXML/356/output/DVTuples1.root";
    //const std::string outFilename("~/cern/ntuples/new_tuples/Lb2chicpK_MC_2011_MagUp_signal_cut.root");
    
    //MC 2011 MagDown
    //const std::string filename = "/afs/cern.ch/work/g/gcowan/gangadir/workspace/gcowan/LocalXML/357/output/DVTuples1.root";
    //const std::string outFilename("~/cern/ntuples/new_tuples/Lb2chicpK_MC_2011_MagDown_signal_cut.root");
    
        
    const std::string treename("Tuple/DecayTree");
 
    
    //const std::string cuts = "Lambda_b0_DTF_MASS_constr1>5550 && Lambda_b0_DTF_MASS_constr1<5700 && Lambda_b0_DTF_CHI2NDOF<7 && Lambda_b0_DTF_CHI2NDOF>0 && Lambda_b0_IPCHI2_OWNPV<25 && Lambda_b0_FDS>10 && kaon_IPCHI2_OWNPV>4 && proton_IPCHI2_OWNPV>4 && gamma_CL>0.03 && chi_c_M>3400 && chi_c_M<3700 && muplus_TRACK_GhostProb<0.3 && muminus_TRACK_GhostProb<0.3 && kaon_TRACK_GhostProb<0.3 && proton_TRACK_GhostProb<0.3 && min(muplus_ProbNNmu,muminus_ProbNNmu)>0.1 && (Lambda_b0_L0MuonDecision_TOS==1||Lambda_b0_L0DiMuonDecision_TOS==1) &&(Lambda_b0_Hlt1DiMuonHighMassDecision_TOS==1||Lambda_b0_Hlt1DiMuonLowMassDecision_TOS==1||Lambda_b0_Hlt1TrackMuonDecision_TOS==1||Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS==1||Lambda_b0_Hlt1TrackAllL0Decision_TOS==1) &&(Lambda_b0_Hlt2DiMuonDetachedDecision_TOS==1||Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS==1) && Lambda_b0_pi0veto==1 && gamma_PT>700";

    //for MC
    const std::string cuts = "Lambda_b0_DTF_MASS_constr1>5550 && Lambda_b0_DTF_MASS_constr1<5700 && Lambda_b0_DTF_CHI2NDOF<7 && Lambda_b0_DTF_CHI2NDOF>0 && Lambda_b0_IPCHI2_OWNPV<25 && Lambda_b0_FDS>10 && kaon_IPCHI2_OWNPV>4 && proton_IPCHI2_OWNPV>4 && gamma_CL>0.03 && chi_c_M>3400 && chi_c_M<3700 && muplus_TRACK_GhostProb<0.3 && muminus_TRACK_GhostProb<0.3 && kaon_TRACK_GhostProb<0.3 && proton_TRACK_GhostProb<0.3 && min(muplus_ProbNNmu,muminus_ProbNNmu)>0.1 && (Lambda_b0_L0MuonDecision_TOS==1||Lambda_b0_L0DiMuonDecision_TOS==1) &&(Lambda_b0_Hlt1DiMuonHighMassDecision_TOS==1||Lambda_b0_Hlt1DiMuonLowMassDecision_TOS==1||Lambda_b0_Hlt1TrackMuonDecision_TOS==1||Lambda_b0_Hlt1SingleMuonHighPTDecision_TOS==1||Lambda_b0_Hlt1TrackAllL0Decision_TOS==1) &&(Lambda_b0_Hlt2DiMuonDetachedDecision_TOS==1||Lambda_b0_Hlt2DiMuonDetachedHeavyDecision_TOS==1) && Lambda_b0_pi0veto==1 && Lambda_b0_BKGCAT<20 ";  
    //const std::string cuts = "Lambda_b0_pi0veto==1 && gamma_PT>700";

    TFile* file = TFile::Open( filename.c_str() );
    if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;

    TTree* tree = (TTree*)file->Get( treename.c_str() );
    if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;
  
    // -- activate the branches you need
  
    tree->SetBranchStatus("*", 1);   
      
    // -- this file is just here to make the 'CopyTree' happy
    TFile* newFile = new TFile(outFilename.c_str(),"RECREATE");
    TTree* rTree1 = tree->CopyTree( cuts.c_str() );
    
    /*int percentCounter = 1;

    for(int i = 0; i < tree->GetEntries(); ++i){
  
      const int percent = (int)(tree->GetEntries()/100.0);
    
      if( i == percent*percentCounter ){
        //std::cout << percentCounter << " %" << std::endl;
        percentCounter++;
      }
      
      //tree->GetEntry(i);
      //rTree1->Fill();
      //std::cout << mass << std::endl;   
    }*/
    //rTree1->Print();
    rTree1->Write();
    newFile->Save();

    double n_pre = tree->GetEntries();
    double n_post = rTree1->GetEntries();
    
    std::cout << "# of events pre cuts = " << n_pre << endl;
    std::cout << "# of events post cuts = " << n_post << endl;


} 
