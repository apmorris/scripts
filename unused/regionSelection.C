/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to select histogram regions 
	

*/

void regionSelection(){ 

  // -- define tuple file name, tuple name and cuts to apply
  // -- and also the name of the output file
  const std::string filename = "/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/reduced_Lb2chicpK_2011_2012_signal.root";
  const std::string treename("DecayTree");
  
 
  const std::string cuts = "proton_ProbNNp>0.3 && kaon_ProbNNk>0.3" ;
  const std::string outFilename("/afs/cern.ch/work/a/apmorris/private/cern/ntuples/new_tuples/reduced_Lb2chicpK_2011_2012_signal_PIDcut.root");
 
/*  // SIGNAL
  const std::string cuts = "Lambda_b0_DTF_MASS_constr1 > 5610 && Lambda_b0_DTF_MASS_constr1 < 5630" ;
  const std::string outFilename("~/cern/ntuples/signal.root"); 
 */ 
  

  TFile* file = TFile::Open( filename.c_str() );
  if( !file ) std::cout << "file " << filename << " does not exist" << std::endl;

  TTree* tree = (TTree*)file->Get( treename.c_str() );
  if( !tree ) std::cout << "tree " << treename << " does not exist" << std::endl;
  
  // -- activate the branches you need
  
  tree->SetBranchStatus("*", 1);
  
  
  // -- this file is just here to make the 'CopyTree' happy
  TFile* newFile = new TFile(outFilename.c_str(),"RECREATE");
  TTree* rTree1 = tree->CopyTree( cuts.c_str() );

  
  rTree1->Write();
  rTree1->Print();
  newFile->Save();
    
  
  double n_post = rTree1->GetEntries();
    
  
  //std::cout << "# of events in signal region = " << n_post << endl;
  //std::cout << "# of events in sideband region = " << n_post << endl;
  
  
}




