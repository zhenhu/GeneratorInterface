#ifndef LHEDECAYFILTER_h
#define LHEDECAYFILTER_h
// -*- C++ -*-
//
// Package:    LHEdecayFilter
// Class:      LHEdecayFilter
// 
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDFilter.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"


//
// class decleration
//

class LHEdecayFilter : public edm::EDFilter {
   public:
      explicit LHEdecayFilter(const edm::ParameterSet&);
      ~LHEdecayFilter();


      virtual bool filter(edm::Event&, const edm::EventSetup&);
   private:
      // ----------member data ---------------------------
      
      edm::InputTag src_;
      int numRequired_;             // number of particles required to pass filter
      std::vector<int> particleID_; // vector of particle IDs to look for
};
#endif
