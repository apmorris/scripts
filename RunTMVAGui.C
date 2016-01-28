///////////////////////////////////////////////////////
// This macro open the TMVA Gui interface for the    //
// file: tmva.root                                   //
///////////////////////////////////////////////////////

void RunTMVAGui()
{
  gROOT->LoadMacro("$ROOTSYS/tmva/test/TMVAGui.C");
  TMVAGui("TMVA.root");
}

