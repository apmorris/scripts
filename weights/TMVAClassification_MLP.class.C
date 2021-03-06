// Class: ReadMLP
// Automatically generated by MethodBase::MakeClass
//

/* configuration options =====================================================

#GEN -*-*-*-*-*-*-*-*-*-*-*- general info -*-*-*-*-*-*-*-*-*-*-*-

Method         : MLP::MLP
TMVA Release   : 4.2.0         [262656]
ROOT Release   : 5.34/32       [336416]
Creator        : apmorris
Date           : Thu Dec 10 17:21:03 2015
Host           : Linux buildvm-13.phx2.fedoraproject.org 4.1.6-100.fc21.x86_64 #1 SMP Mon Aug 17 22:20:37 UTC 2015 x86_64 x86_64 x86_64 GNU/Linux
Dir            : /afs/cern.ch/user/a/apmorris/cern/scripts
Training events: 59190
Analysis type  : [Classification]


#OPT -*-*-*-*-*-*-*-*-*-*-*-*- options -*-*-*-*-*-*-*-*-*-*-*-*-

# Set by User:
NCycles: "600" [Number of training cycles]
HiddenLayers: "9" [Specification of hidden layer architecture]
NeuronType: "sigmoid" [Neuron activation function type]
EstimatorType: "CE" [MSE (Mean Square Estimator) for Gaussian Likelihood or CE(Cross-Entropy) for Bernoulli Likelihood]
V: "False" [Verbose output (short form of "VerbosityLevel" below - overrides the latter one)]
VarTransform: "Norm" [List of variable transformations performed before training, e.g., "D_Background,P_Signal,G,N_AllClasses" for: "Decorrelation, PCA-transformation, Gaussianisation, Normalisation, each for the given class of events ('AllClasses' denotes all events of all classes, if no class indication is given, 'All' is assumed)"]
H: "True" [Print method-specific help message]
TestRate: "5" [Test for overtraining performed at each #th epochs]
# Default:
RandomSeed: "1" [Random seed for initial synapse weights (0 means unique seed for each run; default value '1')]
NeuronInputType: "sum" [Neuron input function type]
VerbosityLevel: "Default" [Verbosity level]
CreateMVAPdfs: "False" [Create PDFs for classifier outputs (signal and background)]
IgnoreNegWeightsInTraining: "False" [Events with negative weights are ignored in the training (but are included for testing and performance evaluation)]
TrainingMethod: "BP" [Train with Back-Propagation (BP), BFGS Algorithm (BFGS), or Genetic Algorithm (GA - slower and worse)]
LearningRate: "2.000000e-02" [ANN learning rate parameter]
DecayRate: "1.000000e-02" [Decay rate for learning parameter]
EpochMonitoring: "False" [Provide epoch-wise monitoring plots according to TestRate (caution: causes big ROOT output file!)]
Sampling: "1.000000e+00" [Only 'Sampling' (randomly selected) events are trained each epoch]
SamplingEpoch: "1.000000e+00" [Sampling is used for the first 'SamplingEpoch' epochs, afterwards, all events are taken for training]
SamplingImportance: "1.000000e+00" [ The sampling weights of events in epochs which successful (worse estimator than before) are multiplied with SamplingImportance, else they are divided.]
SamplingTraining: "True" [The training sample is sampled]
SamplingTesting: "False" [The testing sample is sampled]
ResetStep: "50" [How often BFGS should reset history]
Tau: "3.000000e+00" [LineSearch "size step"]
BPMode: "sequential" [Back-propagation learning mode: sequential or batch]
BatchSize: "-1" [Batch size: number of events/batch, only set if in Batch Mode, -1 for BatchSize=number_of_events]
ConvergenceImprove: "1.000000e-30" [Minimum improvement which counts as improvement (<0 means automatic convergence check is turned off)]
ConvergenceTests: "-1" [Number of steps (without improvement) required for convergence (<0 means automatic convergence check is turned off)]
UseRegulator: "False" [Use regulator to avoid over-training]
UpdateLimit: "10000" [Maximum times of regulator update]
CalculateErrors: "False" [Calculates inverse Hessian matrix at the end of the training to be able to calculate the uncertainties of an MVA value]
WeightRange: "1.000000e+00" [Take the events for the estimator calculations from small deviations from the desired value to large deviations only over the weight range]
##


#VAR -*-*-*-*-*-*-*-*-*-*-*-* variables *-*-*-*-*-*-*-*-*-*-*-*-

NVar 14
kaon_IPCHI2_OWNPV             kaon_IPCHI2_OWNPV             kaon_IPCHI2_OWNPV             kaon_IPCHI2_OWNPV                                               'D'    [4.00053215027,30942.140625]
kaon_TRACK_GhostProb          kaon_TRACK_GhostProb          kaon_TRACK_GhostProb          kaon_TRACK_GhostProb                                            'D'    [2.5843912681e-06,0.299483448267]
proton_IPCHI2_OWNPV           proton_IPCHI2_OWNPV           proton_IPCHI2_OWNPV           proton_IPCHI2_OWNPV                                             'D'    [4.00123596191,22752.8496094]
proton_TRACK_GhostProb        proton_TRACK_GhostProb        proton_TRACK_GhostProb        proton_TRACK_GhostProb                                          'D'    [1.03363299786e-05,0.299567013979]
gamma_PT                      gamma_PT                      gamma_PT                      gamma_PT                                                        'D'    [400.000915527,6938.18994141]
gamma_CL                      gamma_CL                      gamma_CL                      gamma_CL                                                        'D'    [0.0300153419375,1]
muminus_ProbNNmu              muminus_ProbNNmu              muminus_ProbNNmu              muminus_ProbNNmu                                                'D'    [0.100352801383,0.99928599596]
muminus_TRACK_GhostProb       muminus_TRACK_GhostProb       muminus_TRACK_GhostProb       muminus_TRACK_GhostProb                                         'D'    [0,0.291641682386]
muplus_ProbNNmu               muplus_ProbNNmu               muplus_ProbNNmu               muplus_ProbNNmu                                                 'D'    [0.10022944212,0.999370574951]
muplus_TRACK_GhostProb        muplus_TRACK_GhostProb        muplus_TRACK_GhostProb        muplus_TRACK_GhostProb                                          'D'    [0,0.299577355385]
Lambda_b0_DTF_CHI2NDOF        Lambda_b0_DTF_CHI2NDOF        Lambda_b0_DTF_CHI2NDOF        Lambda_b0_DTF_CHI2NDOF                                          'D'    [0.0393369160593,6.98377370834]
Lambda_b0_IPCHI2_OWNPV        Lambda_b0_IPCHI2_OWNPV        Lambda_b0_IPCHI2_OWNPV        Lambda_b0_IPCHI2_OWNPV                                          'D'    [5.2797182434e-05,24.9946022034]
Lambda_b0_FDS                 Lambda_b0_FDS                 Lambda_b0_FDS                 Lambda_b0_FDS                                                   'D'    [10.0026330948,344.658996582]
Lambda_b0_PT                  Lambda_b0_PT                  Lambda_b0_PT                  Lambda_b0_PT                                                    'D'    [51.0862503052,64733.3554688]
NSpec 0


============================================================================ */

#include <vector>
#include <cmath>
#include <string>
#include <iostream>

#ifndef IClassifierReader__def
#define IClassifierReader__def

class IClassifierReader {

 public:

   // constructor
   IClassifierReader() : fStatusIsClean( true ) {}
   virtual ~IClassifierReader() {}

   // return classifier response
   virtual double GetMvaValue( const std::vector<double>& inputValues ) const = 0;

   // returns classifier status
   bool IsStatusClean() const { return fStatusIsClean; }

 protected:

   bool fStatusIsClean;
};

#endif

class ReadMLP : public IClassifierReader {

 public:

   // constructor
   ReadMLP( std::vector<std::string>& theInputVars ) 
      : IClassifierReader(),
        fClassName( "ReadMLP" ),
        fNvars( 14 ),
        fIsNormalised( false )
   {      
      // the training input variables
      const char* inputVars[] = { "kaon_IPCHI2_OWNPV", "kaon_TRACK_GhostProb", "proton_IPCHI2_OWNPV", "proton_TRACK_GhostProb", "gamma_PT", "gamma_CL", "muminus_ProbNNmu", "muminus_TRACK_GhostProb", "muplus_ProbNNmu", "muplus_TRACK_GhostProb", "Lambda_b0_DTF_CHI2NDOF", "Lambda_b0_IPCHI2_OWNPV", "Lambda_b0_FDS", "Lambda_b0_PT" };

      // sanity checks
      if (theInputVars.size() <= 0) {
         std::cout << "Problem in class \"" << fClassName << "\": empty input vector" << std::endl;
         fStatusIsClean = false;
      }

      if (theInputVars.size() != fNvars) {
         std::cout << "Problem in class \"" << fClassName << "\": mismatch in number of input values: "
                   << theInputVars.size() << " != " << fNvars << std::endl;
         fStatusIsClean = false;
      }

      // validate input variables
      for (size_t ivar = 0; ivar < theInputVars.size(); ivar++) {
         if (theInputVars[ivar] != inputVars[ivar]) {
            std::cout << "Problem in class \"" << fClassName << "\": mismatch in input variable names" << std::endl
                      << " for variable [" << ivar << "]: " << theInputVars[ivar].c_str() << " != " << inputVars[ivar] << std::endl;
            fStatusIsClean = false;
         }
      }

      // initialize min and max vectors (for normalisation)
      fVmin[0] = -1;
      fVmax[0] = 0.99999988079071;
      fVmin[1] = -1;
      fVmax[1] = 1;
      fVmin[2] = -1;
      fVmax[2] = 0.99999988079071;
      fVmin[3] = -1;
      fVmax[3] = 0.99999988079071;
      fVmin[4] = -1;
      fVmax[4] = 1;
      fVmin[5] = -1;
      fVmax[5] = 0.99999988079071;
      fVmin[6] = -1;
      fVmax[6] = 1;
      fVmin[7] = -1;
      fVmax[7] = 1;
      fVmin[8] = -1;
      fVmax[8] = 1;
      fVmin[9] = -1;
      fVmax[9] = 1;
      fVmin[10] = -1;
      fVmax[10] = 1;
      fVmin[11] = -1;
      fVmax[11] = 1;
      fVmin[12] = -1;
      fVmax[12] = 0.99999988079071;
      fVmin[13] = -1;
      fVmax[13] = 1;

      // initialize input variable types
      fType[0] = 'D';
      fType[1] = 'D';
      fType[2] = 'D';
      fType[3] = 'D';
      fType[4] = 'D';
      fType[5] = 'D';
      fType[6] = 'D';
      fType[7] = 'D';
      fType[8] = 'D';
      fType[9] = 'D';
      fType[10] = 'D';
      fType[11] = 'D';
      fType[12] = 'D';
      fType[13] = 'D';

      // initialize constants
      Initialize();

      // initialize transformation
      InitTransform();
   }

   // destructor
   virtual ~ReadMLP() {
      Clear(); // method-specific
   }

   // the classifier response
   // "inputValues" is a vector of input values in the same order as the 
   // variables given to the constructor
   double GetMvaValue( const std::vector<double>& inputValues ) const;

 private:

   // method-specific destructor
   void Clear();

   // input variable transformation

   double fMin_1[3][14];
   double fMax_1[3][14];
   void InitTransform_1();
   void Transform_1( std::vector<double> & iv, int sigOrBgd ) const;
   void InitTransform();
   void Transform( std::vector<double> & iv, int sigOrBgd ) const;

   // common member variables
   const char* fClassName;

   const size_t fNvars;
   size_t GetNvar()           const { return fNvars; }
   char   GetType( int ivar ) const { return fType[ivar]; }

   // normalisation of input variables
   const bool fIsNormalised;
   bool IsNormalised() const { return fIsNormalised; }
   double fVmin[14];
   double fVmax[14];
   double NormVariable( double x, double xmin, double xmax ) const {
      // normalise to output range: [-1, 1]
      return 2*(x - xmin)/(xmax - xmin) - 1.0;
   }

   // type of input variable: 'F' or 'I'
   char   fType[14];

   // initialize internal variables
   void Initialize();
   double GetMvaValue__( const std::vector<double>& inputValues ) const;

   // private members (method specific)

   double ActivationFnc(double x) const;
   double OutputActivationFnc(double x) const;

   int fLayers;
   int fLayerSize[3];
   double fWeightMatrix0to1[10][15];   // weight matrix from layer 0 to 1
   double fWeightMatrix1to2[1][10];   // weight matrix from layer 1 to 2

   double * fWeights[3];
};

inline void ReadMLP::Initialize()
{
   // build network structure
   fLayers = 3;
   fLayerSize[0] = 15; fWeights[0] = new double[15]; 
   fLayerSize[1] = 10; fWeights[1] = new double[10]; 
   fLayerSize[2] = 1; fWeights[2] = new double[1]; 
   // weight matrix from layer 0 to 1
   fWeightMatrix0to1[0][0] = -0.401791253968695;
   fWeightMatrix0to1[1][0] = 4.4970882661981;
   fWeightMatrix0to1[2][0] = 5.30299546356122;
   fWeightMatrix0to1[3][0] = 2.38453710779811;
   fWeightMatrix0to1[4][0] = 0.074668264885312;
   fWeightMatrix0to1[5][0] = -3.13130558604297;
   fWeightMatrix0to1[6][0] = -0.589807704176466;
   fWeightMatrix0to1[7][0] = 1.6874532133313;
   fWeightMatrix0to1[8][0] = 0.628209271641676;
   fWeightMatrix0to1[0][1] = -1.51426379474145;
   fWeightMatrix0to1[1][1] = -7.37472735030728;
   fWeightMatrix0to1[2][1] = 0.17119794523576;
   fWeightMatrix0to1[3][1] = -5.54848467024254;
   fWeightMatrix0to1[4][1] = 0.111016245442608;
   fWeightMatrix0to1[5][1] = 1.0335944099822;
   fWeightMatrix0to1[6][1] = -1.14366366129943;
   fWeightMatrix0to1[7][1] = -0.00154666305783646;
   fWeightMatrix0to1[8][1] = 2.31574964581833;
   fWeightMatrix0to1[0][2] = 0.00809686601376933;
   fWeightMatrix0to1[1][2] = 3.64322710666517;
   fWeightMatrix0to1[2][2] = 3.37574770367969;
   fWeightMatrix0to1[3][2] = 0.341345417143346;
   fWeightMatrix0to1[4][2] = 3.35630754880977;
   fWeightMatrix0to1[5][2] = -1.78424473051881;
   fWeightMatrix0to1[6][2] = -0.840715780056973;
   fWeightMatrix0to1[7][2] = 0.208040135030677;
   fWeightMatrix0to1[8][2] = 3.82684567553483;
   fWeightMatrix0to1[0][3] = -1.10117274819833;
   fWeightMatrix0to1[1][3] = -11.757438884533;
   fWeightMatrix0to1[2][3] = 0.111586216673578;
   fWeightMatrix0to1[3][3] = 2.82102401343162;
   fWeightMatrix0to1[4][3] = 0.0399897925982932;
   fWeightMatrix0to1[5][3] = -1.15599512654392;
   fWeightMatrix0to1[6][3] = -0.953848354793832;
   fWeightMatrix0to1[7][3] = -1.10614512682159;
   fWeightMatrix0to1[8][3] = -1.32556401465275;
   fWeightMatrix0to1[0][4] = -1.04815550572228;
   fWeightMatrix0to1[1][4] = 7.07047437948358;
   fWeightMatrix0to1[2][4] = -0.160530934949941;
   fWeightMatrix0to1[3][4] = 0.56739987961385;
   fWeightMatrix0to1[4][4] = 5.99326392149481;
   fWeightMatrix0to1[5][4] = 0.202673209636617;
   fWeightMatrix0to1[6][4] = 6.27101727996755;
   fWeightMatrix0to1[7][4] = 1.64330018930247;
   fWeightMatrix0to1[8][4] = 0.486780656230936;
   fWeightMatrix0to1[0][5] = -1.24525169248409;
   fWeightMatrix0to1[1][5] = 0.0851683128587281;
   fWeightMatrix0to1[2][5] = -0.149107373505287;
   fWeightMatrix0to1[3][5] = 0.122771711352156;
   fWeightMatrix0to1[4][5] = -0.0812563656415343;
   fWeightMatrix0to1[5][5] = 0.0135137515202929;
   fWeightMatrix0to1[6][5] = 0.677936865502183;
   fWeightMatrix0to1[7][5] = -0.0779977595395663;
   fWeightMatrix0to1[8][5] = 0.135151091218611;
   fWeightMatrix0to1[0][6] = -2.07142770501907;
   fWeightMatrix0to1[1][6] = -0.398034365992892;
   fWeightMatrix0to1[2][6] = -0.144247757842751;
   fWeightMatrix0to1[3][6] = -0.493863707009982;
   fWeightMatrix0to1[4][6] = 1.39235343321646;
   fWeightMatrix0to1[5][6] = 0.260888830871374;
   fWeightMatrix0to1[6][6] = -0.0804483401750252;
   fWeightMatrix0to1[7][6] = 1.21401679618648;
   fWeightMatrix0to1[8][6] = 0.353309741559825;
   fWeightMatrix0to1[0][7] = 0.144420171464432;
   fWeightMatrix0to1[1][7] = -1.55818928019377;
   fWeightMatrix0to1[2][7] = 0.674835726512984;
   fWeightMatrix0to1[3][7] = 1.86611559620885;
   fWeightMatrix0to1[4][7] = -10.1267496987039;
   fWeightMatrix0to1[5][7] = 0.521003921392865;
   fWeightMatrix0to1[6][7] = -0.289310264068064;
   fWeightMatrix0to1[7][7] = -1.92044248023328;
   fWeightMatrix0to1[8][7] = 0.151998295124988;
   fWeightMatrix0to1[0][8] = 0.638370695104067;
   fWeightMatrix0to1[1][8] = -0.183564773654851;
   fWeightMatrix0to1[2][8] = -0.307754553606095;
   fWeightMatrix0to1[3][8] = -0.00246328476482185;
   fWeightMatrix0to1[4][8] = 0.323680541194039;
   fWeightMatrix0to1[5][8] = -1.26151312552295;
   fWeightMatrix0to1[6][8] = 0.361339904990573;
   fWeightMatrix0to1[7][8] = 0.62853665821875;
   fWeightMatrix0to1[8][8] = 1.40288812818926;
   fWeightMatrix0to1[0][9] = 0.606833445711158;
   fWeightMatrix0to1[1][9] = 0.276030084857275;
   fWeightMatrix0to1[2][9] = 0.460781725863087;
   fWeightMatrix0to1[3][9] = -1.14198680799107;
   fWeightMatrix0to1[4][9] = -1.79721904882193;
   fWeightMatrix0to1[5][9] = 5.28145863246836;
   fWeightMatrix0to1[6][9] = -2.88756835358861;
   fWeightMatrix0to1[7][9] = -1.1005897649093;
   fWeightMatrix0to1[8][9] = -7.31690233142629;
   fWeightMatrix0to1[0][10] = -1.43721938350815;
   fWeightMatrix0to1[1][10] = 0.37928510697012;
   fWeightMatrix0to1[2][10] = 2.08368309736522;
   fWeightMatrix0to1[3][10] = 0.207454721478135;
   fWeightMatrix0to1[4][10] = -1.64504376042278;
   fWeightMatrix0to1[5][10] = -0.171299142134554;
   fWeightMatrix0to1[6][10] = 0.809432099121309;
   fWeightMatrix0to1[7][10] = -1.9516294778151;
   fWeightMatrix0to1[8][10] = -1.15385903893268;
   fWeightMatrix0to1[0][11] = -0.321897455387664;
   fWeightMatrix0to1[1][11] = -0.56710722180576;
   fWeightMatrix0to1[2][11] = -1.01385105379748;
   fWeightMatrix0to1[3][11] = -0.782646179460608;
   fWeightMatrix0to1[4][11] = -0.0901700522323038;
   fWeightMatrix0to1[5][11] = -1.49993016799374;
   fWeightMatrix0to1[6][11] = -1.67937931101439;
   fWeightMatrix0to1[7][11] = 0.737759896164075;
   fWeightMatrix0to1[8][11] = -0.700005790147843;
   fWeightMatrix0to1[0][12] = 0.656772294753951;
   fWeightMatrix0to1[1][12] = -0.00814045891242203;
   fWeightMatrix0to1[2][12] = -8.78632742776105;
   fWeightMatrix0to1[3][12] = -0.0631525040365247;
   fWeightMatrix0to1[4][12] = 1.63237648342102;
   fWeightMatrix0to1[5][12] = 2.21901922200979;
   fWeightMatrix0to1[6][12] = -2.59934641508174;
   fWeightMatrix0to1[7][12] = 1.4926751113337;
   fWeightMatrix0to1[8][12] = 2.95982522830026;
   fWeightMatrix0to1[0][13] = -0.590584312571587;
   fWeightMatrix0to1[1][13] = 0.195079457101146;
   fWeightMatrix0to1[2][13] = -10.3682563320172;
   fWeightMatrix0to1[3][13] = 0.742952534738067;
   fWeightMatrix0to1[4][13] = -1.50784664809336;
   fWeightMatrix0to1[5][13] = 0.812515838447889;
   fWeightMatrix0to1[6][13] = 1.74770582201077;
   fWeightMatrix0to1[7][13] = 3.35149976683949;
   fWeightMatrix0to1[8][13] = -1.69156103972731;
   fWeightMatrix0to1[0][14] = -0.0886484887532722;
   fWeightMatrix0to1[1][14] = -3.57749099392625;
   fWeightMatrix0to1[2][14] = -8.44951148347121;
   fWeightMatrix0to1[3][14] = -0.0257075941749513;
   fWeightMatrix0to1[4][14] = -3.58839017228378;
   fWeightMatrix0to1[5][14] = -0.59665035299027;
   fWeightMatrix0to1[6][14] = -0.586363816882734;
   fWeightMatrix0to1[7][14] = -0.374447207546421;
   fWeightMatrix0to1[8][14] = -3.0270522104951;
   // weight matrix from layer 1 to 2
   fWeightMatrix1to2[0][0] = -0.851699638928743;
   fWeightMatrix1to2[0][1] = 3.11150560607409;
   fWeightMatrix1to2[0][2] = -7.067593423644;
   fWeightMatrix1to2[0][3] = 3.87573892802872;
   fWeightMatrix1to2[0][4] = 3.53635777300003;
   fWeightMatrix1to2[0][5] = 4.19728978432317;
   fWeightMatrix1to2[0][6] = 3.76414207945925;
   fWeightMatrix1to2[0][7] = -3.2247751571732;
   fWeightMatrix1to2[0][8] = 3.89255759267657;
   fWeightMatrix1to2[0][9] = -3.53015607342334;
}

inline double ReadMLP::GetMvaValue__( const std::vector<double>& inputValues ) const
{
   if (inputValues.size() != (unsigned int)fLayerSize[0]-1) {
      std::cout << "Input vector needs to be of size " << fLayerSize[0]-1 << std::endl;
      return 0;
   }

   for (int l=0; l<fLayers; l++)
      for (int i=0; i<fLayerSize[l]; i++) fWeights[l][i]=0;

   for (int l=0; l<fLayers-1; l++)
      fWeights[l][fLayerSize[l]-1]=1;

   for (int i=0; i<fLayerSize[0]-1; i++)
      fWeights[0][i]=inputValues[i];

   // layer 0 to 1
   for (int o=0; o<fLayerSize[1]-1; o++) {
      for (int i=0; i<fLayerSize[0]; i++) {
         double inputVal = fWeightMatrix0to1[o][i] * fWeights[0][i];
         fWeights[1][o] += inputVal;
      }
      fWeights[1][o] = ActivationFnc(fWeights[1][o]);
   }
   // layer 1 to 2
   for (int o=0; o<fLayerSize[2]; o++) {
      for (int i=0; i<fLayerSize[1]; i++) {
         double inputVal = fWeightMatrix1to2[o][i] * fWeights[1][i];
         fWeights[2][o] += inputVal;
      }
      fWeights[2][o] = OutputActivationFnc(fWeights[2][o]);
   }

   return fWeights[2][0];
}

double ReadMLP::ActivationFnc(double x) const {
   // sigmoid
   return 1.0/(1.0+exp(-x));
}
double ReadMLP::OutputActivationFnc(double x) const {
   // sigmoid
   return 1.0/(1.0+exp(-x));
}
   
// Clean up
inline void ReadMLP::Clear() 
{
   // clean up the arrays
   for (int lIdx = 0; lIdx < 3; lIdx++) {
      delete[] fWeights[lIdx];
   }
}
   inline double ReadMLP::GetMvaValue( const std::vector<double>& inputValues ) const
   {
      // classifier response value
      double retval = 0;

      // classifier response, sanity check first
      if (!IsStatusClean()) {
         std::cout << "Problem in class \"" << fClassName << "\": cannot return classifier response"
                   << " because status is dirty" << std::endl;
         retval = 0;
      }
      else {
         if (IsNormalised()) {
            // normalise variables
            std::vector<double> iV;
            iV.reserve(inputValues.size());
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(NormVariable( *varIt, fVmin[ivar], fVmax[ivar] ));
            }
            Transform( iV, -1 );
            retval = GetMvaValue__( iV );
         }
         else {
            std::vector<double> iV;
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(*varIt);
            }
            Transform( iV, -1 );
            retval = GetMvaValue__( iV );
         }
      }

      return retval;
   }

//_______________________________________________________________________
inline void ReadMLP::InitTransform_1()
{
   // Normalization transformation, initialisation
   fMin_1[0][0] = 4.0007314682;
   fMax_1[0][0] = 30942.140625;
   fMin_1[1][0] = 4.00053215027;
   fMax_1[1][0] = 6807.84423828;
   fMin_1[2][0] = 4.00053215027;
   fMax_1[2][0] = 30942.140625;
   fMin_1[0][1] = 2.5843912681e-06;
   fMax_1[0][1] = 0.299483448267;
   fMin_1[1][1] = 1.29953377837e-05;
   fMax_1[1][1] = 0.284121364355;
   fMin_1[2][1] = 2.5843912681e-06;
   fMax_1[2][1] = 0.299483448267;
   fMin_1[0][2] = 4.00210237503;
   fMax_1[0][2] = 22752.8496094;
   fMin_1[1][2] = 4.00123596191;
   fMax_1[1][2] = 7830.22216797;
   fMin_1[2][2] = 4.00123596191;
   fMax_1[2][2] = 22752.8496094;
   fMin_1[0][3] = 1.03363299786e-05;
   fMax_1[0][3] = 0.299567013979;
   fMin_1[1][3] = 2.78745992546e-05;
   fMax_1[1][3] = 0.286521524191;
   fMin_1[2][3] = 1.03363299786e-05;
   fMax_1[2][3] = 0.299567013979;
   fMin_1[0][4] = 400.000915527;
   fMax_1[0][4] = 6938.18994141;
   fMin_1[1][4] = 400.014068604;
   fMax_1[1][4] = 3077.36474609;
   fMin_1[2][4] = 400.000915527;
   fMax_1[2][4] = 6938.18994141;
   fMin_1[0][5] = 0.0300153419375;
   fMax_1[0][5] = 1;
   fMin_1[1][5] = 0.0300153419375;
   fMax_1[1][5] = 0.996732413769;
   fMin_1[2][5] = 0.0300153419375;
   fMax_1[2][5] = 1;
   fMin_1[0][6] = 0.100352801383;
   fMax_1[0][6] = 0.99928599596;
   fMin_1[1][6] = 0.101475790143;
   fMax_1[1][6] = 0.996258974075;
   fMin_1[2][6] = 0.100352801383;
   fMax_1[2][6] = 0.99928599596;
   fMin_1[0][7] = 0;
   fMax_1[0][7] = 0.291641682386;
   fMin_1[1][7] = 2.77923409158e-05;
   fMax_1[1][7] = 0.283683270216;
   fMin_1[2][7] = 0;
   fMax_1[2][7] = 0.291641682386;
   fMin_1[0][8] = 0.10022944212;
   fMax_1[0][8] = 0.999370574951;
   fMin_1[1][8] = 0.106353461742;
   fMax_1[1][8] = 0.995026648045;
   fMin_1[2][8] = 0.10022944212;
   fMax_1[2][8] = 0.999370574951;
   fMin_1[0][9] = 0;
   fMax_1[0][9] = 0.291669219732;
   fMin_1[1][9] = 2.58438990386e-06;
   fMax_1[1][9] = 0.299577355385;
   fMin_1[2][9] = 0;
   fMax_1[2][9] = 0.299577355385;
   fMin_1[0][10] = 0.0393369160593;
   fMax_1[0][10] = 6.98228549957;
   fMin_1[1][10] = 0.0714655742049;
   fMax_1[1][10] = 6.98377370834;
   fMin_1[2][10] = 0.0393369160593;
   fMax_1[2][10] = 6.98377370834;
   fMin_1[0][11] = 5.2797182434e-05;
   fMax_1[0][11] = 24.8062343597;
   fMin_1[1][11] = 0.00178231520113;
   fMax_1[1][11] = 24.9946022034;
   fMin_1[2][11] = 5.2797182434e-05;
   fMax_1[2][11] = 24.9946022034;
   fMin_1[0][12] = 10.0054607391;
   fMax_1[0][12] = 344.658996582;
   fMin_1[1][12] = 10.0026330948;
   fMax_1[1][12] = 220.657424927;
   fMin_1[2][12] = 10.0026330948;
   fMax_1[2][12] = 344.658996582;
   fMin_1[0][13] = 51.0862503052;
   fMax_1[0][13] = 64733.3554688;
   fMin_1[1][13] = 123.062576294;
   fMax_1[1][13] = 35930.1757812;
   fMin_1[2][13] = 51.0862503052;
   fMax_1[2][13] = 64733.3554688;
}

//_______________________________________________________________________
inline void ReadMLP::Transform_1( std::vector<double>& iv, int cls) const
{
   // Normalization transformation
   if (cls < 0 || cls > 2) {
   if (2 > 1 ) cls = 2;
      else cls = 2;
   }
   const int nVar = 14;

   // get indices of used variables

   // define the indices of the variables which are transformed by this transformation
   static std::vector<int> indicesGet;
   static std::vector<int> indicesPut;

   if ( indicesGet.empty() ) { 
      indicesGet.reserve(fNvars);
      indicesGet.push_back( 0);
      indicesGet.push_back( 1);
      indicesGet.push_back( 2);
      indicesGet.push_back( 3);
      indicesGet.push_back( 4);
      indicesGet.push_back( 5);
      indicesGet.push_back( 6);
      indicesGet.push_back( 7);
      indicesGet.push_back( 8);
      indicesGet.push_back( 9);
      indicesGet.push_back( 10);
      indicesGet.push_back( 11);
      indicesGet.push_back( 12);
      indicesGet.push_back( 13);
   } 
   if ( indicesPut.empty() ) { 
      indicesPut.reserve(fNvars);
      indicesPut.push_back( 0);
      indicesPut.push_back( 1);
      indicesPut.push_back( 2);
      indicesPut.push_back( 3);
      indicesPut.push_back( 4);
      indicesPut.push_back( 5);
      indicesPut.push_back( 6);
      indicesPut.push_back( 7);
      indicesPut.push_back( 8);
      indicesPut.push_back( 9);
      indicesPut.push_back( 10);
      indicesPut.push_back( 11);
      indicesPut.push_back( 12);
      indicesPut.push_back( 13);
   } 

   static std::vector<double> dv;
   dv.resize(nVar);
   for (int ivar=0; ivar<nVar; ivar++) dv[ivar] = iv[indicesGet.at(ivar)];
   for (int ivar=0;ivar<14;ivar++) {
      double offset = fMin_1[cls][ivar];
      double scale  = 1.0/(fMax_1[cls][ivar]-fMin_1[cls][ivar]);
      iv[indicesPut.at(ivar)] = (dv[ivar]-offset)*scale * 2 - 1;
   }
}

//_______________________________________________________________________
inline void ReadMLP::InitTransform()
{
   InitTransform_1();
}

//_______________________________________________________________________
inline void ReadMLP::Transform( std::vector<double>& iv, int sigOrBgd ) const
{
   Transform_1( iv, sigOrBgd );
}
