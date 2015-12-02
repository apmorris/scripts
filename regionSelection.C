/*	
	
	Alice Morris
	MPhys Project 2015/16

	Script to select the sideband and signal regions 
	

*/

void regionSelection(){ 

  // -- define tuple file name, tuple name and cuts to apply
  // -- and also the name of the output file
  const std::string filename = "~/cern/ntuples/new_tuples/Lb2chicpK_2011_2012_signal_cut.root";
  const std::string treename("DecayTree");
  
  // SIDEBAND
  const std::string cuts = "Lambda_b0_DTF_MASS_constr1 > 5660 && Lambda_b0_DTF_MASS_constr1 < 5700" ;
  const std::string outFilename("~/cern/ntuples/sideband.root");
 
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
  newFile->Save();
    
  
  double n_post = rTree1->GetEntries();
    
  
  //std::cout << "# of events in signal region = " << n_post << endl;
  std::cout << "# of events in sideband region = " << n_post << endl;
  
  
}




