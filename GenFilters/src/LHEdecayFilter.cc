
#include "GeneratorInterface/GenFilters/interface/LHEdecayFilter.h"

#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include <iostream>

using namespace edm;
using namespace std;


LHEdecayFilter::LHEdecayFilter(const edm::ParameterSet& iConfig) :
  src_(iConfig.getParameter<InputTag>( "src" ) ),
  numRequired_(iConfig.getParameter<int>("NumRequired")),
  particleID_(iConfig.getParameter< std::vector<int> >("ParticleID"))
{
   //now do what ever initialization is needed

}


LHEdecayFilter::~LHEdecayFilter()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to produce the data  ------------
bool LHEdecayFilter::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   Handle<LHEEventProduct> evt;
   iEvent.getByLabel( src_, evt );

   const lhef::HEPEUP hepeup_ = evt->hepeup();

   const int nup_ = hepeup_.NUP; 
   const std::vector<int> idup_ = hepeup_.IDUP;

   int nFound = 0;

   for (unsigned int i = 0; i < (unsigned int)nup_; ++i) {
    if (hepeup_.ISTUP[i] != 1) { // keep only outgoing particles
      continue;
    }
    for (unsigned int j = 0; j < particleID_.size(); ++j) {
      if (particleID_[j] == 0 || abs(particleID_[j]) == abs(idup_[i]) ) {
        nFound++;
        break; // only match a given particle once!
      }
    } // loop over targets
  } // loop over particles
  
  // event accept/reject logic
  if (nFound >= numRequired_) {
    return true;
  } else {
    return false;
  }   
}

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(LHEdecayFilter);
